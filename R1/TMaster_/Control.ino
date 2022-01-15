
void logData() {
  if (Gamepad.available() > 0) {
    stick.data = Gamepad.read();
  }
  if (Slave.available() > 0) {
    slave.data =  Slave.read();
  }
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

    if (stick.data == 'E' && info.cek == 0) {
      turn = true;
      Slave.print('@');
      stick.data = 'Z';
    }
    else if (stick.data == 'E' && info.cek == 1) {
      turnBack = true;
      Slave.print('!');
      stick.data = 'Z';
    }

    if (stick.data == 'F') {
      Slave.print('F');
      stick.data = 'Z';
    }

    if (stick.data == 'L') {
      heading = false;
      manual = true;
      stick.data = 'Z';
    }
    else if (stick.data == 'K') {
      heading = true;
      manual = false;
      stick.data = 'Z';
    }
    if (currentPOS.T <= -55 ) {
      turn = false;
      info.cek = 1;
      stick.data = 'Z';
    }

    else if (currentPOS.T >= 0 - MIN_DEG_RES && info.cek == 1) {
      turnBack = false;
      info.cek = 0;
      stick.data = 'Z';
      heading = false;
      manual = true;
    }
    getBall();
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
        putar(-100);
        break;
      case 'J':
        putar(100);
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
        BE.pulseCnt = 0;
        KA.pulseCnt = 0;
        KI.pulseCnt = 0;
        break;
      default:
        break;
    }
  }
}

void getBall() {

  float Speed = 100.0;
  //  float FSpeed = FuzzyLinear(Speed);
  float FSpeed = FuzzyOmega(Speed);

  if (turn) {
    RPM_DKI(-Speed, 0.01, 0.05);
    RPM_BKI(-Speed, 0.01, 0.05);
    RPM_BKA(-Speed, 0.01, 0.05);
    RPM_DKA(-Speed, 0.01, 0.05);
  }
  if (turnBack) {
    RPM_DKI(Speed, 0.01, 0.05);
    RPM_BKI(Speed, 0.01, 0.05);
    RPM_BKA(Speed, 0.01, 0.05);
    RPM_DKA(Speed, 0.01, 0.05);
  }
  if (turnBack == false && turn == false) {
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
  float FSpeed = FuzzyOmega(Speed);

  RPM_DKI(Speed, 0.01, 0.05);
  RPM_BKI(Speed, 0.01, 0.05);
  RPM_BKA(Speed, 0.01, 0.05);
  RPM_DKA(Speed, 0.01, 0.05);
}
