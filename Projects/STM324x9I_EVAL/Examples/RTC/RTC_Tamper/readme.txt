/**
  @page RTC_Tamper RTC Tamper example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    RTC/RTC_Tamper/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RTC Tamper example.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
   @endverbatim

@par Example Description 

This example guides you through the different configuration steps by mean of HAL API 
to write/read data to/from RTC Backup data registers and demonstrate the Tamper 
detection feature using the RTC peripheral.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 180 MHz.

The RTC peripheral configuration is ensured by the HAL_RTC_Init() function.
This later is calling the HAL_RTC_MspInit()function which core is implementing
the configuration of the needed RTC resources according to the used hardware (CLOCK, 
PWR, RTC clock source and BackUp). You may update this function to change RTC configuration.

LSE oscillator clock is used as RTC clock source by default. LSE oscillator clock 
usually delivered by a 32.768 kHz quartz.
The user can use also LSI as RTC clock source. The user uncomment the adequate 
define on the main.h file. 

HAL_RTCEx_SetTamper_IT() function is then called to initialize the Tamper with 
interrupt mode.

The associated firmware performs the following:
1. It configures the Tamper pin to be falling edge, and enables the Tamper 
   interrupt.
2. It writes the data to all RTC Backup data registers, then check whether the 
   data were correctly written. If yes, LED2 turns ON, otherwise LED3 turns ON.
3. Applying a low level on the TAMPER1 pin (PC.13) by pressing Tamper push button,
   the RTC backup data registers are reset and the Tamper interrupt is generated 
   and LED1 turns ON. 
   The corresponding ISR then checks whether the RTC Backup data registers are cleared. 
   If yes LED4 Toggles, otherwise LED3 turns ON.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@note  Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select the RTC clock source; in this 
       case the Backup domain will be reset in order to modify the RTC Clock source, as consequence RTC  
       registers (including the backup registers) and RCC_BDCR register are set to their reset values.
       
@par Keywords

System, RTC, Tamper, Reset, LSE, LSI
       
@par Directory contents 

  - RTC/RTC_Tamper/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - RTC/RTC_Tamper/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - RTC/RTC_Tamper/Inc/main.h                  Main program header file  
  - RTC/RTC_Tamper/Src/stm32f4xx_it.c          Interrupt handlers handlers
  - RTC/RTC_Tamper/Src/main.c                  Main program
  - RTC/RTC_Tamper/Src/stm32f4xx_hal_msp.c     HAL MSP module
  - RTC/RTC_Tamper/Src/system_stm32f4xx.c      STM32F4xx system clock configuration file


@par Hardware and Software environment

  - This example runs on STM32F42xxx/STM32F43xxx devices.
    
  - This example has been tested with STM324x9I-EVAL RevB evaluation board and can be
    easily tailored to any other supported device and development board.    


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 