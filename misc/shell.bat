@echo off

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64
set path=%~dp0..\misc;%~dp0..\build;%path%
cls
