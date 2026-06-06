#include "WifiTools.h"
#include <WiFi.h>
#include <Adafruit_ST7789.h>

void WifiTools::connectToWiFi(
    const char* ssid,
    const char* password,
    void* tftPtr) {

    Adafruit_ST7789* tft = (Adafruit_ST7789*)tftPtr;
        
    WiFi.begin(ssid, password);

    if (tft) {

        // Initialize display
        tft->init(135, 240);           
        tft->setRotation(1); 
        tft->fillScreen(ST77XX_BLACK);

        // Set up text formatting
        tft->setTextColor(ST77XX_WHITE);
        tft->setTextSize(2);

        // 1. Connect to Wi-Fi Network
        tft->setCursor(10, 20);
        tft->println("Connecting to:");
        tft->setTextColor(ST77XX_CYAN);
        tft->setCursor(10, 45);
        tft->println(ssid);
    }

    // Blink dots until connected
    int dotCount = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        if (tft) {
            tft->setCursor(10 + (dotCount * 12), 75);
            tft->print(".");
        }
        dotCount = (dotCount + 1) % 15;
    }

    if (tft) {
        tft->fillScreen(ST77XX_BLACK);
        tft->setTextColor(ST77XX_GREEN);
        tft->setCursor(10, 20);
        tft->println("Wi-Fi Connected!");
    }
}