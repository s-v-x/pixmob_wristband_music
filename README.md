# PIXMOB WRISTBAND COLORS
## Introduction

This code allows you to synchronize the colors of the Pixmob wristband (used in Coldplay, Taylor Swift, Karol G and more shows) to the rhythm of the music using Arduino and Elegoo components in two variants:

1. VERSION 1: Manual adjustment based on detected sound levels with as many colors as you like.

2. VERSION 2: Random color selection when sensor detects any sound.

In any case, you can customize the number of colors and the method that best suits your preferences.

Original idea inspired by: [Pixmob-music-rythm] (https://github.com/drneox/pixmob-music-rhythm).

Color codes used, renamed, and updated from: [IR codes] (https://github.com/danielweidman/flipper-pixmob-ir-codes).

## Components and diagram

###Components:
- Arduino
- KY-005 Infrared Transmitter module (info [here] (https://arduinomodules.info/ky-005-infrared-transmitter-sensor-module/))
- KY-037 Sensor module (info [here] (https://arduinomodules.info/ky-037-high-sensitivity-sound-detection-module/))
- PNP Transistor

### Diagram
![Diagram](diagrama_pixmob_eras.jpg)


## Two colors version

### Version 1:
Manual adjustment based on detected sound levels: You can select different colors based on the sound level detected by the sound sensor. For example, you can set one color for silence, another for lower volume, a different one for slightly louder music, and so on, with as many colors as you like.


### Version 2:
Random color selection: The sensor detects a sound, generates a random number, and displays the color corresponding to that random number.