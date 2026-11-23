@echo off
gcc -o main.exe *.c *.h
if errorlevel 1 (
    echo Erro de compilacao
    exit /b 1
)

for %%f in (testes\*.txt) do (
    echo ===== %%~nxf
    main.exe %%f
    echo.
)