
#include <Adafruit_GFX.h>    // Core graphics library
  #include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
  #include <SPI.h>
    
  #define TFT_CS     5
  #define TFT_RST    16  // you can also connect this to the Arduino reset
                        // in which case, set this #define pin to -1!
  #define TFT_DC     2
  #define TFT_SCLK 0   // set these to be whatever pins you like!
  #define TFT_MOSI 4   // set these to be whatever pins you like!
  Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#define pinBL 12
  	
void displayinit(){
    display.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  display.fillScreen(ST77XX_BLACK);
 pinMode(pinBL, OUTPUT);
  digitalWrite(pinBL, HIGH);
}
void displayprint(int line, string text){
    

}