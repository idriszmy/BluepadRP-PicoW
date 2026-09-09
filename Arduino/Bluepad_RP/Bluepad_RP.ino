#include "BluepadRP.h"

BluepadRP bluepad;

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("Bluepad-RP PS4 controller test");
  Serial.println("Put the PS4 controller into pairing mode: hold SHARE + PS.");

  if (!bluepad.begin()) {
    Serial.println("Bluetooth initialization failed.");
    while (true) {
      delay(1000);
    }
  }
}

void loop() {
  bluepad.update();

  static bool wasConnected = false;
  const bool connected = bluepad.connected();

  if (connected != wasConnected) {
    Serial.println(connected ? "Controller connected" : "Controller disconnected");
    wasConnected = connected;
  }

  if (connected && bluepad.available()) {
    const BluepadRPGamepad& gamepad = bluepad.gamepad();

    Serial.printf(
        "x=%6d y=%6d rx=%6d ry=%6d hat=0x%02x buttons=0x%08lx\n",
        gamepad.axisX,
        gamepad.axisY,
        gamepad.axisRX,
        gamepad.axisRY,
        gamepad.dpad,
        static_cast<unsigned long>(gamepad.buttons));
  }

  delay(20);
}
