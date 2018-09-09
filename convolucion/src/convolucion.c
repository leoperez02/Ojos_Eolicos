/**
* @file convolucion.c
* @brief Convolución en tiempo discreto de dos funciones x(k) y h(k). 
* @author Mauro Leonardo Pérez Bravo.
* @date lun nov 30 10:34:14 CST 2015 
*/
#include"convolucion.h"
/**
* @brief 
* @param
* @param
*/
void c_intervalo(int* ini,int* fin,fn_discreta* h,fn_discreta* x)
{
	int contador=0;
	if((*h).t_fin==(*x).t_ini)//La convolución empienza en n=0: [0,-->]
		*ini=0;
	else
	{
		if((*h).t_fin>(*x).t_ini)//Si h(-k) está a la derecha, se mueve a la izquierda
			while((*h).t_fin>(*x).t_ini)
			{
				desplazar_fn(-1,h);
				contador--;
			}
		else //Se mueve a la derecha.
			while((*h).t_fin<(*x).t_ini)
			{
				desplazar_fn(1,h);
				contador++;
			}
		*ini=contador;
	}
	//ver_funcion(h);
	//printf("ini = %d\n",*ini);
	while((*h).t_ini<(*x).t_fin)
	{
		desplazar_fn(1,h);
		contador++;
	}
	*fin=contador;
	//ver_funcion(h);
	//printf("ini = %d\n",*fin);
}
/**
* @brief 
* @param
* @param
*/
fn_discreta* convolucion(fn_discreta* y,fn_discreta* x,fn_discreta* h,int ini,int fin)
{
	int k;
	//---------------------------------------------
	int aux,size;
	y=(fn_discreta*)malloc(sizeof(fn_discreta));
	for(aux=ini,size=0;aux<=fin;aux++,size++);
	(*y).size_fn=size;
	(*y).t_ini=ini;
	(*y).t_fin=fin;
	(*y).fn=(int*)malloc((*y).size_fn*sizeof(int));
	for(aux=0;aux<(*y).size_fn;aux++)
		*((*y).fn+aux)=0;
	//---------------------------------------------
	desplazar_fn(ini,h);
	int index2,aux2=ini;
	for(index2=0;ini<=fin;ini++,index2++)
	{
		printf("Índice n=%d ---> Y(%d) = ",ini,ini);
		printf("X(k) * H(%d - k)\n",ini);
		//ver_funcion(h);
		int index=(*x).t_ini;
		for(k=aux2;k<ini+1;k++)
		{
			//printf("X = %d , ",evaluar(x,index));
			//printf("H = %d\n",evaluar(h,index));
			*((*y).fn+index2)+=evaluar(x,index)*evaluar(h,index);
			index++; 	
		}
		desplazar_fn(1,h);
	}
	return y;		
}
/**
* @brief 
* @param
* @param
*/
void desplazar_fn(int n,fn_discreta* fn)
{
	(*fn).t_ini+=n;
	(*fn).t_fin+=n;
}
/**
* @brief 
* @param
* @param
*/
int evaluar(fn_discreta* f,int x)
{
	int contador,index;
	for(contador=0,index=(*f).t_ini;contador<(*f).size_fn;contador++,index++)
		if(x==index)
			return *((*f).fn+contador);
	return 0;
}
/**
* @brief 
* @param
* @param
*/
fn_discreta* get_funcion(fn_discreta* fn)
{
	int i,n,ini,fin;
	printf("N=#valores discretos de la función\n");
	printf("Dominio de la función = [LimInferior,LimSuperior]\n");
	printf("Escribe el valor de N=");
	scanf("%d",&n);
	fflush(stdin);
	printf("Escribe el valor del LimInferior=");
	scanf("%d",&ini);
	fflush(stdin);
	printf("Escribe el valor del LimSuperior=");
	scanf("%d",&fin);
	fflush(stdin);
	fn=get_memoria(fn,n,ini,fin);
	printf("Escribe los valores de la función desde LimInferior hasta LimSuperior\n");
	for(i=0;i<n;i++)
	{
		printf("#%d --> ",i);
		scanf("%d",(*fn).fn+i);
		fflush(stdin);
	}
	return fn;
}
/**
* @brief 
* @param
* @param
*/
fn_discreta* get_memoria(fn_discreta* fn,int size,int ini,int fin)
{
	fn=(fn_discreta*)malloc(sizeof(fn_discreta));
	(*fn).size_fn=size;
	(*fn).t_ini=ini;
	(*fn).t_fin=fin;
	(*fn).fn=(int*)malloc((*fn).size_fn*sizeof(int));
	return fn;
}
/**
* @brief 
* @param
* @param
*/
void invertir_array(int size,int* array)
{
	int aux[size],i;
	for(i=0;i<size;i++)
		aux[i]=(*(array+(size-1-i)));
	for(i=0;i<size;i++)
		*(array+i)=aux[i];
}
/**
* @brief 
* @param
* @param
*/
void invertir_fn(fn_discreta* fn)
{
	int aux;
	invertir_array((*fn).size_fn,(*fn).fn);
	aux=(*fn).t_ini;
	(*fn).t_ini=-1*(*fn).t_fin;
	(*fn).t_fin=-1*aux;
}
/**
* @brief 
* @param
* @param
*/
void ver_funcion(fn_discreta* fn)
{
	int i;
	printf("{");
	for(i=0;i<(*fn).size_fn;i++)
		printf("%d,",*((*fn).fn+i));
	printf("} ; [%d,%d]\n",(*fn).t_ini,(*fn).t_fin);
}
