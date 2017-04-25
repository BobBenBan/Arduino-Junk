//D7- LED on flora
//name:
int leds[] = {10,9,6};
int del = 500;
int on = 0;
//once on reset
void setup() {
  //initialize the digital pin as an output
  int i;
for (i = 0; i < 2; i = i + 1) {
  pinMode(leds[i],OUTPUT);
}
}

void loop() {
  digitalWrite(leds[on],LOW);
  on = on + 1;
  if (on == 3) on = 0;
  digitalWrite(leds[on],HIGH);
  delay(del);
}
