/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define epc901_VIDEO_P_Pin GPIO_PIN_0
#define epc901_VIDEO_P_GPIO_Port GPIOA
#define epc901_READ_Pin GPIO_PIN_1
#define epc901_READ_GPIO_Port GPIOA
#define epc_901_DATA_READY_Pin GPIO_PIN_2
#define epc_901_DATA_READY_GPIO_Port GPIOA
#define epc_901_CLR_PIX_Pin GPIO_PIN_3
#define epc_901_CLR_PIX_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define epc901_SHUTTER_Pin GPIO_PIN_4
#define epc901_SHUTTER_GPIO_Port GPIOC
#define Slide_potentiometer_Pin GPIO_PIN_5
#define Slide_potentiometer_GPIO_Port GPIOC
#define Heated_Roller_Temperature_Pin GPIO_PIN_0
#define Heated_Roller_Temperature_GPIO_Port GPIOB
#define Heated_Roller_Heater_ON_OFF_Pin GPIO_PIN_1
#define Heated_Roller_Heater_ON_OFF_GPIO_Port GPIOB
#define epc901_I2C2_SCL_Pin GPIO_PIN_10
#define epc901_I2C2_SCL_GPIO_Port GPIOB
#define UP_BUTTON_Pin GPIO_PIN_12
#define UP_BUTTON_GPIO_Port GPIOB
#define UP_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define DOWN_BUTTON_Pin GPIO_PIN_13
#define DOWN_BUTTON_GPIO_Port GPIOB
#define DOWN_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define LED_illuminator_PWM_Pin GPIO_PIN_14
#define LED_illuminator_PWM_GPIO_Port GPIOB
#define Heated_Roller_Motor_ON_OFF_Pin GPIO_PIN_15
#define Heated_Roller_Motor_ON_OFF_GPIO_Port GPIOB
#define BACK_BUTTON_Pin GPIO_PIN_6
#define BACK_BUTTON_GPIO_Port GPIOC
#define BACK_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define START_BUTTON_Pin GPIO_PIN_7
#define START_BUTTON_GPIO_Port GPIOC
#define START_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define SELECT_BUTTON_Pin GPIO_PIN_8
#define SELECT_BUTTON_GPIO_Port GPIOC
#define SELECT_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define RIGHT_BUTTON_Pin GPIO_PIN_9
#define RIGHT_BUTTON_GPIO_Port GPIOC
#define RIGHT_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define GRBL_CTRL_USART1_TX_Pin GPIO_PIN_9
#define GRBL_CTRL_USART1_TX_GPIO_Port GPIOA
#define GRBL_CTRL_USART1_RX_Pin GPIO_PIN_10
#define GRBL_CTRL_USART1_RX_GPIO_Port GPIOA
#define STOP_BUTTON_Pin GPIO_PIN_11
#define STOP_BUTTON_GPIO_Port GPIOA
#define STOP_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define epc901_I2C2_SDA_Pin GPIO_PIN_12
#define epc901_I2C2_SDA_GPIO_Port GPIOC
#define OLED_Display_I2C1_SCL_Pin GPIO_PIN_8
#define OLED_Display_I2C1_SCL_GPIO_Port GPIOB
#define OLED_Display_I2C1_SDA_Pin GPIO_PIN_9
#define OLED_Display_I2C1_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
