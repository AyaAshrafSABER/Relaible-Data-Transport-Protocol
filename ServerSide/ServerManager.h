//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#ifndef SERVERSIDE_SERVERMANAGER_H
#define SERVERSIDE_SERVERMANAGER_H

#define MAX_BUFFER 1024

class ServerManager {
public:
    int sockfd;
    int port_no;
    int random_generator_seed;
    float data_loss_prob;

    ServerManager(int port, int randomG, float p);
    void start_server();

private:
    int create_socket();
    int server_bind(sockaddr_in in, sockaddr_in sockaddrIn);
};


#endif //SERVERSIDE_SERVERMANAGER_H
