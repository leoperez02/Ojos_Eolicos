#!/bin/bash
# Script de compilación del programa DFT
@echo off
clear
echo Compilando y ensamblando...
gcc -Ilib -c src/lectura_datos.c -o lib/lectura_datos.o
gcc -Ilib -c src/dft.c -o lib/dft.o -lm
gcc -Ilib -c src/dft_concurrente.c -o lib/dft_concurrente.o -lm
echo Enlazando...
gcc -Ilib lib/lectura_datos.o lib/dft.o src/main_dft.c -o bin/dft.exe -lm
gcc -Ilib lib/lectura_datos.o lib/dft_concurrente.o src/main_dft.c -o bin/dft_concurrente.exe -lm
echo Proceso terminado.
echo Presione una tecla para continuar
read
clear
