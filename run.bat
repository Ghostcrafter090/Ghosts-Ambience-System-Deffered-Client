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
    start /wait /high "" "%exec:~,-11%\ambience_client.exe" client.py --run
    echo null > "%temp%\%date%_compile.derp"
) else (
    start /wait /high "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile
)

:loop
taskkill /f /im ambience_client.exe
start /wait /high "" "%exec:~,-11%\ambience_client.exe" client.py --run --skipCompile
goto loop
