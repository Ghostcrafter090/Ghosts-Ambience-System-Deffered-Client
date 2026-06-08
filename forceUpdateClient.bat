set client=%~1
set file=%~2

:loop
xcopy "%file%" "%client%\ambience_client\%file%" /c /y && goto end
goto loop

:end