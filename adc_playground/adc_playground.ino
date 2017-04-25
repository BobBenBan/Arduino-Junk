#include <Wire.h>
int16_t buff[128];
int8_t bufft = 0;
void setup() {
  Serial.begin(9600);
  delay(1000);
  // put your setup code here, to run once:
  ADMUX = (ADMUX & 0b11110000) + 1;
  ADCSRA = _BV(ADEN)  | _BV(ADSC)  | _BV(ADATE) |  _BV(ADIE)  | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ADCSRA & _BV(ADIE));
  bufft = 0;
  ADCSRA |= _BV(ADIE);
  for(int x = 0; x < 128; x++){
    Serial.println(buff[x]);
  }
}
ISR(ADC_vect) {
  buff[bufft] = ADC;
  if(++bufft > 128) ADCSRA &= ~_BV(ADIE);
}

