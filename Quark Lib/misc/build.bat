@echo off

set build_name=quark-lib.exe

if not exist build mkdir ..\build
pushd ..\build
gcc -Wall -Wextra -ansi -pedantic ..\source\*.c -o %build_name%
popd

