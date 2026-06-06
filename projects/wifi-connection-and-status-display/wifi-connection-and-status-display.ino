#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_ST7789.h> 
#include <SPI.h>
#include ""
#include <WifiTools.h>

// Onboard Hardware Pins for IdeaSpark 1.14" ST7789 Board
#define TFT_CS    15
#define TFT_DC     2
#define TFT_RST    4
#define TFT_BL    32  

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const char* ssid     = Config::WIFI_SSID;
const char* password = Config::WIFI_PASSWORD;

// Public Weather API Endpoint (No Key Required - London coordinates)
const char* api_url = "https://open-meteo.com";

void setup() {
  Serial.begin(115200);

  // Turn on screen backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH); 

  WifiTools::connectToWiFi(ssid, password, &tft);
}

void loop() {
  // Updates the live status every 60 seconds
  delay(60000);
}
