#ifndef ALARM_HPP
#define ALARM_HPP

#include <iostream>

class Alarm {
public:
    void trigger() {
        std::cout << "[Alarm] Alarm is ACTIVE!" << std::endl;
    }
};

#endif