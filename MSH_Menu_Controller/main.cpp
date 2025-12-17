#include "controller.hpp"
#include "dummy_services.hpp"

int main() {
    DummyDeviceService devices;
    DummyModeService modes;
    DummySecurityService security;
    DummySnapshotService snapshots;
    ConsoleLogger logger;

    Controller controller(devices, modes, security, snapshots, logger);
    controller.run();
    return 0;
}
