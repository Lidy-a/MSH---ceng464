# My Sweet Home (MSH) — Phase 1 Design Report

## 📘 Course Information
- **Course:** CENG-464 — Design Patterns with C++
- **Project:** My Sweet Home (MSH)
- **Phase:** Phase-1 (Design)
- **Date:** December 8, 2025
- **Team:** Team-X

## 👥 Team Members
- Abdirahman Yahya  
- Asma Mohammed  
- Balla Simpara  
- Hibo Mohamed Abdi  
- Lidya Mohammed  
- Maïmouna Bamba  
- Samira Abdi Nur  
- Terry Mazuba  

---

## 🏠 Project Overview
**My Sweet Home (MSH)** is a smart-home simulation system designed using **object-oriented principles** and **software design patterns**.  
The system models a realistic home controller that manages devices, modes, states, logging, and security events.

This repository contains the **Phase-1 Design Report**, which focuses on **architecture, requirements analysis, and design patterns**, not implementation.

---

## 🎯 Objectives
- Design a modular and extensible smart-home system
- Apply required **design patterns** correctly
- Define clear **High-Level Requirements (HLRs)** and **Low-Level Requirements (LLRs)**
- Produce UML diagrams and subsystem responsibilities
- Prepare a solid foundation for Phase-2 implementation

---

## 🧩 System Components
The design is divided into the following main subsystems:

1. **Menu & Controller**
   - Handles user interaction and command routing
   - Uses the **Command Pattern**

2. **Manual & About Module**
   - Displays user instructions and developer information

3. **Logging System**
   - Centralized logging using the **Singleton Pattern**

4. **Device System**
   - Manages smart devices (lights, TV, camera, detectors, alarm)
   - Uses **Factory** and **Prototype Patterns**

5. **Mode System**
   - Supports Normal, Evening, Party, and Cinema modes
   - Uses the **Strategy / State Pattern**

6. **State Machine System**
   - Manages system states and history
   - Uses **State** and **Memento Patterns**

7. **Detection & Security System**
   - Handles smoke, gas, and motion detection
   - Uses **Observer** and **Chain of Responsibility Patterns**

---

## 🧠 Design Patterns Used
- Singleton  
- Command  
- Factory  
- Prototype  
- Strategy  
- State  
- Memento  
- Observer  
- Chain of Responsibility  

Each pattern is mapped explicitly to system requirements and justified in the report.

---

## 📐 UML Diagrams
The report includes:
- Main system UML
- Device hierarchy UML
- Mode system UML
- State machine UML
- Menu & controller UML
- Security workflow diagram

These diagrams illustrate class relationships, inheritance, composition, and subsystem interactions.

---

## 📊 Requirements Coverage
- **High-Level Requirements (REQ1–REQ16)**  
- **Low-Level Requirements (LLR1–LLR46)**  
- Full **Traceability Matrix (HLR → LLR)** included

This ensures all system requirements are fully designed and traceable.

---

## 📁 Repository Contents
- `TEAM - X DESIGN REPORT 1.pdf` — Complete Phase-1 Design Report

---

## 🚀 Project Status
✅ Phase-1 Design completed  
⏳ Phase-2 Implementation planned

---

## 📎 Notes
This repository is intended for **academic purposes** as part of the CENG-464 course.  
All design decisions follow the official project specification and course requirements.

---

## 📜 License
This project is for educational use only.
