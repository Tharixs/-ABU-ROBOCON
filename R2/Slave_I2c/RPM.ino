void readRPM(int Speed) {
  float RPM;
  int PULSE;

  analogWrite(BE_RPWM_PIN,  Speed);
  digitalWrite(BE_LPWM_PIN, LOW);

  if ((millis() - Previousmillis) >= 100) {
    Previousmillis = millis();
    PULSE = ENC_BE_COUNT;
    RPM = float((PULSE * 600) / REVOLUTION );
//    Serial.println(RPM);
    ENC_BE_COUNT = 0;
  }
}

void RPMbelakang(int rpm, float kp, float ki, float kd) {
  float PID, P, I, D;
  float Error, lError, cumError, rateError;
  float setRPM , RPM;
  int PULSE , TS = 1000;

  setRPM = rpm;
  if ((millis() - ltime1) >= 100) {
    ltime1 = millis();

    PULSE = ENC_BE_COUNT;
    RPM = float((PULSE * 600) / REVOLUTION );

    if (setRPM > 0) {
      BE_DIRECTION(CW);
    }
    else if (setRPM < 0) {
      BE_DIRECTION(CCW);
    }
    else if (setRPM == 0) {
      BE_DIRECTION(Stop);
      PWM_BE = 0;
    }

    // output P
    Error = abs(setRPM) -  abs(RPM);
    P = kp * Error;
    // output I
    cumError  += Error * TS;
    I = ki * cumError;
    // output D
    rateError = (Error - lError) / TS;
    D = kd * rateError;
    PID = P + I + D;
    PWM_BE = PWM_BE + PID;
    lError = Error;
//    Serial.println(RPM);
    ENC_BE_COUNT = 0;

    if (PWM_BE > 255) PWM_BE = 255;
    else if (PWM_BE < 0) PWM_BE = 0;

  }
}

void RPMkanan(int rpm, float kp, float ki, float kd) {
  float PID, P, I, D;
  float Error, lError, cumError, rateError;
  float setRPM , RPM;
  int PULSE , TS = 1000;
  setRPM = rpm;
  if ((millis() - ltime2) >= 100) {
    ltime2 = millis();

    PULSE = ENC_KA_COUNT;
    RPM = float((PULSE * 600) / REVOLUTION );

    if (setRPM > 0) {
      KA_DIRECTION(CW);
    }
    else if (setRPM < 0) {
      KA_DIRECTION(CCW);
    }
    else if (setRPM == 0) {
      KA_DIRECTION(Stop);
      PWM_KA = 0;
    }

    // output P
    Error = abs(setRPM) -  abs(RPM);
    P = kp * Error;
    // output I
    cumError  += Error * TS;
    I = ki * cumError;
    // output D
    rateError = (Error - lError) / TS;
    D = kd * rateError;
    PID = P + I + D;
    PWM_KA = PWM_KA + PID;
    lError = Error;

    ENC_KA_COUNT = 0;

    if (PWM_KA > 255) PWM_KA = 255;
    else if (PWM_KA < 0) PWM_KA = 0;

  }
}

void RPMkiri(int rpm, float kp, float ki, float kd) {
  float PID, P, I, D;
  float Error, lError, cumError, rateError;
  float setRPM , RPM;
  int PULSE , TS = 1000;

  setRPM = rpm;
  if ((millis() - ltime3) >= 100) {
    ltime3 = millis();

    PULSE = ENC_KI_COUNT;
    RPM = float((PULSE * 600) / REVOLUTION );

    if (setRPM > 0) {
      KI_DIRECTION(CW);
    }
    else if (setRPM < 0) {
      KI_DIRECTION(CCW);
    }
    else if (setRPM == 0) {
      KI_DIRECTION(Stop);
      PWM_KI = 0;
    }

    // output P
    Error = abs(setRPM) -  abs(RPM);
    P = kp * Error;
    // output I
    cumError  += Error * TS;
    I = ki * cumError;
    // output D
    rateError = (Error - lError) / TS;
    D = kd * rateError;
    PID = P + I + D;
    PWM_KI = PWM_KI + PID;
    lError = Error;

    ENC_KI_COUNT = 0;

    if (PWM_KI > 255) PWM_KI = 255;
    else if (PWM_KI < 0) PWM_KI = 0;

  }
}
