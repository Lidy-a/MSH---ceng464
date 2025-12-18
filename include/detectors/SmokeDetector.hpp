#ifndef SMOKE_DETECTOR_HPP
#define SMOKE_DETECTOR_HPP

#include "Detector.hpp"
#include <iostream>

class SmokeDetector : public Detector {
public:
    SmokeDetector() : Detector("SmokeDetector") {}

    void detect() {
        if (!active) return;
        std::cout << "[SmokeDetector] Smoke detected!" << std::endl;
        if (observer)
            observer->onDetection("SMOKE");
    }
};

#endif