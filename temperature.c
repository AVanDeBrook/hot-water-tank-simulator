#include <stdio.h>
#include <stdbool.h>

// true if on, false if off
bool heater = false; // req 15: "The system shall have a water heater."

// in degrees celcius
int DEFAULT_MIN_TEMP = 10; // req 28: "The default minimum temperature shall be 10°C."
int DEFAULT_MAX_TEMP = 100; // req 27: "The default maximum temperature shall be 100°C."
int minTemp = DEFAULT_MIN_TEMP;
int maxTemp = DEFAULT_MAX_TEMP;
int temp = 20; // user defined req 32: "The temperature of water entering the tank shall be room temperature, or 20°C."
int pressureRange = 10; // req 21: "The pressure shall increase faster when then temperature is within a range of 100°C" user defined req 33: "10°C"

void updateTemp() {
  if (heater) {
    temp++;
  }
}

// req 17: "The system shall turn on the water heater when the temperature is below the minimum."
// req 18: "The system shall turn off the water heater when the temperature is above the maximum."
void setHeaterBySensor() {
  if (temp < minTemp) {
    heater = true;
  }
  if (temp > maxTemp) {
    heater = false;
  }
}

// req 30: "The system shall allow changing the temperature sensor’s minimum value."
void setMinTemperature(int newMinTemp) {
  if (newMinTemp > 0 && newMinTemp < maxTemp) {
    minTemp = newMinTemp;
  }
}

// req 31: "The system shall allow changing the temperature sensor’s maximum value."
void setMaxTemperature(int newMaxTemp) {
  if (newMaxTemp > 0 && newMaxTemp > minTemp) {
    maxTemp = newMaxTemp;
  }
}
