#include "modes/EveningMode.h"

#include <iostream>

void EveningMode::apply(SmartHomeSystem& system) {
    (void)system;

    std::cout << "[Mode] Evening Mode applied: Lights OFF, TV OFF, Music OFF" << std::endl;
    std::cout << "[Mode] Cameras and detectors remain ON" << std::endl;
}
