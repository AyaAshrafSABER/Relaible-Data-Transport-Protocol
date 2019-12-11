//
// Created by sohayla on 10/12/19.
//

#include "GBN.h"
#include "Packet.h"
#include "Receiver.h"



void GBN::start() {
    bool sent = true;
    Packet pkt;
    while (1) {
        if(base == total_packets)
            break;
        if(file_utility.get_current_chunk_index() < total_packets) {
            // int remaining = min(total_packets-base, congestionHandler->get_curr_window_size());
            pkt = file_utility.get_current_chunk_data();


                if (pkt.len != -1 && !randomizer->can_send(pkt.seqno)) {
                    sentpkt.push(pkt);
                    //check timeout
                    time_out();
                    sent = false;
                    continue;
                }

            //send.
            sentpkt.push(pkt);
            sent = gbn_send(pkt);
        }
        //check timeout
        time_out();
        //recv ack pkt
        gbn_recv();
        if(duplicateAcks == 3) {
            duplicateAcks = 0;
            congestionHandler->update_window_size("DUP");
            file_utility.set_chunk_index(sentpkt.back().seqno + 1);
            resend_all();
        }
    }
}


clock_t GBN::start_timer() {
    timer = clock();
}

void GBN::stop_timer() {
    timer = -1;
}

bool GBN::check_timeout() {
    if (timer == -1) {
        return false;
    }
    clock_t now = clock();
    return ((now - timer) / (double) CLOCKS_PER_SEC) >= this->threshold;
}


bool GBN::gbn_send(Packet pkt) {
    if (next_seq_num < base + congestionHandler->get_curr_window_size() && pkt.len != -1) {
    //    std::cout << "Current base : " << base << std::endl << "Window Size : "

     //   << congestionHandler->get_curr_window_size() << endl;
        sender.send_packet(pkt, client_fd);
        if (base == next_seq_num) {
            start_timer();
        }
        next_seq_num++;
        return true;
    }
    return false;
}

void GBN::time_out() {
    if (check_timeout()) {
        congestionHandler->update_window_size("TIMEOUT");
        file_utility.set_chunk_index(sentpkt.back().seqno + 1);
        resend_all();
    }
}


void GBN::resend_all() {
    start_timer();
    queue<Packet> temp;
    while(!sentpkt.empty()) {
        std::cout << "Resending packet with seqno : "<< sentpkt.front().seqno<<std::endl;
        sender.send_packet(sentpkt.front(), client_fd);
        temp.push(sentpkt.front());
        sentpkt.pop();
    }
    sentpkt = temp;
}

void GBN::gbn_recv() {
    int status;
    Ack_Packet pkt = Receiver::receive_ack_packet(client_fd, client_socket, status);
    if (status && PacketHandler::compare_ack_packet_checksum(pkt)) {
        if (base > pkt.ackno) {
            duplicateAcks++;
        } else {
            remove_packet_from_queue(pkt.ackno);
            std::cout << "Ackno : " << pkt.ackno << std::endl;
            base = pkt.ackno + 1;
            duplicateAcks = 0;
            congestionHandler->update_window_size("ACK");
            if (base == next_seq_num) {
                stop_timer();
            } else
                start_timer();
        }
    }
}



GBN::GBN(std::string file_name, int client_fd, int seed, double PLP, struct sockaddr_in client_socket, int size)
        : file_utility(file_name.c_str()), sender(client_socket)  {
 //   file_utility(file_name.c_str()), sender(client_socket);
    this->client_fd = client_fd;
    this->plp = PLP;
    this->client_socket = client_socket;
    //sentpkt.resize(fileReader.get_file_size() + 1);
    this->threshold = 3;
    this->next_seq_num = 0;
    duplicateAcks = 0;
    std::ifstream infile("control.txt");
    int a;
    while(infile >> a){
        window_changes.push_back(a);
    }
    randomizer = new RandomLoss(plp, seed, size);
    total_packets = file_utility.get_total_packet_number();
    congestionHandler = new CongestionHandler();

}

void GBN::remove_packet_from_queue(int ack_no) {
    do{
        sentpkt.pop();
        if(sentpkt.empty())
            break;
    }while (sentpkt.front().seqno <= ack_no);

}
