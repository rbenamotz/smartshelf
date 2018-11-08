#include <ESP8266WiFi.h>
#include "wifi.h"
#include "user_config.h"
#include "common.h"
#include <ESP8266mDNS.h>

#define WIFI_CONNECTION_DELAY_MS 500

void connectToWifi() {
  while (WiFi.status() != WL_CONNECTED) {
    writeToLog("Connecting to WiFi");
    delay(WIFI_CONNECTION_DELAY_MS);
  }
  writeToLog("Connected");
  return;
}


void loopWifi() {
  // reconnectToWifi();
}


void setupWifi() {
  WiFi.mode(WIFI_STA);

  #ifdef IP_ADDR
  IPAddress ip(IP_ADDR);
  IPAddress gateway(IP_GW);
  IPAddress subnet(IP_SUBNET);
  WiFi.config(ip, gateway, subnet);
  #endif
  // WiFi.hostname(HOST_NAME);
  WiFi.begin(WIFI_SSID, WIFI_PSWD);
  connectToWifi();
}
