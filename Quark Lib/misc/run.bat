@echo off
cls

set build_name=quark-lib.exe

if exist ..\build (
	pushd ..\build
	start build_name
)
popd