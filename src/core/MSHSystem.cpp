#include <iostream>
#include "core/MSHSystem.h"
#include "logging/Logger.h"


void MSHSystem::run() {
    std::cout << "Welcome to My Sweet Home (MSH) ✅" << std::endl;
    std::cout << "System Core started..." << std::endl;

    // Placeholder: later this will show the real menu
    std::cout << "[Menu placeholder] 1) Status 2) Manual 3) Shutdown" << std::endl;

    std::cout << "Exiting MSH (placeholder run)." << std::endl;
    Logger::getInstance()->log("System started (test)");

}
