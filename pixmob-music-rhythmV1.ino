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
    // VERSION1: Selecciona un color basado en el rango del valor del sonido.
   
    if (soundValue > 504) {
      Serial.println("send magenta code");
      irsend.sendRaw(magenta, 37, 38);
    } else if (soundValue > 502) {
      Serial.println("send red code");
      irsend.sendRaw(red, 21, 38);
    } else if (soundValue > 500) {
      Serial.println("send white code");
      irsend.sendRaw(white, 23, 38);
    } else if (soundValue > 499) {
      Serial.println("send cyan code");
      irsend.sendRaw(cyan, 27, 38);
    } else if (soundValue > 498) {
      Serial.println("send green code");
      irsend.sendRaw(green, 21, 38);
    }
    delay(90); // Ajusta el tiempo de delay según tus necesidades
  } else {
    // Opcionalmente, puedes configurar un color para el silencio o bajo sonido
    Serial.println("silence");
    //irsend.sendRaw(cyan, 27, 38);
    delay(90);
  }
}