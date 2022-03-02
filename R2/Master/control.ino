
/*Control Belum benar*/
void controlCompute() {
  char IR64, IRTONAS;
  bool MoveGoal = false;
  bool writeODM = false;
  struct data {
    int16_t
    p1,
    p2,
    p3;
  } targetXYT;

  // Move goal To goal
  int ZoneArr[100][3] {
    { -150, 150, 0},
    { -50, 0, 0},
    { 0, 0, 0},
  };

  while (1) {
    updateOdometry();
    if (writeODM) {
      if (goXYT(targetXYT.p1, targetXYT.p2, targetXYT.p3)) {
        writeODM = false;
      }
    }

    if (nanoSerial.available()) {
      IR64 = nanoSerial.read();
    }

    if (joySerial.available()) {
      IRTONAS = joySerial.read();
    }
    switch (IRTONAS) {
      case 'A':
        writeODM = false;
        slaveSerial.println('A');
        break;
      case 'B':
        writeODM = false;
        slaveSerial.println('B');
        break;
      case 'C':
        writeODM = false;
        slaveSerial.println('C');
        break;
      case 'D':
        writeODM = false;
        slaveSerial.println('D');
        break;
      case 'J':
        writeODM = false;
        slaveSerial.println('J');
        break;
      case 'K':
        writeODM = false;
        slaveSerial.println('K');
        break;
      case 'E':
        writeODM = false;
        slaveSerial.println('E');
        break;
      case 'H':
        writeODM = false;
        slaveSerial.println('H');
        break;
      case 'F':
        writeODM = false;
        slaveSerial.println('F');
        break;
      case 'Q':
        writeODM = false;
        slaveSerial.println('Q');
        break;
      case 'R':
        writeODM = false;
        slaveSerial.println('R');
        break;
      case 'L':
        writeODM = false;
        slaveSerial.println("L");
        break;
      case 'M':
        writeODM = false;
        slaveSerial.println("M");
        break;
      case 'Z':
        slaveSerial.println('Z');
      default:
        break;
    }
    switch (IR64) {
      case 'G':
        writeODM = true;
        targetXYT.p1 = 403.30;
        targetXYT.p2 = 0;
        targetXYT.p3 = 0;
        slaveSerial.println("stop");
        break;
      case 'P':
        writeODM = true;
        targetXYT.p1 = 0;
        targetXYT.p2 = 0;
        targetXYT.p3 = 0;
        slaveSerial.println("stop");
        break;
      //      case 'N':
      //        writeODM = true;
      //        targetXYT.p1 = 605.54;
      //        targetXYT.p2 =  38.35;
      //        targetXYT.p3 =  0;
      //        break;
      case 'Z':
        slaveSerial.println('Z');
      default:
        break;
    }
    Serial.println(IR64);
  }
}
