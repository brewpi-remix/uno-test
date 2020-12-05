#include "i2c.h"

int iicScan()
{
    Wire.begin();                    // Wire communication begin
    byte error, address, lcdAddress; // Variable for error and I2C address
    int nDevices = 0;                // Keep count of number of devices

    Log.notice(F(CR "Scanning I2C bus." CR));

    for (address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of Write::endTransmission()
        // to see if a device sent an ack on that address
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Log.notice(F("I2C device found at address %X." CR), address);
            lcdAddress = address;
            nDevices++;
        }
        else if (error == 4)
        {
            Log.notice(F("Unknown error from I2C device found at address %X." CR), address);
        }
    }
    Wire.end();

    if (nDevices == 0)
        Log.notice(F("No I2C devices found." CR));
    else
        iicTest(lcdAddress);

    Log.notice(F("I2C scan complete." CR));

    return nDevices;
}

void iicTest(byte lcdAddress)
{
    Log.notice(F("Setting LCD display at %X." CR), lcdAddress);
    LiquidCrystal_I2C lcd(lcdAddress, 20, 4);
    lcd.init(); // initialize the lcd
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(1, 0);
    lcd.print("Hello, Homebrewer!");
    lcd.setCursor(0, 1);
    lcd.print("Your BrewPi Display");
    lcd.setCursor(7, 2);
    lcd.print("Works!");
    lcd.setCursor(2, 3);
    lcd.print("@lbussy says hi!");
}
