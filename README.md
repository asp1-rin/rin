# Rin: Professional Memory Scanner & Analysis Tool

Rin is a powerful, lightweight memory manipulation suite designed for real-time process analysis. It combines a high-performance C++ scanning engine with a sophisticated Python-based graphical user interface, allowing users to map, scan, and modify process memory across different operating systems.

## Key Features

- **Automated Memory Mapping:** Leverages `/proc/[PID]/maps` to dynamically identify readable memory segments including heaps, stacks, and shared libraries.
- **Advanced Scan & Filter:** Implements an iterative scanning algorithm. Users can perform a global search for values and subsequently filter results to isolate specific memory addresses as values change.
- **Cross-Platform Architecture:** Built with a portable I/O structure using standard system calls, ensuring compatibility and stability on both Linux (Android/Termux) and Windows environments.
- **Integrated Control Panel:** A centralized GUI built with PyQt6 that provides a real-time result list, PID management, and one-click memory injection (dumping).
- **Automated Build Pipeline:** Integrated with GitHub Actions to provide ready-to-use Windows executables (.exe) automatically upon every code update.

## System Architecture

The project is divided into two primary components:
1. **The Core Engine (C++):** A low-level binary responsible for high-speed memory I/O and pattern matching.
2. **The Controller (Python):** A high-level interface that manages the scanning logic, result filtering, and user interaction.

## Usage

### Command Line Interface (Engine)
- **Scan:** `./rin-engine s [PID] [Value]`
- **Read:** `./rin-engine r [PID] [Address]`
- **Write:** `./rin-engine w [PID] [Address] [NewValue]`

### Graphical User Interface
Run the following command to launch the control panel:
```bash
python3 rin_ui.py
```
### Technical Specifications
• Core: C++17
• UI Framework: PyQt6
• Build System: PyInstaller & GitHub Actions (Windows/Linux)
• Dependencies: Build-essential (g++), Python 3.x

### Requirements
• Administrative or Root privileges are required to access process memory (/proc/[PID]/mem).
• Use with caution. High-frequency memory scanning and injection can impact the stability of the target process.

### License
Copyright (c) 2026 asp1-rin. All rights reserved.
