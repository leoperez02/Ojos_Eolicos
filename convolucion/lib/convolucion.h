/*
* Herramientas auxilares para limpiar pantalla y hacer una pausa antes de 
* continuar.
*/
#define AGUANTA printf("\nPRESIONE ENTER\n");getchar();getchar();
#if (__linux__)
	#define LIMPIAR system("clear");
#else
	#define LIMPIAR system("cls");
#endif
#include<stdio.h>
#include<stdlib.h>
/**
* @struct fn_discreta
* @brief Estructura para almacenar un conjunto de valores discretos.
* @var fn
* @brief Arreglo de valores discretos de la función.
* @var size_fn
* @brief Número de valores discretos de la función.
* @var t_ini
* @brief Lado izquierdo del intervalo del dominio de la función.
* @var t_fin
* @brief Lado derecho del imtervalo del dominio de la función.
*/
typedef struct fn_discreta
{
	int size_fn;
	int t_ini;
	int t_fin;
	int* fn;
}fn_discreta;
/*
* Prototipos de funciones
*/
/**
* @fn c_intervalo
*/
void c_intervalo(int*,int*,fn_discreta*,fn_discreta*);
/**
* @fn convolucion
*/
fn_discreta* convolucion(fn_discreta*,fn_discreta*,fn_discreta*,int,int);
/**
* @fn evaluar
*/
int evaluar(fn_discreta*,int);
/**
* @fn desplazar_fn
*/
void desplazar_fn(int,fn_discreta*);
/**
* @fn get_funcion
*/
fn_discreta* get_funcion(fn_discreta*);
/**
* @fn get_memoria
*/
fn_discreta* get_memoria(fn_discreta*,int,int,int);
/**
* @fn invertir_array
*/
void invertir_array(int,int*);
/**
* @fn invertir_fn
*/
void invertir_fn(fn_discreta*);
/**
* @fn ver_funcion
*/
void ver_funcion(fn_discreta*);
