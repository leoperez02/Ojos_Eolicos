#include<stdio.h>
#include<stdlib.h>

int* merge_sort(int*,int);
void printa(int*,int);
int** dividir(int*,int,int**);
int tamano(int*);
int* merge(int*,int*,int,int);

int* merge_sort(int* A,int n)
{
	if(n<=1)
		return A;
	else
	{
		int **A_i_d=dividir(A,n,A_i_d);
		int *A_i=A_i_d[0];
		int *A_d=A_i_d[1];
		/* Test
		printf("\nTamanos n_i: %d\nn_d: %d",tamano(A_i),tamano(A_d));
		printf("\nArreglos 2:\n");
		printa(A_i,tamano(A_i));
		printf("\n");
		printa(A_d,tamano(A_d));
		*/
		int* O_i=merge_sort(A_i,tamano(A_i));
		int* O_d=merge_sort(A_d,tamano(A_d));
		int* O=merge(O_i,O_d,tamano(O_i),tamano(O_d));
		return O;
	}
}

int** dividir(int* A,int n ,int** A_i_d)
{
	int n_i;
	int n_d;
	int* A_i;
	int* A_d;
	if(n%2==0)
	{
		n_i=n/2;
		n_d=n_i;
	}
	else
	{
		n_i=(n+1)/2-1;
		n_d=(n+1)/2;
	}
	
	A_i=(int*)malloc((n_i+1)*sizeof(int));
	A_d=(int*)malloc((n_d+1)*sizeof(int));
	
	int i;
	for(i=0;i<n_i;i++)
		A_i[i]=A[i];
	A_i[i]='\0';
	int j;
	for(j=0;i<n;j++,i++)
		A_d[j]=A[i];
	A_d[j]='\0';
	
	A_i_d=(int**)malloc(2*sizeof(int*));
	*(A_i_d+0)=A_i;	
	*(A_i_d+1)=A_d;	
	/* Test
	// printf("\nArreglos:\n");
	// printa(A_i,n_i);
	// printf("\n");
	// printa(A_d,n_d);
	/*
	******************************** */
	return A_i_d;
}

int* merge(int* O_i,int* O_d, int n_i,int n_d)
{
	int* O=(int*)malloc((n_i+n_d)*sizeof(int));
	int i=0;
	int j=0;
	int k=0;
	while(i<n_i && j<n_d)
	{
		if(O_i[i]<O_d[j])
		{
			O[k]=O_i[i];
			i++;
		}
		else
		{
			O[k]=O_d[j];
			j++;
		}
		k++;
	}
	if(i<n_i)
	{
		for(;i<n_i;i++)
		{
			O[k]=O_i[i];
			k++;
		}
	}
	else
	{
		for(;j<n_d;j++)
		{
			O[k]=O_d[j];
			k++;
		}
	}
	return O;
}

int tamano(int* A)
{
	int tam;
	for(tam=0;A[tam]!='\0';tam++);
	return tam;
}

int main(void)
{
	int n;
	printf("Escribe el valor de n=");
	scanf("%d",&n);
	fflush(stdin);
	int* A=(int*)malloc(n*sizeof(int));
	printf("Escribe los numeros:\n");
	for(int i=0;i<n;i++)
	{
		printf("#%d--> ",i+1);
		scanf("%d",A+i);
		fflush(stdin);
	}
	printa(A,n);
	A=merge_sort(A,n);
	printf("\n\n");
	printa(A,n);
	return 1;
}

void printa(int* A,int n)
{
	for(int i=0;i<n;i++)
		printf("%d, ",A[i]);
}