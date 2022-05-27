#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
int main(void) {
	GPIO_Init('B', 5 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 6 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 7 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 3 , INPUT, PULL_UP);
    unsigned int color[] ={0b00100000,0b01100000,0b01000000,0b11000000,0b10000000
    		,0b11100000,0b10100000,0b00000000};
    unsigned char counter ;
    int i;
    int j;
  while (1) {
	  int rising,falling;
	  rising = GPIO_ReadPin('B', 3);
	  for(i=0;i<10000;i++){}
	  falling = GPIO_ReadPin('B', 3);
	  if (counter==8){
		  counter=0;
	       }
	  if( (rising==1 && falling==0)){
		  for(i=0;i<100000;i++){}
		  		  for(j=5;j<=7;j++){
		  			  if(color[counter]& (1<<j)){
		  				  GPIO_WritePin('B', j, 1);
		  			  }
		  			  else {
		  				  GPIO_WritePin('B', j, 0);
		  			  }
		  		  }
		  		counter++;
		  	  }
	  }
  return 0;
}


