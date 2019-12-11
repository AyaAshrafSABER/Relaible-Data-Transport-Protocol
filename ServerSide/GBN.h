//
// Created by sohayla on 10/12/19.
//

#ifndef RDTOVERUDP_GBN_H
#define RDTOVERUDP_GBN_H

#include "RandomLoss.h"
#include "CongestionControl/CongestionHandler.h"
#include "Packet.h"
#include "Sender.h"
#include "Utilities.h"


#include <bits/stdc++.h>
#include <stdint.h>
#include <ctime>
#include <string>
#include <vector>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <set>

class GBN {
    int base = 0;
    ofstream myfile;
    int next_seq_num = 0;
    RandomLoss* randomizer;
    clock_t timer = 0;
    double threshold = 10;/* threshold of timeout 10 seconds.*/
    Utilities file_utility;
    //FileReader fileReader;
    int client_fd;
    float plp;
    struct sockaddr_in client_socket;
    Sender sender;
    std::vector<int> window_changes;
    int i = 0;
    int total_packets;
    CongestionHandler* congestionHandler;
    int duplicateAcks;
    queue<Packet> sentpkt;




    clock_t start_timer();

    bool check_timeout();

    void time_out();

    void resend_all();

    void stop_timer();
    void remove_packet_from_queue(int ack_no);

public:
    GBN(std::string file_name, int client_fd, int seed, double PLP, struct sockaddr_in client_socket, int size);

    void start();

    void gbn_recv(Ack_Packet pkt);

    void data_listener();

    void gbn_recv();

    bool gbn_send(Packet pkt);

    void get_loss_packets(double loss_prob, int seed_number);

    bool congestion_time();

};


#endif //RDTOVERUDP_GBN_H
