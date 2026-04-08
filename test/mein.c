#include "stm32f103xb.h"
int main(void){
/*1- Habilito clk del puerto (RCC->APB2ENR)
  2- Borro el registro de CRL/CRH (GPIOx -> CRL/CRH&=~)
  3- Configuro el pin (GPIOx -> CRL/CRH|=) */
  RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
  GPIOA -> CRL&=~(0xF<<((14-8)*4));
  GPIOA -> CRL|=(0x1<<((14-8)*4));
    while(1){
        //4- Enciendo el pin (GPIOx -> BSRR)
        GPIOA -> BSRR|=(1<<14);
    }
return 0;
}