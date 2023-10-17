#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// Declaracion de numeros y letras del archivo a leer
int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16;
char letraA [2], letraB[2], letraC [2], letraD [2], letraE [2], letraF [2], letraG[2], letraH [2];

// Declaraciones de las operaciones
int multAB, multAB_C, sumAB_C;
int multBC, multA_BC, sumA_BC;
int multCD, multABC_D, sumABC_D, multA_BCD, multBC_D, sumBC_D, multB_CD, sumB_CD, sumA_BCD;
int multABCD_E, multA_BCDE, multBCD_E, multB_CDE, multCD_E, multC_DE, multDE;
int sumABCD_E, sumA_BCDE, sumBCD_E, sumB_CDE, sumC_DE, sumCD_E;


int abrirArch () {
	
	// Lectura del archivo
	FILE* entrada = fopen ("ejemploEntradaP4.txt", "rb");
	if (entrada == NULL ) {
		perror ("Error al abrir");
		return 1;
	}
	
	while (feof(entrada) == 0) {
		
		fscanf (entrada, "%s%d%d", &letraA, &num1, &num2);
		printf (" \t %s (%dx%d) \t", letraA, num1, num2);
		
		fscanf (entrada, "%s%d%d", &letraB, &num3, &num4);
		printf ("%s (%dx%d) \t", letraB, num3, num4);
		
		fscanf (entrada, "%s%d%d", &letraC, &num5, &num6);
		printf ("%s (%dx%d) \t", letraC, num5, num6);
		
		fscanf (entrada, "%s%d%d", &letraD, &num7, &num8);
		printf ("%s (%dx%d) \t ", letraD, num7, num8);
		
		
		fscanf (entrada, "%s%d%d", &letraE, &num9, &num10);
		printf ("%s (%dx%d) \t \n\n", letraE, num9, num10);
		
		//fscanf (entrada, "%s%d%d", &letraF, &num11, &num12);
		//printf ("%s (%dx%d) \t \n\n", letraF, num11, num12);
	
		//fscanf (entrada, "%s%d%d", &letraG, &num13, &num14);
		//printf ("%s (%dx%d) \t \n\n", letraG, num13, num14);
		
		//fscanf (entrada, "%s%d%d", &letraH, &num15, &num16);
		//printf ("%s (%dx%d) \t \n\n", letraH, num15, num16);
	}
	
	fclose (entrada);

	// AB
	multAB = (num1 * num4) * num2;
	
	// (AB)C
	multAB_C = (num1 * num6) * num5;
	sumAB_C = multAB + multAB_C;
	
	// BC
	multBC = (num3 * num6) * num4;
	
	// A(BC)
	multA_BC = (num1 * num6) * num2;
	sumA_BC = multBC + multA_BC;
	
	// (A(BC))D
	multABC_D = (num1 * num8) * num6;
	sumABC_D = sumA_BC + multABC_D; 

	// (BC)D
	multBC_D = (num3 * num8) * num6;
	sumBC_D = multBC_D + multBC;
	
	// CD
	multCD = (num5 * num8) * num7;
	
	// B(CD)
	multB_CD = (num3 * num8) * num5;
	sumB_CD = multCD + multB_CD;
	
	// A((BC)D)
	multA_BCD = (num1 * num8) * num2;
	sumA_BCD = sumBC_D + multA_BCD;
	
	
	// DE
	multDE = (num7 * num10) * num9;
	
	// (CD)E
	multCD_E = (num5 * num10) * num9;
	sumCD_E = multCD + multCD_E;
	
	// C(DE)
	multC_DE = (num5 * num10) * num7;
	sumC_DE = multDE + multC_DE;
	
	// ((BC)D)E
	multBCD_E = (num3 * num10) * num9;
	sumBCD_E = multBCD_E + sumBC_D;
	
	// B(C(DE))
	multB_CDE = (num3 * num10) * num4;
	sumB_CDE = multB_CDE + sumC_DE;	
	
	
	// A(B(C(DE))
	multA_BCDE = (num1 * num10) * num2;
	//sumA_BCDE = multA_BCDE + sumBCD_E;
	sumA_BCDE = multA_BCDE + sumB_CDE;
	
	// (A(BC)D)E
	
	multABCD_E = (num1 * num10) * num8;
	sumABCD_E = sumABC_D + multABCD_E;
	//sumABCD_E = sumA_BCD + multABCD_E;
	
	// Validacion
	if (num2 != num3) {
		printf ("\n\n\tSecuencia Invalida...\n\n");
		exit (-1);
		} else if (num4 != num5) {
			printf ("\n\n\tSecuencia Invalida...\n\n");
			exit (-1);
		} else if (num6 != num7) {
			printf ("\n\n\tSecuencia Invalida...\n\n");
			exit(-1);
		
		} else if (num8 != num9) {
			printf ("\n\n\tSecuencia Invalida...\n\n");
			exit(-1);
		} else {
			
			printf ("\tAB -> %d \n", multAB); // 30
			printf ("\t-------------------\n");
			
			printf ("\t(AB)C -> %d \n", sumAB_C); // 45
			printf ("\tA(BC) -> %d \n", sumA_BC); // 16
			printf ("\t-------------------\n");

			printf ("\tBC -> %d \n", multBC); // 10
			printf ("\t-------------------\n");
			
			printf ("\t(A(BC))D -> %d \n", sumABC_D); //28
			printf ("\tA((BC)D) -> %d \n", sumA_BCD); //42
			printf ("\t-------------------\n");

			printf ("\t(BC)D -> %d \n", sumBC_D); // 18
			printf ("\tB(CD) -> %d \n", sumB_CD); //60
			printf ("\t-------------------\n");

			printf ("\tCD -> %d \n", multCD); //20
			printf ("\t-------------------\n");
			
			/*if (sumB_CDE < sumBCD_E) {
				printf("");
			} */
			
			printf ("\t(A(BC)D)E -> %d \n", sumABCD_E); //52 ACTUALIZAR
			printf ("\tA(B(C(DE))) -> %d \n", sumA_BCDE); //46 ACTUALIZAR
			printf ("\t-------------------\n");

			printf ("\t((BC)D)E -> %d \n", sumBCD_E); //34
			printf ("\tB(C(DE)) -> %d \n", sumB_CDE); //38
			printf ("\t-------------------\n");

			printf ("\t(CD)E -> %d \n", sumCD_E); //60
			printf ("\tC(DE) -> %d \n", sumC_DE); //18
			printf ("\t-------------------\n");

			printf ("\tDE -> %d \n", multDE); //8
			printf ("\t-------------------\n");
			
			//printf ("\t %d \t", sumABC_D);
			//printf ("\t %d", multABCD_E);
		}	
	
	// ESCRITURA DE ARCHIVO
	FILE  * escribir = fopen ("salidaPractica4.txt", "w");
	if (escribir == NULL) {
		perror ("Error al crear el archivo");
	} else {
		if (sumA_BC < sumAB_C) {
			fprintf (escribir, "A(BC) es la solucion optima: %d\n", sumA_BC);
		} else {
			fprintf (escribir, "(AB)C es la solucion optima: %d\n", sumAB_C);
		}
		
		if (sumABC_D < sumA_BCD) {
			fprintf (escribir, "(A(BC))D es la solucion optima: %d\n", sumABC_D);
		} else {
			fprintf (escribir, "A((BC)D) es la solucion optima: %d\n", sumA_BCD);
		}
		
		if (sumBC_D < sumB_CD) {
			fprintf (escribir, "(BC)D es la solucion optima: %d\n", sumBC_D);
		} else {
			fprintf (escribir, "B(CD) es la solucion optima: %d\n\n", sumB_CD);
		}
		
		
		/*if (letraE [2] = false) { 
			fprintf (escribir, "No hay valores de matriz", letraE);
		} */
		
		 if (sumC_DE < sumCD_E) {
			fprintf (escribir, "C(DE) es la solucion optima: %d \n", sumC_DE);
		} else {
			fprintf (escribir, "(CD)E es la solucion optima: %d \n", sumCD_E);
		}
	
		if (sumBCD_E < sumB_CDE) {
			fprintf (escribir, "C((BC)D)E es la solucion optima: %d \n", sumBCD_E);
		} else {
			fprintf (escribir, "B(C(DE)) es la solucion optima: %d \n", sumB_CDE);
		}	
		
		if (sumA_BCDE < sumABCD_E) {
			fprintf (escribir, "A(((BC)D)E) es la solucion optima: %d \n", sumA_BCDE);
		} else {
			fprintf (escribir, "(A(BC)D)E es la solucion optima: %d \n", sumABCD_E);
		} 
		
		fflush (escribir);
		fclose (escribir);
		
		printf ("\n\n\tSecuencia Valida! \n\n\n");
	}
	
	system ("pause");
	return 0;

}

int main () {
	
	abrirArch ();
	//crearArch ();
}

