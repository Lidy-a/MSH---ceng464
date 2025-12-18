#ifndef ALARM_TRIGGER_HANDLER_HPP
#define ALARM_TRIGGER_HANDLER_HPP

#include "AlarmHandler.hpp"
#include "Alarm.hpp"
#include <iostream>

class AlarmTriggerHandler : public AlarmHandler {
    Alarm alarm;

public:
    void handle(const std::string& event) {
        std::cout << "[Security] Triggering alarm for " << event << std::endl;
        alarm.trigger();
        AlarmHandler::handle(event);
    }
};

#endif