//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#ifndef CLIENTSIDE_RECEIVER_H
#define CLIENTSIDE_RECEIVER_H
#include "PacketHandler.h"
#include "Packet.h"
#include "Utilities.h"
#include "Sender.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <fcntl.h>

using namespace std;
class Receiver {
private:
    int fd;
    int expected_seq;
    Utilities utilities;
    struct sockaddr_in server_addr;
    int recvd;
    int total_packets;

public:
    Receiver(string file_name, int socket_fd, struct sockaddr_in server_addr, int total_packets);
    void GBNstart();
    bool is_corrupt(Packet pkt);
    bool is_expected(Packet pkt);

    static Packet receive_packet(int socket_fd, struct sockaddr_in socket_address);
    static Ack_Server_Packet receive_ack_server_packet(int socket_fd, struct sockaddr_in socket_address);
};



#endif //CLIENTSIDE_RECEIVER_H
