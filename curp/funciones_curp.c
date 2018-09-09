#include "funciones_curp.h"

struct personas
	{
		char nombre [150];
		char fecha_n[11];
		char sexo   [2];
		char entidad[3];
		char curp   [19];
	};

struct personas persona;

void pide_datos()
	{
		int validador = 0;
		
		while(validador == 0)
			{
				printf("\n\nEscribe tu nombre completo en mayusculas, sin acentos y comenzando por tu apellido paterno.\nEjemplo:\nNombre completo: GONZALEZ CHAVEZ LUZ\n\nNombre completo: ");		
				gets(persona.nombre);
				fflush(stdin);
				validador=valida_nombre(persona.nombre);
			}
		convierte_mayus(&persona.nombre);
		
		validador=0;	
		
		while(validador==0)
			{
				printf("\n\nEscribe tu fecha de nacimiento en el formato aaaa/mm/dd. \nEjemplo: para indicar que la fecha de nacimiento es 9 de Noviembre del a�o 1995 escribe lo siguiente:\nFecha de nacimiento: 1995/11/09 \n\nFecha de nacimiento: ");		
				scanf("%s",&persona.fecha_n);
				fflush(stdin);
				validador=valida_fecha(persona.fecha_n);
			}
		
		validador=0;	
		
		while(validador==0)
			{
				printf("\n\nEscribe a continuacion una 'M' si eres mujer o una 'H' si eres hombre: ");
				scanf("%s",&persona.sexo);
				fflush(stdin);
				validador=valida_sexo(persona.sexo);
			}
		convierte_mayus(&persona.sexo);
		
		validador=0;	
		
		while(validador==0)
			{
				printf("\n\nEscribela clave de dos letras correspondiente a la entidad federativa donde naciste segun la siguiente tabla:");
				imprime_tabla();
				printf("\n\nClave: ");
				scanf("%s",&persona.entidad);
				fflush(stdin);
				validador=valida_entidad(persona.entidad);
				if (validador == 1)
					{
						convierte_mayus(&persona.entidad);
						 validador = verifica_entidad(persona.entidad);
					}
			}
	}

void confirma_datos()
	{
		char seguro = 'N';
		
		while (seguro == 'N')
			{
				printf("\n\nTus datos son los siguientes, por favor verifica que sean correctos.");
				printf("\n\nTu nombre es: %s",persona.nombre);
				printf("\n\nFecha de nacimiento: %s",persona.fecha_n);
				printf("\n\nSexo: %s",persona.sexo);
				printf("\n\nEntidad de nacimiento: %s",persona.entidad);
				printf("\n\nSon correctos tus datos? S/N: ");
				scanf("%c",&seguro);
				fflush(stdin);
				
				if(seguro=='N' ||seguro == 'n')
					{
						pide_datos();
						seguro = 'N' ;
					}
			}
			//recorrer el arreglo de fecha
			int i ;
			for ( i =0 ; i < strlen( persona.fecha_n) - 2 ; i++)
				persona.fecha_n[i] = persona.fecha_n[i+2] ; 
			//
	}

