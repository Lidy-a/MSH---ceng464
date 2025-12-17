#ifndef LOWPOWERSTATE_H
#define LOWPOWERSTATE_H

#include "State.h"
#include <iostream>

class LowPowerState : public State {
public:
    void applySettings() override {
        std::cout << "Applying Low Power state settings...\n";
        // Set device settings for low power state, like turning off devices, reducing brightness, etc.
    }
};

#endif
