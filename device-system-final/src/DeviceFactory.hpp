#ifndef DEVICE_FACTORY_HPP
#define DEVICE_FACTORY_HPP

#include "Light.hpp"
#include "Camera.hpp"
#include "TV.hpp"
#include "Detector.hpp"
#include "Alarm.hpp"

class DeviceFactory {
public:
    static Device* createLight(const std::string& name) {
        return new Light(name);
    }

    static Device* createCamera(const std::string& name) {
        return new Camera(name);
    }

    static Device* createTV(const std::string& name) {
        return new TV(name);
    }

    static Device* createSmokeDetector(const std::string& name) {
        return new Detector(name, "Smoke");
    }

    static Device* createGasDetector(const std::string& name) {
        return new Detector(name, "Gas");
    }

    static Device* createAlarm() {
        return new Alarm();
    }
};

#endif
