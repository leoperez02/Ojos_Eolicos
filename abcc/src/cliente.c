/*
* cliente.c
*/
#include<stdio.h>
#include<stdlib.h>
/*
* Definición de constantes de tamaño máximo para cadenas.
*/
#define MAX 40
/*
* Definición del formato DE ESCRITURA (layout) del archivo plano clientes.txt:
* id_cliente nombre a_paterno a_materno fecha_alta credito deuda
*/
#define FORMATO_W "%d\t%s\t%s\t%s\t%s\t%.2f\t%.2f\n"
/*
* Definición del formato DE LECTURA (layot) del archivo plano clientes.txt:
*/
#define FORMATO_R "%d\t%s\t%s\t%s\t%s\t%f\t%f\n"
/*
* Definición del formato para impresión en pantalla (screen) y cabecera:
*/
#define FORMATO_S "| %d\t|\t%s\t|\t%s\t|\t%s\t| %s |\t%.2f\t|\t%.2f |\n"
#define HEADER "| id_cliente |\tnombre\t|\ta_paterno\t|\ta_materno\t| fecha_alta |\tcredito\t|\tdeuda |\n"
/*
* Herramientas auxilares para limpiar pantalla y hacer una pausa antes de 
* continuar.
*/
#define AGUANTA printf("\nPresiona una tecla para continuar...\n");getchar();getchar();
#define LIMPIAR system("clear");
/*
* El archivo donde se guardan todos los registros de los clientes
* es clientes.txt, ubicado en el directorio de aplicación.
*/
FILE *fichero_clientes;
/*
* Defnición del struct para guardar los datos de un cliente
*/
typedef struct cliente{
	int id_cliente;
	char* nombre;
	char* ap_paterno;
	char* ap_materno;
	char* fecha_alta;
	float credito;
	float deuda;
}cliente;
/*
* Prototipos de las funciones:
*/
void Registro(cliente*);
void get_fecha(char[11]);
cliente* get_memoria(cliente*);
void imprime_cliente(cliente*);
void comprueba_archivo(void);
void save_cliente(cliente*);
void menu(void);
void imprime_registros(void);
cliente* lookfor(int,char*,int);
void llena_datos(cliente*,int,char*,char*,char*,char*,float,float);
int equals(char*,char*);
int buscador(void);
void elimina(int);
void borra_linea(int);
void mofica(int);
void inserta_linea(int,cliente*);
int valida_positivo(float);
void selecciona_columnas(char*);
/*
* Registro(): Se llenan los campos de un struct cliente leyendo los datos
* desde la terminal.
*/
void Registro(cliente *nuevo)
{
	int flag=0;
    printf("\nIngresa el nombre del cliente: ");
    scanf("%s",(*nuevo).nombre);
    fflush(stdin);
    printf("\nIngresa apellido paterno: ");
    scanf("%s",(*nuevo).ap_paterno);
    fflush(stdin);
    printf("\nIngresar apellido materno: ");
    scanf("%s",(*nuevo).ap_materno);
    fflush(stdin);
    get_fecha((*nuevo).fecha_alta);
    fflush(stdin);
    printf("\nLa fecha de alta es: %s\n",(*nuevo).fecha_alta);
    while(!flag)
    {
    	printf("\nCredito: ");
    	scanf("%f",&(*nuevo).credito);
    	fflush(stdin);
    	flag=valida_positivo((*nuevo).credito);
    }
    flag=0;
    while(!flag)
    {
    	printf("\nDeuda: ");
    	scanf("%f",&(*nuevo).deuda);
    	fflush(stdin);
    	flag=valida_positivo((*nuevo).deuda);		
    }
}
/*
* get_fecha(): Se invoca el comando date del sistema, escribe la fecha en un 
* archivo, la lee y borra el archivo.
*/
void get_fecha(char fecha[11])
{
	FILE *fichero;
	system("date --rfc-3339='date' > fecha.txt");
	fichero=fopen("fecha.txt","r");
	fgets(fecha,11,fichero);
	system("rm fecha.txt");
}
/*
* get_memoria(): Recibe un apuntador nulo a cliente, reserva memoria para el 
* struct cliente y luego reserva memoria para sus campos cadenas.
*/
cliente* get_memoria(cliente *nuevo)
{
	nuevo=(cliente*)malloc(sizeof(cliente));
	(*nuevo).nombre=(char*)malloc(MAX*sizeof(char));
	(*nuevo).ap_paterno=(char*)malloc(MAX*sizeof(char));
	(*nuevo).ap_materno=(char*)malloc(MAX*sizeof(char));
	(*nuevo).fecha_alta=(char*)malloc(11*sizeof(char));//10 caracteres + '\0'
	return nuevo;
}
/*
* imprime_cliente(): Recibe un apuntador a cliente e imprime en pantalla todos
* sus datos.
*/
void imprime_cliente(cliente *registro)
{
	printf(HEADER);
	printf(FORMATO_S,(*registro).id_cliente,
		(*registro).nombre,
		(*registro).ap_paterno,
		(*registro).ap_materno,
		(*registro).fecha_alta,
		(*registro).credito,
		(*registro).deuda
	);
}
/*
* comprueba_archivo(): Esta función verifica que exista el archivo clientes.txt
* y en caso de no existir lo crea y le da permisos de lectura/escritura
*/
void comprueba_archivo(void)
{
	if(!fopen("clientes.txt","r"))//El archivo no existe.
		system("touch clientes.txt && chmod 666 clientes.txt");
}
/*
* save_cliente(): La función recibe un apuntador a cliente y un apuntador a
* archivo para guardar el resgistro en el archivo clientes.txt
*/
void save_cliente(cliente* nuevo)
{
	int id=0;
	char* nom=(char*)malloc(MAX*sizeof(char));
	char* apa=(char*)malloc(MAX*sizeof(char));
	char* ama=(char*)malloc(MAX*sizeof(char));
	char* fec=(char*)malloc(11*sizeof(char));
	float cre=0,deu=0;
	fichero_clientes=fopen("clientes.txt","r");
	while(!feof(fichero_clientes))
		fscanf(fichero_clientes,FORMATO_R,&id,nom,apa,ama,fec,&cre,&deu);
	fclose(fichero_clientes);
	fichero_clientes=fopen("clientes.txt","a");
	printf("\nID CLIENTE: %d\n",++id);
	fprintf(fichero_clientes,"%d\t",id);
	fprintf(fichero_clientes,"%s\t",(*nuevo).nombre);
	fprintf(fichero_clientes,"%s\t",(*nuevo).ap_paterno);
	fprintf(fichero_clientes,"%s\t",(*nuevo).ap_materno);
	fprintf(fichero_clientes,"%s\t",(*nuevo).fecha_alta);
	fprintf(fichero_clientes,"%.2f\t",(*nuevo).credito);
	fprintf(fichero_clientes,"%.2f\n",(*nuevo).deuda);
	fclose(fichero_clientes);
}
/*
* menu(): La función muestra el menú principal de la aplicación.
*/
void menu(void)
{
    int opc,id,opcion=1;
    while(opcion)
    {
    	printf("\n\t\t*** BASE DE DATOS ***\n");
    	printf("\n\t\tProyecto 1er parcial\n");
		printf("\n\t\tMENÚ PRINCIPAL\n\n");
	    printf("\t\t0. Salir del programa.\n\n");
      	printf("\t\t1. Registro de cliente.\n\n");
      	printf("\t\t2. Baja de cliente.\n\n");
      	printf("\t\t3. Búsqueda de cliente.\n\n");
      	printf("\t\t4. Modificar datos de un cliente.\n\n");
      	printf("\t\t5. Mostrar todos los registros.\n\n");
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
            	printf("\n");
            	cliente* lain=get_memoria(lain);
            	Registro(lain);
            	save_cliente(lain);
            	printf("\nDatos guardados con éxito.\n");
            break;
            case 2:
	            LIMPIAR
            	printf("\n");
            	id=buscador();
            	if(id)
            	{
	            	printf("\nSeguro que desea eliminarlo? (0=Sí/1=No).\n");
            		scanf("%d",&opc);
            		if(!opc)
            		{
	            		elimina(id);
	            		printf("\nRegistro eliminado.\n");
	            	}
            	}
            	else
            		printf("\nNo se pudo borrar el registro.\n");
            break;
            case 3:
            	LIMPIAR
            	printf("\n");
            	buscador();
            break;
            case 4:
	            LIMPIAR
            	printf("\n");
            	id=buscador();
            	if(id)
            	{
	            	printf("\nSeguro que desea editarlo? (0=Sí/1=No).\n");
            		scanf("%d",&opc);
            		if(!opc)
            		{
	            		mofica(id);
	            		printf("\nRegistro modificado.\n");
	            	}
            	}
            	else
            		printf("\nNo se pudo actualizar el registro.\n");
            break;
            case 5:
            	LIMPIAR
            	printf("\n");
            	int op;
            	printf("Ver todas las columnas o seleccionar algunas?(1/0): ");
            	scanf("%d",&op);
            	if(op)
	            	imprime_registros();
	            else
	            {
	            	char* cadena=(char*)malloc(8*sizeof(char));
	            	printf("\nTeclea un 1 para ver una columna y un 0 para ocultarla\n");
	            	printf(HEADER);
	            	scanf("%s",cadena);
	            	selecciona_columnas(cadena);
	            }
            break;
            default:
                printf("\nOpción incorrecta. Intenta de nuevo.");
            break;
        }
        AGUANTA
        LIMPIAR
    }
}
/*
* imprime_registros(): Imprime toda la información del archivo.
*/
void imprime_registros(void)
{
	int id;
	char* nom=(char*)malloc(MAX*sizeof(char));
	char* apa=(char*)malloc(MAX*sizeof(char));
	char* ama=(char*)malloc(MAX*sizeof(char));
	char* fec=(char*)malloc(11*sizeof(char));
	float cre,deu;
	fichero_clientes=fopen("clientes.txt","r");
	printf(HEADER);
	while(!feof(fichero_clientes))
	{
		fscanf(fichero_clientes,FORMATO_R,&id,nom,apa,ama,fec,&cre,&deu);
		printf(FORMATO_S,id,nom,apa,ama,fec,cre,deu);
    }
	fclose(fichero_clientes);
}
/*
* lookfor(): Busca un registro en particular, ya sea por ID o por nombre:
* opc = 0 --> Búsqueda por ID.
* opc = 1 --> Búsqueda por nombre.
*/
cliente* lookfor(int opc,char* nombre,int id)
{
	int id_aux,flag;
	char* nom=(char*)malloc(MAX*sizeof(char));
	char* apa=(char*)malloc(MAX*sizeof(char));
	char* ama=(char*)malloc(MAX*sizeof(char));
	char* fec=(char*)malloc(11*sizeof(char));
	float cre,deu;
	cliente* encontrado;
	fichero_clientes=fopen("clientes.txt","r");
	while(!feof(fichero_clientes))
	{
		flag=1;
		fscanf(fichero_clientes,FORMATO_R,&id_aux,nom,apa,ama,fec,&cre,&deu);
		if(!opc && id==id_aux)
			break;
		else
			if(opc && equals(nombre,nom))
				break;
		flag=0;
	}
	if(flag)
	{
		encontrado=get_memoria(encontrado);
		llena_datos(encontrado,id_aux,nom,apa,ama,fec,cre,deu);
	}
	else
		encontrado=NULL;
	fclose(fichero_clientes);
	return encontrado;
}
/*
* llena_datos():
*/
void llena_datos(cliente* alguien,int id,char* nom,char* apa,char* ama,char* fec,float cre,float deu)
{
	(*alguien).id_cliente=id;
	(*alguien).nombre=nom;
	(*alguien).ap_paterno=apa;
	(*alguien).ap_materno=ama;
	(*alguien).fecha_alta=fec;
	(*alguien).credito=cre;
	(*alguien).deuda=deu;
}
/*
* equals(): Compara dos cadenas y determina si son iguales, caracter a caracter.
*/
int equals(char* c1,char* c2)
{
	int i,flag=1;
	for(i=0;c1[i]!='\0'&&c2[i]!='\0';i++)
		if(c1[i]!=c2[i])
		{
			flag=0;
			break;
		}
	return flag;
}
/*
* buscador(): Interfaz para buscar registros.
*/
int buscador()
{
	int opc,id;
    char* nombre=(char*)malloc(MAX*sizeof(char));
    cliente* alguien;
	printf("Teclea 0 para buscar un cliente por ID.\n");
	printf("Teclea 1 para buscar un cliente por nombre.\n");
	scanf("%d",&opc);
	if(opc)
    {
		printf("\nTeclea el nombre del cliente: ");
		scanf("%s",nombre);
		alguien=lookfor(opc,nombre,0);
	}
	else
	{
		printf("\nTeclea el ID del cliente: ");
		scanf("%d",&id);
		alguien=lookfor(opc,nombre,id);
	}
	if(alguien==NULL)
	{
		printf("\nNo se encontró el registro solicitado.\n");	
		return 0;
	}
	else
	{	
		imprime_cliente(alguien);
		return (*alguien).id_cliente;
	}
}
/*
* elimina(): Ubica el número de línea del archivo donde se halla el registro 
* correspondiente con ID y llama a la función borra_linea().
*/
void elimina(int id)
{
	int id_aux,i=0;
	char* nom=(char*)malloc(MAX*sizeof(char));
	char* apa=(char*)malloc(MAX*sizeof(char));
	char* ama=(char*)malloc(MAX*sizeof(char));
	char* fec=(char*)malloc(11*sizeof(char));
	float cre,deu;
	fichero_clientes=fopen("clientes.txt","r+");
	while(!feof(fichero_clientes))
	{
		i++;
		fscanf(fichero_clientes,FORMATO_R,&id_aux,nom,apa,ama,fec,&cre,&deu);
		if(id==id_aux)
		{
			borra_linea(i);
			break;
		}
	}
	fclose(fichero_clientes);
}
/*
* borra_linea(): Utiliza la utilidad del sistema 'sed' para borrar la línea del
* fichero especificada.
*/
void borra_linea(int linea)
{
	int i=0;
	char* comand=(char*)malloc(MAX*sizeof(char));
	FILE *fichero=fopen("borra.sh","w");
	system("chmod +x borra.sh");
	fprintf(fichero,"sed -i'.bak' '%dd' clientes.txt",linea);
	fclose(fichero);
	system("./borra.sh");
	system("rm borra.sh clientes.txt.bak");
}
/*
* mofica(): Busca en el archivo el número de línea correspondiente al registro
* modificar, manda a llamar a la funcion insertar_linea() y borra el resgistro
* antiguo.
*/
void mofica(int id)
{
	long int pos;
	int id_aux,i=0;
	char* nom=(char*)malloc(MAX*sizeof(char));
	char* apa=(char*)malloc(MAX*sizeof(char));
	char* ama=(char*)malloc(MAX*sizeof(char));
	char* fec=(char*)malloc(11*sizeof(char));
	float cre,deu;
	cliente* lain;
	lain=get_memoria(lain);
	Registro(lain);
	fichero_clientes=fopen("clientes.txt","r");
	while(!feof(fichero_clientes))
	{
		i++;
		fscanf(fichero_clientes,FORMATO_R,&id_aux,nom,apa,ama,fec,&cre,&deu);
		if(id==id_aux)
		{
			(*lain).id_cliente=id;
			inserta_linea(i,lain);
			borra_linea(i);
			break;
		}
	}
	fclose(fichero_clientes);
}
/*
* inserta_linea(): Inserta en la línea especificada por 'linea' los datos en el
* struct cliente.
*/
void inserta_linea(int linea,cliente* reg)
{
	int i=0;
	char* comando=(char*)malloc(MAX*sizeof(char));
	FILE *fichero=fopen("insert.sh","w");
	system("chmod +x insert.sh");
	fprintf(fichero,"sed -i'.bak' '%da",linea);
	fprintf(fichero,"\\");
	fprintf(fichero,"%d\t%s\t%s\t%s\t%s\t%.2f\t%.2f' clientes.txt",
		(*reg).id_cliente,
		(*reg).nombre,
		(*reg).ap_paterno,
		(*reg).ap_materno,
		(*reg).fecha_alta,
		(*reg).credito,
		(*reg).deuda
	);
	fclose(fichero);
	system("./insert.sh");
	system("rm insert.sh clientes.txt.bak");
}
/*
* valida_positivo(): Valida que el dato sea mayor o igual a cero.
*/
int valida_positivo(float f)
{
	if(f>=0)
		return 1;
	else 
		return 0;
}
/*
* selecciona_columnas(): Selecciona las columnas a imprimir en pantalla.
*/
void selecciona_columnas(char* cadena)
{
	if(equals(cadena,"0000000"))
		printf("\nNada que ver\n");
	else
	{
		int i,id;
		char* nom=(char*)malloc(MAX*sizeof(char));
		char* apa=(char*)malloc(MAX*sizeof(char));
		char* ama=(char*)malloc(MAX*sizeof(char));
		char* fec=(char*)malloc(11*sizeof(char));
		float cre,deu;
		fichero_clientes=fopen("clientes.txt","r");
		//printf(HEADER);
		while(!feof(fichero_clientes))
		{
			fscanf(fichero_clientes,FORMATO_R,&id,nom,apa,ama,fec,&cre,&deu);
			for(i=0;cadena[i]!='\0';i++)
			{
				if(cadena[i]=='1')
				{
					switch(i)
					{
						case 0:
							printf("| %d\t",id);
						break;
						case 1:
							printf("|\t%s\t",nom);
						break;
						case 2:
							printf("|\t%s\t",apa);
						break;
						case 3:
							printf("|\t%s\t",ama);
						break;
						case 4:
							printf("| %s ",fec);
						break;
						case 5:
							printf("|\t%.2f\t",cre);
						break;
						case 6:
							printf("|\t%.2f |",deu);
						break;
						default:
							printf("\nERROR:CADENA INVÁLIDA\n");
						break;
					}
				}	
			}
			printf("\n");
    	}
		fclose(fichero_clientes);
	}	
}
/*
* Inicio del método main
*/
int main(void)
{
	LIMPIAR;
	comprueba_archivo();
	menu();
	return 0;
}
