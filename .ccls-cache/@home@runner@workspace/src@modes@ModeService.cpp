#include "modes/ModeService.hpp"

ModeService::ModeService() {
  // Try to set initial mode (safe even if your ModeManager is simple)
  setMode("Normal");
}

std::vector<std::string> ModeService::listModes() {
  // If your teammate ModeManager has its own list method later, we can swap
  // this.
  return {"Normal", "Evening", "Party", "Cinema"};
}

bool ModeService::setMode(const std::string &modeName) {
  // We keep this robust: even if ModeManager API differs, your system still
  // works. First validate name:
  auto modes = listModes();
  bool ok = false;
  for (auto &m : modes)
    if (m == modeName) {
      ok = true;
      break;
    }
  if (!ok)
    return false;

  current = modeName;

  // Optional: call teammate manager if method exists.
  // If compile fails here, comment this out and we still pass the deadline
  // demo.
  manager.setMode(modeName);

  return true;
}

std::string ModeService::currentMode() { return current; }
