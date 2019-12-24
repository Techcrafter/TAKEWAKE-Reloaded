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

//Settings (with settings.h)

#include "settings.h"

string input;
int selection;

void settings()  //Settings
{
  settings:
  
  setColor(15, 0);
  newWindow(languagesGetString(35), 1, 1);
  
  newInterface(15, 0, 0, 15);
  
  drawBox(4, 4, strLength(languagesGetString(36))+2, 3, 1);
  addButton(1, 5, 5, strLength(languagesGetString(36)), 1, languagesGetString(36));  //LanguageSelector
  drawBox(29, 4, strLength(languagesGetString(37))+2, 3, 1);
  addButton(2, 30, 5, strLength(languagesGetString(37)), 1, languagesGetString(37));  //Systeminformation
  drawBox(4, 9, strLength(languagesGetString(23))+2, 3, 1);
  addButton(3, 5, 10, strLength(languagesGetString(23)), 1, languagesGetString(23));  //White background support
  drawBox(29, 9, strLength(languagesGetString(41))+2, 3, 1);
  addButton(4, 30, 10, strLength(languagesGetString(41)), 1, languagesGetString(41));  //Mouse settings
  selection = runInterface(4, 1, 0);
  
  if(selection == 0)  //Quit
  {
    return;
  }
  else if(selection == 1)  //Language Selector
  {
    languageSelector();
  }
  else if(selection == 2)  //White background support
  {
    whiteBgSupportSettings();
  }
  else if(selection == 3)  //Systeminformation
  {
    systeminformation();
  }
  else if(selection == 4)  //Mouse settings
  {
    mouseSettings();
  }
  else  //In case of an error
  {
    kerror("Invalid selection");
  }
  goto settings;
}

void languageSelector()  //Language selector
{
  setColor(15, 0);
  clear();
  printColored(" Language selector                                                              ", 0, 15);
  print("\n\n  Please select your language from below:");
  setCursorX(4);
  setCursorY(19);
  print("Keyboard layout will be set dependend on your choosen language.");
  setCursorX(4);
  setCursorY(21);
  print("Press [Enter] to continue...");
  selection = languagesGetLanguage();  //Set selected entry to current language
  while(1)
  {
    setCursorX(0);
    setCursorY(4);
    
    //English (United States) = 0
    print("\n    [");
    if(selection == 0)
    {
      print("X");
    }
    else
    {
      print(" ");
    }
    print("]   English (United States)");
    
    //English (United Kingdom) = 1
    print("\n    [");
    if(selection == 1)
    {
      print("X");
    }
    else
    {
      print(" ");
    }
    print("]   English (United Kingdom)");
    
    //German/Deutsch (Deutschland) = 2
    print("\n    [");
    if(selection == 2)
    {
      print("X");
    }
    else
    {
      print(" ");
    }
    print("]   Deutsch (Deutschland)");
    
    input = getNavigation(0);
    
    if(strEquals(input, "up") && selection != 0)
    {
      selection--;
    }
    else if(strEquals(input, "down") && selection != 2)
    {
      selection++;
    }
    else if(strEquals(input, (char)27))
    {
      return;
    }
    else if(strEquals(input, "enter"))
    {
      languagesSetLanguage(selection);
      return;
    }
  }
}

void whiteBgSupportSettings()  //Settings for white background support
{
  setWhiteBgSupport(1);
  setColor(0, 0);
  clear();
  
  printColored(languagesGetString(40), 0, 15);
  selection = showInfobox(languagesGetString(37), languagesGetString(38), 2, 2, getMouseSupport()+1);
  
  if(selection == 1)
  {
    return;
  }
  else if(selection == 2)
  {
    setWhiteBgSupport(0);
    return;
  }
  else
  {
    kerror("Invalid selection");
  }
}

