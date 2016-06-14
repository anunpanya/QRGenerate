#include <Arduino.h>
#include "qrencode.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP_NETPIE_Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;
extern int pxSize;
extern int offsetsX;
extern int offsetsY;

void render(int x, int y, int color){
  x=x+offsetsX;
  y=y+offsetsY;
  if(color==1) {
    display.drawPixel(x, y, BLACK);
    display.drawPixel(x, y+1, BLACK);
    display.drawPixel(x+1, y, BLACK);
    display.drawPixel(x+1, y+1, BLACK);
  }
  else {
    display.drawPixel(x, y, WHITE);
    display.drawPixel(x, y+1, WHITE);
    display.drawPixel(x+1, y, WHITE);
    display.drawPixel(x+1, y+1, WHITE);
  }
}

void createQR(String message) {
  // new line
  // Serial.println();
  
  // create QR code
  message.toCharArray((char *)strinbuf,47);
  qrencode();
  // print QR Code
  for (byte x = 0; x < WD; x+=2) {
    for (byte y = 0; y < WD; y++) {
      if ( QRBIT(x,y) &&  QRBIT((x+1),y)) { 
        // black square on top of black square
        // Serial.print("8");
        render(x*pxSize, y*pxSize, 0);
        render((x+1)*pxSize, y*pxSize, 0);
      }  
      if (!QRBIT(x,y) &&  QRBIT((x+1),y)) { 
        // white square on top of black square
        // Serial.print(" ");
        render(x*pxSize, y*pxSize, 1);
        render((x+1)*pxSize, y*pxSize, 0);
      }  
      if ( QRBIT(x,y) && !QRBIT((x+1),y)) { 
        // black square on top of white square
        // Serial.print("8");
        render(x*pxSize, y*pxSize, 0);
        render((x+1)*pxSize, y*pxSize, 1);
      }  
      if (!QRBIT(x,y) && !QRBIT((x+1),y)) { 
        // white square on top of white square
        // Serial.print(" "); 
        render(x*pxSize, y*pxSize, 1);
        render((x+1)*pxSize, y*pxSize, 1);
      }  
    }
    // Serial.println(); // next line
  }

  // new line
  // Serial.println();
  
}
