#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;

#define LOWFLASH (defined(__AVR_ATmega328P__) && defined(MCUFRIEND_KBV_H_))




#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x8410
#define ORANGE  0xE880

void setup()
{
    uint16_t ID = tft.readID();
    tft.begin(ID);

    tft.fillScreen(BLACK);
     draw_robot(90,150,CYAN);
     delay(1000);
     draw_robot(90,150,BLACK);
     draw_robot_blink(90,150,CYAN);
     delay(200);
     draw_robot_blink(90,150,BLACK);
     draw_robot(90,150,CYAN);
     delay(400);
     draw_robot(90,150,BLACK);
     draw_robot_blink(90,150,CYAN);
     delay(200);
     draw_robot_blink(90,150,BLACK);
     draw_robot(90,150,CYAN);
     delay(1000);
     draw_robot(90,150,BLACK);
     draw_robot_talk(90,150,CYAN,"Hello, my name is Neko... and i am your personnal assistant!", false);
     delay(500);
     draw_robot_talk(90,150,CYAN,"Tell me anything you may need!", true);
     delay(1000);
     draw_robot_talk(90,150,BLACK,"", false);
     draw_robot(90,150,CYAN);
}


void draw_robot(int offset_x, int offset_y,short color){
    tft.fillRoundRect(30+offset_x, 10+offset_y, 30, 60, 20, color);
    tft.fillRoundRect(90+offset_x, 10+offset_y, 30, 60, 20, color);
    tft.fillRoundRect(20+offset_x, 80+offset_y, 30, 10, 5, color);
    tft.fillRoundRect(100+offset_x, 80+offset_y, 30, 10, 5, color);
    tft.drawLine(25+offset_x, 95+offset_y, 75+offset_x,110+offset_y, color);
    tft.drawLine(75+offset_x, 110+offset_y, 125+offset_x, 95+offset_y, color);
    tft.drawLine(25+offset_x, 96+offset_y, 75+offset_x,111+offset_y, color);
    tft.drawLine(75+offset_x, 111+offset_y, 125+offset_x, 96+offset_y, color);
    tft.drawLine(25+offset_x, 97+offset_y, 75+offset_x,112+offset_y, color);
    tft.drawLine(75+offset_x, 112+offset_y, 125+offset_x, 97+offset_y, color);
    tft.drawLine(25+offset_x, 98+offset_y, 75+offset_x,113+offset_y, color);
    tft.drawLine(75+offset_x, 113+offset_y, 125+offset_x, 98+offset_y, color); 
  }
  void draw_robot_blink(int offset_x, int offset_y,short color){
    
    tft.drawLine(offset_x, 30+offset_y, 60+offset_x, 50+offset_y, color);
    tft.drawLine(60+offset_x, 50+offset_y, offset_x, 60+offset_y, color);
    tft.drawLine(150+offset_x, 30+offset_y, 90+offset_x, 50+offset_y, color);
    tft.drawLine(90+offset_x, 50+offset_y, 150+offset_x, 60+offset_y, color);
    tft.drawLine(offset_x, 31+offset_y, 60+offset_x, 51+offset_y, color);
    tft.drawLine(60+offset_x, 51+offset_y, offset_x, 61+offset_y, color);
    tft.drawLine(150+offset_x, 31+offset_y, 90+offset_x, 51+offset_y, color);
    tft.drawLine(90+offset_x, 51+offset_y, 150+offset_x, 61+offset_y, color);

    //tft.fillRoundRect(20+offset_x, 80+offset_y, 30, 10, 5, color);
    //tft.fillRoundRect(100+offset_x, 80+offset_y, 30, 10, 5, color);
    tft.drawLine(25+offset_x, 95+offset_y, 75+offset_x,110+offset_y, color);
    tft.drawLine(75+offset_x, 110+offset_y, 125+offset_x, 95+offset_y, color);
    tft.drawLine(25+offset_x, 96+offset_y, 75+offset_x,111+offset_y, color);
    tft.drawLine(75+offset_x, 111+offset_y, 125+offset_x, 96+offset_y, color);
    tft.drawLine(25+offset_x, 97+offset_y, 75+offset_x,112+offset_y, color);
    tft.drawLine(75+offset_x, 112+offset_y, 125+offset_x, 97+offset_y, color);
    tft.drawLine(25+offset_x, 98+offset_y, 75+offset_x,113+offset_y, color);
    tft.drawLine(75+offset_x, 113+offset_y, 125+offset_x, 98+offset_y, color); 
  }
  void draw_robot_talk(int offset_x, int offset_y,short color,String msg,bool clrText){
    if(!clrText){
    
      tft.fillRoundRect(30+offset_x, 10+offset_y, 30, 60, 20, color);
      tft.fillRoundRect(90+offset_x, 10+offset_y, 30, 60, 20, color);
      tft.fillRoundRect(20+offset_x, 80+offset_y, 30, 10, 5, color);
      tft.fillRoundRect(100+offset_x, 80+offset_y, 30, 10, 5, color);
    
      tft.drawLine(40+offset_x, 95+offset_y, 75+offset_x,110+offset_y, color);
      tft.drawLine(75+offset_x, 110+offset_y, 110+offset_x, 95+offset_y, color);
      tft.drawLine(40+offset_x, 96+offset_y, 75+offset_x,111+offset_y, color);
      tft.drawLine(75+offset_x, 111+offset_y, 110+offset_x, 96+offset_y, color);
      tft.drawLine(40+offset_x, 97+offset_y, 75+offset_x,112+offset_y, color);
      tft.drawLine(75+offset_x, 112+offset_y, 110+offset_x, 97+offset_y, color);
      tft.drawLine(40+offset_x, 98+offset_y, 75+offset_x,113+offset_y, color);
      tft.drawLine(75+offset_x, 113+offset_y, 110+offset_x, 98+offset_y, color);
      tft.drawFastHLine(40+offset_x, 95+offset_y, 70, color);
      tft.drawFastHLine(40+offset_x, 96+offset_y, 70, color);
      tft.drawFastHLine(40+offset_x, 97+offset_y, 68, color);
    }
    tft.fillRect(0,0,350,48,BLACK);
    tft.setCursor(0,0);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    for(int i=0; i<msg.length();i++){
      tft.print(msg[i]);
      delay(80);
    }
    
  }
void loop(void)
{



}
