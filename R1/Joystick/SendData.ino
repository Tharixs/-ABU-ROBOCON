void sendData() {
  ps2x.read_gamepad(false, vibrate);

  /* TOMBOL ARAH (MASTER) */
  if (ps2x.ButtonPressed(PSB_PAD_UP))
  {
    Master.print('A');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_UP))
  {
    Master.print('Z');
  }

  if (ps2x.ButtonPressed(PSB_PAD_DOWN))
  {
    Master.print('B');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_DOWN))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_PAD_RIGHT))
  {
    Master.print('C');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_RIGHT))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_PAD_LEFT))
  {
    Master.print('D');
  }
  else if (ps2x.ButtonReleased(PSB_PAD_LEFT))
  {
    Master.print('Z');
  }


  if (ps2x.ButtonPressed(PSB_SQUARE))
  {
    ctrl++;
    if (ctrl == 1) {
      Master.print('E');
    }
    if (ctrl == 2) {
      Master.print('M');
    }
    if (ctrl == 3) {
      Master.print('N');
    }
    if (ctrl == 4) {
      Master.print('O');
      ctrl = 0;
    }
  }
  else if (ps2x.ButtonReleased(PSB_SQUARE))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_TRIANGLE))
  {
    Master.print('F');
  }
  else if (ps2x.ButtonReleased(PSB_TRIANGLE))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_CIRCLE))
  {
    Master.print('G');
  }
  else if (ps2x.ButtonReleased(PSB_CIRCLE))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_CROSS))
  {
    Master.print('H');
  }
  else if (ps2x.ButtonReleased(PSB_CROSS))
  {
    Master.print('Z');
  }

  if (ps2x.ButtonPressed(PSB_R1))
  {
    Master.print('I');
  }
  else if (ps2x.ButtonReleased(PSB_R1))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_L1))
  {
    Master.print('J');
  }
  else if (ps2x.ButtonReleased(PSB_L1))
  {
    Master.print('Z');
  }

  if (ps2x.ButtonPressed(PSB_R2))
  {
    Master.print('K');
  }
  else if (ps2x.ButtonReleased(PSB_R2))
  {
    Master.print('Z');
  }
  if (ps2x.ButtonPressed(PSB_L2))
  {
    Master.print('L');
  }
  else if (ps2x.ButtonReleased(PSB_L2))
  {
    Master.print('Z');
  }

  /*RESET*/

  if (ps2x.ButtonPressed(PSB_START))
  {
    Master.print('0');
    ctrl = 0;
  }
  else if (ps2x.ButtonReleased(PSB_START))
  {
    Master.print('Z');
  }



  /*analog*/
  LY = (int)ps2x.Analog(PSS_LY);
  LX = (int)ps2x.Analog(PSS_LX);
  RY = (int)ps2x.Analog(PSS_RY);
  RX = (int)ps2x.Analog(PSS_RX);

  if (LX != LXold || LY != LYold)
  {
    if (LY == 0 && LX == 128) // POWER WINDOW MAJU
    {
      Master.print('R');
    }
    if (LY == 255 && LX == 128) // POWER WINDOWS MUNDUR
    {
      Master.print('S');
    }
    if (LY == 127 && LX == 128)
    {
      Master.print('Z');
    }
  }

  LYold = LY;
  LXold = LX;
  RYold = RY;
  RXold = RX;

  delay(20);
}
