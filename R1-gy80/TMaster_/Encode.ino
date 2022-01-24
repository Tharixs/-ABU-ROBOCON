
/*enc motor*/
/*===========================================>DKA<=======================================*/
void DKA_INTT_A()
{
  if (digitalRead(DKA_CH_A) == HIGH)
  {
    if (digitalRead(DKA_CH_B) == LOW)
    {
      DKA.pulseCnt++;
    }
    else
    {
      DKA.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(DKA_CH_B) == HIGH)
    {
      DKA.pulseCnt++;
    }
    else
    {
      DKA.pulseCnt--;
    }
  }
}

void DKA_INTT_B()
{
  if (digitalRead(DKA_CH_A) == HIGH)
  {
    if (digitalRead(DKA_CH_B) == HIGH)
    {
      DKA.pulseCnt++;
    }
    else
    {
      DKA.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(DKA_CH_B) == LOW)
    {
      DKA.pulseCnt++;
    }
    else
    {
      DKA.pulseCnt--;
    }
  }
}

/*========================================>DKI<========================================*/
void DKI_INTT_A()
{
  if (digitalRead(DKI_CH_A) == HIGH)
  {
    if (digitalRead(DKI_CH_B) == LOW)
    {
      DKI.pulseCnt++;
    }
    else
    {
      DKI.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(DKI_CH_B) == HIGH)
    {
      DKI.pulseCnt++;
    }
    else
    {
      DKI.pulseCnt--;
    }
  }
}

void DKI_INTT_B()
{
  if (digitalRead(DKI_CH_A) == HIGH)
  {
    if (digitalRead(DKI_CH_B) == HIGH)
    {
      DKI.pulseCnt++;
    }
    else
    {
      DKI.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(DKI_CH_B) == LOW)
    {
      DKI.pulseCnt++;
    }
    else
    {
      DKI.pulseCnt--;
    }
  }
}

/*========================================>BKA<========================================*/
void BKA_INTT_A()
{
  if (digitalRead(BKA_CH_A) == HIGH)
  {
    if (digitalRead(BKA_CH_B) == LOW)
    {
      BKA.pulseCnt++;
    }
    else
    {
      BKA.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(BKA_CH_B) == HIGH)
    {
      BKA.pulseCnt++;
    }
    else
    {
      BKA.pulseCnt--;
    }
  }
}

void BKA_INTT_B()
{
  if (digitalRead(BKA_CH_A) == HIGH)
  {
    if (digitalRead(BKA_CH_B) == HIGH)
    {
      BKA.pulseCnt++;
    }
    else
    {
      BKA.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(BKA_CH_B) == LOW)
    {
      BKA.pulseCnt++;
    }
    else
    {
      BKA.pulseCnt--;
    }
  }
}

/*========================================>BKI<========================================*/
void BKI_INTT_A()
{
  if (digitalRead(BKI_CH_A) == HIGH)
  {
    if (digitalRead(BKI_CH_B) == LOW)
    {
      BKI.pulseCnt++;
    }
    else
    {
      BKI.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(BKI_CH_B) == HIGH)
    {
      BKI.pulseCnt++;
    }
    else
    {
      BKI.pulseCnt--;
    }
  }
}

void BKI_INTT_B()
{
  if (digitalRead(BKI_CH_A) == HIGH)
  {
    if (digitalRead(BKI_CH_B) == HIGH)
    {
      BKI.pulseCnt++;
    }
    else
    {
      BKI.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(BKI_CH_B) == LOW)
    {
      BKI.pulseCnt++;
    }
    else
    {
      BKI.pulseCnt--;
    }
  }
}

/*========================================>BE<========================================*/
void BE_INTT_A()
{
  if (digitalRead(BE_CH__A) == HIGH)
  {
    if (digitalRead(BE_CH__B) == LOW)
    {
      BE.pulseCnt++;
    }
    else
    {
      BE.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(BE_CH__B) == HIGH)
    {
      BE.pulseCnt++;
    }
    else
    {
      BE.pulseCnt--;
    }
  }
}

void BE_INTT_B()
{
  if (digitalRead(BE_CH__A) == HIGH)
  {
    if (digitalRead(BE_CH__B) == HIGH)
    {
      BE.pulseCnt++;
    }
    else
    {
      BE.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(BE_CH__B) == LOW)
    {
      BE.pulseCnt++;
    }
    else
    {
      BE.pulseCnt--;
    }
  }
}


/*========================================>KA<========================================*/
void KA_INTT_A()
{
  if (digitalRead(KA_CH__A) == HIGH)
  {
    if (digitalRead(KA_CH__B) == LOW)
    {
      KA.pulseCnt++;
    }
    else
    {
      KA.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(KA_CH__B) == HIGH)
    {
      KA.pulseCnt++;
    }
    else
    {
      KA.pulseCnt--;
    }
  }
}

void KA_INTT_B()
{
  if (digitalRead(KA_CH__A) == HIGH)
  {
    if (digitalRead(KA_CH__B) == HIGH)
    {
      KA.pulseCnt++;
    }
    else
    {
      KA.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(KA_CH__B) == LOW)
    {
      KA.pulseCnt++;
    }
    else
    {
      KA.pulseCnt--;
    }
  }
}

/*========================================>KI<========================================*/
void KI_INTT_A()
{
  if (digitalRead(KI_CH__A) == HIGH)
  {
    if (digitalRead(KI_CH__B) == LOW)
    {
      KI.pulseCnt++;
    }
    else
    {
      KI.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(KI_CH__B) == HIGH)
    {
      KI.pulseCnt++;
    }
    else
    {
      KI.pulseCnt--;
    }
  }
}

void KI_INTT_B()
{
  if (digitalRead(KI_CH__A) == HIGH)
  {
    if (digitalRead(KI_CH__B) == HIGH)
    {
      KI.pulseCnt++;
    }
    else
    {
      KI.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(KI_CH__B) == LOW)
    {
      KI.pulseCnt++;
    }
    else
    {
      KI.pulseCnt--;
    }
  }
}
