/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define TOUCH_CS_Pin GPIO_PIN_8
#define TOUCH_CS_GPIO_Port GPIOI
#define FLASH_CS_Pin GPIO_PIN_6
#define FLASH_CS_GPIO_Port GPIOF
#define AT24C02_SCL_Pin GPIO_PIN_4
#define AT24C02_SCL_GPIO_Port GPIOH
#define AT24C02_SDA_Pin GPIO_PIN_5
#define AT24C02_SDA_GPIO_Port GPIOH
#define TOUCH_CLK_Pin GPIO_PIN_6
#define TOUCH_CLK_GPIO_Port GPIOH
#define TOUCH_PEN_Pin GPIO_PIN_7
#define TOUCH_PEN_GPIO_Port GPIOH
#define OLED_WR_Pin GPIO_PIN_8
#define OLED_WR_GPIO_Port GPIOH
#define TOUCH_MISO_Pin GPIO_PIN_3
#define TOUCH_MISO_GPIO_Port GPIOG
#define OLED_DATA3_Pin GPIO_PIN_6
#define OLED_DATA3_GPIO_Port GPIOC
#define OLED_DATA4_Pin GPIO_PIN_7
#define OLED_DATA4_GPIO_Port GPIOC
#define OLED_DATA5_Pin GPIO_PIN_8
#define OLED_DATA5_GPIO_Port GPIOC
#define OLED_DATA6_Pin GPIO_PIN_9
#define OLED_DATA6_GPIO_Port GPIOC
#define TOUCH_MOSI_Pin GPIO_PIN_3
#define TOUCH_MOSI_GPIO_Port GPIOI
#define OLED_RST_Pin GPIO_PIN_15
#define OLED_RST_GPIO_Port GPIOA
#define OLED_DATA7_Pin GPIO_PIN_11
#define OLED_DATA7_GPIO_Port GPIOC
#define OLED_DATA8_Pin GPIO_PIN_3
#define OLED_DATA8_GPIO_Port GPIOD
#define OLED_RD_Pin GPIO_PIN_3
#define OLED_RD_GPIO_Port GPIOB
#define OLED_RS_Pin GPIO_PIN_4
#define OLED_RS_GPIO_Port GPIOB
#define OLED_CS_Pin GPIO_PIN_7
#define OLED_CS_GPIO_Port GPIOB
#define OLED_DATA1_Pin GPIO_PIN_8
#define OLED_DATA1_GPIO_Port GPIOB
#define OLED_DATA2_Pin GPIO_PIN_9
#define OLED_DATA2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
