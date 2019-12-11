//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include "Receiver.h"
/**
 * Implement GoBack N */
Receiver::Receiver(string file_name, int socket_fd, struct sockaddr_in server_addr, int total_packets): utilities(file_name){
    expected_seq = 0;
    fd = socket_fd;
    this->server_addr = server_addr;
    recvd = 0;
    this->total_packets = total_packets;

}


void Receiver::GBNstart(){
    Sender sender(server_addr);
    while(1){
        Packet pkt = Receiver::receive_packet(fd, server_addr);
        if(!is_corrupt(pkt) && is_expected(pkt)){
            Ack_Packet ackPacket = PacketHandler::create_ack_packet(expected_seq, sizeof(int));
            sender.send_ack(ackPacket, fd);
            expected_seq++;
            utilities.write_chunk(string(pkt.data, pkt.len));
            recvd++;
        }
        if(recvd == total_packets ){
            break;
        }
    }
}

bool Receiver::is_corrupt(Packet pkt){
    return !PacketHandler::compare_packet_checksum(pkt);
}

bool Receiver::is_expected(Packet pkt){
    return pkt.seqno == expected_seq;
}





// fill the socket address with the sender address
Packet Receiver::receive_packet(int socket_fd, struct sockaddr_in socket_address) {
    Packet packet;
    socklen_t addrlen = sizeof(socket_address);
    //make it a blocking for some time only.
    int bytes = recvfrom(socket_fd, &packet, sizeof(packet),
                         0, (struct sockaddr *) &socket_address, &addrlen);
    if(bytes != sizeof(Packet) || bytes <= 0) {
        perror("Not received all the packet data");
        return Packet();
    }
    printf("packet %d received.\n", packet.seqno);
    cout << "packet size is " << packet.len << endl;
    return packet;
}



// fill the socket address with the sender address
Ack_Server_Packet Receiver::receive_ack_server_packet(int socket_fd, struct sockaddr_in socket_address) {
    Ack_Server_Packet ack_server_packet;
    socklen_t addrlen = sizeof(socket_address);
    int bytes = recvfrom(socket_fd, &ack_server_packet, sizeof(ack_server_packet),
                         0, (struct sockaddr*)&socket_address, &addrlen);
    if(bytes != sizeof(Ack_Server_Packet)){
        std::perror("Not received all the packet data");
    }
    printf("Acknowledge received.\n");
    return ack_server_packet;
}