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
#define MAX_BUFFER 1024

using namespace std;

class ClientManager {
public:
    string ip_address;
    int port_number;
    string requested_file;
    ClientManager(string ip, int port, string file);
    void run_client();
private:
    int init_socket();


    struct sockaddr_in init_server();

    void closeClient(int sockfd);
};


#endif //CLIENTSIDE_CLIENTMANAGER_H
