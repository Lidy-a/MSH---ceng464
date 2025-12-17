#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Device.hpp"

class Light : public Device {
private:
    int brightness;
    std::string color;

public:
    Light(const std::string& n, int b = 100, const std::string& c = "White")
        : Device(n), brightness(b), color(c) {}

    Device* clone() {
        return new Light(*this);
    }

    std::string getType() { return "Light"; }
};

#endif
