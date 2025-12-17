#ifndef HIGHPERFORMANCESTATE_H
#define HIGHPERFORMANCESTATE_H

#include "State.h"
#include <iostream>

class HighPerformanceState : public State {
public:
    void applySettings() override;
};

#endif
