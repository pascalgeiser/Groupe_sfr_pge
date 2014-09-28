/*
 * Application.c
 *
 *  Created on: 27.09.2014
 *      Author: Geiser
 */

#include "Platform.h"
#include "Application.h"
#include "WAIT1.h"
#if PL_HAS_LED
  #include "LED.h"
#endif


void APP_Start(void) {
  PL_Init(); /* platform initialization */
  for(;;) {
    LED1_Neg();
    WAIT1_Waitms(1000);
    LED2_Neg();
    WAIT1_Waitms(1000);
    LED3_Neg();
    WAIT1_Waitms(1000);
  }
}




