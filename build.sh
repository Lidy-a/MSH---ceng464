#!/usr/bin/env bash
set -e

echo "Building My Sweet Home (MSH)..."

clang++ -std=c++17 -Iinclude \
  main.cpp \
  src/core/MSHSystem.cpp \
  src/menu/controller_commands.cpp \
  src/logging/Logger.cpp \
  src/devices/DeviceService.cpp \
  src/modes/ModeService.cpp \
  src/modes/ModeManager.cpp \
  src/modes/NormalMode.cpp \
  src/modes/EveningMode.cpp \
  src/modes/PartyMode.cpp \
  src/modes/CinemaMode.cpp \
  src/states/StateService.cpp \
  src/security/SecurityService.cpp \
  -o main

echo "Build OK. Run with: ./main"

