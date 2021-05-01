#ifndef _LCD_H
#define _LCD_H

#include "tools.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <Arduino.h>

void lcdInit();

extern bool hasLCD;
extern byte lcdAddress;

#endif // _LCD_H
