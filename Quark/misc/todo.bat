@echo off
cls
pushd ..\source
echo LIST OF EVERY FILE AND LINE NUMBER THAT CONTAINS A TODO: COMMENT
echo:
findstr /s /i /N TODO: *.c *cpp *h *hpp
popd
pause >nul

