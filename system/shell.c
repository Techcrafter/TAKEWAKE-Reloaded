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

//OS-shell (with shell.h)

#include "shell.h"

string input;
int selection;

void shellMainMenu()  //Shell main menu
{
  shellMainMenu:
  
  if(getMouseSupport() == 0)
  {
    oldShellMainMenu();  //Start old shell main menu if mouse support is disabled
  }
  
  setColor(15, 0);
  clear();
  
  print("Placeholder for new shell.\nPress [Enter] to start old shell.");
  pause();
  oldShellMainMenu();
}

void shellCalculator()  //Shell-calculator
{
  shellCalculator:
  
  setColor(15, 0);
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored(languagesGetString(8), 0, 15);
  print("\n\n\n\n\n    ");
  printch((char)201);
  printMultipleCh((char)205, 70);
  printch((char)187);
  print("\n    ");
  printch((char)186);
  print(languagesGetString(14));
  setCursorX(75);
  printch((char)186);
  print("\n    ");
  printch((char)186);
  print("                                                                      ");
  printch((char)186);
  print("\n    ");
  printch((char)204);
  printMultipleCh((char)205, 70);
  printch((char)185);
  print("\n    ");
  printch((char)186);
  print(languagesGetString(15));
  setCursorX(75);
  printch((char)186);
  print("\n    ");
  printch((char)186);
  print("               +            -            *            /               ");
  printch((char)186);
  print("\n    ");
  printch((char)186);
  print("                                                                      ");
  printch((char)186);
  print("\n    ");
  printch((char)204);
  printMultipleCh((char)205, 70);
  printch((char)185);
  print("\n    ");
  printch((char)186);
  print(languagesGetString(16));
  setCursorX(75);
  printch((char)186);
  print("\n    ");
  printch((char)186);
  print("                                                                      ");
  printch((char)186);
  print("\n    ");
  printch((char)204);
  printMultipleCh((char)205, 70);
  printch((char)185);
  print("\n    ");
  printch((char)186);
  print(languagesGetString(17));
  setCursorX(75);
  printch((char)186);
  print("\n    ");
  printch((char)186);
  print("                                                                      ");
  printch((char)186);
  print("\n    ");
  printch((char)200);
  printMultipleCh((char)205, 70);
  printch((char)188);
  print("\n\n\n    ");
  print(languagesGetString(18));
  
  setCursorX(6);
  setCursorY(7);
  string str1 = readStr();
  if(strEquals(str1, "quit"))  //Quit
  {
    return;
  }
  int num1 = str_to_int(str1);
  
  int operator = 0;  //1 = + | 2 = - | 3 = * | 4 = /
  newInterface(15, 0, 0, 15);
  addButton(1, 20, 10, 1, 1, "+");
  addButton(2, 33, 10, 1, 1, "-");
  addButton(3, 46, 10, 1, 1, "*");
  addButton(4, 59, 10, 1, 1, "/");
  selection = runInterface(2, 1);

  if(selection == 0)  //Quit
  {
    return;
  }
  else
  {
    operator = selection;
  }
  
  setCursorX(6);
  setCursorY(14);
  string str2 = readStr();
  if(strEquals(str2, "quit"))  //Quit
  {
    return;
  }
  int num2 = str_to_int(str2);
  
  int int_result;
  
  setCursorX(6);
  setCursorY(17);
  if(operator == 1)  // +
  {
    int_result = num1 + num2;
  }
  else if(operator == 2)  // -
  {
    int_result = num1 - num2;
  }
  else if(operator == 3)  // *
  {
    int_result = num1 * num2;
  }
  else if(operator == 4)  // /
  {
    if(num2 == 0)  //Deny division by zero
    {
      kerror();
    }
    int_result = num1 / num2;
  }
  else  //In case of an error
  {
    kerror();
  }
  
  string str_result = int_to_str(int_result);
  print(str_result);
  
  setColor(0, 0);
  setCursorY(23);
  input = pause();
  if(strEquals(input, "quit"))  //Quit
  {
    return;
  }
  
  goto shellCalculator;
}

