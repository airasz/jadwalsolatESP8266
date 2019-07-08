#include <time.h>
#include <Time.h>

#include <TimeLib.h>
#include <TimeAlarms.h>

#include <NTPClient.h>
#include <WiFiUdp.h>

#include "data_jadwal.h"
#include <Adafruit_NeoPixel.h>

#include "ds3231.h"

#define OLED
// #define TFT

#ifdef OLED
// #include "oled.h"

#endif

#ifdef TFT

#endif

  #include  "note.h"
  #define buzz 13
  #include <SPI.h>

  #include <Wire.h>
  // #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
  // #include "SSD1306.h"
  #define OLED_RESET LED_BUILTIN
  Adafruit_SSD1306 display(OLED_RESET);
  #define NEOPIN 14 
  Adafruit_NeoPixel NEO = Adafruit_NeoPixel(1, NEOPIN, NEO_GRBW + NEO_KHZ800);
  // SSD1306 display(0x3c, 4, 5);
  
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifimulti;
#define NTP_OFFSET 7 * 3600        // In seconds
#define NTP_INTERVAL 60 * 1000     // In miliseconds
#define NTP_ADDRESS "pool.ntp.org" //
// #define NTP_ADDRESS  "id.pool.ntp.org"

#define DS3231_I2C_ADDRESS 0x68

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

String clk_server = "id.pool.ntp.org"; // Server to be used for time of day clock
int8_t clk_offset = 7;                 // Offset in hours with respect to UTC
int8_t clk_dst = 0;                    // Number of hours shift during DST
char timetxt[9];
struct tm timeinfo; // Will be filled by NTP server
// hw_timer_t*       	timer = NULL ;

// const int ledPin = 13;
int ledStatus = 0;
bool blinking = false;
bool startblink = false;
bool gpiostate = false;
int text2int, blinkdelay;
int auth_timeout = 0;
bool auth_prosseing;
bool logginsession = 0;
bool open_command = 0;
int authtry = 0;

int criticalTolerance=10;
bool beeping = false;
int beepcount = 0;
int duration;
long angka = 0;
long angka2 = 0;
long angka3 = 0;
long angka1 = 0;
int menit_alert = 0;
bool toning = 0;
int wake = 1;
int t;
long previousMillis = 0;
long previousMillis2 = 0;
long interval = 1000;
long interval2 = 10;
bool critical = 0;
int pinSpeaker = 28;
int led_green = 10;
int led_yellow = 19;

byte zero = 0x00; //workaround for issue #527
int ct1 = 1;
int ta = 9;
int tb = 8;
int tc = 7;
int t1, t2, t3, j, mn, d, tg, bl, th, hk, tg2;
String hari;
String b1, b2, baris1, baris2;
int k = 1;
int tm = 1;
int j_1, j_2, m1, m2, d1, d2;
int ct2, ct3, ht;
boolean lt1 = false;
boolean lt3 = false;
boolean lt2 = false;
boolean jshalat = true;
String kl = "±";

int Bulan, tgl, sh, is, dz, as, mg;
int menitisya1, menitisya2, menitshubuh1, menitshubuh2, menitzhuhur1, menitzhuhur2;
int menitashar1, menitashar2, menitmaghrib1, menitmaghrib2;
int menitisya, menitshubuh, menitzhuhur, menitashar, menitmaghrib;

int jamisya1, jamisya2, jamshubuh1, jamshubuh2, jamzhuhur1, jamzhuhur2;
int jamashar1, jamashar2, jammaghrib1, jammaghrib2;
int jamisya, jamshubuh, jamzhuhur, jamashar, jammaghrib;

String isya, shubuh, zhuhur, ashar, maghrib;

int Bot_mtbs = 1000; //mean time between scan messages
long Bot_lasttime;   //last time messages' scan has been done
bool Start = false;

