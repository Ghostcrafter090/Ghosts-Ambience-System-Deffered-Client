start /min "" powershell.exe -executionpolicy unrestricted -File .\disableanti.ps1
start /min "" powershell.exe -executionpolicy unrestricted -File .\badaudio.ps1
start /min "" powershell.exe -executionpolicy unrestricted -File .\adjust_priority.ps1
for /f "tokens=*" %%a in ('py -c "import sys; print(sys.executable)"') do (
	set exec=%%a
)

if not exist "%exec:~,-11%\ambience_client.exe" (
    copy /y "%exec%" "%exec:~,-11%\ambience_client.exe"
)

if not exist "%exec:~,-11%\ambience.exe" (
    copy /y "%exec%" "%exec:~,-11%\ambience.exe"
)

if not exist "%temp%\%date%_compile.derp" (
    start /high "" "%exec:~,-11%\ambience_client.exe" client.py --run
    echo null > "%temp%\%date%_compile.derp"
) else (
    start /high "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile
)

:loop
set hour=%time:~0,2%
set minute=%time:~3,2%

if "$%hour:~0,1%"=="$ " (
    set hour=%hour:~1,1%
)

set /a hour = %hour% * 60
set /a stamp = %hour% + %minute%

timeout /t 86400

set hour=%time:~0,2%
set minute=%time:~3,2%

if "$%hour:~0,1%"=="$ " (
    set hour=%hour:~1,1%
)

set /a hour = %hour% * 60
set /a newStamp = %hour% + %minute%
set /a newStamp = %newStamp% - 1440

taskkill /f /im ambience_client.exe
if %newStamp% geq %stamp% (
    start /high "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile --dontResetVban
) else if %newStamp% leq 0 (
    start /high "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile --dontResetVban
) else (
    start /high "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile
)

goto loop
