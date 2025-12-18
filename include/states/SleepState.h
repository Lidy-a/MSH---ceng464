#ifndef SLEEPSTATE_H
#define SLEEPSTATE_H

#include "State.h"
#include <iostream>

class SleepState : public State {
public:
    void applySettings() override;
};

#endif
