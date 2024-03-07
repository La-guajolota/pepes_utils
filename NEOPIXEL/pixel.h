#include <stdint.h>

#ifndef PIXEL
#define PIXEL

#define N_pixel 8 // Modificar segun la cantidad de leds
#define total_bits (N_pixel * 8 * 3)

// Codigo rgb de un neopixel
struct pixel
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
};

typedef struct tira
{
    struct pixel LEDs[N_pixel];
    uint8_t vecotr[total_bits]; // 192 bits para 8 neopixel
} tira_T;

// METODOS
void blank(tira_T *tira); // setea

void vector_data(tira_T *tira); // Obtine vector de datos

void send_colors(tira_T *tira); // mandamos los bytes de info a la tira

#endif