void systeminformation()  //Systeminformation
{
  setColor(15, 0);
  newWindow(languagesGetString(23), 1, 1);
  
  newInterface(15, 0, 0, 15);
  
  setCursorX(2);
  setCursorY(4);
  print("TAKEWAKE Reloaded  Copyright (C) 2019-");
  print(getVersionYear());
  print("  The TAKEWAKE Community");
  setCursorX(2);
  plusCursorY();
  print("TAKEWAKE Reloaded is distributed under the GNU General Public License 3.");
  setCursorX(2);
  plusCursorY();
  print("For more informations see <https://www.gnu.org/licenses/>.");
  setCursorX(2);
  setCursorY(8);
  print(languagesGetString(24));
  print(getVersion());
  print(" ");
  print(languagesGetString(25));
  print(" ");
  print(getVersionYear());
  print(".");
  setCursorX(2);
  setCursorY(11);
  printColored(languagesGetString(26), 0, 7);
  setCursorX(2);
  setCursorY(13);
  print(languagesGetString(27));
  setCursorX(2);
  plusCursorY();
  print(languagesGetString(28));
  setCursorX(2);
  setCursorY(16);
  print(languagesGetString(29));
  
  selection = runInterface(4, 1, 0);
  if(selection == 0)  //Quit
  {
    return;
  }
  else
  {
    kerror("Invalid selection");
  }
}

void mouseSettings()  //Mouse settings
{
  setColor(15, 0);
  clear();
  selection = showInfobox(languagesGetString(41), languagesGetString(42), 2, 1, getMouseSupport()+1);  //Enable mouse support?
  if(selection == 1)  //Yes
  {
    setMouseSupport(1);
  }
  else if(selection == 2)  //No
  {
    setMouseSupport(0);
    showInfobox(languagesGetString(43), languagesGetString(44), 1, 1, 1);
    return;
  }
  
  selection = showInfobox(languagesGetString(41), languagesGetString(49), 2, 2, 2);  //Configure mouse now?
  if(selection == 2)  //No
  {
    return;
  }
  
  newWindow(languagesGetString(41), 0, 1);
  
  setCursorX(3);
  setCursorY(4);
  print(languagesGetString(45));
  setCursorX(3);
  plusCursorY();
  printCh((char)218);
  printMultipleCh((char)196, 13);
  printCh((char)191);
  setCursorX(3);
  setCursorY(6);
  printCh((char)179);
  print("-------------");
  printCh((char)179);
  setCursorX(3);
  plusCursorY();
  printCh((char)192);
  printMultipleCh((char)196, 13);
  printCh((char)217);
  int selection2 = getMouseDelay();
  if(selection2 == 1)
  {
    selection2 = 3;
  }
  else if(selection2 == 3)
  {
    selection2 = 1;
  }
  int selection3 = getMouseDoubleclick();
  while(1)
  {
    newInterface(15, 0, 15, 0);
    if(selection2 == 1)
    {
      addButton(1, 4, 6, 3, 1, "-X-");
    }
    else
    {
      addButton(1, 4, 6, 3, 1, "-I-");
    }
    if(selection2 == 2)
    {
      addButton(2, 9, 6, 3, 1, "-X-");
    }
    else
    {
      addButton(2, 9, 6, 3, 1, "-I-");
    }
    if(selection2 == 3)
    {
      addButton(3, 14, 6, 3, 1, "-X-");
    }
    else
    {
      addButton(3, 14, 6, 3, 1, "-I-");
    }
    setCursorX(7);
    setCursorY(9);
    print(languagesGetString(48));
    if(selection3 == 1)
    {
      addButton(4, 3, 9, 3, 1, "[X]");
    }
    else
    {
      addButton(4, 3, 9, 3, 1, "[ ]");
    }
    drawBox(3, 11, 4, 3, 1);
    addButton(5, 4, 12, strLength(languagesGetString(39)), 1, languagesGetString(39));
    selection = runInterface(4, 0, 0);
    if(selection == 5)
    {
      return;
    }
    else if(selection == 4)
    {
      if(selection3 == 1)
      {
        selection3 = 0;
      }
      else
      {
        selection3 = 1;
      }
      setMouseDoubleclick(selection3);
    }
    else
    {
      selection2 = selection;
      if(selection2 == 1)
      {
        setMouseDelay(3);
      }
      else if(selection2 == 2)
      {
        setMouseDelay(2);
      }
      else if(selection2 == 3)
      {
        setMouseDelay(1);
      }
    }
  }
}
