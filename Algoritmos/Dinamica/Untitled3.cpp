#include <stdio.h>
#include <string.h>
// Debe ser de la m�xima + 1. Por ejemplo, si la m�xima es 4, def�nela como 5
#define MAXIMA_LONGITUD_CADENA 1000
// La m�xima cantidad de l�neas que puede tener
#define CANTIDAD_LINEAS 5
#define NOMBRE_ARCHIVO "ejemploEntradaP4.txt"

/*
	https://parzibyte.me/blog
*/

int main()
{
    // Arreglo de cadenas: aqu� almacenamos todas las palabras
    char palabras[CANTIDAD_LINEAS][MAXIMA_LONGITUD_CADENA];
    // �til para leer el archivo
    char buferArchivo[MAXIMA_LONGITUD_CADENA];
    // Abrir el archivo...
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo");
        return 0;
    }
    // Necesitamos este ayudante para saber en qu� l�nea vamos
    int indice = 0;
    // Mientras podamos leer una l�nea del archivo
    while (fgets(buferArchivo, MAXIMA_LONGITUD_CADENA, archivo))
    {
        // Remover salto de l�nea
        strtok(buferArchivo, "\n");
        // Copiar la l�nea a nuestro arreglo, usando el �ndice
        memcpy(palabras[indice], buferArchivo, MAXIMA_LONGITUD_CADENA);
        // Aumentarlo en cada iteraci�n
        indice++;
    }

    // Terminamos de leer
    fclose(archivo);
    // Ahora ya tenemos el arreglo. Podemos imprimirlo
    int i;
    for (i = 0; i < CANTIDAD_LINEAS; i++)
    {
        printf("Tenemos una l�nea: '%s'\n", palabras[i]);
    }
    return 0;
}
