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

#echo Compiling kernel/kernel.asm to objects/kasm.o...  #kernel/kernel.asm
#nasm -f elf32 kernel/kernel.asm -o objects/kasm.o
#echo Done
echo Compiling kernel/kernel.c to objects/kc.o...  #kernel/kernel.c
gcc -m32 -c kernel/kernel.c -o objects/kc.o -ffreestanding
echo Done

echo Compiling modules/display.c to objects/display.o...  #modules/display.c
gcc -m32 -c modules/display.c -o objects/display.o -ffreestanding
echo Done
echo Compiling modules/input.c to objects/input.o...  #modules/input.c
gcc -m32 -c modules/input.c -o objects/input.o -ffreestanding
echo Done
echo Compiling modules/interface.c to objects/interface.o...  #modules/interface.c
gcc -m32 -c modules/interface.c -o objects/interface.o -ffreestanding
echo Done
echo Compiling system/languages.c to objects/languages.o...  #system/languages.c
gcc -m32 -c system/languages.c -o objects/languages.o -ffreestanding
echo Done
echo Compiling system/programs.c to objects/programs.o...  #system/programs.c
gcc -m32 -c system/programs.c -o objects/programs.o -ffreestanding
echo Done
echo Compiling modules/random.c to objects/random.o...  #modules/random.c
gcc -m32 -c modules/random.c -o objects/random.o -ffreestanding
echo Done
echo Compiling system/settings.c to objects/settings.o...  #system/settings.c
gcc -m32 -c system/settings.c -o objects/settings.o -ffreestanding
echo Done
echo Compiling system/shell.c to objects/shell.o...  #system/shell.c
gcc -m32 -c system/shell.c -o objects/shell.o -ffreestanding
echo Done
echo Compiling modules/sound.c to objects/sound.o...  #modules/sound.c
gcc -m32 -c modules/sound.c -o objects/sound.o -ffreestanding
echo Done
echo Compiling modules/string.c to objects/string.o...  #modules/string.c
gcc -m32 -c modules/string.c -o objects/string.o -ffreestanding
echo Done
echo Compiling modules/system.c to objects/system.o...  #modules/system.c
gcc -m32 -c modules/system.c -o objects/system.o -ffreestanding
echo Done
echo Compiling system/terminal.c to objects/terminal.o...  #system/terminal.c
gcc -m32 -c system/terminal.c -o objects/terminal.o -ffreestanding
echo Done
echo Compiling modules/time.c to objects/time.o...  #modules/time.c
gcc -m32 -c modules/time.c -o objects/time.o -ffreestanding
echo Done
echo Compiling modules/utilities.c to objects/utilities.o...  #modules/utilities.c
gcc -m32 -c modules/utilities.c -o objects/utilities.o -ffreestanding
echo Done
echo Linking all files to TAKEWAKE-Reloaded.bin...  #Linking all files
ld -m elf_i386 -T link.ld -o TAKEWAKE-Reloaded/boot/TAKEWAKE-Reloaded.bin objects/kasm.o objects/kc.o objects/display.o objects/input.o objects/interface.o objects/languages.o objects/programs.o objects/random.o objects/settings.o objects/shell.o objects/sound.o objects/string.o objects/system.o objects/terminal.o objects/time.o objects/utilities.o
echo Done
echo Building .iso file...  #Building .iso
grub-mkrescue -o OUTPUT/TAKEWAKE-Reloaded.iso TAKEWAKE-Reloaded/
echo Done
echo ________________________________________________________________________
echo BUILDING DONE
#Building completed

#Start QEMU to test
echo Running QEMU...  #Testing in QEMU
qemu-system-i386 -cdrom OUTPUT/TAKEWAKE-Reloaded.iso -d guest_errors -soundhw pcspk
echo Done

echo Waiting...
read null #Pause script
./build.sh #Build again
