
void logData() {
  if (Gamepad.available() > 0) {
    stick.data = Gamepad.read();
  }
  if (Slave.available() > 0) {
    slave.data =  Slave.read();
  }
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
    updateOdometry();
    updateCMPS();
    //    Serial.println(currentPOS.T);
    param = stick.data;
    switch (param) {
      case 'A':
        pd(maju);
        break;
      case 'B':
        pd(mundur);
        break;
      case 'E':
        turnRight = true;
        stick.post = stick.data;
        range = currentPOS.T - 45;
        stick.data = 'Z';
        break;
      case 'M':
        turnLeft = true;
        range = currentPOS.T + 45;
        stick.post = stick.data;
        stick.data = 'Z';
        break;
      case 'N':
        turnLeft = true;
        stick.post = stick.data;
        range = currentPOS.T + 45;
        stick.data = 'Z';
        break;
      case 'O':
        turnRight = true;
        stick.post = stick.data;
        range = currentPOS.T - 45;
        stick.data = 'Z';
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
    getBall();
    Range();
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

void getBall() {

  float Speed = 80.0;
  //  float FSpeed = FuzzyLinear(Speed);
  float FSpeed = FuzzyOmega(Speed);

  if (turnRight) {
    RPM_DKI(-Speed, 0.01, 0.05);
    RPM_BKI(-Speed, 0.01, 0.05);
    RPM_BKA(-Speed, 0.01, 0.05);
    RPM_DKA(-Speed, 0.01, 0.05);
  }
  if (turnLeft) {
    RPM_DKI(Speed, 0.01, 0.05);
    RPM_BKI(Speed, 0.01, 0.05);
    RPM_BKA(Speed, 0.01, 0.05);
    RPM_DKA(Speed, 0.01, 0.05);
  }
  if (turnLeft == false && turnRight == false) {
    Stop();
  }
}

void Stop() {
  analogWrite(DKA_Rpwm_PIN, LOW);
  analogWrite(DKA_Lpwm_PIN, LOW);
  analogWrite(DKI_Rpwm_PIN, LOW);
  analogWrite(DKI_Lpwm_PIN, LOW);
  analogWrite(BKA_Rpwm_PIN, LOW);
  analogWrite(BKA_Lpwm_PIN, LOW);
  analogWrite(BKI_Rpwm_PIN, LOW);
  analogWrite(BKI_Lpwm_PIN, LOW);
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

void Range() {
  if (currentPOS.T <= range && stick.post == 'E') {
    turnRight = false;
  }
  else if (currentPOS.T >= range && stick.post == 'M') {
    turnLeft = false;
  }
  else if (currentPOS.T >= range && stick.post == 'N') {
    turnLeft = false;
  }
  else if (currentPOS.T <= range && stick.post == 'O') {
    turnRight = false;
    heading = false;
    manual = true;
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
