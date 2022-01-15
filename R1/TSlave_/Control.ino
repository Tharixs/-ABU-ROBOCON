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
  Serial.print(master.data);
}

void control() {
  int Speed;

  /*set awal hold ball*/
  holder(tahan);
  while (1) {
    Speed = 100;
    /*get data serial*/
    logData();
    /*Direction*/
    Direction = map(ENC.pulseCnt, 0 , 400 , 0, 360);

    /*holder*/
    if (master.data == 'F' && cekHold.value == 0) {
      holder(lepas);
      delay(470);
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
    if (master.data == '!') {
      motor(Speed);
      master.data = 'Z';
    } else if (master.data == '@' || master.data == 'H') {
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
    if (Speed > 255) {
      Speed = 255;
    } else if (Speed < 0) {
      Speed = 255;
    }
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
