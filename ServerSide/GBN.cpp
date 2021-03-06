//
// Created by sohayla on 10/12/19.
//

#include "GBN.h"
#include "Packet.h"
#include "Receiver.h"


GBN::GBN(std::string file_name, int client_fd, int seed, double PLP, struct sockaddr_in client_socket, int size)
        : file_utility(file_name.c_str()), sender(client_socket)  {
    //   file_utility(file_name.c_str()), sender(client_socket);
    this->client_fd = client_fd;
    this->plp = PLP;
    this->client_socket = client_socket;
    //sentpkt.resize(fileReader.get_file_size() + 1);
    //Timeout threshold
    this->threshold = 3;
    this->next_seq_num = 0;
    duplicateAcks = 0;
    randomizer = new RandomLoss(plp, seed, size);
    total_packets = file_utility.get_total_packet_number();
    congestionHandler = new CongestionHandler();
    myfile.open ("log.txt");

}

void GBN::start() {
    if(total_packets == 0) {
        return;
    }
    cout << "Total Packets : " << total_packets << endl;
    Packet pkt;
    while (1) {
        if(base == total_packets)
            break;
        myfile << "Base index : " << base << endl;
        clock_t now = clock();
        myfile << "Time : " << ((now - timer) / (double) CLOCKS_PER_SEC) << " s"<< endl;

        if(file_utility.get_current_chunk_index() < total_packets) {
            // int remaining = min(total_packets-base, congestionHandler->get_curr_window_size());
            pkt = file_utility.get_current_chunk_data();
            if (pkt.len != -1 && !randomizer->can_send(pkt.seqno)) {
                myfile << "Packet with seqno : " << pkt.seqno << " Will be lost."<<endl;
                sentpkt.push(pkt);
                    //check timeout
                    time_out();
                    continue;
            }

            //send.
            myfile << "Packet with seqno : " << pkt.seqno << " Will be sent."<<endl;
            sentpkt.push(pkt);
             gbn_send(pkt);
        }
        //check timeout
        time_out();
        //recv ack pkt
        gbn_recv();
        if(duplicateAcks == 3) {
            myfile << "Recieved three Duplicate acks, start resending."<<endl;
            duplicateAcks = 0;
            congestionHandler->update_window_size("DUP");
            myfile << "     Updated window size to : "<< congestionHandler->get_curr_window_size() <<std::endl;

            file_utility.set_chunk_index(sentpkt.back().seqno + 1);
            resend_all();
        }
    }
    myfile.close();
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
        myfile << "Timeout has occured, resending packets."<<endl;
        congestionHandler->update_window_size("TIMEOUT");
        myfile << "     Updated window size to : "<< congestionHandler->get_curr_window_size() <<std::endl;
        file_utility.set_chunk_index(sentpkt.back().seqno + 1);
        resend_all();
    }
}


void GBN::resend_all() {
    start_timer();
    queue<Packet> temp;
    while(!sentpkt.empty()) {
        while (sentpkt.front().seqno >= base + congestionHandler->get_curr_window_size()){
            time_out();
            queue<Packet> holder = sentpkt;
            sentpkt = temp;
            gbn_recv();
            temp = sentpkt;
            sentpkt = holder;
        }
        std::cout << "Resending packet with seqno : "<< sentpkt.front().seqno<<std::endl;
        myfile << "  Resending packet with seqno : "<< sentpkt.front().seqno<<std::endl;
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
            myfile << "Duplicate ack for : "<< pkt.ackno << " has arrived"<<std::endl;
            duplicateAcks++;
        } else {
            remove_packet_from_queue(pkt.ackno);
            std::cout << "Ackno : " << pkt.ackno << std::endl;
            myfile << "Ack for : "<< pkt.ackno << " has arrived"<<std::endl;
            base = pkt.ackno + 1;
            duplicateAcks = 0;
            congestionHandler->update_window_size("ACK");
            myfile << "     Updated window size to : "<< congestionHandler->get_curr_window_size() <<std::endl;

            if (base == next_seq_num) {
                stop_timer();
            } else
                start_timer();
        }
    }
}





void GBN::remove_packet_from_queue(int ack_no) {
    do{
        sentpkt.pop();
        if(sentpkt.empty())
            break;
    }while (sentpkt.front().seqno <= ack_no);

}
