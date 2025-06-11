// version actualizada 10.06.2025
#include <IRremote.h> 
#include <colors.h>

const int IRLedPin = 4;     
const int microAnalog = A0;  

IRsend irsend(IRLedPin);

void setup() {
  Serial.begin(9600);
  pinMode(microAnalog, INPUT);
  pinMode(IRLedPin, OUTPUT);
  randomSeed(analogRead(A1));
}

void loop() {
  int soundValue = analogRead(microAnalog); // Reads the value of ky-037
  Serial.println(soundValue);

  // Adjust this number according to the ambient noise (you can see the limit value on the serial monitor).
  // This number is the "sound of silence", it would be better if you are in a quiet room.
  // If you make some noise, you can see on the serial monitor what numbers the sensor is registering and adjust them.
  // In this version, you can change different values for different colors according to the noise
  // Also, you can change the sensitivity with the potentiometer of the ky-037 module.
  if (soundValue > 480) { 
    // VERSION1: Selects a color based on the range of the sound value.
   
    if (soundValue > 500) {
      Serial.println("send magenta code");
      irsend.sendRaw(magenta, 37, 38);
    } else if (soundValue > 498) {
      Serial.println("send red code");
      irsend.sendRaw(red, 21, 38);
    } else if (soundValue > 496) {
      Serial.println("send white code");
      irsend.sendRaw(white, 23, 38);
    } else if (soundValue > 494) {
      Serial.println("send cyan code");
      irsend.sendRaw(cyan, 27, 38);
    } else if (soundValue > 480) {
      Serial.println("send green code");
      irsend.sendRaw(green, 21, 38);
    }
    delay(90); 
  } else {
    // Optionally, you can set a color for mute.
    Serial.println("silence");
    //irsend.sendRaw(cyan, 27, 38);
    delay(90);
  }
}