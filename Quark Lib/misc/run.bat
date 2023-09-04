@echo off
cls
if exist ..\build (
	pushd ..\build
	start quark-lib.exe
)
popd




