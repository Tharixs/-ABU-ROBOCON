#include "Wire.h"

#define Gamepad Serial2
#define Slave Serial3
#define cmpSerial  Serial1

/*Encoder*/
#define BE_CH__A  23 // intt PIN
#define BE_CH__B  25

#define KA_CH__A  29 // intt PIN
#define KA_CH__B  27

#define KI_CH__A  33 // intt PIN
#define KI_CH__B  31


/* MOTOR*/
#define WHEEL_RESOLUTION 540 // ppr motor
#define DKA_Rpwm_PIN 3 //bts 1
#define DKA_Lpwm_PIN 2

#define BKA_Rpwm_PIN 5 //bts 2
#define BKA_Lpwm_PIN 4

#define BKI_Rpwm_PIN 12 //bts 3
#define BKI_Lpwm_PIN 13

#define DKI_Rpwm_PIN 9 //bts 4
#define DKI_Lpwm_PIN 8

#define Moto_PD_Rpwm 10 //bts 5
#define Moto_PD_Lpwm 11


/* ENC MOTOR*/


#define DKA_CH_A 37
#define DKA_CH_B 35

#define BKA_CH_A 41
#define BKA_CH_B 39

#define BKI_CH_A 45
#define BKI_CH_B 43

#define DKI_CH_A 49
#define DKI_CH_B 47


#define maju 1
#define mundur 2
#define berhenti 3


// Expansi Macro
#define POS_CONV_FACTOR     ((2 * MATH_PI) / ENC_RESOLUTION)  // Position Multiply Factor
#define HEAD_CONV_FACTOR    (360.00 / ENC_RESOLUTION)       // Heading Multiply Factor
#define MATH_SIN(x)         sin(radians(x))
#define MATH_COS(x)         cos(radians(x))

/* ODOMETRY */
#define MATH_PI         3.14286  // PI constant
#define MATH_ROOT_OF_3  1.73205  // root of 3
#define WHEEL_RADIUS    2.9 // Radius of wheel in cm
#define WHEEL_BASE      9.0 //10.64 //21.94  // distance of wheel to center in cm
#define ENC_RESOLUTION  2400.0 // pulse

#define MIN_POS_RES     3.0  // Minimal posisiton resolution
#define MIN_DEG_RES     3.0  // Minimal degree 

#define POS_CONV_FACTOR     ((2 * MATH_PI) / ENC_RESOLUTION)  // Position Multiply Factor
#define HEAD_CONV_FACTOR    (360.00 / ENC_RESOLUTION)       // Heading Multiply Factor

/* Fuzzy */
// omega
#define AVLOW_SPEED      10
#define ALOW_SPEED       20
#define AMEDIUM_SPEED    30
#define AFAST_SPEED      50
#define AVFAST_SPEED     75

// Linear
#define LVLOW_SPEED      20
#define LLOW_SPEED       40
#define LMEDIUM_SPEED    50
#define LFAST_SPEED      60
#define LVFAST_SPEED     190


struct ENC_and_Motor
{
  volatile long int pulseCnt;
  long int lastpulse;
  double PID, pwm, RPM;
  long Time;
} DKA, DKI, BKA, BKI;

struct ENC {
  bool lastPS;  // Last Pulse Status
  volatile long int pulseCnt;   // Pulse Counter
  long int counter;
  // Used for Odometry calc
  long int lastPulse;
} BE, KA, KI;

// Compass GY25
struct cmps {
  char buffer[50];
  int
  counter;
  float heading;
} cmps;

struct POS {
  float
  X,
  Y,
  // Reserved in last tetha
  T;
} currentPOS, lastPOS;

struct JOY {
  char data;
  char post;
} stick, slave;

bool turnRight = false;
bool turnLeft = false;
bool heading = true;
bool manual = false;
bool odom =  true;
char param;
int cek;
float range;

void setup() {
  Gamepad.begin(9600);
  Slave.begin(9600);
  Serial.begin(115200);
  cmpSerial.begin(115200);

  DKA.Time = millis();
  DKI.Time = millis();
  BKA.Time = millis();
  BKI.Time = millis();
  innt();
  initCMPS();
  Mode();
  //      trialCMPS();
}

void loop() {
  //    trialMotor(70,700,70,70, 0); //dka, bka, bki, dki, pd
  //    trialMotorAll(); // on all of motor
  //    terialEnc(); // read pulse enc
  //    trialENC_ext();
  //    trialXYTEnc();
  //    trialRPM(20);
  //    goXYT(0, 0, 45);
  //    updateCMPS();
  //    trialOdometry();

  //    updateCMPS();
  //    Serial.println(cmps.heading);
  //    accelerometer();
  //    gyroscope();
  //    cekRange(-20);

  //    updateCMPS();
  //    setRPM(30, 30, 30, 30);
  //    goXYT(0, 0, 35);
  //    SetRPM(40,40,40,40);

  //  RPM_BKI(40, 0.005, 0.025);


}
