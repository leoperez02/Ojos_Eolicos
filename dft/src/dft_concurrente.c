#include "../lib/dft.h"
/**
* @brief Cálculo de la DFT implementando concurrencia (procesos) para incementar
*	la velocidad de cálculo.
* @param
* @param
*/
void calcula_dft(int N,int* vector)
{
	pid_t pid;
	int u,x;
	float re,im;
	for(u=0;u<N;u++)
	{
		printf("u=%d\n",u);
		re=0; im=0;
		if((pid=fork())==-1)
			exit(-1);
		else
		{
			if(pid==0) // Tarea del proceso hijo
			{
				for(x=0;x<N;x++)
				{
					printf("\t1/%d * f(%d)exp(-j2pi(%d)(%d)/%d) = ",N,x,u,x,N);
					float v1=(1/(float)N)*(*(vector+x));
					float v2=(2*x*u)/(float)N;
					printf("%.2f*exp(-jpi(%.2f)) = ",v1,v2);
					//printf("%.4f * ( cos(%.4fpi) - jsen(%.4fpi) )\n",v1,v2,v2);
					//printf("(%.4f)cos(%.4fpi) - j(%.4f)sen(%.4fpi) = ",v1,v2,v1,v2);
					printf("(%.2f)(%.2f)-j(%.2f)(%.2f) = ",v1,cos((double)(PI*v2)),v1,sin(PI*v2));
					printf("(%.2f)-j(%.2f) \n ",v1*cos((PI*v2)),v1*sin(PI*v2));
					re+=v1*cos((double)(PI*v2));
					im+=-1*v1*sin(PI*v2);
				}
				printf("\t\tF(%d) = %.4f+(%.4f)j\n",u,re,im);
				exit(EXIT_SUCCESS);
			}
			else
			{
				int status;
				waitpid(WAIT_ANY, &status, WUNTRACED);
			}
		}
	}
}
