#include "GPIO.h"
#include "Keypad.h"

int i,j;
unsigned char sevenseg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char y;

int main(void) {
	GPIO_EnableClock(0);
	GPIO_EnableClock(1);
	for (i=0;i<7;i++){
		GPIO_Init(0, i , OUTPUT, PUSH_PULL);
		}
	Keypdad_init();

  while (1) {
	Keypad_manage();
  }

  return 0;
}

void  KeypadCallouts_KeyPressNotificaton()
	{
		y= Keypad_GetKey();
		for(j=0;j<7;j++){
		    if((sevenseg[y] & (1<<j))>>j){
      			GPIO_WritePin(0, j, 1);
	            		}
		    else {
		    	GPIO_WritePin(0, j, 0);
		    	 }
		    			}
	}
