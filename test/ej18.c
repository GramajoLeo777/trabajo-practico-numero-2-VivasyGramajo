#include "stm32f103xb.h"
/*18. Diseñar una solución programable de manera tal que las salidas A0, A1, A2 y A3 se
activen si B0 está activo; y las salidas A4, A5, A6 y A7 se activen si B0 está inactivo.*/
int main(void){
    RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
    RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN;
        for(int i=0;i<7;i++) {
            GPIOB ->CRL&=~(0xF<<i*4); // BORRO EL REGISTRO DEL VALOR DE RESET
            GPIOB ->CRL|=(0x4<<i*4); //CONFIGURO EL PIN (como entrada  float)
            GPIOA ->CRL&=~(0xF<<i*4); //borro registro de b
            GPIOA ->CRL|=(0x1<<i*4);//configuro pin como salida 
        }
            while(1){

    int est = GPIOB -> IDR&(1<<0);
        if (est){
           GPIOA -> BSRR |= (1<<0);
           GPIOA -> BSRR |= (1<<1);
           GPIOA -> BSRR |= (1<<2);
           GPIOA -> BSRR |= (1<<3);
    } else {
        GPIOA -> BSRR |= (0<<4);
        GPIOA -> BSRR |= (0<<5);
        GPIOA -> BSRR |= (0<<6);
        GPIOA -> BSRR |= (0<<7);
    }
    
            }
return 0;
}