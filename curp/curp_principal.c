#include "funciones_curp.h"

int main ( )
	{
		system("CLS");
		char opcion = 'N' ;
		printf("\n\nHola. Este programa obtiene tu curp y lo muestra en pantalla. ");
		printf("\n\nConoces tu curp? S/N: ");
		scanf("%c",&opcion);
		fflush(stdin);
		if (opcion == 'N' || opcion == 'n')
			{	
				pide_datos();
				confirma_datos();
				calcula_curp();
				imprime_curp();
				system("PAUSE");
			}
		else
			{
				char curp[] = "asdfghjklñ!<3" ;
				printf("\n\nTeclea tu curp en mayusculas: ");
				scanf("%s",&curp);
				fflush(stdin);
				printf("\nTu curp es: %s \n\n",curp);
			}
		return 0;
	}