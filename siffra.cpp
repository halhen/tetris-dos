#include "siffra.h"
#include "digitvektor.h"

#include <graphics.h>

cSiffra::cSiffra(int x, int y)
{
  for(int i=0; i<3; i++)
    for(int j=0; j<15; j++)
      DigitPart[i][j] = vektorDigitPart[i][j];
  for(int i=0; i<10; i++)
    for(int j=0; j<7; j++)
      DigitLook[i][j] = vektorDigitLook[i][j];
  nX = x; nY=y;
  for(int i=0; i<7; i++)
    bHorisont[i] = true;
  bHorisont[2] = bHorisont[3] = bHorisont[4] = false;
  Set(0);

}

void cSiffra::Set(int nNumber)
{
  int nPaintX, nPaintY;
  for(int i=0; i<7; i++)
  {
    switch(i)
    {
      case 0:
        nPaintX = nX; nPaintY = nY;
        break;
      case 1:
        nPaintX = nX; nPaintY = nY + 19;
        break;
      case 2:
        nPaintX = nX + 4; nPaintY = nY-1;
        break;
      case 3:
        nPaintX = nX + 3; nPaintY = nY + 16;
        break;
      case 4:
        nPaintX = nX + 4; nPaintY = nY + 33;
        break;
      case 5:
        nPaintX = nX + 20; nPaintY = nY;
        break;
      case 6:
        nPaintX = nX + 20; nPaintY = nY + 19;
        break;
    }
    if(DigitLook[nNumber][i])
      PaintIt(nPaintX, nPaintY, YELLOW, bHorisont[i]);
    else
      PaintIt(nPaintX, nPaintY, BLACK, bHorisont[i]);
   }
}

void cSiffra::PaintIt(int x, int y, int color, bool horiz)
{
  for(int i=0; i<3; i++)
    for(int j=0; j<15; j++)
      if(DigitPart[i][j])
        if(horiz)
          putpixel(x+i, y+j, color);
        else
          putpixel(x+j, y+i, color);
}
