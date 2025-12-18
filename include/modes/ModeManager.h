#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <map>
#include <string>

#include "Mode.h"

// forward declaration (Mode.h already forward-declared SmartHomeSystem,
// but we need it here too for applyCurrentMode signature)
class SmartHomeSystem;

class ModeManager {
private:
    Mode* currentMode;
    std::map<std::string, Mode*> modes;

public:
    ModeManager();
    ~ModeManager();

    void setMode(const std::string& name);
    Mode* getCurrentMode() const;
    std::string getCurrentModeName() const;

    void applyCurrentMode(SmartHomeSystem& system);
    void displayModes() const;
};

#endif
