#define Master Serial2

#define LKick_PWM_PIN 2
#define LKick_LPWM_PIN 3
#define RKick_PWM_PIN 4
#define RKick_LPWM_PIN 5

#define Holder_PIN_A 47
#define Holder_PIN_B 41

#define ENC_DIR_A 23
#define ENC_DIR_B 25

/*holder*/
#define tahan 1
#define lepas 2
#define reset 0

struct input {
  char data;
} master, serial;

struct ENC_and_Motor
{
  volatile long int pulseCnt;
  long int lastpulse;
  int Speed;
} ENC, Motor;


void (* Reset) (void) = 0;

int Direction;

void setup() {
  Serial.begin(9600);
  Master.begin(9600);
  pinMode(LKick_PWM_PIN, OUTPUT);
  pinMode(LKick_LPWM_PIN, OUTPUT);
  pinMode(Holder_PIN_A, OUTPUT);
  pinMode(Holder_PIN_B, OUTPUT);
  /*encoder*/
  pinMode(ENC_DIR_A, INPUT_PULLUP);
  pinMode(ENC_DIR_B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENC_DIR_A), ENC_INTT_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_DIR_B), ENC_INTT_B, CHANGE);
  control();
}
void loop() {
  //    Serial.println(ENC.pulseCnt); //cek pulsa enc
  //  logData();
  //  Serial.print(master.data);
  //logData();
  //  Serial.print(Direction);
}
