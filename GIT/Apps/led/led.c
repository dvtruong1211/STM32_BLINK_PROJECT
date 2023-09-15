/**
 ******************************************************************************
 * @file    led.c
 * @author  truongdv
 * @version 1.0
 * @date
 * @brief
 * @history
 ******************************************************************************/


/*******************************************************************************
 * Include
 ******************************************************************************/
#include "led.h"
#include "stdbool.h"



/*******************************************************************************
 * Definitions
 ******************************************************************************/


 /*******************************************************************************
 * Variables
 ******************************************************************************/
GPIO_TypeDef *port[LED_NUM_MAX] = {led1_GPIO_Port, led2_GPIO_Port, led3_GPIO_Port};
uint16_t pin[LED_NUM_MAX] = {led1_Pin, led2_Pin, led3_Pin};

uint32_t timeStartBlink[LED_NUM_MAX] = {0, 0, 0};
uint32_t ledState[LED_NUM_MAX] = {LED_ENABLE, LED_ENABLE, LED_ENABLE};
uint32_t led_timeON[LED_NUM_MAX] = {1000, 2000, 1500};
uint32_t led_timeOFF[LED_NUM_MAX] = {2000, 3000, 2500};

bool ledIsBlink[LED_NUM_MAX] = {true, true, true};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
void led_processBlink(void){
	for(int i = 0; i < LED_NUM_MAX; i++){
		if(ledIsBlink[i]){
			if(ledState[i] == LED_DISABLE && (uint32_t)(HAL_GetTick()- timeStartBlink[i]) > led_timeOFF[i]){
				LED_ON(port[i], pin[i]);
				timeStartBlink[i] = HAL_GetTick();
				ledState[i] = LED_ENABLE;
			}
			if(ledState[i] == LED_ENABLE && (uint32_t)(HAL_GetTick()- timeStartBlink[i]) > led_timeON[i]){
				LED_OFF(port[i], pin[i]);
				timeStartBlink[i] = HAL_GetTick();
				ledState[i] = LED_DISABLE;
			}
		}
		else
		{
			LED_OFF(port[i], pin[i]);
		}
	}
}

void led_setBlink(uint8_t led_index, bool isBlink){
	ledIsBlink[led_index] = isBlink;
}



/***********************************************/
