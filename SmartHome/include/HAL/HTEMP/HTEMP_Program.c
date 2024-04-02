#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

#include "../../MCAL/MADC/MADC_Interface.h"

#include "HTEMP_Config.h"
#include "HTEMP_Interface.h"

u16 adcValue = 0;

f32 ADC_to_Temperature() {




	adcValue = ADC_ReadChannel(0);

    // and LM35 sensitivity is 10 mV/°C
    // f32 voltage = (adcValue / (STEPS*1.0)) * Vref; // Convert ADC reading to voltage

	// f32 temperature = (voltage - 0.5) * 100.0; // Convert voltage to temperature in Celsius

	f32 output_temp=((f32) adcValue /STEPS) * Vref;

	output_temp = output_temp/0.01;

	return output_temp;
}
