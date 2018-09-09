REM Script de compilación del programa DFT
@echo off
cls
echo Compilando y ensamblando...
gcc -m32 -Ilib -c src/lectura_datos.c -o lib/lectura_datos_win.o
gcc -m32 -Ilib -c src/dft.c -o lib/dft_win.o -lm
rem gcc -Ilib -c src/dft_concurrente.c -o lib/dft_concurrente_win.o -lm
echo Enlazando...
gcc -m32 -Ilib lib/lectura_datos_win.o lib/dft_win.o src/main_dft.c -o bin/dft_win.exe -lm
rem gcc -m32 -Ilib lib/lectura_datos_win.o lib/dft_concurrente_win.o src/main_dft.c -o bin/dft_concurrente_win.exe -lm
echo Proceso terminado.
pause
cls