void shellTicTacToe()  //Shell-Tic Tac Toe
{
  shellTicTacToe:
  
  setColor(15, 0);
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored(languagesGetString(10), 0, 15);
  print("\n\n\n\n\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                  ");
  printMultipleCh((char)196, 3);
  printch((char)197);
  printMultipleCh((char)196, 3);
  printch((char)197);
  printMultipleCh((char)196, 3);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                  ");
  printMultipleCh((char)196, 3);
  printch((char)197);
  printMultipleCh((char)196, 3);
  printch((char)197);
  printMultipleCh((char)196, 3);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n                                     ");
  printch((char)179);
  print("   ");
  printch((char)179);
  print("\n\n\n\n         ");
  print(languagesGetString(19));
  int symbol = 0;
  selection = 1;
  while(symbol == 0)
  {
    setCursorY(19);
    setCursorX(35);
    if(selection == 1)
    {
      printColored("X", 0, 15);
    }
    else
    {
      print("X");
    }
    print("       ");
    if(selection == 2)
    {
      printColored("O", 0, 15);
    }
    else
    {
      print("O");
    }
    
    input = getNavigation();
    
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
      symbol = selection;  //1 = X | 2 = O
    }
    else if(strEquals(input, "quit"))  //Quit
    {
      return;
    }
  }
  
  clearLine(19, 19);
  
  setCursorY(19);
  setCursorX(9);
  print(languagesGetString(18));
  
  int field1 = 0;
  int field2 = 0;
  int field3 = 0;
  int field4 = 0;
  int field5 = 0;
  int field6 = 0;
  int field7 = 0;
  int field8 = 0;
  int field9 = 0;
  
  int done = 0;
  if(symbol == 1)  //X begins
  {
    shellTicTacToePlayerAtRow:
    selection = 1;
    done = 0;
    while(done == 0)
    {
      if(selection == 1)
      {
        if(field1 == 0)
        {
          setCursorY(6);
          setCursorX(35);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field1 == 0)
      {
        setCursorY(6);
        setCursorX(35);
        print(" ");
      }
      if(selection == 2)
      {
        if(field2 == 0)
        {
          setCursorY(6);
          setCursorX(39);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field2 == 0)
      {
        setCursorY(6);
        setCursorX(39);
        print(" ");
      }
      if(selection == 3)
      {
        if(field3 == 0)
        {
          setCursorY(6);
          setCursorX(43);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field3 == 0)
      {
        setCursorY(6);
        setCursorX(43);
        print(" ");
      }
      if(selection == 4)
      {
        if(field4 == 0)
        {
          setCursorY(10);
          setCursorX(35);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field4 == 0)
      {
        setCursorY(10);
        setCursorX(35);
        print(" ");
      }
      if(selection == 5)
      {
        if(field5 == 0)
        {
          setCursorY(10);
          setCursorX(39);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field5 == 0)
      {
        setCursorY(10);
        setCursorX(39);
        print(" ");
      }
      if(selection == 6)
      {
        if(field6 == 0)
        {
          setCursorY(10);
          setCursorX(43);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field6 == 0)
      {
        setCursorY(10);
        setCursorX(43);
        print(" ");
      }
      if(selection == 7)
      {
        if(field7 == 0)
        {
          setCursorY(14);
          setCursorX(35);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field7 == 0)
      {
        setCursorY(14);
        setCursorX(35);
        print(" ");
      }
      if(selection == 8)
      {
        if(field8 == 0)
        {
          setCursorY(14);
          setCursorX(39);
          printColored(" ", 15, 15);
        }
        else
        {
          selection++;
        }
      }
      else if(field8 == 0)
      {
        setCursorY(14);
        setCursorX(39);
        print(" ");
      }
      if(selection == 9)
      {
        if(field9 == 0)
        {
          setCursorY(14);
          setCursorX(43);
          printColored(" ", 15, 15);
        }
        else
        {
          selection = 1;
        }
      }
      else if(field9 == 0)
      {
        setCursorY(14);
        setCursorX(43);
        print(" ");
      }
      
      input = getNavigation();
      
      if(strEquals(input, "left") && selection != 1)
      {
        selection--;
      }
      else if(strEquals(input, "left") && selection == 1)
      {
        selection = 9;
      }
      else if(strEquals(input, "right") && selection != 9)
      {
        selection++;
      }
      else if(strEquals(input, "right") && selection == 9)
      {
        selection = 1;
      }
      else if(strEquals(input, "up"))
      {
        if(selection == 1)
        {
          selection = 7;
        }
        else if(selection == 2)
        {
          selection = 8;
        }
        else if(selection == 3)
        {
          selection = 9;
        }
        else if(selection == 4)
        {
          selection = 1;
        }
        else if(selection == 5)
        {
          selection = 2;
        }
        else if(selection == 6)
        {
          selection = 3;
        }
        else if(selection == 7)
        {
          selection = 4;
        }
        else if(selection == 8)
        {
          selection = 5;
        }
        else if(selection == 9)
        {
          selection = 6;
        }
      }
      else if(strEquals(input, "down"))
      {
        if(selection == 1)
        {
          selection = 4;
        }
        else if(selection == 2)
        {
          selection = 5;
        }
        else if(selection == 3)
        {
          selection = 6;
        }
        else if(selection == 4)
        {
          selection = 7;
        }
        else if(selection == 5)
        {
          selection = 8;
        }
        else if(selection == 6)
        {
          selection = 9;
        }
        else if(selection == 7)
        {
          selection = 1;
        }
        else if(selection == 8)
        {
          selection = 2;
        }
        else if(selection == 9)
        {
          selection = 3;
        }
      }
      else if(strEquals(input, "quit"))  //Quit
      {
        return;
      }
      else if(strEquals(input, "enter"))
      {
        done = 1;
        if(selection == 1)
        {
          setCursorY(6);
          setCursorX(35);
          if(symbol == 1)
          {
            field1 = 1;
            print("X");
          }
          else
          {
            field1 = 2;
            print("O");
          }
        }
        if(selection == 2)
        {
          setCursorY(6);
          setCursorX(39);
          if(symbol == 1)
          {
            field2 = 1;
            print("X");
          }
          else
          {
            field2 = 2;
            print("O");
          }
        }
        if(selection == 3)
        {
          setCursorY(6);
          setCursorX(43);
          if(symbol == 1)
          {
            field3 = 1;
            print("X");
          }
          else
          {
            field3 = 2;
            print("O");
          }
        }
        if(selection == 4)
        {
          setCursorY(10);
          setCursorX(35);
          if(symbol == 1)
          {
            field4 = 1;
            print("X");
          }
          else
          {
            field4 = 2;
            print("O");
          }
        }
        if(selection == 5)
        {
          setCursorY(10);
          setCursorX(39);
          if(symbol == 1)
          {
            field5 = 1;
            print("X");
          }
          else
          {
            field5 = 2;
            print("O");
          }
        }
        if(selection == 6)
        {
          setCursorY(10);
          setCursorX(43);
          if(symbol == 1)
          {
            field6 = 1;
            print("X");
          }
          else
          {
            field6 = 2;
            print("O");
          }
        }
        if(selection == 7)
        {
          setCursorY(14);
          setCursorX(35);
          if(symbol == 1)
          {
            field7 = 1;
            print("X");
          }
          else
          {
            field7 = 2;
            print("O");
          }
        }
        if(selection == 8)
        {
          setCursorY(14);
          setCursorX(39);
          if(symbol == 1)
          {
            field8 = 1;
            print("X");
          }
          else
          {
            field8 = 2;
            print("O");
          }
        }
        if(selection == 9)
        {
          setCursorY(14);
          setCursorX(43);
          if(symbol == 1)
          {
            field9 = 1;
            print("X");
          }
          else
          {
            field9 = 2;
            print("O");
          }
        }
      }
    }
  }
  
  //Check for win/lose
  if(field1 == 1 && field2 == 1 && field3 == 1)  //Horizontal
  {
    goto shellTicTacToeWin1;
  }
  else if(field1 == 2 && field2 == 2 && field3 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field4 == 1 && field5 == 1 && field6 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field4 == 2 && field5 == 2 && field6 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field7 == 1 && field8 == 1 && field9 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field7 == 2 && field8 == 2 && field9 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field1 == 1 && field5 == 1 && field9 == 1)  //Across
  {
    goto shellTicTacToeWin1;
  }
  else if(field1 == 2 && field5 == 2 && field9 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field7 == 1 && field5 == 1 && field3 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field7 == 2 && field5 == 2 && field3 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field1 == 1 && field4 == 1 && field7 == 1)  //Vertical
  {
    goto shellTicTacToeWin1;
  }
  else if(field1 == 2 && field4 == 2 && field7 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field2 == 1 && field5 == 1 && field8 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field2 == 2 && field5 == 2 && field8 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field3 == 1 && field6 == 1 && field9 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field3 == 2 && field6 == 2 && field9 == 2)
  {
    goto shellTicTacToeWin2;
  }
  
  //Check for tie
  if(field1 != 0 && field2 != 0 && field3 != 0 && field4 != 0 && field5 != 0 && field6 != 0 && field7 != 0 && field8 != 0 && field9 != 0)
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(20), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    pause();
    if(strEquals(input, "quit"))  //Quit
    {
      return;
    }
    else
    {
      goto shellTicTacToe;
    }
  }
  
  //AI
  if(field5 == 0)
  {
    setCursorY(10);
    setCursorX(39);
    if(symbol == 1)
    {
      field5 = 2;
      print("O");
    }
    else
    {
      field5 = 1;
      print("X");
    }
  }
  else if(field1 == 0)
  {
    setCursorY(6);
    setCursorX(35);
    if(symbol == 1)
    {
      field1 = 2;
      print("O");
    }
    else
    {
      field1 = 1;
      print("X");
    }
  }
  else if(field3 == 0)
  {
    setCursorY(6);
    setCursorX(43);
    if(symbol == 1)
    {
      field3 = 2;
      print("O");
    }
    else
    {
      field3 = 1;
      print("X");
    }
  }
  else if(field7 == 0)
  {
    setCursorY(14);
    setCursorX(35);
    if(symbol == 1)
    {
      field7 = 2;
      print("O");
    }
    else
    {
      field7 = 1;
      print("X");
    }
  }
  else if(field9 == 0)
  {
    setCursorY(14);
    setCursorX(43);
    if(symbol == 1)
    {
      field9 = 2;
      print("O");
    }
    else
    {
      field9 = 1;
      print("X");
    }
  }
  else if(field2 == 0)
  {
    setCursorY(6);
    setCursorX(39);
    if(symbol == 1)
    {
      field2 = 2;
      print("O");
    }
    else
    {
      field2 = 1;
      print("X");
    }
  }
  else if(field4 == 0)
  {
    setCursorY(10);
    setCursorX(35);
    if(symbol == 1)
    {
      field4 = 2;
      print("O");
    }
    else
    {
      field4 = 1;
      print("X");
    }
  }
  else if(field6 == 0)
  {
    setCursorY(10);
    setCursorX(43);
    if(symbol == 1)
    {
      field6 = 2;
      print("O");
    }
    else
    {
      field6 = 1;
      print("X");
    }
  }
  else if(field8 == 0)
  {
    setCursorY(14);
    setCursorX(39);
    if(symbol == 1)
    {
      field8 = 2;
      print("O");
    }
    else
    {
      field8 = 1;
      print("X");
    }
  }
  
  //Check for win/lose
  if(field1 == 1 && field2 == 1 && field3 == 1)  //Horizontal
  {
    goto shellTicTacToeWin1;
  }
  else if(field1 == 2 && field2 == 2 && field3 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field4 == 1 && field5 == 1 && field6 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field4 == 2 && field5 == 2 && field6 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field7 == 1 && field8 == 1 && field9 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field7 == 2 && field8 == 2 && field9 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field1 == 1 && field5 == 1 && field9 == 1)  //Across
  {
    goto shellTicTacToeWin1;
  }
  else if(field1 == 2 && field5 == 2 && field9 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field7 == 1 && field5 == 1 && field3 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field7 == 2 && field5 == 2 && field3 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field1 == 1 && field4 == 1 && field7 == 1)  //Vertical
  {
    goto shellTicTacToeWin1;
  }
  else if(field1 == 2 && field4 == 2 && field7 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field2 == 1 && field5 == 1 && field8 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field2 == 2 && field5 == 2 && field8 == 2)
  {
    goto shellTicTacToeWin2;
  }
  else if(field3 == 1 && field6 == 1 && field9 == 1)
  {
    goto shellTicTacToeWin1;
  }
  else if(field3 == 2 && field6 == 2 && field9 == 2)
  {
    goto shellTicTacToeWin2;
  }
  
  //Check for tie
  if(field1 != 0 && field2 != 0 && field3 != 0 && field4 != 0 && field5 != 0 && field6 != 0 && field7 != 0 && field8 != 0 && field9 != 0)
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(20), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, "quit"))  //Quit
    {
      return;
    }

    goto shellTicTacToe;
  }
  
  goto shellTicTacToePlayerAtRow;  //Jumps to playerinput
  
  //------------------------------------------------------------
  
  shellTicTacToeWin1:  //Symbol 1 won
  if(symbol == 1)
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(21), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, "quit"))  //Quit
    {
      return;
    }
    
    goto shellTicTacToe;
  }
  else
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(22), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, "quit"))  //Quit
    {
      return;
    }
    
    goto shellTicTacToe;
  }
  
  //------------------------------------------------------------
  
  shellTicTacToeWin2:  //Symbol 2 won
  if(symbol == 2)
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(21), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, "quit"))  //Quit
    {
      return;
    }
    
    goto shellTicTacToe;
  }
  else
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(22), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, "quit"))  //Quit
    {
      return;
    }
    
    goto shellTicTacToe;
  }
}

