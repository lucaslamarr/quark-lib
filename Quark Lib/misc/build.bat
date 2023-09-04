@echo off
if not exist build mkdir ..\build
pushd ..\build
gcc -ansi -pedantic ..\source\*.c -o quark-lib.exe
popd


