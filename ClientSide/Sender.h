//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#ifndef CLIENTSIDE_SENDER_H
#define CLIENTSIDE_SENDER_H


#include "Packet.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Sender {

private:
    struct sockaddr_in socket_address;

public:
    explicit Sender(struct sockaddr_in socket_addres);
    explicit Sender();
    void send_packet(Packet packet, int socket_fd);
    void send_ack(Ack_Packet ack_packet, int socket_fd);
};

#endif //CLIENTSIDE_SENDER_H