void shellSettings()  //Shell-settings
{
  shellSettings:
  
  setColor(15, 0);
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored(languagesGetString(35), 0, 15);
  print("\n\n\n\n  ");
  printColored(languagesGetString(7), 0, 7);
  print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  ");
  print(languagesGetString(18));
  
  newInterface(15, 0, 0, 15);
  addButton(1, 2, 6, strlength(languagesGetString(36)), 1, languagesGetString(36));  //LanguageSelector
  addButton(2, 2, 7, strlength(languagesGetString(37)), 1, languagesGetString(37));  //Systeminformation
  addButton(3, 2, 8, strlength(languagesGetString(23)), 1, languagesGetString(23));  //White background support
  addButton(4, 2, 9, strlength(languagesGetString(41)), 1, languagesGetString(41));  //Mouse settings
  selection = runInterface(1, 1);
  
  if(selection == 0)  //Quit
  {
    return;
  }
  if(selection == 1)  //LanguageSelector
  {
    shellLanguageSelector();
    goto shellSettings;
  }
  else if(selection == 2)  //Systeminformation
  {
    shellWhiteBgSupportSettings();
    goto shellSettings;
  }
  else if(selection == 3)  //White background support
  {
    shellSysteminformation();
    goto shellSettings;
  }
  else if(selection == 4)  //Mouse settings
  {
    shellMouseSettings();
    goto shellSettings;
  }
  else  //In case of an error
  {
    kerror();
  }
}

