
#pragma once
#include <string>
#include <vector>

struct IDeviceService {
  virtual ~IDeviceService() = default;
  virtual std::string createDevice(const std::string &type,
                                   const std::string &name) = 0;
  virtual bool removeDevice(const std::string &deviceId) = 0;
  virtual bool turnOn(const std::string &deviceId) = 0;
  virtual bool turnOff(const std::string &deviceId) = 0;
  virtual std::string status(const std::string &deviceId) = 0;
  virtual std::vector<std::string> listDevices() = 0;
};

struct IModeService {
  virtual ~IModeService() = default;
  virtual std::vector<std::string> listModes() = 0;
  virtual bool setMode(const std::string &modeName) = 0;
  virtual std::string currentMode() = 0;
};

struct ISecurityService {
  virtual ~ISecurityService() = default;
  virtual bool arm() = 0;
  virtual bool disarm() = 0;
  virtual std::string status() = 0;
  virtual std::vector<std::string> recentAlerts() = 0;
};

struct ISnapshotService {
  virtual ~ISnapshotService() = default;
  virtual std::string saveSnapshot(const std::string &note) = 0;
  virtual bool restoreSnapshot(const std::string &snapshotId) = 0;
  virtual std::vector<std::string> listSnapshots() = 0;
};

struct ILogger {
  virtual ~ILogger() = default;
  virtual void info(const std::string &msg) = 0;
  virtual void warn(const std::string &msg) = 0;
  virtual void error(const std::string &msg) = 0;
};

struct IStateService {
    virtual ~IStateService() = default;
    virtual std::string currentState() = 0;
    virtual bool setState(const std::string& name) = 0;
    virtual bool nextState() = 0;
    virtual bool prevState() = 0;
    virtual std::vector<std::string> listHistory() = 0;
};

