#ifndef _SUPPORT_H
#define _SUPPORT_H

#include "tools.h"
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void setSerial();
void _delay(unsigned long);

extern bool hasLCD;
extern byte lcdAddress;
extern LiquidCrystal_I2C lcd;

#endif // _SUPPORT_H
