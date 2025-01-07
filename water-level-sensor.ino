// Name: Mark Katigbak
// Water Level Sensor with LCD screen

#include <LiquidCrystal.h>

// Water level sensor pin
const int waterSensor = A1;
int waterSensorValue = 0;

// LCD pins
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// LED pins
const int redLED = 12;
const int blueLED = 11;

// Potentiometer pin
const int potentiometer = A0;

void setup() {
  // LEDs
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  
  // LCD 16 rows, 2 columns
  lcd.begin(16, 2);
  lcd.print("Threshold: ");

  // Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Convert water level sensor value to mm
  waterSensorValue = (analogRead(waterSensor) / 10);
  
  // Scale potentiometer value to water sensor value
  int potentiometerValue = analogRead(potentiometer);
  potentiometerValue = map(potentiometerValue, 0, 1023, 0, 40);

  // Print water level threshold
  lcd.setCursor(11, 0);
  lcd.print(potentiometerValue);
  lcd.print("mm");

  Serial.print("Threshold: ");
  Serial.println(potentiometerValue);
  
  // Print the water level in 2nd column
  lcd.setCursor(0, 1);
  lcd.print("Water Lvl: ");
  lcd.print(waterSensorValue);
  lcd.print("mm");

  Serial.print("Water level: ");
  Serial.println(waterSensorValue);

  if (waterSensorValue > (potentiometerValue + 5)) {
    // Turn fan (red LED) on
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
} else if (waterSensorValue < (potentiometerValue - 5)) {
    // Turn pump (blue LED) on
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
} else {
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
}
  
  // Execute every 5 seconds
  delay(5000);
}