#ifndef _I2C_H
#define _I2C_H

#include "tools.h"
#include "lcd.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoLog.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

int iicScan();

#endif // _I2C_H
