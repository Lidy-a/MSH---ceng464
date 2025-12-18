#ifndef DETECTION_SYSTEM_HPP
#define DETECTION_SYSTEM_HPP

#include "SmokeDetector.hpp"
#include "GasDetector.hpp"
#include "SecuritySystem.hpp"

class DetectionSystem {
    SmokeDetector smoke;
    GasDetector gas;

public:
    DetectionSystem(SecuritySystem* sec) {
        smoke.attach(sec);
        gas.attach(sec);
    }

    void simulateSmoke() { smoke.detect(); }
    void simulateGas() { gas.detect(); }
};

#endif