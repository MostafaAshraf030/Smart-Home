/********************************************/
/* Description : ADC                        */
/* Author      : Mostafa Ashraf             */
/* Date        : 9/9/2023                  */
/* Version     : 0.1V                       */
/********************************************/

#ifndef   MADC_INTERFACE_H
#define   MADC_INTERFACE_H

void ADC_Init(void);
f32 ADC_ReadChannel(u32 channel);

//f32 adc_read();
//void start_conversation();
//void adc_init();

#endif
