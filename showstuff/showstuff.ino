//accelerometer stuffs
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS0.h>
//neopixel stuffs
#include <Adafruit_NeoPixel.h>
//...
#include <Math.h>
//setup stuffs
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16,6, NEO_GRB+NEO_KHZ800);
Adafruit_NeoPixel single = Adafruit_NeoPixel(1,8,NEO_GRB+NEO_KHZ800);
const float pi = 3.141592654;
const uint8_t brightness = 64;
//mathy
uint8_t getPixLight(float x, float y, float z=0, uint32_t color=0){
  return 16-ceil((atan2(x,y)*180.0/pi+180.0)/22.5);
}
//tricks
//*
void setComp(uint8_t pixel, uint8_t color, uint8_t value){
   uint32_t temp = pixels.getPixelColor(pixel);
   ((uint8_t*)((void*)&temp))[color] = value;
   pixels.setPixelColor(pixel,temp);
}//*/
//stuffs
void setup() {
  //Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(brightness);
  
  single.begin();
  single.setBrightness(brightness);
  single.setPixelColor(0,255,255,255);
  single.show();
  
  lsm.begin();
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
}
void loop() {
  sensors_event_t s[4] = {};
  lsm.getEvent(&s[0],&s[1],&s[2],&s[3]);
  uint8_t pixel1 = getPixLight(s[0].acceleration.x,s[0].acceleration.y);
 
  setComp(pixel1,2,255);
  
  uint8_t pixel2 = getPixLight(s[1].magnetic.x,s[1].magnetic.y,s[1].magnetic.z,3);
  setComp(pixel2,1,255);
  
  pixels.show();
  
  setComp(pixel1,2,0);
  
  setComp(pixel2,1,0);
  delay(50);
}
