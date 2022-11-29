/*
 * thermLUT.h
 *
 *  Created on: Nov 28, 2022
 *      Author: carlos
 */

#ifndef INC_LUTS_H_
#define INC_LUTS_H_

#include <stdint.h>
#include "constants.h"

typedef struct {
    uint8_t LUT_size;
    const unsigned int* LUT; /* Pointer to LUT */
} LookUpTable;

/* Export Lookup Table(s) */
extern LookUpTable Thermistor;

/* Function Declarations */
int convertADCToTemperature(int16_t adc_val, LookUpTable table, uint8_t unit);


#endif /* INC_LUTS_H_ */
