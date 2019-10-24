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

//Manager for interface elements (like buttons) (with interface.h)

#include "interface.h"

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

void newInterface(int unselectedTextColor, int unselectedBackgroundColor, int selectedTextColor, int selectedBackgroundColor)  //Prepares for a new interface
{
  unselTxtCl = unselectedTextColor;
  unselBgCl = unselectedBackgroundColor;
  selTxtCl = selectedTextColor;
  selBgCl = selectedBackgroundColor;
  
  button1 = 0;
  button2 = 0;
  button3 = 0;
  button4 = 0;
  button5 = 0;
  button6 = 0;
  button7 = 0;
  button8 = 0;
  button9 = 0;
  button10 = 0;
  button11 = 0;
  button12 = 0;
  button13 = 0;
  button14 = 0;
  button15 = 0;
  button16 = 0;
  button17 = 0;
  button18 = 0;
  button19 = 0;
  button20 = 0;
}

void addButton(int id, int posX, int posY, int sizeX, int sizeY, string text)  //Adds a new button to the interface
{
  if(id < 1 || id > 9)
  {
    kerror();
  }
  
  if(id == 1)
  {
    button1 = 1;
    button1X = posX;
    button1Y = posY;
    button1SizeX = sizeX;
    button1SizeY = sizeY;
    button1Text = text;
  }
  else if(id == 2)
  {
    button2 = 1;
    button2X = posX;
    button2Y = posY;
    button2SizeX = sizeX;
    button2SizeY = sizeY;
    button2Text = text;
  }
  else if(id == 3)
  {
    button3 = 1;
    button3X = posX;
    button3Y = posY;
    button3SizeX = sizeX;
    button3SizeY = sizeY;
    button3Text = text;
  }
  else if(id == 4)
  {
    button4 = 1;
    button4X = posX;
    button4Y = posY;
    button4SizeX = sizeX;
    button4SizeY = sizeY;
    button4Text = text;
  }
  else if(id == 5)
  {
    button5 = 1;
    button5X = posX;
    button5Y = posY;
    button5SizeX = sizeX;
    button5SizeY = sizeY;
    button5Text = text;
  }
  else if(id == 6)
  {
    button6 = 1;
    button6X = posX;
    button6Y = posY;
    button6SizeX = sizeX;
    button6SizeY = sizeY;
    button6Text = text;
  }
  else if(id == 7)
  {
    button7 = 1;
    button7X = posX;
    button7Y = posY;
    button7SizeX = sizeX;
    button7SizeY = sizeY;
    button7Text = text;
  }
  else if(id == 8)
  {
    button8 = 1;
    button8X = posX;
    button8Y = posY;
    button8SizeX = sizeX;
    button8SizeY = sizeY;
    button8Text = text;
  }
  else if(id == 9)
  {
    button9 = 1;
    button9X = posX;
    button9Y = posY;
    button9SizeX = sizeX;
    button9SizeY = sizeY;
    button9Text = text;
  }
  else if(id == 10)
  {
    button10 = 1;
    button10X = posX;
    button10Y = posY;
    button10SizeX = sizeX;
    button10SizeY = sizeY;
    button10Text = text;
  }
  else if(id == 11)
  {
    button11 = 1;
    button11X = posX;
    button11Y = posY;
    button11SizeX = sizeX;
    button11SizeY = sizeY;
    button11Text = text;
  }
  else if(id == 12)
  {
    button12 = 1;
    button12X = posX;
    button12Y = posY;
    button12SizeX = sizeX;
    button12SizeY = sizeY;
    button12Text = text;
  }
  else if(id == 13)
  {
    button13 = 1;
    button13X = posX;
    button13Y = posY;
    button13SizeX = sizeX;
    button13SizeY = sizeY;
    button13Text = text;
  }
  else if(id == 14)
  {
    button14 = 1;
    button14X = posX;
    button14Y = posY;
    button14SizeX = sizeX;
    button14SizeY = sizeY;
    button14Text = text;
  }
  else if(id == 15)
  {
    button15 = 1;
    button15X = posX;
    button15Y = posY;
    button15SizeX = sizeX;
    button15SizeY = sizeY;
    button15Text = text;
  }
  else if(id == 16)
  {
    button16 = 1;
    button16X = posX;
    button16Y = posY;
    button16SizeX = sizeX;
    button16SizeY = sizeY;
    button16Text = text;
  }
  else if(id == 17)
  {
    button17 = 1;
    button17X = posX;
    button17Y = posY;
    button17SizeX = sizeX;
    button17SizeY = sizeY;
    button17Text = text;
  }
  else if(id == 18)
  {
    button18 = 1;
    button18X = posX;
    button18Y = posY;
    button18SizeX = sizeX;
    button18SizeY = sizeY;
    button18Text = text;
  }
  else if(id == 19)
  {
    button19 = 1;
    button19X = posX;
    button19Y = posY;
    button19SizeX = sizeX;
    button19SizeY = sizeY;
    button19Text = text;
  }
  else if(id == 20)
  {
    button20 = 1;
    button20X = posX;
    button20Y = posY;
    button20SizeX = sizeX;
    button20SizeY = sizeY;
    button20Text = text;
  }
}

