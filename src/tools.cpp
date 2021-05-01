#include "tools.h"

void _delay(unsigned long ms)
{
    unsigned long then = ms + millis();
    while (millis() < then)
        yield();
}
