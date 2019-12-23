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

#ifndef SETTINGS_H
#define SETTINGS_H

//Including the modules
#include "../modules/display.h"
#include "../modules/input.h"
#include "../modules/interface.h"
#include "../modules/string.h"
#include "../modules/system.h"
#include "../modules/time.h"
#include "../modules/types.h"
#include "../modules/utilities.h"

//Including the systemelements
#include "languages.h"

void settings();  //Settings

void languageSelector();  //Language selector

void whiteBgSupportSettings();  //Settings for white background support

void systeminformation();  //Systeminformation

void mouseSettings();  //Mouse settings

#endif
