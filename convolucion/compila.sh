#!/bin/bash
# Script de compilación del programa DFT
@echo off
clear
echo Compilando y ensamblando...
gcc -Ilib -c src/convolucion.c -o lib/convolucion.o
echo Enlazando...
gcc -Ilib lib/convolucion.o src/main_convolucion.c -o bin/convolucion.exe
echo Proceso terminado.
echo Presione una tecla para continuar
read
clear
