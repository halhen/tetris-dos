#include "kloss.h"
#include "vektorer.h"

#include <graphics.h>
#include <dos.h>

cKloss::cKloss()
{
  int i, j, k;
  for(i=0; i<20; i++)
    for(j=0; j<20; j++)
      vKlossMonster[i][j] = vektorKlossMonster[i][j];
  for(i=0; i<7; i++)
    for(j=0; j<4; j++)
      for(k=0; k<4; k++)
        figurMonster[i][j][k] = vektorFigurMonster[i][j][k];
  for(i=0; i<7; i++)
    nColor[i] = i+1;
  setfillstyle(1,0);
}

void cKloss::Rotera(int nIndex)
{
  bool vTemp[4][4];
  int i, j;
    for(i=0; i<4; i++)
      for(j=0; j<4; j++)
        vTemp[i][j] = figurMonster[nIndex][3-j][i];
  for(i=0; i<4; i++)
    for(j=0; j<4; j++)
      figurMonster[nIndex][i][j] = vTemp[i][j];
}

void cKloss::ritaUpp(int nIndex, int nX, int nY)
{
  for(int z = 0; z<4; z++)
    for(int x = 0; x<4; x++)
      if(figurMonster[nIndex][z][x])
        for(int i=0; i<20; i++)
          for(int j=0; j<20; j++)
            if(!vKlossMonster[j][i])
              putpixel(nX + i + z*20, nY + j + x*20, nColor[nIndex]);
}

void cKloss::tack(int nIndex, int nX, int nY)
{
  for(int z = 0; z<4; z++)
    for(int x = 0; x<4; x++)
      if(figurMonster[nIndex][z][x])
        bar(nX+20*z, nY+20*x, nX+20*z+19, nY+20*x+19);
}

void cKloss::Wait4Retrace(void)
{
  unsigned char Input;
  do
  {
    Input = inportb(0x3DA);
  } while(Input & 0x08);
  do
  {
    Input = inportb(0x3DA);
  } while(!(Input & 0x08));
}
