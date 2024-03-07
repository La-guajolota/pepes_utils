#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define pi2 (2.0*3.1416) // Definición de 2*pi
#define samples 255 //Numero de muestreos

uint8_t signal[samples]; //Aquí guardamos os valores discretizados de la funcion señal

void discrt_func(uint16_t *signal, float A, float dc){

    float w;
    //float A= 127.5, dc=A;//Amlitud y componente dc en referencia del voltaje maximo en resolución de 8bits

    for(int i=0;i<samples;i++){//Discretizamos la señal funcion
        w= pi2*(1/(float)samples)*(float)(i);//2pi*angulo rd
        signal[i] = (int16_t)(sin(w)*A+dc);// A*sin(2Wft)+DC

        //debug
        printf("%d\n",signal[i]);
    }
}

//Ejecutamos algoritmo
int main(){

    discrt_func(signal,254/2,254/2);

    return 0;
}