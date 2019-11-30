//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include "ClientManager.h"


/*read from client.in
 * ip address
 * port number
 * file to be read
 */
/*
 * create socket
 *
 * */
/*
 * */

/*
 * */
ClientManager::ClientManager(string ip, int port, string file) {
    ClientManager::ip_address = ip;
    ClientManager::port_number = port;
    ClientManager::requested_file = file;
}

void ClientManager::run_client() {
    int sockfd = init_socket();
    char buffer[MAX_BUFFER];
    char *hello = "Hello from client";
    struct sockaddr_in	servaddr = init_server();
    int n, len;
    //start logic  creat packet and sent to the server
    sendto(sockfd, (const char *)hello, strlen(hello),
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,
           sizeof(servaddr));
    printf("Hello message sent.\n");

    n = recvfrom(sockfd, (char *)buffer, MAX_BUFFER,
                 MSG_WAITALL, (struct sockaddr *) &servaddr,
                 reinterpret_cast<socklen_t *>(&len));
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);
    closeClient(sockfd);
}

int ClientManager::init_socket() {
    // Creating socket file descriptor
    int sockfd;
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in ClientManager::init_server() {
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_number);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    return servaddr;
}

void ClientManager::closeClient(int sockfd) {
    close(sockfd);

}
