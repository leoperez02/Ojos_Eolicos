#!/bin/bash
clear
# Declaración de función pausa
function pause(){
   read -p "$*"
}
# init
gcc src/cliente.c -o bin/main
pause 'Press [Enter] key to continue...'
cd bin
./main
