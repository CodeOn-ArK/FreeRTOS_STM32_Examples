/**
  ******************************************************************************
  * @file    main.c
  * @author  CodeOn-ArK
  * @version V1.0
  * @date    June_2021
  * @brief   Testing Template
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
			

int main(void)
{
	GPIO_InitTypeDef GPIOHandle;
	uint8_t OUT = 0;

	GPIOHandle.GPIO_Mode = GPIO_Mode_OUT;
	GPIOHandle.GPIO_OType = GPIO_OType_PP;
	GPIOHandle.GPIO_Pin = GPIO_Pin_5;
	GPIOHandle.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIOHandle.GPIO_Speed = GPIO_Speed_2MHz;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &GPIOHandle);

	for(;;)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, !OUT);
		for(uint32_t i=0; i<300000; i++);
		OUT = !OUT;
	}
}
