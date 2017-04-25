#define N_PIXELS 256
#define MIC_PIN A0
#define LED_PIN 4
#define SAMPLES 200 //#of readings per sample to analyze
#define NOISE 100
//inity
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel matrix = Adafruit_NeoPixel(N_PIXELS, LED_PIN);
//a single dat pt
struct dataPt {
  int freq;
  int vol;
} datas[32];


void setup() {
  memset(datas, 0, sizeof(datas));
  //matrix
  matrix.setBrightness(32);
  matrix.begin();
  matrix.show();

  Serial.begin(112500);
}

void loop() {
  //collect samples
  int n, avgCtr = 1, tmElasp, raw[SAMPLES], prevWav = 0;
  long avgT = 0, avgT0 = 0;
  long long tm;
  dataPt current; // current data reading
  //collect datas
  tm = millis();
  for (byte i = 0; i < SAMPLES; i++)
    raw[i] = analogRead(MIC_PIN);
  //Serial.println("samp got");
  tmElasp = millis() - tm;
  tmElasp = tmElasp == 0 ? 1 : tmElasp;
  //get average vol of sample.
  for ( byte i = 0; i < SAMPLES; i++) {
    n = abs(raw[i] - 512);
    avgT += (n <= NOISE) ? 0 : (n - NOISE);
  }
  current.vol = avgT / SAMPLES;
  //Serial.println("vol calc");
  //get vols;
  //basic calc of frequency
  for (int i = 1; i < SAMPLES-1; i++) {
    if (raw[i-1] >= raw[i] ^ raw[i+1] >= raw[i]) {
      avgT0 += 1000 * (i - prevWav);
      avgCtr++;
      prevWav = i;
    }
  }
  //Serial.println("freq 1");
  current.freq = (avgT0/avgCtr)/SAMPLES/10;
  //Serial.println("freq calc");
  for (int i = 31; i >= 1; i --) {
    //Serial.println(i);
    //Serial.println(i - 1);
    datas[i] = datas[i - 1];
  }
  datas[0] = current;
  Serial.println(datas[0].freq);
  //Serial.println("reDatas");
  //TODO: background based of prev samples
  for (int i = 0; i < 256; i++) matrix.setPixelColor(i, 0);
  for (int i = 0; i < 32; i++) {
    matrix.setPixelColor(xy(31 - i, datas[i].freq), 255, 0, 0);
  }
  matrix.show();
}
uint16_t xy(int x, int y) {
  y %= 8;
  return x * 8 + ((x % 2) ? y : 7 - y);
}

