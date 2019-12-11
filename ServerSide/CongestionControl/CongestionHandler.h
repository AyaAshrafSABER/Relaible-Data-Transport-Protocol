//
// Created by sohayla on 10/12/19.
//

#ifndef RDTOVERUDP_CONGESTIONHANDLER_H
#define RDTOVERUDP_CONGESTIONHANDLER_H


#include "Slowstart.h"
#include "CongestionControl.h"
#define INITIAL_THRESHOLD 8

class CongestionHandler {
private:
    float window_size;
  Slowstart * slowstart;
  CongestionControl* congestionControl;
  int threshold;
  STATE curr_state;

public:
    CongestionHandler();
    STATE getCurrentState();

    float update_window_size(std::string event);

    float get_curr_window_size();
};


#endif //RDTOVERUDP_CONGESTIONHANDLER_H
