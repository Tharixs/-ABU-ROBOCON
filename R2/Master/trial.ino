void trialEncMaster() {
  while (1) {
    updateOdometry();
    Serial.print("BE: ");
    Serial.print(EncBelakang.pulseCnt);
    Serial.print("\tKA: ");
    Serial.print(EncKanan.pulseCnt);
    Serial.print("\tKI: ");
    Serial.print(EncKiri.pulseCnt);
    Serial.print("\tX: ");
    Serial.print(currentPOS.X);
    Serial.print("\tY: ");
    Serial.print(currentPOS.Y);
    Serial.print("\tT: ");
    Serial.println(currentPOS.T);
    delay(100);
  }
}