void shellQuitConformationDialog()  //Quit session (Conformation dialog)
{
  selection = showInfobox(languagesGetString(12), languagesGetString(30), 2, 1);
  
  if(selection == 1)
  {
    kend();
  }
  else if(selection == 2)
  {
    return;
  }
  else
  {
    kerror();
  }
}

void shellRebootSystemConformationDialog()  //Reboot system (Conformation dialog)
{
  selection = showInfobox(languagesGetString(13), languagesGetString(33), 2, 1);
  
  if(selection == 1)
  {
    kreboot();
  }
  else if(selection == 2)
  {
    return;
  }
  else
  {
    kerror();
  }
}

void shellLanguageSelector()  //Languageselector
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
    
    input = getNavigation();
    
    if(strEquals(input, "up") && selection != 0)
    {
      selection--;
    }
    else if(strEquals(input, "down") && selection != 2)
    {
      selection++;
    }
    else if(strEquals(input, "quit"))
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

void shellWhiteBgSupportSettings()  //Settings for white background support
{
  setWhiteBgSupport(1);
  setColor(0, 0);
  clear();
  
  printColored(languagesGetString(40), 0, 15);
  selection = showInfobox(languagesGetString(37), languagesGetString(38), 2, 2);
  
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
    kerror();
  }
}

