# Water Level Sensor with LCD Screen

## Overview
This program reads data from a water level sensor and displays the water level and a threshold value on an LCD screen. It also controls two LEDs (red and blue) based on the water level, simulating the control of a fan and a pump. The threshold for the water level is adjustable using a potentiometer.

## Components
* Water Level Sensor: Connected to analog pin ```A1``` to measure the water level.
* Potentiometer: Connected to analog pin ```A0``` to set the water level threshold.
* LCD Display: Displays the water level and threshold (using pins ```2```, ```3```, ```4```, ```5```, ```6```, ```7```).
* Red LED: Simulates a fan, lights up when the water level is too high.
* Blue LED: Simulates a pump, lights up when the water level is too low.

## Pin Configuration
* Water Level Sensor: Analog pin ```A1```.
* Potentiometer: Analog pin ```A0```.
* Red LED (Fan): Digital pin ```12```.
* Blue LED (Pump): Digital pin ```11```.
* LCD: Pins ```2``` (RS), ```3``` (EN), ```4``` (D4), ```5``` (D5), ```6``` (D6), ```7``` (D7).

## Key Functions
```setup()```
* Initializes the LCD and LEDs.
* Starts serial communication at 9600 baud for debugging.

```loop()```
* Reads and converts the water level sensor value to a millimeter value.
* Maps the potentiometer value to adjust the water level threshold.
* Displays the water level and threshold on the LCD.
* Controls the LEDs based on the comparison of the water level and threshold:
  - Red LED (fan) turns on if the water level exceeds the threshold by more than 5mm.
  - Blue LED (pump) turns on if the water level is lower than the threshold by more than 5mm.
  - Both LEDs are off if the water level is close to the threshold.

```delay(5000)```
* Pauses the program for 5 seconds between measurements.

## Logic
* Water level is displayed on the LCD and serial monitor in millimeters.
* Threshold is set by the potentiometer, displayed on the LCD.
* If the water level exceeds the threshold (with a 5mm buffer), the red LED (fan) turns on.
* If the water level is below the threshold (with a 5mm buffer), the blue LED (pump) turns on.
* Both LEDs are off if the water level is within the threshold range.

## How to Use
1. Connect the water level sensor, potentiometer, and LEDs to the specified pins.
2. Upload the code to your Arduino.
3. Open the Serial Monitor to view the water level and threshold values.
4. Adjust the potentiometer to set the water level threshold.
5. Observe the water level on the LCD and see the LEDs react accordingly.

## Requirements
* LiquidCrystal Library: Required to control the LCD screen. This is available by default in the Arduino IDE.
