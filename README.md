# keyboard-shortcuts-emulator
A Bluetooth-based macro pad built with ESP32 that emulates common keyboard shortcuts (Ctrl+C, Ctrl+V, Ctrl+X, Ctrl+A, Ctrl+Z) using physical push buttons.

# ESP32 Keyboard Shortcut Emulator (BLE Macro Pad)

A simple but powerful **Bluetooth macro pad** built using the ESP32.  
This device allows you to trigger common keyboard shortcuts like **Copy, Paste, Cut, Select All, and Undo** using physical push buttons.


## Features
🔵 Copy (Ctrl + C)
🟡 Paste (Ctrl + V)
🔴 Cut (Ctrl + X)
⚫ Select All (Ctrl + A)
⚪ Undo (Ctrl + Z)
Bluetooth Low Energy (BLE) keyboard emulation
Plug-and-play after pairing

## Project Motivation
Frequent use of keyboard shortcuts can wear out physical keys over time.  
This project was built as a **hardware solution to a real-world problem**; offloading repetitive keyboard actions to dedicated external buttons.

It also serves as a practical demonstration of:
- Embedded systems design
- Human Interface Devices (HID)
- Hardware-software integration

## Hardware Requirements
- ESP32 development board
- 5 × Push buttons
- Jumper wires
- LED for status indication (this is optional)

## Pin Configuration
 **Function         GPIO Pin**
  | Copy           | 27      |
  | Paste          | 26      |
  | Cut            | 14      |
  | Select All     | 25      |
  | Undo           | 13      |
  | Status LED     | 2       |
Note: Avoid using GPIO 12 as it is a strapping pin and may cause boot issues. I stayed with this for hours.

## Software Requirements
- PlatformIO or Arduino IDE
- ESP32 Board Support Package
- BLE Keyboard Library: ESP32 BLE Keyboard by T-vK

## How It Works
1. ESP32 initializes as a **Bluetooth keyboard**
2. User pairs it with a PC or mobile device
3. Each button press sends a predefined keyboard shortcut
4. Internal pull-up resistors are used for stable input

## 🔮 Future Improvements
- Rechargeable battery integration
- Custom enclosure design (3D printed)
- Configurable shortcuts via mobile app

## Author
**Dean Etim (Radiant Tech)**  
Embedded Systems & Hardware Innovation

## Contributing
Feel free to fork, improve, and submit pull requests.  
Ideas and suggestions are always welcome!

## License
This project is open-source and available under the MIT License.
