#ifndef _RELAYTEST_H
#define _RELAYTEST_H

#include "tools.h"
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void initRelays();
void testRelays();

extern bool hasLCD;
extern byte lcdAddress;
extern LiquidCrystal_I2C lcd;

#endif // _RELAYTEST_H
