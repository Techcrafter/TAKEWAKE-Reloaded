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

//Programs (with programs.h)

#include "programs.h"

string input;
int selection;

void calculator()  //Calculator
{
  calculator:
  
  setColor(15, 0);
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored(languagesGetString(8), 0, 15);
  print("\n\n\n\n\n    ");
  printCh((char)201);
  printMultipleCh((char)205, 70);
  printCh((char)187);
  print("\n    ");
  printCh((char)186);
  print(languagesGetString(14));
  setCursorX(75);
  printCh((char)186);
  print("\n    ");
  printCh((char)186);
  print("                                                                      ");
  printCh((char)186);
  print("\n    ");
  printCh((char)204);
  printMultipleCh((char)205, 70);
  printCh((char)185);
  print("\n    ");
  printCh((char)186);
  print(languagesGetString(15));
  setCursorX(75);
  printCh((char)186);
  print("\n    ");
  printCh((char)186);
  print("               +            -            *            /               ");
  printCh((char)186);
  print("\n    ");
  printCh((char)186);
  print("                                                                      ");
  printCh((char)186);
  print("\n    ");
  printCh((char)204);
  printMultipleCh((char)205, 70);
  printCh((char)185);
  print("\n    ");
  printCh((char)186);
  print(languagesGetString(16));
  setCursorX(75);
  printCh((char)186);
  print("\n    ");
  printCh((char)186);
  print("                                                                      ");
  printCh((char)186);
  print("\n    ");
  printCh((char)204);
  printMultipleCh((char)205, 70);
  printCh((char)185);
  print("\n    ");
  printCh((char)186);
  print(languagesGetString(17));
  setCursorX(75);
  printCh((char)186);
  print("\n    ");
  printCh((char)186);
  print("                                                                      ");
  printCh((char)186);
  print("\n    ");
  printCh((char)200);
  printMultipleCh((char)205, 70);
  printCh((char)188);
  print("\n\n\n    ");
  print(languagesGetString(18));
  
  setCursorX(6);
  setCursorY(7);
  string str1 = readStr(30);
  if(strEquals(str1, (char)27))  //Quit
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
  selection = runInterface(2, 1, 0);

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
  string str2 = readStr(30);
  if(strEquals(str2, (char)27))  //Quit
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
      kerror("Division by zero");
    }
    int_result = num1 / num2;
  }
  else  //In case of an error
  {
    kerror("Invalid operator");
  }
  
  string str_result = int_to_str(int_result);
  print(str_result);
  
  setColor(0, 0);
  setCursorY(23);
  input = pause();
  if(strEquals(input, (char)27))  //Quit
  {
    return;
  }
  
  goto calculator;
}

