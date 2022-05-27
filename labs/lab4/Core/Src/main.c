#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	GPIO_Init('A', 0 , OUTPUT, PUSH_PULL);
  while (1) {
	  //led on
	  GPIO_WritePin('A', 0, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
	  //led of
	  GPIO_WritePin('A', 0, 0);
	  //delay
	  for (int i = 0; i < 1000000; i++)
	  {
	  }
  }
  return 0;
}
