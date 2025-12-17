#include "DeviceFactory.hpp"
#include <vector>

int main() {
    std::vector<Device*> devices;

    Device* l1 = DeviceFactory::createLight("Philips-A1");
    Device* l2 = l1->clone();   // Prototype copy

    Device* cam = DeviceFactory::createCamera("Sony-Cam");
    Device* alarm = DeviceFactory::createAlarm();

    devices.push_back(l1);
    devices.push_back(l2);
    devices.push_back(cam);
    devices.push_back(alarm);

    alarm->powerOff(); // should be blocked

    cam->reportFailure();

    return 0;
}
