#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Device.hpp"

class Camera : public Device {
private:
    int resolution;
    int fps;

public:
    Camera(const std::string& n, int r = 1080, int f = 30)
        : Device(n), resolution(r), fps(f) {}

    Device* clone() {
        return new Camera(*this);
    }

    std::string getType() { return "Camera"; }
};

#endif
