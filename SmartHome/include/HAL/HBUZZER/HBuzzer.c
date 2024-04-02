#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MGPIO/MGPIO_Interface.h"

#include "HBuzzer.h"

void HBuzzer_VidInt(void){

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN3,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN3,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN3,MGPIO_SPEED_LOW);

}
