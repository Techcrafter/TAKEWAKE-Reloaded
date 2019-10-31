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

//Manager for interface elements (like buttons) (with interface.c)

#ifndef INTERFACE_H
#define INTERFACE_H

#include "display.h"
#include "types.h"

int selection;
string input;

//Prepare interface variables for up to 20 buttons
int unselTxtCl;
int unselBgCl;
int selTxtCl;
int selBgCl;

int button1;
int button1X;
int button1Y;
int button1SizeX;
int button1SizeY;
string button1Text;

int button2;
int button2X;
int button2Y;
int button2SizeX;
int button2SizeY;
string button2Text;

int button3;
int button3X;
int button3Y;
int button3SizeX;
int button3SizeY;
string button3Text;

int button4;
int button4X;
int button4Y;
int button4SizeX;
int button4SizeY;
string button4Text;

int button5;
int button5X;
int button5Y;
int button5SizeX;
int button5SizeY;
string button5Text;

int button6;
int button6X;
int button6Y;
int button6SizeX;
int button6SizeY;
string button6Text;

int button7;
int button7X;
int button7Y;
int button7SizeX;
int button7SizeY;
string button7Text;

int button8;
int button8X;
int button8Y;
int button8SizeX;
int button8SizeY;
string button8Text;

int button9;
int button9X;
int button9Y;
int button9SizeX;
int button9SizeY;
string button9Text;

int button10;
int button10X;
int button10Y;
int button10SizeX;
int button10SizeY;
string button10Text;

int button11;
int button11X;
int button11Y;
int button11SizeX;
int button11SizeY;
string button11Text;

int button12;
int button12X;
int button12Y;
int button12SizeX;
int button12SizeY;
string button12Text;

int button13;
int button13X;
int button13Y;
int button13SizeX;
int button13SizeY;
string button13Text;

int button14;
int button14X;
int button14Y;
int button14SizeX;
int button14SizeY;
string button14Text;

int button15;
int button15X;
int button15Y;
int button15SizeX;
int button15SizeY;
string button15Text;

int button16;
int button16X;
int button16Y;
int button16SizeX;
int button16SizeY;
string button16Text;

int button17;
int button17X;
int button17Y;
int button17SizeX;
int button17SizeY;
string button17Text;

int button18;
int button18X;
int button18Y;
int button18SizeX;
int button18SizeY;
string button18Text;

int button19;
int button19X;
int button19Y;
int button19SizeX;
int button19SizeY;
string button19Text;

int button20;
int button20X;
int button20Y;
int button20SizeX;
int button20SizeY;
string button20Text;

void newInterface(int unselectedTextColor, int unselectedBackgroundColor, int selectedTextColor, int selectedBackgroundColor);  //Prepares for a new interface

void addButton(int id, int posX, int posY, int sizeX, int sizeY, string text);  //Adds a new button to the interface

int runInterface(int navType, int ableToQuit);  //Runs the interface with the specified navigation type (1 = up and down | 2 = left and right | 3 = up, down, left and right)

int showInfobox(string title, string text, int type, int preselected, int navType);  //Shows an infobox and returns the selection (type1 = ok | type2 = yes,no) (navType1 = keyboard | navType2 = mouse)

void drawBox(int x, int y, int xSize, int ySize, int style);  //Draws a box for a button or something else (style1 = 1 line, style2 = 2 lines)

void newWindow(string title, int ableToClose, int style);  //Overwrites screen with a new window form (style1 = 1 line, style2 = 2 lines)

#endif
