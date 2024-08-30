
call %~dp0env.bat

REM call "%BUILD_BAT_FILE%" %PROJECT%Editor Win64 Development "%UPROJ_FILE%" -waitmutex -NoHotReload

call "%BUILD_BAT_FILE%" %PROJECT%Editor Win64 Development "%UPROJ_FILE%" -mode=GenerateClangDatabase 

if not exist "%~dp0compile_commands.json" (
    mklink "%~dp0compile_commands.json" "%UE_DIR%\compile_commands.json"
    if errorlevel 1 echo Failed to create symbolic link.
)else (
    echo compile_commands.json exists, skip symbolic link.
)
