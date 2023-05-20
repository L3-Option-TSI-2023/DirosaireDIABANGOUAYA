#include <TimerOne.h>

#define INTERUP_PIN 3
volatile long count = 0;
unsigned long lastTime = 0;
float speed = 0;


void Routine() {
  
  Serial.println(count);
  count++;
}

void setup() {

  pinMode(INTERUP_PIN, INPUT);
  digitalWrite(INTERUP_PIN, HIGH);
  attachInterrupt(digitalPinToInterrupt(INTERUP_PIN), Routine, RISING);

  Serial.begin(115200);
}

void loop() {
  // Mesure le temps écoulé depuis la dernière interruption
  unsigned long elapsedTime = millis() - lastTime;
  
  // Calcule la vitesse en utilisant le temps écoulé et le nombre de tics codeurs
  speed = (float)count / elapsedTime * 1000 * 60 / 24;  // 24 est le nombre de tics codeurs par tour de roue
  
  // Affiche la vitesse dans la console
  Serial.print("Vitesse : ");
  Serial.print(speed);
  Serial.println(" RPM");
  
  // Réinitialise le compteur et le temps
  count = 0;
  lastTime = millis();
}
