#include "lcd.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

void lcdInit()
{
    if (hasLCD)
    {
        Log.notice(F("Setting LCD display at %X." CR), lcdAddress);
        // Initialize the lcd
        lcd.scan_address(lcdAddress);
        lcd.init();
        lcd.begin(20, 4);
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(1, 0);
        // Print a message to the LCD.
        lcd.print("Hello, Homebrewer!");
        lcd.setCursor(0, 2);
        lcd.print("Your BrewPi display");
        lcd.setCursor(7, 3);
        lcd.print("works.");
        _delay(3000);        
    }
}
