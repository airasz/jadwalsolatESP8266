
  #include <SPI.h>

  #include <Wire.h>
  // #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
  #define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
void displayprint(int line, string text);
	
void displayinit(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)

}
void displayprint(int line, string text){


}