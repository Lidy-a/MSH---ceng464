#ifndef ALARM_HPP
#define ALARM_HPP

#include "Device.hpp"

class Alarm : public Device {
public:
    Alarm(const std::string& n = "Home Alarm")
        : Device(n) {}

    void powerOff() {
        std::cout << "ERROR: Alarm cannot be powered OFF!" << std::endl;
    }

    Device* clone() {
        return new Alarm(*this);
    }

    std::string getType() { return "Alarm"; }
};

#endif
