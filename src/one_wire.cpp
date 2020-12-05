#include "one_wire.h"

void checkSensors(int pin)
{
    Log.notice(F(CR "Checking %d for OneWire devices." CR), pin);

    // Create a OneWire bus on pin
    OneWire oneWire(pin);
    // Pass our oneWire reference to Dallas Temperature.
    DallasTemperature sensors(&oneWire);

    sensors.begin();

    Log.notice(F("Parasitic power is %s for the OneWire bus on pin %d." CR), sensors.isParasitePowerMode() ? "on" : "off", pin);

    Log.notice(F("Detected %d devices on pin %d." CR), sensors.getDeviceCount(), pin);

    byte deviceAddress[8];

    for (int i = 0; i < sensors.getDeviceCount(); i++)
    {
        sensors.getAddress(deviceAddress, i);
        String device = "";
        switch (deviceAddress[0])
        {
        case DS18S20MODEL:
            device = "a DS18S20";
            break;
        case DS18B20MODEL:
            device = "a DS18B20";
            break;
        case DS1822MODEL:
            device = "a DS1822";
            break;
        case DS1825MODEL:
            device = "a DS1825";
            break;
        default:
            device = "an unknown";
        }
        Log.notice(F("Device %d:%d is %s device." CR), pin, i, device.c_str());
    }
    delay(1000);

    sensors.requestTemperatures(); // Send the command to get temperatures
    delay(750);

    for (int i = 0; i < sensors.getDeviceCount(); i++)
    {
        float temp = sensors.getTempCByIndex(i);
        DeviceAddress deviceAddress;
        sensors.getAddress(deviceAddress, i);
        Log.notice(F("Sensor:\t%d:%d\tAddress: %x:%x:%x:%x:%x:%x:%x:%x\tTemperature: %D°C" CR),
        pin,
        i,
        deviceAddress[0],
        deviceAddress[1],
        deviceAddress[2],
        deviceAddress[3],
        deviceAddress[4],
        deviceAddress[5],
        deviceAddress[6],
        deviceAddress[7],
        temp);
    }
}
