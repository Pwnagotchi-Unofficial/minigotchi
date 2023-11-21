// packet.h: header for packet.cpp

#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "raw80211.h"

class PacketSender {
public:
    String serializeJsonPayload();
    String sendJsonPayload(const char* essid);

    const char* jsonPayload;

private:
};
