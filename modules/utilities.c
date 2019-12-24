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

//Utilities for Memorymanagement and other things (with utilities.h)

#include "utilities.h"

void memory_copy(char *source, char *dest, int nbytes)  //Copys data inside the memory
{
  int i;
  for(i = 0; i < nbytes; i++)
  {
    *(dest +i) = *(source + i);
  }
}

void memory_set(uint8 *dest, uint8 val, uint32 len)  //Writes data into the memory
{
  uint8 *temp = (uint8 *)dest;
  for( ; len != 0 ; len--) *temp++ = val;
}

void int_to_ascii(int n, char str[])  //Converts int to ascii
{
  int i, sign;
  if ((sign = n)<0) n = -n;
  i = 0;
  do
  {
    str[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  
  if (sign < 0) str[i++] = '-';
  str[i] = '\0';

  return str;
}

string int_to_str(int n)  //Converts int to string
{
  string ch = malloc(50);
  int_to_ascii(n, ch);
  int len = strLength(ch);
  int i = 0;
  int j = len -1;
  
  while(i<(len/2 + len%2))
  {
    char tmp = ch[i];
    ch[i] = ch[j];
    ch[j] = tmp;
    i++;
    j--;
  }
  
  return ch;
}

int str_to_int(string ch)  //Converts string to int
{
  int n = 0;
  int p = 1;
  int strlen = strLength(ch);
  int i;
  for(i = strlen-1;i>=0;i--)
  {
    n += ((int)(ch[i] - '0')) * p;
    p *= 10;
  }
  return n;
}

void * malloc(int nbytes)
{
  char variable[nbytes];
  return &variable;
}
