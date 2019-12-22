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

//Print and deleted text on screen (with display.h)

#include "display.h"

int cursorX = 0, cursorY = 0;  //Cursor X and Y position
const uint8 sw = 80, sh = 25, sd = 2;  //Defining screen width, high and depth
int autoScroll = 0;  //Auto scroll activated/deactivated
int color = 0x0F;  //Actual color

int whiteBgSupport = 0;

void clearLine(uint8 from, uint8 to)  //Clears certain lines of the display
{
  uint16 i = sw * from * sd;
  string vidmem=(string)0xb8000;
  
  for(i; i<(sw*(to+1)*sd);i++)
  {
    vidmem[(i/2)*2+1] = color;
    vidmem[(i/2)*2] = 0;
  }
}

void updateCursor()  //Updates the current cursorposition
{
  unsigned temp;

  temp = cursorY * sw + cursorX;  //Position is y*width+x
  
  outportb(0x3D4, 14);  //CRT Controll Register: Select cursorposition
  outportb(0x3D5, temp >> 8);  //Send maxbyte to bus
  outportb(0x3D4, 15);  //CRT Controll Register: Select lowbyte
  outportb(0x3D5, temp);  //Send lowbyte to bus
}

void showCursor()  //Starts showing cursor on screen
{
  outportb(0x3D4, 0x0A);
  outportb(0x3D5, (inportb(0x3D5) & 0xC0) | 0);
  
  outportb(0x3D4, 0x0B);
  outportb(0x3D5, (inportb(0x3D5) & 0xE0) | sw);
}

void hideCursor()  //Starts hiding cursor on screen
{
  outportb(0x3D4, 0x0A);
  outportb(0x3D5, 0x20);
}

void clear()  //Clears the entire screen
{
  clearLine(0, sh-1);
  cursorX = 0;
  cursorY = 0;
  updateCursor();
}

void ScrollUp(uint8 lineNumber)  //Scrolls up the screen
{
  string vidmem = (string)0xb8000;
  uint16 i = 0;
  
  for(i; i<sw*(sh-1)*2;i++)
  {
    vidmem[i] = vidmem[i+sw*2*lineNumber];
  }
  
  clearLine(sh-1-lineNumber,sh-1);
  
  if((cursorY - lineNumber) < 0)
  {
    cursorX = 0;
    cursorY = 0;
  }
  else
  {
    cursorY -= lineNumber;
  }
  
  updateCursor();
}

void newLineCheck()  //Checks if new line is needed
{
  if(cursorY >= sh-1 && autoScroll == 1)
  {
    ScrollUp(1);
  }
}

void printCh(char c)  //Prints a char
{
  string vidmem = (string)0xb8000;
  switch(c)
  {
    case(0x08):
      if(cursorX > 0)
      {
        cursorX--;
        vidmem[(cursorY*sw+cursorX)*sd]=0;
      }
      break;
    
    case(0x09):
      cursorX = (cursorX+8) & ~(8 - 1);
      break;
    
    case('\r'):
      cursorX = 0;
      break;
    
    case('\n'):
      cursorX = 0;
      cursorY++;
      break;
  
    default:
      vidmem [((cursorY*sw+cursorX))*sd] = c;
      vidmem [((cursorY*sw+cursorX))*sd+1] = color;
      cursorX++;
      break;
  }
  
  if(cursorX >= sw)
  {
    cursorX = 0;
    cursorY++;
  }
  
  newLineCheck();
  updateCursor();
}

void printMultipleCh(char c, int count)
{
  int i = 0;
  
  while(i != count)
  {
    printCh(c);
    i++;
  }
}

void print(string ch)  //Prints a text
{
  uint16 i = 0;
  uint8 length = strlength(ch);  //Saves the stringlength into a variable for calling the function only once
  
  for(i;i<length;i++)
  {
    printCh(ch[i]);
  }
}

void printColored(string ch, int textColor, int bgColor)  //Prints colored text
{
  int currentColor = color;
  setColor(textColor, bgColor);
  print(ch);
  setColorcode(currentColor);
}

void setColor(int textColor, int bgColor)  //Sets text and background color
{
  if(bgColor == 15 && whiteBgSupport == 0)
  {
    bgColor = 7;
  }
  else if(bgColor == 8 && whiteBgSupport == 0)
  {
    bgColor = 0;
  }
  color = (bgColor << 4) | textColor;
}

void setColorcode(int colorcode)  //Sets colorvariable by colorcode
{
  color = colorcode;
}

int getColor()  //Gets color variable
{
  return color;
}

void setWhiteBgSupport(int newWhiteBgSupport)  //Sets white Background support state (some graphic card's/adapters didn't support this feature)
{
  whiteBgSupport = newWhiteBgSupport;
}

int getCursorX()  //Returns cursorX
{
  return cursorX;
}

int getCursorY()  //Returns cursorY
{
  return cursorY;
}

void setCursorX(uint8 newCursorX)  //Sets X-cursorposition
{
  cursorX = newCursorX;
  updateCursor();
}

void setCursorY(uint8 newCursorY)  //Sets Y-cursorposition
{
  cursorY = newCursorY;
  updateCursor();
}

void plusCursorX()  //Sets cursorX plus one position
{
  if(cursorX != 79)
  {
    cursorX++;
  }
  updateCursor();
}

void minusCursorX()  //Sets cursorX minus one position
{
  if(cursorX != 0)
  {
    cursorX--;
  }
  updateCursor();
}

void plusCursorY()  //Sets cursorY plus one position
{
  if(cursorY != 24)
  {
    cursorY++;
  }
  updateCursor();
}

void minusCursorY()  //Sets cursorY minus one position
{
  if(cursorY != 0)
  {
    cursorY--;
  }
  updateCursor();
}

void setAutoScroll(int value)  //Enables/Disables auto scroll
{
  autoScroll = value;
}
