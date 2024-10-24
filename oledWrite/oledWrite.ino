#include "U8glib.h"

const int btn1 = 8;
const int btn2 = 9;
int xpos = 0;

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC

void setup(void) {
  u8g.setFont(u8g_font_unifont);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop(void) {

  if(digitalRead(btn1)== HIGH){
    xpos = xpos + 5;
    oledWrite(">", xpos);
  }

  if(digitalRead(btn2) == HIGH){
    xpos = xpos - 5;
    oledWrite("<", xpos);
  }

  oledWrite("o", xpos);

}

void oledWrite(int x, int y, String text) {
  u8g.firstPage();

  do {

    u8g.drawStr(x, y, text.c_str());

  } while (u8g.nextPage());
}