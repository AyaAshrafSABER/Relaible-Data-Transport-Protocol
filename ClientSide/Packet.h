//
// Created by saber on ٣٠‏/١١‏/٢٠١٩.
//

#include <cstdint>

#ifndef CLIENTSIDE_PACKET_H
#define CLIENTSIDE_PACKET_H

#endif //CLIENTSIDE_PACKET_H


/* Data-only packets */
 struct Packet {
     /* Header */
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t seqno;
    /* Data */
    char data[500]; /* Not always 500 bytes, can be less */
 };

/* Ack-only packets are only 8 bytes */
struct Ack_Packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};