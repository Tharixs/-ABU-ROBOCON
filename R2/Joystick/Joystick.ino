#include <PS2X_lib.h>
#include <SoftwareSerial.h>


SoftwareSerial Slave(2, 3);

#define Master Serial

PS2X ps2x;

byte vibrate = 0;
int LY, LX, RY, RX, LYold, LXold, RYold, RXold;

struct con {
  int ctrl;
} sqr, crcl;

char data;

void setup() {
  Master.begin(115200);
  Slave.begin(115200);
  delay(300);
  ps2x.config_gamepad(13, 11, 10, 12, false, false);
}

void loop() {
  SendData();
}
