#ifndef NORMALSTATE_H
#define NORMALSTATE_H

#include "State.h"  // Include the base class header
#include <iostream>

class NormalState : public State {
public:
    void applySettings() override;  // Override the applySettings method
};

#endif
