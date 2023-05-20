#define LED 22
void setup() {
   Serial.begin(9600);
   pinMode(LED, OUTPUT);
 
}

void loop() {
    // période 
    int periode = 1000;
    // calcul de rapport cyclique
    int rapport_cyclique = (analogRead(A0)/1023.0)*periode;
    // affichage de rapport cyclique sur la console
    Serial.println(rapport_cyclique);
   
    digitalWrite(LED, HIGH);
    delay(rapport_cyclique);
    digitalWrite(LED, LOW);
    delay(periode-rapport_cyclique);
   
}
