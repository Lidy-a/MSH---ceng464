
#pragma once
#include "menu/commands.hpp"
#include "menu/input.hpp"
#include "menu/services.hpp"
#include <iostream>

class Controller {
public:
  Controller(IDeviceService &d, IModeService &m, ISecurityService &s,
             ISnapshotService &snap, ILogger &log);

  void run();

private:
  IDeviceService &devices;
  IModeService &modes;
  ISecurityService &security;
  ISnapshotService &snapshots;
  ILogger &logger;

  void devicesMenu();
  void modesMenu();
  void securityMenu();
  void snapshotsMenu();

  // Device commands
  CommandPtr makeListDevicesCmd();
  CommandPtr makeAddDeviceCmd();
  CommandPtr makeRemoveDeviceCmd();
  CommandPtr makeTurnOnCmd();
  CommandPtr makeTurnOffCmd();
  CommandPtr makeStatusCmd();

  // Mode commands
  CommandPtr makeListModesCmd();
  CommandPtr makeSetModeCmd();
  CommandPtr makeCurrentModeCmd();

  // Security commands
  CommandPtr makeArmCmd();
  CommandPtr makeDisarmCmd();
  CommandPtr makeSecurityStatusCmd();
  CommandPtr makeAlertsCmd();

  // Snapshot commands
  CommandPtr makeSaveSnapshotCmd();
  CommandPtr makeListSnapshotsCmd();
  CommandPtr makeRestoreSnapshotCmd();
};
