# Device System Component

## Overview
This project implements the **Device System** component of the Smart Home System.
It defines the structure, creation, configuration, and behaviour of all smart devices
such as lights, cameras, detectors, televisions, and alarms.

This component is developed according to the design specifications and low-level
requirements provided in the course project.

## Implemented Features
- Abstract base class `Device` for all device types
- Power state management (ON/OFF)
- Critical device protection (Alarm and Detectors cannot be powered OFF)
- Factory Pattern for device creation
- Prototype Pattern for automatic configuration copying
- Failure reporting and active/inactive simulation

## Design Patterns Used
- **Factory Pattern**: Centralized creation of device objects
- **Prototype Pattern**: Cloning device configurations when multiple devices are added

## Project Structure
