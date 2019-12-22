#    This file is part of TAKEWAKE Reloaded.
#    TAKEWAKE Reloaded, a free operating system in C and ASM
#    Copyright (C) 2019  The TAKEWAKE Community
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.

#Building the OS

#echo Compiling kernel/kernel.asm to objects/kasm.o...
#nasm -f elf32 kernel/kernel.asm -o objects/kasm.o
#echo Done
echo Compiling kernel/kernel.c to objects/kc.o...
gcc -m32 -c kernel/kernel.c -o objects/kc.o -ffreestanding
echo Done

echo Compiling modules/display.c to objects/display.o...
gcc -m32 -c modules/display.c -o objects/display.o -ffreestanding
echo Done
echo Compiling modules/input.c to objects/input.o...
gcc -m32 -c modules/input.c -o objects/input.o -ffreestanding
echo Done
echo Compiling modules/interface.c to objects/interface.o...
gcc -m32 -c modules/interface.c -o objects/interface.o -ffreestanding
echo Done
echo Compiling system/languages.c to objects/languages.o...
gcc -m32 -c system/languages.c -o objects/languages.o -ffreestanding
echo Done
echo Compiling system/shell.c to objects/shell.o...
gcc -m32 -c system/shell.c -o objects/shell.o -ffreestanding
echo Done
echo Compiling modules/sound.c to objects/sound.o...
gcc -m32 -c modules/sound.c -o objects/sound.o -ffreestanding
echo Done
echo Compiling modules/string.c to objects/string.o...
gcc -m32 -c modules/string.c -o objects/string.o -ffreestanding
echo Done
echo Compiling modules/system.c to objects/system.o...
gcc -m32 -c modules/system.c -o objects/system.o -ffreestanding
echo Done
echo Compiling system/terminal.c to objects/terminal.o...
gcc -m32 -c system/terminal.c -o objects/terminal.o -ffreestanding
echo Done
echo Compiling modules/time.c to objects/time.o...
gcc -m32 -c modules/time.c -o objects/time.o -ffreestanding
echo Done
echo Compiling modules/utilities.c to objects/utilities.o...
gcc -m32 -c modules/utilities.c -o objects/utilities.o -ffreestanding
echo Done
echo Linking all files to TAKEWAKE-Reloaded.bin...
ld -m elf_i386 -T link.ld -o TAKEWAKE-Reloaded/boot/TAKEWAKE-Reloaded.bin objects/kasm.o objects/kc.o objects/display.o objects/input.o objects/interface.o objects/languages.o objects/shell.o objects/sound.o objects/string.o objects/system.o objects/terminal.o objects/time.o objects/utilities.o
echo Done
echo Building .iso file...
grub-mkrescue -o OUTPUT/TAKEWAKE-Reloaded.iso TAKEWAKE-Reloaded/
echo Done
echo ________________________________________________________________________
echo BUILDING DONE
#Building completed

#Start QEMU to test
echo Running QEMU...
qemu-system-i386 -cdrom OUTPUT/TAKEWAKE-Reloaded.iso -d guest_errors -soundhw pcspk
echo Done

echo Waiting...
read null #Pause script
./build.sh #Build again
