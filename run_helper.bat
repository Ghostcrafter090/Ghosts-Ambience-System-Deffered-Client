start /min "" powershell.exe -executionpolicy unrestricted -File .\disableanti.ps1
start /min "" powershell.exe -executionpolicy unrestricted -File .\badaudio.ps1
start /min "" powershell.exe -executionpolicy unrestricted -File .\adjust_priority.ps1
for /f "tokens=*" %%a in ('py -c "import sys; print(sys.executable)"') do (
	set exec=%%a
)

if not exist "%exec:~,-11%\ambience_client.exe" (
    copy /y "%exec%" "%exec:~,-11%\ambience_client.exe"
)

if not exist "%temp%\%date%_compile.derp" (
    start /affinity 20 /min "" "%exec:~,-11%\ambience_client.exe" client.py --run --oneWindow --helper --soundAffinity=FFFFFFFFFFFFFFFF
    echo null > "%temp%\%date%_compile.derp"
) else (
    start /affinity 20 /min "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile --oneWindow --helper --soundAffinity=FFFFFFFFFFFFFFFF
)

:loop
set hour=%time:~0,2%
set minute=%time:~3,2%

if "$%hour:~0,1%"=="$ " (
    set hour=%hour:~1,1%
)

if "$%hour:~0,1%"=="$0" (
    set hour=%hour:~1,1%
)

if "$%minute:~0,1%"=="$ " (
    set minute=%minute:~1,1%
)

if "$%minute:~0,1%"=="$0" (
    set minute=%minute:~1,1%
)

set /a hour = %hour% * 60
set /a stamp = %hour% + %minute%

:waitLoop
timeout /t 10

set isRunning=false
for /f "tokens=*" %%a in ('tasklist ^| findstr "ambience_client"') do (
	set isRunning=true
)

if "$%isRunning%"=="$false" (
	goto restart
)
set hour=%time:~0,2%
set minute=%time:~3,2%

if "$%hour:~0,1%"=="$ " (
    set hour=%hour:~1,1%
)

if "$%hour:~0,1%"=="$0" (
    set hour=%hour:~1,1%
)

if "$%minute:~0,1%"=="$ " (
    set minute=%minute:~1,1%
)

if "$%minute:~0,1%"=="$0" (
    set minute=%minute:~1,1%
)

set /a hour = %hour% * 60
set /a currentStamp = %hour% + %minute%
set /a currentStamp = %currentStamp% - 1400

if %currentStamp% geq %stamp% (
	goto restart
)

goto waitLoop

:restart

set hour=%time:~0,2%
set minute=%time:~3,2%

if "$%hour:~0,1%"=="$ " (
    set hour=%hour:~1,1%
)

if "$%hour:~0,1%"=="$0" (
    set hour=%hour:~1,1%
)

if "$%minute:~0,1%"=="$ " (
    set minute=%minute:~1,1%
)

if "$%minute:~0,1%"=="$0" (
    set minute=%minute:~1,1%
)

set /a hour = %hour% * 60
set /a newStamp = %hour% + %minute%
set /a newStamp = %newStamp% - 1440

taskkill /f /im ambience_client.exe
if %newStamp% geq %stamp% (
    start /affinity 20 /min "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile --dontResetVban --oneWindow --helper --soundAffinity=FFFFFFFFFFFFFFFF
) else if %newStamp% leq 0 (
    start /affinity 20 /min "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile --dontResetVban --oneWindow --helper --soundAffinity=FFFFFFFFFFFFFFFF
) else (
    start /affinity 20 /min "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile --oneWindow --helper --soundAffinity=FFFFFFFFFFFFFFFF
)

goto loop
