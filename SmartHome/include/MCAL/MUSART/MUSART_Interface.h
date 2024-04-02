/*
 * MUSART_Interface.h
 *
 *  Created on: Sep 4, 2022
 *      Author: Mostafa Ashraf
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

void MUSART_voidInit(void) ;

void MUSART_voidSendData(u8* copy_u8Data,u8 Copy_u8Len);

void MUSART_u8ReadData(u8* buffer, u8 length) ;

void MUSART_voidEnable(void) ;

void MUSART_voidDisable(void) ;

void MUSART_voidCallBack(void(*Fptr)(void)) ;


#endif /* MUSART_INTERFACE_H_ */
