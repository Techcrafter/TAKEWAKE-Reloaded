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

//Get input from devices (with input.h)

#include "input.h"

int mouseSupport = 0;
int mouseDelay = 3;
int mouseDoubleclick = 0;
int mouseCursorX = 39;
int mouseCursorY = 12;

string readStr(int limit)  //Input of strings (keyboard) (0 limit = no limit)
{
  string buffstr;
  int i = 0;
  uint8 reading = 1;
  uint8 shifted = 0;
  int layout = languagesGetKbLayout();  //0 = en, 1 = de
  
  showCursor();
  
  continueReading:
  
  while(reading && i < limit)  //Checks for reading and sets a limit to 60
  {
    if(inportb(0x64) & 0x1)
    {
      switch(inportb(0x60))
      {
        case 1:
          hideCursor();  //Escapekey (returns char 27 (ESC))
          return (char)27;
          break;
        case 2:
          if(shifted == 0)  //1
          {
            printCh('1');
            buffstr[i] = '1';
          }
          else
          {
            printCh('!');
            buffstr[i] = '!';
          }
          i++;
          break;
        case 3:
          if(shifted == 0)  //2
          {
            printCh('2');
            buffstr[i] = '2';
          }
          else
          {
            if(layout == 0)
            {
              printCh('@');
              buffstr[i] = '@';
            }
            else if(layout == 1)
            {
              printCh('"');
              buffstr[i] = '"';
            }
          }
          i++;
          break;
        case 4:
          if(shifted == 0)  //3
          {
            printCh('3');
            buffstr[i] = '3';
          }
          else
          {
            if(layout == 0)
            {
              printCh('#');
              buffstr[i] = '#';
            }
            else if(layout == 1)
            {
              printCh((char)245);
              buffstr[i] = (char)245;
            }
          }
          i++;
          break;
        case 5:
          if(shifted == 0)  //4
          {
            printCh('4');
            buffstr[i] = '4';
          }
          else
          {
            printCh('$');
            buffstr[i] = '$';
          }
          i++;
          break;
        case 6:
          if(shifted == 0)  //5
          {
            printCh('5');
            buffstr[i] = '5';
          }
          else
          {
            printCh('%');
            buffstr[i] = '%';
          }
          i++;
          break;
        case 7:
          if(shifted == 0)  //6
          {
            printCh('6');
            buffstr[i] = '6';
          }
          else
          {
            if(layout == 0)
            {
              printCh('^');
              buffstr[i] = '^';
            }
            else if(layout == 1)
            {
              printCh('&');
              buffstr[i] = '&';
            }
          }
          i++;
          break;
        case 8:
          if(shifted == 0)  //7
          {
            printCh('7');
            buffstr[i] = '7';
          }
          else
          {
            if(layout == 0)
            {
              printCh('&');
              buffstr[i] = '&';
            }
            else if(layout == 1)
            {
              printCh('/');
              buffstr[i] = '/';
            }
          }
          i++;
          break;
        case 9:
          if(shifted == 0)  //8
          {
            printCh('8');
            buffstr[i] = '8';
          }
          else
          {
            if(layout == 0)
            {
              printCh('*');
              buffstr[i] = '*';
            }
            else if(layout == 1)
            {
              printCh('(');
              buffstr[i] = '(';
            }
          }
          i++;
          break;
        case 10:
          if(shifted == 0)  //9
          {
            printCh('9');
            buffstr[i] = '9';
          }
          else
          {
            if(layout == 0)
            {
              printCh('(');
              buffstr[i] = '(';
            }
            else if(layout == 1)
            {
              printCh(')');
              buffstr[i] = ')';
            }
          }
          i++;
          break;
        case 11:
          if(shifted == 0)  //0
          {
            printCh('0');
            buffstr[i] = '0';
          }
          else
          {
            if(layout == 0)
            {
              printCh(')');
              buffstr[i] = ')';
            }
            else if(layout == 1)
            {
              printCh('=');
              buffstr[i] = '=';
            }
          }
          i++;
          break;
        case 12:
          if(shifted == 0)  //-
          {
            if(layout == 0)
            {
              printCh('-');
              buffstr[i] = '-';
            }
            else if(layout == 1)
            {
              printCh((char)225);
              buffstr[i] = (char)225;
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('_');
              buffstr[i] = '_';
            }
            else if(layout == 1)
            {
              printCh('?');
              buffstr[i] = '?';
            }
          }
          i++;
          break;
        case 13:
          if(shifted == 0)  //=
          {
            if(layout == 0)
            {
              printCh('=');
              buffstr[i] = '=';
            }
            else if(layout == 1)
            {
              printCh((char)239);
              buffstr[i] = (char)239;
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('+');
              buffstr[i] = '+';
            }
            else if(layout == 1)
            {
              printCh('`');
              buffstr[i] = '`';
            }
          }
          i++;
          break;
        case 14:
          if(i!=0)  //Back space
          {
            print("\b");
            i--;
            buffstr[i] = '\0';
          }
          break;
        case 15:
          hideCursor();  //Tabulator (returns char 9 (HT))
          return (char)9;
          break;
        case 16:
          if(shifted == 0)  //q
          {
            printCh('q');
            buffstr[i] = 'q';
          }
          else
          {
            printCh('Q');
            buffstr[i] = 'Q';
          }
          i++;
          break;
        case 17:
          if(shifted == 0)  //w
          {
            printCh('w');
            buffstr[i] = 'w';
          }
          else
          {
            printCh('W');
            buffstr[i] = 'W';
          }
          i++;
          break;
        case 18:
          if(shifted == 0)  //e
          {
            printCh('e');
            buffstr[i] = 'e';
          }
          else
          {
            printCh('E');
            buffstr[i] = 'E';
          }
          i++;
          break;
        case 19:
          if(shifted == 0)  //r
          {
            printCh('r');
            buffstr[i] = 'r';
          }
          else
          {
            printCh('R');
            buffstr[i] = 'R';
          }
          i++;
          break;
        case 20:
          if(shifted == 0)  //t
          {
            printCh('t');
            buffstr[i] = 't';
          }
          else
          {
            printCh('T');
            buffstr[i] = 'T';
          }
          i++;
          break;
        case 21:
          if(shifted == 0)  //y
          {
            if(layout == 0)
            {
              printCh('y');
              buffstr[i] = 'y';
            }
            else if(layout == 1)
            {
              printCh('z');
              buffstr[i] = 'z';
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('Y');
              buffstr[i] = 'Y';
            }
            else if(layout == 1)
            {
              printCh('Z');
              buffstr[i] = 'Z';
            }
          }
          i++;
          break;
        case 22:
          if(shifted == 0)  //u
          {
            printCh('u');
            buffstr[i] = 'u';
          }
          else
          {
            printCh('U');
            buffstr[i] = 'U';
          }
          i++;
          break;
        case 23:
          if(shifted == 0)  //i
          {
            printCh('i');
            buffstr[i] = 'i';
          }
          else
          {
            printCh('I');
            buffstr[i] = 'I';
          }
          i++;
          break;
        case 24:
          if(shifted == 0)  //o
          {
            printCh('o');
            buffstr[i] = 'o';
          }
          else
          {
            printCh('O');
            buffstr[i] = 'O';
          }
          i++;
          break;
        case 25:
          if(shifted == 0)  //p
          {
            printCh('p');
            buffstr[i] = 'p';
          }
          else
          {
            printCh('P');
            buffstr[i] = 'P';
          }
          i++;
          break;
        case 26:
          if(shifted == 0)  //[
          {
            if(layout == 0)
            {
              printCh('[');
              buffstr[i] = '[';
            }
            else if(layout == 1)
            {
              printCh((char)129);
              buffstr[i] = (char)129;
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('{');
              buffstr[i] = '{';
            }
            else if(layout == 1)
            {
              printCh((char)154);
              buffstr[i] = (char)154;
            }
          }
          i++;
          break;
        case 27:
          if(shifted == 0)  //]
          {
            if(layout == 0)
            {
              printCh(']');
              buffstr[i] = ']';
            }
            else if(layout == 1)
            {
              printCh('+');
              buffstr[i] = '+';
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('}');
              buffstr[i] = '}';
            }
            else if(layout == 1)
            {
              printCh('*');
              buffstr[i] = '*';
            }
          }
          i++;
          break;
        case 28:
        //printCh('\n');  //Enter
        //buffstr[i] = '\n';
        //i++;
          buffstr[i] = '\0';
          i++;
          buffstr[i] = '\0';
          i++;
          buffstr[i] = '\0';
          i++;
          reading = 0;
          break;
      /*case 29:
          printCh('C');  //Ctrl-left
          buffstr[i] = 'C';
          i++;
          break;*/
        case 30:
          if(shifted == 0)  //a
          {
            printCh('a');
            buffstr[i] = 'a';
          }
          else
          {
            printCh('A');
            buffstr[i] = 'A';
          }
          i++;
          break;
        case 31:
          if(shifted == 0)  //s
          {
            printCh('s');
            buffstr[i] = 's';
          }
          else
          {
            printCh('S');
            buffstr[i] = 'S';
          }
          i++;
          break;
        case 32:
          if(shifted == 0)  //d
          {
            printCh('d');
            buffstr[i] = 'd';
          }
          else
          {
            printCh('D');
            buffstr[i] = 'D';
          }
          i++;
          break;
        case 33:
          if(shifted == 0)  //f
          {
            printCh('f');
            buffstr[i] = 'f';
          }
          else
          {
            printCh('F');
            buffstr[i] = 'F';
          }
          i++;
          break;
        case 34:
          if(shifted == 0)  //g
          {
            printCh('g');
            buffstr[i] = 'g';
          }
          else
          {
            printCh('G');
            buffstr[i] = 'G';
          }
          i++;
          break;
        case 35:
          if(shifted == 0)  //h
          {
            printCh('h');
            buffstr[i] = 'h';
          }
          else
          {
            printCh('H');
            buffstr[i] = 'H';
          }
          i++;
          break;
        case 36:
          if(shifted == 0)  //j
          {
            printCh('j');
            buffstr[i] = 'j';
          }
          else
          {
            printCh('J');
            buffstr[i] = 'J';
          }
          i++;
          break;
        case 37:
          if(shifted == 0)  //k
          {
            printCh('k');
            buffstr[i] = 'k';
          }
          else
          {
            printCh('K');
            buffstr[i] = 'K';
          }
          i++;
          break;
        case 38:
          if(shifted == 0)  //l
          {
            printCh('l');
            buffstr[i] = 'l';
          }
          else
          {
            printCh('L');
            buffstr[i] = 'L';
          }
          i++;
          break;
        case 39:
          if(shifted == 0)  //;
          {
            if(layout == 0)
            {
              printCh(';');
              buffstr[i] = ';';
            }
            else if(layout == 1)
            {
              printCh((char)148);
              buffstr[i] = (char)148;
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh(':');
              buffstr[i] = ':';
            }
            else if(layout == 1)
            {
              printCh((char)153);
              buffstr[i] = (char)153;
            }
          }
          i++;
          break;
        case 40:
          if(shifted == 0)  //'
          {
            if(layout == 0)
            {
              printCh((char)39);
              buffstr[i] = (char)39;
            }
            else if(layout == 1)
            {
              printCh((char)132);
              buffstr[i] = (char)132;
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('"');
              buffstr[i] = '"';
            }
            else if(layout == 1)
            {
              printCh((char)142);
              buffstr[i] = (char)142;
            }
          }
          i++;
          break;
        case 41:
          if(shifted == 0)  //`
          {
            if(layout == 0)
            {
              printCh('`');
              buffstr[i] = '`';
            }
            else if(layout == 1)
            {
              printCh('^');
              buffstr[i] = '^';
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('~');
              buffstr[i] = '~';
            }
            else if(layout == 1)
            {
              printCh((char)167);
              buffstr[i] = (char)167;
            }
          }
          i++;
          break;
        case 42:
          if(shifted == 0)  //Shift-left
          {
            shifted = 1;
          }
          else
          {
            shifted = 0;
          }
          break;
        case 43:
          if(shifted == 0)  //[BACKSLASH]
          {
            if(layout == 0)
            {
              printCh((char)92);
              buffstr[i] = (char)92;
            }
            else if(layout == 1)
            {
              printCh('#');
              buffstr[i] = '#';
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('|');
              buffstr[i] = '|';
            }
            else if(layout == 1)
            {
              printCh((char)39);
              buffstr[i] = (char)39;
            }
          }
          i++;
          break;
        case 44:
          if(shifted == 0)  //z
          {
            if(layout == 0)
            {
              printCh('z');
              buffstr[i] = 'z';
            }
            else if(layout == 1)
            {
              printCh('y');
              buffstr[i] = 'y';
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('Z');
              buffstr[i] = 'Z';
            }
            else if(layout == 1)
            {
              printCh('Y');
              buffstr[i] = 'Y';
            }
          }
          i++;
          break;
        case 45:
          if(shifted == 0)  //x
          {
            printCh('x');
            buffstr[i] = 'x';
          }
          else
          {
            printCh('X');
            buffstr[i] = 'X';
          }
          i++;
          break;
        case 46:
          if(shifted == 0)  //c
          {
            printCh('c');
            buffstr[i] = 'c';
          }
          else
          {
            printCh('C');
            buffstr[i] = 'C';
          }
          i++;
          break;
        case 47:
          if(shifted == 0)  //v
          {
            printCh('v');
            buffstr[i] = 'v';
          }
          else
          {
            printCh('V');
            buffstr[i] = 'V';
          }
          i++;
          break;
        case 48:
          if(shifted == 0)  //b
          {
            printCh('b');
            buffstr[i] = 'b';
          }
          else
          {
            printCh('B');
            buffstr[i] = 'B';
          }
          i++;
          break;
        case 49:
          if(shifted == 0)  //n
          {
            printCh('n');
            buffstr[i] = 'n';
          }
          else
          {
            printCh('N');
            buffstr[i] = 'N';
          }
          i++;
          break;
        case 50:
          if(shifted == 0)  //m
          {
            printCh('m');
            buffstr[i] = 'm';
          }
          else
          {
            printCh('M');
            buffstr[i] = 'M';
          }
          i++;
          break;
        case 51:
          if(shifted == 0)  //,
          {
            printCh(',');
            buffstr[i] = ',';
          }
          else
          {
            if(layout == 0)
            {
              printCh('<');
              buffstr[i] = '<';
            }
            else if(layout == 1)
            {
              printCh(';');
              buffstr[i] = ';';
            }
          }
          i++;
          break;
        case 52:
          if(shifted == 0)  //.
          {
            printCh('.');
            buffstr[i] = '.';
          }
          else
          {
            if(layout == 0)
            {
              printCh('>');
              buffstr[i] = '>';
            }
            else if(layout == 1)
            {
              printCh(':');
              buffstr[i] = ':';
            }
          }
          i++;
          break;
        case 53:
          if(shifted == 0)  //[SLASH]
          {
            if(layout == 0)
            {
              printCh('/');
              buffstr[i] = '/';
            }
            else if(layout == 1)
            {
              printCh('-');
              buffstr[i] = '-';
            }
          }
          else
          {
            if(layout == 0)
            {
              printCh('?');
              buffstr[i] = '?';
            }
            else if(layout == 1)
            {
              printCh('_');
              buffstr[i] = '_';
            }
          }
          i++;
          break;
        case 54:
          if(shifted == 0)  //Shift-right
          {
            shifted = 1;
          }
          else
          {
            shifted = 0;
          }
          break;
        case 55:
          printCh('*');  //Numblock *
          buffstr[i] = '*';
          i++;
          break;
        /*case 56:
          printCh('A');  //Alt (Gr)
          buffstr[i] = 'A';
          i++;
          break;*/
        case 57:
          printCh(' ');  //Space
          buffstr[i] = ' ';
          i++;
          break;
        case 58:
          if(shifted == 0)  //Capslock
          {
            shifted = 1;
          }
          else
          {
            shifted = 0;
          }
          break;
      /*case 59:
          printCh('F');  //F1
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 60:
          printCh('F');  //F2
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 61:
          printCh('F');  //F3
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 62:
          printCh('F');  //F4
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 63:
          printCh('F');  //F5
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 64:
          printCh('F');  //F6
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 65:
          printCh('F');  //F7
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 66:
          printCh('F');  //F8
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 67:
          printCh('F');  //F9
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 68:
          printCh('F');  //F10
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 69:
          printCh('F');  //F11
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 70:
          printCh('F');  //F12
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 71:
          printCh('P');  //Pos 1
          buffstr[i] = 'P';
          i++;
          break;*/
      /*case 72:
          printCh('U');  //Up
          buffstr[i] = 'U';
          i++;
          break;*/
      /*case 73:
          break;  //Page-up*/
        case 74:
          printCh('-');  //Numblock -
          buffstr[i] = '-';
          i++;
          break;
        case 75:
          if(i!=0)
          {
            minusCursorX();  //Left
            i--;
          }
          break;
      /*case 76:
          printCh('5');  //Numblock 5
          buffstr[i] = '5';
          i++;
          break;*/
        case 77:
          plusCursorX();  //Right
          i++;
          break;
        case 78:
          printCh('+');  //Numblock +
          buffstr[i] = '+';
          i++;
          break;
      /*case 79:
          printCh('E');  //End
          buffstr[i] = 'E';
          i++;
          break;*/
      /*case 80:
          printCh('D');  //Down
          buffstr[i] = 'D';
          i++;
          break;*/
      /*case 81:
          ScrollUp(1);  //Page-Down
          break;*/
      /*case 82:
          printCh('P');  //Paste
          buffstr[i] = 'P';
          i++;
          break;*/
      /*case 83:
          printCh('D');  //Delete
          buffstr[i] = 'D';
          i++;
          break;*/
      }
    }
  }

  while(reading && i == limit)  //Delete and Enter must even work with full limit
  {
    if(inportb(0x64) & 0x1)
    {
      switch(inportb(0x60))
      {
        case 1:
          return (char)27;  //Escapekey (returns char 27 (ESC))
          break;
        case 14:
          if(i!=0)  //Back space
          {
            print("\b");
            i--;
            buffstr[i] = '\0';
          }
          break;
        case 28:
        //printCh('\n');  //Enter
        //buffstr[i] = '\n';
        //i++;
          buffstr[i] = '\0';
          i++;
          buffstr[i] = '\0';
          i++;
          buffstr[i] = '\0';
          i++;
          reading = 0;
          break;
        case 75:
          if(i!=0)
          {
            minusCursorX();  //Left
            i--;
          }
          break;
      } 
    }
  }
  
  if(reading == 1)
  {
    goto continueReading;  //Jump to begin
  }
  
  hideCursor();
  return buffstr;
}

