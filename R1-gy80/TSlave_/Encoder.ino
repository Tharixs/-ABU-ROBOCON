void ENC_INTT_A()
{
  if (digitalRead(ENC_DIR_A) == HIGH)
  {
    if (digitalRead(ENC_DIR_B) == LOW)
    {
      ENC.pulseCnt++;
    }
    else
    {
      ENC.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(ENC_DIR_B) == HIGH)
    {
      ENC.pulseCnt++;
    }
    else
    {
      ENC.pulseCnt--;
    }
  }
}

void ENC_INTT_B()
{
  if (digitalRead(ENC_DIR_A) == HIGH)
  {
    if (digitalRead(ENC_DIR_B) == HIGH)
    {
      ENC.pulseCnt++;
    }
    else
    {
      ENC.pulseCnt--;
    }
  }
  else
  {
    if (digitalRead(ENC_DIR_B) == LOW)
    {
      ENC.pulseCnt++;
    }
    else
    {
      ENC.pulseCnt--;
    }
  }
}
