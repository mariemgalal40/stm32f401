#include "Keypad.h"
#include "GPIO.h"
unsigned char key ;
unsigned char buttonState = 0;
unsigned char arr[4][3]={{1,2,3},{4,5,6},{7,8,9},{0,0,0}};
int k;
void Keypdad_init()
{
	GPIO_Init(1, 0, OUTPUT, PUSH_PULL);
	GPIO_Init(1, 1, OUTPUT, PUSH_PULL);
	GPIO_Init(1, 2, OUTPUT, PUSH_PULL);
	GPIO_Init(1, 3, INPUT, PULL_UP);
	GPIO_Init(1, 4, INPUT, PULL_UP);
	GPIO_Init(1, 5, INPUT, PULL_UP);
	GPIO_Init(1, 6, INPUT, PULL_UP);

	}

void Keypad_manage()
{

	unsigned char row,column,x;
	if(buttonState == 0){
	 for(column=0;column<3;column++)
	 {
		 GPIO_WritePin(1,0,1);
		 GPIO_WritePin(1,1,1);
		 GPIO_WritePin(1,2,1);
		 GPIO_WritePin(1,column,0);
	     for(row=3;row<7;row++){
	    	x =GPIO_ReadPin(1,(row));
	    	for(k=0;k<1000;k++){}
	    	x =GPIO_ReadPin(1,(row));
	    	if (x==0){
	    	buttonState=1;
	    	key=arr[row-3][column];
	    	KeypadCallouts_KeyPressNotificaton();
	    	}
	     }
	     }
	  }
	}

unsigned char Keypad_GetKey(){
	if(buttonState==1){
		buttonState =0;
		return key;
	}
	else
	{
		return -1;
	}
}

