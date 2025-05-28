// version actualizada 28.05.2025
#include <IRremote.h> // Usa la biblioteca IRremote estándar
#include <colors.h>

const int IRLedPin = 4;      // Pin para el LED IR
const int microAnalog = A0; // Pin analógico para el sensor de sonido
const int microDigital = 3; // Pin digital para el sensor de sonido

IRsend irsend(IRLedPin); // Configura el pin en el constructor

void setup() {
  Serial.begin(115200);
  pinMode(microAnalog, INPUT);
  pinMode(microDigital, INPUT);
  randomSeed(analogRead(A1));
}

void loop() {
  int soundValue = analogRead(microAnalog); // Lee el valor del sensor de sonido
  Serial.println(soundValue); // Imprime el valor del sonido para depuración

  if (soundValue > 498) { // Ajusta el umbral según sea necesario
    // VERSION2: Elige un color aleatorio cada vez que detecta sonido 
    int randomNumber = random(1, 7);
    
    if (randomNumber == 1) {
      Serial.println("send red code");
      irsend.sendRaw(red, 21, 38);
    }
    if (randomNumber == 2) {
      Serial.println("send magenta code");
      irsend.sendRaw(magenta, 37, 38);
    }
    if (randomNumber == 3) {
      Serial.println("send pink code");
      irsend.sendRaw(pink, 22, 38);
    }
    if (randomNumber == 4){
      Serial.println("send white code");
      irsend.sendRaw(white, 23, 38);
    }
    if (randomNumber == 5){
      Serial.println("send cyan code");
      irsend.sendRaw(cyan, 27, 38);
    }
    if (randomNumber == 6){
      Serial.println("send mint code");
      irsend.sendRaw(mint, 24, 38);
    }

    delay(90);

  }
}