//
// Created by sohayla on 10/12/19.
//

#include <cmath>
#include <iostream>
#include "RandomLoss.h"


RandomLoss::RandomLoss(float plp, int seed, int size) {
    this->plp = plp;
    this->random_seed = seed;
    randomize(size);
}

void RandomLoss::randomize(int size) {
    int num_lost_packets = (int)ceil(plp * size);

    srand(random_seed);
    for(int i = 0 ; i < num_lost_packets; i++ ){
        int random_val = rand() % size;
        std::cout << "lost index : " << random_val << std::endl;
        lost_index.insert(random_val);
    }
}

bool RandomLoss::can_send(int seqno) {
    if(lost_index.count(seqno)) {
        lost_index.erase(seqno);
        return false;
    }
    return true;
}
