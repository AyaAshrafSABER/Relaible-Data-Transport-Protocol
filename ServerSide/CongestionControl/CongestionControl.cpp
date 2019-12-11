//
// Created by sohayla on 10/12/19.
//

#include <cmath>
#include "CongestionControl.h"

CongestionControl::CongestionControl(float wsz, int threshold) {
    this->window_size = wsz;
    this->threshold = threshold;
    self = CONGESTION_CONTROL;
}

STATE CongestionControl::update_window_size(std::string event) {
        /*
         * 3 duplicate ack will reduce the window size to 1, and update the threshold
         * */
        if(event == "DUP"){
            threshold = window_size / 2 ;
            window_size = 1;
            return SLOW_START;

        }
            /* timeout event has happened
             * decrease threshold and transfer to slow start state */
        else if(event == "TIMEOUT")
        {
            threshold = window_size / 2 ;
            window_size = threshold;
        }
            /* acknowledgement is received rather than doubling the value of cwnd every RTT,
             * TCP adopts a more conservative approach and increases the value of cwnd by
             * just a single MSS every RTT */
        else if(event == "ACK")
        {
            float addition = 1/floor(window_size);
            window_size = window_size+addition < MAX_WINDOW_SZ ? window_size+addition : MAX_WINDOW_SZ;
            //std::min(window_size + addition , MAX_WINDOW_SZ);
        }

        return self ;
}

int CongestionControl::getThreshold() {
    return threshold;
}

float CongestionControl::getWindowSize() {
    return window_size;
}

void CongestionControl::set_threshold(int threshold) {
    this->threshold = threshold;
}

void CongestionControl::set_Wsz(int window_size) {
    this->window_size = window_size;
}
