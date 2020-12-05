#include "relaytest.h"

void testRelay(int pin)
{
    Log.notice(F(CR "Testing relay pin %d." CR), pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, RELAYOFF);
    delay(1000);
    Log.notice(F("Turning relay on pin %d on." CR), pin);
    digitalWrite(pin, RELAYON);
    delay(1000);
    Log.notice(F("Turning relay on pin %d off." CR), pin);
    delay(250);
    digitalWrite(pin, RELAYOFF);
    Log.notice(F("Relay test on pin %d complete." CR), pin);
}
