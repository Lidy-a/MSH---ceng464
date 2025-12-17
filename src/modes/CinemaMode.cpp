#include "modes/CinemaMode.h"

#include <iostream>

void CinemaMode::apply(SmartHomeSystem& system) {
    (void)system;

    std::cout << "[Mode] Cinema Mode applied: Lights OFF, TV ON, Music OFF" << std::endl;
    std::cout << "[Mode] Cameras and detectors remain ON" << std::endl;
}
