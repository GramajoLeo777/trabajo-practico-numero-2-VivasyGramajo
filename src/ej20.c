#include "stm32f103xb.h"
/*20. Diseñar una solución programable de manera tal que las salidas A0 y A1 se activen si
B0 está activo, las salidas A2 y A3 se activen si B1 está activo, las salidas A4 y A5 se activen
si B2 está activo, las salidas A6 y A7 se activen si B3 está activo.*/
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

    int est0 = GPIOB -> IDR&(1<<0);
    int est1 = GPIOB -> IDR&(1<<1);
    int est2 = GPIOB -> IDR&(1<<2);
    int est3 = GPIOB -> IDR&(1<<3);

        if (est0){
           GPIOA -> BSRR |= (1<<0);
           GPIOA -> BSRR |= (1<<1);
  
    } 
    if (est1) {
        GPIOA -> BSRR |= (0<<2);
        GPIOA -> BSRR |= (0<<3);
    } 
    if(est2){
        GPIOA -> BSRR |= (0<<4);
        GPIOA -> BSRR |= (0<<5);
    }
    if(est3){
        GPIOA -> BSRR |= (0<<6);
        GPIOA -> BSRR |= (0<<7);
    }
    }
           
return 0;
}