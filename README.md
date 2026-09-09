# Bluepad-RP

Experimental Arduino support for using Bluetooth game controllers with the
Raspberry Pi Pico W and Raspberry Pi Pico 2 W.

The first milestone pairs a DualShock 4 (PS4) controller and prints its four
axes, D-pad and button state to the Arduino Serial Monitor.

> [!IMPORTANT]
> This is an early hardware-validation implementation. It currently uses the
> `BluetoothHIDMaster` supplied by the Arduino-Pico core and does not yet expose
> the complete Bluepad32 controller API, including motion sensors, touchpad,
> light bar, rumble, battery information or multiple controllers.

## Requirements

- Raspberry Pi Pico W or Raspberry Pi Pico 2 W
- Arduino IDE
- Earle Philhower Arduino-Pico core 6.0.0 or newer
- **Tools > IP/Bluetooth Stack > IPv4 + Bluetooth**
- Serial Monitor at 115200 baud

## First test

1. Open `Arduino/Bluepad_RP/Bluepad_RP.ino`.
2. Select **Raspberry Pi Pico W** or **Raspberry Pi Pico 2 W**.
3. Enable the Bluetooth stack from the Arduino IDE Tools menu.
4. Upload the sketch and open Serial Monitor at 115200 baud.
5. Hold **SHARE + PS** until the controller light flashes rapidly.
6. Move the sticks and press the controls while watching the serial output.

## Project status

Compilation is verified with Arduino-Pico 6.0.0 for Pico W and Pico 2 W. Physical
pairing has not yet been verified. The next stage is to test both target boards
with a real DualShock 4, record the HID mapping, and then decide whether to
extend Arduino-Pico's HID master or integrate the full upstream Bluepad32
parser.

## Name and upstream attribution

Bluepad-RP is the name of this Raspberry Pi RP2040/RP2350 Arduino integration.
It is not an official Bluepad32 project and is not affiliated with its author.

[Bluepad32](https://github.com/ricardoquesada/bluepad32) is the official name of
the upstream multi-platform controller project. Despite its historical name,
Bluepad32 also supports Pico W and Pico 2 W through the Pico SDK.

## License

MIT. See `LICENSE`.
