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

//Print and deleted text on screen (with display.c)

#ifndef DISPLAY_H
#define DISPLAY_H

#include "string.h"
#include "system.h"
#include "types.h"

int cursorX, cursorY;  //Cursor X and Y position
const uint8 sw, sh, sd;  //Defining screen width, high and depth
int color;  //Actual color

int whiteBgSupport;  //White Background support state

void clearLine(uint8 from, uint8 to);  //Clears certain lines of the display

void updateCursor();  //Updates the current cursorposition

void showCursor();  //Starts showing cursor on screen

void hideCursor();  //Starts hiding cursor on screen

void clear();  //Clears the entire screen

void ScrollUp(uint8 lineNumber);  //Scrolls up the screen

void newLineCheck();  //Checks if new line is needed

void printch(char c);  //Prints a char

void print(string ch);  //Prints a text

void printColored(string ch, int textColor, int bgColor);  //Prints colored text

void setColor(int textColor, int bgColor);  //Sets text and background color

void setColorcode(int colorcode);  //Sets colorvariable by colorcode

int getColor();  //Gets color variable

void setWhiteBgSupport(int newWhiteBgSupport);  //Sets white Background support state (some graphic card's/adapters didn't support this feature)

int getCursorX();  //Returns cursorX

int getCursorY();  //Returns cursorY

void setCursorX(uint8 newCursorX);  //Sets X-cursorposition

void setCursorY(uint8 newCursorY);  //Sets Y-cursorposition

void plusCursorX();  //Sets cursorX plus one position

void minusCursorX();  //Sets cursorX minus one position

void plusCursorY();  //Sets cursorY plus one position

void minusCursorY();  //Sets cursorY minus one position

void drawBox(int x, int y, int xSize, int ySize, int style);  //Draws a box for a button or something else

void setAutoScroll(int value);  //Enables/Disables auto scroll

#endif
