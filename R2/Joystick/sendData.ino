void SendData()
{
  ps2x.read_gamepad(false, vibrate);

  /* TOMBOL ARAH (MASTER) */
  if (ps2x.ButtonPressed(PSB_PAD_UP))
  {
    Slave.print('A');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_UP))
  {
    Slave.print('Z');
  }

  if (ps2x.ButtonPressed(PSB_PAD_DOWN))
  {
    Slave.print('B');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_DOWN))
  {
    Slave.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_PAD_RIGHT))
  {
    Slave.print('C');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_RIGHT))
  {
    Slave.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_PAD_LEFT))
  {
    Slave.print('D');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_LEFT))
  {
    Slave.print('Z');
  }

  /** TRIANGLE **/
  if (ps2x.ButtonPressed(PSB_TRIANGLE))
  {
    Slave.print('E');
  }
  else if (ps2x.ButtonReleased(PSB_TRIANGLE)) {
    Slave.print('Z');
  }

  /** CIRCLE **/
  if (ps2x.ButtonPressed(PSB_CIRCLE))
  {
    crcl.ctrl++;
    if (crcl.ctrl == 1) {
      Slave.print('F');
    } else if (crcl.ctrl == 2) {
      Slave.print('Q');
    } else if (crcl.ctrl == 3) {
      Slave.print('R');
    } else if (crcl.ctrl == 4) {
      Slave.print('S');
    } else if (crcl.ctrl == 5) {
      Slave.print('T');
    } else if (crcl.ctrl == 6) {
      Slave.print('U');
      crcl.ctrl = 0;
    }
  }
  else if (ps2x.ButtonReleased(PSB_CIRCLE))
  {
    Slave.print('Z');
  }

  /** SQUARE **/
  if (ps2x.ButtonPressed(PSB_SQUARE))
  {
    sqr.ctrl++;

    if (sqr.ctrl == 1) {
      Master.print('G');
    }
    if (sqr.ctrl == 2) {
      Master.print('P');
    }
    if (sqr.ctrl == 3) {
      Master.print('Q');
    }
    if (sqr.ctrl == 4) {
      Master.print('R');
      sqr.ctrl = 0;
    }
  }
  else if (ps2x.ButtonReleased(PSB_SQUARE))
  {
    Master.print('Z');
  }

  /** CROSS **/
  if (ps2x.ButtonPressed(PSB_CROSS))
  {
    Slave.print('H');
  }
  else if (ps2x.ButtonReleased(PSB_CROSS))
  {
    Slave.print('Z');
  }

  /* START AND SELECT */
  if (ps2x.ButtonPressed(PSB_START))
  {
    Slave.print('I');
  }
  else if (ps2x.ButtonReleased(PSB_START))
  {
    Slave.print('Z');
  }

  /* L DAN R (SLAVE) */
  if (ps2x.ButtonPressed(PSB_R1))
  {
    Slave.print('J');
  }
  else if (ps2x.ButtonReleased(PSB_R1))
  {
    Slave.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_L1))
  {
    Slave.print('K');
  }
  else if (ps2x.ButtonReleased(PSB_L1))
  {
    Slave.print('Z');
  }

  if (ps2x.ButtonPressed(PSB_R2))
  {
    Master.print('L');
    Slave.print('M');
  }
  else if (ps2x.ButtonReleased(PSB_R2))
  {
    Master.print('Z');
    Slave.print('Z');
  }

  if (ps2x.ButtonPressed(PSB_L2))
  {
    Master.print('M');
    Slave.print('L');
  }
  else if (ps2x.ButtonReleased(PSB_L2))
  {
    Master.print('Z');
    Slave.print('Z');
  }

  LY = (int)ps2x.Analog(PSS_LY);
  LX = (int)ps2x.Analog(PSS_LX);
  RY = (int)ps2x.Analog(PSS_RY);
  RX = (int)ps2x.Analog(PSS_RX);

  if (LX != LXold || LY != LYold)
  {
    if (LY == 0 && LX == 128) // POWER WINDOW MAJU
    {
      Slave.print('N');
    }
    if (LY == 255 && LX == 128) // POWER WINDOWS MUNDUR
    {
      Slave.print('O');
    }
    if (LY == 127 && LX == 128)
    {
      Slave.print('Z');
    }
  }

  LYold = LY;
  LXold = LX;
  RYold = RY;
  RXold = RX;

  delay(20);
}
