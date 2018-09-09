REM Script de compilación del programa de convolución.
@echo off
cls
echo Compilando y ensamblando...
gcc -m32 -Ilib -c src/convolucion.c -o lib/convolucion_win.o
echo Enlazando...
gcc -m32 -Ilib lib/convolucion_win.o src/main_convolucion.c -o bin/convolucion_windows.exe
echo Proceso terminado.
pause
exit