#include "spelplan.h"
//#include "digital.h"


#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

void initVGAgraphics(void);
void terminateProgram(void);
void temp();

main()
{
  initVGAgraphics();
  temp();
  terminateProgram();
}

void initVGAgraphics(void)
{
  int gdriver = VGA, gmode = VGAHI, errorcode;
  initgraph(&gdriver, &gmode, "");
  errorcode = graphresult();
  if (errorcode != grOk)    /* an error occurred */
  {
     cout<<"Graphics error: "<<grapherrormsg(errorcode)<<'\n';
     cout<<"Press any key to halt:";
     getch();
     exit(1);               /* return with error code */
  }
}

void terminateProgram(void)
{
  closegraph();
  exit(0);
}

void temp()
{
	cSpelplan *plan = new cSpelplan();
	plan->Start();
  delete plan;



}
