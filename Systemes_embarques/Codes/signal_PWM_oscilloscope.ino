#define PWM 2
void setup() {
  Serial.begin(9600);
}

void loop() {
  analogWrite(PWM, 126);
}
