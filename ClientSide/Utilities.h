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

class Utilities {
private:
    FILE *file;
    int chunk_size;
    int current_chunk_index;

public:
    Utilities(string file_path, int chunk_size=CHUNK_SIZE);
    Utilities();

    void write_chunk(string data);
    void write_chunk_data(int chunk_index, string data);
};


#endif //CLIENTSIDE_UTILITIES_H
