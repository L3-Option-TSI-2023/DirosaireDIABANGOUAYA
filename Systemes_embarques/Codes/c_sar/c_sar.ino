
#define LED_JAUNE 24
#define LED_ROUGE 22
#define LED_VERTE 26
#define BOUTON 28

//#define TAILLE_MESSAGE 32
//char message[TAILLE_MESSAGE];
//int longueur_message = 0;

/*void afficher_message();
int lire_message();
void crypter_message(int cle);
void decrypter_message(int cle);*/

void setup() {
  // Initialisation des broches des LED et du bouton
  Serial.begin(9600);
  pinMode(LED_JAUNE, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_VERTE, OUTPUT);
  pinMode(BOUTON, INPUT_PULLUP);
  
  // Extinction de toutes les LED au démarrage
  digitalWrite(LED_JAUNE, LOW);
  digitalWrite(LED_ROUGE, LOW);
  digitalWrite(LED_VERTE, LOW);
}

void loop() {
  

//  if (digitalRead(LED_JAUNE) == HIGH) {
//    // Copie du message saisi
//      longueur_message = lire_message();
//      afficher_message();
//      
//    
//
//  } else if (digitalRead(LED_ROUGE) == HIGH) {
//         
//      int cle = 3; 
//      longueur_message = lire_message();
//      crypter_message(cle);
//      afficher_message();
//  } else if (digitalRead(LED_VERTE) == HIGH) {
//   
//    int cle = 3; 
//    longueur_message = lire_message();
//    decrypter_message(cle);
//    afficher_message();
//   
//  }

 while(Serial.available()>0)
 {
      char c = Serial.read();
      char rep;
      int cle = 3;
      if(c != '\n' || c != ' ')
      {
      if(digitalRead(LED_JAUNE) == HIGH)
        Serial.print(c);
      else if(digitalRead(LED_ROUGE) == HIGH)
           {
              if (c >= 'A' && c <= '}') {
                 rep = ((c - 'A' + cle) % 61) + 'A';
                }
            
             
           }
       else if( digitalRead(LED_VERTE) == HIGH)
           {
               if(c>='A' && c<='}')
                { int var= (c-'A')-cle  ; 
                   if(var<0)
                     var+=61; 
    
                  rep=(var)%61+'A' ;
                 }
            
           }
      }    
          Serial.print(rep);
                  
 }    
    
      


  if (digitalRead(BOUTON) == LOW) {
    delay(1);
    if(digitalRead(BOUTON)== HIGH)
    {
    if (digitalRead(LED_JAUNE) == LOW && digitalRead(LED_ROUGE) == LOW && digitalRead(LED_VERTE) == LOW)
    {
      digitalWrite(LED_JAUNE, HIGH); 
      digitalWrite(LED_VERTE, LOW);
      digitalWrite(LED_ROUGE, LOW);        
    } else {
    
    if (digitalRead(LED_JAUNE) == HIGH) 
        {
        digitalWrite(LED_ROUGE, HIGH);
        digitalWrite(LED_JAUNE, LOW);
        digitalWrite(LED_VERTE, LOW); 
        } else 
          if (digitalRead(LED_ROUGE) == HIGH) 
        {
          digitalWrite(LED_VERTE, HIGH);
          digitalWrite(LED_ROUGE, LOW);
           digitalWrite(LED_JAUNE, LOW);
         } else 
           if (digitalRead(LED_VERTE) == HIGH) 
         {
          digitalWrite(LED_JAUNE, HIGH);
          digitalWrite(LED_VERTE, LOW);
          digitalWrite(LED_ROUGE, LOW);
         }
      }
    }
  } 
 }

/*// Fonction pour afficher le message sur la console série
void afficher_message() {
  Serial.print("Message : ");
  for(int i = 0; i<longueur_message; i++)
  {
    Serial.print(message[i]);
  }
  //Serial.println(message);
  //Serial.println("--------");
}

// Fonction pour lire le message saisi par l'utilisateur
int lire_message() {
  int index = 0;
  while (index < TAILLE_MESSAGE - 1) {
    if (Serial.available() != 0) {
      char caractere = Serial.read();
      if (caractere == ' ' || caractere == '\n') {
        break;
      }
      message[index] = caractere;
      index++;
    }
  }
  message[index] = '\0';
  return index;
}


// Fonction pour crypter le message en utilisant une clé de chiffrement
void crypter_message(int cle) {
  for (int i = 0; i < longueur_message; i++) {
    // Vérification si le caractère est une lettre majuscule
    if (message[i] >= 'A' && message[i] <= '}') {
      message[i] = ((message[i] - 'A' + cle) % 61) + 'A';
    }
    // Vérification si le caractère est une lettre minuscule
    /*else if (message[i] >= 'a' && message[i] <= 'z') {
      message[i] = ((message[i] - 'a' + cle) % 26) + 'a';
    }*/
    


// Fonction pour décrypter le message en utilisant une clé de déchiffrement
/*void decrypter_message(int cle) {
  // Pour décrypter, on utilise la clé opposée (inverse)
 // cle = 26 - cle;
 // crypter_message(cle);
  for(int i=0;i<longueur_message;i++){ 
  if(message[i]>='A' && message[i]<='}')
  { int var= (message[i]-'A')-cle  ; 
    if(var<0)
     var+=61; 
    
    message[i]=(var)%61+'A' ;
  }/* else if (message[i] >= 'a' && message[i] <= 'z') {
      int var = (message[i]-'a')-cle;
      if(var<0)
      {
        var+=26;
      }
      message[i] = (var) % 26 + 'a';
    }    
   }*/
//   }
//}*/
