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

const string version = "0.0.8";  //Version
const string versionYear = "2020";  //Year of the current version

void kmain()  //Kernel-main (at start)
{
  //Begin of the bootprocess
  setColor(15, 0);
  clear();
  setCursorX(51);
  print(versionYear);
  print(" | The TAKEWAKE Community");
  drawBox(26, 6, 27, 4, 2);
  setCursor(31, 7);
  print("TAKEWAKE Reloaded");
  setCursor(33, 8);
  print("Version ");
  print(version);
  setCursor(33, 18);
  print("Please wait...");
  setCursor(4, 20);
  setColor(15, 0);
  drawBox(4, 20, 72, 3, 1);
  setCursorX(5);
  minusCursorY();
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
  setCursor(4, 21);
  print("Press [Enter] to accept and to continue.\n    Press [ESC] to refuse and to quit session.");
  if(strEquals(pause(), (char)27))
  {
    kend();
  }
  //End of license part
  
  languageSelector();  //Open language selector
  
  whiteBgSupportSettings();  //Open white background support settings
  
  mouseSettings();  //Open mouse settings
  
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
  playToneForSec(200, 0);
  playToneForSec(300, 0);
  wait(1);  //Wait 1 seconds before continue
  shell();
}

string getVersion()  //Return version
{
  return version;
}

string getVersionYear()  //Return year of the current version
{
  return versionYear;
}

void kerror(string reason)  //Error
{
  setColor(0, 15);
  setAutoScroll(0);
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
  setCursor(51, 0);
  printColored(versionYear, 0, 15);
  printColored(" | The TAKEWAKE Community", 0, 15);
  setCursorY(23);
  print("\nReason: ");
  print(reason);
  pause();
  shell();  //Reload shell-function
}

void kfatal(string reason)  //Fatal error
{
  beep();  //Play a beep
  setAutoScroll(0);
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
  setCursor(51, 0);
  printColored(versionYear, 15, 0);
  printColored(" | The TAKEWAKE Community", 15, 0);
  setCursorY(23);
  print("\nReason: ");
  print(reason);
  pause();
  kreboot();  //Reboot computer
}

void kreboot()  //Kernelrebootfunction
{
  setColor(15, 0);
  clear();
  setCursorX(51);
  print(versionYear);
  print(" | The TAKEWAKE Community");
  drawBox(26, 6, 27, 4, 2);
  setCursor(31, 7);
  print("TAKEWAKE Reloaded");
  setCursor(33, 8);
  print("Version ");
  print(version);
  setCursor(32, 18);
  print(languagesGetString(52));
  setCursor(4, 20);
  setColor(15, 0);
  drawBox(4, 20, 72, 3, 1);
  setCursorX(5);
  minusCursorY();
  setColor(10, 10);
  print("                        ");
  playToneForSec(300, 0);
  print("                        ");
  playToneForSec(200, 0);
  setColor(15, 0);
  clearLine(18, 18);
  setCursor(33, 18);
  print(languagesGetString(34));
  
  outportb(0x64, 0xFE);  //Reboot
}

void kend()  //Kernelendfunction (at end)
{
  setColor(15, 0);
  clear();
  setCursorX(51);
  print(versionYear);
  print(" | The TAKEWAKE Community");
  drawBox(26, 6, 27, 4, 2);
  setCursor(31, 7);
  print("TAKEWAKE Reloaded");
  setCursor(33, 8);
  print("Version ");
  print(version);
  setCursor(32, 18);
  print(languagesGetString(52));
  setCursor(4, 20);
  setColor(15, 0);
  drawBox(4, 20, 72, 3, 1);
  setCursorX(5);
  minusCursorY();
  setColor(10, 10);
  print("                           ");
  playToneForSec(300, 0);
  print("                           ");
  playToneForSec(200, 0);
  setColor(15, 0);
  clearLine(18, 22);
  setCursor(20, 18);
  print(languagesGetString(5));
  asm("hlt");
}
