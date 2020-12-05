#include "erase.h"

void erase()
{
  // Iterate through each byte of the EEPROM storage and clear it
    Log.notice(F(CR "Clearing EEPROM." CR));

    for (uint16_t i = 0; i < EEPROM.length(); i++)
    {
        EEPROM.write(i, 0);
    }

    Log.notice(F("EEPROM clear complete." CR));
}
