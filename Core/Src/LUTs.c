/*
 *  LUTs.c
 *
 *  Lookup tables and functions to access their data.
 *
 *  Created on: Nov 28, 2022
 *      Author: carlos
 */
#include <LUTs.h>

/*
 *	Look-up tables for ADC count to temperature conversion.
 *	ADC values in between values in LUT will use linear interpolation
 *	to determine approximate temperature.
 *
 *	Table organization:
 *	- Even indices (incl. zero): ADC Count
 *	- Odd indices: Temperature
 *
 */
#define HRT_LUT_SIZE 78
static unsigned int HeatedRoller_Thermistor[HRT_LUT_SIZE] = {
	/* NTC Thermistor */
	/* ADCval | Temperature (F) */
		0,		320, // Upper temperature boundary
		981,	310,
		1002,	305,
		1022,	300,
		1055,	295,
		1095,	290,
		1140,	285,
		1196,	280,
		1250,	275,
		1304,	270,
		1374,	265,
		1433,	260,
		1491,	255,
		1551,	250,
		1622,	245,
		1687,	240,
		1765,	235,
		1835,	230,
		1907,	225,
		1979,	220,
		2055,	215,
		2132,	210,
		2208,	205,
		2278,	200,
		2437,	190,
		2589,	180,
		2758,	170,
		2892,	160,
		3025,	150,
		3165,	140,
		3272,	130,
		3400,	120,
		3469,	110,
		3571,	100,
		3639,	90,
		3696,	80,
		3758,	70,
		3776,	60,
		4095,	0	// Lower temperature boundary
};
LookUpTable Thermistor = {HRT_LUT_SIZE, HeatedRoller_Thermistor};


int convertADCToTemperature(int16_t adc_val, LookUpTable table, uint8_t unit)
{
	/*
	 * Steps:
	 * 1. Scan through LUT to find which LUT ADC values the ADC value being
	 * converted is in between.
	 * 2. Interpolate to convert ADC value to temperature
	 * 3. Convert units if necessary
	 *
	 *
	 * Linear Interpolation formula:
	 *
	 * t = y1 + (x - x1)(y2 - y1) / (x2 - x1)
	 * where:
	 *   x1 and y1 are the first coordinates (lower ADC/temperature pair)
	 *   x2 and y2 are the second coordinates (upper ADC/temperature pair)
	 *	 x is the point to perform the interpolation (ADC value)
	 *	 t is the interpolated value (temperature)
	 */
	uint16_t x1, y1, x2, y2;
	int t;

	/* 1. Scan LUT */
	for (uint16_t i=0; i<=(table.LUT_size - 1); i+=2)
	{
		// Quick check to make sure to not exceed array boundaries
		if (i > (table.LUT_size - 3))
			break;
		else if (adc_val >= table.LUT[i] && adc_val <= table.LUT[i+2])
		{
			x1 = table.LUT[i];
			y1 = table.LUT[i+1];

			x2 = table.LUT[i+2];
			y2 = table.LUT[i+3];
			break;
		}
	}

	/* 2. Interpolate */
	t = y1 + ((adc_val - x1) * (y2 - y1)) / (x2 - x1);

	/* 3. Convert units */
	if (unit == CELCIUS)
		return 0.55555 * (t - 32);
	else // Fahrenheit
		return t;
}
