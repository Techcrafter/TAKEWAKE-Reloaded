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

//OS-terminal (with terminal.h)

#include "languages.h"
#include "terminal.h"

string input;

void terminalMain()  //Terminal-mainfunction
{
  terminalMain:
  
  
  
  setColor(15, 0);
  setAutoScroll(1);
  clear();
  drawBox(25, 0, 29, 3, 1);
  setCursorX(26);
  setCursorY(1);
  print("TAKEWAKE Reloaded ver.");
  print(getVersion());
  print("\n\n");
  printColored("                                    Welcome!", 10, 0);
  print("\n");
  print("\nPress [ESC] to quit.");
  print("\nEnter 'help' for help.\n");
  while(1)
  {
    print("\nTW-Terminal> ");
    input = readStr(20);
    if(strEquals(input, "ascii"))
    {
      terminalAscii();
    }
    else if(strEquals(input, "clear"))
    {
      clear();
    }
    else if(strEquals(input, "date"))
    {
      terminalGetDate();
    }
    else if(strEquals(input, "help"))
    {
      terminalHelp();
      goto terminalMain;
    }
    else if(strEquals(input, "infobox"))
    {
      terminalTestInfobox();
    }
    else if(strEquals(input, "mouse"))
    {
      terminalMouse();
    }
    else if(strEquals(input, (char)27))
    {
      setAutoScroll(0);
      return;
    }
    else if(strEquals(input, "quit-session"))
    {
      kend();
    }
    else if(strEquals(input, "reboot"))
    {
      kreboot();
    }
    else if(strEquals(input, "setlang"))
    {
      terminalSetLanguage();
    }
    else if(strEquals(input, "time"))
    {
      terminalGetTime();
    }
    else if(strEquals(input, "tone"))
    {
      terminalPlayTone();
    }
    else
    {
      printColored("\nUnknown command!", 4, 0);
    }
  }
}

void terminalHelp()  //Terminal-help
{
  setColor(15, 0);
  clear();
  printColored("                               Terminal commands                                ", 0, 15);
  minusCursorY();
  print("\n\n      Command        ");
  printCh((char)186);
  print("                    Description\n");
  printMultipleCh((char)205, 21);
  printCh((char)206);
  printMultipleCh((char)205, 58);
  setCursorX(1);
  print("ascii               ");
  printCh((char)186);
  print(" Displays a specified ascii symbol.");
  print("\n clear               ");
  printCh((char)186);
  print(" Clears the terminalscreen.");
  print("\n date                ");
  printCh((char)186);
  print(" Displays the current date.");
  print("\n help                ");
  printCh((char)186);
  print(" Shows this commandlist.");
  print("\n infobox             ");
  printCh((char)186);
  print(" Displays a test infobox.");
  print("\n mouse               ");
  printCh((char)186);
  print(" Demonstration of mouse functionality.");
  print("\n quit-session        ");
  printCh((char)186);
  print(" Quit the actual session.                                ");
  print("\n reboot              ");
  printCh((char)186);
  print(" Reboots the computer.");
  print("\n setlang             ");
  printCh((char)186);
  print(" Sets the systemlanguage.");
  print("\n time                ");
  printCh((char)186);
  print(" Displays the current time.");
  print("\n tone                ");
  printCh((char)186);
  print(" Plays a tone with a specified frequence and time.");
  print("\n                     ");
  printCh((char)186);
  print("\n\n  Press [Enter] to return to terminal...");
  pause();
  
  return;
}

void terminalAscii()  //Displays a specified ascii symbol
{
  print("\nDEC: ");
  input = readStr(3);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  int dec = str_to_int(input);
  print("\nASCII: ");
  printCh((char)dec);
  
  return;
}

void terminalTestInfobox()  //Displays an infobox with customized type and preselection
{
  print("\nType: ");
  input = readStr(1);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  int type = str_to_int(input);
  print("\nPreselected: ");
  input = readStr(1);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  int preselected = str_to_int(input);
  print("\nNavigation type: ");
  input = readStr(1);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  int navType = str_to_int(input);
  print("\nShowing...");
  int result = showInfobox("Infobox", "This is an infobox.", type, preselected, navType);
  
  if(type != 1)
  {
    print("\nResult: ");
    print(int_to_str(result));
  }
  
  return;
}

void terminalSetLanguage()  //Sets the systemlanguage to an int
{
  print("\nDEC: ");
  input = readStr(3);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  int dec = str_to_int(input);
  languagesSetLanguage(dec);
  printColored("\nDone!", 10, 0);
  
  return;
}

void terminalGetTime()  //Prints the current time from CMOS in HH/MM/SS format
{
  print("\nCurrent time (HH/MM/SS):\n");
  print(int_to_str(getCmosHour()));
  print(":");
  print(int_to_str(getCmosMinute()));
  print(":");
  print(int_to_str(getCmosSecond()));
  
  return;
}

void terminalGetDate()  //Prints the current date from CMOS in DD/MM/YY format
{
  print("\nCurrent date (MM/DD/YY):\n");
  print(int_to_str(getCmosMonth()));
  print(".");
  print(int_to_str(getCmosDay()));
  print(".");
  print(int_to_str(getCmosYear()));
  
  return;
}

void terminalPlayTone()  //Plays a tone with a specified frequence and time
{
  print("\nFrequence (Hz): ");
  input = readStr(5);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  int freq = str_to_int(input);
  print("\nTime (s): ");
  input = readStr(2);
  if(strEquals(input, (char)27))
  {
    printColored("Aborted!", 4, 0);
    return;
  }
  printColored("\nPlaying...", 10, 0);
  playToneForSec(freq, str_to_int(input));
  
  return;
}

void terminalMouse()  //Demonstration of mouse functionality
{
  clear();
  cursorMouse(0);
  int tempX = getCursorX();
  int tempY = getCursorY();
  clear();
  print("X: ");
  print(int_to_str(tempX));
  print("\nY: ");
  print(int_to_str(tempY));
  
  return;
}
