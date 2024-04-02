#include "Services/FreeRTOS.h"
#include "Services/task.h"
#include "Services/queue.h"
#include "Services/semphr.h"

#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"

#include "MCAL/MGPIO/MGPIO_Interface.h"
#include "MCAL/MRCC/MRCC_Interface.h"
#include "MCAL/MUSART/MUSART_Interface.h"
#include "MCAL/MADC/MADC_Interface.h"

#include "APP/APP.h"


#define STACK_SIZE 100


int main(void) {
    // Initialize the hardware here (e.g., system clock, GPIOs, ADC, UART, LCD, etc.)
	MRCC_voidInitSystemClk();
	ADC_Init();
	MUSART_voidInit();
	LCD_enuInit();

	MRCC_voidEnablePeripheralClock (AHB1,MRCC_GPIOA);
	MRCC_voidEnablePeripheralClock (AHB1,MRCC_GPIOB);
	MRCC_voidEnablePeripheralClock (APB2,MRCC_USART1);

	// Initialize FreeRTOS objects
    xLedSemaphore = xSemaphoreCreateBinary();
    xButtonSemaphore = xSemaphoreCreateBinary();
    xTemperatureMutex = xSemaphoreCreateMutex();

    // Create tasks
    xTaskCreate(vTaskLEDControl, "LEDControl", STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(vTaskDoorSensor, "DoorSensor", STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(vTaskLCD, "LCD", STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTaskUART, "UART", STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vTaskButton, "Button", STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(vTaskTemperature, "Temperature", STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(vTaskAlarmBuzzer, "AlarmBuzzer", STACK_SIZE, NULL, 4, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    while (1) {
    }
}
