//
// Created by sohayla on 10/12/19.
//

#ifndef RDTOVERUDP_SLOWSTART_H
#define RDTOVERUDP_SLOWSTART_H


#include "State.h"

class Slowstart  {
private:
    int window_size;
    int threshold;
    STATE self;

public:
    Slowstart(int wsz, int threshold);
    STATE update_window_size(std::string event);
    void set_Wsz(int window_size);
    void set_threshold(int threhold);

    int getWindowSize();
    int getThreshold();


};


#endif //RDTOVERUDP_SLOWSTART_H
