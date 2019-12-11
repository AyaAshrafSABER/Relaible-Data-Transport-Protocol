//
// Created by sohayla on 10/12/19.
//

#ifndef RDTOVERUDP_CONGESTIONCONTROL_H
#define RDTOVERUDP_CONGESTIONCONTROL_H


#include "State.h"

class CongestionControl {
private:
    float window_size;
    int threshold;
    STATE self;

public:
    CongestionControl(float wsz, int threshold);
    STATE update_window_size(std::string event);
    void set_Wsz(int window_size);
    void set_threshold(int threhold);

    float getWindowSize();
    int getThreshold();

};


#endif //RDTOVERUDP_CONGESTIONCONTROL_H
