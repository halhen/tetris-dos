#ifndef _DIGITAL_H_
#define _DIGITAL_H_

#include "siffra.h"


class cDigitalNumbers
{
public:
  cDigitalNumbers(int, int, int);
  ~cDigitalNumbers();
  cSiffra *Num[10];
  void Satt(int);

protected:
  int nDigits, nPosX, nPosY;

};

#endif