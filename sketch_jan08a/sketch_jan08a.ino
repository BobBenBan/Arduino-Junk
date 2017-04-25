#include <Adafruit_GPS.h>
#include <Adafruit_NeoPixel.h>

/*
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS0.h>
*/
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12,6);
Adafruit_NeoPixel lonley = Adafruit_NeoPixel(1,8);
Adafruit_GPS GPS(&Serial1);
void setup() {
  // put your setup code here, to run once:
  GPS.begin(9600);
  Serial1.begin();

  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); 
  //useInterrupt(true);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
