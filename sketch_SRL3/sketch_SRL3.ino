#define LOG_OUT 1
#define FFT_N 256 // set to 256 point fft
#define MIC_PIN 9
#define NOISE 4
#include <FFT.h> // include the library
uint16_t pros[FFT_N];
int maxAvg[8], minAvg[8];
void setup() {
  Serial.begin(115200);
  memset(pros, 0, sizeof(pros));
  //TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = MIC_PIN; 
  DIDR0 = 1 << MIC_PIN; 
}
void loop() {
  while (1) { // reduces jitter
    cli();  // UDRE interrupt slows this way down on arduino1.0
    for (int i = 0 ; i < 512 ; i += 2) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; 
      fft_input[i] = ADC;
      fft_input[i + 1] = 0; // set odd bins to 0
    }
    fft_window();
    fft_reorder();
    fft_run();
    fft_mag_log();
    sei();
    for(int i=0;i<FFT_N/2;i++){
      Serial.println(fft_log_out[i]);
    }
    delay(200);
  }
}
