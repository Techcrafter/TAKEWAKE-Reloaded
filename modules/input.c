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

string readStr()  //Input of strings (keyboard)
{
  char buff;
  string buffstr;
  uint8 i = 0;
  uint8 reading = 1;
  uint8 shifted = 0;
  int layout = languagesGetKbLayout();  //0 = en, 1 = de
  
  showCursor();
  
  continueReading:
  
  while(reading && i < 60)  //Checks for reading and sets a limit to 60
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
            printch('1');
            buffstr[i] = '1';
          }
          else
          {
            printch('!');
            buffstr[i] = '!';
          }
          i++;
          break;
        case 3:
          if(shifted == 0)  //2
          {
            printch('2');
            buffstr[i] = '2';
          }
          else
          {
            if(layout == 0)
            {
              printch('@');
              buffstr[i] = '@';
            }
            else if(layout == 1)
            {
              printch('"');
              buffstr[i] = '"';
            }
          }
          i++;
          break;
        case 4:
          if(shifted == 0)  //3
          {
            printch('3');
            buffstr[i] = '3';
          }
          else
          {
            if(layout == 0)
            {
              printch('#');
              buffstr[i] = '#';
            }
            else if(layout == 1)
            {
              printch((char)245);
              buffstr[i] = (char)245;
            }
          }
          i++;
          break;
        case 5:
          if(shifted == 0)  //4
          {
            printch('4');
            buffstr[i] = '4';
          }
          else
          {
            printch('$');
            buffstr[i] = '$';
          }
          i++;
          break;
        case 6:
          if(shifted == 0)  //5
          {
            printch('5');
            buffstr[i] = '5';
          }
          else
          {
            printch('%');
            buffstr[i] = '%';
          }
          i++;
          break;
        case 7:
          if(shifted == 0)  //6
          {
            printch('6');
            buffstr[i] = '6';
          }
          else
          {
            if(layout == 0)
            {
              printch('^');
              buffstr[i] = '^';
            }
            else if(layout == 1)
            {
              printch('&');
              buffstr[i] = '&';
            }
          }
          i++;
          break;
        case 8:
          if(shifted == 0)  //7
          {
            printch('7');
            buffstr[i] = '7';
          }
          else
          {
            if(layout == 0)
            {
              printch('&');
              buffstr[i] = '&';
            }
            else if(layout == 1)
            {
              printch('/');
              buffstr[i] = '/';
            }
          }
          i++;
          break;
        case 9:
          if(shifted == 0)  //8
          {
            printch('8');
            buffstr[i] = '8';
          }
          else
          {
            if(layout == 0)
            {
              printch('*');
              buffstr[i] = '*';
            }
            else if(layout == 1)
            {
              printch('(');
              buffstr[i] = '(';
            }
          }
          i++;
          break;
        case 10:
          if(shifted == 0)  //9
          {
            printch('9');
            buffstr[i] = '9';
          }
          else
          {
            if(layout == 0)
            {
              printch('(');
              buffstr[i] = '(';
            }
            else if(layout == 1)
            {
              printch(')');
              buffstr[i] = ')';
            }
          }
          i++;
          break;
        case 11:
          if(shifted == 0)  //0
          {
            printch('0');
            buffstr[i] = '0';
          }
          else
          {
            if(layout == 0)
            {
              printch(')');
              buffstr[i] = ')';
            }
            else if(layout == 1)
            {
              printch('=');
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
              printch('-');
              buffstr[i] = '-';
            }
            else if(layout == 1)
            {
              printch((char)225);
              buffstr[i] = (char)225;
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('_');
              buffstr[i] = '_';
            }
            else if(layout == 1)
            {
              printch('?');
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
              printch('=');
              buffstr[i] = '=';
            }
            else if(layout == 1)
            {
              printch((char)239);
              buffstr[i] = (char)239;
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('+');
              buffstr[i] = '+';
            }
            else if(layout == 1)
            {
              printch('`');
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
            printch('q');
            buffstr[i] = 'q';
          }
          else
          {
            printch('Q');
            buffstr[i] = 'Q';
          }
          i++;
          break;
        case 17:
          if(shifted == 0)  //w
          {
            printch('w');
            buffstr[i] = 'w';
          }
          else
          {
            printch('W');
            buffstr[i] = 'W';
          }
          i++;
          break;
        case 18:
          if(shifted == 0)  //e
          {
            printch('e');
            buffstr[i] = 'e';
          }
          else
          {
            printch('E');
            buffstr[i] = 'E';
          }
          i++;
          break;
        case 19:
          if(shifted == 0)  //r
          {
            printch('r');
            buffstr[i] = 'r';
          }
          else
          {
            printch('R');
            buffstr[i] = 'R';
          }
          i++;
          break;
        case 20:
          if(shifted == 0)  //t
          {
            printch('t');
            buffstr[i] = 't';
          }
          else
          {
            printch('T');
            buffstr[i] = 'T';
          }
          i++;
          break;
        case 21:
          if(shifted == 0)  //y
          {
            if(layout == 0)
            {
              printch('y');
              buffstr[i] = 'y';
            }
            else if(layout == 1)
            {
              printch('z');
              buffstr[i] = 'z';
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('Y');
              buffstr[i] = 'Y';
            }
            else if(layout == 1)
            {
              printch('Z');
              buffstr[i] = 'Z';
            }
          }
          i++;
          break;
        case 22:
          if(shifted == 0)  //u
          {
            printch('u');
            buffstr[i] = 'u';
          }
          else
          {
            printch('U');
            buffstr[i] = 'U';
          }
          i++;
          break;
        case 23:
          if(shifted == 0)  //i
          {
            printch('i');
            buffstr[i] = 'i';
          }
          else
          {
            printch('I');
            buffstr[i] = 'I';
          }
          i++;
          break;
        case 24:
          if(shifted == 0)  //o
          {
            printch('o');
            buffstr[i] = 'o';
          }
          else
          {
            printch('O');
            buffstr[i] = 'O';
          }
          i++;
          break;
        case 25:
          if(shifted == 0)  //p
          {
            printch('p');
            buffstr[i] = 'p';
          }
          else
          {
            printch('P');
            buffstr[i] = 'P';
          }
          i++;
          break;
        case 26:
          if(shifted == 0)  //[
          {
            if(layout == 0)
            {
              printch('[');
              buffstr[i] = '[';
            }
            else if(layout == 1)
            {
              printch((char)129);
              buffstr[i] = (char)129;
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('{');
              buffstr[i] = '{';
            }
            else if(layout == 1)
            {
              printch((char)154);
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
              printch(']');
              buffstr[i] = ']';
            }
            else if(layout == 1)
            {
              printch('+');
              buffstr[i] = '+';
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('}');
              buffstr[i] = '}';
            }
            else if(layout == 1)
            {
              printch('*');
              buffstr[i] = '*';
            }
          }
          i++;
          break;
        case 28:
        //printch('\n');  //Enter
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
          printch('C');  //Ctrl-left
          buffstr[i] = 'C';
          i++;
          break;*/
        case 30:
          if(shifted == 0)  //a
          {
            printch('a');
            buffstr[i] = 'a';
          }
          else
          {
            printch('A');
            buffstr[i] = 'A';
          }
          i++;
          break;
        case 31:
          if(shifted == 0)  //s
          {
            printch('s');
            buffstr[i] = 's';
          }
          else
          {
            printch('S');
            buffstr[i] = 'S';
          }
          i++;
          break;
        case 32:
          if(shifted == 0)  //d
          {
            printch('d');
            buffstr[i] = 'd';
          }
          else
          {
            printch('D');
            buffstr[i] = 'D';
          }
          i++;
          break;
        case 33:
          if(shifted == 0)  //f
          {
            printch('f');
            buffstr[i] = 'f';
          }
          else
          {
            printch('F');
            buffstr[i] = 'F';
          }
          i++;
          break;
        case 34:
          if(shifted == 0)  //g
          {
            printch('g');
            buffstr[i] = 'g';
          }
          else
          {
            printch('G');
            buffstr[i] = 'G';
          }
          i++;
          break;
        case 35:
          if(shifted == 0)  //h
          {
            printch('h');
            buffstr[i] = 'h';
          }
          else
          {
            printch('H');
            buffstr[i] = 'H';
          }
          i++;
          break;
        case 36:
          if(shifted == 0)  //j
          {
            printch('j');
            buffstr[i] = 'j';
          }
          else
          {
            printch('J');
            buffstr[i] = 'J';
          }
          i++;
          break;
        case 37:
          if(shifted == 0)  //k
          {
            printch('k');
            buffstr[i] = 'k';
          }
          else
          {
            printch('K');
            buffstr[i] = 'K';
          }
          i++;
          break;
        case 38:
          if(shifted == 0)  //l
          {
            printch('l');
            buffstr[i] = 'l';
          }
          else
          {
            printch('L');
            buffstr[i] = 'L';
          }
          i++;
          break;
        case 39:
          if(shifted == 0)  //;
          {
            if(layout == 0)
            {
              printch(';');
              buffstr[i] = ';';
            }
            else if(layout == 1)
            {
              printch((char)148);
              buffstr[i] = (char)148;
            }
          }
          else
          {
            if(layout == 0)
            {
              printch(':');
              buffstr[i] = ':';
            }
            else if(layout == 1)
            {
              printch((char)153);
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
              printch((char)39);
              buffstr[i] = (char)39;
            }
            else if(layout == 1)
            {
              printch((char)132);
              buffstr[i] = (char)132;
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('"');
              buffstr[i] = '"';
            }
            else if(layout == 1)
            {
              printch((char)142);
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
              printch('`');
              buffstr[i] = '`';
            }
            else if(layout == 1)
            {
              printch('^');
              buffstr[i] = '^';
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('~');
              buffstr[i] = '~';
            }
            else if(layout == 1)
            {
              printch((char)167);
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
              printch((char)92);
              buffstr[i] = (char)92;
            }
            else if(layout == 1)
            {
              printch('#');
              buffstr[i] = '#';
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('|');
              buffstr[i] = '|';
            }
            else if(layout == 1)
            {
              printch((char)39);
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
              printch('z');
              buffstr[i] = 'z';
            }
            else if(layout == 1)
            {
              printch('y');
              buffstr[i] = 'y';
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('Z');
              buffstr[i] = 'Z';
            }
            else if(layout == 1)
            {
              printch('Y');
              buffstr[i] = 'Y';
            }
          }
          i++;
          break;
        case 45:
          if(shifted == 0)  //x
          {
            printch('x');
            buffstr[i] = 'x';
          }
          else
          {
            printch('X');
            buffstr[i] = 'X';
          }
          i++;
          break;
        case 46:
          if(shifted == 0)  //c
          {
            printch('c');
            buffstr[i] = 'c';
          }
          else
          {
            printch('C');
            buffstr[i] = 'C';
          }
          i++;
          break;
        case 47:
          if(shifted == 0)  //v
          {
            printch('v');
            buffstr[i] = 'v';
          }
          else
          {
            printch('V');
            buffstr[i] = 'V';
          }
          i++;
          break;
        case 48:
          if(shifted == 0)  //b
          {
            printch('b');
            buffstr[i] = 'b';
          }
          else
          {
            printch('B');
            buffstr[i] = 'B';
          }
          i++;
          break;
        case 49:
          if(shifted == 0)  //n
          {
            printch('n');
            buffstr[i] = 'n';
          }
          else
          {
            printch('N');
            buffstr[i] = 'N';
          }
          i++;
          break;
        case 50:
          if(shifted == 0)  //m
          {
            printch('m');
            buffstr[i] = 'm';
          }
          else
          {
            printch('M');
            buffstr[i] = 'M';
          }
          i++;
          break;
        case 51:
          if(shifted == 0)  //,
          {
            printch(',');
            buffstr[i] = ',';
          }
          else
          {
            if(layout == 0)
            {
              printch('<');
              buffstr[i] = '<';
            }
            else if(layout == 1)
            {
              printch(';');
              buffstr[i] = ';';
            }
          }
          i++;
          break;
        case 52:
          if(shifted == 0)  //.
          {
            printch('.');
            buffstr[i] = '.';
          }
          else
          {
            if(layout == 0)
            {
              printch('>');
              buffstr[i] = '>';
            }
            else if(layout == 1)
            {
              printch(':');
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
              printch('/');
              buffstr[i] = '/';
            }
            else if(layout == 1)
            {
              printch('-');
              buffstr[i] = '-';
            }
          }
          else
          {
            if(layout == 0)
            {
              printch('?');
              buffstr[i] = '?';
            }
            else if(layout == 1)
            {
              printch('_');
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
          printch('*');  //Numblock *
          buffstr[i] = '*';
          i++;
          break;
        /*case 56:
          printch('A');  //Alt (Gr)
          buffstr[i] = 'A';
          i++;
          break;*/
        case 57:
          printch(' ');  //Space
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
          printch('F');  //F1
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 60:
          printch('F');  //F2
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 61:
          printch('F');  //F3
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 62:
          printch('F');  //F4
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 63:
          printch('F');  //F5
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 64:
          printch('F');  //F6
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 65:
          printch('F');  //F7
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 66:
          printch('F');  //F8
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 67:
          printch('F');  //F9
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 68:
          printch('F');  //F10
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 69:
          printch('F');  //F11
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 70:
          printch('F');  //F12
          buffstr[i] = 'F';
          i++;
          break;*/
      /*case 71:
          printch('P');  //Pos 1
          buffstr[i] = 'P';
          i++;
          break;*/
      /*case 72:
          printch('U');  //Up
          buffstr[i] = 'U';
          i++;
          break;*/
      /*case 73:
          break;  //Page-up*/
        case 74:
          printch('-');  //Numblock -
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
          printch('5');  //Numblock 5
          buffstr[i] = '5';
          i++;
          break;*/
        case 77:
          plusCursorX();  //Right
          i++;
          break;
        case 78:
          printch('+');  //Numblock +
          buffstr[i] = '+';
          i++;
          break;
      /*case 79:
          printch('E');  //End
          buffstr[i] = 'E';
          i++;
          break;*/
      /*case 80:
          printch('D');  //Down
          buffstr[i] = 'D';
          i++;
          break;*/
      /*case 81:
          ScrollUp(1);  //Page-Down
          break;*/
      /*case 82:
          printch('P');  //Paste
          buffstr[i] = 'P';
          i++;
          break;*/
      /*case 83:
          printch('D');  //Delete
          buffstr[i] = 'D';
          i++;
          break;*/
      }
    }
  }

  while(reading && i == 60)  //Delete and Enter must even work with full limit
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
        //printch('\n');  //Enter
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

string getNavigation()  //Get Arrow-Key Navigation (keyboard)
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
    shellMouseSettings();
    shellMainMenu();
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

void cursorMouse()  //Shows cursor that can be moved by the mouse (mouse)
{
  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int n4 = 0;
  int n5a = 0;
  int n5b = 0;
  
  activateMouse();
  
  setCursorX(mouseCursorX);
  setCursorY(mouseCursorY);
  showCursor();
  
  while(1)
  {
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
