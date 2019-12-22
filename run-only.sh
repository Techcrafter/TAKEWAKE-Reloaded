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

#Run OS in QEMU to test it

#Run QEMU to test the OS
echo Running QEMU...
qemu-system-i386 -cdrom OUTPUT/TAKEWAKE-Reloaded.iso -d guest_errors -m 2G -soundhw pcspk
echo Done
