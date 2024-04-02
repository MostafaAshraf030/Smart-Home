#ifndef APP_H
#define APP_H



// Function prototypes
void vTaskButton(void *pvParameters);
void vTaskAlarmBuzzer(void *pvParameters);
void vTaskLCD(void *pvParameters);
void vTaskLEDControl(void *pvParameters);
void vTaskDoorSensor(void *pvParameters);
void vTaskTemperature(void *pvParameters);
void ASystem_vodiUART (void);
void vTaskUART(void *pvParameters);


#endif
