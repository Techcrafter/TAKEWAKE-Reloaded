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

//Contains different languages for the OS (with languages.c)

#ifndef LANGUAGES_H
#define LANGUAGES_H

//Including the modules
#include "../modules/display.h"
#include "../modules/input.h"
#include "../modules/string.h"
#include "../modules/system.h"
#include "../modules/types.h"
#include "../modules/utilities.h"

int language;

void languagesSetLanguage(int newLanguage);  //Set new language

int languagesGetLangugae();  //Return language

int languagesGetKbLayout();  //Returns keyboard layout for the selected language

string languagesGetString(int stringNumber);  //Returns string (no. number) in choosen language

//Languages
string language_en_us[];  //English (United States)

string language_en_uk[];  //English (United Kingdom)

string language_de_de[];  //German/Deutsch (Deutschland)

#endif