void ticTacToe()  //Tic Tac Toe
{
  ticTacToe:
  
  setColor(15, 0);
  clear();
  printColored("                                                                                ", 15, 15);
  plusCursorX();
  minusCursorY();
  printColored("Tic Tac Toe", 0, 15);
  print("\n\n\n\n\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                  ");
  printMultipleCh((char)196, 3);
  printCh((char)197);
  printMultipleCh((char)196, 3);
  printCh((char)197);
  printMultipleCh((char)196, 3);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                  ");
  printMultipleCh((char)196, 3);
  printCh((char)197);
  printMultipleCh((char)196, 3);
  printCh((char)197);
  printMultipleCh((char)196, 3);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
  print("\n                                     ");
  printCh((char)179);
  print("   ");
  printCh((char)179);
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
    
    input = getNavigation(0);
    
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
    else if(strEquals(input, (char)27))  //Quit
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
    ticTacToePlayerAtRow:
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
      
      input = getNavigation(0);
      
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
      else if(strEquals(input, (char)27))  //Quit
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
    goto ticTacToeWin1;
  }
  else if(field1 == 2 && field2 == 2 && field3 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field4 == 1 && field5 == 1 && field6 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field4 == 2 && field5 == 2 && field6 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field7 == 1 && field8 == 1 && field9 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field7 == 2 && field8 == 2 && field9 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field1 == 1 && field5 == 1 && field9 == 1)  //Across
  {
    goto ticTacToeWin1;
  }
  else if(field1 == 2 && field5 == 2 && field9 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field7 == 1 && field5 == 1 && field3 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field7 == 2 && field5 == 2 && field3 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field1 == 1 && field4 == 1 && field7 == 1)  //Vertical
  {
    goto ticTacToeWin1;
  }
  else if(field1 == 2 && field4 == 2 && field7 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field2 == 1 && field5 == 1 && field8 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field2 == 2 && field5 == 2 && field8 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field3 == 1 && field6 == 1 && field9 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field3 == 2 && field6 == 2 && field9 == 2)
  {
    goto ticTacToeWin2;
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
    if(strEquals(input, (char)27))  //Quit
    {
      return;
    }
    else
    {
      goto ticTacToe;
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
    goto ticTacToeWin1;
  }
  else if(field1 == 2 && field2 == 2 && field3 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field4 == 1 && field5 == 1 && field6 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field4 == 2 && field5 == 2 && field6 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field7 == 1 && field8 == 1 && field9 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field7 == 2 && field8 == 2 && field9 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field1 == 1 && field5 == 1 && field9 == 1)  //Across
  {
    goto ticTacToeWin1;
  }
  else if(field1 == 2 && field5 == 2 && field9 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field7 == 1 && field5 == 1 && field3 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field7 == 2 && field5 == 2 && field3 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field1 == 1 && field4 == 1 && field7 == 1)  //Vertical
  {
    goto ticTacToeWin1;
  }
  else if(field1 == 2 && field4 == 2 && field7 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field2 == 1 && field5 == 1 && field8 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field2 == 2 && field5 == 2 && field8 == 2)
  {
    goto ticTacToeWin2;
  }
  else if(field3 == 1 && field6 == 1 && field9 == 1)
  {
    goto ticTacToeWin1;
  }
  else if(field3 == 2 && field6 == 2 && field9 == 2)
  {
    goto ticTacToeWin2;
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
    if(strEquals(input, (char)27))  //Quit
    {
      return;
    }

    goto ticTacToe;
  }
  
  goto ticTacToePlayerAtRow;  //Jumps to playerinput
  
  //------------------------------------------------------------
  
  ticTacToeWin1:  //Symbol 1 won
  if(symbol == 1)
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(21), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, (char)27))  //Quit
    {
      return;
    }
    
    goto ticTacToe;
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
    if(strEquals(input, (char)27))  //Quit
    {
      return;
    }
    
    goto ticTacToe;
  }
  
  //------------------------------------------------------------
  
  ticTacToeWin2:  //Symbol 2 won
  if(symbol == 2)
  {
    setCursorY(19);
    setCursorX(9);
    printColored(languagesGetString(21), 0, 7);
    setCursorY(20);
    setCursorX(0);
    setColor(0, 0);
    input = pause();
    if(strEquals(input, (char)27))  //Quit
    {
      return;
    }
    
    goto ticTacToe;
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
    if(strEquals(input, (char)27))  //Quit
    {
      return;
    }
    
    goto ticTacToe;
  }
}

