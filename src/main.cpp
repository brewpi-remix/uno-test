#include "main.h"

void setup()
{
    setSerial(); // Starts serial and ArduinoLog

    // Initialize the LED pin as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LEDON); // Turn LED on

    Log.verbose(F(CR "BrewPi Family Arduino Uno Test beginning." CR));

    // Check I2C bus, then test the correct OneWire pin
    if (iicScan())
        checkSensors(I2C_PIN);
    else
        checkSensors(NORMAL_PIN);

    testRelay(HEATRELAY);
    testRelay(COOLRELAY);

    erase(); // Clear EEPROM

    digitalWrite(LED_BUILTIN, LEDOFF); // Turn LED off
    Log.verbose(F(CR "BrewPi Family Arduino Uno Test complete." CR));
}

void loop() {}