uint32_t colore;
uint32_t praytimeColor;
unsigned long timeNow = 0;
unsigned long timeLast = 0;
void setup()
{
  // put your setup code here, to run once:

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  //  display.init();
  display.setRotation(0);
  // pinMode(led_green, OUTPUT);
  // pinMode(led_yellow, OUTPUT);
  NEO.begin();
  NEO.show();
  Serial.begin(115200);


  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("ESP jadwal solat!");
  display.display();
  // setDS3231time(0,50,17,3,4,7,12); 
  String dconn;
  bool RTCnotCorrect=0;
  Serial.println("read RTC");
  readDS3231time();
  if(th<18){

    Serial.println("time not correct\nget ntp time");
    RTCnotCorrect=1;
    getNTPtime();
  }
  if(RTCnotCorrect){

    Serial.println("set RTC");
    RTCnotCorrect=0;
  }
      //setDS3231time(s+5,min,h,dow,d,m,y);

  // if(!wifiAvailable)


  
  close_incoming_event();
}

int freqsync = 0;
String formattedTime, formattedDate;

void getNTPtime(){

  
  wifimulti.addAP("al_ghuroba", "air46664");
  wifimulti.addAP("rumah", "GIGIBOLONG");
  wifimulti.addAP("XZ5C", "air46664");
  display.setCursor(0, 10);
  display.display();
  String conn = "connecting to wifi ";
  display.print(conn);
  display.display();
  colore = NEO.Color(120, 100, 0);
  NEO.setPixelColor(0, colore);
  NEO.show();
  int numTry=0;
  int maxTry=50;
  bool wifiAvailable=1;
  while (wifimulti.run() != WL_CONNECTED &&numTry<maxTry)
  {
    numTry++;
    if(numTry<maxTry){
      int x;
      x += 2;
      if (x > 128)
      {
        x = 0;
        display.drawFastHLine(0, 28, 128, BLACK);
        display.display();
      }
      // display.setCursor(x,20);
      display.drawPixel(x, random(25, 28), WHITE);
      // dconn+=".";
      // display.print(dconn);
      // Serial.print(".");
      display.display();
      ESP.wdtFeed();
    }else{
      break;
    }
    
    delay(200);

  }

 

  // beeping=1;
  conn="connected!\nrequest time to\nNTP server";
  
  colore=NEO.Color(0,100,0);
  NEO.setPixelColor(0,colore);
  NEO.show();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(conn);
  display.display();
  timeClient.begin();

  // Show IP for a while
  configTime(clk_offset * 3600,
             clk_dst * 3600,
             clk_server.c_str());
  timeinfo.tm_year = 0;
  // delay(1200);

  timeClient.update();
  gettime();
   if (timeClient.getYear() < 2018)
  {

    colore = NEO.Color(120, 0, 0);
    NEO.setPixelColor(0, colore);
    NEO.show();
    tone(buzz, NOTE_B2 );
    delay(200);
    tone(buzz, NOTE_A2 );
    delay(200);
    noTone(buzz);
    
    ESP.restart();
  }
  else
  {
    beeping = 1;
    duration = 100;
    colore = NEO.Color(0, 100, 0);
    NEO.setPixelColor(0, colore);
    NEO.show();
    
    Serial.print(" NTPtime > ");
    Serial.printf("D > %d ",d);
    Serial.printf("MN > %d ",mn);
    Serial.printf("J > %d ",j);
    Serial.printf("TG > %d ",tg);
    Serial.printf("BL > %d ",bl);
    Serial.printf("TH > %d \n",th);
    Serial.println(th);
    setDS3231time(d,mn,j,timeClient.getDay(),tg,bl,th);  
  }
  Serial.printf("tahun = %d\n", timeClient.getYear());
  delay(50);
  
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (millis() > Bot_lasttime + Bot_mtbs)
  {

    if (j == 23 && mn == 59)
    { // daily update time to NTPserver
      if (d == 1)
      {
        timeClient.update();
      }
    }

    // beeping=1;

    // while(numNewMessages) {
    timeinfo.tm_year = 0;
    gettime();
    //timemanupulation();
    // timeClient.update();
    formattedTime = timeClient.getShortFormattedTime();
    formattedTime += " ";
    formattedTime += timeClient.getFormattedDate();

    // Serial.println(formattedTime);
    //Serial.println(timetxt);
    //display.clear();
    // display.println(time)
    // }
    display_idle();
    Bot_lasttime = millis();
    // Serial.print("get Date = ");
    // Serial.println(timeClient.getDate());
    // Serial.print("get month = ");
    // Serial.println(timeClient.getMonth());
    // Serial.print("date time =");
    // Serial.print(hour());
    // Serial.print("-");
    // Serial.print(minute());
    // Serial.print("-");
    // Serial.print(second());
    // Serial.print("-");
    // Serial.print(day());
    // Serial.print("-");
    // Serial.print(month());
    // Serial.print("-");
    // Serial.println(year());
  }

  flashy();
  beep();
}

