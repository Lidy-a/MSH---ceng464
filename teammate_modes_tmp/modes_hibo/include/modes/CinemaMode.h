#ifndef CINEMA_MODE_H
#define CINEMA_MODE_H

#include "Mode.h"

class CinemaMode : public Mode {
public:
    CinemaMode() : Mode("Cinema") {}

    void apply(SmartHomeSystem& system) override;
};

#endif
