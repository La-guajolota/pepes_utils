#include "modulators.h"
#include <stdlib.h> //memoria dinamica

void init_AM(sig_AM *am)
{
    am->t_ciclo_completo = 1 / am->moduladora.f; // periodo de modulada
    am->step = (1 / am->portadora.f) / 10;       // periodo de portadora / muestras
}

void modulate(sig_AM *am) // modula la señal
{
    // self.A_c*math.sin(w*self.f_c*t)+((self.A_m*math.sin(w*self.f_m*t))*(math.sin(w*self.f_c*t)))
    float t = 0; // tiempo inicial
    int i = 0;

    int cant = am->t_ciclo_completo / am->step;
    uint16_t dac_values[cant];

    do // populamos
    {
        dac_values[i] = am->portadora.A * sinf(w * am->portadora.f * t) + ((am->moduladora.A * sinf(w * am->moduladora.f * t) * sin(w * am->portadora.f * t))) + dc_offset;
        t += am->step;
        i++;
    } while (i <= cant);

    am->dac_values = dac_values; // pasamos direccion de memoria
}