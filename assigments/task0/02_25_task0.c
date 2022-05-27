#include "stm32f4xx_hal.h"

void LED(void);
void BUTTON(void);

int main(void)
{
LED();
BUTTON(); 
GPIO_PinState mode; 
   while(1)
   {	
mode = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0); 
    if(mode)
	{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	}
    else
       {
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_2, GPIO_PIN_RESET);
       }
   }
}
void LED(void)
{
	 __HAL_RCC_GPIOB_CLK_ENABLE(); 
	GPIO_InitTypeDef ledpin; 
	ledpin.Mode = GPIO_MODE_OUTPUT_PP; 
	ledpin.Pin = GPIO_PIN_2; 
	HAL_GPIO_Init(GPIOB, &ledpin);
}
void BUTTON(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); 
	GPIO_InitTypeDef PushButton;  
	PushButton.Mode = GPIO_MODE_INPUT; 
	PushButton.Pin = GPIO_PIN_0;  
	PushButton.Pull = GPIO_PULLDOWN; 
	HAL_GPIO_Init(GPIOA, &PushButton); 
}
