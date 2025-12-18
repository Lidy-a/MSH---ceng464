#include "security/SecurityService.hpp"

SecurityService::SecurityService() : armed(false) {}

bool SecurityService::arm() {
  armed = true;
  alerts.push_back("System armed");
  return true;
}

bool SecurityService::disarm() {
  armed = false;
  alerts.push_back("System disarmed");
  return true;
}

std::string SecurityService::status() { return armed ? "ARMED" : "DISARMED"; }

std::vector<std::string> SecurityService::recentAlerts() {
  return alerts; // simple log
}
