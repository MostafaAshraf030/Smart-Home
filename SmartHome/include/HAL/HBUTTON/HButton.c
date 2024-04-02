#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MGPIO/MGPIO_Interface.h"

#include "HButton.h"


void HButton_VidInt(void){

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN2,MGPIO_MODE_INPUT);
	MGPIO_u8SetPullState(MGPIOA_PORT,MGPIO_PIN2,MGPIO_PULL_UP);

}
