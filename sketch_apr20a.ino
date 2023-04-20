#include <Servo.h>

Servo monServo;
const int boutonPin = 2;
int boutonEtatPrec = HIGH;
int servoPos = 0;

void setup() {
  pinMode(boutonPin, INPUT);
  Serial.begin(9600); // Initialise la communication série avec une vitesse de 9600 bauds
  monServo.attach(9); // Broche de signal du servo moteur
}

void loop() {
  int boutonEtat = digitalRead(boutonPin);
  
  if (boutonEtat == LOW && boutonEtatPrec == HIGH) {
    // Le bouton poussoir a été pressé une fois
    Serial.println("Bouton pressé");
    
    if (servoPos == 0) {
      // Servo à 0 degré, le faire bouger à 180 degrés
      for (int pos = 0; pos <= 90; pos++) {
        monServo.write(pos);
        delay(15);
      }
      servoPos = 90;
    } else {
      // Servo à 180 degrés, le faire bouger à 0 degré
      for (int pos = 90; pos >= 0; pos--) {
        monServo.write(pos);
        delay(15);
      }
      servoPos = 0;
    }
  }
  
  boutonEtatPrec = boutonEtat;
}
