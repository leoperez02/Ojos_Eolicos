/*
* Herramientas auxilares para limpiar pantalla y hacer una pausa antes de 
* continuar.
*/
#define AGUANTA printf("\nPRESIONE ENTER\n");getchar();getchar();
#if (__linux__)
	#define LIMPIAR system("clear");
	#include <sys/wait.h>
#else
	#define LIMPIAR system("cls");
#endif
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#define PI 3.1416
/**
* @fn flee_funcion
*/
void calcula_dft(int,int*);
/**
* @fn flee_funcion
*/
int* flee_funcion(char*,int*,int*);
/**
* @fn lee_funcion
*/
int* lee_funcion(int*,int*);
