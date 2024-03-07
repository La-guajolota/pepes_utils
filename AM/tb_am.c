#include <stdio.h>
#include "modulators.h"

void guardarCSV(uint16_t array[], int longitud, const char *nombreArchivo);

int main()
{

    sig_AM sennal; // instancia

    sennal.moduladora.A = 300; // en bits de resolucion
    sennal.moduladora.f = 1;   // hz
    sennal.portadora.A = 1;
    sennal.portadora.f = 300;

    init_AM(&sennal);
    modulate(&sennal); // modulamos la señal

    /*
    int i;
    for (i = 0; i < sampling; i++)
    {
        printf("%d\n", sennal.dac_values[i]);
    }
    */

    guardarCSV(sennal.dac_values, sampling, "datos.csv");

    return 0;
}

void guardarCSV(uint16_t array[], int longitud, const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "w"); // Abrir archivo en modo escritura
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo %s\n", nombreArchivo);
        return;
    }

    // Escribir los elementos del array en formato CSV
    for (int i = 0; i < longitud; i++)
    {
        fprintf(archivo, "%d", array[i]); // Escribir el elemento
        if (i < longitud - 1)
        {
            fprintf(archivo, "\n"); // Agregar coma si no es el último elemento
        }
    }

    fclose(archivo); // Cerrar archivo
}