int runInterface(int navType, int ableToQuit)  //Runs the interface with the specified navigation type (1 = up and down (keyboard) | 2 = left and right (keyboard) | 3 = up, down, left and right (keyboard) | 4 = mouse)
{
  if(navType == 1 || navType == 2 || navType == 3)  //Selection for keyboard navigation only
  {
    selection = 1;
  }
  else
  {
    selection = 0;
  }
  
  if(button1 == 0)  //Error if there is no button1
  {
    kerror();
  }
  
  while(1)
  {
    if(button1 == 1)
    {
      setCursorX(button1X);
      setCursorY(button1Y);
      if(selection == 1)
      {
        printColored(button1Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button1Text, unselTxtCl, unselBgCl);
      }
    }
    if(button2 == 1)
    {
      setCursorX(button2X);
      setCursorY(button2Y);
      if(selection == 2)
      {
        printColored(button2Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button2Text, unselTxtCl, unselBgCl);
      }
    }
    if(button3 == 1)
    {
      setCursorX(button3X);
      setCursorY(button3Y);
      if(selection == 3)
      {
        printColored(button3Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button3Text, unselTxtCl, unselBgCl);
      }
    }
    if(button4 == 1)
    {
      setCursorX(button4X);
      setCursorY(button4Y);
      if(selection == 4)
      {
        printColored(button4Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button4Text, unselTxtCl, unselBgCl);
      }
    }
    if(button5 == 1)
    {
      setCursorX(button5X);
      setCursorY(button5Y);
      if(selection == 5)
      {
        printColored(button5Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button5Text, unselTxtCl, unselBgCl);
      }
    }
    if(button6 == 1)
    {
      setCursorX(button6X);
      setCursorY(button6Y);
      if(selection == 6)
      {
        printColored(button6Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button6Text, unselTxtCl, unselBgCl);
      }
    }
    if(button7 == 1)
    {
      setCursorX(button7X);
      setCursorY(button7Y);
      if(selection == 7)
      {
        printColored(button7Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button7Text, unselTxtCl, unselBgCl);
      }
    }
    if(button8 == 1)
    {
      setCursorX(button8X);
      setCursorY(button8Y);
      if(selection == 8)
      {
        printColored(button8Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button8Text, unselTxtCl, unselBgCl);
      }
    }
    if(button9 == 1)
    {
      setCursorX(button9X);
      setCursorY(button9Y);
      if(selection == 9)
      {
        printColored(button9Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button9Text, unselTxtCl, unselBgCl);
      }
    }
    if(button10 == 1)
    {
      setCursorX(button10X);
      setCursorY(button10Y);
      if(selection == 10)
      {
        printColored(button10Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button10Text, unselTxtCl, unselBgCl);
      }
    }
    if(button11 == 1)
    {
      setCursorX(button11X);
      setCursorY(button11Y);
      if(selection == 11)
      {
        printColored(button11Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button11Text, unselTxtCl, unselBgCl);
      }
    }
    if(button12 == 1)
    {
      setCursorX(button12X);
      setCursorY(button12Y);
      if(selection == 12)
      {
        printColored(button12Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button12Text, unselTxtCl, unselBgCl);
      }
    }
    if(button13 == 1)
    {
      setCursorX(button13X);
      setCursorY(button13Y);
      if(selection == 13)
      {
        printColored(button13Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button13Text, unselTxtCl, unselBgCl);
      }
    }
    if(button14 == 1)
    {
      setCursorX(button14X);
      setCursorY(button14Y);
      if(selection == 14)
      {
        printColored(button14Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button14Text, unselTxtCl, unselBgCl);
      }
    }
    if(button15 == 1)
    {
      setCursorX(button15X);
      setCursorY(button15Y);
      if(selection == 15)
      {
        printColored(button15Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button15Text, unselTxtCl, unselBgCl);
      }
    }
    if(button16 == 1)
    {
      setCursorX(button16X);
      setCursorY(button16Y);
      if(selection == 16)
      {
        printColored(button16Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button16Text, unselTxtCl, unselBgCl);
      }
    }
    if(button17 == 1)
    {
      setCursorX(button17X);
      setCursorY(button17Y);
      if(selection == 17)
      {
        printColored(button17Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button17Text, unselTxtCl, unselBgCl);
      }
    }
    if(button18 == 1)
    {
      setCursorX(button18X);
      setCursorY(button18Y);
      if(selection == 18)
      {
        printColored(button18Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button18Text, unselTxtCl, unselBgCl);
      }
    }
    if(button19 == 1)
    {
      setCursorX(button19X);
      setCursorY(button19Y);
      if(selection == 19)
      {
        printColored(button19Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button19Text, unselTxtCl, unselBgCl);
      }
    }
    if(button20 == 1)
    {
      setCursorX(button20X);
      setCursorY(button20Y);
      if(selection == 20)
      {
        printColored(button20Text, selTxtCl, selBgCl);
      }
      else
      {
        printColored(button20Text, unselTxtCl, unselBgCl);
      }
    }
    
    if(navType == 1 || navType == 2 || navType == 3)  //Keyboard navigation for 1, 2, 3
    {
      input = getNavigation();
    }
    
    if(navType == 1 || navType == 3)  //up and down (keyboard)
    {
      if(strEquals(input, "up"))
      {
        if(selection == 1)
        {
          if(button20 == 1)
          {
            selection = 20;
          }
          else if(button19 == 1)
          {
            selection = 19;
          }
          else if(button18 == 1)
          {
            selection = 18;
          }
          else if(button17 == 1)
          {
            selection = 17;
          }
          else if(button16 == 1)
          {
            selection = 16;
          }
          else if(button15 == 1)
          {
            selection = 15;
          }
          else if(button14 == 1)
          {
            selection = 14;
          }
          else if(button13 == 1)
          {
            selection = 13;
          }
          else if(button12 == 1)
          {
            selection = 12;
          }
          else if(button11 == 1)
          {
            selection = 11;
          }
          else if(button10 == 1)
          {
            selection = 10;
          }
          else if(button9 == 1)
          {
            selection = 9;
          }
          else if(button8 == 1)
          {
            selection = 8;
          }
          else if(button7 == 1)
          {
            selection = 7;
          }
          else if(button6 == 1)
          {
            selection = 6;
          }
          else if(button5 == 1)
          {
            selection = 5;
          }
          else if(button4 == 1)
          {
            selection = 4;
          }
          else if(button3 == 1)
          {
            selection = 3;
          }
          else if(button2 == 1)
          {
            selection = 2;
          }
        }
        else
        {
          selection--;
        }
      }
      else if(strEquals(input, "down"))
      {
        if(selection == 20)
        {
          selection = 1;
        }
        else if(button20 == 0 && selection == 19)
        {
          selection = 1;
        }
        else if(button19 == 0 && selection == 18)
        {
          selection = 1;
        }
        else if(button18 == 0 && selection == 17)
        {
          selection = 1;
        }
        else if(button17 == 0 && selection == 16)
        {
          selection = 1;
        }
        else if(button16 == 0 && selection == 15)
        {
          selection = 1;
        }
        else if(button15 == 0 && selection == 14)
        {
          selection = 1;
        }
        else if(button14 == 0 && selection == 13)
        {
          selection = 1;
        }
        else if(button13 == 0 && selection == 12)
        {
          selection = 1;
        }
        else if(button12 == 0 && selection == 11)
        {
          selection = 1;
        }
        else if(button11 == 0 && selection == 10)
        {
          selection = 1;
        }
        else if(button10 == 0 && selection == 9)
        {
          selection = 1;
        }
        else if(button9 == 0 && selection == 8)
        {
          selection = 1;
        }
        else if(button8 == 0 && selection == 7)
        {
          selection = 1;
        }
        else if(button7 == 0 && selection == 6)
        {
          selection = 1;
        }
        else if(button6 == 0 && selection == 5)
        {
          selection = 1;
        }
        else if(button5 == 0 && selection == 4)
        {
          selection = 1;
        }
        else if(button4 == 0 && selection == 3)
        {
          selection = 1;
        }
        else if(button3 == 0 && selection == 2)
        {
          selection = 1;
        }
        else if(button2 == 0 && selection == 1)
        {
          //Nothing
        }
        else
        {
          selection++;
        }
      }
    }
    
    if(navType == 2 || navType == 3)  //left and right (keyboard)
    {
      if(strEquals(input, "left"))
      {
        if(selection == 1)
        {
          if(button20 == 1)
          {
            selection = 20;
          }
          else if(button19 == 1)
          {
            selection = 19;
          }
          else if(button18 == 1)
          {
            selection = 18;
          }
          else if(button17 == 1)
          {
            selection = 17;
          }
          else if(button16 == 1)
          {
            selection = 16;
          }
          else if(button15 == 1)
          {
            selection = 15;
          }
          else if(button14 == 1)
          {
            selection = 14;
          }
          else if(button13 == 1)
          {
            selection = 13;
          }
          else if(button12 == 1)
          {
            selection = 12;
          }
          else if(button11 == 1)
          {
            selection = 11;
          }
          else if(button10 == 1)
          {
            selection = 10;
          }
          else if(button9 == 1)
          {
            selection = 9;
          }
          else if(button8 == 1)
          {
            selection = 8;
          }
          else if(button7 == 1)
          {
            selection = 7;
          }
          else if(button6 == 1)
          {
            selection = 6;
          }
          else if(button5 == 1)
          {
            selection = 5;
          }
          else if(button4 == 1)
          {
            selection = 4;
          }
          else if(button3 == 1)
          {
            selection = 3;
          }
          else if(button2 == 1)
          {
            selection = 2;
          }
        }
        else
        {
          selection--;
        }
      }
      else if(strEquals(input, "right"))
      {
        if(selection == 20)
        {
          selection = 1;
        }
        else if(button20 == 0 && selection == 19)
        {
          selection = 1;
        }
        else if(button19 == 0 && selection == 18)
        {
          selection = 1;
        }
        else if(button18 == 0 && selection == 17)
        {
          selection = 1;
        }
        else if(button17 == 0 && selection == 16)
        {
          selection = 1;
        }
        else if(button16 == 0 && selection == 15)
        {
          selection = 1;
        }
        else if(button15 == 0 && selection == 14)
        {
          selection = 1;
        }
        else if(button14 == 0 && selection == 13)
        {
          selection = 1;
        }
        else if(button13 == 0 && selection == 12)
        {
          selection = 1;
        }
        else if(button12 == 0 && selection == 11)
        {
          selection = 1;
        }
        else if(button11 == 0 && selection == 10)
        {
          selection = 1;
        }
        else if(button10 == 0 && selection == 9)
        {
          selection = 1;
        }
        else if(button9 == 0 && selection == 8)
        {
          selection = 1;
        }
        else if(button8 == 0 && selection == 7)
        {
          selection = 1;
        }
        else if(button7 == 0 && selection == 6)
        {
          selection = 1;
        }
        else if(button6 == 0 && selection == 5)
        {
          selection = 1;
        }
        else if(button5 == 0 && selection == 4)
        {
          selection = 1;
        }
        else if(button4 == 0 && selection == 3)
        {
          selection = 1;
        }
        else if(button3 == 0 && selection == 2)
        {
          selection = 1;
        }
        else if(button2 == 0 && selection == 1)
        {
          //Nothing
        }
        else
        {
          selection++;
        }
      }
    }
    
    if(navType == 1 || navType == 2 || navType == 3)  //Keyboard only features
    {
      if(strEquals(input, "enter"))
      {
        return selection;
      }
      else if(strEquals(input, "quit") && ableToQuit == 1)
      {
        return 0;
      }
    }
    
    if(navType == 4)  //Mouse navigation
    {
      //Subtract 1 from the size values
      button1SizeX--;
      button1SizeY--;
      button2SizeX--;
      button2SizeY--;
      button3SizeX--;
      button3SizeY--;
      button4SizeX--;
      button4SizeY--;
      button5SizeX--;
      button5SizeY--;
      button6SizeX--;
      button6SizeY--;
      button7SizeX--;
      button7SizeY--;
      button8SizeX--;
      button8SizeY--;
      button9SizeX--;
      button9SizeY--;
      button10SizeX--;
      button10SizeY--;
      button11SizeX--;
      button11SizeY--;
      button12SizeX--;
      button12SizeY--;
      button13SizeX--;
      button13SizeY--;
      button14SizeX--;
      button14SizeY--;
      button15SizeX--;
      button15SizeY--;
      button16SizeX--;
      button16SizeY--;
      button17SizeX--;
      button17SizeY--;
      button18SizeX--;
      button18SizeY--;
      button19SizeX--;
      button19SizeY--;
      button20SizeX--;
      button20SizeY--;
      
      while(1)
      {
        cursorMouse();  //Unlock mouse and wait for leftclick
        
        //Check for any buttons at the position of the cursor
        if(button1 == 1 && getCursorX() >= button1X && getCursorX() <= button1X + button1SizeX && getCursorY() >= button1Y && getCursorY() <= button1Y + button1SizeY)
        {
          return 1;
        }
        else if(button2 == 1 && getCursorX() >= button2X && getCursorX() <= button2X + button2SizeX && getCursorY() >= button2Y && getCursorY() <= button2Y + button2SizeY)
        {
          return 2;
        }
        else if(button3 == 1 && getCursorX() >= button3X && getCursorX() <= button3X + button3SizeX && getCursorY() >= button3Y && getCursorY() <= button3Y + button3SizeY)
        {
          return 3;
        }
        else if(button4 == 1 && getCursorX() >= button4X && getCursorX() <= button4X + button4SizeX && getCursorY() >= button4Y && getCursorY() <= button4Y + button4SizeY)
        {
          return 4;
        }
        else if(button5 == 1 && getCursorX() >= button5X && getCursorX() <= button5X + button5SizeX && getCursorY() >= button5Y && getCursorY() <= button5Y + button5SizeY)
        {
          return 5;
        }
        else if(button6 == 1 && getCursorX() >= button6X && getCursorX() <= button6X + button6SizeX && getCursorY() >= button6Y && getCursorY() <= button6Y + button6SizeY)
        {
          return 6;
        }
        else if(button7 == 1 && getCursorX() >= button7X && getCursorX() <= button7X + button7SizeX && getCursorY() >= button7Y && getCursorY() <= button7Y + button7SizeY)
        {
          return 7;
        }
        else if(button8 == 1 && getCursorX() >= button8X && getCursorX() <= button8X + button8SizeX && getCursorY() >= button8Y && getCursorY() <= button8Y + button8SizeY)
        {
          return 8;
        }
        else if(button9 == 1 && getCursorX() >= button9X && getCursorX() <= button9X + button9SizeX && getCursorY() >= button9Y && getCursorY() <= button9Y + button9SizeY)
        {
          return 9;
        }
        else if(button10 == 1 && getCursorX() >= button10X && getCursorX() <= button10X + button10SizeX && getCursorY() >= button10Y && getCursorY() <= button10Y + button10SizeY)
        {
          return 10;
        }
        else if(button11 == 1 && getCursorX() >= button11X && getCursorX() <= button11X + button11SizeX && getCursorY() >= button11Y && getCursorY() <= button11Y + button11SizeY)
        {
          return 11;
        }
        else if(button12 == 1 && getCursorX() >= button12X && getCursorX() <= button12X + button12SizeX && getCursorY() >= button12Y && getCursorY() <= button12Y + button12SizeY)
        {
          return 12;
        }
        else if(button13 == 1 && getCursorX() >= button13X && getCursorX() <= button13X + button13SizeX && getCursorY() >= button13Y && getCursorY() <= button13Y + button13SizeY)
        {
          return 13;
        }
        else if(button14 == 1 && getCursorX() >= button14X && getCursorX() <= button14X + button14SizeX && getCursorY() >= button14Y && getCursorY() <= button14Y + button14SizeY)
        {
          return 14;
        }
        else if(button15 == 1 && getCursorX() >= button15X && getCursorX() <= button15X + button15SizeX && getCursorY() >= button15Y && getCursorY() <= button15Y + button15SizeY)
        {
          return 15;
        }
        else if(button16 == 1 && getCursorX() >= button16X && getCursorX() <= button16X + button16SizeX && getCursorY() >= button16Y && getCursorY() <= button16Y + button16SizeY)
        {
          return 16;
        }
        else if(button17 == 1 && getCursorX() >= button17X && getCursorX() <= button17X + button17SizeX && getCursorY() >= button17Y && getCursorY() <= button17Y + button17SizeY)
        {
          return 17;
        }
        else if(button18 == 1 && getCursorX() >= button18X && getCursorX() <= button18X + button18SizeX && getCursorY() >= button18Y && getCursorY() <= button18Y + button18SizeY)
        {
          return 18;
        }
        else if(button19 == 1 && getCursorX() >= button19X && getCursorX() <= button19X + button19SizeX && getCursorY() >= button19Y && getCursorY() <= button19Y + button19SizeY)
        {
          return 19;
        }
        else if(button20 == 1 && getCursorX() >= button20X && getCursorX() <= button20X + button20SizeX && getCursorY() >= button20Y && getCursorY() <= button20Y + button20SizeY)
        {
          return 20;
        }
      }
    }
  }
}

