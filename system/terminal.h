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

//OS-terminal (with terminal.c)

#ifndef TERMINAL_H
#define TERMINAL_H

//Including the modules
#include "../modules/display.h"
#include "../modules/input.h"
#include "../modules/random.h"
#include "../modules/sound.h"
#include "../modules/string.h"
#include "../modules/system.h"
#include "../modules/types.h"
#include "../modules/utilities.h"

string input;

void terminalMain();  //Terminal-mainfunction

void terminalHelp();  //Terminal-help

void terminalAscii();  //Displays a specified ascii symbol

void terminalTestInfobox();  //Displays an infobox with customized type and preselection

void terminalSetLanguage(); //Sets the systemlanguage to an int

void terminalGetTime();  //Prints the current time from CMOS in HH/MM/SS format

void terminalGetDate();  //Prints the current date from CMOS in DD/MM/YY format

void terminalPlayTone();  //Plays a tone with a specified frequence for 3 seconds

void terminalMouse();  //Demonstration of mouse functionality

void terminalRandom();  //Generates a random int based on a specified range

#endif
