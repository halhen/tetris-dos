#include "kloss.h"
#include "digital.h"

class cSpelplan{
public:
  cSpelplan();
  ~cSpelplan();
  bool NerEtt();		//Anropar Landed() o returnerar samma värde
  bool FullLine(int); //Om Linjen blivit full
  void DeleteLine(int);
  void NyKloss(bool forsta);
  void Rotera();
  void StegaHoger();
  void StegaVanster();
  void MarkeraLandning();
  char Input();
  void Start();
protected:
  cKloss *kloss;
  int nKlossX, nKlossY; //I rutor på spelplanen, Från övre vänstra!
  int nKlossIndex, nNastaKlossIndex;		//Klossens ID 0-6
  bool Landed();	//Om klossen når botten!
  bool Sidstot(bool);
  bool ForLangtNer();
  int nPlanX, nPlanY;
  int nDelay;
  bool bKloss[10][20];
  bool TolkaInput(char);
  void HideSpelplan();
  void FadeScreen();
  unsigned long int nPoints, nKlossar;
  cDigitalNumbers *DigPoints, *DigNumKlossar;



};