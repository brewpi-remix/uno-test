#include "one_wire.h"

const char *owPinName[] = {
    "A0",
    "A4"};

const int owPinNum[] = {
    I2C_PIN,
    NORMAL_PIN};

void checkSensors()
{
    int pin;
    (hasLCD) ? pin = 0 : pin = 1;
    Log.notice(F(CR "Checking %s for OneWire devices." CR), owPinName[pin]);
    if (hasLCD)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Checking OneWire on");
        lcd.setCursor(0, 1);
        lcd.print("pin ");
        lcd.print(owPinName[pin]);
        lcd.print(".");
        _delay(3000);
    }

    // Create a OneWire bus on pin
    OneWire oneWire(owPinNum[pin]);
    // Pass our OneWire reference to Dallas Temperature.
    DallasTemperature sensors(&oneWire);

    sensors.begin();

    bool parasitic = sensors.isParasitePowerMode();
    Log.notice(F("Parasitic power is %s for the OneWire bus on pin %s." CR), parasitic ? "on" : "off", owPinName[pin]);
    if (hasLCD)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Parasitic power is");
        lcd.setCursor(0, 1);
        if (parasitic)
            lcd.print("on ");
        else
            lcd.print("off ");
        lcd.print("for pin ");
        lcd.print(owPinName[pin]);
        lcd.print(".");
        _delay(3000);
    }

    Log.notice(F("Detected %d devices on pin %d." CR), sensors.getDeviceCount(), pin);
    if (hasLCD)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Detected ");
        lcd.print(sensors.getDeviceCount());
        lcd.print(" devices.");
        _delay(2000);
    }

    byte deviceAddress[8];

    for (int i = 0; i < sensors.getDeviceCount(); i++)
    {
        sensors.getAddress(deviceAddress, i);
        String article = "";
        String device = "";
        switch (deviceAddress[0])
        {
        case DS18S20MODEL:
            article = "a ";
            device = "DS18S20";
            break;
        case DS18B20MODEL:
            article = "a ";
            device = "DS18B20";
            break;
        case DS1822MODEL:
            article = "a ";
            device = "DS1822";
            break;
        case DS1825MODEL:
            article = "a ";
            device = "DS1825";
            break;
        default:
            article = "an ";
            device = "unknown";
        }
        Log.notice(F("Device %s:%d is %s%s device." CR), owPinName[pin], i, article.c_str(), device.c_str());
        if (hasLCD)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Device ");
            lcd.print(owPinName[pin]);
            lcd.print(":");
            lcd.print(i);
            lcd.print(" is ");
            lcd.print(article);
            lcd.setCursor(0,1);
            lcd.print(device);
            lcd.print(" device.");
            _delay(2000);
        }
    }
    _delay(1000);

    sensors.requestTemperatures(); // Send the command to get temperatures
    _delay(750);

    for (int i = 0; i < sensors.getDeviceCount(); i++)
    {
        float temp = sensors.getTempCByIndex(i);
        DeviceAddress deviceAddress;
        sensors.getAddress(deviceAddress, i);
        char address[25];

        sprintf(address, "%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X%c",
            deviceAddress[0],
            deviceAddress[1],
            deviceAddress[2],
            deviceAddress[3],
            deviceAddress[4],
            deviceAddress[5],
            deviceAddress[6],
            deviceAddress[7],
            '\0');

        Log.notice(F("Sensor: %d:%d, address: %s, temperature: %D°C" CR),
                   pin,
                   i,
                   address,
                   temp);

        sprintf(address, "%02X%02X%02X%02X%02X%02X%02X%02X%c",
            deviceAddress[0],
            deviceAddress[1],
            deviceAddress[2],
            deviceAddress[3],
            deviceAddress[4],
            deviceAddress[5],
            deviceAddress[6],
            deviceAddress[7],
            '\0');

        if (hasLCD)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Sensor: ");
            lcd.print(owPinName[pin]);
            lcd.print(":");
            lcd.print(i);
            lcd.print(", addr:");
            lcd.setCursor(0, 1);
            lcd.print(address);
            lcd.setCursor(0, 2);
            lcd.print("Temperature: ");
            lcd.print(temp);
            lcd.write(0b11011111);
            lcd.print("C");
            _delay(2000);
        }
    }
}
