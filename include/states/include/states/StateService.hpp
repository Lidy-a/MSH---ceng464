#pragma once
#include <string>
#include <vector>

#include "menu/services.hpp"

class StateService : public IStateService {
public:
  StateService();

  bool setState(const std::string &stateName) override;
  bool prevState() override;
  bool nextState() override;

  std::string currentState() override;
  std::vector<std::string> listHistory() override;

private:
  std::vector<std::string> history;
  int idx = 0;

  bool isValid(const std::string &s) const;
};
