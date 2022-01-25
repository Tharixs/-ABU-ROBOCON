
void updateOdometry() {

  // Temporary Position and Heading
  float
  _x, _y, _t,

  // Rotational Velcovity for Position and Heading
  _rvPos1, _rvPos2, _rvPos3,
  _rvHead1, _rvHead2, _rvHead3;


  long int
  // Delta / difference of every pulse counter
  dLeftENC, dRightENC, dBackENC, convention,

            // Current pulse counter
            currentLeftPC, currentRightPC, currentBackPC;


  // GUnakan sumber Encoder External
  currentRightPC = KA.pulseCnt;
  currentLeftPC = KI.pulseCnt;
  currentBackPC = BE.pulseCnt;


  dLeftENC = currentLeftPC - KI.lastPulse;
  dRightENC = currentRightPC - KA.lastPulse;
  dBackENC = currentBackPC - BE.lastPulse;

  _rvPos1 = dBackENC * POS_CONV_FACTOR;
  _rvPos2 = dRightENC * POS_CONV_FACTOR;
  _rvPos3 = dLeftENC * POS_CONV_FACTOR;

/*
  //  untuk mengambil heading dari Encoder
  _rvHead1 = currentBackPC * HEAD_CONV_FACTOR;
  _rvHead2 = currentRightPC * HEAD_CONV_FACTOR;
  _rvHead3 = currentLeftPC * HEAD_CONV_FACTOR;
*/
  _x = WHEEL_RADIUS * ((2 / 3.0 * _rvPos1) - (1 / 3.0 * _rvPos2) - (1 / 3.0 * _rvPos3));
  _y = WHEEL_RADIUS * ((1 / MATH_ROOT_OF_3 * _rvPos2) - (1 / MATH_ROOT_OF_3 * _rvPos3));

  //   untuk menghitung heading dari encoder
  //  _t = (WHEEL_RADIUS / (3.0 * WHEEL_BASE)) * (_rvHead1 + _rvHead2 + _rvHead3);


  // Baca Heading dari compass gy25
    _t = cmps.heading;

  currentPOS.X = lastPOS.X + ((MATH_COS(_t) * _x) - (MATH_SIN(_t) * _y));
  currentPOS.Y = lastPOS.Y + ((MATH_SIN(_t) * _x) + (MATH_COS(_t) * _y));
  currentPOS.T = _t;

  lastPOS.X = currentPOS.X;
  lastPOS.Y = currentPOS.Y;

  KI.lastPulse = currentLeftPC;
  KA.lastPulse = currentRightPC;
  BE.lastPulse = currentBackPC;
}

// Reset Odometry
void initOdometry(void) {
  currentPOS.X = lastPOS.X = currentPOS.Y = lastPOS.Y = currentPOS.T = 0;
  KI.lastPulse = KA.lastPulse = BE.lastPulse = 0;
  KA.counter = 0;
  KI.pulseCnt = KA.pulseCnt = BE.pulseCnt = 0;
}
