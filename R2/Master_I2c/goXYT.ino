bool goXYT(int x, int y, int t) {
  updateOdometry();
  float
  s,      // Jarak
  v,      // Linear Velocity
  w,      // angular velocity
  Vx,     // Kecepatan arah X
  Vy;     // Kecepatan arah Y

  float
  alpha,  // heading Error Robot
  TB,     // Target Bearing
  dx,     // Delta x
  dy,     // Delta y
  w1,     // Motor Belakang
  w2,     // Motor Kanan
  w3,     // Motor Kiri
  v1,     // Motor Belakang
  v2,     // Motor Kanan
  v3,     // Motor Kiri
  RPM1,   // Motor Belakang
  RPM2,   // Motor Kanan
  RPM3,   // Motor Kiri
  dw;     // Delta Omega

  v1 = v2 = v3 = 0;
  w1 = w2 = w3 = 0;
  v  = 0;
  w  = 0;

  // Delta Position
  dx = abs(currentPOS.X - x);
  dy = abs(currentPOS.Y - y);

  // Target Bearing
  TB    = degrees(atan2((y - currentPOS.Y), (x - currentPOS.X)));

  // heading Error Robot
  alpha = TB - currentPOS.T;

  s  = sqrt (pow(dx, 2) + pow(dy, 2));
  s = s - 40;
  dw = t - currentPOS.T;

  if (s <= MIN_POS_RES && abs(dw) < MIN_DEG_RES) {
    Break = true;
    writeODM = false;
    setRPM(0, 0, 0);
    return true;
  }

    if (s > 20 && !Break) {
      v = FuzzyLinear(s);
    }
    if (abs(dw) >= MIN_DEG_RES && !Break) {
      w = FuzzyOmega(abs(dw));
      if (dw < 0) {
        w *= -1;
      }
    }

  //  if (abs(dw) >= MIN_DEG_RES && !Break) {
  //    w = FuzzyOmega(abs(dw));
  //    if (dw < 0) {
  //      w *= -1;
  //    }
  //  }


  // Hitung kecepatan arah sumbu X dan Y (Vektor)
  Vx = v * cos(radians(alpha));
  Vy = v * sin(radians(alpha));

  // angular Motor [rad/s]
  w1 = (0.67  * Vx)  + (0     * Vy) + (0.33 * w);
  w2 = (-0.33 * Vx)  + (0.58  * Vy) + (0.33 * w);
  w3 = (-0.33 * Vx)  + (-0.58 * Vy) + (0.33 * w);

  // Linear Motor [m/s];
  v1 = float(0.029 * w1);
  v2 = float(0.029 * w2);
  v3 = float(0.029 * w3);

  // convert To RPM
  RPM1 = (60 * v1) / (2 * MATH_PI * 0.075); // 0.075 is radius motor
  RPM2 = (60 * v2) / (2 * MATH_PI * 0.075);
  RPM3 = (60 * v3) / (2 * MATH_PI * 0.075);

  setRPM(RPM1, RPM2, RPM3);

  return false;
}
