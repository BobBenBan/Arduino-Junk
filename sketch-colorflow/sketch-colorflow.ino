int del = 0;
int st = 100;
double spma = 0.4;
double spmi = 0.2;

int pins[] = {6,9,10,7};
double spad = 127/(spma-spmi);
double a = 255.00;
int ipa[3] = {};
int ina[3] = {255,255,255};
void setup() {
  for(int i = 0; i < 4; i++)pinMode(pins[i],OUTPUT);
  /*
  while(!Serial)
  Serial.begin(9600);//*/
  randomSeed(analogRead(0));
}
void loop() {
 //*
  rgbs(ipa,ina,a);
  double ss = abs(a-127.00);
  a+=spma-(ss/spad);
  if(a >=255){
    digitalWrite(7,HIGH);
    a=0.00;
    for(int i = 0; i < 3; i++)ipa[i] = ina[i];
    for(int i = 0; i < 3; i++)ina[i] = random(255);
    delay(st);
  }
  else digitalWrite(7,LOW);
  delay(del);
  //*/
}
void rgbs(int p[],int n[],double t){
  double rgba[]={};
  double lt = t/255.00;
  int ttt = 0;
  for(int i = 0; i < 3; i++){
    double r = (p[i]*(1-lt))+(n[i]*lt);
    int o = (r*r*r/255.00/255.00)+0.5;
    rgba[i] = o;
    //ttt += o;
    analogWrite(pins[i],o);
  }
  //Serial.println(ttt);
  //Serial.println();
}