int showInfobox(string title, string text, uint16 type, uint16 preselected)  //Shows an infobox and returns the selection (type1 = ok | type2 = yes,no)
{
  int currentColor = getColor();
  
  setColor(15, 0);
  setCursorY(17);
  setCursorX(10);
  printch((char)218);
  printMultipleCh((char)196, 58);
  printch((char)191);
  setCursorX(12);
  print(title);
  
  print("\n          ");
  printch((char)179);
  print("                                                          ");
  printch((char)179);
  print("\n          ");
  printch((char)179);
  print("                                                          ");
  setCursorX(14);
  print(text);
  setCursorX(69);
  printch((char)179);
  print("\n          ");
  printch((char)179);
  print("                                                          ");
  printch((char)179);
  print("\n          ");
  printch((char)179);
  print("                                                          ");
  printch((char)179);
  print("\n          ");
  printch((char)179);
  print("                                                          ");
  printch((char)179);
  print("\n          ");
  
  printch((char)192);
  printMultipleCh((char)196, 58);
  printch((char)217);
  
  uint16 selection = preselected;
  
  while(1)
  {
    if(type == 1)  //ok
    {
      if(selection != 1)
      {
        kerror();
      }
      
      setCursorY(21);
      setCursorX(38);
      printColored(languagesGetString(39), 9, 0);
      pause();
      
      setColorcode(currentColor);
      clearLine(17, 23);
      return 1;
    }
    else if(type == 2)  //yes,no
    {
      if(selection != 1 && selection != 2)
      {
        kerror();
      }
      
      setCursorY(21);
      setCursorX(32);
      if(selection == 1)
      {
        printColored(languagesGetString(31), 10, 0);
      }
      else
      {
        print(languagesGetString(31));
      }
      print("          ");
      if(selection == 2)
      {
        printColored(languagesGetString(32), 4, 0);
      }
      else
      {
        print(languagesGetString(32));
      }
      
      string input = getNavigation();
      
      if(strEquals(input, "left") && selection != 1)
      {
        selection--;
      }
      else if(strEquals(input, "right") && selection != 2)
      {
        selection++;
      }
      else if(strEquals(input, "enter"))
      {
        if(selection == 1)  //Yes
        {
          setColorcode(currentColor);
          clearLine(17, 23);
          return selection;
        }
        else if(selection == 2)  //No
        {
          setColorcode(currentColor);
          clearLine(17, 23);
          return selection;
        }
        else  //In case of an error
        {
          kerror();
        }
      }
      else if(strEquals(input, "quit"))  //Quit
      {
        setColorcode(currentColor);
        clearLine(17, 23);
        return preselected;
      }
    }
    else
    {
      kerror();
    }
  }
}
