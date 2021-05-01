#include "main.h"

void setup()
{
    // Initialize relays off
    pinMode(HEATRELAY, OUTPUT);
    digitalWrite(HEATRELAY, RELAYOFF);
    pinMode(COOLRELAY, OUTPUT);
    digitalWrite(COOLRELAY, RELAYOFF);

    // Initialize the LED pin as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LEDON); // Turn LED on
    setSerial(); // Starts serial and ArduinoLog

    Log.verbose(F(CR "BrewPi Family Arduino Uno Test beginning." CR));

    // Check and test LCD
    iicScan(); // Get I2C address
    if (hasLCD)
        lcdInit();
    else
        Log.verbose(F(CR "Did not find an LCD." CR));

    erase();        // Erase EEPROM
    checkSensors(); // Test the OneWire pin
    testRelays();   // Test relays

    digitalWrite(LED_BUILTIN, LEDOFF); // Turn LED off
    Log.verbose(F(CR "BrewPi Family Arduino Uno Test complete." CR));
    if (hasLCD)
    {
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Testing complete.");
        _delay(3000);
        lcd.clear();
        lcd.noBacklight();
    }
}

void loop() {}
