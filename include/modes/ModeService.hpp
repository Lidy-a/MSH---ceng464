#pragma once
#include <string>
#include <vector>

#include "menu/services.hpp"   // IModeService
#include "modes/ModeManager.h" // teammate code

class ModeService : public IModeService {
public:
  ModeService();

  std::vector<std::string> listModes() override;
  bool setMode(const std::string &modeName) override;
  std::string currentMode() override;

private:
  ModeManager manager;
  std::string current = "Normal";
};
