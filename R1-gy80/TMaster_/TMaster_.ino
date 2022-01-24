#include "Wire.h"

// I2Cdev and ADXL345 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "ADXL345.h"
#include "L3G4200D.h"
#include "BMP085.h"
#include "HMC5883L.h"

#define Gamepad Serial2
#define Slave Serial3

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

HMC5883L mag;
int16_t mx, my, mz;

ADXL345 accel;
int16_t ax, ay, az;

// gyro
L3G4200D gyro;
int16_t avx, avy, avz;

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

struct POS {
  float
  X,
  Y,
  // Reserved in last tetha
  T;
} currentPOS, lastPOS;

struct JOY {
  char data;
} stick, slave;

struct CEK {
  int cek = 0;
} cast, info;

struct Compas {
  float heading;
  float range;
  float head;
  float Direction;
} cmps, pastCmps;

bool turnRight = false;
bool turnLeft = false;
bool heading = true;
bool manual = false;
char param;

void setup() {
  Wire.begin();
  Gamepad.begin(9600);
  Slave.begin(9600);
  Serial.begin(9600);
  mag.initialize();
  accel.initialize();
  gyro.initialize();

  DKA.Time = millis();
  DKI.Time = millis();
  BKA.Time = millis();
  BKI.Time = millis();
  innt();
  Mode();
  //  trialCMPS();
  //  updateCMPS();

  trialLastCmps();
}

void loop() {
  //    trialMotor(0,0,255,0, 0); //dka, bka, bki, dki, pd
  //    trialMotorAll(); // on all of motor
  //    terialEnc(); // read pulse enc
  //    trialENC_ext();
  //    trialXYTEnc();
  //    trialRPM(20);
  //    goXYT(0,0,45);
  //    trialOdometry();
  //    Serial.println(currentPOS.T);
  //    updateCMPS();
  //    Serial.println(cmps.heading);
  //  accelerometer();
  //  gyroscope();
  //  cekRange(-20);

}
