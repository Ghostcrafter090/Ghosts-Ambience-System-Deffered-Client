start /min "" powershell.exe -executionpolicy unrestricted -File .\disableanti.ps1
:loop
del speakerSets.json /s /q
py client.py --run
goto loop
