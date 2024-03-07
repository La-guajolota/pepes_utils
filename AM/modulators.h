#ifndef MODULATORS_H
#define MODULATORS_H

#include <stdint.h>
#include <math.h>

#define resolution (sqrt(12) - 1)  // DAC
#define sampling 100.0             // cantidad de muestras
#define w (2 * 3.1416)             // velocidad angular
#define dc_offset (resolution / 2) // componente dc

// Moduladorar
struct sig_m
{
    uint16_t A; // amplitud
    uint16_t f; // frecuecnia
};

// Portadora
struct sig_c
{
    uint16_t A; // amplitud
    uint16_t f; // frecuencia
};

typedef struct AM
{
    // Señales para mezclar
    struct sig_m moduladora;
    struct sig_c portadora;

    // paramentros de para la genracion de outs
    float t_ciclo_completo;
    float step;

    // outputs
    uint16_t *dac_values; // puntero al arreglo de los outs
} sig_AM;

// METODOS
void init_AM(sig_AM *am); // genera los parametros

void modulate(sig_AM *am); // modula la señal, puntero al arreglo de los outs

#endif