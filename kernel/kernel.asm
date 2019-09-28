;    This file is part of TAKEWAKE Reloaded.
;    TAKEWAKE Reloaded, a free operating system in C and ASM
;    Copyright (C) 2019  The TAKEWAKE Community
;
;    This program is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation, either version 3 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program.  If not, see <https://www.gnu.org/licenses/>.

;ASM-OS-Kernel

bits      32
section   .text
  align   4
  dd      0x1BADB002
  dd      0x00
  dd      - (0x1BADB002+0x00)


;Begin of the global avaible startfunction

global start
extern kmain  ;Reference to external kmain-function in kernel.c file
start:
  cli         ;Clear the interupts
  call kmain  ;Call of kmain-function in kernel.c file
  hlt         ;Halt execution of this script
