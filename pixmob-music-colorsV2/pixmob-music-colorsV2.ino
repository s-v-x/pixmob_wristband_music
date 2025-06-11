// version actualizada 10.06.2025
#include <IRremote.h> 
#include <colors.h>

const int IRLedPin = 4;     
const int microDigital = 3; 

IRsend irsend(IRLedPin);

void setup() {
  Serial.begin(9600);
  pinMode(microDigital, INPUT);
  pinMode(IRLedPin, OUTPUT);
  randomSeed(analogRead(A1));
}

void loop() {
  int soundValue = digitalRead(microDigital); // Reads the value of ky-037
  Serial.println(soundValue);

  // You can change the sensitivity with the potentiometer of the ky-037 module.
  if (soundValue == HIGH) { 
    // VERSION2: Chooses a random color each time sound is detected
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