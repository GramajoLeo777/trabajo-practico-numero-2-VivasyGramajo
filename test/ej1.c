#include "stm32f103xb.h"
/*1. Diseñar una solución programable de manera tal que en el Puerto A se reflejen los
estados del Puerto B.*/
int main(void){
    RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN; //habilitar los clocks 
    RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
        for(int i=0;i<7;i++) {
            GPIOA ->CRL&=~(0xF<<i*4); // BORRO EL REGISTRO DEL VALOR DE RESET
            GPIOA ->CRL|=(0x4<<i*4); //CONFIGURO EL PIN (como entrada  float)
            GPIOB ->CRL&=~(0xF<<i*4); //borro registro de b
            GPIOB ->CRL|=(0x1<<i*4);//configuro pin como salida 
        }
        for(int i=7;i<15;i++){
            GPIOA ->CRH&=~(0xF<<(i%8)*4); // BORRO EL REGISTRO DEL VALOR DE RESET
            GPIOA ->CRH|=(0x4<<(i%8)*4); //CONFIGURO EL PIN (como entrada  float)
            GPIOB ->CRH&=~(0xF<<(i%8)*4); //borro registro de b
            GPIOB ->CRL|=(0x1<<(i%8)*4);//configuro pin como salida 
        }
            while(1){

        for(int i=0;i<15;i++){
    int est = GPIOB -> IDR&(1<<i);
            if (est) GPIOA -> BSRR |= (1<<i); //estado alto
            else{
                     GPIOA -> BSRR |= (1<<(i+16)); //estado bajo
            }
        }
            }
return 0;
}