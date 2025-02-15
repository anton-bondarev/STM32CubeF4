/**
  ******************************************************************************
  * @file    TIM/TIM_7PWMOutput/Src/stm32f4xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */


/**
  * @brief TIM MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
  GPIO_InitTypeDef   GPIO_InitStruct;
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* TIMx Peripheral clock enable */
  __HAL_RCC_TIM1_CLK_ENABLE();
  
  /* Enable GPIO Channels Clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* Configure (PA.08, TIM1_CH1), (PB.13, TIM1_CH1N), (PA.09, TIM1_CH2),
               (PB.14, TIM1_CH2N), (PA.10, TIM1_CH3), (PB.15, TIM1_CH3N),
               (PA.11, TIM1_CH4) in push-pull, alternate function mode  */
  
  /* Common configuration for all channels */
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  
  /* GPIO TIM1_Channel1 configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* GPIO TIM1_Channel1N configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* GPIO TIM1_Channel2 configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* GPIO TIM1_Channel2N configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* GPIO TIM1_Channel3 configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_10;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* GPIO TIM1_Channel3N configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* GPIO TIM1_Channel4 configuration */
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
