void vSlave() {
  int  beRPM = 0, kaRPM = 0, kiRPM = 0;

  while (1) {

    beRPM = (int)(map(Value[0], 0, 255, 0, 400));
    kaRPM = (int)(map(Value[1], 0, 255, 0, 400));
    kiRPM = (int)(map(Value[2], 0, 255, 0, 400));


    if (Ctrl[0] == DIR_CCW) {
      beRPM = beRPM * -1;
    }    if (Ctrl[1] == DIR_CCW) {
      kaRPM = kaRPM * -1;
    }    if (Ctrl[2] == DIR_CCW) {
      kiRPM = kiRPM * -1;
    }

    RPMbelakang( beRPM, 0.0008,  0.0000001, 27);
    RPMkanan   ( kaRPM, 0.0008,  0.0000001, 27);
    RPMkiri    ( kiRPM, 0.0008,  0.0000001, 27);

    beRPM = 0; kaRPM = 0; kiRPM = 0;

    //    Serial.print(beRPM);
    //    Serial.print('\t');
    //    Serial.print(kaRPM);
    //    Serial.print('\t');
    //    Serial.println(kiRPM);
  }
}

void Control() {
  int  beRPM = 0, kaRPM = 0, kiRPM = 0;
  holder(lepas);
  while (1) {

    beRPM = (int)(map(Value[0], 0, 255, 0, 400));
    kaRPM = (int)(map(Value[1], 0, 255, 0, 400));
    kiRPM = (int)(map(Value[2], 0, 255, 0, 400));

    if (joySerial.available()) {
      Joystik.Data = joySerial.read();
    }

    switch (Joystik.Data) {
      case 'A':
        beRPM = 0;
        kaRPM = 300;
        kiRPM = -300;
        break;
      case 'B':
        beRPM = 0;
        kaRPM = -300;
        kiRPM = 300;
        break;
      case 'C':
        beRPM = 300;
        kaRPM = -150;
        kiRPM = -150;
        break;
      case 'D':
        beRPM = -300;
        kaRPM = 150;
        kiRPM = 150;
        break;
      case 'J':
        beRPM = -200;
        kaRPM = -200;
        kiRPM = -200;
        break;
      case 'K':
        beRPM = 200;
        kaRPM = 200;
        kiRPM = 200;
        break;
      case 'H':
        analogWrite(PW_RPWM_PIN, 100);
        digitalWrite(PW_LPWM_PIN, LOW);
        break;
      case 'E':
        analogWrite(PW_LPWM_PIN, 100);
        digitalWrite(PW_RPWM_PIN, LOW);
        break;
      case 'F':
        holder1(tahan);
        break;
      case 'Q':
        holder2(tahan);
        break;
      //
      case 'R':
        holder3(tahan);
        break;
      case 'S':
        holder4(tahan);
        break;
      case 'T':
        holder5(tahan);
        break;
      case 'U':
        holder(lepas);
        break;
      case 'Z':
        digitalWrite(PW_RPWM_PIN, LOW);
        digitalWrite(PW_LPWM_PIN, LOW);
        //
        digitalWrite(CAPIT1_A_PIN, LOW);
        digitalWrite(CAPIT2_A_PIN, LOW);
        digitalWrite(CAPIT1_B_PIN, LOW);
        digitalWrite(CAPIT2_B_PIN, LOW);
        digitalWrite(CAPIT3_A_PIN, LOW);
        digitalWrite(CAPIT4_A_PIN, LOW);
        digitalWrite(CAPIT3_B_PIN, LOW);
        digitalWrite(CAPIT4_B_PIN, LOW);
        digitalWrite(CAPIT5_A_PIN, LOW);
        digitalWrite(CAPIT5_B_PIN, LOW);
        break;
      default:
        break;
        //      delay(5);
    }

    if (Ctrl[0] == DIR_CCW) {
      beRPM = beRPM * -1;
    }    if (Ctrl[1] == DIR_CCW) {
      kaRPM = kaRPM * -1;
    }    if (Ctrl[2] == DIR_CCW) {
      kiRPM = kiRPM * -1;
    }

    RPMbelakang( beRPM, 0.0008,  0.0000001, 27);
    RPMkanan   ( kaRPM, 0.0008,  0.0000001, 27);
    RPMkiri    ( kiRPM, 0.0008,  0.0000001, 27);

    //    belum dicoba ;
    //    beRPM = 0; kaRPM = 0; kiRPM = 0;

  }
}
