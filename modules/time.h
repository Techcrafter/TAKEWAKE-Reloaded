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

#ifndef TIME_H
#define TIME_H

#include "system.h"
#include "types.h"

int getRawCmosSecond();  //Gets actual raw second from CMOS

int getCmosSecond();  //Gets actual second from CMOS

int getCmosMinute();  //Gets actual minute from CMOS

int getCmosHour();  //Gets actual hour from CMOS

int getCmosDay();  //Gets actual day from CMOS

int getCmosMonth();  //Gets actual month from CMOS

int getCmosYear();  //Gets actual year from CMOS

void wait(int secondsToWait);  //Waits a specific time in seconds (maximum is 59)

#endif
