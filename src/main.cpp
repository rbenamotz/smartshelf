#include <Arduino.h>
#include "wifi.h"
#include "ota.h"
#include "common.h"
#include "user_config.h"
#include "neo.h"

void setup() {
  setupCommon();
  setupWifi();
  setupOta();
  setupNeo();
}

void loop() {
  loopWifi();
  loopOta();
  // loopMqtt();
  loopNeo();
 delay(5);
} 
