#include "BluepadRP.h"

bool BluepadRP::begin() {
  hid_.onJoystick(onJoystick, this);

  hid_.begin();

  // DualShock 4 uses Bluetooth Classic HID. This starts discovery and pairs
  // with the first joystick placed into pairing mode.
  return hid_.connectJoystick();
}

void BluepadRP::update() {
  bool hasReport = false;

  noInterrupts();
  if (reportPending_) {
    gamepad_.axisX = pendingAxisX_;
    gamepad_.axisY = pendingAxisY_;
    gamepad_.axisRX = pendingAxisRX_;
    gamepad_.axisRY = pendingAxisRY_;
    gamepad_.dpad = pendingDpad_;
    gamepad_.buttons = pendingButtons_;
    reportPending_ = false;
    hasReport = true;
  }
  interrupts();

  reportAvailable_ = hasReport;
}

bool BluepadRP::connected() {
  return hid_.connected();
}

bool BluepadRP::available() {
  const bool available = reportAvailable_;
  reportAvailable_ = false;
  return available;
}

const BluepadRPGamepad& BluepadRP::gamepad() const {
  return gamepad_;
}

void BluepadRP::forgetBluetoothKeys() {
  hid_.clearPairing();
}

void BluepadRP::onJoystick(void* context,
                           int x,
                           int y,
                           int z,
                           int rz,
                           uint8_t hat,
                           uint32_t buttons) {
  BluepadRP* self = static_cast<BluepadRP*>(context);
  self->pendingAxisX_ = x;
  self->pendingAxisY_ = y;
  self->pendingAxisRX_ = z;
  self->pendingAxisRY_ = rz;
  self->pendingDpad_ = hat;
  self->pendingButtons_ = buttons;
  self->reportPending_ = true;
}
