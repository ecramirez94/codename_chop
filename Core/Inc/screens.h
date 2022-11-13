/*
 * screens.h
 *
 *  Created on: Nov 12, 2022
 *      Author: carlos
 */

#ifndef SRC_SCREENS_H_
#define SRC_SCREENS_H_

#include <stdint.h>

//
//  Structure used to define screens
//
typedef struct {
    const uint8_t ScreenWidth;    /* Font width in pixels */
    uint8_t ScreenHeight;         /* Font height in pixels */
    const unsigned char* data;       /* Pointer to data font data array */
} ScreenDef;

//
//  Export screens
//
extern ScreenDef Logo;
extern ScreenDef Home_Screen;

/*
 * Function Declarations
 */
void Draw_Home_Screen(void);

#endif /* SRC_SCREENS_H_ */
