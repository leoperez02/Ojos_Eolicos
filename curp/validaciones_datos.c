#include "validaciones_datos.h"

int valida_nombre(char nombre[150])
	{
		int longitud = strlen(nombre);
		int i, validador = 1;
		char caracter = 'a' ;
		
		if (nombre[0] == ' ' || strlen(nombre)<=10)
			{
				printf("\n\nNombre incorrecto. Verifica por favor\n");
				return 0;
			}
			
		while(validador==1)
			{
				for ( i=0 ; i < longitud ; i++ )
					{
						caracter = (char) nombre[i];
						if( ((toascii(caracter)<65 || toascii(caracter)>90)) )
							if (((toascii(caracter)<97 || toascii(caracter)>122)))
								if( toascii(caracter)!=32)
									{
										printf("\n\nNombre incorrecto. Verifica por favor\n");
										return 0;
									}
							
					}
				return validador;
			}
		return validador;
	}
	
int valida_fecha(char fecha[11])
	{
		int longitud = strlen(fecha);
		int i,validador = 1;
		int diagonal = 0;
		char caracter = 'a';
		
		if (fecha[0] == ' ' || longitud != 10)
			{
				printf("\n\nFecha incorrecta. Verifica por favor\n");
				return 0;
			}
			
		while(validador==1)
			{
				for ( i=0 ; i < longitud ; i++ )
					{
						caracter = (char) fecha[i];
						if( (toascii(caracter)<47 || toascii(caracter)>57) )
							{
								printf("\n\nFecha incorrecta. Verifica por favor\n");
								return 0;
							}
						else
							{
								if(  toascii(caracter) == 47 )
									diagonal++;
							}
					}
				if (diagonal == 2)
					return verifica_fecha(fecha);
				else
					{
						printf("\n\nFecha incorrecta. Verifica por favor\n");
						return 0;
					}
			}
		return validador;
	}
	
int valida_sexo(char sexo[2])
	{
		int longitud = strlen(sexo);
		int validador = 1;
		char caracter = 'a';
		
		if (sexo[0] == ' ' || longitud!=1 )
			{
				printf("\n\nSexo incorrecto. Verifica por favor\n");
				return 0;
			}
		
		caracter = (char) sexo[0];
		if( (toascii(caracter)!=72 && toascii(caracter)!=77 && toascii(caracter)!=104 && toascii(caracter)!=109) )
			{
				printf("\n\nSexo incorrecto. Verifica por favor\n");
				return 0;
			}
		return validador;
	}

int valida_entidad(char entidad[3])
	{
		int longitud = strlen(entidad);
		int i,validador = 1;
		char caracter = 'a' ;
		
		if (entidad[0] == ' ' || longitud != 2)
			{
				printf("\n\nClave de entidad incorrecta. Verifica por favor\n");
				return 0;
			}
			
		while(validador==1)
			{
				for ( i=0 ; i < longitud ; i++ )
					{
						caracter = (char) entidad[i];
						if( (toascii(caracter)<65 || toascii(caracter)>90) )
							if (((toascii(caracter)<97 || toascii(caracter)>122)))
								{
									printf("\n\nClave de entidad incorrecta. Verifica por favor\n");
									return 0;
								}
					}
				return validador;
			}
		return validador;
	}

void convierte_mayus(char (*arreglo)[150])
	{
		int longitud = strlen(*arreglo);
		int i ;
		char caracter = 'a' ;
		
		for ( i=0 ; i < longitud ; i++ )
					{
						caracter = (char) ((*arreglo)[i]);
										
						if( ((toascii(caracter)<65 || toascii(caracter)>90)) )
							if( toascii(caracter)!=32)
								if ( toascii(caracter)>96 && toascii(caracter)<123 )
									{
										 ((*arreglo)[i]) = (char)(toascii(caracter) - 32)   ;
									}
					}
	}
	
int verifica_fecha(char fecha[11])
	{
		int validador=1;
		
		char dd[3]   ;
		char mm[3] ;
		char aa[5]   ;
		
		dd[0] = fecha[8];       mm[0] = fecha[5];		aa[0] = fecha[0];
		dd[1] = fecha[9];       mm[1] = fecha[6];   	aa[1] = fecha[1];
		dd[2] = '\0' ;              mm[2] = '\0' ;          	aa[2] = fecha[2];
																			aa[3] = fecha[3];
																			aa[4] = '\0' ;
		int dia =  atoi(dd);
		int mes =atoi(mm);
		int ajo =  atoi(aa);
		
		if (mes >12 || mes<1 )
			{
				printf("\n\nFecha incorrecta. Verifica por favor\n");
				return 0;
			}
		else
			{
				if ( mes <= 7 )
					{
						if (mes%2 == 0)
							{
								if ( dia > 30 || dia < 1) 
									{
										printf("\n\nFecha incorrecta. Verifica por favor\n");
										return 0;
									}
							}
						else
							{
								if ( dia > 31 || dia < 1) 
									{
										printf("\n\nFecha incorrecta. Verifica por favor\n");
										return 0;
									}
							}
						if (mes == 2)
							{
								if ( dia > 29 || dia < 1) 
									{
										printf("\n\nFecha incorrecta. Verifica por favor\n");
										return 0;
									}
								else
									if(dia == 29)
										validador = verifica_ajo_bis(ajo);
							}
					}
				else
					{
						if (mes%2 == 0)
							{
								if ( dia > 31 || dia < 1) 
									{
										printf("\n\nFecha incorrecta. Verifica por favor\n");
										return 0;
									}
							}
						else
							{
								if ( dia > 30 || dia < 1) 
									{
										printf("\n\nFecha incorrecta. Verifica por favor\n");
										return 0;
									}
							}
					}
					
			}
			
		return validador;
	}
	
int verifica_ajo_bis(int ajo)
	{
		int validador  ;
		
		if (ajo%4==0)
			{
				if (ajo%100 ==0)
					{
						if(ajo%400==0)
							validador = 1;
						else
							validador = 0;
					}
				else
					validador=1;
			}
		else
			validador = 0;
		
		return validador ;
	}