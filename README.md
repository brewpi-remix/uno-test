# <a name="top"></a>![BrewPi Legacy Remix Logo](https://raw.githubusercontent.com/brewpi-remix/brewpi-www-rmx/master/images/brewpi_logo.png)

# BrewPi Family Arduino Uno Test

This firmware will allow you to test the setup of your BrewPi family Arduino Uno.  The program will:

1. Turn the onboard LED on
1. Scan for an I2C device.  If found, it will use A0 for sensor tests; otherwise, it will use the original A4 pin for sensors.  If the program detects an I2C LCD, a test message will display
1. Check the OneWire
    1. Display if parasitic sensors are present on the bus
    1. Display the number and type of sensors found
    1. Display the address and current temperature for each sensor
1. Test the heat and cool relays (pins 5 and 6)
1. Clear the EEPROM to avoid issues saving the sensors later on

# ![Arduino Uno Pin Diagram](https://github.com/brewpi-remix/uno-test/blob/main/images/Arduino-Uno-Pin-Diagram.png)

It will automatically check for an I2C display, and if found, will show a test on the display.  It will then scan the proper pin for the variant; A4 if no I2C is detected, and A0 if an I2C is present.

Results using a standard or parallel LCD system:

```
BrewPi Family Arduino Uno Test beginning.

Scanning I2C bus.
No I2C devices found.
I2C scan complete.

Checking 18 for OneWire devices.
Parasitic power is off for the OneWire bus on pin 18.
Detected 2 devices on pin 18.
Device 18:0 is a DS18B20 device.
Device 18:1 is a DS18B20 device.
Sensor: 18:0    Address: 28:EE:7E:28:2C:15:0:BB Temperature: 18.94°C
Sensor: 18:1    Address: 28:EE:B1:35:23:15:0:C  Temperature: 21.62°C

Testing relay pin 5.
Turning pin 5 on.
Turning pin 5 off.
Relay test on pin 5 complete.

Testing relay pin 6.
Turning pin 6 on.
Turning pin 6 off.
Relay test on pin 6 complete.

Clearing EEPROM.
EEPROM clear complete.

BrewPi Family Arduino Uno Test complete.
```

Results using an I2C LCD system:

```
BrewPi Family Arduino Uno Test beginning.

Scanning I2C bus.
I2C device found at address 0x3F.
Setting LCD display at 0x3F.
I2C scan complete.

Checking 14 for OneWire devices.
Parasitic power is off for the OneWire bus on pin 14.
Detected 2 devices on pin 14.
Device 14:0 is a DS18B20 device.
Device 14:1 is a DS18B20 device.
Sensor: 14:0    Address: 28:EE:7E:28:2C:15:0:BB Temperature: 19.00°C
Sensor: 14:1    Address: 28:EE:B1:35:23:15:0:C  Temperature: 19.31°C

Testing relay pin 5.
Turning relay on pin 5 on.
Turning relay on pin 5 off.
Relay test on pin 5 complete.

Testing relay pin 6.
Turning relay on pin 6 on.
Turning relay on pin 6 off.
Relay test on pin 6 complete.

Clearing EEPROM.
EEPROM clear complete.

BrewPi Family Arduino Uno Test complete.
```

# ![LCD Display](https://github.com/brewpi-remix/uno-test/blob/main/images/i2c_test.jpg)
