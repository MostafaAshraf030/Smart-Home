#include "../Services/FreeRTOS.h"
#include "../Services/task.h"
#include "../Services/queue.h"
#include "../Services/semphr.h"

#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"

#include "../MCAL/MGPIO/MGPIO_Interface.h"
#include "../MCAL/MRCC/MRCC_Interface.h"
#include "../MCAL/MUSART/MUSART_Interface.h"

#include "../HAL/HBUTTON/HButton.h"
#include "../HAL/HBUZZER/HBuzzer.h"
#include "../HAL/HLCD/HLCD_Interface.h"
#include "../HAL/HLED/HLED.h"
#include "../HAL/HSWITCH/HSwitch.h"
#include "../HAL/HTEMP/HTEMP_Interface.h"

#include "APP.h"

SemaphoreHandle_t xButtonSemaphore;
SemaphoreHandle_t xLedSemaphore;
SemaphoreHandle_t xTemperatureMutex;
SemaphoreHandle_t xDoorSensorStateMutex;

u32 ledState = 0;  // 0: OFF, 1: ON
u32 doorState = 0; // 0: CLOSED, 1: OPEN
f32 temperature = 0.0;


void vTaskButton(void *pvParameters) {

	HButton_VidInt();
    while (1) {
    	//xSemaphoreTake(xButtonSemaphore, portMAX_DELAY);
        // Handle button press and toggle LED state
        if (MGPIO_u8GetPinValue(MGPIOA_PORT, MGPIO_PIN2) == MGPIO_HIGH_VALUE) {
            xSemaphoreGive(xButtonSemaphore);
        }

        // Delay for 50 ms
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}


void vTaskAlarmBuzzer(void *pvParameters) {
	HBuzzer_VidInt();
    while (1) {
        // Activate/deactivate the alarm buzzer based on the door sensor state
        if (doorState == 1) {
        	MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN3,MGPIO_HIGH_VALUE) ;
        } else {
        	MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN3,MGPIO_LOW_VALUE) ;
        }

        // Delay for 100 ms
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


void vTaskLCD(void *pvParameters) {
    while (1) {

    	u8 arrLED [];
    	u8 arrDoor [];
    	u8 arrTemp [];

    	//Display the state of the LED (ON or OFF) on one line of the LCD.
    	LCD_voidSetPosition(0,1) ;

    	if (ledState == 0){
    		//LCD_enuSendCommand(0x01);
    		arrLED[] = "LED OFF";
    		LCD_voidSendString(arrLED);
    	}
    	else{
    		//LCD_enuSendCommand(0x01);
    		arrLED[] = "LED ON";
    		LCD_voidSendString(arrLED);
    	}

    	//Display the state of the door sensor (OPEN or CLOSED) on another line of the LCD.
    	LCD_voidSetPosition(1,1) ;

    	if (doorState == 0){
    		//LCD_enuSendCommand(0x01);
    		arrDoor[] = "Door CLOSED";
    		LCD_voidSendString(arrDoor);
    	}
    	else{
    		//LCD_enuSendCommand(0x01);
    		arrDoor[] = "Door OPEN";
    		LCD_voidSendString(arrDoor);
    	}

    	//Display the current temperature on a third line of the LCD.
    	LCD_voidSetPosition(0,9) ;

    	LCD_voidSendFloatNumber(temperature);

    	LCD_voidSetPosition(0,14) ;
    	u8 arrSym [] = "C" ;

        // Delay for 500 ms
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}


void vTaskLEDControl(void *pvParameters) {

	HLED_VidInt();

    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (1) {
        // Toggle the LED state
        xSemaphoreTake(xLedSemaphore, portMAX_DELAY);

		MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_HIGH_VALUE) ;
		vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));
		MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_LOW_VALUE) ;
		//MSTK_voidDelayMs (1000) ; //100,000 >> 1 sec

        ledState = MGPIO_u8GetPinValue(MGPIOA_PORT, MGPIO_PIN0);
        xSemaphoreGive(xLedSemaphore);

        // Delay for 1 second
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1000));
    }
}


void vTaskDoorSensor(void *pvParameters) {
	HSwitch_VidInt();
    while (1) {

   	    // Acquire the semaphore before updating the shared resource (DoorSensor)
        xSemaphoreTake(xDoorSensorStateMutex, portMAX_DELAY);

        // Read the door sensor state
        doorState = MGPIO_u8GetPinValue(MGPIOA_PORT, MGPIO_PIN1);

        // Release the semaphore to signal that the operation is complete
        xSemaphoreGive(xDoorSensorStateMutex);

        // Delay for 100 ms
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


void vTaskTemperature(void *pvParameters) {
    while (1) {

        // Read temperature from the sensor & Store the temperature in the global variable
    	temperature = ADC_to_Temperature();

    	 // Acquire the semaphore before updating the shared resource (temperature)
        xSemaphoreTake(xTemperatureMutex, portMAX_DELAY);

        // Release the semaphore to signal that the operation is complete
        xSemaphoreGive(xTemperatureMutex);

        // Delay for 2 seconds
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}


void ASystem_vodiUART (void){


	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF);
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF);

	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,MGPIO_ALTFN_7);
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,MGPIO_ALTFN_7);

	MUSART_voidEnable();
	//u8 dataToSend []  = {1,2,3,4,5} ;
	//	u8 dataLenght = (sizeof (dataToSend) / sizeof (dataToSend[0])) ;

	//	MUSART_voidSendData (dataToSend , dataLenght) ;

}


void vTaskUART(void *pvParameters) {
	ASystem_vodiUART();
	while (1) {

    	u8 dataString[50];

    	// Acquire mutexes to access shared resources
    	xSemaphoreTake(xLedSemaphore, portMAX_DELAY);
    	xSemaphoreTake(xDoorSensorStateMutex, portMAX_DELAY);
    	xSemaphoreTake(xTemperatureMutex, portMAX_DELAY);

    	MUSART_voidSendData(&dataString, 1);

    	// Release the mutexes
    	xSemaphoreGive(xLedSemaphore);
    	xSemaphoreGive(xDoorSensorStateMutex);
    	xSemaphoreGive(xTemperatureMutex);

        // Delay for 1 second
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
