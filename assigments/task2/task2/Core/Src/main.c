#include "stm32f401cc_interface.h"

int main(void) {
	int i;
	int j=0;
	//enable clock
	RCC->AHB1ENR |= (1<<1);
    //clearing the pins (3,5,6,7)
	GPIOB->MODER &= ~((1011<<6));
    //set the 3 pins of the led as output (5,6,7)
    GPIOB->MODER |= ((21<<10));
    //set the led push-pull
    GPIOB->OTYPER &=~(7<<5);
    //set pin 3 as input
    GPIOB->MODER &= ~((3<<6));
    unsigned int color[] ={0b00100000,0b01100000,0b01000000,0b11000000,0b10000000,0b11100000,0b10100000,0b00000000};

    while (1) {
	  int rising,falling;
	  rising = GPIOB->IDR;
	  for(i=0;i<10000;i++){}
	  falling = GPIOB->IDR;
      if (j==8){
    	 j=0;
      }
      if(((GPIOB->IDR & (1<<3)) >>3) &&(rising != falling) ){
      GPIOB->ODR = color[j] ;
      for(i=0;i<100000;i++){}
      j++;

      }


  }
  return 0;
}


