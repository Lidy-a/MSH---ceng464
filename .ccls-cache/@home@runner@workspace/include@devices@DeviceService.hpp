#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "menu/services.hpp" // IDeviceService

struct DeviceEntry {
  std::string id;
  std::string type;
  std::string name;
  bool isOn = false;
};

class DeviceService : public IDeviceService {
public:
  DeviceService();

  std::string createDevice(const std::string &type,
                           const std::string &name) override;
  bool removeDevice(const std::string &deviceId) override;
  bool turnOn(const std::string &deviceId) override;
  bool turnOff(const std::string &deviceId) override;
  std::string status(const std::string &deviceId) override;
  std::vector<std::string> listDevices() override;

private:
  std::unordered_map<std::string, DeviceEntry> devices;
  int nextId = 1;

  std::string makeId();
  DeviceEntry *get(const std::string &deviceId);
};
