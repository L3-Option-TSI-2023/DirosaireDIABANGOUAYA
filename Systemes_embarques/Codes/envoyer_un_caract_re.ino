
void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  Serial.print("Entrez une phrase : ");
  while (!Serial.available()) {}

  String phrase = Serial.readString();
  Serial.print(phrase);
}
