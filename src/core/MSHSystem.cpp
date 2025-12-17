#include "core/MSHSystem.h"
#include <iostream>

// controller + services (teammate subsystem)
#include "devices/DeviceService.hpp"
#include "menu/controller.hpp"
#include "menu/dummy_services.hpp"
#include "menu/logger_adapter.hpp"
#include "modes/ModeService.hpp"
#include "states/StateService.hpp"

void MSHSystem::run() {
  std::cout << "Welcome to My Sweet Home (MSH) ✅\n";
  std::cout << "System Core started...\n";

  DeviceService devices;
  ModeService modes;
  StateService states;
  DummySecurityService security;
  DummySnapshotService snapshots;

  // Adapter to your real logger singleton
  LoggerAdapter log;

  Controller controller(devices, modes, security, snapshots, states, log);
  controller.run();

  std::cout << "Exiting MSH.\n";
}
