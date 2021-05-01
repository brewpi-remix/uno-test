#ifndef _TOOLS_H
#define _TOOLS_H

#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

void _delay(unsigned long ms);

extern bool hasLCD;
extern byte lcdAddress;
extern LiquidCrystal_I2C lcd;

#endif // _TOOLS_H