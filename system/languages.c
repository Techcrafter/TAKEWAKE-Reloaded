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

//Contains different languages for the OS (with languages.h)

#include "languages.h"

int language = 0;  //Set default language to English (USA)

void languagesSetLanguage(int newLanguage)  //Set new language
{
  language = newLanguage;
}

int languagesGetLanguage()  //Return language
{
  return language;
}

int languagesGetKbLayout()  //Returns keyboard layout for the selected language
{
  if(language == 0 || language == 1)
  {
    return 0;
  }
  else if(language == 2)
  {
    return 1;
  }
  else
  {
    languagesSetLanguage(0);
    kfatal("Invalid language (kbLayout)");
  }
}

string languagesGetString(int stringNumber)
{
  if(language == 0)
  {
    return language_en_us[stringNumber];
  }
  else if(language == 1)
  {
    return language_en_uk[stringNumber];
  }
  else if(language == 2)
  {
    return language_de_de[stringNumber];
  }
  else
  {
    languagesSetLanguage(0);
    kfatal("Invalid language");
  }
}

//Languages
string language_en_us[] = {  //English (United States)
  "     Press [Enter] to continue...",
  "        Sorry, an error has occurred.",
  "  If that's happening often, please report this error.",
  "          Sorry, a fatal error has occurred.",
  "Press [Enter] to restart the computer...",
  "   You can turn off the computer now.",  //5
  "Welcome!",
  "Please select a Menuentry:",
  "Calculator",
  "Terminal",
  "User",  //10
  "Systeminformations",
  "Quit session",
  "Reboot system",
  "Number 1:",
  "Operator:",  //15
  "Number 2:",
  "Summary:",
  "Press [ESC] to quit...",
  "Please select a symbol:",
  "Tie!   [Enter] -> New match   [ESC] -> Quit                   ",  //20
  "You win!   [Enter] -> New match   [ESC] -> Quit               ",
  "You lose!   [Enter] -> New match   [ESC] -> Quit              ",
  "Systeminformations",
  "You're using systemversion ",
  "from the year",  //25
  "About TAKEWAKE Reloaded",
  "TAKEWAKE Reloaded is a free operating system by the TAKEWAKE Community.",
  "The project was started in 2019.",
  "Thank you for choosing TAKEWAKE Reloaded.",
  "Do you really want to quit the session?",  //30
  "Yes",
  "No",
  "Do you really want to reboot the system?",
  "Rebooting...",
  "Settings",  //35
  "Change language",
  "White background support",
  "Please follow the instructions at the top left.",
  "OK",
  "Select 'No' if this text is blinking, else 'Yes'.",  //40
  "Mouse settings",
  "Do you want to enable mouse support?",
  "Information",
  "The terminal will be used instead of the shell.",
  "Set the pointer speed of your mouse below.",  //45
  "Error!",
  "Mouse support needs to be enabled for this action.",
  "Need doubleclick",
  "Do you want to configure the mouse now?",
  "Session",  //50
  "Cancel",
  "Please wait..."
};

string language_en_uk[] = {  //English (United Kingdom)
  "     Press [Enter] to continue...",
  "        Sorry, an error has occurred.",
  "  If that's happening often, please report this error.",
  "          Sorry, a fatal error has occurred.",
  "Press [Enter] to restart the computer...",
  "   You can turn off the computer now.",  //5
  "Welcome!",
  "Please select a Menuentry:",
  "Calculator",
  "Terminal",
  "User",  //10
  "Systeminformations",
  "Quit session",
  "Reboot system",
  "Number 1:",
  "Operator:",  //15
  "Number 2:",
  "Summary:",
  "Press [ESC] to quit...",
  "Please select a symbol:",
  "Tie!   [Enter] -> New match   [ESC] -> Quit                   ",  //20
  "You win!   [Enter] -> New match   [ESC] -> Quit               ",
  "You lose!   [Enter] -> New match   [ESC] -> Quit              ",
  "Systeminformations",
  "You're using systemversion ",
  "from the year",  //25
  "About TAKEWAKE Reloaded",
  "TAKEWAKE Reloaded is a free operating system by the TAKEWAKE Community.",
  "The project was started in 2019.",
  "Thank you for choosing TAKEWAKE Reloaded.",
  "Do you really want to quit the session?",  //30
  "Yes",
  "No",
  "Do you really want to reboot the system?",
  "Rebooting...",
  "Settings",  //35
  "Change language",
  "White background support",
  "Please follow the instructions at the top left.",
  "OK",
  "Select 'No' if this text is blinking, else 'Yes'.",  //40
  "Mouse settings",
  "Do you want to enable mouse support?",
  "Information",
  "The terminal will be used instead of the shell.",
  "Set the pointer speed of your mouse below.",  //45
  "Error!",
  "Mouse support needs to be enabled for this action.",
  "Need doubleclick",
  "Do you want to configure the mouse now?",
  "Session",  //50
  "Cancel",
  "Please wait..."
};

string language_de_de[] = {  //German/Deutsch (Deutschland)
  "Druecken sie [Enter] zum Fortfahren...",
  "Entschuldigung, es ist ein Fehler aufgetreten.",
  "Wenn dies oefters passiert, melden sie diesen Fehler bitte.",
  "Entschuldigung, es ist ein fataler Fehler aufgetreten.",
  "  Druecken sie [Enter] zum neustarten...",
  "Sie koennen den Computer nun abschalten.",  //5
  "Wilkommen!",
  "Bitte waehlen sie einen Menueintrag aus:",
  "Taschenrechner",
  "Terminal",
  "Benutzer",  //10
  "Systeminformationen",
  "Sitzung beenden",
  "System neustarten",
  "Zahl 1:",
  "Operator:",  //15
  "Zahl 2:",
  "Ergebnis:",
  "Zum verlassen [ESC] druecken...",
  "Waehlen sie ein Zeichen:",
  "Unentschieden!   [Enter] -> Neues Spiel   [ESC] -> Verlassen  ",  //20
  "Gewonnen!   [Enter] -> Neues Spiel   [ESC] -> Verlassen       ",
  "Leider Verloren!   [Enter] -> Neues Spiel   [ESC] -> Verlassen",
  "Systeminformationen",
  "Sie benutzen Systemversion ",
  "aus dem Jahr",  //25
  "Ueber TAKEWAKE Reloaded",
  "TAKEWAKE Reloaded ist ein freies Betriebssystem der TAKEWAKE Community.",
  "Es enstand in dem Jahr 2019.",
  "Vielen Dank dass sie sich fuer TAKEWAKE Reloaded entschieden haben.",
  "Moechten sie die Sitzung wirklich beenden?",  //30
  "Ja",
  "Nein",
  "Moechten die das System wirklich neustarten?",
  "Neustarten...",
  "Einstellungen",  //35
  "Sprache aendern",
  "Unterstuetzung von weissem Hintergrund",
  "Bitte die Anweisungen oben links befolgen.",
  "OK",
  "'Nein' waehlen falls dieser Text blinkt, sonst 'Ja'.",  //40
  "Mauseinstellungen",
  "Moechten sie die Maus aktivieren?",
  "Hinweis",
  "Das Terminal wird anstelle der Shell verwendet.",
  "Stellen sie unten die Zeigergeschwindigkeit ihrer Maus ein.",  //45
  "Fehler!",
  "Fuer diese Aktion muss die Maus aktiviert sein.",
  "Doppelklick benoetigt",
  "Moechten sie die Maus jetzt konfigurieren?",
  "Sitzung",  //50
  "Abbrechen",
  "Bitte warten..."
};
