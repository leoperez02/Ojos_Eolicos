#include "tabla_entidades.h"
void imprime_tabla()
	{	
		printf("\n\nESTADO				CLAVE");
		printf("\n--------------------------------------");
		printf("\nAGUASCALIENTES			AS");
		printf("\nBAJA CALIFORNIA			BC");
		printf("\nBAJA CALIFORNIA SUR		BS");
		printf("\nCAMPECHE			CC");
		printf("\nCOAHUILA			CL");
		printf("\nCOLIMA				CM");
		printf("\nCHIAPAS				CS");
		printf("\nCHIHUHUA			CH");
		printf("\nDISTRITO FEDERAL		DF");
		printf("\nDURANGO				DG");
		printf("\nGUANAJUATO			GT");
		printf("\nGUERRERO			GR");
		printf("\nHIDALGO				HG");
		printf("\nJALISCO				JC");
		printf("\nMEXICO				MC");
		printf("\nMICHOACAN			MN ");
		printf("\nMORELOS				MS ");
		printf("\nNAYARIT				NT ");
		printf("\nNUEVO LEON			NL  ");
		printf("\nOAXACA				OC");
		printf("\nPUEBLA				PL  ");
		printf("\nQUERETARO			QT ");
		printf("\nQUINTANA ROO			QR");
		printf("\nSAN LUIS POTOSI			SP ");
		printf("\nSINALOA				SL  ");
		printf("\nSONORA				SR ");
		printf("\nTABASCO				TC ");
		printf("\nTAMAULIPAS			TS ");
		printf("\nTLAXCALA			TL  ");
		printf("\nVERACRUZ			VZ  ");
		printf("\nYUCATAN				YN ");
		printf("\nZACATECAS			ZS  ");
 	 	printf("\nNACIDO EN EL EXTRANJERO		NE ");
		printf("\n");
	}
int verifica_entidad(char entidad[3])
	{
		int i, validador = 1 ;
		char entidades[33][2] ;

		 entidades[0][0] = 'A' ;   entidades[0][1] = 'S'  ;
		 entidades[1][0] = 'B' ;   entidades[1][1] = 'C' ;
		 entidades[2][0] = 'B' ;   entidades[2][1] = 'S'  ;
		 entidades[3][0] = 'C' ;   entidades[3][1] = 'C' ;
		 entidades[4][0] = 'C' ;   entidades[4][1] = 'L'  ;
		 entidades[5][0] = 'C' ;   entidades[5][1] = 'M' ;
		 entidades[6][0] = 'C' ;   entidades[6][1] = 'S' ;
		 entidades[7][0] = 'C' ;   entidades[7][1] = 'H' ;
		 entidades[8][0] = 'D' ;   entidades[8][1] = 'F'  ;
		 entidades[9][0] = 'D' ;   entidades[9][1] = 'G' ;
		 entidades[10][0] = 'G' ;   entidades[10][1] = 'T' ;
		 entidades[11][0] = 'G' ;   entidades[11][1] = 'R' ;
		 entidades[12][0] = 'H' ;   entidades[12][1] = 'G' ;
		 entidades[13][0] = 'J' ;   entidades[13][1] = 'C' ;
		 entidades[14][0] = 'M' ;   entidades[14][1] = 'C' ;
		 entidades[15][0] = 'M' ;   entidades[15][1] = 'N' ;
		 entidades[16][0] = 'M' ;   entidades[16][1] = 'S' ;
		 entidades[17][0] = 'N' ;   entidades[17][1] = 'T' ;
		 entidades[18][0] = 'N' ;   entidades[18][1] = 'L' ;
		 entidades[19][0] = 'O' ;   entidades[19][1] = 'C' ;
		 entidades[20][0] = 'P' ;   entidades[20][1] = 'L' ;
		 entidades[21][0] = 'Q' ;   entidades[21][1] = 'T' ;
		 entidades[22][0] = 'Q' ;   entidades[22][1] = 'R' ;
		 entidades[23][0] = 'S' ;   entidades[23][1] = 'P' ;
		 entidades[24][0] = 'S' ;   entidades[24][1] = 'L' ;
		 entidades[25][0] = 'S' ;   entidades[25][1] = 'R' ;
		 entidades[26][0] = 'T' ;   entidades[26][1] = 'C' ;
		 entidades[27][0] = 'T' ;   entidades[27][1] = 'S' ;
		 entidades[28][0] = 'T' ;   entidades[28][1] = 'L' ;
		 entidades[29][0] = 'V' ;   entidades[29][1] = 'Z' ;
		 entidades[30][0] = 'Y' ;   entidades[30][1] = 'N' ;
		 entidades[31][0] = 'Z' ;   entidades[31][1] = 'S' ;
		 entidades[32][0] = 'N' ;   entidades[32][1] = 'E' ;
		 
		 for ( i = 0 ; i < 33 ; i++ )
			{
				if( entidad[0] == entidades[i][0] )
					if (entidad[1] != entidades[i][1])
						{
							validador =  0;
						}
					else
						{
							return 1;
						}
				else
					validador = 0 ;
			}
		 if (validador== 0)
				printf("\n\nClave de entidad incorrecta. Verifica por favor\n");
		return validador;
	}