
void controlCompute() {
  bool MoveGoal = false;
  bool BackMove = false;
  struct data {
    int16_t
    p1,
    p2,
    p3;
  } targetXYT;

  // Move goal To goal
  float ZoneArr[3][4] {
    { 403.30, 0, 0},
    { 403.30, 50, 0},
    { 0, 0, 0},
  };

  while (1) {
    updateOdometry();
    if (writeODM) {
      if (goXYT(targetXYT.p1, targetXYT.p2, targetXYT.p3)) {
        writeODM = false;
      }
    }
    if (MoveGoal) {
      switch (count) {
        case 0:
          goXYT(ZoneArr[0][0], ZoneArr[0][1], ZoneArr[0][2]);
          break;
        case 1:
          goXYT(ZoneArr[1][0], ZoneArr[1][1], ZoneArr[1][2]);
          break;
        default:
          setRPM(0, 0, 0);
          //          count = 1; // Last Count
          break;
      }
    }
    else if (BackMove) {
      switch (count) {
        case 0:
          goXYT(ZoneArr[0][0], ZoneArr[0][1], ZoneArr[0][2]);
          break;
        case 1:
          goXYT(ZoneArr[2][0], ZoneArr[2][1], ZoneArr[2][2]);
          break;
        default:
          setRPM(0, 0, 0);
          //          count = 1; // Last Count
          break;
      }
    }
  

    if (nanoSerial.available()) {
      IR64.data = nanoSerial.read();
    }
    switch (IR64.data) {
      case 'G':
        writeODM = true;
        Break = false;
        //        Auto = true;
        //        Auto2 = false;
        //        count = 1;
        targetXYT.p1 = 558.08;
        targetXYT.p2 = 0;
        targetXYT.p3 = 0;
        resetRpm();
        break;
      case 'P':
        writeODM  = true;
        Break = false;
        //        Auto2 = true;
        //        Auto = false;
        //        count = 1;
        targetXYT.p1 = 558.08;
        targetXYT.p2 = 332.00;
        targetXYT.p3 = 0;
        resetRpm();
        break;
      case 'Q':
        writeODM  = true;
        Break = false;
        //        count = 1;
        targetXYT.p1 = 558.08;
        targetXYT.p2 = 0;
        targetXYT.p3 = 0;
        resetRpm();
        break;
      case 'R':
        writeODM  = true;
        Break = false;
        //        count = 1;
        targetXYT.p1 = 0;
        targetXYT.p2 = 0;
        targetXYT.p3 = 0;
        resetRpm();
        break;
      case 'L':
        writeODM  = false;
        //        fullResetENC();
        Wire.beginTransmission(ADDR);
        Wire.write(AT_RESET);
        Wire.endTransmission();
        break;
      default:
        break;
    }

//    if (Auto) {
//      if (count == 1) {
//        targetXYT.p1 = 403.30;
//        targetXYT.p2 = 0;
//        targetXYT.p3 = 0;
//      } else if (count == 2) {
//        Break = false;
//        targetXYT.p1 = 403.30;
//        targetXYT.p2 = 50;
//        targetXYT.p3 = 0;
//      }
//    }
//
//    if (Auto2) {
//      if (count == 1) {
//        targetXYT.p1 = 403.30;
//        targetXYT.p2 = 0;
//        targetXYT.p3 = 0;
//
//      } else if (count == 2) {
//        Break = false;
//        targetXYT.p1 = 0;
//        targetXYT.p2 = 0;
//        targetXYT.p3 = 0;
//      }
//    }

  }
}
