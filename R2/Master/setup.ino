void Init() {
  Serial.begin(115200);
  cmpSerial.begin(115200);
  slaveSerial.begin(115200);
  nanoSerial.begin(115200);
  joySerial.begin(115200);

  pinMode(encBelakang_CHA , INPUT_PULLUP);
  pinMode(encBelakang_CHB , INPUT_PULLUP);
  pinMode(encKanan_CHA    , INPUT_PULLUP);
  pinMode(encKanan_CHB    , INPUT_PULLUP);
  pinMode(encKiri_CHA     , INPUT_PULLUP);
  pinMode(encKiri_CHB     , INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encBelakang_CHA), encBelakang_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encBelakang_CHB), encBelakang_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKanan_CHA),    encKanan_INTT_A,    CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKanan_CHB),    encKanan_INTT_B,    CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKiri_CHA),     encKiri_INTT_A,      CHANGE);
  attachInterrupt(digitalPinToInterrupt(encKiri_CHB),     encKiri_INTT_B,      CHANGE);
  delay(1000);
}
