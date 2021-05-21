#include <LCD.h>
#include <Wire.h>
#define sensor A0

LCD lcd1(16,2);

void setup() {
  Wire.begin();
  lcd1.initLCD();
  lcd1.setcursor(4,0);
  lcd1.printchar("hi there");
  lcd1.setcursor(1,1);
  lcd1.printchar("temp :");
  lcd1.setcursor(13,1);
  lcd1.C();
}

void loop() {
  float value=analogRead(sensor);
  float vol=(value*3.3)/1023;
  float temp=(vol*1000-600)/10;
  char cstr[20];
  dtostrf(temp,3,2,cstr);
  lcd1.setcursor(8,1);
  lcd1.printchar(cstr);
  delay(500);
}
