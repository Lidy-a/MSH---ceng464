#ifndef TV_HPP
#define TV_HPP

#include "Device.hpp"

class TV : public Device {
private:
    int screenSize;

public:
    TV(const std::string& n, int s = 55)
        : Device(n), screenSize(s) {}

    Device* clone() {
        return new TV(*this);
    }

    std::string getType() { return "TV"; }
};

#endif
