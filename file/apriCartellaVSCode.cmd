@echo off
setlocal enabledelayedexpansion

REM Chiedi all'utente il nome della cartella
set /p foldername=Inserisci il nome della cartella da cercare:

REM Imposta il disco di partenza (puoi cambiarlo se necessario, ad esempio a D:\)
set startdir=C:\

REM Cerca la cartella (prima corrispondenza)
for /f "delims=" %%f in ('dir /s /b /ad "%startdir%\%foldername%" 2^>nul') do (
    set foundpath=%%f
    goto :found
)

echo Cartella non trovata.
pause
exit /b

:found
echo Cartella trovata: !foundpath!
code "!foundpath!"
pause
