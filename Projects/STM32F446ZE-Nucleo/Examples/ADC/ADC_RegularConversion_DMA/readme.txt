/**
  @page ADC_RegularConversion_DMA conversion using DMA for Data transfer

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    ADC/ADC_RegularConversion_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC RegularConversion DMA example.
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

How to use the ADC1 and DMA to transfer continuously converted data from 
ADC1 to memory.

The ADC1 is configured to convert continuously ADC_CHANNEL_10.

Each time an end of conversion occurs the DMA transfers, in circular mode, the
converted data from ADC1 DR register to the uhADCxConvertedValue variable.

In this example, the system clock is 180MHz, APB2 = 90MHz and ADC clock = APB2/4. 
Since ADC1 clock is 22.5 MHz and sampling time is set to 3 cycles, the conversion 
time to 12bit data is 12 cycles so the total conversion time is (12+3)/22.5= 0.66us(1.5Msps).

User can vary the ADC_CHANNEL_10 voltage by applying an input voltage on pin PC.00 (pin3 connector 9) 
(e.g. using function generator).

The converted value is monitored through debugger: uhADCxConvertedValue variable.

STM32 Nucleo board's LEDs can be used to monitor the transfer status:
  - LED1 is ON when the conversion is complete.
  - LED2 is ON when there is an error in ADC initialization, in ADC channel configuration 
    or during conversion process.

@par Keywords

Analog, ADC, Analog to Digital Converter, Regular Conversion, DMA, Continuous Conversion

@par Directory contents 

  - ADC/ADC_RegularConversion_DMA/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - ADC/ADC_RegularConversion_DMA/Inc/stm32f4xx_it.h          DMA interrupt handlers header file
  - ADC/ADC_RegularConversion_DMA/Inc/main.h                  Header for main.c module  
  - ADC/ADC_RegularConversion_DMA/Src/stm32f4xx_it.c          DMA interrupt handlers
  - ADC/ADC_RegularConversion_DMA/Src/main.c                  Main program
  - ADC/ADC_RegularConversion_DMA/Src/stm32f4xx_hal_msp.c     HAL MSP file 
  - ADC/ADC_RegularConversion_DMA/Src/system_stm32f4xx.c      STM32F4xx system source file

@par Hardware and Software environment 

  - This example runs on STM32F446xx devices.
  
  - This example has been tested with NUCLEO-446ZE Rev.B board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
