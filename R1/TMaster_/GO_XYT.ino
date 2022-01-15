bool goXYT(int x, int y, int t) {
  // Kinematic Variable
  float
  s,      // Jarak
  v,      // Linear Velocity
  w,      // Omega
  Vx,     // Kecepatan arah X
  Vy;     // Kecepatan arah Y

  int
  alpha,  // Kemiringan
  dx,     // Delta x
  dy,     // Delta y
  w1,
  w2,
  w3,
  w4,

  v1,   // Motor Kanan Depan
  v2,   // Motor Kiri Depan
  v3,   // Motor Kiri Belakang
  v4,  // Motor Kanan Belakang
  v1Abs, v2Abs, v3Abs, v4Abs, vMax,
  dw;    // Delta Omega

  // vpad digunakan untuk menyesuaiakan kecepatan output agar tidak melebihi
  // RPM maksimal yang dapat dicapai
  float vpad;

  w1 = w2 = w3 = w4 = 0;
  v1 = v2 = v3 = v4 = 0 ;
  v = 0;
  w = 0;

  updateOdometry();

  dx = abs(currentPOS.X - x);
  dy = abs(currentPOS.Y - y);

  alpha = degrees(atan2((y - currentPOS.Y), (x - currentPOS.X)));
  alpha = alpha - currentPOS.T;

  s = sqrt(pow(dx, 2) + pow(dy, 2));
  dw = currentPOS.T - t;

  // If target reach with optimal resolution
  if (s <= MIN_POS_RES && abs(dw) <= MIN_DEG_RES) {
    setRPM(0, 0, 0, 0);
    return true;
  }

  if (s > MIN_POS_RES) {
    v = FuzzyLinear(s);
  }

  /* NOTE: BETA ALGHORITHM */
  if (abs(dw) > MIN_DEG_RES) {
    w = FuzzyOmega(abs(dw));

    if (dw < 0)
      w *= -1;
  }

  // Hitung kecepatan arah sumbu X dan Y
  Vx = v * cos(radians(alpha));
  Vy = v * sin(radians(alpha));

  // Hithung kecepatan masing-masing roda
  w1 = (0.7071 * Vx) + (0.7071 * Vy) + w;
  w2 = (-0.7071 * Vx) + (0.7071 * Vy) + w;
  w3 = (-0.7071 * Vx) + (-0.7071 * Vy) + w;
  w4 = (0.7071 * Vx) + (-0.7071 * Vy) + w;

  v1 = (w1 * 9.56 / 0.229) / (WHEEL_BASE / WHEEL_RADIUS);
  v2 = (w2 * 9.56 / 0.229) / (WHEEL_BASE / WHEEL_RADIUS);
  v3 = (w3 * 9.56 / 0.229) / (WHEEL_BASE / WHEEL_RADIUS);
  v4 = (w4 * 9.56 / 0.229) / (WHEEL_BASE / WHEEL_RADIUS);

  /* NOTE: BETA ALGHORITHM */

#ifdef RPM_SCALE
  v1Abs = abs(v1);
  v2Abs = abs(v2);
  v3Abs = abs(v3);
  v4Abs = abs(v4);

  if (v1Abs > RPM_SCALE || v2Abs > RPM_SCALE || v3Abs > RPM_SCALE || v4Abs > RPM_SCALE) {

    // Find maximum speed
    if (v1Abs >= v2Abs && v1Abs >= v3Abs && v1Abs >= v4Abs)
      vMax = v1Abs;
    else if (v2Abs >= v1Abs && v2Abs >= v3Abs && v2Abs >= v4Abs)
      vMax = v2Abs;
    else if (v3Abs >= v1Abs && v3Abs >= v2Abs && v3Abs >= v4Abs)
      vMax = v3Abs;
    else
      vMax = v4Abs;

    vpad = vMax / RPM_SCALE;

    v1 = round(v1 / vpad);
    v2 = round(v2 / vpad);
    v3 = round(v3 / vpad);
    v4 = round(v4 / vpad);
  }
#endif

  // Inverse masing-masing kecepatan motor
  v1 *= -1;
  v2 *= -1;
  v3 *= -1;
  v4 *= -1;

  // atur RPM masing-masing slave
  setRPM(v1, v2, v3, v4);

  // Koordinat belum terpenuhi, return false
  return false;
}

void setRPM(int m1, int m2, int m3, int m4) {

  // Variabel RPM Aktual
  int
  afrRPM, aflRPM, ablRPM, abrRPM;

#ifdef RPM_SCALE
  if (m1 > RPM_SCALE)
    m1 = RPM_SCALE;
  else if (m1 < -(RPM_SCALE))
    m1 = -(RPM_SCALE);

  if (m2 > RPM_SCALE)
    m2 = RPM_SCALE;
  else if (m2 < -(RPM_SCALE))
    m2 = -(RPM_SCALE);

  if (m3 > RPM_SCALE)
    m3 = RPM_SCALE;
  else if (m3 < -(RPM_SCALE))
    m3 = -(RPM_SCALE);

  if (m4 > RPM_SCALE)
    m4 = RPM_SCALE;
  else if (m4 < -(RPM_SCALE))
    m4 = -(RPM_SCALE);


  // Rubah RPM menjadi RPM yang sebenarnya (Aktual)
  //abRPM = map(bRPM, 0, RPM_SCALE, 0, RPM_LIMIT);
  //arRPM = map(rRPM,0, RPM_SCALE, 0, RPM_LIMIT);
  //alRPM = map(lRPM, 0, RPM_SCALE, 0, RPM_LIMIT);

  aflRPM = round( (m1 / RPM_SCALE) * ((MOD_RPM / RPM_SCALE) * RPM_LIMIT) );
  ablRPM = round( (m2 / RPM_SCALE) * ((MOD_RPM / RPM_SCALE) * RPM_LIMIT) );
  abrRPM = round( (m3 / RPM_SCALE) * ((MOD_RPM / RPM_SCALE) * RPM_LIMIT) );
  afrRPM = round( (m4 / RPM_SCALE) * ((MOD_RPM / RPM_SCALE) * RPM_LIMIT) );

#else
  aflRPM = m1;
  ablRPM = m2;
  abrRPM = m3;
  afrRPM = m4;
#endif
}
