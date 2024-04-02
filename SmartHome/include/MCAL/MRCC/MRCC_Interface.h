/***********************************************************************/
/*Auther           : Mostafa Ashraf                                    */
/*Version          : V0.0.0                                            */
/*Data             : 15 Aug 2023                                       */
/*Description      : MRCC_Interface.h --> Function Prototypes          */
/*Module Features  :                                                   */
/*        01- MRCC_voidEnablePeripheralClock                           */
/*        02- MRCC_voidDisablePeripheralClock                          */
/*        03- MRCC_voidInitSystemClk                                   */
/***********************************************************************/

#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H


typedef enum
{
	AHB1 = 0 ,
	AHB2     ,
	APB1     ,
	APB2
}MRCC_Bus_t;

/*******************************************************************************************************/
/*                                      01- MRCC_voidEnablePeripheralClock                               */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input -> Bus Peripheral, Peripheral Number                                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidEnablePeripheralClock (MRCC_Bus_t Copy_uddtPeripheralBus, u32 Copy_u32PeripheralNumber);


/*******************************************************************************************************/
/*                                      01- MRCC_voidDisablePeripheralClock                               */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input -> Bus Peripheral, Peripheral Number                                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidDisablePeripheralClock (MRCC_Bus_t Copy_uddtPeripheralBus, u32 Copy_u32PeripheralNumber);

/*******************************************************************************************************/
/*                                      01- MRCC_voidInitSystemClk                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->                                                                          */
/* 2- Function Input -> 				                                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidInitSystemClk (void);


/********************* Peripherals Numbers In AHB1 ***********/
/***********************************************************/

#define MRCC_GPIOA	0UL
#define MRCC_GPIOB	1UL
#define MRCC_GPIOC	2UL
#define MRCC_GPIOD	3UL
#define MRCC_GPIOE	4UL
#define MRCC_GPIOH	7UL
#define MRCC_CRC	12UL
#define MRCC_DMA1	21UL
#define MRCC_DMA2	22UL
#define MRCC_SYS_CFG 14UL

#define MRCC_PERIPHERAL_EN_SPI1 12UL

/********************* Peripherals Numbers In APB1 ***********/
/***********************************************************/
#define MRCC_PWR    28UL
#define MRCC_I2C3   23UL
#define MRCC_I2C2   22UL
#define MRCC_I2C1   21UL
#define MRCC_USART2 17UL
#define MRCC_SPI3   15UL
#define MRCC_SPI2   14UL
#define MRCC_WWDG   11UL
#define MRCC_TIM5   3UL
#define MRCC_TIM4   2UL
#define MRCC_TIM3   1UL
#define MRCC_TIM2   0UL


/********************* Peripherals Numbers In APB2 ***********/
/***********************************************************/
#define MRCC_TIM11  18UL
#define MRCC_TIM10  17UL
#define MRCC_TIM9   16UL
#define MRCC_SYSCFG 14UL
#define MRCC_SPI4   13UL
#define MRCC_SPI1   12UL
#define MRCC_SDIO   11UL
#define MRCC_ADC1   8UL
#define MRCC_USART6 5UL
#define MRCC_USART1 4UL
#define MRCC_TIM1   0UL

#define MRCC_USART1 4UL

#endif

