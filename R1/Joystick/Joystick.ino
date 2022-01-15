#include <PS2X_lib.h>
#include <SoftwareSerial.h>
#define Master Serial

PS2X ps2x;

byte vibrate = 0;
int LY, LX, RY, RX, LYold, LXold, RYold, RXold;

void setup() {

  Master.begin(9600);
  delay(300);
  ps2x.config_gamepad(13, 11, 10, 12, false, false);
}

void loop() {
  sendData();
//  Serial.println(LY);
}
