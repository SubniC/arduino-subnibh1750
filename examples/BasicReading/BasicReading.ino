/*
 * SubniBH1750 — BasicReading
 *
 * Reads the BH1750 ambient light sensor over I2C and prints the
 * illuminance in lux once per second.
 */

#include <Wire.h>
#include <SubniBH1750.h>

// BH1750 at the low I2C address (ADDR pin low or floating).
// Use BH_ADDRESS_HIGH (0x5C) if the ADDR pin is tied high.
SubniBH1750 lightSensor(BH_ADDRESS_LOW);

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Serial.print("Light: ");
  Serial.print(lightSensor.getLux());
  Serial.println(" lux");
  delay(1000);
}
