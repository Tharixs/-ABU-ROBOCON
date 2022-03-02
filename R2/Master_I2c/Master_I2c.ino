#include <Wire.h>
#define slaveSerial Serial2
#define cmpSerial   Serial3
#define nanoSerial  Serial1

#define ADDR    64

/*COMMAND*/
#define AT_RESET    (byte(0x00))
#define AT_RPS      (byte(0x01))

/* Direction Slave */
#define CW     (byte(0x06))
#define CCW    (byte(0x04))

/* ENCODER */
#define encBelakang_CHA  23
#define encBelakang_CHB  25
#define encKanan_CHA     27
#define encKanan_CHB     29
#define encKiri_CHA      31
#define encKiri_CHB      33

/* ODOMETRY */
#define MATH_PI           3.14286
#define MATH_ROOT_OF_3    1.73205
#define WHEEL_RADIUS      2.9
#define WHEEL_BASE        8.0
#define ENC_RESOLUTION    2400.0
#define MIN_POS_RES       3.0
#define MIN_DEG_RES       5.0

/* Expansi Macro */
#define POS_CONV_FACTOR   ((2 * MATH_PI) / ENC_RESOLUTION)
#define MATH_SIN(x)       sin(radians(x))
#define MATH_COS(x)       cos(radians(x))

/* Fuzzy */
// omega
#define AVLOW_SPEED      10
#define ALOW_SPEED       20
#define AMEDIUM_SPEED    30
#define AFAST_SPEED      50
#define AVFAST_SPEED     75

// Linear
#define LVLOW_SPEED      20//20
#define LLOW_SPEED       40//40
#define LMEDIUM_SPEED    45//45
#define LFAST_SPEED      60//60
#define LVFAST_SPEED     160//160

/* MOVE GOAL TO GOAL */
int count = 0;
bool Move = false;
bool Auto = false;
bool Auto2 = false;
/* MOVE GOAL TO GOAL */

/* KOORDINAT X, Y, DAN HEADING */
struct POS {
  float X, Y, T;
} currentPOS, lastPOS;

/* PENYIMPANAN PULSA ENCODER */
struct ENC {
  volatile long int pulseCnt;
  long int lastpulse;
} EncBelakang, EncKanan, EncKiri;

/*COMPAS GY 25*/
struct cmps {
  char  buffer[50];
  int   counter;
  float heading;
} cmps;
bool writeODM = false;

struct stick {
  char data = 'Z';
} IR64, Ctrl;
bool Break;
//bool Auto = false;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  nanoSerial.begin(115200);
  cmpSerial.begin(115200);
  slaveSerial.begin(115200);

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
  delay(300);

  /* RESET */
  fullResetENC();
  initCMPS();
  initOdometry();

  /* Fungsi Utama */
  controlCompute();

  /* Fungsi Trial */
//       trialEncMaster();

}

void loop() {
  // Dead Loop();
}
