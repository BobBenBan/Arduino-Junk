
#ifndef PixelSimulator_h // to prevent people from breaking their code by #include-ing twice
#define PixelSimulator_h
#include <stdint.h> // for the uint _t goodness
#include <fstream> // for file writing stuff
using namespace std;
union RGB {
        uint32_t f;
        uint8_t c[4];
};
char RGB2HEXCHARS[17] = "0123456789abcdef";
class PixelSimulator
{
public:
        PixelSimulator(int numPixels,bool realT,int stop);
        void setPixelColor(int pixelNumber,uint32_t c);
        void setPixelColor(int pixelNumber,int r,int g,int b);
        void setPin(int blah);
        void setBrightness(uint8_t brightness);
        uint32_t Color(uint8_t r,uint8_t g,uint8_t b);
        int numPixels();
        void delayT(int delays);
        uint32_t getPixelColor(int pixelNumber);
        void show();
        void stop();
        void begin();
//private:
        int _numPixels;
        unsigned long _stop;
        int _count;
        unsigned long _T;
        RGB* _pixelData;
        bool _running;
        ofstream FILC;
};


PixelSimulator::PixelSimulator(int numPixels, bool realT, int stop) : _numPixels(numPixels),_stop(stop){
        _pixelData = new RGB[numPixels];
        for(int i = 0; i < numPixels; i++) _pixelData[i].f = 0;
        _numPixels = numPixels;
        _count = 0;
        _T = 0;
        _running = true;
}
void PixelSimulator::setPin(int blah){
};
void PixelSimulator::begin(){
        FILC.open ("COPYTTHIS.txt",ios::trunc | ios::out);
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
void PixelSimulator::setBrightness(uint8_t blah){
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
        _T += delays;
}
uint32_t PixelSimulator::getPixelColor(int pixelNumber){
        return _pixelData[pixelNumber].f;
}
void PixelSimulator::stop(){
        _running = false;
        FILC.close();
        //or do something else, if dsiredtobeso.
        exit(0);
}
void PixelSimulator::show(){
        if(!_running) return;
        FILC << '|';
        FILC << _T;
        FILC << ',';
        for(int i = 0; i < _numPixels; i++) {
                for(int j = 0; j < 3; j++) {
                        FILC << RGB2HEXCHARS[_pixelData[i].c[j]/16];
                        FILC << RGB2HEXCHARS[_pixelData[i].c[j]%16];
                }
        }
        FILC << '\n';
        _count++;
        _T = 0;
        if(_count >= _stop) stop();
}

#endif
