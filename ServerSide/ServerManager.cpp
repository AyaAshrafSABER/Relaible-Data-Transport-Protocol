//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include <chrono>
#include "ServerManager.h"
#include "Packet.h"
#include "Receiver.h"
#include "Sender.h"
#include "Utilities.h"
#include "GBN.h"

ServerManager::ServerManager(int port, int randomG, float p) {
    ServerManager::port_no = port;
    ServerManager::random_generator_seed = randomG;
    ServerManager::data_loss_prob = p;
    cout<<port<<endl;

}

void ServerManager::start_server() {
    char buffer[MAX_BUFFER];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
    create_socket();
    server_bind(servaddr, cliaddr);
    run();
    /*int len, n;
    n = recvfrom(sockfd, (char *)buffer, MAX_BUFFER,
                 MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                 reinterpret_cast<socklen_t *>(&len));
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(sockfd, (const char *)hello, strlen(hello),
           MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
           len);
    printf("Hello message sent.\n");*/
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

void ServerManager::run() {
    printf("Server is waiting for clients\n");
    /* server main loop */
    printf("Successfully Connected with a Client\n");
    struct sockaddr_in client_address;
    // receive the file name
    memset(&client_address, 0, sizeof(client_address));
    socklen_t addrlen = sizeof(client_address);
    Packet packet = Receiver::receive_packet(sockfd, client_address);
    printf("packet recevied.\n");
    // checking the file
    cout << packet.data <<endl;
    string file_name(packet.data, packet.len);
    Utilities file_utility(file_name.c_str(), CHUNK_SIZE);

    int number_of_packets = ceil(file_utility.get_file_size() * 1.0 / CHUNK_SIZE);
    // sending the ack with the number of packets which will be sended

    Sender sender = Sender(client_address);
    Ack_Server_Packet server_ack_packet;
    server_ack_packet.packets_numbers = number_of_packets;
    sender.send_server_ack(server_ack_packet, sockfd);
    cout << "file size is " << file_utility.get_file_size() << endl;
    cout << "transfering " << ceil(1.0 * file_utility.get_file_size() / CHUNK_SIZE) << " packet" <<endl;
    // call the desired method to send the file
    file_utility.close();
    auto start = std::chrono::high_resolution_clock::now();
    // GBN
    GBN gbn(file_name, sockfd,random_generator_seed, data_loss_prob, client_address,number_of_packets);

    gbn.start();
    printf("Finished Client\n");
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

}