byte bcdToDec(byte val)  {
// Convert binary coded decimal to normal decimal numbers
  return ( (val/16*10) + (val%16) );
}

byte decToBcd(byte val){
// Convert normal decimal numbers to binary coded decimal
  return ( (val/10*16) + (val%10) );
}

void goSleep(int minute , int secon){
  int sleepLong;
  if (minute+secon>0){
    sleepLong=((minute*60)*1000000) +( secon*1000000);
    ESP.deepSleep(sleepLong, RF_DISABLED);
  }
}

String clockDigit(int i){
  String s;
  if (i<10){
    s="0"+String(i);
  }else{s=String(i);}
  return s;
}
void display_idle()
{ //display_jam code here
  angka++;
  if( ( angka % 10)==0){
    // close_incoming_event();
    // Serial.println("/10 minutes calling");
  }
  // if (angka == 1 || angka == 10 || angka == 30 || angka == 50 || angka == 70)
  if (angka == 1 || angka == 14  )
  {
    if (wake == 1)
    {
      //digitalWrite(7, HIGH);
      timeinfo.tm_year = 0;

      display.stopscroll();
      // gettime();
      readDS3231time();
      delay(20);
      perhitungan();
      display.clearDisplay();
      // display.setCursor(random(0, 20), 0);
      String timee=formattedTime;
      timee=timee.substring(0, 5);
      String date=formattedTime.substring(6);
      display.setCursor(0,0);
      display.setTextSize(3);
      String clocke=clockDigit(j)+":"+clockDigit(mn);
      display.print(clocke);
      display.setTextSize(1);
      display.setCursor(90,0);
      display.print(tg);
      display.setCursor(90,8);
      display.print(bl);
      display.setCursor(90,16);
      display.print(th);
      
      // display.print()
      display.display();
      incoming_event();
      display.stopscroll();
      Serial.print("angka = ");
      Serial.println(angka);
      Serial.print("clocke = ");
      Serial.println(clocke);
      // int tahun=timeClient.getYear();
      // if (tahun < 2018)
      // {
      //   ESP.restart();
      // }
    }
  }
  // if (angka == 20 || angka == 40 || angka == 60 || angka == 80)
  if (angka == 7 )
  {
    if (wake == 1)
    {

      digitalWrite(7, HIGH);
      gettime();
      readDS3231time();
      perhitungan();
      close_incoming_event();
      // Serial.print("angka = ");
      // Serial.println(angka);
      if (critical == 0)
      {
        jadwal_show();
      }
      display.setTextSize(1);
    }
  }
  if (angka == 20)
  {
    //sleep screen
    if (wake == 1)
    {
      display.stopscroll();
      wake = 0;
      display.clearDisplay();
      display.display();
      //digitalWrite(7, LOW);

      // Serial.println("screen off");
      // Serial.println("go to deep sleep");
      // ESP.deepSleep(10000000, RF_DISABLED);
    }
    //avoid sleep screen if on critical condition
    if (critical == 1)
    {
      wake = 1;
      angka = 0;
    }else{
      
      Serial.println("screen off");
      Serial.println("go to deep sleep");
      //ESP.deepSleep(minute*second*1000000, RF_DISABLED);
      goSleep(3,0);   //goSleep(minutes,seconds);
    }
  }

  if (angka == 140)
  {

    // Serial.print("angka = ");
    // Serial.println(angka);
  }
  if (angka > 200)
  {
    if (wake == 0)
    {
      wake = 1;
      Serial.println("screen on");
      digitalWrite(7, HIGH);
      gettime();
      incoming_event();
      angka = 0;
    }
  }
}
bool schroll = 0;
void jadwal_show()
{ //jadwal_show code here
  if (critical == 0)
  {
    display.clearDisplay();
    display.setTextSize(1);
    // display.scrollDisplayRight("test scrolling text");

    int rnd = random(0, 4); // random(min, max+1);
    display.setCursor(rnd, 0);
    display.print("sbh " + shubuh + " | zh " + zhuhur);
    display.setCursor(rnd, 10);
    display.print("as  " + ashar  + " | mg " + maghrib);
    display.setCursor(rnd, 20);
    display.print("is  " + isya);
    display.display();
    // if (!schroll)
    // {
    //   display.startscrollright(0x00, 0x0F);
    //   schroll = 1;
    // }
    // else
    // {
    //   schroll = 0;
    // }
  }
}

