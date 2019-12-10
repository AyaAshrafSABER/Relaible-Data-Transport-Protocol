//
// Created by saber on ١٠‏/١٢‏/٢٠١٩.
//

#include "Utilities.h"

Utilities::Utilities(string file_path, int chunk_size) {
    Utilities::file = fopen(file_path.c_str(), "wa+");
    Utilities::chunk_size = chunk_size;
    Utilities::current_chunk_index = 0;
}

Utilities::Utilities() {
}


void Utilities::write_chunk(string data){
    current_chunk_index++;
    write_chunk_data(current_chunk_index - 1, data);
}

void Utilities::write_chunk_data(int chunk_index, string data) {
    //fseek(FileWriter::file, chunk_index * chunk_size, SEEK_SET);
    cout  << "client wrote "<< data.size()
          << " char" << " as chunk " << chunk_index * chunk_size << endl;
    fwrite(data.c_str(), sizeof(char), data.size(), file);
}
