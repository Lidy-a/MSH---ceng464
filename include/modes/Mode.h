#ifndef MODE_H
#define MODE_H

#include <string>

// Forward declaration to avoid include cycles
class SmartHomeSystem;

class Mode {
protected:
    std::string name;

public:
    explicit Mode(const std::string& modeName) : name(modeName) {}
    virtual ~Mode() = default;

    virtual void apply(SmartHomeSystem& system) = 0;

    std::string getName() const {
        return name;
    }
};

#endif

