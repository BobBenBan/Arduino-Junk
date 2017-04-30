#define HALF 1.05946
#define WHOLE HALF*HALF
#define C base
#define D C * WHOLE
#define E D * WHOLE
#define F E * HALF
#define G F * WHOLE
#define A G * WHOLE
#define B A * WHOLE
#define s * HALF
#define b / HALF
float base = 523;
//*
float mus[] = {C, C, G, G, A, A, G, 0, F, F, E, E, D, D, C, 0, G, G, F, F, E, E, D, 0, G, G, F, F, E, E, D, 0, C, C, G, G, A, A, G, 0, F, F, E, E, D, D, C, 0};
/*/
float mus[] ={E,E,F,G,G,F,E,D,C,C,D,E,E,D,D,0,E,E,F,G,G,F,E,D,C,C,D,E,D,C,C,0};
//*/
int c = 0;

void setup() {
  // put your setup code here, to run once:
  while(digitalRead(19)==LOW);
}

void loop() {
  if(mus[c]!=0);
  tone(5,mus[c]);
  delay(250);
  c++;
  if(mus[c]!=0)noTone(5);
  delay(50);
  // put your main code here, to run repeatedly:

}
