echo Starting Install...
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe
taskkill /f /im explorer.exe

start /wait /max "" ".\drivers\python\python-3.11.2-amd64.exe" InstallAllUsers=0 Include_launcher=1 InstallLauncher=1 InstallLauncherAllUsers=1 Include_test=0 SimpleInstall=1 SimpleInstallDescription="Just for me, no test suite." /passive
start /wait /max "" ".\drivers\voicemeeter\Voicemeeter8Setup.exe" -i -h
start /wait /max "" ".\drivers\cable64\VBCABLE_Setup_x64.exe" -i -h

mkdir .\sound
mkdir .\sound\assets

rem py install.py

py
