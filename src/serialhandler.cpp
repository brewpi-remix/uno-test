#include "serialhandler.h"

void setSerial() {
    Serial.begin(BAUD);
    Serial.flush();
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, false);
    Serial.println();
}
