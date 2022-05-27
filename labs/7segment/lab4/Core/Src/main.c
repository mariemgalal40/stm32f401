#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	unsigned char counter ;
	int i,j,k;

	//for making the 7 pins in port A output
	for (i=0;i<7;i++){
	GPIO_Init('A', i , OUTPUT, PUSH_PULL);
	}
  while (1) {
	  //for looping into the array
	  for (counter=0;counter<=9;counter++){
          // for comparing every pin to set it high or low
		  for(j=0;j<7;j++){
			  if(arr[counter]& (1<<j)){
				  GPIO_WritePin('A', j, 1);
			  }
			  else {
				  GPIO_WritePin('A', j, 0);
			  }
		  }
		  //delay
		  for (k = 0; k < 1000000; k++)
		  		  	  {
		  		  	  }
	  }

  }
  return 0;
}
