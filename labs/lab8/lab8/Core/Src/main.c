#include "GPIO.h"
#include "USART.h"


int main(void) {
	GPIO_EnableClock(0);    //	enable clock of port A

	GPIO_Init(0,2,ALTERNATE_FUN,PUSH_PULL); //set pin 2 ALTERNATE FUNCTION mode

	*GPIOA_AFRL |= 0x07 << 8;
//	USART_Init( 0x683,16, 8, transmitter ,1);
	*RCC_APB1ENR |= (0x01 << 17);  //enable clock of the USART2

	*USART_BRR |= 0x683 ;  //setting the baud_rate
	*USART_CR1 &= ~(0x01<<15); //oversampling by 16
	*USART_CR1 &= ~(0x01<<12); //setting 8 Data_bits
	*USART_CR1 |= 0x01<<3 ; //enable transmitter
	*USART_CR1 |= 0x01<<13 ; //enable USART
	*USART_CR2 &= ~(0x03<<12); //1 stop bit


	display("hello world");


  while (1) {
  }
  return 0;
}




