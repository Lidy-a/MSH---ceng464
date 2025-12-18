
#include "menu/controller.hpp"
#include "menu/services.hpp"
#include <unordered_map>

// ---------------- Controller basic wiring ----------------
Controller::Controller(IDeviceService &d, IModeService &m, ISecurityService &s,
                       ISnapshotService &snap, IStateService &st, ILogger &log)
    : devices(d), modes(m), security(s), snapshots(snap), states(st),
      logger(log) {}

void Controller::run() {
  logger.info("MSH started");

  bool running = true;
  while (running) {
    std::cout << "\n=== MY SWEET HOME (MSH) ===\n"
              << "1) Devices\n"
              << "2) Modes\n"
              << "3) Security\n"
              << "4) Snapshots\n"
              << "5) States\n"
              << "0) Exit\n";

    int c = readInt("Choose: ", 0, 5);

    switch (c) {
    case 1:
      devicesMenu();
      break;
    case 2:
      modesMenu();
      break;
    case 3:
      securityMenu();
      break;
    case 4:
      snapshotsMenu();
      break;
    case 5:
      statesMenu();
      break;
    case 0:
      running = false;
      logger.info("MSH exiting");
      break;
    default:
      break;
    }
  }

  std::cout << "Bye.\n";
}

// ---------------- Commands (small classes) ----------------
class ListDevicesCmd : public ICommand {
  IDeviceService &devices;
  ILogger &log;

public:
  ListDevicesCmd(IDeviceService &d, ILogger &l) : devices(d), log(l) {}
  void execute() override {
    auto list = devices.listDevices();
    if (list.empty())
      std::cout << "(no devices)\n";
    else
      for (auto &s : list)
        std::cout << s << "\n";
    log.info("Listed devices");
  }
};

class AddDeviceCmd : public ICommand {
  IDeviceService &devices;
  ILogger &log;

public:
  AddDeviceCmd(IDeviceService &d, ILogger &l) : devices(d), log(l) {}
  void execute() override {
    std::string type = readLine("Type (Light/AC/...): ");
    std::string name = readLine("Name: ");
    std::string id = devices.createDevice(type, name);
    std::cout << "Created device id: " << id << "\n";
    log.info("Created device " + id);
  }
};

class RemoveDeviceCmd : public ICommand {
  IDeviceService &devices;
  ILogger &log;

public:
  RemoveDeviceCmd(IDeviceService &d, ILogger &l) : devices(d), log(l) {}
  void execute() override {
    std::string id = readLine("Device id: ");
    bool ok = devices.removeDevice(id);
    std::cout << (ok ? "Removed.\n" : "Not found.\n");
    log.info(std::string("Remove device ") + id + (ok ? " OK" : " FAIL"));
  }
};

class TurnOnCmd : public ICommand {
  IDeviceService &devices;
  ILogger &log;

public:
  TurnOnCmd(IDeviceService &d, ILogger &l) : devices(d), log(l) {}
  void execute() override {
    std::string id = readLine("Device id: ");
    bool ok = devices.turnOn(id);
    std::cout << (ok ? "ON.\n" : "Failed.\n");
    log.info(std::string("Turn ON ") + id + (ok ? " OK" : " FAIL"));
  }
};

class TurnOffCmd : public ICommand {
  IDeviceService &devices;
  ILogger &log;

public:
  TurnOffCmd(IDeviceService &d, ILogger &l) : devices(d), log(l) {}
  void execute() override {
    std::string id = readLine("Device id: ");
    bool ok = devices.turnOff(id);
    std::cout << (ok ? "OFF.\n" : "Failed.\n");
    log.info(std::string("Turn OFF ") + id + (ok ? " OK" : " FAIL"));
  }
};

class StatusCmd : public ICommand {
  IDeviceService &devices;
  ILogger &log;

public:
  StatusCmd(IDeviceService &d, ILogger &l) : devices(d), log(l) {}
  void execute() override {
    std::string id = readLine("Device id: ");
    std::cout << devices.status(id) << "\n";
    log.info("Device status checked " + id);
  }
};

// Modes
class ListModesCmd : public ICommand {
  IModeService &modes;
  ILogger &log;

public:
  ListModesCmd(IModeService &m, ILogger &l) : modes(m), log(l) {}
  void execute() override {
    for (auto &s : modes.listModes())
      std::cout << s << "\n";
    log.info("Listed modes");
  }
};

class SetModeCmd : public ICommand {
  IModeService &modes;
  ILogger &log;

public:
  SetModeCmd(IModeService &m, ILogger &l) : modes(m), log(l) {}
  void execute() override {
    std::string mode = readLine("Mode name: ");
    bool ok = modes.setMode(mode);
    std::cout << (ok ? "Mode set.\n" : "Invalid mode.\n");
    log.info(std::string("Set mode ") + mode + (ok ? " OK" : " FAIL"));
  }
};

