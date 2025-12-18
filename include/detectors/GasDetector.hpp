#ifndef GAS_DETECTOR_HPP
#define GAS_DETECTOR_HPP

#include "Detector.hpp"
#include <iostream>

class GasDetector : public Detector {
public:
    GasDetector() : Detector("GasDetector") {}

    void detect() {
        if (!active) return;
        std::cout << "[GasDetector] Gas detected!" << std::endl;
        if (observer)
            observer->onDetection("GAS");
    }
};

#endif