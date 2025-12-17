
#pragma once
#include "services.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

// -------- Logger (Singleton-ready) --------
class ConsoleLogger : public ILogger {
public:
    void info(const std::string& msg) override {
        std::cout << "[INFO] " << msg << "\n";
    }
    void warn(const std::string& msg) override {
        std::cout << "[WARN] " << msg << "\n";
    }
    void error(const std::string& msg) override {
        std::cout << "[ERROR] " << msg << "\n";
    }
};

// -------- Dummy Device Service --------
class DummyDeviceService : public IDeviceService {
    struct Device {
        std::string id, type, name;
        bool on = false;
    };

    std::unordered_map<std::string, Device> devices;
    int counter = 0;

public:
    std::string createDevice(const std::string& type, const std::string& name) override {
        Device d;
        d.id = "D" + std::to_string(++counter);
        d.type = type;
        d.name = name;
        devices[d.id] = d;
        return d.id;
    }

    bool removeDevice(const std::string& deviceId) override {
        return devices.erase(deviceId) > 0;
    }

    bool turnOn(const std::string& deviceId) override {
        auto it = devices.find(deviceId);
        if (it == devices.end()) return false;
        it->second.on = true;
        return true;
    }

    bool turnOff(const std::string& deviceId) override {
        auto it = devices.find(deviceId);
        if (it == devices.end()) return false;
        it->second.on = false;
        return true;
    }

    std::string status(const std::string& deviceId) override {
        auto it = devices.find(deviceId);
        if (it == devices.end()) return "Device not found";
        std::ostringstream os;
        os << it->second.id << " | " << it->second.type
           << " | " << it->second.name
           << " | " << (it->second.on ? "ON" : "OFF");
        return os.str();
    }

    std::vector<std::string> listDevices() override {
        std::vector<std::string> out;
        for (auto& [id, d] : devices) {
            out.push_back(status(id));
        }
        return out;
    }
};

// -------- Dummy Mode Service --------
class DummyModeService : public IModeService {
    std::string current = "HOME";

public:
    std::vector<std::string> listModes() override {
        return {"HOME", "AWAY", "NIGHT", "ECO"};
    }

    bool setMode(const std::string& modeName) override {
        for (auto& m : listModes()) {
            if (m == modeName) {
                current = modeName;
                return true;
            }
        }
        return false;
    }

    std::string currentMode() override {
        return current;
    }
};

// -------- Dummy Security Service --------
class DummySecurityService : public ISecurityService {
    bool armed = false;

public:
    bool arm() override {
        armed = true;
        return true;
    }

    bool disarm() override {
        armed = false;
        return true;
    }

    std::string status() override {
        return armed ? "ARMED" : "DISARMED";
    }

    std::vector<std::string> recentAlerts() override {
        if (armed)
            return {"No alerts"};
        return {"System disarmed"};
    }
};

// -------- Dummy Snapshot Service --------
class DummySnapshotService : public ISnapshotService {
    std::vector<std::string> snapshots;
    int counter = 0;

public:
    std::string saveSnapshot(const std::string& note) override {
        std::string id = "S" + std::to_string(++counter);
        snapshots.push_back(id + " | " + note);
        return id;
    }

    bool restoreSnapshot(const std::string& snapshotId) override {
        for (auto& s : snapshots) {
            if (s.rfind(snapshotId + " |", 0) == 0)
                return true;
        }
        return false;
    }

    std::vector<std::string> listSnapshots() override {
        return snapshots;
    }
};
