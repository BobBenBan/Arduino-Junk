#include <Adafruit_CircuitPlayground.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  CircuitPlayground.begin();
  while(!CircuitPlayground.tapped());
  // put your main code here, to run repeatedly:
    tone(5,100,100);
}
