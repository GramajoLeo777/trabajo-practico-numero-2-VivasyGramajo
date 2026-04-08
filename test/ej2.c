#include "stm32f103xb.h"
//2. Diseñar una solución programable de manera tal que en el Puerto A se visualice el
//complemento a 1 del Puerto B.
int main(void){
    RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
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
    int est = GPIOB -> IDR&(1<<i);      //leo el valor del bit
            if (est) GPIOA -> BSRR |= (1<<(i+16));   //estado alto (en este caso es negado)
            else{
                     GPIOA -> BSRR |= (1<<i); //estado bajo (lo  mismo q arriba)
            }
        }
            }
return 0;
}