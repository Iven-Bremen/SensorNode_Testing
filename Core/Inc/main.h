/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EX1GP2_Pin GPIO_PIN_2
#define EX1GP2_GPIO_Port GPIOE
#define EX1GP3_Pin GPIO_PIN_3
#define EX1GP3_GPIO_Port GPIOE
#define EX1GP4_Pin GPIO_PIN_4
#define EX1GP4_GPIO_Port GPIOE
#define EX1GP5_Pin GPIO_PIN_5
#define EX1GP5_GPIO_Port GPIOE
#define EX1GP6_Pin GPIO_PIN_6
#define EX1GP6_GPIO_Port GPIOE
#define EX1GP7_Pin GPIO_PIN_13
#define EX1GP7_GPIO_Port GPIOC
#define LSADC10_Pin GPIO_PIN_0
#define LSADC10_GPIO_Port GPIOC
#define LSADC11_Pin GPIO_PIN_1
#define LSADC11_GPIO_Port GPIOC
#define LSADC12_Pin GPIO_PIN_2
#define LSADC12_GPIO_Port GPIOC
#define LSADC13_Pin GPIO_PIN_3
#define LSADC13_GPIO_Port GPIOC
#define EXADC0_Pin GPIO_PIN_0
#define EXADC0_GPIO_Port GPIOA
#define EXADC1_Pin GPIO_PIN_1
#define EXADC1_GPIO_Port GPIOA
#define EXADC2_Pin GPIO_PIN_2
#define EXADC2_GPIO_Port GPIOA
#define EXADC3_Pin GPIO_PIN_3
#define EXADC3_GPIO_Port GPIOA
#define EXDAC4_Pin GPIO_PIN_4
#define EXDAC4_GPIO_Port GPIOA
#define EXDAC5_Pin GPIO_PIN_5
#define EXDAC5_GPIO_Port GPIOA
#define EXADC6_Pin GPIO_PIN_6
#define EXADC6_GPIO_Port GPIOA
#define EXADC7_Pin GPIO_PIN_7
#define EXADC7_GPIO_Port GPIOA
#define VDADC14_Pin GPIO_PIN_4
#define VDADC14_GPIO_Port GPIOC
#define VDADC15_Pin GPIO_PIN_5
#define VDADC15_GPIO_Port GPIOC
#define HSCADC8_Pin GPIO_PIN_0
#define HSCADC8_GPIO_Port GPIOB
#define HSCADC9_Pin GPIO_PIN_1
#define HSCADC9_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define Gelb_Pin GPIO_PIN_7
#define Gelb_GPIO_Port GPIOE
#define HS1_Pin GPIO_PIN_8
#define HS1_GPIO_Port GPIOE
#define LS1_Pin GPIO_PIN_9
#define LS1_GPIO_Port GPIOE
#define HS2_Pin GPIO_PIN_10
#define HS2_GPIO_Port GPIOE
#define LS2_Pin GPIO_PIN_11
#define LS2_GPIO_Port GPIOE
#define RGB_B_Pin GPIO_PIN_12
#define RGB_B_GPIO_Port GPIOE
#define LS3_Pin GPIO_PIN_13
#define LS3_GPIO_Port GPIOE
#define LS4_Pin GPIO_PIN_14
#define LS4_GPIO_Port GPIOE
#define ROT_Pin GPIO_PIN_15
#define ROT_GPIO_Port GPIOE
#define RGB_R_Pin GPIO_PIN_11
#define RGB_R_GPIO_Port GPIOB
#define EX2GP7_Pin GPIO_PIN_11
#define EX2GP7_GPIO_Port GPIOD
#define EX2GP6_Pin GPIO_PIN_12
#define EX2GP6_GPIO_Port GPIOD
#define EX2GP5_Pin GPIO_PIN_13
#define EX2GP5_GPIO_Port GPIOD
#define EX2GP4_Pin GPIO_PIN_14
#define EX2GP4_GPIO_Port GPIOD
#define EX2GP3_Pin GPIO_PIN_15
#define EX2GP3_GPIO_Port GPIOD
#define EX2GP2_Pin GPIO_PIN_6
#define EX2GP2_GPIO_Port GPIOC
#define EX2GP1_Pin GPIO_PIN_7
#define EX2GP1_GPIO_Port GPIOC
#define EX2GP0_Pin GPIO_PIN_8
#define EX2GP0_GPIO_Port GPIOC
#define BTN_U_Pin GPIO_PIN_4
#define BTN_U_GPIO_Port GPIOD
#define RGB_G_Pin GPIO_PIN_4
#define RGB_G_GPIO_Port GPIOB
#define EX1GP0_Pin GPIO_PIN_0
#define EX1GP0_GPIO_Port GPIOE
#define EX1GP1_Pin GPIO_PIN_1
#define EX1GP1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
