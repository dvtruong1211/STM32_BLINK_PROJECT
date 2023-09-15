/**
 ******************************************************************************
 * @file    led.h
 * @author  truongdv
 * @version 1.0
 * @date
 * @brief
 * @history
 ******************************************************************************/


#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
typedef enum{
	LED_NUM_1 = 0,
	LED_NUM_2,
	LED_NUM_3,
	LED_NUM_MAX
}led_number;

/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define LED_ENABLE 		1
#define LED_DISABLE		0

#define BLINK_ENABLE 	1
#define BLINK_DISABLE	0

#define LED_ON(port, pin)		HAL_GPIO_WritePin(port, pin, LED_ENABLE)
#define LED_OFF(port, pin)		HAL_GPIO_WritePin(port, pin, LED_DISABLE)

/* Exported functions ------------------------------------------------------- */
void led_processBlink(void);


#endif /* __HEADER_FILE_H */