string getNavigation(int cycles)  //Get Arrow-Key Navigation (keyboard) (0 cycles = wait for key)
{
  int cycle = 0;
  
  if(cycles == 0)
  {
    cycle = 1;
  }
  
  while(cycle != cycles)
  {
    if(cycles != 0)
    {
      cycle++;
    }
    if(inportb(0x64) & 0x1)
    {
      switch(inportb(0x60))
      {
        case 1:
          return (char)27;  //Escapekey (returns char 27 (ESC))
          break;
        case 28:
          return "enter";  //Enter (returns 'enter')
          break;
        case 57:
          return "space";  //Space (returns 'space')
          break;
        case 72:
          return "up";  //Up (returns 'up')
          break;
        case 75:
          return "left";  //Left (returns 'left')
          break;
        case 77:
          return "right";  //Right (returns 'right')
          break;
        case 80:
          return "down";  //Down (returns 'down')
          break;
      }
    }
  }
}

string pause()  //Pause until Escapekey or Enter is pressed (keyboard)
{
  while(1)
  {
    if(inportb(0x64) & 0x1)
    {
      switch(inportb(0x60))
      {
        case 1:
          return (char)27;  //Escapekey (returns char 27 (ESC))
          break;
        case 28:
          return "enter";  //Enter (returns 'enter')
          break;
      }
    }
  }
}

