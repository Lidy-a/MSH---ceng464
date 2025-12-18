#pragma once
#include "menu/services.hpp"
#include <string>
#include <vector>

// Simple implementation that satisfies ISecurityService used by the Controller.
// You can improve behavior later; this is enough to compile + demo.
class SecurityService : public ISecurityService {
public:
  SecurityService();

  bool arm() override;
  bool disarm() override;
  std::string status() override;
  std::vector<std::string> recentAlerts() override;

private:
  bool armed;
  std::vector<std::string> alerts;
};