class CurrentModeCmd : public ICommand {
  IModeService &modes;
  ILogger &log;

public:
  CurrentModeCmd(IModeService &m, ILogger &l) : modes(m), log(l) {}
  void execute() override {
    std::cout << "Current: " << modes.currentMode() << "\n";
    log.info("Checked current mode");
  }
};

// Security
class ArmCmd : public ICommand {
  ISecurityService &sec;
  ILogger &log;

public:
  ArmCmd(ISecurityService &s, ILogger &l) : sec(s), log(l) {}
  void execute() override {
    bool ok = sec.arm();
    std::cout << (ok ? "Armed.\n" : "Failed.\n");
    log.info(std::string("Arm ") + (ok ? "OK" : "FAIL"));
  }
};

class DisarmCmd : public ICommand {
  ISecurityService &sec;
  ILogger &log;

public:
  DisarmCmd(ISecurityService &s, ILogger &l) : sec(s), log(l) {}
  void execute() override {
    bool ok = sec.disarm();
    std::cout << (ok ? "Disarmed.\n" : "Failed.\n");
    log.info(std::string("Disarm ") + (ok ? "OK" : "FAIL"));
  }
};

class SecurityStatusCmd : public ICommand {
  ISecurityService &sec;
  ILogger &log;

public:
  SecurityStatusCmd(ISecurityService &s, ILogger &l) : sec(s), log(l) {}
  void execute() override {
    std::cout << sec.status() << "\n";
    log.info("Checked security status");
  }
};

class AlertsCmd : public ICommand {
  ISecurityService &sec;
  ILogger &log;

public:
  AlertsCmd(ISecurityService &s, ILogger &l) : sec(s), log(l) {}
  void execute() override {
    for (auto &a : sec.recentAlerts())
      std::cout << a << "\n";
    log.info("Viewed alerts");
  }
};

// Snapshots
class SaveSnapshotCmd : public ICommand {
  ISnapshotService &snap;
  ILogger &log;

public:
  SaveSnapshotCmd(ISnapshotService &s, ILogger &l) : snap(s), log(l) {}
  void execute() override {
    std::string note = readLine("Note: ");
    std::string id = snap.saveSnapshot(note);
    std::cout << "Saved snapshot id: " << id << "\n";
    log.info("Saved snapshot " + id);
  }
};

class ListSnapshotsCmd : public ICommand {
  ISnapshotService &snap;
  ILogger &log;

public:
  ListSnapshotsCmd(ISnapshotService &s, ILogger &l) : snap(s), log(l) {}
  void execute() override {
    for (auto &s : snap.listSnapshots())
      std::cout << s << "\n";
    log.info("Listed snapshots");
  }
};

class RestoreSnapshotCmd : public ICommand {
  ISnapshotService &snap;
  ILogger &log;

public:
  RestoreSnapshotCmd(ISnapshotService &s, ILogger &l) : snap(s), log(l) {}
  void execute() override {
    std::string id = readLine("Snapshot id: ");
    bool ok = snap.restoreSnapshot(id);
    std::cout << (ok ? "Restored.\n" : "Failed.\n");
    log.info(std::string("Restore snapshot ") + id + (ok ? " OK" : " FAIL"));
  }
};

// -------- Controller menus (routing) --------
CommandPtr Controller::makeListDevicesCmd() {
  return std::make_unique<ListDevicesCmd>(devices, logger);
}
CommandPtr Controller::makeAddDeviceCmd() {
  return std::make_unique<AddDeviceCmd>(devices, logger);
}
CommandPtr Controller::makeRemoveDeviceCmd() {
  return std::make_unique<RemoveDeviceCmd>(devices, logger);
}
CommandPtr Controller::makeTurnOnCmd() {
  return std::make_unique<TurnOnCmd>(devices, logger);
}
CommandPtr Controller::makeTurnOffCmd() {
  return std::make_unique<TurnOffCmd>(devices, logger);
}
CommandPtr Controller::makeStatusCmd() {
  return std::make_unique<StatusCmd>(devices, logger);
}

CommandPtr Controller::makeListModesCmd() {
  return std::make_unique<ListModesCmd>(modes, logger);
}
CommandPtr Controller::makeSetModeCmd() {
  return std::make_unique<SetModeCmd>(modes, logger);
}
CommandPtr Controller::makeCurrentModeCmd() {
  return std::make_unique<CurrentModeCmd>(modes, logger);
}

CommandPtr Controller::makeArmCmd() {
  return std::make_unique<ArmCmd>(security, logger);
}
CommandPtr Controller::makeDisarmCmd() {
  return std::make_unique<DisarmCmd>(security, logger);
}
CommandPtr Controller::makeSecurityStatusCmd() {
  return std::make_unique<SecurityStatusCmd>(security, logger);
}
CommandPtr Controller::makeAlertsCmd() {
  return std::make_unique<AlertsCmd>(security, logger);
}

