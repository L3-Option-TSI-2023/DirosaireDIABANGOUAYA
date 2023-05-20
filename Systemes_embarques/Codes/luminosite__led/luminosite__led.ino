#define led 2
void setup() {
  Serial.begin(9600);
//  pinMode(led, OUTPUT);
}

void loop() {

  analogWrite(led, analogRead(A0)/4);
  
    
}
