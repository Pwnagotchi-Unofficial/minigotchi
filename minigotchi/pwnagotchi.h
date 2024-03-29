////////////////////////////////////////////////////////////////////////////
// pwnagotchi.h: header files for pwnagotchi.cpp, and perhaps channel.cpp //
////////////////////////////////////////////////////////////////////////////

#ifndef PWNAGOTCHI_H
#define PWNAGOTCHI_H

#include "raw80211.h"
#include "packet.h"
#include <ArduinoJson.h>
#include <user_interface.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>

class Pwnagotchi {
public:
    Pwnagotchi();
    void detect();
    void handle(const wifi_ieee80211_mac_hdr_t *hdr, int rssi, const unsigned char *buff, short unsigned int buff_len);
    String extractMAC(const unsigned char *buff);
    void getMAC(char* addr, const unsigned char* buff, int offset);

private:
    String essid;
    bool pwnagotchiDetected;
};

#endif // PWNAGOTCHI_H
