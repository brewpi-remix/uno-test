#include "erase.h"

void erase()
{
    Log.notice(F(CR "Clearing EEPROM." CR));
    if (hasLCD)
    {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Clearing EEPROM.");
        _delay(1000);
    }
    for (int i = 0; i < (int)EEPROM.length(); i++)
    {
        // Only clear EEPROM if it's not clear
        // This reduces wear on the memory
        if (EEPROM.read(i) != 0)
            EEPROM.write(i, 0);
    }
    _delay(1000);
    Log.notice(F("EEPROM clear complete." CR));
    if (hasLCD)
    {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("EEPROM cleared.");
        _delay(2000);
    }
}
