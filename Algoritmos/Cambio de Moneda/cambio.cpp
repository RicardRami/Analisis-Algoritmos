#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Frida Estrada Borja
//Loredo Cortes Luis Josue
//Ramírez Rodriguez Ricardo Daniel

//Analisis de Algoritmos 

int main()
{
	int filas=9 ,columnas=2, total=0, resultadoDiv=0, d=0, c=0, r=0;
	int dinero [filas][columnas]={{500,0},{200,0},{100,0},{50,0},{20,0},{10,0},{5,0},{2,0},{1,0}};
	int i=0, j=1;
	
	for (i=0; i<filas; i++){
		printf (" Ingrese la cantidad de billetes o monedas de %d \n", dinero[i][0]);
		scanf ("%d", &dinero[i][j]);	
	}
	
	for (i=0; i<filas; i++){
		printf ("\n");
		for (j=0; j<columnas; j++){
			printf (" %| %d", dinero[i][j]);
		}
	}
	
	printf (" \n Ingrese la cantidad a cambiar \n" );
	scanf ("%d",&total);
	
	
		for(i=0; i<filas; i++){
			d= dinero [i][0];
			c= dinero [i][1];
			resultadoDiv= total/d;
			if (resultadoDiv<= c){
				r= total-(d*resultadoDiv);
				printf (" %d  billetes/monedas de %d \n",resultadoDiv, dinero[i][0]);
			}
			else{
				r= total-(d*c);
				printf (" %d  billetes/monedas de %d \n",c, dinero[i][0]);
			}
			total= r;
			//printf (" cantidad de dinero que queda %d \n",total);
			if (total==0){
				break;
			}
		}
		
	return(0);
	
		
	
}


