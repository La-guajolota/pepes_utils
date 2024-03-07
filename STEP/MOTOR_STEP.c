#include "MOTOR_STEP.h"

void motor_init(stepper_t *motor)
{
    motor->dir = paro;
    motor->steps = 0;
}

void run_motor(stepper_t *motor, uint8_t direccion, void (*move_motor)(uint8_t))
{

    // modificamos el estado del motor
    motor->dir = direccion;

    switch (direccion)
    {
    case sentido_0:
        motor->steps += 1;
        break;
    case sentido_1:
        motor->steps -= 1;
        break;
    default:
        break;
    }
    // Ejecutamos dicho movimiento al mototr correspondinte
    move_motor(motor->dir);
}