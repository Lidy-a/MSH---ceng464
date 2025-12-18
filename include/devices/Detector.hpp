#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include "Device.hpp"

class Detector : public Device {
private:
    std::string detectorType; // Smoke or Gas

public:
    Detector(const std::string& n, const std::string& type)
        : Device(n), detectorType(type) {}

    void powerOff() {
        std::cout << "ERROR: Detector cannot be powered OFF!" << std::endl;
    }

    Device* clone() {
        return new Detector(*this);
    }

    std::string getType() { return detectorType + " Detector"; }
};

#endif
