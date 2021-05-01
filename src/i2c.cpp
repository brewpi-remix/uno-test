#include "i2c.h"

bool hasLCD;
byte lcdAddress;

int iicScan()
{
    Wire.begin();       // Wire communication begin
    int nDevices = 0;   // Keep count of number of devices

    Log.notice(F(CR "Scanning I2C bus." CR));

    for (byte address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of Write::endTransmission()
        // to see if a device sent an ack on that address
        Wire.beginTransmission(address);
        byte error = Wire.endTransmission();

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
        {
            hasLCD = false;
            Log.notice(F("No I2C devices found." CR));
        }
        else
            hasLCD = true;

    Log.notice(F("I2C scan complete." CR));

    return nDevices;
}
