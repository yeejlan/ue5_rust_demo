@echo off

set PROJECT=Nexus

set WORK_DIR=%~dp0
set WORK_DIR=%WORK_DIR:~0,-1%

set UPROJ_FILE=%WORK_DIR%\%PROJECT%.uproject

set UE_DIR=D:\EpicGames\UE_5.4
set UE_EDITOR_FILE=%UE_DIR%\Engine\Binaries\Win64\UnrealEditor.exe

set BAT_DIR=%UE_DIR%\Engine\Build\BatchFiles
set BUILD_BAT_FILE=%BAT_DIR%\Build.bat
set UAT_BAT_FILE=%BAT_DIR%\RunUAT.bat
