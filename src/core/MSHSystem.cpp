#include "core/MSHSystem.h"
#include <iostream>

// controller + services (teammate subsystem)
#include "devices/DeviceService.hpp"
#include "menu/controller.hpp"
#include "menu/dummy_services.hpp"
#include "menu/logger_adapter.hpp"

void MSHSystem::run() {
  std::cout << "Welcome to My Sweet Home (MSH) ✅\n";
  std::cout << "System Core started...\n";

  // Dummy implementations (temporary, until real subsystems are merged)
  DeviceService devices;
  DummyModeService modes;
  DummySecurityService security;
  DummySnapshotService snapshots;

  // Adapter to your real logger singleton
  LoggerAdapter log;

  Controller controller(devices, modes, security, snapshots, log);
  controller.run();

  std::cout << "Exiting MSH.\n";
}
