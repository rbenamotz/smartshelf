#include <ArduinoOTA.h>
#include "user_config.h"

#define OTA_INITIAL_STATE true


bool is_ota_enabled;
unsigned long lastOtaLoop = 0;


void setupOta() {
  is_ota_enabled = OTA_INITIAL_STATE;
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }
  });
  ArduinoOTA.onEnd([]() {
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
  });
  ArduinoOTA.onError([](ota_error_t error) {
  });
  ArduinoOTA.begin();
}

void loopOta() {
  if (!is_ota_enabled) {
    return;
  }
  unsigned long l = millis() - lastOtaLoop;
  if (l<300) {
    return;
  }
  ArduinoOTA.handle();
  lastOtaLoop = millis();
}
