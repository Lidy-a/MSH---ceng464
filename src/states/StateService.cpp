#include "states/StateService.hpp"
#include <memory>
#include <vector>

StateService::StateService() {
  // Default state from spec: Normal
  history.push_back("Normal");
  idx = 0;
}

bool StateService::isValid(const std::string &s) const {
  return (s == "Normal" || s == "Sleep" || s == "LowPower" ||
          s == "HighPerformance");
}

bool StateService::setState(const std::string &stateName) {
  if (!isValid(stateName))
    return false;

  // If user changed state after going back in history,
  // we discard "future" states (like a browser back/forward model)
  if (idx < (int)history.size() - 1) {
    history.erase(history.begin() + idx + 1, history.end());
  }

  history.push_back(stateName);
  idx = (int)history.size() - 1;
  return true;
}

bool StateService::prevState() {
  if (idx <= 0)
    return false;
  idx--;
  return true;
}

bool StateService::nextState() {
  if (idx >= (int)history.size() - 1)
    return false;
  idx++;
  return true;
}

std::string StateService::currentState() { return history[idx]; }

std::vector<std::string> StateService::listHistory() {
  // Return a pretty list with an arrow on the current index
  std::vector<std::string> out;
  out.reserve(history.size());
  for (int i = 0; i < (int)history.size(); i++) {
    std::string line = (i == idx ? "-> " : "   ");
    line += std::to_string(i) + ": " + history[i];
    out.push_back(line);
  }
  return out;
}
