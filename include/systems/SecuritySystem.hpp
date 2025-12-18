#ifndef SECURITY_SYSTEM_HPP
#define SECURITY_SYSTEM_HPP

#include "Detector.hpp"
#include "AlarmHandler.hpp"
#include "AlarmTriggerHandler.hpp"
#include "LightHandler.hpp"
#include "CallServiceHandler.hpp"

class SecuritySystem : public Observer {
    AlarmHandler* chain;

public:
    SecuritySystem() {
        AlarmTriggerHandler* alarm = new AlarmTriggerHandler();
        LightHandler* lights = new LightHandler();
        CallServiceHandler* call = new CallServiceHandler();

        alarm->setNext(lights);
        lights->setNext(call);

        chain = alarm;
    }

    void onDetection(const std::string& type) {
        chain->handle(type);
    }
};

#endif