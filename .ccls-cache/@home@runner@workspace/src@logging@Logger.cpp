#include "logging/Logger.h"
#include <ctime>
#include <iostream>

Logger *Logger::instance = NULL;

Logger::Logger() {
  logFile.open("msh_log.txt", ios::out | ios::app);
  if (logFile.is_open()) {
    log("=== MSH System Started ===");
  }
}

Logger::~Logger() { close(); }

Logger *Logger::getInstance() {
  if (instance == NULL) {
    instance = new Logger();
  }
  return instance;
}

void Logger::log(const string &message) {
  if (logFile.is_open()) {
    time_t now = time(0);
    char *dt = ctime(&now);
    string timestamp(dt);
    timestamp = timestamp.substr(0, timestamp.length() - 1);
    logFile << "[" << timestamp << "] " << message << endl;
    logFile.flush();
  }
}

void Logger::close() {
  if (logFile.is_open()) {
    log("=== MSH System Shutdown ===");
    logFile.close();
  }
}