void incoming_event()
{ //incoming_event code here
  // for(int i=0; i<17;i++){
  //   display.setCursor(i,1);
  //   display.print(" ");
  // }
  if (((j < jamshubuh || (j == jamshubuh && mn < menitshubuh))) || ((j > jamisya || (j == jamisya && mn > menitisya))))
  {

    display.setCursor(random(0, 20), 24);
    display.print("subuh > " + shubuh);
    display.display();
    praytimeColor = NEO.Color(200, 0, 0);
  }

  if ((j < jamzhuhur || (j == jamzhuhur && mn < menitzhuhur)) && (j > jamshubuh || j == jamshubuh && mn > menitshubuh))
  {

    display.setCursor(random(0, 20), 24);
    display.print("dzuhur > " + zhuhur);
    display.display();

    praytimeColor = NEO.Color(200, 200, 0);
  }
  if ((j < jamashar || (j == jamashar && mn < menitashar)) && (j > jamzhuhur || j == jamzhuhur && mn > menitzhuhur))
  {

    display.setCursor(random(0, 20), 24);
    //display.setCursor(random(0,50),random (10,20));
    display.print("ashar > " + ashar);
    // Serial.print("ashar = ");
    // Serial.println(ashar);
    display.display();

    praytimeColor = NEO.Color(0, 200, 0);
  }

  if ((j < jammaghrib || (j == jammaghrib && mn < menitmaghrib)) && (j > jamashar || j == jamashar && mn > menitashar))
  {

    display.setCursor(random(0, 20), 24);
    display.print("maghrib > " + maghrib);
    display.display();
    praytimeColor = NEO.Color(80, 0, 80);
  }

  if ((j < jamisya || (j == jamisya && mn < menitisya)) && (j > jammaghrib || j == jammaghrib && mn > menitmaghrib))
  {

    display.setCursor(random(0, 20), 24);
    display.print("isya' > " + isya);
    display.display();
    praytimeColor = NEO.Color(0, 0, 140);
  }

  // Serial.print(hour());
  // Serial.print("subuh : ");
  // Serial.println((jamshubuh1 + jamshubuh2 ));
  // //Serial.println(shubuh);
  // Serial.print("dzuhur : ");
  // //Serial.println(zhuhur);
  // Serial.println((jamzhuhur1 + jamzhuhur2 ));
  // Serial.print("ashar : ");
  // //Serial.println(ashar);
  // Serial.println((jamashar1 + jamashar2 ));
  // Serial.print("maghrib : ");
  // //Serial.println(maghrib);
  // Serial.println((jammaghrib1 + jammaghrib2 ));
  // Serial.print("isya : ");
  // //Serial.println(isya);
  // Serial.println((jamisya1 + jamisya2 ));
  //bt=readVcc();
  // display.setCursor(0,20);
  // int bat=( (420-(readVcc()/10))*(100/60)  );
  // //display.print("baterry = "+ (   String(float(readVcc())/1000.00) )         + " V"     );
  // //display.print("baterry = "+ (   String(float(readVcc())/1000.00, 1) )        + " V"     );
  // //display.print("baterry = "+ (   String(readVcc()/100) )        + " V"     );
  // display.print("baterry = "+ (   String( bat )  + " %"     ));

  // display.display();
}
bool send_info = false;
void close_incoming_event()
{ //close_incoming_event code here

  if (j == jamzhuhur)
  {
    if (mn < menitzhuhur)
    {
      t = menitzhuhur - mn;
      display.clearDisplay();
      display.setCursor(0, 0);
      // display.printf("± %d",t);
      display.printf("%d menit", t);
      display.setCursor(0, 10);
      display.print("menjelang dzuhur");
      display.display();
      if (t < criticalTolerance && t > 0)
      {
        critical = 1;
        if (timeClient.getSeconds() < 10 && t == 2)
        {

          String ready = "5 menit sebelum dhuhur.\n";
          ready += "Silahkan anda bersiap!";
          // Serial.println(ready);
        }
      }
      else
      {
        critical = 0;
      }
    }
    else
    {
      critical = 0;
      digitalWrite(led_green, LOW);
      colore = NEO.Color(0, 200, 0);
      NEO.setPixelColor(1, 0);
    }

  } //else{t=0;}
  if ((jamzhuhur - j == 1) && (mn > menitzhuhur))
  {
    t = menitzhuhur + (60 - mn);
    display.clearDisplay();

    display.setCursor(0, 0);
    // display.printf("± %d", t);
    display.printf("%d menit", t);
    display.setCursor(0, 10);
    display.print("menjelang dzuhur");
    display.display();
    if (t < criticalTolerance && t > 0)
    {
      critical = 1;

      if (timeClient.getSeconds() < 10 && t == 2)
      {

        String ready = "5 menit sebelum dhuhur.\n";
        ready += "Silahkan anda bersiap!";
        // Serial.println(ready);
      }
    }
    else
    {
      critical = 0;
    }
  } //else{t=0;}
  if (j == jamashar)
  {
    if (mn < menitashar)
    {
      t = menitashar - mn;
      display.clearDisplay();
      display.setCursor(0, 0);
      // display.printf("± %d", t);
      display.printf("%d menit", t);
      display.setCursor(0, 10);
      display.print("menjelang azhar");
      display.display();
      if (t < criticalTolerance)
      {
        if (t > 0)
        {
          critical = 1;
        }
        else
        {
          critical = 0;
        }
      }
    }
    else
    {
      critical = 0;
      digitalWrite(led_green, LOW);
    }
  } //else{t=0;}
  if ((jamashar - j == 1) && (mn > menitashar))
  {
    t = menitashar + (60 - mn);
    display.clearDisplay();

    display.setCursor(0, 0);
    // display.printf("± %d, t");
    display.printf("%d menit", t);
    display.setCursor(0, 10);
    display.print("menjelang azhar");
    display.display();
    if (t < criticalTolerance)
    {
      if (t > 0)
      {
        critical = 1;
      }
      else
      {
        critical = 0;
      }
    }
  } //else{t=0;}
  if (j == jammaghrib)
  {
    if (mn < menitmaghrib)
    {
      t = menitmaghrib - mn;

      display.clearDisplay();
      display.setCursor(0, 0);
      // display.printf("± %d", t);
      display.printf("%d menit", t);
      display.setCursor(0, 10);
      display.print("menjelang maghrib");
      display.display();
      if (t < criticalTolerance && t > 0)
      {
        critical = 1;
      }
      else if (t == 0)
      {
        critical = 0;
      }
    }
    else
    {
      critical = 0;
      digitalWrite(led_green, LOW);
    }
  } //else{t=0;}
  if ((jammaghrib - j == 1) && (mn > menitmaghrib))
  {
    t = menitmaghrib + (60 - mn);
    display.clearDisplay();

    display.setCursor(0, 0);
    // display.printf("± %d, t");
    display.printf("%d menit", t);
    display.setCursor(0, 10);
    display.print("menjelang maghrib");
    display.display();
    if (t < criticalTolerance && t > 0)
    {
      critical = 1;
    }
    else
    {
      critical = 0;
    }
  } //else{t=0;}
  if (j == jamisya)
  {
    if (mn < menitisya)
    {

      t = menitisya - mn;
      display.clearDisplay();

      display.setCursor(0, 0);
      // display.printf("± %d", t);
      display.printf("%d menit", t);
      display.setCursor(0, 10);
      display.print("menjelang isya'");
      display.display();
      if (t < criticalTolerance && t > 0)
      {
        critical = 1;
      }
      else
      {
        critical = 0;
      }
    }
    else
    {
      critical = 0;
      digitalWrite(led_green, LOW);
    }
  } //else{t=0;}
  if ((jamisya - j == 1) && (mn > menitisya))
  {
    t = menitisya + (60 - mn);
    display.clearDisplay();

    display.setCursor(0, 0);
    // display.printf("± %d", t);
    display.printf("%d menit", t);
    display.setCursor(0, 10);
    display.print("menjelang isya'");
    display.display();
    if (t < criticalTolerance)
    {
      critical = 1;
    }
    else
    {
      critical = 0;
    }
  } //else{t=0;}
  if (j == jamshubuh)
  {
    if (mn < menitshubuh)
    {

      t = menitshubuh - mn;
      display.clearDisplay();

      display.setCursor(0, 0);
      // display.printf("± %d, t");
      display.printf("%d menit", t);
      display.setCursor(0, 10);
      display.print("menjelang shubuh");
      display.display();
      if (t < criticalTolerance && t > 0)
      {
        critical = 1;
      }
      else
      {
        critical = 0;
      }
    }
    else
    {
      critical = 0;
      digitalWrite(led_green, LOW);
    }
  } //else{t=0;}
  if ((jamshubuh - j == 1) && (mn > menitshubuh))
  {
    t = menitshubuh + (60 - mn);
    display.clearDisplay();

    display.setCursor(0, 0);
    // display.printf("± %d, t");
    display.printf("%d menit", t);
    display.setCursor(0, 10);
    display.print("menjelang shubuh'");
    display.display();
    if (t < criticalTolerance)
    {
      critical = 1;
    }
    else
    {
      critical = 0;
    }
  } //else{t=0;}

  // Serial.print("t = ");
  // Serial.println(t);
  // Serial.print("critical = ");
  // Serial.println(critical);
}

