/////////////////////////////////////////////////
// minigotchi.ino: everything implemented here //
/////////////////////////////////////////////////

#include "pwnagotchi.h"
#include "packet.h"
#include "deauth.h"
#include "network.h"
#include "webui.h"
#include "raw80211.h"

Pwnagotchi pwnagotchi;
PacketSender packetSender;
DeauthAttack deauthAttack;
Network network("minigotchi", "dj1ch-minigotchi");
WebUI webUI;
Raw80211 raw;

// defines what the minigotchi is to do on startup.
// the only things that should be adjusted here is probably the whitelist.
void setup() {
    Serial.begin(115200);
    Serial.println(" ");
    Serial.println("(^-^) Hi, I'm Minigotchi, your pwnagotchi's best friend!");
    Serial.println(" ");
    Serial.println("You can edit my whitelist in the minigotchi.ino, and you can also edit the json parameters in the packet.cpp");
    Serial.println(" ");
    Serial.println("(>-<) Starting now...");
    network.setupAP();
    deauthAttack.addToWhitelist("SSID"); // add your ssid(s) here
    deauthAttack.addToWhitelist("ANOTHER_SSID");
    raw.init("bssid of ap you will listen on", channel number); // set the settings here, ("BSSID", channel)
    raw.start();
    delay(15000);
    Serial.println(" ");
    Serial.println("('-') Started successfully!");
}

// defines what happens every loop
// this goes on infinitely, until the minigotchi is turned off
void loop() {
    // get local payload from local pwnagotchi
    pwnagotchi.detectAndHandlePwnagotchi();
    delay(5000);

    // stop for deauthing and payload
    raw.stop();

    // send payload(10 times)
    packetSender.sendJsonPayloadMultipleTimes();
    delay(5000);

    // deauth a random ap
    deauthAttack.selectRandomAP();
    deauthAttack.startRandomDeauth();
    delay(5000);

    // restart the process
    raw.start();
}
