void receiveEvent(int bytes) {
  byte data[10];
  for (int i = 0; i <= 7; i++) {
    data[i] = Wire.read();
  }
  if (data[0] == AT_RPS) {
    Value[0] = data[1];
    Value[1] = data[2];
    Value[2] = data[3];
    Ctrl[0]  = data[4];
    Ctrl[1]  = data[5];
    Ctrl[2]  = data[6];
  } else if (data[0] == AT_RESET) {
    Value[0] = 0;
    Value[1] = 0;
    Value[2] = 0;
  }
}
