#ifndef LIGHT_HANDLER_HPP
#define LIGHT_HANDLER_HPP

#include "AlarmHandler.hpp"
#include <iostream>

class LightHandler : public AlarmHandler {
public:
    void handle(const std::string& event) {
        std::cout << "[Security] Lights ON due to " << event << std::endl;
        AlarmHandler::handle(event);
    }
};

#endif