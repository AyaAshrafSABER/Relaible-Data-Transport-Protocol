//
// Created by sohayla on 10/12/19.
//

#include "Slowstart.h"
Slowstart::Slowstart(float wsz, int threshold) {
    this->window_size = wsz;
    this->threshold = threshold;
    self = SLOW_START;
}

STATE Slowstart::update_window_size(std::string event) {
    /* timeout event has happened
  * decrease threshold and remain in slow start state */
    if(event == "TIMEOUT" || event == "DUP")
    {
        threshold = threshold > window_size/2 ? threshold : window_size/2 ;//std::max(threshold, window_size / 2) ;
        window_size = 1 ;
    }
        /* acknowledgment is received, increase window size by MSS every ACK*/
    else if(event == "ACK")
    {
        window_size += 1 ;
    }

    /* when windows reach threshold transfer state to congestion control */
    if(window_size >= threshold)
    {
        return CONGESTION_CONTROL;
    }
    return self;
}

int Slowstart::getThreshold() {
    return threshold;
}

float Slowstart::getWindowSize() {
    return window_size;
}

void Slowstart::set_threshold(int threshold) {
    this->threshold = threshold;
}

void Slowstart::set_Wsz(int window_size) {
    this->window_size = window_size;
}