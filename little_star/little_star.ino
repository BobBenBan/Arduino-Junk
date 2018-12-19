#include "BasicMusic.h"
MusicGenerator mg = MusicGenerator(9, 70);
char bnotes[100] = "4740-740'4940-994'7+07959+07404742-740'";
char btime [100] = "1311 21441311 21441 31121 31121311 214";
void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:
int oct = 2;
  int i = 0;
  while(bnotes[i]!='\0'){
    oct = 2;
    if(bnotes[i] == '-') {
      oct = 1;
      i++;
    } else if (bnotes[i] == '+'){
      oct = 3;
      i++;
    }
    if(bnotes[i] == '\''){
      delay((btime[i]-'0')*150);
    }
    else
    mg.playNote(toNote(bnotes[i]-'0',oct),(btime[i]-'0')*200-50,50);
    i++;
  }
}
