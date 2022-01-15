
/*=====================================RPM DKA =================================*/

void RPM_DKA(int RPM, double kp, double kd)
{
  double
  Kp = kp,
  Kd = kd, TS = 1.0;

  double P, I, D, error, lError = 0;
  int cRPM;
  DKA.RPM = RPM;

  if ((millis() - DKA.Time) > 100)
  {
    cRPM = (DKA.pulseCnt * 600) / WHEEL_RESOLUTION; //pprmotor = 550
    if (DKA.RPM > 0)
    {
      Motor_DKA(maju);
    }
    else if (DKA.RPM < 0)
    {
      Motor_DKA(mundur);
    }
    else
    {
      Motor_DKA(berhenti);
      DKA.pwm = 0;
    }

    error = abs(DKA.RPM) - abs(cRPM);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    DKA.PID = P + D;
    DKA.pwm = DKA.pwm + DKA.PID;

    DKA.Time = millis();
    lError = error;
    DKA.lastpulse = DKA.pulseCnt;
//  menampilkan data RPM
//    Serial.print("DKA : ");
//    Serial.println(cRPM);
   
    DKA.pulseCnt = 0;
    
    if (DKA.pwm > 255)
      DKA.pwm = 255;
    else if (DKA.pwm < 0)
      DKA.pwm = 0;
  }
}

void Motor_DKA(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(DKA_Rpwm_PIN, DKA.pwm);
      analogWrite(DKA_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(DKA_Lpwm_PIN, DKA.pwm);
      analogWrite(DKA_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(DKA_Rpwm_PIN, LOW);
      analogWrite(DKA_Lpwm_PIN, LOW);
      break;
  }
}



/*=====================================RPM DKI =================================*/


void RPM_DKI(int RPM, double kp, double kd)
{
  double
  Kp = kp,
  Kd = kd, TS = 1.0;

  double P, I, D, error, lError = 0;
  int cRPM;
  DKI.RPM = RPM;
 

  if ((millis() - DKI.Time) > 100)
  {
    
    cRPM = (DKI.pulseCnt * 600) / WHEEL_RESOLUTION; //pprmotor
    if (DKI.RPM > 0)
    {
      Motor_DKI(maju);
    }
    else if (DKI.RPM < 0)
    {
      Motor_DKI(mundur);
    }
    else
    {
      Motor_DKI(berhenti);
      DKI.pwm = 0;
    }

    error = abs(DKI.RPM) - abs(cRPM);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    DKI.PID = P + D;
    DKI.pwm = DKI.pwm + DKI.PID;

    DKI.Time = millis();
    lError = error;
    DKI.lastpulse = DKI.pulseCnt;
//  menampilkan data RPM
//    Serial.print("DKI : ");
//    Serial.println(cRPM);
    DKI.pulseCnt = 0;
    
    if (DKI.pwm > 255)
      DKI.pwm = 255;
    else if (DKI.pwm < 0)
      DKI.pwm = 0;
  }
}

void Motor_DKI(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(DKI_Rpwm_PIN, DKI.pwm);
      analogWrite(DKI_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(DKI_Lpwm_PIN, DKI.pwm);
      analogWrite(DKI_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(DKI_Rpwm_PIN, LOW);
      analogWrite(DKI_Lpwm_PIN, LOW);
      break;
  }
}

/*=====================================RPM BKA =================================*/

void RPM_BKA(int RPM, double kp, double kd)
{
  double
  Kp = kp,
  Kd = kd, TS = 1.0;

  double P, I, D, error, lError = 0;
  int cRPM;
  BKA.RPM = RPM;

  if ((millis() - BKA.Time) > 100)
  {
  
    cRPM = (BKA.pulseCnt * 600) / WHEEL_RESOLUTION; //pprmotor
    if (BKA.RPM > 0)
    {
      Motor_BKA(maju);
    }
    else if (BKA.RPM < 0)
    {
      Motor_BKA(mundur);
    }
    else
    {
      Motor_BKA(berhenti);
      BKA.pwm = 0;
    }

    error = abs(BKA.RPM) - abs(cRPM);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    BKA.PID = P + D;
    BKA.pwm = BKA.pwm + BKA.PID;

    BKA.Time = millis();
    lError = error;
    BKA.lastpulse = BKA.pulseCnt;
//  menampilkan data RPM
//    Serial.print("BKA: ");
//    Serial.println(cRPM);

    BKA.pulseCnt = 0;
    
    if (BKA.pwm > 255)
      BKA.pwm = 255;
    else if (BKA.pwm < 0)
      BKA.pwm = 0;
  }
}

void Motor_BKA(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(BKA_Rpwm_PIN, BKA.pwm);
      analogWrite(BKA_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(BKA_Lpwm_PIN, BKA.pwm);
      analogWrite(BKA_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(BKA_Rpwm_PIN, LOW);
      analogWrite(BKA_Lpwm_PIN, LOW);
      break;
  }
}

/*=====================================RPM BKI =================================*/

void RPM_BKI(int RPM, double kp, double kd)
{
  double
  Kp = kp,
  Kd = kd, TS = 1.0;

  double P, I, D, error, lError = 0;
  int cRPM;
  BKI.RPM = RPM;

  if ((millis() - BKI.Time) > 100)
  {
    cRPM = (BKI.pulseCnt * 600) / WHEEL_RESOLUTION; //pprmotor
    if (BKI.RPM > 0)
    {
      Motor_BKI(maju);
    }
    else if (BKI.RPM < 0)
    {
      Motor_BKI(mundur);
    }
    else
    {
      Motor_BKI(berhenti);
      BKI.pwm = 0;
    }

    error = abs(BKI.RPM) - abs(cRPM);
    P = Kp * error;
    D = ((Kd / TS) * (error - lError));
    BKI.PID = P + D;
    BKI.pwm = BKI.pwm + BKI.PID;

    BKI.Time = millis();
    lError = error;
    BKI.lastpulse = BKI.pulseCnt;
//  menampilkan data RPM
//    Serial.print("BKI : ");
//    Serial.println(cRPM);
    
    BKI.pulseCnt = 0;
    
    if (BKI.pwm > 255)
      BKI.pwm = 255;
    else if (BKI.pwm < 0)
      BKI.pwm = 0;
  }
}

void Motor_BKI(int dir)
{
  switch (dir)
  {
    case maju:
      analogWrite(BKI_Rpwm_PIN, BKI.pwm);
      analogWrite(BKI_Lpwm_PIN, LOW);
      break;
    case mundur:
      analogWrite(BKI_Lpwm_PIN, BKI.pwm);
      analogWrite(BKI_Rpwm_PIN, LOW);
      break;
    case berhenti:
      analogWrite(BKI_Rpwm_PIN, LOW);
      analogWrite(BKI_Lpwm_PIN, LOW);
      break;
  }
}
