#define led 2
void setup()
{
  Serial.begin(9600);
}

void loop() {
 
  for(int i = 4; i<=255;i++)
  {
    analogWrite(led,i);
    delay(10);
  }
  for(int i =255;i>=4;i--)
  {
   analogWrite(led,i);
   delay(10); 
  }
  //analogWrite(led, analogRead(A0)/4);
}
