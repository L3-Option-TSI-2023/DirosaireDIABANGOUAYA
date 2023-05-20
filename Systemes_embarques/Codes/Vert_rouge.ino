 int poussoir = 24;
 int rouge = 22;
 int verte = 26;
 bool toto = true;
void setup() {
   pinMode(poussoir, INPUT_PULLUP);
   pinMode(rouge, OUTPUT);
   pinMode(verte, OUTPUT);

}

void loop() {
  
if (digitalRead(poussoir) == LOW)
  {
    delay(200);
    if(toto == true)
        toto = false;
     else
        toto = true;
    
  }  

  switch(toto)
  {
    case true:
               digitalWrite(rouge, HIGH);
               digitalWrite(verte, LOW); 
               break;
    case false:
               digitalWrite(rouge, LOW);
               digitalWrite(verte, HIGH);     
               break;  
  }
  
}
