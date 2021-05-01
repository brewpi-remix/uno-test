#include "relaytest.h"

const char *pinName[] = {
    "Heat",
    "Cool"};

const int pinNum[] = {
    HEATRELAY,
    COOLRELAY};

void testRelays()
{
    for (int i = 0; i < (int)sizeof(pinNum) / (int)sizeof(pinNum[0]); i++)
    {
        Log.notice(F(CR "Testing %s relay on pin %d." CR), pinName[i], pinNum[i]);
        if (hasLCD)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Testing ");
            lcd.print(pinName[i]);
            lcd.print(" relay");
            lcd.setCursor(0, 1);
            lcd.print("on pin ");
            lcd.print(pinNum[i]);
            lcd.print(": ");
        }
        _delay(1000);
        pinMode(pinNum[i], OUTPUT);
        digitalWrite(pinNum[i], RELAYOFF);
        _delay(1000);
        Log.notice(F("Turning %s relay on pin %d on." CR), pinName[i], pinNum[i]);
        if (hasLCD)
        {
            lcd.setCursor(10, 1);
            lcd.print("On");
        }
        digitalWrite(pinNum[i], RELAYON);
        _delay(2000);
        Log.notice(F("Turning %s relay on pin %d off." CR), pinName[i], pinNum[i]);
        if (hasLCD)
        {
            lcd.setCursor(10, 1);
            lcd.print("Off");
        }
        digitalWrite(pinNum[i], RELAYOFF);
        _delay(2000);
        Log.notice(F("%s relay test on pin %d complete." CR), pinName[i], pinNum[i]);
       if (hasLCD)
        {
            lcd.setCursor(10, 1);
            lcd.print("Complete");
        }
        _delay(2000);
    }
}
