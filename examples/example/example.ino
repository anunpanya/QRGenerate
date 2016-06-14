#include <Arduino.h>
#include <qrgenerate.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP_NETPIE_Adafruit_SSD1306.h>

#define SDA 4
Adafruit_SSD1306 display(SDA);

int pxSize = 2;
int offsetsX = 35;
int offsetsY = 2;

void setup() {
           
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x78>>1);
  display.display();
  delay(2000);
  display.clearDisplay();
    
  // print "Hello, world!" as text and then a QR code.
  Serial.println("Hello, world!");
  createQR("Hello, world!");
  display.display();
}

void loop() { }