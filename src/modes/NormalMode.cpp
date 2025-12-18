#include "modes/NormalMode.h"

#include <iostream>

void NormalMode::apply(SmartHomeSystem& system) {
    (void)system; // avoid unused warning until integration is ready

    std::cout << "[Mode] Normal Mode applied: Lights ON, TV OFF, Music OFF" << std::endl;
    std::cout << "[Mode] Cameras and detectors remain ON" << std::endl;
}