void shellSysteminformation()  //Shell-systeminformation
{
  setColor(15, 0);
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored(languagesGetString(23), 0, 15);
  print("\n\n\n\n  TAKEWAKE Reloaded  Copyright (C) 2019-");
  print(getVersionYear());
  print("  The TAKEWAKE Community");
  print("\n  TAKEWAKE Reloaded is distributed under the GNU General Public License 3.");
  print("\n  For more informations see <https://www.gnu.org/licenses/>.");
  print("\n\n  ");
  print(languagesGetString(24));
  print(getVersion());
  print(" ");
  print(languagesGetString(25));
  print(" ");
  print(getVersionYear());
  print(".");
  print("\n\n\n  ");
  printColored(languagesGetString(26), 0, 7);
  print("\n\n  ");
  print(languagesGetString(27));
  print("\n  ");
  print(languagesGetString(28));
  print("\n\n  ");
  print(languagesGetString(29));
  print("\n\n\n  ");
  print(languagesGetString(18));
  setColor(0, 0);
  while(1)
  {
    input = pause();
    if(strEquals(input, "quit"))
    {
      return;
    }
  }
}

void shellMouseSettings()  //Mouse settings
{
  setColor(15, 0);
  selection = showInfobox(languagesGetString(41), languagesGetString(42), 2, 1);  //Enable mouse support?
  if(selection == 1)  //Yes
  {
    setMouseSupport(1);
  }
  else if(selection == 2)  //No
  {
    setMouseSupport(0);
    showInfobox(languagesGetString(43), languagesGetString(44), 1, 1);
    return;
  }
  
  selection = showInfobox(languagesGetString(41), languagesGetString(49), 2, 2);  //Configure mouse now?
  if(selection == 2)  //No
  {
    return;
  }
  
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored(languagesGetString(41), 0, 15);
  print("\n\n\n   ");
  print(languagesGetString(45));
  print("\n\n    <---<===>--->");
  setCursorX(3);
  setCursorY(6);
  print("[-------------]");
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
      addButton(1, 3, 6, 4, 1, "[-X-");
    }
    else
    {
      addButton(1, 3, 6, 4, 1, "[-I-");
    }
    if(selection2 == 2)
    {
      addButton(2, 8, 6, 5, 1, "--X--");
    }
    else
    {
      addButton(2, 8, 6, 5, 1, "--I--");
    }
    if(selection2 == 3)
    {
      addButton(3, 14, 6, 4, 1, "-X-]");
    }
    else
    {
      addButton(3, 14, 6, 4, 1, "-I-]");
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
    addButton(5, 3, 12, strlength(languagesGetString(39)), 1, languagesGetString(39));
    selection = runInterface(4, 1);
    if(selection == 0 || selection == 5)
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

void oldShellMainMenu()  //Old version of the shell main menu for disabled mouse support
{
  oldShellMainMenu:
  
  setColor(15, 0);
  clear();
  printColored("                               TAKEWAKE  Reloaded                               ", 0, 15);
  print("\n                                   ");
  printColored(languagesGetString(6), 10, 0);
  print("\n\n\n  ");
  printColored(languagesGetString(7), 0, 7);
  
  newInterface(15, 0, 0, 15);
  addButton(1, 2, 7, strlength(languagesGetString(8)), 1, languagesGetString(8));  //Calculator
  addButton(2, 2, 8, strlength(languagesGetString(9)), 1, languagesGetString(9));  //Terminal
  addButton(3, 2, 9, strlength(languagesGetString(10)), 1, languagesGetString(10));  //Tic Tac Toe
  addButton(4, 2, 10, strlength(languagesGetString(35)), 1, languagesGetString(35));  //Settings
  addButton(5, 2, 11, strlength(languagesGetString(12)), 1, languagesGetString(12));  //Quit session (Conformation dialog)
  addButton(6, 2, 12, strlength(languagesGetString(13)), 1, languagesGetString(13));  //Reboot system (Conformation dialog)
  selection = runInterface(1, 0);
  
  if(selection == 1)  //Calculator
  {
    shellCalculator();
    goto oldShellMainMenu;
  }
  else if(selection == 2)  //Terminal
  {
    terminalMain();
    goto oldShellMainMenu;
  }
  else if(selection == 3)  //Tic Tac Toe
  {
    shellTicTacToe();
    goto oldShellMainMenu;
  }
  else if(selection == 4)  //Settings
  {
    shellSettings();
    goto oldShellMainMenu;
  }
  else if(selection == 5)  //Quit session (Conformation dialog)
  {
    shellQuitConformationDialog();
    goto oldShellMainMenu;
  }
  else if(selection == 6)  //Reboot system (Conformation dialog)
  {
    shellRebootSystemConformationDialog();
    goto oldShellMainMenu;
  }
  else  //In case of an error
  {
    kerror();
  }
}
