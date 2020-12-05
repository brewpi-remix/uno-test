#ifndef _ONE_WIRE_H
#define _ONE_WIRE_H

#include <ArduinoLog.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void checkSensors(int pin);

#endif // _ONE_WIRE_H
