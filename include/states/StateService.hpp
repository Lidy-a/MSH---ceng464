#pragma once
#include <string>
#include <vector>

#include "menu/services.hpp"

class StateService : public IStateService {
public:
  StateService();

  std::string currentState() override;
  bool setState(const std::string &name) override;
  bool nextState() override;
  bool prevState() override;
  std::vector<std::string> listHistory() override;

private:
  std::vector<std::string> history;
  int idx = 0;

  bool isValid(const std::string &s) const;
};

