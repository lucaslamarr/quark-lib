@echo off
cls
if not exist build mkdir ..\build
pushd ..\build
start quark-lib.exe
popd


