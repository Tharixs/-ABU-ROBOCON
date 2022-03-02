#include <Wire.h>

#define CW    1
#define CCW   2
#define Stop  3

/* AT COMMAND */
#define AT_RESET    (byte(0x00))
#define AT_RPS      (byte(0x01))

/* DIRECTION */
#define DIR_CW      (byte(0x06))
#define DIR_CCW     (byte(0x04))

/* COM */
#define masterSerial Serial3
#define joySerial Serial2
#define ADDR        64
#define REVOLUTION 540

#define ENC_BE_CHA    33
#define ENC_BE_CHB    31
#define ENC_KA_CHA    29
#define ENC_KA_CHB    27
#define ENC_KI_CHA    25
#define ENC_KI_CHB    23

#define BE_RPWM_PIN   3
#define BE_LPWM_PIN   2
#define KA_RPWM_PIN   5
#define KA_LPWM_PIN   4
#define KI_RPWM_PIN   7
#define KI_LPWM_PIN   6

#define PW_RPWM_PIN   9
#define PW_LPWM_PIN   8

//Capit
#define CAPIT1_A_PIN 34
#define CAPIT1_B_PIN 40
#define CAPIT2_A_PIN 42
#define CAPIT2_B_PIN 44
#define CAPIT3_A_PIN 46
#define CAPIT3_B_PIN 48
#define CAPIT4_A_PIN 52
#define CAPIT4_B_PIN 47
#define CAPIT5_A_PIN 43
#define CAPIT5_B_PIN 35

/*holder*/
#define tahan 1
#define lepas 2
#define reset 0

/*PULSE*/
volatile int32_t
ENC_BE_COUNT = 0, ENC_KA_COUNT = 0, ENC_KI_COUNT = 0;
volatile long int
LENC_BE_COUNT = 0, LENC_KA_COUNT = 0, LENC_KI_COUNT = 0;
float PWM_BE = 0, PWM_KA = 0, PWM_KI = 0;
long ltime1, ltime2, ltime3;
long Previousmillis;

/* SLAVE */
byte Value[3];
byte Ctrl[3];

struct serial
{
  char Data = 'Z';
} Master, Joystik;


void setup() {
  Serial.begin(115200);
  masterSerial.begin(115200);
  joySerial.begin(115200);
  Wire.begin(ADDR);
  Wire.onReceive(receiveEvent);
  /* Encoder */
  pinMode(ENC_BE_CHA, INPUT_PULLUP);
  pinMode(ENC_KA_CHA, INPUT_PULLUP);
  pinMode(ENC_KI_CHA, INPUT_PULLUP);
  /* Motor */
  pinMode(BE_RPWM_PIN, OUTPUT);
  pinMode(BE_LPWM_PIN, OUTPUT);
  pinMode(KA_RPWM_PIN, OUTPUT);
  pinMode(KA_LPWM_PIN, OUTPUT);
  pinMode(KI_RPWM_PIN, OUTPUT);
  pinMode(KI_LPWM_PIN, OUTPUT);

  pinMode(CAPIT1_A_PIN, OUTPUT);
  pinMode(CAPIT1_B_PIN, OUTPUT);
  pinMode(CAPIT2_A_PIN, OUTPUT);
  pinMode(CAPIT2_B_PIN, OUTPUT);

  pinMode(CAPIT3_A_PIN, OUTPUT);
  pinMode(CAPIT3_B_PIN, OUTPUT);
  pinMode(CAPIT4_A_PIN, OUTPUT);
  pinMode(CAPIT4_B_PIN, OUTPUT);

  pinMode(CAPIT5_A_PIN, OUTPUT);
  pinMode(CAPIT5_B_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENC_BE_CHA), ENC_BE_FUNCT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_BE_CHB), ENC_BE_FUNCT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_KA_CHA), ENC_KA_FUNCT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_KA_CHB), ENC_KA_FUNCT_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_KI_CHA), ENC_KI_FUNCT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_KI_CHB), ENC_KI_FUNCT_B, CHANGE);
  delay(300);

  //  trialEnc();
  //  trialPWM(20);
  //  trialRPS(20);
  //    vSlave();
  Control();
  //  ConSlave();
}

void loop() {
  //      RPMbelakang( 100, 0.0008,  0.0000001, 27);
}
