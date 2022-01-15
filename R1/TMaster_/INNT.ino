void innt() {
  /*Indikator*/
   pinMode(LED_BUILTIN, OUTPUT);
  /*motor*/
  pinMode(DKA_Rpwm_PIN, OUTPUT);
  pinMode(DKA_Lpwm_PIN, OUTPUT);
  pinMode(DKI_Rpwm_PIN, OUTPUT);
  pinMode(DKI_Lpwm_PIN, OUTPUT);
  pinMode(BKA_Rpwm_PIN, OUTPUT);
  pinMode(BKA_Lpwm_PIN, OUTPUT);
  pinMode(BKI_Rpwm_PIN, OUTPUT);
  pinMode(BKI_Lpwm_PIN, OUTPUT);
  pinMode(Moto_PD_Rpwm, OUTPUT);
  pinMode(Moto_PD_Lpwm, OUTPUT);
  /*Encode Motor*/
  pinMode(DKA_CH_A, INPUT_PULLUP);
  pinMode(DKA_CH_B, INPUT_PULLUP);
  pinMode(DKI_CH_A, INPUT_PULLUP);
  pinMode(DKI_CH_B, INPUT_PULLUP);
  pinMode(BKA_CH_A, INPUT_PULLUP);
  pinMode(BKA_CH_B, INPUT_PULLUP);
  pinMode(BKI_CH_A, INPUT_PULLUP);
  pinMode(BKI_CH_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(DKA_CH_A), DKA_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DKA_CH_B), DKA_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DKI_CH_A), DKI_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DKI_CH_B), DKI_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BKA_CH_A), BKA_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BKA_CH_B), BKA_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BKI_CH_A), BKI_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BKI_CH_B), BKI_INTT_B, CHANGE);

  /*Encode*/
  pinMode(BE_CH__A, INPUT_PULLUP);
  pinMode(BE_CH__B, INPUT_PULLUP);
  pinMode(KA_CH__A, INPUT_PULLUP);
  pinMode(KA_CH__B, INPUT_PULLUP);
  pinMode(KI_CH__A, INPUT_PULLUP);
  pinMode(KI_CH__B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BE_CH__A), BE_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BE_CH__B), BE_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(KA_CH__A), KA_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(KA_CH__B), KA_INTT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(KI_CH__A), KI_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(KI_CH__B), KI_INTT_B, CHANGE);
}
