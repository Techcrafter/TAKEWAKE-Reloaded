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

//Get input from devices (with input.c)

#ifndef INPUT_H
#define INPUT_H

#include "display.h"
#include "interface.h"
#include "system.h"
#include "types.h"

int mouseSupport;
int mouseDelay;
int mouseDoubleclick;

string readStr();  //Input of strings (keyboard)

string getNavigation();  //Get Arrow-Key Navigation (keyboard)

string pause();  //Pause until Escapekey or Enter is pressed (keyboard)

void activateMouse();  //Activates the mouse to send data (mouse)

void deactivateMouse();  //Deactivates the mouse to stop sending data (mouse)

void cursorMouse();  //Shows cursor that can be moved by the mouse (mouse)

void setMouseSupport(int state);  //Sets mouse support

int getMouseDelay();  //Gets mouse delay

void setMouseDelay(int value);  //Sets mouse delay

int getMouseDoubleclick();  //Gets if doubleclick is needed for mouse

void setMouseDoubleclick(int state);  //Set if doubleclick is needed for mouse

#endif
