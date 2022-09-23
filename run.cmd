@echo off
setlocal

chcp 936 >nul

set "EXE=%~dp0x64\Debug\Assignment.exe"

if not exist "%EXE%" (
    echo Assignment.exe was not found.
    echo Please build the project first in Visual Studio using Debug ^| x64.
    echo Expected location:
    echo %EXE%
    echo.
    pause
    exit /b 1
)

pushd "%~dp0x64\Debug"
Assignment.exe
popd

echo.
pause