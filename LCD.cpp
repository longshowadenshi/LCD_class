#include <LCD.h>
#include <Wire.h>
#define lcd_address 0x3e
LCD::LCD(int c, int r)
{
}

void LCD::WriteCommand(uint8_t cmd)
{
  Wire.beginTransmission(lcd_address);
  Wire.write(0x00);
  Wire.write(cmd);
  Wire.endTransmission();
}
void LCD::WriteData(uint8_t data)
{
  Wire.beginTransmission(lcd_address);
  Wire.write(0x40);
  Wire.write(data);
  Wire.endTransmission();
}

void LCD::initLCD()
{
  
  delay(40);
  WriteCommand(0x38); 
  delay(1);
  WriteCommand(0x39); 
  delay(1);
  WriteCommand(0x14); 
  delay(1);
  WriteCommand(0x73); 
  delay(1);
  WriteCommand(0x5e); 
  delay(1);
  WriteCommand(0x6c); 
  delay(1);
  WriteCommand(0x38); 
  delay(1);
  WriteCommand(0x0c); 
  delay(1);
  WriteCommand(0x01); 
  delay(1);
}

void LCD::setcursor(int x, int y)
{
  uint8_t Cursor=0x80;
  Cursor|=x;
  if(y==1)
  {
    Cursor|=0x40;
  }
  WriteCommand(Cursor);
}

void LCD::printchar(char s[])
{
  int len=strlen(s);
  for(int i=0;i<len;i++)
  {
    WriteData((uint8_t)s[i]);
  }
}
void LCD::C()
{
  WriteData(0xDF);
  WriteData(0x43);
}
