#include "stm32f103xb.h"
/*15. Diseñar una solución programable de manera tal que en el Puerto A se refleje el valor
del Puerto B con un desplazamiento lógico a la izquierda. Utilizar el operador <<.*/
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

    uint16_t puertoB = GPIOB -> IDR;
    GPIOA -> BSRR = puertoB << 1; //b desplaza 1 a la izquierda

            }
return 0;
}