#ifndef _KLOSS_H_
#define _KLOSS_H_

class cKloss{
public:
  cKloss();
  void Rotera(int);
  bool vKlossMonster[20][20];
  bool figurMonster[7][4][4];
  int nColor[7];
  void ritaUpp(int, int, int);
  void tack(int, int, int);
  void Wait4Retrace(void);


};

#endif