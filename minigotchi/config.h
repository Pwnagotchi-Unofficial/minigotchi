/**
 * config.h: header files for config.cpp
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <string>
#include <vector>
#include <iostream>
#include <random>

class Config {
public:
    static bool deauth;
    static bool advertise;
    static int baud;
    static const char* bssid;
    static int channel;
    static std::vector<std::string> whitelist;
    static int epoch;
    static std::string face;
    static uint8_t identity;
    static std::string name;
    static bool associate;
    static int bored_num_epochs;
    static int channels[3];
    static int excited_num_epochs;
    static int hop_recon_time;
    static int max_inactive_scale;
    static int max_interactions;
    static int max_misses_for_recon;
    static int min_recon_time;
    static int min_rssi;
    static int recon_inactive_multiplier;
    static int recon_time;
    static int sad_num_epochs;
    static int sta_ttl;
    static int pwnd_run;
    static int pwnd_tot;
    static std::string session_id;
    static int uptime;
    static std::string version;

private:
    static int random(int min, int max);
    static int time();
};

#endif // CONFIG_H