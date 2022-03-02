
void control() {
  while (1) {
    vSlave(goPos);
    Manual();
  }
}


void vSlave(bool goPos) {
  String
  CMD, sBE, sKA, sKI;
  int
  beRPM = 0, kaRPM = 0, kiRPM = 0;
  int
  nA, nB, nC, nD, nE;
  while (goPos) {
    if (slaveSerial.available() > 0) {
      rpm.data = slaveSerial.readStringUntil('\n');
    }
    nA = rpm.data.indexOf("A");
    nB = rpm.data.indexOf("B");
    nC = rpm.data.indexOf("C");
    nD = rpm.data.indexOf("D");
    nE = rpm.data.indexOf("E");

    CMD = rpm.data.substring(nA + 1, nB);
    sBE  = rpm.data.substring(nB + 1, nC);
    sKA  = rpm.data.substring(nC + 1, nD);
    sKI  = rpm.data.substring(nD + 1, nE);

    if (rpm.data == "L") {
      goPos = true;
      manual = false;
      rpm.data = "Z";
    }
    if (rpm.data == "M") {
      goPos = false;
      manual = true;
      holder(lepas);
      rpm.data = "Z";
    }

    if (CMD == AT_RPS) {
      beRPM = sBE.toInt();
      kaRPM = sKA.toInt();
      kiRPM = sKI.toInt();
    } else if (rpm.data == "stop") {
      ENC_BE_COUNT = 0;
      ENC_KA_COUNT = 0;
      ENC_KI_COUNT = 0;
    }  else {
      beRPM = 0;
      kaRPM = 0;
      kiRPM = 0;
    }
  }
  RPMbelakang( beRPM, 0.001,  0.00003, 35);
  RPMkanan   ( kaRPM, 0.001,  0.00003, 35);
  RPMkiri    ( kiRPM, 0.001,  0.00003, 35);


  //    Serial.print(beRPM);
  //    Serial.print('\t');
  //    Serial.print(kaRPM);
  //    Serial.print('\t');
  //    Serial.println(kiRPM);
}


void Manual() {
  char Data;
  int
  beRPM = 0, kaRPM = 0, kiRPM = 0;
  while (1) {
    if (slaveSerial.available() > 0) {
      Data = slaveSerial.read();
    }
    if (Data == 'L') {
      goPos = true;
      manual = false;
    }
    if (Data == 'M') {
      goPos = false;
      manual = true;
    }
    if (Data == 'A') {
      beRPM = 0;
      kaRPM = 200;
      kiRPM = -200;
    } else if (Data == 'B') {
      beRPM = 0;
      kaRPM = -200;
      kiRPM = 200;
    } else if (Data == 'C') {
      beRPM = 200;
      kaRPM = -100;
      kiRPM = -100;

    } else if (Data == 'D') {
      beRPM = -200;
      kaRPM = 100;
      kiRPM = 100;
    } else if (Data == 'J') {
      beRPM = -150;
      kaRPM = -150;
      kiRPM = -150;
    } else if (Data == 'K') {
      beRPM = 150;
      kaRPM = 150;
      kiRPM = 150;
    } else if (Data == 'H') {
      analogWrite(PW_RPWM_PIN, 200);
      digitalWrite(PW_LPWM_PIN, LOW);
    } else if (Data == 'E') {
      analogWrite(PW_LPWM_PIN, 200);
      digitalWrite(PW_RPWM_PIN, LOW);
    } else if (Data == 'F') {
      holder1(tahan);
    }
    else if (Data == 'Q') {
      holder2(tahan);
    }
    else if (Data == 'R') {
      holder(lepas);
    }
    if (Data == 'L') {
      goPos = true;
      manual = false;
    }
    if (Data == 'M') {
      goPos = false;
      manual = true;
    }
    else if (Data == 'Z') {
      beRPM = 0;
      kaRPM = 0;
      kiRPM = 0;
      digitalWrite(PW_RPWM_PIN, LOW);
      digitalWrite(PW_LPWM_PIN, LOW);
      //
      digitalWrite(CAPIT1_A_PIN, LOW);
      digitalWrite(CAPIT2_A_PIN, LOW);
      digitalWrite(CAPIT1_B_PIN, LOW);
      digitalWrite(CAPIT2_B_PIN, LOW);
    }
    RPMbelakang( beRPM, 0.001,  0.00003, 35);
    RPMkanan   ( kaRPM, 0.001,  0.00003, 35);
    RPMkiri    ( kiRPM, 0.001,  0.00003, 35);

    Serial.println(Data);
  }
}
