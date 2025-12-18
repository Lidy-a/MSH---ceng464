#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include <string>

class Observer {
public:
    virtual void onDetection(const std::string& type) = 0;
    virtual ~Observer() {}
};

class Detector {
protected:
    Observer* observer;
    bool active;
    std::string name;

public:
    Detector(const std::string& n) : observer(0), active(true), name(n) {}
    virtual ~Detector() {}

    void attach(Observer* obs) { observer = obs; }

    void setActive(bool state) { active = state; }
    bool isActive() const { return active; }

    virtual void detect() = 0;
};

#endif