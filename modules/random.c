/*
    This file is part of TAKEWAKE Reloaded.
    TAKEWAKE Reloaded, a free operating system in C and ASM
    Copyright (C) 2019  The TAKEWAKE Community

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

//Generate randomized variables (with random.h)

#include "random.h"

int i = 0;
int integers[] = {12,34,22,72,2389,12,0,423,231,342,32,1,654,24,654,23,2,56,76,12,14,56,23,1,4,6789,4,67,789,4,346,32,53,53,21,3,2,1,323,233,423,2,32,32,45,65,21,19,15,8,54,23,13,67,8,9,8,19,13,14,591,41,156,15,169,94,14,5,654,64,31,31,54,21,52,29,214,12,46,14,46,25,1543,124,132,5,14455,1214,412,567,74,1732,481,381,491,4,1,45,12,4,5,65,7356,2,33,3,4,4,535,4,3,24,45,6,3,56,4,67,754,4,2,433,53,52,343,2,42,143,42,42,45546,7564,21,313,1245,354,65,43,2,1,3414,12,654,214,1,2137,0,78643,56721346,64334,64,2343234,3434,45,312,0,24354,234,234235654,3435,234545,654,642,13,23,4,0,32424,2342,342434,2,34,2,4,43,2,23,42,42,12,243,3,2,24,267,5678,7,0,678,57,57,56,7765,35,654,67,857,685,7857,6,7353,466,47,657,8,5,7345,5435,24,245,24,5,36,5467,567,5,7565,7,567,57,5,342,23,423,5,647,567,578,876,8,6967,876,86,785,45,234,2,42545436,457,57,57,577856,54465,6,646,464567,0,23,254,68,87654,234,35785,42312,12341,48,99,6446344,21,2314,213,5345,32,0,546,5687655,2234532,556785,3442,2323,3234,23423456,35435345,3412,1,31,3232143,4,2434,234,2344,56,456,6778,98754,6784,56,54432,3482394,213,12351,213,13,0,13,123,13,4,2345,5,5466,67,7,5,6,57,67,57,0,7578,563,2,43,43,6,0,76,56,8,876,8,96,8,76,5,344523,42,4,65,5,44,2,42,4,25454,56,65,64,6,234,0,24,5634,6,7,6467,657,58,86,87,0,5,54,524,23,42,56,47,8,9,6,98,876,567,123,45,0,54,52,1235,453,46776786,87665,7,856,7,4,64,5,2367856,654535,3345345345,3534422,0,2331123,1313,13131,33,-1};

int getRandomInt(int rangeDown, int rangeUp)  //Returns a "random" int
{
  if(rangeDown > rangeUp)
  {
    kerror("Invalid random range (rD > rU)");
  }
  
  if(rangeDown < 0)
  {
    kerror("Invalid random range (rD < 0)");
  }
  
  startOver:
  
  if(i == 0)
  {
    if(getRawCmosSecond() != 0)
    {
      i = getRawCmosSecond();
    }
    else
    {
      i = 91;
    }
  }
  else
  {
    i++;
  }
  
  while(integers[i] < rangeDown || integers[i] > rangeUp)
  {
    i++;
    if(integers[i] == -1)
    {
      i = 0;
      goto startOver;
    }
  }
  
  return integers[i];
}