CommandPtr Controller::makeSaveSnapshotCmd() {
  return std::make_unique<SaveSnapshotCmd>(snapshots, logger);
}
CommandPtr Controller::makeListSnapshotsCmd() {
  return std::make_unique<ListSnapshotsCmd>(snapshots, logger);
}
CommandPtr Controller::makeRestoreSnapshotCmd() {
  return std::make_unique<RestoreSnapshotCmd>(snapshots, logger);
}

void Controller::devicesMenu() {
  std::unordered_map<int, CommandPtr> cmd;
  cmd.emplace(1, makeListDevicesCmd());
  cmd.emplace(2, makeAddDeviceCmd());
  cmd.emplace(3, makeRemoveDeviceCmd());
  cmd.emplace(4, makeTurnOnCmd());
  cmd.emplace(5, makeTurnOffCmd());
  cmd.emplace(6, makeStatusCmd());

  while (true) {
    std::cout << "\n--- Devices ---\n"
              << "1) List devices\n"
              << "2) Add device\n"
              << "3) Remove device\n"
              << "4) Turn ON\n"
              << "5) Turn OFF\n"
              << "6) Device status\n"
              << "0) Back\n";

    int c = readInt("Choose: ", 0, 6);
    if (c == 0)
      return;

    auto it = cmd.find(c);
    if (it != cmd.end())
      it->second->execute();
    else
      std::cout << "Invalid.\n";
  }
}

void Controller::modesMenu() {
  auto listCmd = makeListModesCmd();
  auto setCmd = makeSetModeCmd();
  auto curCmd = makeCurrentModeCmd();

  while (true) {
    std::cout << "\n--- Modes ---\n"
              << "1) List modes\n"
              << "2) Set mode\n"
              << "3) Current mode\n"
              << "0) Back\n";

    int c = readInt("Choose: ", 0, 3);
    if (c == 0)
      return;

    if (c == 1)
      listCmd->execute();
    else if (c == 2)
      setCmd->execute();
    else if (c == 3)
      curCmd->execute();
  }
}

void Controller::securityMenu() {
  auto armCmd = makeArmCmd();
  auto disCmd = makeDisarmCmd();
  auto statCmd = makeSecurityStatusCmd();
  auto alertCmd = makeAlertsCmd();

  while (true) {
    std::cout << "\n--- Security ---\n"
              << "1) Arm\n"
              << "2) Disarm\n"
              << "3) Status\n"
              << "4) Recent alerts\n"
              << "0) Back\n";

    int c = readInt("Choose: ", 0, 4);
    if (c == 0)
      return;

    if (c == 1)
      armCmd->execute();
    else if (c == 2)
      disCmd->execute();
    else if (c == 3)
      statCmd->execute();
    else if (c == 4)
      alertCmd->execute();
  }
}

void Controller::snapshotsMenu() {
  auto saveCmd = makeSaveSnapshotCmd();
  auto listCmd = makeListSnapshotsCmd();
  auto resCmd = makeRestoreSnapshotCmd();

  while (true) {
    std::cout << "\n--- Snapshots ---\n"
              << "1) Save snapshot\n"
              << "2) List snapshots\n"
              << "3) Restore snapshot\n"
              << "0) Back\n";

    int c = readInt("Choose: ", 0, 3);
    if (c == 0)
      return;

    if (c == 1)
      saveCmd->execute();
    else if (c == 2)
      listCmd->execute();
    else if (c == 3)
      resCmd->execute();
  }
}

void Controller::statesMenu() {
  while (true) {
    std::cout << "\n--- States ---\n";
    std::cout << "1) Show current\n";
    std::cout << "2) Set state\n";
    std::cout << "3) Previous state\n";
    std::cout << "4) Next state\n";
    std::cout << "5) List history\n";
    std::cout << "0) Back\n";
    std::cout << "Choose: ";

    int c;
    if (!(std::cin >> c)) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      continue;
    }

    if (c == 0)
      return;

    if (c == 1) {
      std::cout << "Current: " << states.currentState() << "\n";
    } else if (c == 2) {
      std::cout << "Enter state (Normal/Sleep/LowPower/HighPerformance): ";
      std::string s;
      std::cin >> s;
      bool ok = states.setState(s);
      std::cout << (ok ? "State set.\n" : "Invalid state.\n");
    } else if (c == 3) {
      bool ok = states.prevState();
      std::cout << (ok ? "Moved to previous.\n" : "No previous state.\n");
      std::cout << "Current: " << states.currentState() << "\n";
    } else if (c == 4) {
      bool ok = states.nextState();
      std::cout << (ok ? "Moved to next.\n" : "No next state.\n");
      std::cout << "Current: " << states.currentState() << "\n";
    } else if (c == 5) {
      auto h = states.listHistory();
      for (auto &line : h)
        std::cout << line << "\n";
    }
  }
}
