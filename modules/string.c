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

//Functions with strings (with string.h)

#include "string.h"

uint16 strLength(string ch)  //Returns the length of a string
{
  uint16 i = 0;
  while(ch[i++]);
  return i - 1;
}

uint8 strEquals(string ch1, string ch2)  //Checks if two strings are the same
{
  uint8 result = 1;
  uint8 size = strLength(ch1);
  if(size != strLength(ch2))
  {
    result = 0;
  }
  else
  {
    uint8 i = 0;
    for(i;i<=size;i++)
    {
      if(ch1[i] != ch2[i])
      {
        result = 0;
      }
    }
  }
  
  return result;
}
