#include "GPIO.h"
#include "EXIT.h"
unsigned char state=0;
int main(void) {

	GPIO_EnableClock(0);   //	enable clock of poat A
	Timer_EnableClock(14);  //	enable clock of external interrupt
	GPIO_Init(0, 0 , INPUT	, PULL_UP);  //	make pin 0 inpt and 7 output
	GPIO_Init(0, 7 , OUTPUT, PUSH_PULL);
	*EXTI_IMR |=  0x01 << 0 ; //	interrupt mask register for line 1 for rexternal_interrupt 0
	*EXTI_FTSR |= (0x01<<0) ; //  faling interrupt
	*SYSCFG_EXTICR1 &= ~(0x0f<<0) ;  //	external interrupt for pin 0 in port A
	*NVIC_ISER = (0x01<<6) ;   //	enable the interrupt line 0 in NVIC
  while (1) {
  }
  return 0;
}
void  toggle_led()
	{
    state =~ state;
	GPIO_WritePin(0, 7, state) ;
	*EXT1_PR |= (1<<0) ;
	}




