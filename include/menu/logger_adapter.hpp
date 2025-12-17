#pragma once
#include <string>

#include "logging/Logger.h"
#include "menu/services.hpp"

class LoggerAdapter : public ILogger {
public:
  void info(const std::string &msg) override {
    Logger::getInstance()->log("[INFO] " + msg);
  }

  void warn(const std::string &msg) override {
    Logger::getInstance()->log("[WARN] " + msg);
  }

  void error(const std::string &msg) override {
    Logger::getInstance()->log("[ERROR] " + msg);
  }
};
