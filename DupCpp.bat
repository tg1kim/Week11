@echo off

IF "%~1"=="" GOTO usage

cd %~1
mkdir Answer
FOR %%l IN (*.cpp) DO copy %%~nxl Answer\%%~nlA.cpp
GOTO end

:usage
@echo Usage:: %~0 path

:end
cd ..
REM