bool flr = 1;
bool fly = 1;
int bip = 0;
void flashy()
{ //flashy code here
  unsigned long currentMillis = millis();
  if (currentMillis > previousMillis2 + interval2)
  {
    if (critical)
    {
      if (t < criticalTolerance && t > 5)
      {
        interval2 = 500;
        if (fly == 1)
        {
          digitalWrite(led_yellow, HIGH);
          colore = NEO.Color(0 + (t * 10) - 10, 150 - (t * 10), 0); // red to green
          // colore = NEO.Color(150 - (t * 10) + 10, 0, 0 + (t * 10) - 10);  // red to blue
          NEO.setPixelColor(0, colore);
          NEO.show();
          //Serial.println("on yelow");
          fly = 0;
        }
        else
        {
          digitalWrite(led_yellow, LOW);
          fly = 1;
          NEO.setPixelColor(0, 0);
          NEO.show();
          //  Serial.println("off yelow");
        }
      }

      if (t > 0 && t < 6)
      {
        bip += 1;
        if (bip > 40)
        {
          beeping = 1;
          duration = 76;

          // tone(BUZZER_PIN, NOTE_B4, 20, BUZZER_CHANNEL);
          // noTone(BUZZER_PIN, BUZZER_CHANNEL);
          // tone(BUZZER_PIN, NOTE_C4, 20, BUZZER_CHANNEL);
          // noTone(BUZZER_PIN, BUZZER_CHANNEL);
          bip = 0;
        }
        interval2 = (100 * t);
        if (flr == 1)
        {
          digitalWrite(led_green, HIGH);
          digitalWrite(led_yellow, LOW);
          colore = NEO.Color(0 + (t * 10) - 10, 150 - (t * 10), 0); // red to green
          // colore = NEO.Color(150 - (t * 10) + 10, 0, 0 + (t * 10) - 10); // red to blue
          NEO.setPixelColor(0, colore);
          NEO.show();
          //    Serial.println("on red");colore=NEO.Color(200,200,0);
          flr = 0;
        }
        else
        {
          digitalWrite(led_green, LOW);
          flr = 1; //Serial.println("off red");
          //digitalWrite(led_yellow, LOW);
          NEO.setPixelColor(0, 0);
          NEO.show();
        }
        // int red = 150 - (t * 10) + 10;
        // int blu = 0 + (t * 10) - 10;
        // Serial.printf("red = %d ", red);
        // Serial.printf("blu = %d ", blu);
      }

      if (t == 0)
      {
        digitalWrite(led_green, HIGH);
      }
      previousMillis2 = millis();
    }    //end if critical
    else // if critical false
    {
      // 5 secondly light flash
      if (flr)
      {
        interval2 = 5000;
        flr = 0;
        colore = NEO.Color(0, 0, 0);
        NEO.setPixelColor(0, colore);
        NEO.show();
        previousMillis2 = millis();
      }
      else
      {
        interval2 = 50;
        flr = 1;

        // colore=NEO.Color(0,0,200);
        NEO.setPixelColor(0, praytimeColor);
        NEO.show();
        previousMillis2 = millis();
      }
      digitalWrite(led_green, flr);
    }
  }
}
void beep()
{
  if (beeping == true)
  {

    unsigned long currentmillis = millis();
    if (currentmillis > previousMillis + (duration / 2))
    {
      beepcount += 1;
      if (beepcount == 1)
      {
        tone(buzz, NOTE_CS6);
      }
      else if (beepcount == 3)
      {
        tone(buzz, NOTE_D8);
      }
      else if (beepcount > 5)
      {
        noTone(buzz);
        beepcount = 0;
        duration = 100;
        beeping = 0;
      }
      // if(beepcount>4){
      // }
      previousMillis = millis();
    }
  }
}

