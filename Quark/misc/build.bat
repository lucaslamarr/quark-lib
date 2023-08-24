@echo off
if not exist build mkdir ..\build
pushd ..\build
gcc ..\source\*.c -o quark.exe
popd


