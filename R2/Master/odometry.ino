/* Odometry */
void initOdometry(void) {
  currentPOS.X       = lastPOS.X = currentPOS.Y = lastPOS.Y = currentPOS.T = 0;
  EncKanan.pulseCnt  = EncBelakang.pulseCnt = EncKiri.pulseCnt    = 0;
  EncKanan.lastpulse = EncBelakang.lastpulse = EncKiri.lastpulse = 0;
}

void fullResetENC(void) {
  initOdometry();
  slaveSerial.println(AT_RESET);
}

void updateOdometry(void) {
  updateCMPS();

  long ltime;
  float _x, _y, _t;
  // kecepatan rotasi posisi dan heading
  float rvPos1, rvPos2, rvPos3;
  float  _rvHead1, _rvHead2, _rvHead3;

  long int
  // delta pulse
  dKiriENC, dKananENC, dBelakangENC,
            // pulsa sekarang
            currentBePC, currentKaPC, currentKiPC;

  currentBePC = EncBelakang.pulseCnt;
  currentKaPC = EncKanan.pulseCnt;
  currentKiPC = EncKiri.pulseCnt;

  dBelakangENC = currentBePC - EncBelakang.lastpulse;
  dKananENC    = currentKaPC - EncKanan.lastpulse;
  dKiriENC     = currentKiPC - EncKiri.lastpulse;

  /* POS ENC X AND Y */
  rvPos1 = dBelakangENC * POS_CONV_FACTOR;
  rvPos2 = dKananENC    * POS_CONV_FACTOR;
  rvPos3 = dKiriENC     * POS_CONV_FACTOR;

//   //  untuk mengambil heading dari Encoder
//  _rvHead1 = currentBePC * HEAD_CONV_FACTOR;
//  _rvHead2 = currentKaPC * HEAD_CONV_FACTOR;
//  _rvHead3 = currentKiPC * HEAD_CONV_FACTOR;


  _x = WHEEL_RADIUS * ((2 / 3.0 * rvPos1) - (1 / 3.0 * rvPos2) - (1 / 3.0 * rvPos3));
  _y = WHEEL_RADIUS * ((1 / MATH_ROOT_OF_3 * rvPos2) - (1 / MATH_ROOT_OF_3 * rvPos3));
  _t = cmps.heading ;

//  //   untuk menghitung heading dari encoder
//  _t = (WHEEL_RADIUS / (3.0 * WHEEL_BASE)) * (_rvHead1 + _rvHead2 + _rvHead3);

  currentPOS.X = lastPOS.X + ((MATH_COS(_t) * _x ) - (MATH_SIN(_t) * _y));
  currentPOS.Y = lastPOS.Y + ((MATH_SIN(_t) * _x ) + (MATH_COS(_t) * _y));
  currentPOS.T = _t;

  EncBelakang.lastpulse  = currentBePC;
  EncKanan.lastpulse     = currentKaPC;
  EncKiri.lastpulse      = currentKiPC;

  lastPOS.X = currentPOS.X;
  lastPOS.Y = currentPOS.Y;

//  Serial.print("BE: ");
//  Serial.print(EncBelakang.pulseCnt);
//  Serial.print("\tKA: ");
//  Serial.print(EncKanan.pulseCnt);
//  Serial.print("\tKI: ");
//  Serial.print(EncKiri.pulseCnt);
//  Serial.print("\tX: ");
//  Serial.print(currentPOS.X);
//  Serial.print("\tY: ");
//  Serial.print(currentPOS.Y);
//  Serial.print("\tT: ");
//  Serial.println(currentPOS.T);
}
