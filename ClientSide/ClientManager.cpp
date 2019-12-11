//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include "ClientManager.h"
#include "Sender.h"
#include "Receiver.h"



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
    std::cout << ip_address << "/ " << port << "/ " << requested_file << std::endl;
}

void ClientManager::run_client() {
     sockfd = init_socket();
     servaddr = init_server();

}

int ClientManager::init_socket() {
    // Creating socket file descriptor
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

void ClientManager::receive_file() {
    //start logic  creat packet and sent to the server
    uint32_t number_of_packets = send_request_to_Server();
    cout << "client receive " << number_of_packets << " packet from server" << endl;

    Receiver gbn(requested_file, sockfd, servaddr, number_of_packets);
    gbn.GBNstart();

    printf("Client finished\n");

    closeClient(sockfd);
}

uint32_t ClientManager::send_request_to_Server() {
    printf("Start sending req.\n");
    // send the file name packet
    Packet packet = PacketHandler::create_packet(strdup(requested_file.c_str()), 0 , requested_file.size());
   // Ack_Packet packet = PacketHandler::create_ack_packet(0, 5);
    Sender sender = Sender(servaddr);
    sender.send_packet(packet, sockfd);
    printf("Socket address %d", sockfd);

    printf("req sent.\n");
    /*
     * wait until receive ack from server
     */
    Ack_Server_Packet server_ack_packet =  Receiver::receive_ack_server_packet(sockfd, servaddr);
    printf("ack received.\n");
    return server_ack_packet.packets_numbers;

}
