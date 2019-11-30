//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include <cstdint>

#ifndef SERVERSIDE_PACKET_H
#define SERVERSIDE_PACKET_H

#endif //SERVERSIDE_PACKET_H

/* Data-only packets */
struct packet {
    /* Header */
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t seqno;
    /* Data */
    char data[500]; /* Not always 500 bytes, can be less */
};

/* Ack-only packets are only 8 bytes */
struct ack_packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};