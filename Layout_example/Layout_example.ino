#include <Adafruit_HX8357.h>
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

#define LTBLUE    0xB6DF
#define LTTEAL    0xBF5F
#define LTGREEN   0xBFF7
#define LTCYAN    0xC7FF
#define LTRED     0xFD34
#define LTMAGENTA 0xFD5F
#define LTYELLOW  0xFFF8
#define LTORANGE  0xFE73
#define LTPINK    0xFDDF
#define LTPURPLE  0xCCFF
#define LTGREY    0xE71C

#define BLUE      0x001F
#define TEAL      0x0438
#define GREEN     0x07E0
#define CYAN      0x07FF
#define RED       0xF800
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define ORANGE    0xFC00
#define PINK      0xF81F
#define PURPLE    0x8010
#define GREY      0xC618
#define WHITE     0xFFFF
#define BLACK     0x0000

#define DKBLUE    0x000D
#define DKTEAL    0x020C
#define DKGREEN   0x03E0
#define DKCYAN    0x03EF
#define DKRED     0x6000
#define DKMAGENTA 0x8008
#define DKYELLOW  0x8400
#define DKORANGE  0x8200
#define DKPINK    0x9009
#define DKPURPLE  0x4010
#define DKGREY    0x4A49

boolean graph1 = true;
boolean graph2 = true;
boolean graph3 = true;
boolean graph4 = true;
boolean graph5 = true;
boolean graph6 = true;
boolean graph7 = true;


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

int offset = 0;

void setup() {

  pinMode(TFT_CS, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(TFT_CS, HIGH);
  digitalWrite(7, HIGH);

  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.setRotation(1);
  
}

void loop() {

  int volt = analogRead(A0);
  double voltage = map(volt, 0, 1023, 0, 2500) + offset;

  voltage /= 100;
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
        tft.print(voltage);

        delay(1000);
}
