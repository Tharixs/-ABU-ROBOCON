
/* terial */

void trialMotor(int a, int b, int c, int d, int e) {

  analogWrite(DKA_Rpwm_PIN, a);
  analogWrite(DKA_Lpwm_PIN, LOW);
  analogWrite(BKA_Rpwm_PIN, b);
  analogWrite(BKA_Lpwm_PIN, LOW);
  analogWrite(BKI_Rpwm_PIN, c);
  analogWrite(BKI_Lpwm_PIN, LOW);
  analogWrite(DKI_Rpwm_PIN, d);
  analogWrite(DKI_Lpwm_PIN, LOW);
  analogWrite(Moto_PD_Rpwm, e);
  analogWrite(Moto_PD_Lpwm, LOW);


  delay(2000);

  analogWrite(DKA_Rpwm_PIN, LOW);
  analogWrite(DKA_Lpwm_PIN, a);
  analogWrite(BKA_Rpwm_PIN, LOW);
  analogWrite(BKA_Lpwm_PIN, b);
  analogWrite(BKI_Rpwm_PIN, LOW);
  analogWrite(BKI_Lpwm_PIN, c);
  analogWrite(DKI_Rpwm_PIN, LOW);
  analogWrite(DKI_Lpwm_PIN, d);
  analogWrite(Moto_PD_Rpwm, LOW);
  analogWrite(Moto_PD_Lpwm, e);

  delay(2000);
}

void trialMotorAll() {

  analogWrite(DKA_Rpwm_PIN, 20);
  analogWrite(DKA_Lpwm_PIN, LOW);

  analogWrite(DKI_Rpwm_PIN, 20);
  analogWrite(DKI_Lpwm_PIN, LOW);

  analogWrite(BKA_Rpwm_PIN, 20);
  analogWrite(BKA_Lpwm_PIN, LOW);

  analogWrite(BKI_Rpwm_PIN, 20);
  analogWrite(BKI_Lpwm_PIN, LOW);

  analogWrite(Moto_PD_Rpwm, 100);
  analogWrite(Moto_PD_Lpwm, LOW);

  delay(2000);

  analogWrite(DKA_Rpwm_PIN, LOW);
  analogWrite(DKA_Lpwm_PIN, 20);

  analogWrite(DKI_Rpwm_PIN, LOW);
  analogWrite(DKI_Lpwm_PIN, 20);

  analogWrite(BKA_Rpwm_PIN, LOW);
  analogWrite(BKA_Lpwm_PIN, 20);

  analogWrite(BKI_Rpwm_PIN, LOW);
  analogWrite(BKI_Lpwm_PIN, 20);

  analogWrite(Moto_PD_Rpwm, LOW);
  analogWrite(Moto_PD_Lpwm, 100);

  delay(2000);
}

void terialEnc() {

  Serial.print("DKA : ");
  Serial.print(DKA.pulseCnt);
  Serial.print("\t\tDKI : ");
  Serial.print(DKI.pulseCnt);
  Serial.print("\t\tBKA : ");
  Serial.print(BKA.pulseCnt);
  Serial.print("\t\tBKI : ");
  Serial.print(BKI.pulseCnt);
  Serial.print("\t\tBE : ");
  Serial.print(BE.pulseCnt);
  Serial.print("\t\tKA : ");
  Serial.print(KA.pulseCnt);
  Serial.print("\t\tKI : ");
  Serial.println(KI.pulseCnt);
}

void trialENC_ext() {
  while (1) {
    updateOdometry();
    Serial.print("BE: ");
    Serial.print(BE.pulseCnt);
    Serial.print("\tRE: ");
    Serial.print(KA.pulseCnt);
    Serial.print("\tLE: ");
    Serial.print(KI.pulseCnt);
    Serial.print("\t\tX: ");
    Serial.print(currentPOS.X);
    Serial.print("\tY: ");
    Serial.print(currentPOS.Y);
    Serial.print("\ttetha: ");
    Serial.println(currentPOS.T);
    delay(100);
  }
}

void trialXYTEnc() {
  Serial.print("\t\tRIGHT: ");
  Serial.print(KA.pulseCnt);
  Serial.print("\t\tLEFT: ");
  Serial.print(KI.pulseCnt);
  Serial.print("\t\tBACK: ");
  Serial.println(BE.pulseCnt);
}

void trialRPM(int pwm) {
  RPM_DKA(pwm, 0.01, 0.05); //ok
  RPM_DKI(pwm, 0.01, 0.05); //ok
  RPM_BKA(pwm, 0.01, 0.05); //ok
  RPM_BKI(pwm, 0.01, 0.05); //ok
}

void trialOdometry() {
  while (1) {
    updateOdometry();
    Serial.print("\t\tX: ");
    Serial.print(currentPOS.X);
    Serial.print("\t\tY: ");
    Serial.print(currentPOS.Y);
    Serial.print("\t\tT: ");
    Serial.println(currentPOS.T);
  }
}
void updateCMPS() {
  // read raw heading measurements from device
  mag.getHeading(&mx, &my, &mz);

  // display tab-separated gyro x/y/z values
  //    Serial.print("mag:\t");
  //  Serial.print(mx); Serial.print("\t");
  //  Serial.print(my); Serial.print("\t");
  //  Serial.print(mz); Serial.print("\t");

  // To calculate heading in degrees. 0 degree indicates North
  cmps.head = atan2(my, mx);
  if (cmps.head < 0)
    cmps.head  += 2 * M_PI;
  cmps.heading = cmps.head * 180 / M_PI;
  //  Serial.print("heading:\t");
  //  Serial.println(cmps.heading);

}

void trialLastCmps() {
  while (1) {
    updateCMPS();
    pastCmps.heading = cmps.heading;

    while (1) {
      cmps.Direction =  pastCmps.heading;
      Serial.print(cmps.heading);
      Serial.print("\t\t");
      Serial.print(pastCmps.heading);
      Serial.print("\t\t");
      Serial.println(cmps.Direction);
    }
  }

}
