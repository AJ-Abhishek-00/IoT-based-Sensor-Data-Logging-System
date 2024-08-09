#include <LiquidCrystal.h>
#include <stdio.h>

#include <Wire.h>
#include "dht.h"

#define dht_apin A2
dht DHT;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
// defines pins numbers
//New GPS GY-GPS6MV2


int buzzer  = 7;
int fire = 2;
int gas = 3;

int beatAvg=0,beatAvg1=0;
int hbv=0,spo2v=0;

int sys=0,dia=0;
int lcup=0;
int cntlmk=0;
int cntlmk1=0;






int tempc=0,humc=0;
unsigned char rcv,count,gchr;


int sti=0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void okcheck()
{
  unsigned char rcr;
  do{
      rcr = Serial.read();
    }while(rcr != 'K');
}
 void beep()
 {
  digitalWrite(buzzer,LOW);delay(2000);digitalWrite(buzzer,HIGH);
 }

void setup() 
{
 Serial.begin(115200);//serialEvent();

  pinMode(buzzer, OUTPUT);
  pinMode(fire, INPUT);
  pinMode(gas, INPUT);
  digitalWrite(buzzer, HIGH);


  lcd.begin(16, 2);lcd.cursor();  
  lcd.print("Sensor data logger");
  lcd.setCursor(0,1);
  lcd.print("   using IOT");
  delay(2000);
  lcd.clear();
 lcd.print("Wifi init");

  Serial.write("AT\r\n");         delay(500); okcheck();
  Serial.write("ATE0\r\n");         okcheck();
  Serial.write("AT+CWMODE=3\r\n"); delay(500);
  Serial.write("AT+CIPMUX=1\r\n"); delay(500);         okcheck();
  Serial.write("AT+CIPSERVER=1,23\r\n");      okcheck();


  lcd.clear();
  lcd.print("Waiting For");
  lcd.setCursor(0, 1);
  lcd.print("Connection");
  do {
    rcv = Serial.read();
  } while (rcv != 'C');


  lcd.clear();
  lcd.print("Connected");
  delay(2000);
  lcd.clear();

 
  lcd.clear();
  lcd.print("Connected");
  delay(1000);


  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T:");  //2-3-4,0
    lcd.setCursor(5,0);
    lcd.print("H:");  //7-8-9,0
    lcd.setCursor(12,0);
    
    lcd.setCursor(0,1);
    lcd.print("F:");  //2,1
    lcd.setCursor(5,1);
    lcd.print("G:");  //7,1
}

void loop() 
{
  DHT.read11(dht_apin);

      tempc = DHT.temperature;
      humc  = DHT.humidity;

    lcd.setCursor(2,0);convertl(tempc);
    lcd.setCursor(7,0);convertl(humc);
    if(tempc > 40)
      {beep();
              Serial.write("AT+CIPSEND=0,15\r\n");delay(2000);
              Serial.write("High Temp:");
              converts(tempc);//3
              Serial.write("\r\n");               delay(3000);
      }
    if(humc > 90)
      {beep();
              Serial.write("AT+CIPSEND=0,14\r\n");delay(2000);
              Serial.write("High Hum:");
              converts(humc);//3
              Serial.write("\r\n");               delay(3000);
      }


if(digitalRead(fire)==LOW)
{
lcd.setCursor(2,1);
lcd.print(" ON");
beep();
              Serial.write("AT+CIPSEND=0,13\r\n");delay(2000);
              Serial.write("Fire Detected");
              Serial.write("\r\n");               delay(3000);
}
if(digitalRead(fire)==HIGH)
{
lcd.setCursor(2,1);
lcd.print("OFF");
}




 if(digitalRead(gas)==LOW)
{
lcd.setCursor(7,1);
lcd.print(" ON");
beep();
              Serial.write("AT+CIPSEND=0,12\r\n");delay(2000);
              Serial.write("Gas Detected");
              Serial.write("\r\n");               delay(3000);
}
if(digitalRead(gas)==HIGH)
{
lcd.setCursor(7,1);
lcd.print("OFF");
}
}


void serialEvent() 
{
   while(Serial.available()) 
        {         
         char inChar = (char)Serial.read();
           if(inChar == '*')
             {
             // gchr = Serial.read();              
             gchr = 's';
             }                 
        }
}

void converts(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   //Serial.write(a);
   //Serial.write(c);
   Serial.write(e); 
   Serial.write(g);
   Serial.write(h);
}

void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   //lcd.write(a);
   //lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}

void convertk(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
  // lcd.write(a);
  // lcd.write(c);
  // lcd.write(e); 
  // lcd.write(g);
   lcd.write(h);
}
