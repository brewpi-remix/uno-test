#ifndef _MAIN_H
#define _MAIN_H

#include "serialhandler.h"
#include "one_wire.h"
#include "i2c.h"
#include "erase.h"
#include "relaytest.h"

#include <ArduinoLog.h>
#include <Arduino.h>

#include "config.h" // Should be after Arduino.h

void setup();
void loop();

#endif // _MAIN_H
