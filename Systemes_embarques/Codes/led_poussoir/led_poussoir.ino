
const int poussoir = 24;
const int led = 22;
void setup() {
   pinMode(poussoir, INPUT_PULLUP);
   pinMode(led, OUTPUT);

}

void loop() {
  if(digitalRead(poussoir) == LOW)
  {
  digitalWrite(led, HIGH);
  }
  else
  {
  digitalWrite(led, LOW);
 }

}
