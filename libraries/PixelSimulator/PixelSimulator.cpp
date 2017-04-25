#include "Arduino.h"
#include "PixelSimulator.h"

PixelSimulator::PixelSimulator(int numPixels, bool realT, int stop) : _numPixels(numPixels),_realT(realT),_stop(stop){
        _pixelData = new RGB[numPixels];
        for(int i = 0; i < numPixels; i++) _pixelData[i].f = 0;
        _numPixels = numPixels;
        _count = 0;
        _time = 0;
        _brightness = 255;
        _running = true;
}
void PixelSimulator::setPin(int blah){
};
void PixelSimulator::begin(){
        while(!Serial)
                Serial.begin(250000);
}
void PixelSimulator::setPixelColor(int pixelNumber,uint32_t c){
        if(!_running) return;
        _pixelData[pixelNumber].f = c;
}
void PixelSimulator::setPixelColor(int pixelNumber,int r,int g,int b){
        if(!_running) return;
        _pixelData[pixelNumber].c[0] = r;
        _pixelData[pixelNumber].c[1] = g;
        _pixelData[pixelNumber].c[2] = b;
}
void PixelSimulator::setBrightness(uint8_t brightness){
        _brightness = brightness;
}
uint32_t PixelSimulator::Color(uint8_t r, uint8_t g, uint8_t b){
        RGB temp;
        temp.c[0] = r;
        temp.c[1] = g;
        temp.c[2] = b;
        return temp.f;
}
int PixelSimulator::numPixels(){
        return _numPixels;
};
void PixelSimulator::delayT(int delays){
        if(_realT) {
                delay(delays);
        }
        else
                _time += delays;
}
uint32_t PixelSimulator::getPixelColor(int pixelNumber){
        return _pixelData[pixelNumber].f;
}
void PixelSimulator::stop(){
        _running = false;
}
void PixelSimulator::show(){
        if(!_running) return;
        Serial.print('|');
        if(_realT) Serial.print(millis());
        else Serial.print(_time);
        Serial.print(',');
        for(int i = 0; i < _numPixels; i++) {
                for(int j = 0; j < 3; j++) {
                        if(_pixelData[i].c[j] < 0x10) Serial.print('0');
                        Serial.print(_pixelData[i].c[j],HEX);
                }
        }
        Serial.println();
        _count++;
        if(_count >= _stop) stop();
}
