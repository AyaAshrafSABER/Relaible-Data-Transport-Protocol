//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#ifndef SERVERSIDE_SENDER_H
#define SERVERSIDE_SENDER_H

#include "Packet.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Sender {

private:
    struct sockaddr_in socket_address;

public:
    explicit Sender(struct sockaddr_in socket_addres);
    explicit Sender();

    void send_packet(Packet packet, int socket_fd);
    void send_server_ack(Ack_Server_Packet ack_server_packet, int socket_fd);
};

#endif //SERVERSIDE_SENDER_H
