//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#ifndef CLIENTSIDE_CLIENTMANAGER_H
#define CLIENTSIDE_CLIENTMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <string>
#include "PacketHandler.h"

using namespace std;

class ClientManager {
public:
    int sockfd;
    sockaddr_in	servaddr;
    string ip_address;
    int port_number;
    string requested_file;
    ClientManager(string ip, int port, string file);
    void run_client();

    void receive_file();

private:
    int init_socket();


    struct sockaddr_in init_server();

    void closeClient(int sockfd);

    uint32_t send_request_to_Server();
};


#endif //CLIENTSIDE_CLIENTMANAGER_H
