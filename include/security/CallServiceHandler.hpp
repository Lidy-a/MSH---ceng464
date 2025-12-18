#ifndef CALL_SERVICE_HANDLER_HPP
#define CALL_SERVICE_HANDLER_HPP

#include "AlarmHandler.hpp"
#include <iostream>

class CallServiceHandler : public AlarmHandler {
public:
    void handle(const std::string& event) {
        if (event == "SMOKE")
            std::cout << "[Security] Calling FIRE STATION!" << std::endl;
        else
            std::cout << "[Security] Calling POLICE!" << std::endl;
    }
};

#endif