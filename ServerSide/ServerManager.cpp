//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include "ServerManager.h"
ServerManager::ServerManager(int port, int randomG, float p) {
    ServerManager::port_no = port;
    ServerManager::random_generator_seed = randomG;
    ServerManager::data_loss_prob = p;

};

void ServerManager::start_server() {
    char buffer[MAX_BUFFER];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
    create_socket();
    server_bind(servaddr, cliaddr);
    int len, n;
    n = recvfrom(sockfd, (char *)buffer, MAX_BUFFER,
                 MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                 reinterpret_cast<socklen_t *>(&len));
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(sockfd, (const char *)hello, strlen(hello),
           MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
           len);
    printf("Hello message sent.\n");
}

int ServerManager::create_socket() {
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

int ServerManager::server_bind(sockaddr_in servaddr, sockaddr_in cliaddr) {
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port_no);

    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,
              sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}
