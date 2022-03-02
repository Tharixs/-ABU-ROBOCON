
void logData() {
  if (Gamepad.available() > 0) {
    stick.data = Gamepad.read();
  }
  if (Slave.available() > 0) {
    slave.data =  Slave.read();
  }

  Serial.println(stick.data);
  //  delay(20);
}

void Mode() {
  while (1) {
    Heading(heading);
    Manual();
  }
}

void Heading(bool heading) {
  while (heading) {
    logData();
    //    updateOdometry();
    param = stick.data;
    switch (param) {
      case 'A':
        pd(maju);
        break;
      case 'B':
        pd(mundur);
        break;
      case 'E':
        goOdom(0, 0, -45);
        break;
      case 'M':
        odom  = true;
        goOdom(0, 0, 0);
        break;
      case 'N':
        odom  = true;
        goOdom(0, 0, 45);
        break;
      case 'O':
        odom  = true;
        goOdom(0, 0, 0);
        break;
      case 'G':
        Slave.print('#');
        stick.data = 'Z';
        break;
      case 'F':
        Slave.print('F');
        stick.data = 'Z';
        break;
      case 'L':
        heading = false;
        manual = true;
        stick.data = 'Z';
        break;
      case 'H':
        Slave.print('H');
        stick.data = 'Z';
        break;
      case 'K':
        heading = true;
        manual = false;
        stick.data = 'Z';
        break;
      case 'Z':
        pd(berhenti);
        break;
      default:
        break;
    }
    //    Serial.print("\t\t");
    //    Serial.print(cmps.range);
    //    Serial.print("\t\t");
    //    Serial.println(stick.data);
    //    delay(20);
  }
}

void Manual() {
  while (manual) {
    logData();
    param = stick.data;
    switch (param) {
      /*Power Window*/
      case 'A':
        pd(maju);
        break;
      case 'B':
        pd(mundur);
        break;
      /*pelontar*/
      case 'H':
        Slave.print('H');
        stick.data = 'Z';
        break;
      case 'G':
        Slave.print('#');
        stick.data = 'Z';
        break;
      /*PUTAR*/
      case 'I':
        putar(-80);
        break;
      case 'J':
        putar(80);
        break;
      /*HOLDER*/
      case 'F':
        Slave.print('F');
        stick.data = 'Z';
        break;
      case 'K':
        heading = true;
        manual = false;
        stick.data = 'Z';
        break;
      case 'L':
        heading = false;
        manual = true;
        stick.data = 'Z';
        break;
      case 'Z':
        Stop();
        pd(berhenti);
        break;
      case '0':
        initOdometry();
        resetCMPS();
        range = 0;
        Stop();
        break;
      default:
        break;
    }
  }
}

void Stop() {
  RPM_DKA(0, 0, 0); 
  RPM_DKI(0, 0, 0); 
  RPM_BKA(0, 0, 0); 
  RPM_BKI(0, 0, 0); 
  analogWrite(DKA_Rpwm_PIN, LOW);
  analogWrite(DKA_Lpwm_PIN, LOW);
  analogWrite(DKI_Rpwm_PIN, LOW);
  analogWrite(DKI_Lpwm_PIN, LOW);
  analogWrite(BKA_Rpwm_PIN, LOW);
  analogWrite(BKA_Lpwm_PIN, LOW);
  analogWrite(BKI_Rpwm_PIN, LOW);
  analogWrite(BKI_Lpwm_PIN, LOW);
  DKA.pwm = BKA.pwm = BKI.pwm = DKI.pwm = 0;
  Serial.println(DKA.pwm);
}

void pd(int a) {
  switch (a) {
    case mundur:
      analogWrite(Moto_PD_Rpwm, 255);
      analogWrite(Moto_PD_Lpwm, LOW);
      break;
    case maju:
      analogWrite(Moto_PD_Rpwm, LOW);
      analogWrite(Moto_PD_Lpwm, 255);
      break;
    case berhenti:
      analogWrite(Moto_PD_Rpwm, LOW);
      analogWrite(Moto_PD_Lpwm, LOW);
      break;
  }
}

/*R1 L1*/
void putar(int s) {

  float Speed = s;
  //  float FSpeed = FuzzyLinear(Speed);
  float Fpeed = FuzzyOmega(Speed);

  RPM_DKI(Speed, 0.01, 0.05);
  RPM_BKI(Speed, 0.01, 0.05);
  RPM_BKA(Speed, 0.01, 0.05);
  RPM_DKA(Speed, 0.01, 0.05);
}


void updateCMPS() {
  char tmp;

  while (cmpSerial.available()) {
    tmp = cmpSerial.read();
    cmps.buffer[cmps.counter++] = tmp;
    if (tmp == '\n') {
      cmps.buffer[cmps.counter] = 0;
      cmps.heading = atof(strtok(cmps.buffer + 5, ","));
      cmps.counter = 0;

      if (cmps.heading > 180) {
        cmps.heading -= 360;
      }
      if (cmps.heading < -180) {
        cmps.heading += 360;
      }
    }
  }
}


void resetCMPS() {
  cmpSerial.write(0xA5);
  cmpSerial.write(0x55);
  delay(100);
  cmpSerial.write(0xA5);
  cmpSerial.write(0x53);
}

void initCMPS() {
  cmpSerial.write(0xA5);
  cmpSerial.write(0x54);
  delay(1000);
  resetCMPS();
}


void goOdom(int x, int y, int t) {
  while (odom) {
    goXYT(x, y, t);
  }
}
