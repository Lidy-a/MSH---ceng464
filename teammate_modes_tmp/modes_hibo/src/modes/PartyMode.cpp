#include "modes/PartyMode.h"

#include <iostream>

void PartyMode::apply(SmartHomeSystem& system) {
    (void)system;

    std::cout << "[Mode] Party Mode applied: Lights ON, TV OFF" << std::endl;
    std::cout << "[Mode] Music ON (simulated)" << std::endl;
    std::cout << "[Mode] Cameras and detectors remain ON" << std::endl;
}
