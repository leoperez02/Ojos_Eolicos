/**
* @file main_convolucion.c
* @brief Menú principal de la convolución de dos funciones x(k) y h(k). 
* @author Mauro Leonardo Pérez Bravo.
* @date lun nov 30 10:34:14 CST 2015 
*/
#include"convolucion.h"
/*
* Main
*/
int main(void)
{
	LIMPIAR
	printf("Ingresa la función H(k) ...\n");
	fn_discreta* h=get_funcion(h);
	printf("H(k) = ");
	ver_funcion(h);
	AGUANTA
	/*
	* Test de funciones
	*/
	/**************************************************************************
	//Evaluar
	int i;
	for(i=(*h).t_ini-1;i<=(*h).size_fn;i++)
		printf("Y(%d) = %d\n",i,evaluar(h,i));
	//Invertir
	invertir_fn(h);
	ver_funcion(h);
	for(i=(*h).t_ini-1;i<=(*h).size_fn;i++)
		printf("Y(%d) = %d\n",i,evaluar(h,i));
	invertir_fn(h);
	//Desplazar
	desplazar_fn(0,h);
	ver_funcion(h);
	desplazar_fn(3,h);
	ver_funcion(h);
	desplazar_fn(-2,h);
	ver_funcion(h);
	/**************************************************************************/
	/**************************************************************************/
	printf("Ingresa la función X(k) ...\n");
	fn_discreta* x=get_funcion(x);
	printf("X(k) = ");
	ver_funcion(x);
	AGUANTA
	
	int ini=0;
	int fin=0;
	invertir_fn(h);
	printf("H(-k) = ");
	ver_funcion(h);
	fn_discreta aux=*h;
	c_intervalo(&ini,&fin,&aux,x);
	printf("Intervalo de convolución de las funciones=[%d,%d]\n",ini,fin);
	AGUANTA
	fn_discreta* y=convolucion(y,x,h,ini,fin);
	printf("Y(n) = ");
	ver_funcion(y);
	/**************************************************************************/
	return 0;
}
