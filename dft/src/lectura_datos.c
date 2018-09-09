#include "../lib/dft.h"
/**
* @brief 
* @param
* @param
*/
int* lee_funcion(int* N,int* vector)
{
	int i;
	printf("Escribe el valor de N=");
	scanf("%d",N);
	fflush(stdin);
	vector=(int*)malloc(*N*sizeof(int));
	printf("Escribe la funcion:\n");
	for(i=0;i<*N;i++)
	{
		printf("#%d --> ",i);
		scanf("%d",vector+i);
		fflush(stdin);
	}	
	return vector;
}
/**
* @brief 
* @param
* @param
*/
int* flee_funcion(char* ruta,int* N,int* vector)
{
	FILE *fichero;
	if(!(fichero=fopen(ruta,"r")))
	{
		printf("No se puede abrir el fichero: %s\n",ruta);
		return NULL;
	}
	else
	{
		int i,comas=0;
		while(!feof(fichero))
			if(fgetc(fichero)==',')
				comas++;
		vector=(int*)malloc(++comas*sizeof(int));
		rewind(fichero);
		for(i=0;!feof(fichero) && i<comas;i++)
		{
			fscanf(fichero,"%d,",vector+i);
			//printf("vector[%d] = %d",i,*(vector+i));
		}
		*N=comas;
		fclose(fichero);
		return vector;
	}
}
