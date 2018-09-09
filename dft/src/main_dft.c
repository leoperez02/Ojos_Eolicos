/**
* @file main_dft.c
* @brief Menú de la aplicación de cálculo de la DFT.
* @author Mauro Leonardo Pérez Bravo.
* @date lun nov 30 10:34:14 CST 2015 
*/
#include "../lib/dft.h"
/*
* Main
*/
int main(void)
{
	LIMPIAR
	int N;
	int* vector_IN;
	int opc,id,opcion=1;
    while(opcion)
    {
    	printf("\n\t\t*** Teoría de comunicaciones y señales ***\n");
    	printf("\n\t\tPrograma para hallar la transformada discreta de Fourier (DFT)\n");
		printf("\n\t\tMENÚ PRINCIPAL\n\n");
	    printf("\t\t0. Salir del programa.\n\n");
      	printf("\t\t1. Cargar función desde teclado.\n\n");
      	printf("\t\t2. Cargar función desde archivo.\n\n");
      	printf("Teclea el número de la opción que quieras: ");
      	scanf("%d",&opcion);
      	switch(opcion)
      	{
        	case 0:
                LIMPIAR
                printf("\nBye.\n");
            break;
            case 1:
            	LIMPIAR
            	vector_IN=lee_funcion(&N,vector_IN);
            	calcula_dft(N,vector_IN);
            	AGUANTA
            break;
			case 2:
				LIMPIAR
				char* ruta=(char*)malloc(100*sizeof(char));
				printf("Ruta del archivo: ");
				scanf("%s",ruta);
				fflush(stdin);
				if((vector_IN=flee_funcion(ruta,&N,vector_IN))!=NULL)
					calcula_dft(N,vector_IN);
				AGUANTA
            default:
                printf("\nOpción incorrecta. Intenta de nuevo.");
            break;
        }
        LIMPIAR
    }
	return 1;
}
