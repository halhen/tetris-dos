#ifndef _SIFFRA_H_
#define _SIFFRA_H_

class cSiffra{
public:
  cSiffra(int, int);
  void Set(int);
protected:
  bool bHorisont[7];
  void PaintIt(int, int, int, bool);
  bool DigitLook[10][7];
  bool DigitPart[15][3];				//En del av siffran
  int nX, nY;


};

#endif