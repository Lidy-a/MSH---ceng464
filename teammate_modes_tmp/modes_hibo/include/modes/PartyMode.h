#ifndef PARTY_MODE_H
#define PARTY_MODE_H

#include "Mode.h"

class PartyMode : public Mode {
public:
    PartyMode() : Mode("Party") {}

    void apply(SmartHomeSystem& system) override;
};

#endif
