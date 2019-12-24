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

//Shell (with shell.h)

#include "shell.h"

string input;
int selection;

void shell()  //Shell
{
  shell:
  
  if(getMouseSupport() == 0)  //Start terminal if mouse support is disabled
  {
    terminal();
  }
  
  setColor(15, 0);
  clear();
  
  newInterface(15, 0, 0, 15);
  
  drawBox(25, 7, 29, 3, 1);
  setCursorX(26);
  setCursorY(8);
  print("TAKEWAKE Reloaded ver.");
  print(getVersion());
  
  setCursorY(22);
  print("\n");
  printMultipleCh((char)196, 5);
  printCh((char)194);
  printMultipleCh((char)196, 65);
  printCh((char)194);
  printMultipleCh((char)196, 8);
  addButton(1, 0, 24, 5, 1, "Start");
  print("     ");
  printCh((char)179);
  setCursorX(71);
  printCh((char)179);
  addButton(2, 72, 24, 8, 1, "");
  if(languagesGetLanguage() == 0 || languagesGetLanguage() == 1)
  {
    print(int_to_str(getCmosMonth()));
    print("/");
    print(int_to_str(getCmosDay()));
    print("/");
    print(int_to_str(getCmosYear()));
  }
  else if(languagesGetLanguage() == 2)
  {
    print(int_to_str(getCmosDay()));
    print(".");
    print(int_to_str(getCmosMonth()));
    print(".");
    print(int_to_str(getCmosYear()));
  }
  
  selection = runInterface(4, 0, 0);
  if(selection == 1)  //Start
  {
    setCursorY(8);
    print("\n");
    printMultipleCh((char)205, 19);
    printCh((char)187);
    print("\n                   ");
    printCh((char)186);
    print("\n                   ");
    printCh((char)185);
    int i = 11;
    while(i != 0)
    {
      print("\n                   ");
      printCh((char)186);
      i--;
    }
    setCursorY(9);
    print("\n");
    printColored(languagesGetString(6), 10, 0);
    print("\n");
    printMultipleCh((char)205, 19);
    
    addButton(1, 0, 24, 5, 1, "Start");
    addButton(2, 72, 24, 8, 1, "");
    
    addButton(3, 0, 21, 19, 1, languagesGetString(35));
    addButton(4, 0, 22, 19, 1, languagesGetString(50));
    setCursorY(19);
    print("\n");
    printMultipleCh((char)196, 19);
    
    addButton(5, 0, 12, 19, 1, languagesGetString(8));
    addButton(6, 0, 13, 19, 1, "Tic Tac Toe");
    addButton(7, 0, 14, 19, 1, languagesGetString(9));
    addButton(8, 0, 15, 19, 1, "Degrand");
    
    selection = runInterface(4, 0, 0);
    if(selection == 0 || selection == 1)
    {
      //Nothing, just continue
    }
    else if(selection == 2)
    {
      clearLine(9, 22);
      drawBox(25, 7, 29, 3, 1);
      setCursorX(26);
      setCursorY(8);
      print("TAKEWAKE Reloaded ver.");
      print(getVersion());
      setCursorX(72);
      setCursorY(24);
      print(int_to_str(getCmosHour()));
      print(":");
      print(int_to_str(getCmosMinute()));
      print(":");
      print(int_to_str(getCmosSecond()));
      wait(1);
      goto shell;
    }
    else if(selection == 3)
    {
      settings();
    }
    else if(selection == 4)
    {
      sessionMenu();
    }
    else if(selection == 5)
    {
      calculator();
    }
    else if(selection == 6)
    {
      ticTacToe();
    }
    else if(selection == 7)
    {
      terminal();
    }
    else if(selection == 8)
    {
      degrand();
    }
    else
    {
      kerror("Invalid selection");
    }
    goto shell;
  }
  else if(selection == 2)
  {
    setCursorX(72);
    setCursorY(24);
    print(int_to_str(getCmosHour()));
    print(":");
    print(int_to_str(getCmosMinute()));
    print(":");
    print(int_to_str(getCmosSecond()));
    print("   ");
    wait(1);
    goto shell;
  }
}

void sessionMenu()  //Menu for session options
{
  setColor(0, 7);
  clearLine(0, 8);
  wait(0);
  clearLine(8, 16);
  wait(0);
  clearLine(16, 25);
  setColor(15, 0);
  newInterface(15, 0, 0, 15);
  drawBox(22, 6, 35, 6, 2);
  addButton(1, 23, 7, 33, 1, languagesGetString(12));
  addButton(2, 23, 8, 33, 1, languagesGetString(13));
  addButton(3, 23, 10, 33, 1, languagesGetString(51));
  
  selection = runInterface(4, 0, 0);
  if(selection == 0 || selection == 3)
  {
    //Nothing, just continue
  }
  else if(selection == 1)
  {
    kend();
  }
  else if(selection == 2)
  {
    kreboot();
  }
  else
  {
    kerror("Invalid selection");
  }
}
