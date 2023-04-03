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

start /wait /max "" ".\drivers\python\python-3.11.2-amd64.exe"
start /wait /max "" ".\drivers\voicemeeter\Voicemeeter8Setup.exe"
start /wait /max "" ".\drivers\cable64\VBCABLE_Setup_x64.exe"

mkdir .\sound
mkdir .\sound\assets

py install.py