void degrand()  //Degrand (2D space shooting game)
{
  setColor(15, 0);
  int i = 1;
  int ch = 175;
  int freq = 500;
  string title = " XXXX  XXXX  XXXX  XXXX    XX   X   X XXXX X   X X    X      X   X  X  X  XX  X X   XX   X XXX  X  XX  XXXX  XXXXXX X X X X   XX   X X    X    X X  X  X    X X  XX X   XXXXX  XXXX  XXXX  X   X X    X X   X XXXX";
  degrand:
  
  while(ch != 219)
  {
    clear();
    int s = 0;
    while(s != 500)
    {
      s++;
      setCursor(getRandomInt(0, 79), getRandomInt(0, 24));
      if(getRandomInt(1, 5) == 5)
      {
        printCh((char)254);
      }
      else
      {
        printCh((char)250);
      }
    }
    
    drawBox(17, 2, 46, 9, 2);
    setCursorX(19);
    setCursorY(4);
    if(ch == 178)
    {
      ch = 219;
    }
    else if(ch < 178)
    {
      ch++;
    }
    
    while(i < 210)
    {
      if(title[i] == 'X')
      {
        printCh((char)ch);
      }
      else
      {
        print(" ");
      }
      if(getCursorX() == 61)
      {
        setCursorX(19);
        plusCursorY();
      }
      i++;
    }
    if(freq != 1100)
    {
      playToneForSec(freq, 1);
      if(freq == 700)
      {
        freq = 1000;
      }
      else
      {
        freq += 100;
      }
    }
    
    i = 1;
  }
  ch = 178;
  
  drawBox(23, 14, 34, 7, 1);
  newInterface(15, 0, 0, 15);
  addButton(1, 24+(32-strLength(languagesGetString(53)))/2, 16, strLength(languagesGetString(53)), 1, languagesGetString(53));
  addButton(2, 24+(32-strLength(languagesGetString(54)))/2, 17, strLength(languagesGetString(54)), 1, languagesGetString(54));
  addButton(3, 24+(32-strLength(languagesGetString(55)))/2, 18, strLength(languagesGetString(55)), 1, languagesGetString(55));
  selection = runInterface(5, 1, 0);
  if(selection == 0 || selection == 3)  //Quit
  {
    return;
  }
  else if(selection == 1)  //Start game
  {
    goto degrandGame;
  }
  else if(selection == 2)  //How to play
  {
    newWindow(languagesGetString(54), 1, 1);
    setCursor(2, 4);
    print(languagesGetString(54));
    newInterface(15, 0, 0, 15);
    selection = runInterface(5, 1, 0);
    if(selection == 0)  //Back to main menu
    {
      //Do nothing, just continue
    }
    else  //Invalid selection
    {
      kerror("Invalid selection");
    }
  }
  else  //Invalid selection
  {
    kerror("Invalid selection");
  }
  
  goto degrand;
  
  //Game
  degrandGame:
  clear();
  drawBox(25, 8, 30, 6, 2);
  setCursor(26+(28-strLength(languagesGetString(56)))/2, 10);
  print(languagesGetString(56));
  int highscore = 100000;  //Replace '100000' with command for getting real highscore
  setCursor(26+(28-strLength(int_to_str(highscore)))/2, 11);
  print(int_to_str(highscore));
  setCursor(39-strLength(languagesGetString(52))/2, 18);
  print(languagesGetString(52));
  int lifes = 3;
  int oldLifes = 0;
  int score = 0;
  int oldScore = -1;
  int playerX = 5;
  int playerY = 12;
  int oldPlayerX = 4;
  int oldPlayerY = 12;
  int playerMissile1X = -1;
  int playerMissile1Y = -1;
  int playerMissile2X = -1;
  int playerMissile2Y = -1;
  int playerMissile3X = -1;
  int playerMissile3Y = -1;
  int playerMissile4X = -1;
  int playerMissile4Y = -1;
  int playerMissile5X = -1;
  int playerMissile5Y = -1;
  wait(2);
  clear();
  print(languagesGetString(57));
  setCursorX(34);
  printCh((char)174);
  print(" DEGRAND ");
  printCh((char)175);
  setCursorX(80-strLength(languagesGetString(58)));
  print(languagesGetString(58));
  setCursor(0, 2);
  printMultipleCh((char)196, 80);
  
  while(1)
  {
    if(lifes != oldLifes)  //Print lifes
    {
      if(lifes <= 0)
      {
        goto degrandGameOver;
      }
      else
      {
        setCursor(0, 1);
        printMultipleCh((char)32, oldLifes);
        setCursor(0, 1);
        printMultipleColoredCh((char)3, lifes, 4, 0);
      }
    }
    
    if(score != oldScore)  //Print score
    {
      setCursor(80-strLength(int_to_str(score)) , 1);
      if(score <= highscore)
      {
        print(int_to_str(score));
      }
      else
      {
        highscore = score;
        printColored(int_to_str(score), 14, 0);
      }
    }
    
    //Get input
    input = getNavigation(200000);
    if(strEquals(input, "up") && playerY != 4)  //Up
    {
      playerY--;
    }
    else if(strEquals(input, "down") && playerY != 23)  //Down
    {
      playerY++;
    }
    else if(strEquals(input, "left") && playerX != 0)  //Left
    {
      playerX--;
    }
    else if(strEquals(input, "right") && playerX != 78)  //Right
    {
      playerX++;
    }
    else if(strEquals(input, "space"))  //Shoot
    { 
      if(playerMissile1X == -1 && playerMissile1Y == -1)
      {
        playerMissile1X = playerX + 2;
        playerMissile1Y = playerY;
      }
      else if(playerMissile2X == -1 && playerMissile2Y == -1)
      {
        playerMissile2X = playerX + 2;
        playerMissile2Y = playerY;
      }
      else if(playerMissile3X == -1 && playerMissile3Y == -1)
      {
        playerMissile3X = playerX + 2;
        playerMissile3Y = playerY;
      }
      else if(playerMissile4X == -1 && playerMissile4Y == -1)
      {
        playerMissile4X = playerX + 2;
        playerMissile4Y = playerY;
      }
      else if(playerMissile5X == -1 && playerMissile5Y == -1)
      {
        playerMissile5X = playerX + 2;
        playerMissile5Y = playerY;
      }
    }
    else if(strEquals(input, (char)27))  //Escape
    {
      goto degrandGameOver;
    }
    
    //Print player
    if(playerX != oldPlayerX || playerY != oldPlayerY)
    {
      //Remove old
      setCursor(oldPlayerX, oldPlayerY-1);
      print(" ");
      setCursor(oldPlayerX, oldPlayerY);
      print("  ");
      setCursor(oldPlayerX, oldPlayerY+1);
      print(" ");
      
      //Draw new one
      setCursor(playerX, playerY-1);
      printColoredCh((char)175, 4, 0);
      setCursor(playerX, playerY);
      print("<>");
      setCursor(playerX, playerY+1);
      printColoredCh((char)175, 4, 0);
      
      //Set old variables to new one
      oldPlayerX = playerX;
      oldPlayerY = playerY;
    }
    
    //Move/print player missiles
    if(playerMissile1X != -1 && playerMissile1Y != -1)
    {
      setCursor(playerMissile1X, playerMissile1Y);
      print(" ");
      playerMissile1X++;
      if(playerMissile1X >= 80)
      {
        playerMissile1X = -1;
        playerMissile1Y = -1;
      }
      else
      {
        printColoredCh((char)254, 14, 0);
      }
    }
    if(playerMissile2X != -1 && playerMissile2Y != -1)
    {
      setCursor(playerMissile2X, playerMissile2Y);
      print(" ");
      playerMissile2X++;
      if(playerMissile2X >= 80)
      {
        playerMissile2X = -1;
        playerMissile2Y = -1;
      }
      else
      {
        printColoredCh((char)254, 14, 0);
      }
    }
    if(playerMissile3X != -1 && playerMissile3Y != -1)
    {
      setCursor(playerMissile3X, playerMissile3Y);
      print(" ");
      playerMissile3X++;
      if(playerMissile3X >= 80)
      {
        playerMissile3X = -1;
        playerMissile3Y = -1;
      }
      else
      {
        printColoredCh((char)254, 14, 0);
      }
    }
    if(playerMissile4X != -1 && playerMissile4Y != -1)
    {
      setCursor(playerMissile4X, playerMissile4Y);
      print(" ");
      playerMissile4X++;
      if(playerMissile4X >= 80)
      {
        playerMissile4X = -1;
        playerMissile4Y = -1;
      }
      else
      {
        printColoredCh((char)254, 14, 0);
      }
    }
    if(playerMissile5X != -1 && playerMissile5Y != -1)
    {
      setCursor(playerMissile5X, playerMissile5Y);
      print(" ");
      playerMissile5X++;
      if(playerMissile5X >= 80)
      {
        playerMissile5X = -1;
        playerMissile5Y = -1;
      }
      else
      {
        printColoredCh((char)254, 14, 0);
      }
    }
  }
  
  goto degrand;
  
  //Game over
  degrandGameOver:
  drawBox(27, 4, 26, 16, 2);
  setCursor(35, 5);
  printColored("GAME OVER", 4, 0);
  setCursor(35, 6);
  printMultipleCh((char)196, 9);
  setCursor(29, 8);
  print(languagesGetString(58));
  setCursor(29, 9);
  print(int_to_str(score));
  setCursor(29, 11);
  print(languagesGetString(56));
  setCursor(29, 12);
  print(int_to_str(highscore));
  newInterface(15, 0, 0, 15);
  addButton(1, 28+(24-strLength(languagesGetString(59)))/2, 15, strLength(languagesGetString(59)), 1, languagesGetString(59));
  addButton(2, 28+(24-strLength(languagesGetString(60)))/2, 16, strLength(languagesGetString(60)), 1, languagesGetString(60));
  selection = runInterface(5, 1, 0);
  if(selection == 0 || selection == 2)
  {
    goto degrand;
  }
  else if(selection == 1)
  {
    goto degrandGame;
  }
  else
  {
    kerror("Invalid selection");
  }
}
