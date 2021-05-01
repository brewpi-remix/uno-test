#ifndef _ONE_WIRE_H
#define _ONE_WIRE_H

#include "tools.h"
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void checkSensors();

extern bool hasLCD;
extern byte lcdAddress;
extern LiquidCrystal_I2C lcd;

#endif // _ONE_WIRE_H
