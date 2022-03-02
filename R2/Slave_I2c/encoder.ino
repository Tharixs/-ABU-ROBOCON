void ENC_BE_FUNCT_A() {
  if (digitalRead(ENC_BE_CHA) == HIGH) {
    if (digitalRead(ENC_BE_CHB) == LOW) {
      ENC_BE_COUNT++;
    }
    else {
      ENC_BE_COUNT--;
    }
  }
  else {
    if (digitalRead(ENC_BE_CHB) == HIGH) {
      ENC_BE_COUNT++;
    }
    else {
      ENC_BE_COUNT--;
    }
  }
}

void ENC_BE_FUNCT_B() {
  if (digitalRead(ENC_BE_CHA) == HIGH) {
    if (digitalRead(ENC_BE_CHB) == HIGH) {
      ENC_BE_COUNT++;
    }
    else {
      ENC_BE_COUNT--;
    }
  }

  else {
    if (digitalRead(ENC_BE_CHB) == LOW) {
      ENC_BE_COUNT++;
    }
    else {
      ENC_BE_COUNT--;
    }
  }
}

void ENC_KA_FUNCT_A() {
  if (digitalRead(ENC_KA_CHA) == HIGH) {
    if (digitalRead(ENC_KA_CHB) == LOW) {
      ENC_KA_COUNT++;
    }
    else {
      ENC_KA_COUNT--;
    }
  }

  else {
    if (digitalRead(ENC_KA_CHB) == HIGH) {
      ENC_KA_COUNT++;
    }
    else {
      ENC_KA_COUNT--;
    }
  }
}

void ENC_KA_FUNCT_B() {
  if (digitalRead(ENC_KA_CHA) == HIGH) {
    if (digitalRead(ENC_KA_CHB) == HIGH) {
      ENC_KA_COUNT++;
    }
    else {
      ENC_KA_COUNT--;
    }
  }
  else {
    if (digitalRead(ENC_KA_CHB) == LOW) {
      ENC_KA_COUNT++;
    }
    else {
      ENC_KA_COUNT--;
    }
  }
}

void ENC_KI_FUNCT_A() {
  if (digitalRead(ENC_KI_CHA) == HIGH) {
    if (digitalRead(ENC_KI_CHB) == LOW) {
      ENC_KI_COUNT++;
    }
    else {
      ENC_KI_COUNT--;
    }
  }

  else {
    if (digitalRead(ENC_KI_CHB) == HIGH) {
      ENC_KI_COUNT++;
    }
    else {
      ENC_KI_COUNT--;
    }
  }
}

void ENC_KI_FUNCT_B() {
  if (digitalRead(ENC_KI_CHA) == HIGH) {
    if (digitalRead(ENC_KI_CHB) == HIGH) {
      ENC_KI_COUNT++;
    }
    else {
      ENC_KI_COUNT--;
    }
  }

  else {
    if (digitalRead(ENC_KI_CHB) == LOW) {
      ENC_KI_COUNT++;
    }
    else {
      ENC_KI_COUNT--;
    }
  }
}