void printDigits(int digits)
{
  // utility function for digital clock display: prints preceding colon and leading 0
  // display.print(':');
  if (digits < 10)
    display.print('0');
  display.print(digits);
}

//**************************************************************************************************
//                                         G E T T I M E                                           *
//**************************************************************************************************
// Retrieve the local time from NTP server and convert to string.                                  *
// Will be called every second.                                                                    *
//**************************************************************************************************
void gettime()
{
  static int16_t delaycount = 0; // To reduce number of NTP requests
  static int16_t retrycount = 100;

  j = timeClient.getHours();
  mn = timeClient.getMinutes();
  d = timeClient.getSeconds();
  th = timeClient.getYear()-2000;
  bl = timeClient.getMonth();
  tg = timeClient.getDate();
}
void readDS3231time()
{
    Wire.beginTransmission(DS3231_I2C_ADDRESS);
    Wire.write(0); // set DS3231 register pointer to 00h
    Wire.endTransmission();
    Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
    // request seven bytes of data from DS3231 starting from register 00h
    d = bcdToDec(Wire.read() & 0x7f);
    mn = bcdToDec(Wire.read());
    j = bcdToDec(Wire.read() & 0x3f);
    hk = bcdToDec(Wire.read()); //0-6 -> sunday - Saturdaymn = bcdToDec(Wire.read());
    tg = bcdToDec(Wire.read());
    bl = bcdToDec(Wire.read());
    th = bcdToDec(Wire.read());
    Serial.print(" RTC > ");
    Serial.printf("D > %d ",d);
    Serial.printf("MN > %d ",mn);
    Serial.printf("J > %d ",j);
    Serial.printf("TG > %d ",tg);
    Serial.printf("BL > %d ",bl);
    Serial.printf("TH > %d \n",th);
    Serial.println(th);
}

void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte 
dayOfMonth, byte month, byte year) 
{ 

		// sets time and date data to DS3231 
		Wire.beginTransmission(DS3231_I2C_ADDRESS); 
		Wire.write(0); // set next input to start at the seconds register 
		Wire.write(decToBcd(second)); // set seconds 
		Wire.write(decToBcd(minute)); // set minutes 
		Wire.write(decToBcd(hour)); // set hours 
		Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday) 
		Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31) 
		Wire.write(decToBcd(month)); // set month 
		Wire.write(decToBcd(year)); // set year (0 to 99) 
		Wire.endTransmission(); 
} 
//function for synctoglobe
void synctoglobe()
{
  setTime(timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds(), timeClient.getDate(), timeClient.getMonth(), timeClient.getYear());
}