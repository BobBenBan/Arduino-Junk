//include these codingn libraries
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_NeoPixel.h>


//initiate 16pixels, pin number 6
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();
//variable limit is  always at 15000
const int limit = 7000;
//variable stayt is constintaly 5
const int stayt = 5;

int prevAccel[3] = {0, 0, 0};
int counter = 0;
//variable for walking
bool walking = false;
//variable before walking
bool prevWalking = false;

void setup() {
  // put your setup code here, to run once:
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);


  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //amount of numbers per secound the serial monitor
  //Serial.begin(9600);
  //pixel brightness
  pixels.setBrightness(32);
  //initializes pixels
  pixels.begin();
  //waits for accelerometor to initialize, keep trying if it fails
  while (!lsm.begin());
}
int j = 0;
//creating function allTo
//sets all pixels to color val
void allTo(uint32_t val) {
  /*
    there are 16 pixels set the  of the pixels
    to the value, then show pixel
  */
  for (int i = 0; i < 16; i++) pixels.setPixelColor(i, val);
  pixels.show();
}


/*
  creating function wipe, calling , set j to the  of pixel,
  then increase j to the value of 16, each time in the loop for all 16 pixels
  stop at 16
*/
int cycle = 0;
void pixelManager() {
  // change cycle each time wipe happens, loop through colors
  switch (cycle) {
    case 0:
      Wipe(pixels.Color(255, 0, 0));
      break;
    case 1:
      Wipe(pixels.Color(0, 255, 0));
      break;
    case 2:
      Wipe(pixels.Color(0, 0, 255));
  }
}
void Wipe(uint32_t val) {
  pixels.setPixelColor(j, val);
  pixels.show();
  j++;
  if (j == 16) done();
}
//when j = 16, call the function done; switches color
void done() {
  //move the value of j back to 0 so wipe restarts
  j = 0;
  cycle = (cycle + 1) % 3;
}
void loop() {

  lsm.read();
  //an if the change in acceleration is 15000 or more (limit)
  //sets a counter to 5 (stayt) when moving, and  decrments it if not moving. Math!
  long tempAccel[3] = {};
  tempAccel[0] = prevAccel[0] - lsm.accelData.x;
  tempAccel[1] = prevAccel[1] - lsm.accelData.y;
  tempAccel[2] = prevAccel[2] - lsm.accelData.z;
  for (int i = 0; i < 3; i ++) tempAccel[i] *= tempAccel[i];
  if (sqrt(tempAccel[0] + tempAccel[1] + tempAccel[2]) >= limit)
    counter = stayt;
  else if (counter) counter--;
  // when counter is 0 it considers it not moving
  walking = counter != 0;
  if (walking != prevWalking) {
    //if the accelerometer didnt move then make j=0
    if (!walking) {
      //if not moving, then reset pixel and set all pixels to off
      j = 0;
      cycle = 0;
      allTo(0);
    }
  }
  if (walking) pixelManager();
  prevWalking = walking;

  prevAccel[0] = lsm.accelData.x;
  prevAccel[1] = lsm.accelData.y;
  prevAccel[2] = lsm.accelData.z;
  delay(100);
}
