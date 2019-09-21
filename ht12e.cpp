#include "esp.h"
#include "ht12e.h"


HT12E::HT12E(){
}
  
void HT12E::setFrequency(int f){
  _clock = f;
  _time=(1000/_clock);            //calculate time per ht12e clock cycle in microseconds
}

int HT12E::getFrequency(){
  return _clock;
}

void HT12E::setOutPin(int p){
  _pin = p;
}

int HT12E::getOutPin(){
  return _pin;
}
  
void HT12E::DOUT(int16_t output, int rep){
  int j,n;
  pinMode(_pin,OUTPUT);           //Set pin for output
  digitalWrite(_pin,LOW);
  for(j=0;j<=rep;j++){                     //Loop 6 times so decoder gets atleast 3 good transmissions
    delayMicroseconds(36 * _time);           //Pilot Period (12Bits)
    digitalWrite(_pin,HIGH);      //Sync (1/3 bit high)
    delayMicroseconds(_time);
    for(n=11;n>=0;n--){                  //output 12 bits
      if (output & (1 << n)){
        Serial.print("1");
        digitalWrite(_pin,LOW);   //send "1"
        delayMicroseconds(2 * _time);
        digitalWrite(_pin,HIGH);
        delayMicroseconds(_time);
      }else{
        Serial.print("0");
        digitalWrite(_pin,LOW);   //send "0"
        delayMicroseconds(_time);
        digitalWrite(_pin,HIGH);
        delayMicroseconds(2 * _time);
      }
    }
    Serial.println();
    digitalWrite(_pin,LOW);  
  }
  digitalWrite(_pin,LOW);  
}  
