#include <SPI.h>
#include <Adafruit_GFX.h>
#include <SH1106.h>
#include <dht11.h>

#define DHT11_PIN 5
dht11 DHT11;

int hour;
int minute;
int second;

// If using software SPI (the default case):
#define OLED_MOSI   10
#define OLED_CLK   6
#define OLED_DC    8
#define OLED_CS    7
#define OLED_RESET  9
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

void setup(){
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();

  Serial.begin(9600);
  
  display.clearDisplay();
  display.setTextSize(1.35);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("PLEASE TURN ON TR!");
  display.println("POWERED BY MIKEJU");
  display.display();//you have to print this after any print/draw...commend
  delay(2000);
  display.clearDisplay();

}

void loop() {

  DHT11.read(DHT11_PIN);
  display.setCursor(0,0);
  display.setTextSize(2.0);
  display.setTextColor(WHITE);
  display.print(DHT11.temperature);
  display.print("oC");
  display.print(" ");
  display.print(DHT11.humidity);
  display.print("%");
    /*
    second=Clock.getSecond();
    minute=Clock.getMinute();
    hour=Clock.getHour(h12, PM);
    date=Clock.getDate();
    month=Clock.getMonth(Century);
    year=Clock.getYear();
    */
    display.display();//you have to print this after any print/draw...commend
    delay(1000);
    display.clearDisplay();
}

