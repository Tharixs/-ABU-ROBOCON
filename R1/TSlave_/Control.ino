struct Param {
  int value;
} cekHold;

void logData() {
  if (Serial.available() > 0) {
    serial.data = Serial.read();
  }
  if (Master.available() > 0) {
    master.data = Master.read();
  }

}

void control() {
  int SpeedDom, SpeedAmy;
  /*set awal hold ball*/
  holder(tahan);
  while (1) {
    SpeedAmy = 200; //untuk menembak musuh
    SpeedDom = 200; //untuk menembak Dom
    /*get data serial*/
    logData();
    /*Direction*/
    Direction = map(ENC.pulseCnt, 0 , 400 , 0, 360);

    /*holder*/
    if (master.data == 'F' && cekHold.value == 0) {
      holder(lepas);
      delay(450);
      holder(tahan);
      cekHold.value = 1;
      master.data = 'Z';
    }
    else if (master.data == 'F' && cekHold.value == 1) {
      holder(lepas);
      delay(450);
      holder(tahan);
      cekHold.value = 0;
      master.data = 'Z';
    }
    /*pelontar*/
    if (master.data == '#') {
      motor(SpeedDom);
      master.data = 'Z';
    } else if (master.data == 'H') {
      motor(0);
      master.data = 'Z';
    }

    /*RESET*/
    //    if (master.data == '0' ) {
    //      holder(lepas);
    //      Reset();
    //      master.data = 'Z';
    //    }
    /*direction*/
    //    if(Direction >= 45){
    //      Master.print('@');
    //      master.data = 'Z';
    //    }
    //    Serial.print(Direction);

    /*Protection Speed*/
    if (SpeedDom > 255 || SpeedAmy > 255) {
      SpeedDom = 255;
      SpeedAmy = 255;
    } else if (SpeedDom < 0 || SpeedAmy < 0) {
      SpeedDom = 255;
      SpeedAmy = 255;
    }
//    delay(20);
  }
}

void holder(int con) {
  switch (con) {
    case lepas:
      digitalWrite(Holder_PIN_A, HIGH);
      delay(100);
      digitalWrite(Holder_PIN_A, LOW);
      break;
    case tahan:
      digitalWrite(Holder_PIN_B, HIGH);
      delay(100);
      digitalWrite(Holder_PIN_B, LOW);
      break;
  }
}

void motor(int s) {
  analogWrite(LKick_PWM_PIN, s);
  analogWrite(LKick_LPWM_PIN, LOW);
  analogWrite(RKick_PWM_PIN, s);
  analogWrite(RKick_LPWM_PIN, LOW);
}
