/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include"adc.h"
#include"i2c_lcd.h"
#include"i2c.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	uint16_t value;
	char str[100];
	SystemInit();
	ADCInit();
	Lcd_Init();
	while(1)
	{
		value=ADC_On();
        sprintf(str,"ADC = %u",value);
        Lcd_Puts(LCD_LINE1, str);
        DelayMs(1000);
	}
	return 0;
}
