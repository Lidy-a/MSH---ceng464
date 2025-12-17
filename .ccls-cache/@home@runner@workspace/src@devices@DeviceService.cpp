#include "devices/DeviceService.hpp"
#include <sstream>

DeviceService::DeviceService() {
  // Seed devices so demo works immediately
  createDevice("Light", "Living Room Light");
  createDevice("TV", "Bedroom TV");
  createDevice("Camera", "Front Door Camera");
}

std::string DeviceService::makeId() {
  // IDs are strings because your interface uses string IDs
  return "DEV-" + std::to_string(nextId++);
}

DeviceEntry *DeviceService::get(const std::string &deviceId) {
  auto it = devices.find(deviceId);
  if (it == devices.end())
    return nullptr;
  return &it->second;
}

std::string DeviceService::createDevice(const std::string &type,
                                        const std::string &name) {
  DeviceEntry d;
  d.id = makeId();
  d.type = type;
  d.name = name;
  d.isOn = false;

  devices[d.id] = d;
  return d.id;
}

bool DeviceService::removeDevice(const std::string &deviceId) {
  return devices.erase(deviceId) > 0;
}

bool DeviceService::turnOn(const std::string &deviceId) {
  auto *d = get(deviceId);
  if (!d)
    return false;
  d->isOn = true;
  return true;
}

bool DeviceService::turnOff(const std::string &deviceId) {
  auto *d = get(deviceId);
  if (!d)
    return false;
  d->isOn = false;
  return true;
}

std::string DeviceService::status(const std::string &deviceId) {
  auto *d = get(deviceId);
  if (!d)
    return "Device not found: " + deviceId;

  std::ostringstream out;
  out << d->id << " | " << d->name << " [" << d->type << "] is "
      << (d->isOn ? "ON" : "OFF");
  return out.str();
}

std::vector<std::string> DeviceService::listDevices() {
  std::vector<std::string> out;
  out.reserve(devices.size());

  for (const auto &kv : devices) {
    const auto &d = kv.second;
    std::ostringstream line;
    line << d.id << " | " << d.name << " [" << d.type << "] "
         << (d.isOn ? "ON" : "OFF");
    out.push_back(line.str());
  }

  if (out.empty())
    out.push_back("(no devices)");
  return out;
}
