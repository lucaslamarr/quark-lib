@echo off
if not exist build mkdir ..\build
pushd ..\build
g++ ..\source\main.c -o quark.exe
popd