#include "relaytest.h"

const char *relayPinName[] = {
    "Heat",
    "Cool"};

const int relayPinNum[] = {
    HEATRELAY,
    COOLRELAY};

void testRelays()
{
    for (int i = 0; i < (int)sizeof(relayPinNum) / (int)sizeof(relayPinNum[0]); i++)
    {
        Log.notice(F(CR "Testing %s relay on pin %d." CR), relayPinName[i], relayPinNum[i]);
        if (hasLCD)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Testing ");
            lcd.print(relayPinName[i]);
            lcd.print(" relay");
            lcd.setCursor(0, 1);
            lcd.print("on pin ");
            lcd.print(relayPinNum[i]);
            lcd.print(": ");
        }
        _delay(1000);
        pinMode(relayPinNum[i], OUTPUT);
        digitalWrite(relayPinNum[i], RELAYOFF);
        _delay(1000);
        Log.notice(F("Turning %s relay on pin %d on." CR), relayPinName[i], relayPinNum[i]);
        if (hasLCD)
        {
            lcd.setCursor(10, 1);
            lcd.print("On");
        }
        digitalWrite(relayPinNum[i], RELAYON);
        _delay(2000);
        Log.notice(F("Turning %s relay on pin %d off." CR), relayPinName[i], relayPinNum[i]);
        if (hasLCD)
        {
            lcd.setCursor(10, 1);
            lcd.print("Off");
        }
        digitalWrite(relayPinNum[i], RELAYOFF);
        _delay(2000);
        Log.notice(F("%s relay test on pin %d complete." CR), relayPinName[i], relayPinNum[i]);
       if (hasLCD)
        {
            lcd.setCursor(10, 1);
            lcd.print("Complete");
        }
        _delay(2000);
    }
}
