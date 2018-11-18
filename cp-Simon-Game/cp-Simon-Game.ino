
#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define PIN 17 //ring pin
#define SPEAKER_PIN 5
#define builtInRing
#ifdef builtInRing
Adafruit_NeoPixel ring = Adafruit_NeoPixel(10, 17);
#else
Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, PIN);
#endif
//*
//light level intensity modifiers:
uint8_t const lightMin = 3; //light minimum
uint8_t const lightSelect = 100; //light level, select
uint8_t const lightDiminish = 5; //light level, rate of diminishing
uint8_t const lightSection = 30; //light level, section select
uint8_t const lightFlash = 250; //light level, flashed
//x10ms (every 10 MS delay, + time)
//pixel offset
uint8_t pixelOffset = 1;

int const waitIntro = 90; //in the intro sequence
int const waitDisplay = 300; //waitTime, show sequence
int const waitBetween = 400; //waitTime, before it starts showing the sequence
int const waitWrong = 100; //in recap after you make a mistake

int const noteTime = 100; //handled differently
//in steps of 10MS

int const freq[8] = {400, 500, 800, 600,
                     300, 375, 535, 450
                    }; //first 4 when click, last 4 when show


//FUNCTIONS FOR LIGHT STUFF
void setPixel(uint8_t p, uint32_t c) { //set pixel p to color c
  p = (p + pixelOffset) % 12;
#ifdef builtInRing
  if (p == 5 || p == 11)return;
  if (p > 5)p--;
#endif
  ring.setPixelColor(p, c);
}

//get pixel based of accelorometer tilt
uint8_t accelPix() {
  float rpix = 20 - pixelOffset - atan2(CircuitPlayground.motionX(), CircuitPlayground.motionY()) / 3.141592654 * 6;
  return round(rpix) % 12;
}

//get color, based of pixel and intensity
uint32_t wheel(uint8_t p, uint8_t t) {
  if (p < 3) return ring.Color(t, 0, 0);
  if (p < 6) return ring.Color(0, 0, t);
  if (p < 9) return ring.Color(0, t, 0);
  return ring.Color(t, t, 0);
}

//stores current light intensities
int16_t lit[12];

//set an entire setSectiontors intensities
void setSection(uint8_t s, uint8_t b) {
  s *= 3;
  for (uint8_t i = 0; i < 3; i++) {
    if (lit[s + i] < b) lit[s + i] = b;
  }
}

void showPix() {
  for (uint8_t i = 0; i < 12; i++) {
    setPixel(i, wheel(i, lit[i])) ;
    if (lit[i] > lightMin) lit[i] -= lightDiminish;
    if (lit[i] < lightMin) lit[i] = lightMin;
  }
  ring.show();
}

//Gameplay variables
uint8_t notes[1000]; //notesious values
uint16_t len = 0; //length
uint16_t curNote = 0; //

uint8_t curMode = 0;
/* 0: Idle
   1: Play Lightshow Intro
   2: Display
   3: Player
   4: lose
*/
//*
bool tapped = false;
//pause/wait time
uint8_t waitTime = 0;
void setWaitTime(int tim) {
  waitTime = tim;
}
//make nextNote note;
void nextNote() {
  notes[len++] = random(4);
  setWaitTime(waitBetween);
}
void makeSound(int htz, unsigned long mill = noteTime) {
  tone(SPEAKER_PIN, htz, mill);
}
void makeIndefSound(int htz) {
  tone(SPEAKER_PIN, htz);
}
//persistance of sound when you hold button
bool isPersist = false;
uint8_t persistSec = 0;
unsigned long noteWaitEnd = 0;
//other things
uint8_t wrongNote;
long nextTime = 0;

void setup() {
  randomSeed(analogRead(A4) + (int)analogRead(12)*analogRead(6) + (int)analogRead(9) + analogRead(10));
  //setup
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_2_G);
  ring.begin();
  ring.setBrightness(200);
  /*
    Serial.begin(9600);
    while (!Serial)
    Serial.println("I work!");//*/
  //setlight levels to minimum
  memset(&lit, lightMin, 12);
  nextTime = millis();
}
//main loop
void loop() {
  uint8_t pix = accelPix();
  if (waitTime > 0) {
    waitTime -= 5;
  }
  else switch (curMode) {
      case 0: //idle mode
        //setSection(pix/3*3, lightSection);
        if (digitalRead(21) == HIGH) {
          lit[pix] = lightSelect;
          if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) curMode = 1; //ifClicked, start game
        }
        break;
      case 1: //introduction
        makeSound(freq[curNote % 4 + ((curNote % 8) < 4 ? 4 : 0)]); //make sound
        setSection(curNote % 4, lightFlash); //set light
        pixelOffset = (pixelOffset + 1) % 12; //rotato!
        if (++curNote == 16) { //after 16 runs, move to actual game
          pixelOffset = (pixelOffset + 8) % 12;
          curNote = 0;
          curMode = 2;
          nextNote();
          setWaitTime(waitBetween); //allow some delay;
        } else
          setWaitTime(waitIntro); //pause between each flash
        break;
      case 2: //show the notes;
        setSection(notes[curNote], lightFlash); //flash
        makeSound(freq[notes[curNote] + 4]); //show sound
        setWaitTime(waitDisplay);
        if (++curNote == len) {
          curNote = 0;
          curMode = 3;
        }
        break;
      case 3: //user input section;
        if (CircuitPlayground.leftButton() || CircuitPlayground.rightButton()) { //button down
          if (!tapped && curNote != len) { //runs only on first tap, and not at end
            //not at end possible to last note spamming, and waiting for persist to end.
            tapped = true;
            if (pix / 3 == notes[curNote]) { //if correct
              isPersist = true;
              persistSec = pix / 3;
              makeIndefSound(freq[notes[curNote]]);
              noteWaitEnd = millis() + noteTime;
              setSection(notes[curNote], lightFlash);
              curNote++;
            } else {
              wrongNote = curNote;
              curNote = 0;
              curMode = 4; //show correct value
            }
          }
          else setSection(persistSec, lightFlash); //hold light on;
        } else { //button not down
          tapped = false;
          if (isPersist && millis() > noteWaitEnd) {
            isPersist = false;
            noTone(SPEAKER_PIN);
          }
          lit[pix] = lightSelect; //highlight current light
          setSection(pix / 3, lightSection); //highlight currently selected section
          if (curNote == len && !isPersist) { //if all correct (and button not down)
            curNote = 0;
            curMode = 2;
            setWaitTime(waitBetween);
            nextNote();
          }
        }
        break;
      case 4: //flash correct value;
        setSection(notes[wrongNote], lightFlash);
        makeSound(freq[notes[wrongNote]] / 4, waitWrong * 4 / 5);
        setWaitTime(waitWrong);
        if (++curNote == 4) {
          setWaitTime(waitBetween);
          curMode = 5;
          curNote = 0;
        }
        break;
      case 5: //recap
        setSection(notes[curNote], lightFlash);
        makeSound(freq[notes[curNote]], waitWrong * 4 / 5);
        setWaitTime(waitWrong);
        if (++curNote == len) {
          len = 0;
          curMode = 0;
          curNote = 0;
        }
        break;
    }
  showPix(); //show the pixels appropiately
  nextTime += 5;
  while(millis()<nextTime);
  //*/
}

