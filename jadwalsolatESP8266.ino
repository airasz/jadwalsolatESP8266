#include <time.h>
#include <Time.h>

#include <TimeLib.h> 
#include <TimeAlarms.h>

#include <NTPClient.h>
#include <WiFiUdp.h>

#include "data_jadwal.h"

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
  
  // SSD1306 display(0x3c, 4, 5);
  
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
  
ESP8266WiFiMulti wifimulti;
#define NTP_OFFSET  7*3600 // In seconds 
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "pool.ntp.org"//
// #define NTP_ADDRESS  "id.pool.ntp.org"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);



String         		clk_server = "id.pool.ntp.org" ;                         // Server to be used for time of day clock
int8_t         		clk_offset = 7 ;                         // Offset in hours with respect to UTC
int8_t         		clk_dst = 0 ;                            // Number of hours shift during DST
char              	timetxt[9] ;
struct tm         	timeinfo ;                             // Will be filled by NTP server
// hw_timer_t*       	timer = NULL ;

// const int ledPin = 13;
int ledStatus = 0;
bool blinking=false;
bool startblink=false;
bool gpiostate=false;
int text2int,blinkdelay;
int auth_timeout=0;
bool auth_prosseing;
bool logginsession=0;
bool open_command=0;
int authtry=0;


bool beeping=false;
int beepcount=0;
long angka=0;
long angka2=0;
long angka3=0;
long angka1=0;
int menit_alert=0; 
bool toning=0;
int wake=1;
int t;
long previousMillis=0;
long previousMillis2=0;
long interval=1000;
long interval2=10;
bool critical=0;
int pinSpeaker=28;
int pred=9;
int pyel=10;

byte zero = 0x00; //workaround for issue #527
int ct1=1;
int ta=9 ; int tb=8; int tc=7;
int t1,t2,t3,j,mn,d,tg,bl,th,hk,tg2;
String hari;
String b1,b2,baris1,baris2;
int k=1; int tm=1;
int j_1,j_2,m1,m2,d1,d2;
int ct2,ct3,ht;
boolean lt1= false;
boolean lt3= false;
boolean lt2= false;
boolean jshalat= true;


int Bulan,tgl,sh,is,dz,as,mg;
int menitisya1,menitisya2,menitshubuh1,menitshubuh2,menitzhuhur1,menitzhuhur2;
int menitashar1,menitashar2,menitmaghrib1,menitmaghrib2;
int menitisya,menitshubuh,menitzhuhur,menitashar,menitmaghrib;

int jamisya1,jamisya2,jamshubuh1,jamshubuh2,jamzhuhur1,jamzhuhur2;
int jamashar1,jamashar2,jammaghrib1,jammaghrib2;
int jamisya,jamshubuh,jamzhuhur,jamashar,jammaghrib;

String isya,shubuh,zhuhur, ashar, maghrib;


int Bot_mtbs = 1000; //mean time between scan messages
long Bot_lasttime;   //last time messages' scan has been done
bool Start = false;



