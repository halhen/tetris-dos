#include "spelplan.h"


#include <graphics.h>
#include <stdlib.h>			//För slumptalsgeneratorn
#include <conio.h>
#include <dos.h>
#include <alloc.h>

cSpelplan::cSpelplan()
{
  kloss = new cKloss;
  nPlanX = 100; nPlanY = 60;
  for(int i=0; i<20; i++)
    for(int j=0; j<10; j++)
      bKloss[j][i] = false;
  nPoints = nKlossar = 0;

//Rita upp användargränssnittet
  setfillstyle(9, RED);
  floodfill(10,10,10);
  setlinestyle(DASHED_LINE,0,1);
  setfillstyle(SOLID_FILL, 0);
  bar3d(nPlanX-1,nPlanY-1,nPlanX + 200+1, nPlanY + 400+1,0,false);
  bar3d(nPlanX+240-1,nPlanY+30-1,nPlanX+320+1,nPlanY+110+1,0,false);
  outtextxy(nPlanX + 265,nPlanY+10,"NEXT");
  setlinestyle(SOLID_LINE,0,1);
  setcolor(0);
  line(nPlanX + 28,nPlanY-1, nPlanX+173,nPlanY-1);

//Initiera slumptalsgeneratorn
  srand(time(0));

//Digitala siffror
  setcolor(LIGHTRED);
  outtextxy(480,180,"POINTS");
  DigPoints = new cDigitalNumbers(5, 480,200);

  outtextxy(530,280,"BLOCKS");
  DigNumKlossar = new cDigitalNumbers(3,530,300);

}

cSpelplan::~cSpelplan()
{
  delete kloss;
  delete DigPoints;
  delete DigNumKlossar;
}

bool cSpelplan::FullLine(int n)
{
  for(int i=0; i<10; i++)
    if(!bKloss[i][n])
      return false;
  return true;
}

bool cSpelplan::Landed()
{
  int nLower;
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
      if(kloss->figurMonster[nKlossIndex][j][i])
        nLower = i;
  if(nLower + nKlossY >=20)
    return(true);
  else
  {
    for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        if(bKloss[i+nKlossX][j+nKlossY] && kloss->figurMonster[nKlossIndex][i][j])
          return(true);

  }

  return false;
}

void cSpelplan::DeleteLine(int nLine)
{
  void far *buf= farmalloc(imagesize(nPlanX, nPlanY, nPlanX+200, nPlanY+20*nLine-1));
  getimage(nPlanX, nPlanY, nPlanX+200, nPlanY+20*nLine-1,buf);

  putimage(nPlanX,nPlanY+20,buf,0);
  farfree(buf);
  for(int i=nLine; i>0; i--)
    for(int j=0; j<10; j++)
      bKloss[j][i] = bKloss[j][i-1];

}

void cSpelplan::NyKloss(bool forsta)
{

  nDelay = 512 / (nKlossar / 100 + 1);
  nKlossX = 3; nKlossY = 0;
  if(forsta)
    nKlossIndex = rand() % 7;
  else
    nKlossIndex = nNastaKlossIndex;
  nNastaKlossIndex = rand() % 7;
  kloss->Rotera(nKlossIndex);
  bar(nPlanX+240, nPlanY+30, nPlanX+320, nPlanY+110);
  kloss->ritaUpp(nNastaKlossIndex, nPlanX+240, nPlanY+30);
}

bool cSpelplan::NerEtt()
{
  nKlossY++;
  char ch;
  for(int i=0; i<10; i++)
  {
    ch=Input();
    if(ch)
    {
      kloss->tack(nKlossIndex, nPlanX+nKlossX*20,nPlanY + (nKlossY-1)*20);
      TolkaInput(ch);
      kloss->ritaUpp(nKlossIndex, nPlanX+nKlossX*20,nPlanY+(nKlossY-1)*20);
    }
    delay(nDelay/10);
  }
  bool bLandat = Landed();
  if(bLandat)
    nKlossY--;
  if(!bLandat)
  {
    kloss->tack(nKlossIndex, nPlanX+nKlossX*20,nPlanY + (nKlossY-1)*20);
    kloss->ritaUpp(nKlossIndex, nPlanX+nKlossX*20,nPlanY+nKlossY*20);
  }
  else
  {
    kloss->tack(nKlossIndex, nPlanX+nKlossX*20,nPlanY + nKlossY*20);
    kloss->ritaUpp(nKlossIndex, nPlanX+nKlossX*20,nPlanY+nKlossY*20);
  }
  return bLandat;
}

