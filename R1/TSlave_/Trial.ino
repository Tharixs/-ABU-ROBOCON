
void trialMotor(int a){
  analogWrite(LKick_PWM_PIN,a);
  analogWrite(LKick_LPWM_PIN, LOW);
  analogWrite(RKick_PWM_PIN,a);
  analogWrite(RKick_LPWM_PIN, LOW);
  delay(1000);
  analogWrite(LKick_PWM_PIN,LOW);
  analogWrite(LKick_LPWM_PIN, a);
  analogWrite(RKick_PWM_PIN,LOW);
  analogWrite(RKick_LPWM_PIN, a);
  delay(1000);
}
void trialHolder(){
  digitalWrite(Holder_PIN_A, HIGH);
  delay(10);
  digitalWrite(Holder_PIN_A, LOW);
  delay(1000);
  digitalWrite(Holder_PIN_B, HIGH);
  delay(10);
  digitalWrite(Holder_PIN_B, LOW);
  delay(1000);
}