void calcula_curp()
	{
		//funcion strtok para generar 3 arreglo de cadenas: paterno materno nombre
		
		char paterno[50];
		char materno[50];
		char nombre_pila[50];
		char *auxiliar;
		char auxiliar2[20];
		char caracter = 'a' ;
		int i, longitud,validador ;
		
		for (i = 0 ,  auxiliar = strtok(persona.nombre," ") ; auxiliar != NULL && i<3 ; auxiliar = strtok(NULL, " ") , i++)
			{
				if (i == 0)
					strcpy( paterno, auxiliar);
				else
					{
						if (i==1)
							strcpy( materno, auxiliar);
						else
							strcpy( nombre_pila, auxiliar);
					}
			}	
		
		//strcpy para primer letra del paterno(concatenar a variable curp)
		
		strncpy (persona.curp,paterno,1);
		
		//for que compare caracter a caracter (con strcpy) contra el codigo ascii para hallar vocales y se detenga en la primer vocal, y concatenar a variable curp
		
		longitud = strlen(paterno);
		validador = 0 ;
		auxiliar[0] = 'd' ; auxiliar[1] = 'd'; auxiliar[2]='a' ;
		
		for ( i=0 ; i < longitud ; i++ )
			{
				caracter = (char) paterno[i];
				toupper(caracter);
				auxiliar=strchr(paterno,caracter);
				
				if((toascii(caracter) ==65 || toascii(caracter) ==69 || toascii(caracter) ==73 || toascii(caracter)==78 || toascii(caracter) ==85) && validador==0)
					{
						strncpy(auxiliar2,auxiliar,1);
						strcat(persona.curp,auxiliar2);
						validador = 1;
					}
			}
			
		//inicial del materno
		
		strncpy(auxiliar2,materno,1);	
		strcat(persona.curp,auxiliar2);
		
		//inicial del nombre
		
		strncpy(auxiliar2,nombre_pila,1);	
		strcat(persona.curp,auxiliar2);
		
		// funcion strtok para separar la fecha usando el caracter '/' y concatenar directamente a curp
		
		for (i = 0 ,  auxiliar = strtok(persona.fecha_n,"/") ; auxiliar != NULL && i<3 ; auxiliar = strtok(NULL, "/") , i++)
			strcat(persona.curp,auxiliar);
		
		//concatenar con el contenido de las variables sexo y entidad 
		
		strcat(persona.curp,persona.sexo);
		strcat(persona.curp,persona.entidad);
		
		//tres letras m�s: primea consonante interna del primer apellido, primera consonante interna del segundo apellido, primera consonante interna del nombre de pila 
		
			//paterno
		
		longitud = strlen(paterno);
		validador = 0;
		
		for ( i=0 ; i < longitud ; i++ )
			if ( i != 0 )
					{
						caracter = (char) paterno[i];
						toupper(caracter);
						auxiliar=strchr(paterno,caracter);
						
						if( !(toascii(caracter) ==65 || toascii(caracter) ==69 || toascii(caracter) ==73 || toascii(caracter)==78 || toascii(caracter) ==85) && validador==0)
							{
								strncpy(auxiliar2,auxiliar,1);
								strcat(persona.curp,auxiliar2);
								validador = 1;
							}
					}
		
			//materno
			
		longitud = strlen(materno);
		validador = 0;
		
		for ( i=0 ; i < longitud ; i++ )
			if ( i != 0 )
					{
						caracter = (char) materno[i];
						toupper(caracter);
						auxiliar=strchr(materno,caracter);
						
						if( !(toascii(caracter) ==65 || toascii(caracter) ==69 || toascii(caracter) ==73 || toascii(caracter)==78 || toascii(caracter) ==85) && validador==0)
							{
								strncpy(auxiliar2,auxiliar,1);
								strcat(persona.curp,auxiliar2);
								validador = 1;
							}
					}
			
			//nombre_pila
			
		longitud = strlen(nombre_pila);
		validador = 0;
		
		for ( i=0 ; i < longitud ; i++ )
			if ( i != 0 )
					{
						caracter = (char) nombre_pila[i];
						toupper(caracter);
						auxiliar=strchr(nombre_pila,caracter);
						
						if( !(toascii(caracter) ==65 || toascii(caracter) ==69 || toascii(caracter) ==73 || toascii(caracter)==78 || toascii(caracter) ==85) && validador==0)
							{
								strncpy(auxiliar2,auxiliar,1);
								strcat(persona.curp,auxiliar2);
								validador = 1;
							}
					}
		//digito verificador y clave homóloga (un digito y un caracter más) --> ?
		
		int hora = time(NULL);   
		int nums[2] ;
		srand(hora); 
		for( i = 0; i <2; i++)  
			{	  
               nums[i] = rand()%10;    
			}  
		char *uno_mas ;	
		char *dos_mas ;
		
		sprintf(uno_mas, "%d", nums[0]); 
		sprintf(dos_mas, "%d", nums[1]);
		
		strcat(persona.curp,uno_mas);
		strcat(persona.curp,dos_mas);
		
		}
	
void imprime_curp()
	{
		printf("\n\nTu curp es: %s \n\nAdios.\n\n",persona.curp);			
	}