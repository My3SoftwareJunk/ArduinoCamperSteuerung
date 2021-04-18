#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>


#define TFT_DC 9
#define TFT_CS 10
#define TFT_RST 8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {

  pinMode(TFT_CS, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(TFT_CS, HIGH);
  digitalWrite(7, HIGH);

  tft.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
