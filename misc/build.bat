@echo off

set build_name=quark-lib-demo.exe

cd..

gcc -Wall -Wextra -ansi -pedantic source\*.c -o %build_name%

