bool vektorDigitLook[10][7] =
{
  {true, true, true, false, true, true, true}, //0
  {false, false, false, false, false, true, true}, //1
  {false, true, true, true, true, true, false}, //2
  {false, false, true, true, true, true, true}, //3
  {true, false, false, true, false, true, true}, //4
  {true, false, true, true, true, false, true},  //5
  {true, true, true, true, true, false, true},   //6
  {false, false, true, false, false, true, true},//7
  {true, true, true, true, true, true, true},  //8
  {true, false, true, true, true, true, true}, //9         
};

bool vektorDigitPart[3][15] =
{
  {false, true, true, true, true, true, true, true,
   true, true, true, true, true, true, false},
  {true, true, true, true, true, true, true, true,
   true, true, true, true, true, true, true},
  {false, true, true, true, true, true, true, true,
   true, true, true, true, true, true, false}
};