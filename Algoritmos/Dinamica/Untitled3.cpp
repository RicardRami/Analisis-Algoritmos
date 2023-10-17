#include <stdio.h>
#include <string.h>
// Debe ser de la máxima + 1. Por ejemplo, si la máxima es 4, defínela como 5
#define MAXIMA_LONGITUD_CADENA 1000
// La máxima cantidad de líneas que puede tener
#define CANTIDAD_LINEAS 5
#define NOMBRE_ARCHIVO "ejemploEntradaP4.txt"

/*
	https://parzibyte.me/blog
*/

int main()
{
    // Arreglo de cadenas: aquí almacenamos todas las palabras
    char palabras[CANTIDAD_LINEAS][MAXIMA_LONGITUD_CADENA];
    // Útil para leer el archivo
    char buferArchivo[MAXIMA_LONGITUD_CADENA];
    // Abrir el archivo...
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo");
        return 0;
    }
    // Necesitamos este ayudante para saber en qué línea vamos
    int indice = 0;
    // Mientras podamos leer una línea del archivo
    while (fgets(buferArchivo, MAXIMA_LONGITUD_CADENA, archivo))
    {
        // Remover salto de línea
        strtok(buferArchivo, "\n");
        // Copiar la línea a nuestro arreglo, usando el índice
        memcpy(palabras[indice], buferArchivo, MAXIMA_LONGITUD_CADENA);
        // Aumentarlo en cada iteración
        indice++;
    }

    // Terminamos de leer
    fclose(archivo);
    // Ahora ya tenemos el arreglo. Podemos imprimirlo
    int i;
    for (i = 0; i < CANTIDAD_LINEAS; i++)
    {
        printf("Tenemos una línea: '%s'\n", palabras[i]);
    }
    return 0;
}
