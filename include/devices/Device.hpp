#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>
#include <iostream>

enum PowerState { OFF, ON };

class Device {
protected:
    std::string name;
    PowerState powerState;
    bool active;
    bool failed;

public:
    Device(const std::string& n)
        : name(n), powerState(OFF), active(true), failed(false) {}

    virtual ~Device() {}

    virtual void powerOn() { powerState = ON; }

    virtual void powerOff() { powerState = OFF; }

    void setActive(bool a) { active = a; }

    void reportFailure() {
        failed = true;
        std::cout << "Failure detected in device: " << name << std::endl;
    }

    virtual Device* clone() = 0;   // Prototype
    virtual std::string getType() = 0;
};

#endif
