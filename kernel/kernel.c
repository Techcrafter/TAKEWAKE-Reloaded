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

//C-OS-Kernel

//Including the modules
#include "../modules/display.h"
#include "../modules/input.h"
#include "../modules/sound.h"
#include "../modules/string.h"
#include "../modules/system.h"
#include "../modules/time.h"
#include "../modules/types.h"
#include "../modules/utilities.h"

//Including the systemelements
#include "../system/languages.h"
#include "../system/shell.h"

const string version = "0.0.6";  //Version
const string versionYear = "2019";  //Year of the current version

void kmain()  //Kernelmainfunktion (at start)
{
  //Begin of the bootprocess
  setColor(15, 0);
  clear();
  setCursorX(51);
  print(versionYear);
  print(" | The TAKEWAKE Community");
  setCursorX(31);
  setCursorY(7);
  print("TAKEWAKE Reloaded");
  setCursorX(33);
  setCursorY(8);
  print("Version ");
  print(version);
  setCursorY(18);
  setCursorX(33);
  print("Please wait...");
  setCursorX(4);
  setCursorY(20);
  setColor(15, 15);
  print("                                                                      ");
  print(" ");
  printColored("                                                                               ", 0, 0);
  print(" \n");
  setCursorX(4);
  print("                                                                       ");
  setCursorX(4);
  minusCursorY();
  setColor(15, 15);
  print(" ");
  setColor(10, 10);
  print("                               ");
  hideCursor();
  print("                              ");
  //End of bootprocess
  
  //Begin of license part
  setColor(15, 0);
  clear();
  printColored(" License                                                                        ", 0, 15);
  print("\n\n\n\n    TAKEWAKE Reloaded  Copyright (C) 2019-");
  print(versionYear);
  print("  The TAKEWAKE Community");
  print("\n    TAKEWAKE Reloaded is distributed under the GNU General Public License 3.");
  print("\n    For more informations see <https://www.gnu.org/licenses/>.");
  setCursorX(4);
  setCursorY(21);
  print("Press [Enter] to accept and to continue.\n    Press [ESC] to refuse and to quit session.");
  if(strEquals(pause(), (char)27))
  {
    clear();
    print("You can turn off the computer now.");
    asm("hlt");
  }
  //End of license part
  
  shellLanguageSelector();  //Open language selector
  
  shellWhiteBgSupportSettings();  //Open white background support settings
  
  clear();
  shellMouseSettings();  //Open mouse settings
  
  //Welcome screen
  setColor(0, 15);
  clear();
  print("\n\n\n\n\n\n\n");
  print("                          ");
  printColored("TAKEWAKE Reloaded ver.", 15, 0);
  printColored(version, 15, 0);
  print("\n\n                   Designed to make the world a better place.");
  print("\n\n\n\n\n                                  ");
  print(languagesGetString(6));
  setCursorX(51);
  setCursorY(0);
  print(versionYear);
  print(" | The TAKEWAKE Community");
  setCursorY(18);
  setColor(15, 15);
  wait(3);  //Wait 3 seconds before continue
  shellMainMenu();
}

string getVersion()  //Return version
{
  return version;
}

string getVersionYear()  //Return year of the current version
{
  return versionYear;
}

void kerror()  //Error
{
  setColor(0, 15);
  clear();
  print("\n\n\n\n\n\n\n");
  print("                          ");
  printColored("TAKEWAKE Reloaded ver.", 15, 0);
  printColored(version, 15, 0);
  print("\n\n\n\n\n\n\n");
  print("                 ");
  print(languagesGetString(1));
  print("\n           ");
  print(languagesGetString(2));
  print("\n\n                     ");
  print(languagesGetString(0));
  setCursorX(51);
  setCursorY(0);
  printColored(versionYear, 0, 15);
  printColored(" | The TAKEWAKE Community", 0, 15);
  setCursorY(18);
  setColor(15, 15);
  pause();
  shellMainMenu();  //Reload shellMainMenu-function
}

void kfatal()  //Fatal error
{
  beep();  //Play a beep
  setColor(15, 4);
  clear();
  print("\n\n\n\n\n\n\n");
  print("                          ");
  printColored("TAKEWAKE Reloaded ver.", 15, 0);
  printColored(version, 15, 0);
  print("\n\n\n\n\n");
  print("             ");
  print(languagesGetString(3));
  print("\n           ");
  print(languagesGetString(2));
  print("\n\n                    ");
  print(languagesGetString(4));
  setCursorX(51);
  setCursorY(0);
  printColored(versionYear, 15, 0);
  printColored(" | The TAKEWAKE Community", 15, 0);
  pause();
  kreboot();  //Reboot computer
}

void kreboot()  //Kernelrebootfunction
{
  setColor(15, 0);
  clear();
  print(languagesGetString(34));
  
  outportb(0x64, 0xFE);  //Reboot
}

void kend()  //Kernelendfunction (at end)
{
  setColor(0, 15);
  clear();
  print("\n\n\n\n\n\n\n");
  print("                          ");
  printColored("TAKEWAKE Reloaded ver.", 15, 0);
  printColored(version, 15, 0);
  print("\n\n                   Designed to make the world a better place.");
  print("\n\n\n\n\n");
  print("                    ");
  print(languagesGetString(5));
  setCursorX(51);
  setCursorY(0);
  print(versionYear);
  print(" | The TAKEWAKE Community");
  asm("hlt");
}
