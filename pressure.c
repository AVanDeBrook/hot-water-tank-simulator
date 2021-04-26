// FIXME fix Corrina's bad syntax, make it more C less Java

#include <stdio.h>
#include <stdbool.h>

// in psi
int MIN_NOM_OP_PRESSURE = 20; // req 24: "The minimum nominal operating pressure shall be 20 psi (130 kPa)."
int MIN_NOM_OP_PRESSURE = 30; // req 25: "The maximum nominal operating pressure shall be 30 psi (206 kPa)."
int CRIT_PRESSURE = 50; // req 26: "The critical pressure shall be 50 psi (344 kPa)."
int pressure = 25;
int DEFAULT_MAX_TEMP = 100; // req 27: "The default maximum temperature shall be 100°C."
int pressureTempRange = 10; // req 21: "The pressure shall increase faster when then temperature is within a range of 100°C" user defined req 33: "10°C"

// TODO use real time construct to retreieve water level and temperature
// TODO use real time construct to initiate action
void updatePressure() {
  // req 20: "The pressure shall increase when the water level surpasses the second to highest water level sensor."
  if (waterLevel > sensor3WaterLevel) {
    pressure++;
  }
  // req 21: "The pressure shall increase faster when then temperature is within a range of 100°C."
  if (temp > DEFAULT_MAX_TEMP + pressureTempRange) {
    pressure++;
  }
}

// TODO use real time construct to initiate action
// req 22: "The system shall open the outlet valve when the pressure reaches the critical pressure of 50 psi (344 kPa)."
void pressureCheck() {
  if (pressure >= CRIT_PRESSURE) {
    outValve = true;
  }
}
