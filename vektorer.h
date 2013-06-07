#ifndef _VEKTORER_H_
#define _VEKTORER_H_

bool vektorKlossMonster[20][20]={
  { true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true},
  { false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, false, true},
  { false, false, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
  { false, false, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true},
//  { false, false, true, false, false, false, false, false, false, false,
//    false, false, false, false, false, false, false, true, false, true},
  { false, false, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, false, true},
  { false, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true},
  { true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true},
  {true, true, true, true, true, true, true, true, true, true,
   true, true, true, true, true, true, true, true, true, true}};


bool vektorFigurMonster[7][4][4]={
{
  {false, false, false, false},	//  0000
  {false, true, true, false},		//  0XX0
  {false, true, true, false},		//  0XX0
  {false, false, false, false}	//  0000
},

{
  {false, false, false, false},	//  0000
  {false, false, false, false},	//  0000
  {true, true, true, true},		//  XXXX
  {false, false, false, false}	//  0000
},

{
  {false, true, false, false},	//  0X00
  {false, true, true, false},		//  0XX0
  {false, false, true, false},	//  00X0
  {false, false, false, false}	//  0000
},

{
  {false, false, true, false}, 	//  00X0
  {false, true, true, false},		//  0XX0
  {false, true, false, false},	//  0X00
  {false, false, false, false}  //	 0000
},

{
  {false, true, true, false},		//  0XX0
  {false, false, true, false},   //  00X0
  {false, false, true, false},   //  00X0
  {false, false, false, false}	//  0000
},

{
  {false, true, true, false},		//  0XX0
  {false, true, false, false},	//  0X00
  {false, true, false, false},	//  0X00
  {false, false, false, false}	//  0000
},

{
  {false, false, false, false},   //  0000
  {true, true, true, false},		//  XXX0
  {false, true, false, false},   //  0X00
  {false, false, false, false}  //  0000
}};



#endif
