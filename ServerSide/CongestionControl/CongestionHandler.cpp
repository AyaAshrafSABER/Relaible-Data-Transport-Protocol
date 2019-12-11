//
// Created by sohayla on 10/12/19.
//

#include "CongestionHandler.h"

CongestionHandler::CongestionHandler() {
    this->threshold = INITIAL_THRESHOLD;
    this->window_size = 1;

    slowstart = new Slowstart(window_size, threshold);
    congestionControl = new CongestionControl(window_size, threshold);
    this->curr_state = SLOW_START;
}

float CongestionHandler::update_window_size(std::string event) {
    if(curr_state == SLOW_START) {
        curr_state = slowstart->update_window_size(event);
        window_size = slowstart->getWindowSize();
        threshold = slowstart->getThreshold();
        if(curr_state == CONGESTION_CONTROL) {
            congestionControl->set_Wsz(window_size);
            congestionControl->set_threshold(threshold);
        }
    } else if(curr_state == CONGESTION_CONTROL) {
        curr_state = congestionControl->update_window_size(event);
        window_size = congestionControl->getWindowSize();
        threshold = congestionControl->getThreshold();
        if(curr_state == SLOW_START) {
            slowstart->set_Wsz(window_size);
            slowstart->set_threshold(threshold);
        }
    } else {
        perror("Invalid State!");
    }
    return window_size;
}

float CongestionHandler::get_curr_window_size() {
    return window_size;
}

