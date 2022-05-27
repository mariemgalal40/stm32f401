#include "GPIO.h"
#include "EXIT.h"

int i,j;
unsigned char counter=0;
unsigned char sevenseg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Display (unsigned char);
void Interruptdisable();
void Interruptenable();

int main(void) {
	unsigned char loccounter;
	GPIO_EnableClock(0);  //	enable clock of port A
	GPIO_EnableClock(1);  //	enable clock of port B
	SYSCFG_EnableClock(14);  //	enable SYSCFG
//	make the pins from 0 to 6 in port A output and pins 0 and 1 input in port B
	GPIO_Init(0, 0 , INPUT	, PULL_UP);
	GPIO_Init(0, 1 , INPUT	, PULL_UP);
	for (i=0;i<7;i++){
			GPIO_Init(1, i , OUTPUT, PUSH_PULL);
			}
	*SYSCFG_EXTICR1 &= ~(0x0f << 0); //	external interrupt for pin 0 and 1 in port A
	*SYSCFG_EXTICR1 &= ~(0x0f << 4);
	*EXTI_FTSR |= (0x01<<0) ;  //  faling edge
	*EXTI_FTSR |= (0x01<<1) ;
	*EXTI_IMR |=  0x01 << 0 ;  //	Unmasking the interrupt on EXTI 0 and 1
	*EXTI_IMR |=  0x01 << 1 ;
	*NVIC_ISER = (0x01<<6) ;  //	enable the interrupt line 0 and 1 in NVIC
	*NVIC_ISER = (0x01<<7) ;
  while (1) {
	  Interruptdisable();
	  loccounter = counter;
	  Interruptenable();
	  Display(loccounter);
  }
  return 0;
}
void Display(unsigned char counter) {
	for(j=0;j<7;j++){
		  if((sevenseg[counter] & (1<<j))>>j){
		     GPIO_WritePin(1, j, 1);
	           		}
		  else {
		  	 GPIO_WritePin(1, j, 0);
		  	   }
         			}
}
void  ISR_Increment()
	{
	if (counter == 9){
		counter = 9;
		     }
	else{
		counter=counter +1 ;
			}
	*EXT1_PR |= (1<<0) ;
	}
void  ISR_Decrement()
	{
	if (counter == 0){
			counter = 0;
	}
			else{
	counter=counter - 1 ;
			}
	*EXT1_PR |= (1<<1) ;
	}
void Interruptdisable(){
//	Masking the interrupt on EXTI 0 and 1
	*EXTI_IMR &= ~(0x0f<<0) ;
	*EXTI_IMR &= ~(0x0f<<1) ;
}
void Interruptenable(){
//	Unmasking the interrupt on EXTI 0 and 1
	*EXTI_IMR |=  0x01 << 0 ;
	*EXTI_IMR |=  0x01 << 1 ;
}

