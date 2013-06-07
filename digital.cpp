#include "digital.h"


#include <graphics.h>



cDigitalNumbers::cDigitalNumbers(int nNum, int nX, int nY)
{
  nDigits = nNum;
  nPosX = nX; nPosY = nY;
//  setlinestyle(0,0,1);
  setfillstyle(SOLID_FILL,0);
  bar(nPosX+21, nPosY-3, nPosX + 24 * nNum + 24, nPosY + 39);
  for(int i=nDigits; i>0; i--)
    Num[i] = new cSiffra(nPosX + i*24, nPosY);
}

cDigitalNumbers::~cDigitalNumbers()
{
  for(int i=nDigits; i>0; i--)
    delete Num[i];
}

void cDigitalNumbers::Satt(int nTal)
{
  unsigned long nTemp = nTal;
  for(int i=nDigits; i>0; i--)
  {
    Num[i]->Set(nTemp % 10);
    nTemp /=10;
  }
}
