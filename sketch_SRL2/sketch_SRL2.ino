#define LOG_OUT 1
#define FFT_N 256
#define NOISE 4
#include <FFT.h>
byte pos = 0;
void setup() {
  //assumes pin 7;
  Serial.begin(115200);
  delay(3000);
  TIMSK0 = 0;
  ADMUX = 7;
  ADCSRA = _BV(ADEN)  |
           _BV(ADSC)  |
           _BV(ADATE) |
           _BV(ADIE)  |
           _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);
  ADCSRB = 0;
  DIDR0 = 1<<7;
  TIMSK0 = 0;
  sei();
}

void loop() {
  
  Serial.println("wait'n");
  while (ADCSRA & _BV(ADIE)); //wait for ADC readings
  Serial.println("waited");
  pos = 0; //reset pos
  fft_window(); //fft process
  fft_reorder();
  fft_run();
  fft_mag_log();
  //ADCSRA |= _BV(ADIE); //reenable
  for (int i = 0; i < FFT_N / 2; i++){
    if (fft_log_out[i] < NOISE) fft_log_out[i] = 0;
    Serial.println(fft_log_out[i]);
  }
  
}

ISR(ADC_vect) {
  int16_t samp = ADC;
  fft_input[pos] = samp;
  fft_input[pos + 1] = 0;
  pos += 2;
  if (pos > FFT_N) ADCSRA &= ~_BV(ADIE);
}
