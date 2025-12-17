#include "modes/ModeManager.h"

#include <iostream>

#include "modes/NormalMode.h"
#include "modes/EveningMode.h"
#include "modes/PartyMode.h"
#include "modes/CinemaMode.h"

ModeManager::ModeManager() : currentMode(nullptr) {
    // Create mode objects once
    modes["Normal"] = new NormalMode();
    modes["Evening"] = new EveningMode();
    modes["Party"] = new PartyMode();
    modes["Cinema"] = new CinemaMode();

    // Default mode
    currentMode = modes["Normal"];
}

ModeManager::~ModeManager() {
    for (auto& kv : modes) {
        delete kv.second;
    }
    modes.clear();
    currentMode = nullptr;
}

void ModeManager::setMode(const std::string& name) {
    auto it = modes.find(name);
    if (it == modes.end()) {
        std::cout << "[ModeManager] Invalid mode: " << name << std::endl;
        return;
    }
    currentMode = it->second;
    std::cout << "[ModeManager] Mode changed to: " << currentMode->getName() << std::endl;
}

Mode* ModeManager::getCurrentMode() const {
    return currentMode;
}

std::string ModeManager::getCurrentModeName() const {
    if (!currentMode) return "None";
    return currentMode->getName();
}

void ModeManager::applyCurrentMode(SmartHomeSystem& system) {
    if (!currentMode) {
        std::cout << "[ModeManager] No mode selected." << std::endl;
        return;
    }
    currentMode->apply(system);
}

void ModeManager::displayModes() const {
    std::cout << "Available modes:" << std::endl;
    for (const auto& kv : modes) {
        std::cout << " - " << kv.first << std::endl;
    }
}
