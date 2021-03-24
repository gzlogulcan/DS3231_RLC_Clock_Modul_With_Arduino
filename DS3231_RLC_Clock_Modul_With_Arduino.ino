#include <Wire.h>  //Kütüphaneleri yükleyin
#include "RTClib.h" //Kütüphaneleri yükleyin

//Arduino Uno
//SCL = A5 
//SDA  = A4
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Pazar", "Pazartesi", "Salı", "Çarşamba", "Perşembe", "Cuma", "Cumartesi"};

void setup () 
{
  Serial.begin(9600);
  delay(1000); 

  if (! rtc.begin()) {
    Serial.println("RTC BULUNAMADI!");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC güç kaybetti, zamanı ayarlayalım!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () 
{
    DateTime now = rtc.now();
    
    Serial.print("Tarih: ");
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    //Serial.print(" (");
    Serial.print(" ");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //Serial.print(") ");
    Serial.print("\n");
    Serial.print("Saat:  ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("\n");
    Serial.print("--------------------------------");
    
    Serial.println();
    delay(1000);
}