unsigned long timeNow = 0;
unsigned long timeLast = 0;
void setup() {
  // put your setup code here, to run once:
  
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  //  display.init();

	pinMode(pred, OUTPUT);
	pinMode(pyel, OUTPUT);
  Serial.begin(115200);
	wifimulti.addAP("al_ghuroba", "air46664");
	wifimulti.addAP("rumah", "GIGIBOLONG");
  wifimulti.addAP("XZ5C", "air46664");




  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	display.clearDisplay();
	display.println("ESP jadwal solat!");
  display.display();
  String dconn;

  display.setCursor(0,10);
  display.display();
	String conn="connecting to wifi ";
	display.print(conn);
  display.display();
  while(wifimulti.run()!=WL_CONNECTED){
    int x;
    x+=2;
    if (x>128){x=0;display.drawFastHLine(0,28,128,BLACK); display.display();}
  // display.setCursor(x,20);
    display.drawPixel(x,random(25, 28) ,WHITE);
    // dconn+=".";
    // display.print(dconn);
    Serial.print(".");
    display.display();
    delay(200);
  }
  conn="connected!\nrequest time to\nNTP server";
  display.clearDisplay();
	display.setCursor(0,0);
	display.print(conn);
  display.display();
	timeClient.begin();
  
                  // Show IP for a while
  configTime ( clk_offset * 3600,
               clk_dst * 3600,
               clk_server.c_str() ) ;     
	timeinfo.tm_year=0;
  // delay(1200);
	gettime();
  
	timeClient.update();
  // delay(1000);
  if(timeClient.getYear()<2018){
    
    tone(buzz, NOTE_B2 );
    delay(200);
    // noTone(buzz);
    tone(buzz, NOTE_A2 );
    delay(200);
    noTone(buzz);
  }else{beeping=1;
  }

  Serial.printf("jam = %d", timeClient.getYear());
    // beeping=1;
	WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}


int freqsync=0;
String formattedTime,formattedDate;

void loop() {
  // put your main code here, to run repeatedly:
   if (millis() > Bot_lasttime + Bot_mtbs)  {
    
    if(j==23&&mn==59){				// daily update time to NTPserver
      if(d==1){
          timeClient.update();
      }
    }

        // beeping=1;

    // while(numNewMessages) {
    timeinfo.tm_year=0;
    gettime();
    //timemanupulation();
    // timeClient.update();
 	  formattedTime= timeClient.getShortFormattedTime();
 	  formattedTime+=" ";
 	  formattedTime+=timeClient.getFormattedDate();

      // Serial.println(formattedTime);
      //Serial.println(timetxt);
      //display.clear();
      // display.println(time)
    // }
    display_idle();
    Bot_lasttime = millis();
    /* Serial.print("get Date = ");
    Serial.println(timeClient.getDate()); 
    Serial.print("get month = ");
    Serial.println(timeClient.getMonth()); 
    Serial.print("date time =");
    Serial.print(hour());
    Serial.print("-");
    Serial.print(minute());
    Serial.print("-");
    Serial.print(second());
    Serial.print("-");
    Serial.print(day());
    Serial.print("-");
    Serial.print(month());
    Serial.print("-");
    Serial.println(year()); */
  }

	flashy();
	beep();
}

void display_idle(){                    //display_jam code here
    angka++;
    if (angka==1||angka==10||angka==30||angka==50||angka==70){
    	if(wake==1){
        //digitalWrite(7, HIGH);
        timeinfo.tm_year=0;

    		display.stopscroll();
        gettime();
        delay(20);
        perhitungan();
        display.clearDisplay();
	   	  display.setCursor(random(0,20),0);

        display.print(formattedTime);
        display.display();
        incoming_event();
		    display.stopscroll();
        Serial.print("angka = ");
        Serial.println(angka);
    	}
    }
    if (angka==20||angka==40||angka==60||angka==80){
      if(wake==1){
        
        digitalWrite(7, HIGH);
        gettime();
        perhitungan();
        close_incoming_event();
        Serial.print("angka = ");
        Serial.println(angka);
        if(critical==0){
            jadwal_show();
        }
		    display.setTextSize(1);
        
      }
    }
    if (angka==100){
      //sleep screen
    	if(wake==1){
    		display.stopscroll();
    		wake=0;
    		display.clearDisplay();
        display.display();
    	 //digitalWrite(7, LOW);

        Serial.println("screen off");

    	}
      //avoid sleep screen if on critical condition
      if(critical==1){
          wake=1;
          angka=0;
                    
      }
    }

    if(angka ==140){

        Serial.print("angka = ");
        Serial.println(angka);
        
    }
    if (angka>200){
    	if(wake==0){
    		wake=1;
        Serial.println("screen on");
        digitalWrite(7, HIGH);
    		gettime();
        incoming_event();
    		angka=0;
    	}
    }

}
bool schroll=0;
void jadwal_show(){                    //jadwal_show code here
  if(critical==0){
        display.clearDisplay();
        display.setTextSize(1);
        // display.scrollDisplayRight("test scrolling text");

        int rnd= random(0, 4); // random(min, max+1); 
        display.setCursor(rnd,0);
        display.print("sbh " + shubuh +" | zh " + zhuhur);
        display.setCursor(rnd,10);
        display.print("as  " + ashar  +" | mg " + maghrib );
        display.setCursor(rnd,20);
        display.print("is  " + isya );
        display.display();
      if (!schroll){
    		display.startscrollright(0x00, 0x0F); schroll=1;
      }else{ schroll=0;}
      
  }
    
}