void activateMouse()  //Activates the mouse to send data (mouse)
{
  if(mouseSupport == 0)
  {
    showInfobox(languagesGetString(46), languagesGetString(47), 1, 1, 1);
    mouseSettings();
    shell();
  }
  outportb(0x64, 0xA8);  //Activate input by mouse
  outportb(0x64, 0x20);  //Prepare command byte
  outportb(0x64, 0xD4);  //Tells the keyboard controller to send information to the mouse
  outportb(0x60, 0xF4);  //Tells the mouse to start sending data
}

void deactivateMouse()  //Deactivates the mouse to stop sending data (mouse)
{
  outportb(0x64, 0xD4);  //Tells the keyboard controller to send information to the mouse
  outportb(0x60, 0xF5);  //Tells the mouse to stop sending data
}

int cursorMouse(int cycles)  //Shows cursor that can be moved by the mouse (mouse) (0 cycles = wait for leftclick)
{
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int n4 = 0;
  int n5a = 0;
  int n5b = 0;
  int cycle = 0;

  if(cycles == 0)
  {
    cycle = 1;
  }
  
  activateMouse();
  
  setCursorX(mouseCursorX);
  setCursorY(mouseCursorY);
  showCursor();
  
  while(cycle != cycles)
  {
    if(cycles != 0)
    {
      cycle++;
    }
    
    if(inportb(0x64) & 0x1)
    {
      uint32 value = inportb(0x60);
      value &= (uint32)0xFF;
      
      if(value == 24)  //Up (1)
      {
        n1++;
        if(n1 == mouseDelay)
        {
          n1 = 0;
          minusCursorY();
        }
        n5a = 0;
        n5b = 0;
      }
      else if(value == 40)  //Down (2)
      {
        n2++;
        if(n2 == mouseDelay)
        {
          n2 = 0;
          plusCursorY();
        }
        n5a = 0;
        n5b = 0;
      }
      else if(value == 56)  //Left (3)
      {
        n3++;
        if(n3 == mouseDelay)
        {
          n3 = 0;
          minusCursorX();
        }
        n5a = 0;
        n5b = 0;
      }
      else if(value == 8 && n5a != 3)  //Right (4)
      {
        n4++;
        if(n4 == mouseDelay)
        {
          n4 = 0;
          plusCursorX();
        }
        n5a = 0;
        n5b = 0;
      }
      else if(value == 9 && n5a == 0)  //Leftclick 1 (5)
      {
        n5a++;
      }
      else if(value == 0 && n5a == 1)  //Leftclick 2 (5)
      {
        n5a++;
      }
      else if(value == 0 && n5a == 2)  //Leftclick 3 (5)
      {
        n5a++;
      }
      else if(value == 8 && n5a == 3)  //Leftclick 4 (5)
      {
        n5a++;
      }
      else if(value == 0 && n5a == 4)  //Leftclick 5 (5)
      {
        n5a++;
      }
      else if(value == 0 && n5a == 5)  //Leftclick 6 (5)
      {
        if(n5b == mouseDoubleclick)
        {
          deactivateMouse();
          hideCursor();
          mouseCursorX = getCursorX();
          mouseCursorY = getCursorY();
          return;
        }
        else
        {
          n5a = 0;
          n5b++;
        }
      }
      else  //Reset
      {
        n5a = 0;
        n5b = 0;
      }
    }
  }
  
  deactivateMouse();
  hideCursor();
  mouseCursorX = getCursorX();
  mouseCursorY = getCursorY();
  
  return -1;
}

int getMouseSupport()  //Gets mouse support
{
  return mouseSupport;
}

void setMouseSupport(int value)  //Sets mouse support
{
  mouseSupport = value;
}

int getMouseDelay()  //Gets mouse delay
{
  return mouseDelay;
}

void setMouseDelay(int value)  //Sets mouse delay
{
  mouseDelay = value;
}

int getMouseDoubleclick()  //Gets if doubleclick is needed for mouse
{
  return mouseDoubleclick;
}

void setMouseDoubleclick(int value)  //Set if doubleclick is needed for mouse
{
  mouseDoubleclick = value;
}
