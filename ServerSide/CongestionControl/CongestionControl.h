//
// Created by sohayla on 10/12/19.
//

#ifndef RDTOVERUDP_CONGESTIONCONTROL_H
#define RDTOVERUDP_CONGESTIONCONTROL_H


#include "State.h"

class CongestionControl {
private:
    int window_size;
    int threshold;
    STATE self;

public:
    CongestionControl(int wsz, int threshold);
    STATE update_window_size(std::string event);
    void set_Wsz(int window_size);
    void set_threshold(int threhold);
    int getWindowSize();
    int getThreshold();

};


#endif //RDTOVERUDP_CONGESTIONCONTROL_H
