#define slaveSerial Serial3
#define cmpSerial   Serial2
#define nanoSerial  Serial1

/*COMMAND*/
#define AT_RESET    "RESET"
#define AT_RPS      "RPS"

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
#define WHEEL_BASE        8.00
#define ENC_RESOLUTION    2400.0
#define MIN_POS_RES       1.0
#define MIN_DEG_RES       5.0

/* Expansi Macro */
#define HEAD_CONV_FACTOR    (360.00 / ENC_RESOLUTION)       // Heading Multiply Factor
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
#define LMEDIUM_SPEED    45//50
#define LFAST_SPEED      60//60
#define LVFAST_SPEED     160//190

/* MOVE GOAL TO GOAL */
int count = 0;
bool Move = false;
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

bool com = false;
bool Break =  true;
void setup() {
  Init();

  /* RESET */
  fullResetENC();
  initCMPS();
  initOdometry();

  /* Fungsi Utama */
  controlCompute();

  //  control();

  /* Fungsi Trial */
  //   trialEncMaster();

}

void loop() {
  // Dead Loop();
}
