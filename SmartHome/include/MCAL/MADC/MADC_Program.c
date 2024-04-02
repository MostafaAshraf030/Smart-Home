/********************************************/
/* Description : ADC 						*/
/* Author      : Mostafa Ashraf         	*/
/* Date        : 9/9/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../MRCC/MRCC_Interface.h"
#include"../MGPIO/MGPIO_Interface.h"

#include "MADC_Private.h"
#include "MADC_Config.h"
#include "MADC_Interface.h"


void ADC_Init(void) {

    // Enable the ADC peripheral clock
	MRCC_voidEnablePeripheralClock(APB2 ,MRCC_ADC1);

	//A port clock enable
	MGPIO_u8SetPinMode(MGPIOA_PORT, MGPIO_PIN4, MGPIO_MODE_ANALOG);

    // Configure the ADC for single conversion mode
    ADC1->ADC_CR1 = 0; // Reset CR1 register
    ADC1->ADC_CR2 = 0; // Reset CR2 register

	// Configure ADC for single conversion mode

    ADC1->ADC_CR2 &= ~(1U << 11); // Set CONT = 0 for single conversion
    ADC1->ADC_CR1 &= ~(0x3U << 24); // Clear RES bits
	ADC1->ADC_CR1 |= (RES << 24);
   #if channel_num<10
   ADC1->ADC_SMPR2 &=~ (0x7U << (channel_num*3));
	ADC1->ADC_SMPR2 |= (SAMPLE_CYC << (channel_num*3));
	#else
	ADC1->ADC_SMPR1 &=~ (0x7U <<  ((channel_num-10)*3));
	ADC1->ADC_SMPR1 |= (SAMPLE_CYC <<  ((channel_num-10)*3));
	#endif
	ADC1->ADC_CR2 |= 1U;
}

f32 ADC_ReadChannel(u32 channel) {
    // Configure the channel
    ADC1->ADC_SQR1= (channel & 0x1F);

    // Start a conversion
    ADC1-> ADC_CR2 |= (1 << 30); // Set the SWSTART bit
    // Wait for the conversion to complete
    while (!(ADC1->ADC_SR & (1 << 1))); // Check EOC bit in ADC_SR


    // Read and return the ADC conversion result
    return ADC1->ADC_DR;
}



