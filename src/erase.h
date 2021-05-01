#ifndef _ERASE_H
#define _ERASE_H

#include "tools.h"
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <EEPROM.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void erase();

extern bool hasLCD;
extern byte lcdAddress;
extern LiquidCrystal_I2C lcd;

#endif // _ERASE_H
