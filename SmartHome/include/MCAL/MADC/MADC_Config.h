/********************************************/
/* Description : ADC 						*/
/* Author      : Mostafa Ashraf       		*/
/* Date        : 9/9/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef  MADC_CONFIG_H
#define  MADC_CONFIG_H


/*resolution Options
1-TWELVE_BIT 2-ELEVEN_BIT 3-EGHIT_BIT 4-SIX_BIT */
#define RES  TWELVE_BIT

/*Sampling time options
1-CYCLE3  2-CYCLE15 3-CYCLE28
4-CYCLE56 5-CYCLE84 6-CYCLE112
7-CYCLE144 8-CYCLE480
*/
#define SAMPLE_CYC  CYCLE15

/*number of channel between 0 and 18*/
#define channel_num 0

#endif
