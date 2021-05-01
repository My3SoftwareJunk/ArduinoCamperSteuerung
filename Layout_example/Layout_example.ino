#include <TouchScreen.h>
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

#define YP A1
#define XM A2
#define YM 7
#define XP 6
#define TS_MINX 940
#define TS_MINY 160
#define TS_MAXX 160
#define TS_MAXY 970

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


//boolean graph1 = true;
//boolean graph2 = true;
//boolean graph3 = true;
//boolean graph4 = true;
//boolean graph5 = true;
//boolean graph6 = true;
//boolean graph7 = true;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

#define BOXSIZE 40
#define PENRADIUS 3

#define MINPRESSURE 10
#define MAXPRESSURE 1000

int offset = 0;
bool change = 0;
bool touch = 0;

void setup() {

 pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  Serial.begin(9600);

  pinMode(TFT_CS, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(TFT_CS, HIGH);
  digitalWrite(7, HIGH);
  
  tft.begin();
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.fillScreen(BLACK);
  
  tft.fillRect(0,0,120,120, GREEN);
  tft.fillRect(120,0,120,120, RED);
  
  tft.setCursor(8,45);
  tft.println("LED ON");
  
  tft.setCursor(128,45);
  tft.println("LED OFF");
  
  
}

void loop() {
  
  if (change == 0 && touch == 0) {
    digitalWrite(A5, LOW);
    tft.fillCircle(120, 160, 50, RED);
    tft.setCursor(95, 150);
    tft.println("LED");
    change = 1;
    delay(200);
  }

  if (change == 0 && touch == 1) {
    digitalWrite(A5, HIGH);
    tft.fillCircle(120, 160, 50, GREEN);
    tft.setCursor(95, 150);
    tft.println("LED");
    change = 1;
    delay(200);
  }

  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
    Serial.print("("); Serial.print(p.x);
    Serial.print(", "); Serial.print(p.y);
    Serial.println(")");
    if (p.x > 70 && p.x < 170) {
      if (p.y > 110 && p.y < 210) {
        change = 0;
        touch = !touch;
      }
    }
  }
        
}
