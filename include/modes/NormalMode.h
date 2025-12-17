#ifndef NORMAL_MODE_H
#define NORMAL_MODE_H

#include "Mode.h"

class NormalMode : public Mode {
public:
    NormalMode() : Mode("Normal") {}

    void apply(SmartHomeSystem& system) override;
};

#endif
