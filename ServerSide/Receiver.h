//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#ifndef SERVERSIDE_RECEIVER_H
#define SERVERSIDE_RECEIVER_H

#include "Packet.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <iostream>

using namespace std;


class Receiver {

public:
    explicit Receiver();

    static Packet receive_packet(int socket_fd, struct sockaddr_in &socket_address);
    static Ack_Packet receive_ack_packet(int socket_fd, struct sockaddr_in socket_address, int& status, int TIMEOUT=1);
};

#endif //SERVERSIDE_RECEIVER_H
