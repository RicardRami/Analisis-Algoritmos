#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int ric, num1, num2;
char letra[3][2];

int AbrirArch(){
    int i=0;
    FILE* entrada = fopen ("ejemploEntradaP4.txt", "rb");
    	if (entrada == NULL ) {
    		perror ("Error al abrir");
    		return 1;
    	}
    while(!feof(entrada)){
        fscanf (entrada, "%d", &ric);
    	fscanf (entrada, "%s%d%d", letra[i++], &num1, &num2);
    		printf (" \t  (%dx%d) \t", num1, num2);
    }
    fclose(entrada);
    return ric;
}

int FinalArch(int n){
    FILE  * escribir = fopen ("salidaPractica4.txt", "w");
        	if (escribir == NULL) {
        		perror ("Error al crear el archivo");
            }else{
                fprintf(escribir, "Resultado %d", n);
                }
}
int MultiMatrix(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;
 

    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
 
    return m[1][n-1];
 
}
 
int main()
{
    int n,i;
    AbrirArch();
   // printf("Valor de ric: %d\n", ric);
   // printf("Numero de matrices\n");
   // scanf("%d",&ric);
 
    ric++;
 
    int arr[ric];
 
    printf("Dimensiones \n");
 
    for(i=0;i<ric;i++)
    {
        printf("Enter d%d :: ",i);
        scanf("%d",&arr[i]);
    }

    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimo numeros de multiplicaciones es: %d ", MultiMatrix(arr, size));
    MultiMatrix(arr, size)==n;
    FinalArch(n);
    return 0;
}
