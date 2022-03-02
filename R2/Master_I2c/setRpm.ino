void setRPM(int beRPM, int kaRPM, int kiRPM) {
  int beCtrl, kaCtrl, kiCtrl;

  if (beRPM < 0) {
    beCtrl = CCW;
  } else {
    beCtrl = CW;
  }

  if (kaRPM < 0) {
    kaCtrl = CCW;
  } else {
    kaCtrl = CW;
  }

  if (kiRPM < 0) {
    kiCtrl = CCW;
  } else {
    kiCtrl = CW;
  }

  Wire.beginTransmission(ADDR);
  Wire.write(AT_RPS);
  Wire.write((byte)map(abs(beRPM), 0, 400, 0, 255));
  Wire.write((byte)map(abs(kaRPM), 0, 400, 0, 255));
  Wire.write((byte)map(abs(kiRPM), 0, 400, 0, 255));
  Wire.write(beCtrl);
  Wire.write(kaCtrl);
  Wire.write(kiCtrl);
  Wire.endTransmission();

}
