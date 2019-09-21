#ifndef ht12e_h
#define ht12e_h

#include "esp.h"

class HT12E{

  public:
    HT12E();
    void setOutPin(int p);
    void setFrequency(int f);
    int getOutPin();
    int getFrequency();
    void DOUT(int16_t output, int rep);
  private:
    int _clock = 3;                      //Emulated HT12e clock speed in Khz
    int _pin = D2;                       //Serial Output Pin
    int _time = 333;                     //Microseconds per bit
};

#endif
