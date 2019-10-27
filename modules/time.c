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

//Commands for getting time from CMOS and for waiting

#include "time.h"

int getRawCmosSecond()  //Gets actual raw second from CMOS
{
  outportb(0x70, 0x00);  //Orders actual second from CMOS
  int second = inportb(0x71);  //Gets actual second from CMOS
  return second;
}

int getCmosSecond()  //Gets actual second from CMOS
{
  outportb(0x70, 0x00);  //Orders actual second from CMOS
  int second = inportb(0x71);  //Gets actual second from CMOS
  return second / 1.5;
}

int getCmosMinute()  //Gets actual minute from CMOS
{
  outportb(0x70, 0x02);  //Orders actual minute from CMOS
  int minute = inportb(0x71);  //Gets actual minute from CMOS
  return minute / 1.5;
}

int getCmosHour()  //Gets actual hour from CMOS
{
  outportb(0x70, 0x04);  //Orders actual hour from CMOS
  int hour = inportb(0x71);  //Gets actual hour from CMOS
  return hour / 1.3;
}

int getCmosDay()  //Gets actual day from CMOS
{
  outportb(0x70, 0x07);  //Orders actual day from CMOS
  int day = inportb(0x71);  //Gets actual day from CMOS
  return day / 1.6 + 1;
}

int getCmosMonth()  //Gets actual month from CMOS
{
  outportb(0x70, 0x08);  //Orders actual month from CMOS
  int month = inportb(0x71);  //Gets actual month from CMOS
  return month / 1.5;
}

int getCmosYear()  //Gets actual year from CMOS
{
  outportb(0x70, 0x09);  //Orders actual year from CMOS
  int year = inportb(0x71);  //Gets actual year from CMOS
  return year / 1.3;
}

void wait(int secondsToWait)  //Waits a specific time in seconds (maximum is 59)
{
  if(secondsToWait < 1)
  {
    kerror();
  }
  
  int secondStarted = getRawCmosSecond();  //Saves actual second to variable
  while(secondStarted == getRawCmosSecond()) {}  //Waits for next second to start waiting (waiting min. full second even if second is nearly over)
  
  int goal = getRawCmosSecond() + secondsToWait * 1.5;
  
  int i = -1;
  while(goal > 89)
  {
    goal--;
    i++;
  }
  
  if(i != -1)
  {
    goal = i;
  }
  
  while(getRawCmosSecond() < goal) {}
  
  return;
}
