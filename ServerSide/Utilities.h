//
// Created by saber on ١٠‏/١٢‏/٢٠١٩.
//

#ifndef CLIENTSIDE_UTILITIES_H
#define CLIENTSIDE_UTILITIES_H
using namespace std;

#include <string>
#include <iostream>
#include "Packet.h"
#include "PacketHandler.h"
#define CHUNK_SIZE 500
using namespace std;

#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>

#include "Packet.h"
#include "PacketHandler.h"

class Utilities {
private:
    FILE *file;
    int chunk_size;
    int current_chunk_index;
    char* file_path;

public:
    explicit Utilities(const char* file_path, int chunk_size=CHUNK_SIZE);
    explicit Utilities(string file_path, int chunk_size=CHUNK_SIZE);

    int get_file_size();
    bool is_finished();
    int get_current_chunk_index();
    void set_chunk_index(int index);
    Packet get_current_chunk_data();
    Packet get_chunk_data(int chunk_index);
    void advance_chunk_pointer();
    int get_total_packet_number();
    void close();
};

#endif //CLIENTSIDE_UTILITIES_H
