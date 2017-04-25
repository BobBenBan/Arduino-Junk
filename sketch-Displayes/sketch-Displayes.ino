struct bmap {
  uint8_t a[6];
};
char test = 0b11011100;
void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
bool getBit(char value,uint16_t bit){
  return !!(value | 1<<bit);
}

