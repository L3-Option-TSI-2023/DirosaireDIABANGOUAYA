#define ANALOG_PIN 0
int val;

void setup() {
  Serial.begin(9600);
  

}

void loop() {

     //Serial.println(analogRead(0)*(5.0/1024));
     val = analogRead(0)*(5.0/1023);
    if(val != 0 || val != 1023)
    {
      Serial.println(val); 
      delay(100);
    }

}
