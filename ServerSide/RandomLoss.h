//
// Created by sohayla on 10/12/19.
//

#ifndef RDTOVERUDP_RANDOMLOSS_H
#define RDTOVERUDP_RANDOMLOSS_H

#include <set>

class RandomLoss {
private:
    float plp;
    std::set<int> lost_index;
    int random_seed;
    void randomize(int size);

public:
    RandomLoss(float plp, int seed, int size);
    bool can_send(int seqno);

};


#endif //RDTOVERUDP_RANDOMLOSS_H