bool cSpelplan::Sidstot(bool bVanster)
{
  int ytterst;
  if(bVanster)
  {
    for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        if(kloss->figurMonster[nKlossIndex][i][j])
          ytterst = i;
    if(ytterst + nKlossX >= 10)
      return(true);
    else
    {
      for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
          if(bKloss[i+nKlossX][j+nKlossY-1]&& kloss->figurMonster[nKlossIndex][i][j])
            return(true);
    }
    return(false);
  }
  else
  {
    for(int i=3; i>-1; i--)
      for(int j=0; j<4; j++)
        if(kloss->figurMonster[nKlossIndex][i][j])
          ytterst = i;
    if(nKlossX + ytterst  <0)
      return(true);
    else
    {
      for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
          if(bKloss[i+nKlossX][j+nKlossY-1] && kloss->figurMonster[nKlossIndex][i][j])
            return(true);
    }
  }
  return(false);
}

void cSpelplan::StegaHoger()
{
  nKlossX++;
  if(Sidstot(true))
    nKlossX--;
}

void cSpelplan::StegaVanster()
{
  nKlossX--;
  if(Sidstot(false))
    nKlossX++;
}

void cSpelplan::Rotera()
{
  kloss->Rotera(nKlossIndex);
  if(ForLangtNer() || Sidstot(false) || Sidstot(true))
    for(int i=0; i<3; i++)
      kloss->Rotera(nKlossIndex);
}

void cSpelplan::MarkeraLandning()
{
  nPoints +=4;
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
      if(kloss->figurMonster[nKlossIndex][i][j])
        bKloss[i+nKlossX][j+nKlossY] = true;

  int nFullLines = 0;
  for(int i=0; i<20; i++)
    if(FullLine(i))
    {
      DeleteLine(i);
      nFullLines++;
    }
  nPoints += nFullLines * 100;
  if(nFullLines == 4)
    nPoints +=300;
  nKlossar++;
}

char cSpelplan::Input()
{
  if(!kbhit())
    return 0;
  char ch;
  ch=getch();
  if(ch==0)
    ch=getch();
  return ch;
}


bool cSpelplan::TolkaInput(char ch)
{
    switch(ch)
    {
      case 27:
        closegraph();
        exit(0);
        break;
      case 72:
        Rotera();
        return true;
      case 75:
        StegaVanster();
        return true;
      case 77:
        StegaHoger();
        return true;
      case 80:
        nDelay /=4;
        return false;
    }
    return false;
}

void cSpelplan::Start()
{
  NyKloss(true);
  while(true)
  {
    if(NerEtt())
    {
      HideSpelplan();
      FadeScreen();
      setcolor(YELLOW);
      outtextxy(167,230,"GAME OVER");
      getch();
      closegraph();
      exit(0);
    }
    while(!NerEtt());
    MarkeraLandning();
    DigPoints->Satt(nPoints);
    DigNumKlossar->Satt(nKlossar);
    NyKloss(false);
  }
}

bool cSpelplan::ForLangtNer()
{

  int nNere=4;
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
    {
      if(kloss->figurMonster[nKlossIndex][j][i])
        nNere=i;
      if(bKloss[i+nKlossX][j+nKlossY] && kloss->figurMonster[nKlossIndex][i][j])
        return(true);
    }
  bool bTemp = (nNere + nKlossY > 20);
  return(bTemp);
}


void cSpelplan::HideSpelplan()
{
  setcolor(BLACK);
  setfillstyle(1,8);
  bar3d(nPlanX-1,nPlanY-1,nPlanX + 200+1, nPlanY + 400+1,0,false);
}

void cSpelplan::FadeScreen()
{
  for(int i=0; i<480; i++)
    for(int j=0; j<640; j+=2)
      putpixel(j,i,BLACK);
}
