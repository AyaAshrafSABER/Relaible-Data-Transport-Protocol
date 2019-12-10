//
// Created by saber on ١٠‏/١٢‏/٢٠١٩.
//

#include "Utilities.h"

Utilities::Utilities(string file_path, int chunk_size) {
    Utilities::file = fopen(file_path.c_str(), "rb");
    file_path = file_path.c_str();
    if (!file){
        perror("No Existing File at server");
    }
    Utilities::chunk_size = chunk_size;
    Utilities::current_chunk_index = 0;
}

Utilities::Utilities(const char* file_path, int chunk_size) {
    Utilities::file = fopen(file_path, "rb");
    file_path = file_path;
    if (!file){
        perror("No Existing File at server");
    }
    Utilities::chunk_size = chunk_size;
    Utilities::current_chunk_index = 0;
}

int Utilities::get_file_size() {
    fseek(file, 0, SEEK_END);
    int x = ftell(file);
    rewind(file);
    return x;
}

int Utilities::get_current_chunk_index() {
    return current_chunk_index;
}

Packet Utilities::get_current_chunk_data() {
    if(is_finished()){
        perror("No remaining bytes to be read");
        return Packet();
    }
    current_chunk_index++;
    return get_chunk_data(current_chunk_index - 1);
}

void Utilities::advance_chunk_pointer() {
    current_chunk_index++;
}

Packet Utilities::get_chunk_data(int chunk_index) {
    int size = min(chunk_size, get_file_size() - (chunk_index*chunk_size));
    char * buffer = (char*) malloc(size);
    int bytes_readed;
    fseek(Utilities::file, chunk_index * chunk_size, SEEK_SET);
    bytes_readed = fread (buffer, sizeof(char), size, file);
    Packet packet = PacketHandler::create_packet(buffer, chunk_index, bytes_readed);
    return packet;
}

bool Utilities::is_finished(){
    return ftell(file) == get_file_size();
}

int Utilities::get_total_packet_number(){
    return ceil(1.0 * get_file_size() / Utilities::chunk_size);
}

void Utilities::close(){
    fclose(file);
}