@echo off

call %~dp0env.bat

start "%UE_EDITOR_FILE%" "%UPROJ_FILE%" %*
