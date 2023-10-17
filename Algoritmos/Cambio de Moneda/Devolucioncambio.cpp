#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ENTER 13 //13 es la tecla Enter/

int main(void);
void pausa(void);
void captura(void);
void monedas(int);

int main(){
	captura();
	pausa();
}

void pausa(){
	printf("\nPresione Enter para continuar\n");
	while(getch()!=ENTER);
}

void captura(){
	float monto,pago;
	int cambio;
	
	printf("Programa 'Devolucion de cambio'");
	
	printf("\nCantidad que se pagara:");
	scanf("%f",&monto);
	
	printf("Cantidad que se dio: ");
	scanf("%f",&pago);
	
	cambio=(int)(pago)-(int)(monto);
	printf("Su cambio es %d",cambio);
	
	monedas(cambio);
}

void monedas(int x){
	int c500=0,c200=0,c100=0,c50=0,c20=0,c10=0,c5=0,c2=0,c1=0;
	
	while(x>=500){
		x-=500;
		c500++;
	}
	if(c500!=0){
		printf("\n\nRegresar %d billetes de 500 pesos",c500);
	}
	
	
	//--------------------------------------------------------------
	
	while(x>=200){
		x-=200;
		c200++;
	}
	if(c200!=0){
		printf("\n\nRegresar %d billetes de 200 pesos",c200);
	}
	
	//--------------------------------------------------------------
	
	while(x>=100){
		x-=100;
		c100++;
	}

	if(c100!=0){
		printf("\n\nRegresar %d billetes de 100 pesos",c100);
	}
	
	//--------------------------------------------------------------
	
	while(x>=50){
		x-=50;
		c50++;
	}

	if(c50!=0){
		printf("\n\nRegresar %d billetes de 50 pesos",c50);
	}
	
	//--------------------------------------------------------------

	while(x>=20){
		x-=20;
		c20++;
	}

	if(c20!=0){
		printf("\n\nRegresar %d billetes de 20 pesos",c20);
	}

	//--------------------------------------------------------------

	while(x>=10){
		x-=10;
		c10++;
	}
	
	if(c10!=0){
		printf("\n\nRegresar %d billetes de 10 pesos",c10);
	}
	
	//--------------------------------------------------------------

	while(x>=5){
		x-=5;
		c5++;
	}
	if(c5!=0){
		printf("\n\nRegresar %d billetes de 5 pesos",c5);
	}
	
	//--------------------------------------------------------------

	while(x>=2){
		x-=2;
		c2++;
	}

	if(c2!=0){
		printf("\n\nRegresar %d billetes de 2 pesos",c2);
	}
	
	//--------------------------------------------------------------
	
	while(x>=1){
		c1++;
		x-=1;
	}
	
	if(c1!=0){
		printf("\n\nRegresar %d billetes de 1 pesos",c1);
	}
}
