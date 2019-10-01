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

//Plays sound (with sound.h)

#include "sound.h"

void playTone(int frequence)  //Play tone using built in speaker
{
  int division;
  uint8 temp;
  
  //Set PIT to frequency
  division = 1193180 / frequence;
  outportb(0x43, 0xb6);
  outportb(0x42, (uint8)(division));
  outportb(0x42, (uint8)(division >> 8));
  
  //Play tone
  temp = inportb(0x61);
  if(temp != (temp | 3))
  {
    outportb(0x61, temp | 3);
  }
}

void stopTone()  //Stops built in speaker from playing tones
{
  uint8 temp = inportb(0x61) & 0xFC;
  outportb(0x61, temp);
}

void playToneForSec(int frequence, int seconds)  //plays a tone using built in speaker for X seconds
{
  playTone(frequence);
  wait(seconds);
  stopTone();
}

void beep()  //Plays a simple beep using built in speaker
{
  playToneForSec(1200, 1);
  stopTone();
}
