#ifndef EVENING_MODE_H
#define EVENING_MODE_H

#include "Mode.h"

class EveningMode : public Mode {
public:
    EveningMode() : Mode("Evening") {}

    void apply(SmartHomeSystem& system) override;
};

#endif
