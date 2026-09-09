#pragma once

#include <Arduino.h>
#include <BluetoothHIDMaster.h>

struct BluepadRPGamepad {
  int axisX = 0;
  int axisY = 0;
  int axisRX = 0;
  int axisRY = 0;
  uint8_t dpad = 0x0f;
  uint32_t buttons = 0;
};

class BluepadRP {
 public:
  bool begin();
  void update();
  bool connected();
  bool available();
  const BluepadRPGamepad& gamepad() const;
  void forgetBluetoothKeys();

 private:
  static void onJoystick(void* context,
                         int x,
                         int y,
                         int z,
                         int rz,
                         uint8_t hat,
                         uint32_t buttons);

  BluetoothHIDMaster hid_;
  BluepadRPGamepad gamepad_;

  volatile int pendingAxisX_ = 0;
  volatile int pendingAxisY_ = 0;
  volatile int pendingAxisRX_ = 0;
  volatile int pendingAxisRY_ = 0;
  volatile uint8_t pendingDpad_ = 0x0f;
  volatile uint32_t pendingButtons_ = 0;
  volatile bool reportPending_ = false;
  bool reportAvailable_ = false;
};
