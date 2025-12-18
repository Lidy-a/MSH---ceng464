
# Demo Script — My Sweet Home (MSH)
**Phase 1: Design Demonstration**

## 1. Demo Purpose
This demo presents the **Phase-1 design** of the *My Sweet Home (MSH)* smart-home system developed for the course **CENG-464 — Design Patterns with C++**.

Phase-1 focuses on:
- System architecture
- Design patterns
- UML diagrams
- Requirement analysis

No executable implementation is included in this phase.

---

## 2. System Overview
My Sweet Home (MSH) is a **menu-driven smart-home simulation system** designed using object-oriented principles.

The system manages:
- Smart devices (lights, TV, camera, detectors, alarm)
- Home modes (Normal, Evening, Party, Cinema)
- System states (Normal, High Performance, Low Power, Sleep)
- Security and hazard detection
- Centralized logging

---

## 3. Menu & Controller
The Menu allows the user to interact with the system using keyboard input.  
The Controller receives the selected option and routes the request to the correct subsystem.

**Design Pattern Used:** Command Pattern  
This pattern separates user input handling from execution logic and allows easy future extension of menu commands.

---

## 4. Device System
All smart devices inherit from a common abstract `Device` class.

**Design Patterns Used:**
- Factory Pattern for device creation
- Prototype Pattern for copying device configuration

Critical devices such as detectors and alarms cannot be powered off.

---

## 5. Mode System
The Mode subsystem controls system behavior based on the selected mode.

Supported modes:
- Normal
- Evening
- Party
- Cinema

Each mode is implemented as a separate class.

**Design Pattern Used:** Strategy / State Pattern  
Cameras and detectors remain ON in all modes for safety reasons.

---

## 6. State Machine System
A system state represents a full snapshot of the home configuration.

Features:
- Previous states are saved automatically
- Users can restore previous or next states
- Ensures consistency across device configurations

**Design Patterns Used:** State and Memento

---

## 7. Detection & Security System
The system reacts automatically to hazard events.

**Design Patterns Used:**
- Observer Pattern for event notification
- Chain of Responsibility for alarm escalation

Scenarios include:
- Smoke or gas detection
- Motion detection via camera
- Alarm activation and emergency notification

All events are logged.

---

## 8. Logging System
A single logging instance records all system actions.

**Design Pattern Used:** Singleton  
Logged events include:
- Menu selections
- Device operations
- Mode and state changes
- Security and detection events

---

## 9. UML Diagrams
The project includes UML diagrams showing:
- System architecture
- Device hierarchy
- Mode system
- State machine
- Security workflow

These diagrams demonstrate inheritance, composition, and subsystem interactions.

---

## 10. Demo Conclusion
This demo demonstrates that all system requirements have been analyzed, mapped, and designed using appropriate software design patterns.

The system is fully prepared for **Phase-2 implementation**.

**End of Demo**