void incoming_event(){                    //incoming_event code here
  // for(int i=0; i<17;i++){
  //   display.setCursor(i,1);
  //   display.print(" ");
  // }
  if(((timeClient.getHours()<jamshubuh||(timeClient.getHours()==jamshubuh&&timeClient.getMinutes()<menitshubuh)))  ||    ((timeClient.getHours()> jamisya||(timeClient.getHours()==jamisya&&timeClient.getMinutes()>menitisya )))) {

        
         display.setCursor(random(0,20),10);
        display.setCursor(random(0,50),random (10,20));
        display.print("subuh > " + shubuh);
        display.display();

		  
  }


  if((timeClient.getHours()<jamzhuhur||(timeClient.getHours()==jamzhuhur&&timeClient.getMinutes()<menitzhuhur))  &&(timeClient.getHours()>jamshubuh||timeClient.getHours()==jamshubuh&&timeClient.getMinutes()>menitshubuh)){

        display.setCursor(random(0,20),10);
        display.print("dzuhur > " + zhuhur);
        display.display();
      
       
  }
  if((timeClient.getHours()<jamashar||(timeClient.getHours()==jamashar&&timeClient.getMinutes()<menitashar))  &&(timeClient.getHours()>jamzhuhur||timeClient.getHours()==jamzhuhur&&timeClient.getMinutes()>menitzhuhur)){

        display.setCursor(random(0,20),10);
        //display.setCursor(random(0,50),random (10,20));
        display.print("ashar > " + ashar);
        // Serial.print("ashar = ");
        // Serial.println(ashar);
        display.display();
  }

  if((timeClient.getHours()<jammaghrib||(timeClient.getHours()==jammaghrib&&timeClient.getMinutes()<menitmaghrib))  &&(timeClient.getHours()>jamashar||timeClient.getHours()==jamashar&&timeClient.getMinutes()>menitashar)){

        display.setCursor(random(0,20),10);
        display.print("maghrib > " + maghrib);
        display.display();
  }

  if((timeClient.getHours()<jamisya||(timeClient.getHours()==jamisya&&timeClient.getMinutes()<menitisya))  &&(timeClient.getHours()>jammaghrib||timeClient.getHours()==jammaghrib&&timeClient.getMinutes()>menitmaghrib)){

        display.setCursor(random(0,20),10);
        display.print("isya' > " + isya);
        display.display();
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
bool send_info=false;
void close_incoming_event(){                    //close_incoming_event code here
        
        if(timeClient.getHours()==jamzhuhur){
            if(timeClient.getMinutes()<menitzhuhur){
              t=menitzhuhur-timeClient.getMinutes();
              display.clearDisplay();
              display.setCursor(0,0);
              display.print(t);
              display.print(" menit");
              display.setCursor(0,10);
              display.print("menjelang dzuhur");
              display.display();
              if(t<15&&t>0){
              	critical=1;
              	if(timeClient.getSeconds()<10&&t==2){

                  String ready="5 menit sebelum dhuhur.\n";
                  ready +="Silahkan anda bersiap!";
              // Serial.println(ready);
				  
              	}
              }else{critical=0;}    
            }else{critical=0;digitalWrite(pred, LOW);}
            
        }//else{t=0;}
        if ((jamzhuhur-timeClient.getHours()==1)&&(timeClient.getMinutes()>menitzhuhur)){
          t=menitzhuhur+(60-timeClient.getMinutes());
          display.clearDisplay();
          
          display.setCursor(0,0);
          display.print(t);
          display.print(" menit");
          display.setCursor(0,10);
          display.print("menjelang dzuhur");
          display.display();
          if(t<15&&t>0){
          	critical=1;

              	if(timeClient.getSeconds()<10&&t==2){

                  String ready="5 menit sebelum dhuhur.\n";
                  ready +="Silahkan anda bersiap!";
                  // Serial.println(ready);
				 
              	}

          	}else{critical=0;}
        }//else{t=0;}
        if(timeClient.getHours()==jamashar){
          if(timeClient.getMinutes()<menitashar){
            t=menitashar-timeClient.getMinutes();
            display.clearDisplay();
            display.setCursor(0,0);
            display.print(t);
            display.print(" menit");
            display.setCursor(0,10);
            display.print("menjelang azhar");
            display.display();
            if(t<15){if(t>0){critical=1;}else{critical=0;}}
          }else{critical=0;digitalWrite(pred, LOW);}
        }//else{t=0;}
        if ((jamashar-timeClient.getHours()==1)&&(timeClient.getMinutes()>menitashar)){
          t=menitashar+(60-timeClient.getMinutes());
          display.clearDisplay();
          
          display.setCursor(0,0);
          display.print(t);
          display.print(" menit");
          display.setCursor(0,10);
          display.print("menjelang azhar");
          display.display();
          if(t<15)
          {
            if(t>0){
            critical=1;
            }
            else
            {critical=0;}
          }
        }//else{t=0;}
        if(timeClient.getHours()==jammaghrib){
          if(timeClient.getMinutes()<menitmaghrib){
            t=menitmaghrib-timeClient.getMinutes();
            
            display.clearDisplay();
            display.setCursor(0,0);
            display.print(t);
            display.print(" menit");
            display.setCursor(0,10);
            display.print("menjelang maghrib");
            display.display();
            if(t<15&&t>0){critical=1;}
            else if (t==0){critical=0;}
              
          }else{critical=0;digitalWrite(pred, LOW);}
        }//else{t=0;}
        if ((jammaghrib-timeClient.getHours()==1)&&(timeClient.getMinutes()>menitmaghrib)){
          t=menitmaghrib+(60-timeClient.getMinutes());
          display.clearDisplay();
          
          display.setCursor(0,0);
          display.print(t);
          display.print(" menit");
          display.setCursor(0,10);
          display.print("menjelang maghrib");
          display.display();
          if(t<15&&t>0){critical=1;}else{critical=0;}
        }//else{t=0;}
        if(timeClient.getHours()==jamisya){
          if(timeClient.getMinutes()<menitisya){
            
            t=menitisya-timeClient.getMinutes();
            display.clearDisplay();
            
            display.setCursor(0,0);
            display.print(t);
            display.print(" menit");
            display.setCursor(0,10);
            display.print("menjelang isya'");
            display.display();
            if(t<15&&t>0){critical=1;}else{critical=0;}   
          }else{critical=0;digitalWrite(pred, LOW);}
        }//else{t=0;}
        if ((jamisya-timeClient.getHours()==1)&&(timeClient.getMinutes()>menitisya)){
          t=menitisya+(60-timeClient.getMinutes());
          display.clearDisplay();
          
          display.setCursor(0,0);
          display.print(t);
          display.print(" menit");
          display.setCursor(0,10);
          display.print("menjelang isya'");
          display.display();
          if(t<15){critical=1;}else{critical=0;}
        }//else{t=0;}
        if(timeClient.getHours()==jamshubuh){
          if(timeClient.getMinutes()<menitshubuh){
            
            t=menitshubuh-timeClient.getMinutes();
            display.clearDisplay();
            
            display.setCursor(0,0);
            display.print(t);
            display.print(" menit");
            display.setCursor(0,10);
            display.print("menjelang shubuh");
            display.display();
            if(t<15&&t>0){critical=1;}else{critical=0;}   
          }else{critical=0;digitalWrite(pred, LOW);}
        }//else{t=0;}
        if ((jamshubuh-timeClient.getHours()==1)&&(timeClient.getMinutes()>menitshubuh)){
          t=menitshubuh+(60-timeClient.getMinutes());
          display.clearDisplay();
          
          display.setCursor(0,0);
          display.print(t);
          display.print(" menit");
          display.setCursor(0,10);
          display.print("menjelang shubuh'");
          display.display();
          if(t<15){critical=1;}else{critical=0;}
        }//else{t=0;}


      Serial.print("t = ");
      Serial.println(t);
      Serial.print("critical = ");
      Serial.println(critical);
  }


bool flr=1;
bool fly=1;
int bip=0;
void flashy(){                    //flashy code here
  unsigned long currentMillis=millis();
  if (currentMillis>previousMillis2+interval2){
    if(critical){
      if(t<15&&t>5){
        interval2=500;
        if(fly==1){
          digitalWrite(pyel, HIGH);
        //Serial.println("on yelow");
            fly=0;
        }else{digitalWrite(pyel, LOW); fly=1;
      //  Serial.println("off yelow");
        }
      }
      if(t>0&&t<6){
        bip+=1;
        if(bip>40){
          beeping=1;
          
          // tone(BUZZER_PIN, NOTE_B4, 20, BUZZER_CHANNEL);
          // noTone(BUZZER_PIN, BUZZER_CHANNEL);
          // tone(BUZZER_PIN, NOTE_C4, 20, BUZZER_CHANNEL);
          // noTone(BUZZER_PIN, BUZZER_CHANNEL);
          bip=0;
        }
        interval2=(80*t);
        if(flr==1){
              digitalWrite(pred, HIGH);
              digitalWrite(pyel, LOW);
          //    Serial.println("on red");
              flr=0;
          }else{digitalWrite(pred, LOW); flr=1;//Serial.println("off red");
          //digitalWrite(pyel, LOW);
        }
      }
      if(t==0){
          digitalWrite(pred, HIGH);
          
      }
      previousMillis2=millis();
    } //end if critical
    else
    {
     if(flr){interval2=5000;flr=0; previousMillis2=millis();}else{interval2=50;flr=1; previousMillis2=millis();}
     digitalWrite(pred, flr);

    }
    
    
  }
}  
void beep(int duration){
	if(beeping==true){
	 	
		long currentmillis=millis();
		if(currentmillis>previousMillis +(duration/2)){
		  beepcount+=1;
      if(beepcount==1){    
        tone(buzz, NOTE_C8 );
			}else if(beepcount==3){
        tone(buzz, NOTE_D8 );
      }else if(beepcount>5){
        noTone(buzz);
        beepcount=0; 
        beeping=0;
      }
      // if(beepcount>4){
      // }
      previousMillis=millis();
		}
	}
}


void printDigits(int digits){
    // utility function for digital clock display: prints preceding colon and leading 0
   // display.print(':');
    if(digits < 10)
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
  static int16_t delaycount = 0 ;                           // To reduce number of NTP requests
  static int16_t retrycount = 100 ;

      j=timeClient.getHours();
      mn=timeClient.getMinutes();
      d=timeClient.getSeconds();
      th=timeClient.getYear();
      bl=timeClient.getMonth();
      tg=timeClient.getDate();
   
   
  
}

//function for synctoglobe
void synctoglobe(){                    
    setTime(timeClient.getHours(),timeClient.getMinutes(),timeClient.getSeconds(),timeClient.getDate(),timeClient.getMonth(),timeClient.getYear() );
}   

