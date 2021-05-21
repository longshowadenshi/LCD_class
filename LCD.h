#ifndef LCD_H
#define LCD_H
#include <Arduino.h>
#include <Wire.h>

class LCD
{
  public:
  LCD(int c,int r);
  void initLCD();
  void setcursor(int x, int y);
  void printchar(char s[]);
  void C();
  private:
  void WriteCommand(uint8_t cmd);
  void WriteData(uint8_t data);
  char s[50];
};

#endif
