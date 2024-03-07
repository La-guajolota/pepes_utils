#ifndef MOTOR_STEP
#define MOTOR_STEP

// Libreria del MCU en cuestion
// #include "project.h"

// Librerias de C nativas
#include <stdint.h>

// macros y variables globales
// #define rotation_full 2037 //2037.8864
#define sentido_0 0x00 // rota a un sentido 0
#define sentido_1 0x01 // rota al sentido contrario
#define paro 0x02      // motor inmovil

// Secuencia caracteristica del
#define size 8
#define patron                                         \
    {                                                  \
        0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09 \
    }

// Parametros de un motor
typedef struct motor
{
    uint8_t dir;    // direccion y paro o corriendo
    uint16_t steps; // cantidas de steps que se ha dado
} stepper_t;

// METODOS
void motor_init(stepper_t *motor);                                                // inicializa instancia
void run_motor(stepper_t *motor, uint8_t direccion, void (*move_motor)(uint8_t)); // configuramos el estado del motor

#endif