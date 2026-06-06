#pragma once
#include <Arduino.h>

class WifiTools {
    public:
        static void connectToWiFi(
            const char* ssid,
            const char* password,
            void* tft = nullptr);
};