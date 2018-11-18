#include "BasicMusic.h"
MusicGenerator mg = MusicGenerator(5, 110);
char bnotes[8] = "0077997";
char btime [8] = "1111112";
void setup() {
  for(int i=0;i<7;i++){
    mg.playNote(toNote(bnotes[i]-'0',2),(btime[i]-'0')*500-50,50);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
