#ifndef _MAIN_H
#define _MAIN_H

#include "tools.h"
#include "serialhandler.h"
#include "one_wire.h"
#include "i2c.h"
#include "erase.h"
#include "relaytest.h"
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void setup();
void loop();

extern bool hasLCD;
extern byte lcdAddress;
extern LiquidCrystal_I2C lcd;

#endif // _MAIN_H
