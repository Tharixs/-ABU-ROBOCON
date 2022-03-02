void encBelakang_INTT_A() {
  if (digitalRead(encBelakang_CHA) == HIGH) {
    if (digitalRead(encBelakang_CHB) == LOW) {
      EncBelakang.pulseCnt++;
    } else {
      EncBelakang.pulseCnt--;
    }
  }
  else {
    if (digitalRead(encBelakang_CHB) == HIGH) {
      EncBelakang.pulseCnt++;
    } else {
      EncBelakang.pulseCnt--;
    }
  }
}
void encBelakang_INTT_B() {
  if (digitalRead(encBelakang_CHA) == HIGH) {
    if (digitalRead(encBelakang_CHB) == HIGH) {
      EncBelakang.pulseCnt++;
    } else {
      EncBelakang.pulseCnt--;
    }
  }
  else {
    if (digitalRead(encBelakang_CHB) == LOW) {
      EncBelakang.pulseCnt++;
    } else {
      EncBelakang.pulseCnt--;
    }
  }
}
void encKanan_INTT_A() {
  if (digitalRead(encKanan_CHA) == HIGH) {
    if (digitalRead(encKanan_CHB) == LOW) {
      EncKanan.pulseCnt++;
    } else {
      EncKanan.pulseCnt--;
    }
  }
  else {
    if (digitalRead(encKanan_CHB) == HIGH) {
      EncKanan.pulseCnt++;
    } else {
      EncKanan.pulseCnt--;
    }
  }
}
void encKanan_INTT_B() {
  if (digitalRead(encKanan_CHA) == HIGH) {
    if (digitalRead(encKanan_CHB) == HIGH) {
      EncKanan.pulseCnt++;
    } else {
      EncKanan.pulseCnt--;
    }
  }
  else {
    if (digitalRead(encKanan_CHB) == LOW) {
      EncKanan.pulseCnt++;
    } else {
      EncKanan.pulseCnt--;
    }
  }
}
void encKiri_INTT_A() {
  if (digitalRead(encKiri_CHA) == HIGH) {
    if (digitalRead(encKiri_CHB) == LOW) {
      EncKiri.pulseCnt++;
    } else {
      EncKiri.pulseCnt--;
    }
  }
  else {
    if (digitalRead(encKiri_CHB) == HIGH) {
      EncKiri.pulseCnt++;
    } else {
      EncKiri.pulseCnt--;
    }
  }
}
void encKiri_INTT_B() {
  if (digitalRead(encKiri_CHA) == HIGH) {
    if (digitalRead(encKiri_CHB) == HIGH) {
      EncKiri.pulseCnt++;
    } else {
      EncKiri.pulseCnt--;
    }
  }
  else {
    if (digitalRead(encKiri_CHB) == LOW) {
      EncKiri.pulseCnt++;
    } else {
      EncKiri.pulseCnt--;
    }
  }
}
