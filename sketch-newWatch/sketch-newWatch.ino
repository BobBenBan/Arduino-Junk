#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 12
#define Second 1000
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel apm = Adafruit_NeoPixel(NUMPIXELS, 8, NEO_GRB + NEO_KHZ800);
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
Adafruit_GPS GPS(&Serial1);

uint8_t twelveOclock = 7;
int8_t tmZone[2] = { -7, 0};
uint8_t br[3] = {255, 159, 223};
uint8_t ord[3] = {2, 1, 0};
uint8_t bwitnhass = 16;
uint32_t back = pixels.Color(256/bwitnhass, 256/bwitnhass, 256/bwitnhass);

uint8_t rTime[3] = {11, 59, 0};

uint8_t pTime[3] = {12, 12, 12};
uint8_t prevmil;
signed long long selfT = 0;
bool fixed = false;
void changeComp(int n, uint8_t comp, uint8_t v) {
  uint32_t col = pixels.getPixelColor(n);
  void *p = &col;
  ((uint8_t*)p)[comp] = v;
  /*
    //Serial.print("set ");
    //Serial.print(n);
    //Serial.print(" comp ");
    //Serial.print(comp);
    //Serial.print(" to ");
    //Serial.println(v);//*/
  pixels.setPixelColor(n, col);
}

void showTime() {
  uint8_t sTime[3];
  sTime[0] = (twelveOclock + rTime[0]) % 12;
  sTime[1] = (twelveOclock + (rTime[1] / 5)) % 12;
  sTime[2] = (twelveOclock + (rTime[2] / 5)) % 12;
  /*//Serial.print(sTime[0]);
    //Serial.print(':');
    //Serial.print(sTime[1]);
    //Serial.print(':');
    //Serial.println(sTime[2]);//*/
  apm.setPixelColor(0,rTime[0] >= 12 ? apm.Color(br[0],br[1],0) : apm.Color(0,0,255));
  //Serial.println(rTime[0]);
  for (int i = 0; i < 3; i ++) {
    changeComp(pTime[i], ord[i], 0);
    changeComp(sTime[i], ord[i], br[ord[i]]);
  }
  pTime[0] = sTime[0];
  pTime[1] = sTime[1];
  pTime[2] = sTime[2];
  if ((uint8_t)GPS.satellites != 0)
    for (int i = 0; i < NUMPIXELS; i ++)
      if (pixels.getPixelColor(i) == 0)pixels.setPixelColor(i, back);
  apm.show();
  pixels.show();
}
void resetTime() {
  for (int i = 0; i < NUMPIXELS; i ++)
    pixels.setPixelColor(i, 0);
  pixels.show();
  fixed = (uint8_t)GPS.satellites != 0;
}
void inc() {
  if (++rTime[2] == 60) {
    rTime[2] = 0;
    if (++rTime[1] == 60) {
      rTime[1] = 0;
      rTime[0] = (rTime[0] + 1) % 24;
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  pixels.setBrightness(bwitnhass);
  apm.setBrightness(bwitnhass);
  pixels.begin();
  apm.begin();
  selfT = millis();
  showTime();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (selfT > millis()) selfT -= (signed long long)4294967295;
  GPS.read();
  if (GPS.newNMEAreceived()) {
    if (!GPS.parse(GPS.lastNMEA()))return;
  }
  if (((uint8_t)GPS.satellites != 0) != fixed) resetTime();
  if ((uint8_t)GPS.satellites != 0 && (GPS.seconds != rTime[2] || GPS.milliseconds != prevmil)) {
      prevmil = GPS.milliseconds;
      rTime[0] =  (24 + GPS.hour + tmZone[0]) % 24;
      rTime[1] = (60 + GPS.minute + tmZone[1]) % 60;
      rTime[2] = GPS.seconds;
      if (GPS.milliseconds >= 500)inc();
      selfT += GPS.milliseconds - (millis() - selfT);
      showTime();

      //Serial.print("\nTime: ");
      //Serial.print(GPS.hour, DEC); //Serial.print(':');
      //Serial.print(GPS.minute, DEC); //Serial.print(':');
      //Serial.print(GPS.seconds, DEC); //Serial.print('.');
      //Serial.print(GPS.milliseconds);
      //Serial.print(" --> " );
      //Serial.print(rTime[0], DEC); //Serial.print(':');
      //Serial.print(rTime[1], DEC); //Serial.print(':');
      //Serial.print(rTime[2], DEC); //Serial.println('.');
      //Serial.println((int)GPS.satellites);
    
  }
  else if (millis() - selfT >= Second) {
    //Serial.println(GPS.satellites);
    inc();
    showTime();//*/
    selfT += Second;
  }
}
