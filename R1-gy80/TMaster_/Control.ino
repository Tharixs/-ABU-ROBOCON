
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
    int dir = 45;
    logData();
    updateOdometry();
    updateCMPS();
    Serial.print(cmps.heading);
    if (stick.data == 'E' && info.cek == 0 || pastCmps.heading > 360 ) {
      pastCmps.heading = cmps.heading;
      pastCmps.heading += dir;
      pastCmps.range = pastCmps.heading;
      cekRange(pastCmps.range);
      turnRight = true;
      Slave.print('@');
      stick.data = 'Z';
    }
    else if (stick.data == 'E' && info.cek == 1) {
      pastCmps.heading = cmps.heading;
      pastCmps.heading -= dir;
      pastCmps.range = pastCmps.heading;
      cekRange(pastCmps.range);
      Slave.print('!');
      turnLeft = true;
      stick.data = 'Z';
    }

    if (stick.data == 'E' && info.cek == 2 || pastCmps.heading < 0) {
      pastCmps.heading = cmps.heading;
      pastCmps.heading -= dir;
      pastCmps.range = pastCmps.heading;
      cekRange(pastCmps.range);
      turnLeft = true;
      Slave.print('@');
      stick.data = 'Z';
    }
    else if (stick.data == 'E' && info.cek == 3) {
      pastCmps.heading = cmps.heading;
      pastCmps.heading += dir;
      pastCmps.range = pastCmps.heading;
      cekRange(pastCmps.range);
      turnRight = true;
      Slave.print('!');
      stick.data = 'Z';
    }
    Serial.print("\t\t");
    Serial.print(info.cek);
    Serial.print("\t\t");
    Serial.print(pastCmps.heading );
    Serial.print("\t\t");
    Serial.println(cmps.range);


    if (stick.data == 'F') {
      Slave.print('F');
      stick.data = 'Z';
    }

    if (stick.data == 'L') {
      heading = false;
      manual = true;
      stick.data = 'Z';
    }
    if (stick.data == 'H') {
      Slave.print('H');
      stick.data = 'Z';
    }
    else if (stick.data == 'K') {
      heading = true;
      manual = false;
      stick.data = 'Z';
    }

    if (pastCmps.heading < 0) {
    } else  if (cmps.heading == cmps.range) {
      turnLeft = false;
      info.cek = 3;
      stick.data = 'Z';
    }
    else if (pastCmps.heading > 360) {
      if (cmps.heading == cmps.range) {
        turnRight = false;
        info.cek = 1;
        stick.data = 'Z';
      }
    }
    else if (cmps.heading >= cmps.range && turnRight == true && info.cek == 0) {
      turnRight = false;
      info.cek = 1;
      stick.data = 'Z';
    }
    else if (cmps.heading <= cmps.range  && turnLeft == true && info.cek == 1) {
      turnLeft = false;
      info.cek = 2;
      stick.data = 'Z';
    }

    else if (cmps.heading <= cmps.range  && turnLeft == true && info.cek == 2) {
      turnLeft = false;
      info.cek = 3;
      stick.data = 'Z';
    }
    else if (cmps.heading >= cmps.range  && turnLeft == false && info.cek == 3) {
      turnRight = false;
      info.cek = 0;
      heading = false;
      manual = true;
      stick.data = 'Z';
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
        cmps.range = 0;
        info.cek = 0;
        pastCmps.heading = 0;
        BE.pulseCnt = 0;
        KA.pulseCnt = 0;
        KI.pulseCnt = 0;
        Stop();
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



void cekRange(float value) {

  if (value > 360) {
    cmps.range = value - 360;
  } else if (value < 0) {
    cmps.range = value + 360;
  } else {
    cmps.range = value;
  }

  //  Serial.println(cmps.range);

}
