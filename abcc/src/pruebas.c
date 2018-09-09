/*
	char* cadena1;
	cadena1=(char*)malloc(MAX*sizeof(char));
	printf("Teclea cadena de caracteres: ");
	scanf("%s",cadena1);
	printf("\n%s\n",cadena1);
	/*
	* Probando función de get_fecha()
	*/
	/*
	printf("\nTest\n\a");
	char fecha[11];
	get_fecha(fecha);
	printf("La fecha es: %s\n",fecha);
	*/
	/*
	* Probando función Registro()
	*/
	//cliente *registro;
	//printf("Reservando memoria\n\n");
	//(*registro).id_cliente=(int*)malloc(sizeof(int));
	//(*registro).nombre=(char*)malloc(MAX*sizeof(char));
	//(*registro).ap_paterno=(char*)malloc(MAX*sizeof(char));
	//(*registro).ap_materno=(char*)malloc(MAX*sizeof(char));
	//(*registro).fecha_alta = (char*)malloc(11*sizeof(char));
	//(*registro).credito = (float*)malloc(sizeof(float));
	//(*registro).deuda=(float*)malloc(sizeof(float));
	/*
	registro=(cliente*)malloc(sizeof(cliente));
	get_memoria(registro);
	printf("Registrando datos");
	Registro(registro);
	imprime_cliente(registro);
	*/
	/*
	* Prueba de la función comprueba_archivo();
	*/
	/*
	* Prueba de reservación de memoria, registro, desplegado de datos y 
	* de un guardado en archivo de un cliente.
	*/
	/*
	cliente *lain=get_memoria(lain);
	Registro(lain);
	imprime_cliente(lain);
	save_cliente(lain);
    	*/
    	/*
	* Prueba de la función slipt()
	char* cad="1,lain,iwakura,osita,2015-10-13,9.50,6.50";
	char* arr[7];
	split(7,arr,cad,',');
	*/
	/*
	char* cadena1="Hola";
	char* cadena2="Holo";
	if(equals(cadena1,cadena2))
		printf("\nIguales\n");
	else
		printf("\nDesiguales\n");
	*/
	/*
* slipt(): La función recibe una cadena, un delimitador y devuelve
* en el arreglo indicado del tamaño indicado los campos de la cadena.
*/
void split(int n,char* array[n],char* cadena,char delimitador)
{
	printf("\nIniciando split\n");
	printf("%s\n",cadena);
	printf("%c\n",cadena[0]);
	printf("%c\n",cadena[1]);
	/*
	array[0]="Hola\0";
	array[1]="Hola1\0";
	array[2]="Hola2\0";
	array[3]="Hola3\0";
	array[4]="Hola4\0";
	array[5]="Hola5\0";
	array[6]="Hola6\0";
	*/
	int index,suma=0;
	for(index=0;cadena[index]!='\0';index++)
		if(cadena[index]==delimitador)
			suma++;
	int indices[suma];
	for(index=0,suma=0;cadena[index]!='\0';index++)
		if(cadena[index]==delimitador)
			indices[suma++]=index;
	for(index=0;index<suma;index++)
		printf("%d,",indices[index]);
}
