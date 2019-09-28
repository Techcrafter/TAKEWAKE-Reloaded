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

//Utilities for Memorymanagement and other things (with utilities.c)

#ifndef UTILITIES_H
#define UTILITIES_H

#include "types.h"

void memory_copy(char *source, char *dest, int nbytes);  //Copys data inside the memory

void memory_set(uint8 *dest, uint8 val, uint32 len);  //Writes data into the memory

void int_to_ascii(int n, char str[]);  //Converts int to ascii

string int_to_str(int n);  //Converts int to string

int str_to_int(string ch);  //Converts string to int

void * malloc(int nbytes);

#endif
