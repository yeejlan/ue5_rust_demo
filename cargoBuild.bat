
call %~dp0env.bat

set PLUGIN=RustPlugin
set PLUGIN_DIR=%WORK_DIR%\Plugins\%PLUGIN%

PUSHD "%PLUGIN_DIR%" 

rem cargo build --release -vv

cargo build --release


POPD