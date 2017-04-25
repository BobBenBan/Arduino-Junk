
#ifndef PixelSimulator_h
#define PixelSimulator_h
#include "Arduino.h"
union RGB {
        uint32_t f;
        uint8_t c[4];
};
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
        bool _realT;
        unsigned long _stop;
        int _count;
        unsigned long _time;
        uint8_t _brightness;
        RGB* _pixelData;
        bool _running;
};

#endif
