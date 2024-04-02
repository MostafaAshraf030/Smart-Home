/********************************************/
/* Description : ADC                        */
/* Author      : Mostafa Ashraf        		*/
/* Date        : 9/9/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef   MADC_PRIVATE_H
#define   MADC_PRIVATE_H


typedef struct
{
    u32 ADC_SR;
    u32 ADC_CR1;
    u32 ADC_CR2;
    u32 ADC_SMPR1;
    u32 ADC_SMPR2;
	u32 ADC_JOFR1;
    u32 ADC_JOFR2;
    u32 ADC_JOFR3;
	u32 ADC_JOFR4;
    u32 ADC_HTR;
    u32 ADC_LTR;
	u32 ADC_SQR1;
    u32 ADC_SQR2;
    u32 ADC_SQR3;
	u32 ADC_JSQR;
    u32 ADC_JDR1;
    u32 ADC_JDR2;
	u32 ADC_JDR3;
    u32 ADC_JDR4;
    u32 ADC_DR;
    u32 ADC_CCR;


}ADC_t;




#define ADC1_Base_Address  0x40012000

#define ADC1 ((volatile ADC_t *) ADC1_Base_Address)
/*resolution */
#define TWELVE_BIT   0
#define ELEVEN_BIT	 1
#define EGHIT_BIT	 2
#define SIX_BIT		 3

/*sampling time */

#define CYCLE3   	 0
#define CYCLE15	     1
#define CYCLE28	     2
#define CYCLE56		 3
#define CYCLE84      4
#define CYCLE112	 5
#define CYCLE144	 6
#define CYCLE480	 7



#endif
