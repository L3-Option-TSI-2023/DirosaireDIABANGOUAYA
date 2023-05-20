#include <LiquidCrystal.h>

// Broches des LED
#define ledDroitePin 42
#define ledGauchePin 50
#define inp1 28
#define inp2 26
#define inp3 24
#define inp4 22
#define enA 2
#define enB 3

// Broches des LED de ralentissement
#define ledRalentissement1Pin 44
#define ledRalentissement2Pin 46
#define ledRalentissement3Pin 48

// Broche du bouton poussoir
#define boutonPin 52

// Broche des potentiomètres
#define potentiometreVitessePin A0

// Broches de l'écran LCD
const int rs = 40, en = 30, d4 = 32, d5 = 34, d6 = 36, d7 = 38;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables pour la vitesse des roues
float vitesseRobot;
float vitesseRoueDroite;
float vitesseRoueGauche;
bool ex = false;

void setup() {
  Serial.begin(9600);
  
  // Initialisation des modes des broches
  pinMode(ledDroitePin, OUTPUT);
  pinMode(ledGauchePin, OUTPUT);
  pinMode(ledRalentissement1Pin, OUTPUT);
  pinMode(ledRalentissement2Pin, OUTPUT);
  pinMode(ledRalentissement3Pin, OUTPUT);
  pinMode(boutonPin, INPUT_PULLUP);

  // Initialisation de l'écran LCD
  lcd.begin(16, 2);

  // Affichage du message d'attente
  lcd.setCursor(0, 0);
  lcd.print("Appuyez sur le");
  lcd.setCursor(0, 1);
  lcd.print("bouton pour:run");
  
  while (digitalRead(boutonPin) == HIGH) {
    // Attendre que le bouton soit enfoncé
  }
  lcd.clear();
}

void loop() {
  // Lecture des valeurs des potentiomètres
  vitesseRobot = map(analogRead(potentiometreVitessePin), 0, 1023, 0, 255);
  vitesseRoueDroite = vitesseRobot;
  vitesseRoueGauche = vitesseRobot + 23;
  analogWrite(enA, vitesseRoueDroite);
  analogWrite(enB, vitesseRoueGauche);
  
  // Affichage des valeurs sur l'écran LCD
  lcd.setCursor(0, 0);
  lcd.print("Vitesse: ");
  lcd.print(vitesseRobot);
  lcd.setCursor(0, 1);
  lcd.print("D: ");
  lcd.print(vitesseRoueDroite);
  lcd.print(" G: ");
  lcd.print(vitesseRoueGauche);

  // Suivi de la trajectoire
  if (!ex) {
    forward();  
    delay(2770);
    ex = true;
    off();
    digitalWrite(ledGauchePin, HIGH);
    turnRight1();
    forward();
    delay(2250);
    off(); 
    digitalWrite(ledGauchePin, HIGH);
    turnRight2(); 
    forward();
    delay(3150);
    off();
  }
   
  // Activation des clignotants lors d'un virage
  if (vitesseRoueDroite + 23 > vitesseRoueGauche) {
    // Activation du clignotant droit
    Serial.println("1");
    digitalWrite(ledGauchePin, HIGH);
    delay(200);
    digitalWrite(ledGauchePin, LOW);
  } 
  else if (vitesseRoueGauche > vitesseRoueDroite + 23) {
    // Activation du clignotant gauche
    digitalWrite(ledDroitePin, HIGH);
    delay(200);
    digitalWrite(ledDroitePin, LOW);
  }

  // Activation des LED de ralentissement
  if (vitesseRobot < 100) {
    Serial.println("aa");
    digitalWrite(ledRalentissement1Pin, HIGH);
    digitalWrite(ledRalentissement2Pin, HIGH);
    digitalWrite(ledRalentissement3Pin, HIGH);
  } else {
    digitalWrite(ledRalentissement1Pin, LOW);
    digitalWrite(ledRalentissement2Pin, LOW);
    digitalWrite(ledRalentissement3Pin, LOW);
  }
}

void forward() {
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, HIGH);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, HIGH);
}

void reverse() {
  digitalWrite(inp1, HIGH);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, HIGH);
  digitalWrite(inp4, LOW);
}

void Tleft() {
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, HIGH);
  digitalWrite(inp3, HIGH);
  digitalWrite(inp4, LOW);
}

void Tright() {
  digitalWrite(inp1, HIGH);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, HIGH);
}

void turnRight1() {
  // Définir la durée de rotation à droite (ajustez selon vos besoins)
  int rotationDuration = 450;

  // Activer les mouvements appropriés pour tourner à droite
  Tleft();
  delay(rotationDuration);
  digitalWrite(ledGauchePin, LOW);
  off();
}

void turnRight2() {
  // Définir la durée de rotation à droite (ajustez selon vos besoins)
  int rotationDuration = 530;

  // Activer les mouvements appropriés pour tourner à droite
  Tleft();
  delay(rotationDuration);
  digitalWrite(ledGauchePin, LOW);
  off();
}

void off() {
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp3, LOW);
  digitalWrite(inp4, LOW);
}