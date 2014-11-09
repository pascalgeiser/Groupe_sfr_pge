/*
 * RTOS.c
 *
 *  Created on: 26.10.2014
 *      Author: Geiser
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"

static portTASK_FUNCTION(T1, pvParameters) {
  for(;;) {
    LED1_Neg();
    FRTOS1_vTaskDelay(50/portTICK_RATE_MS);
  }
}

static portTASK_FUNCTION(T2, pvParameters) {
  for(;;) {
	  LED_U1_Neg();
    FRTOS1_vTaskDelay(50/portTICK_RATE_MS);
  }
}

void RTOS_Run(void) {

 //  if (FRTOS1_xTaskCreate(T1, (signed portCHAR *)"T1", configMINIMAL_STACK_SIZE+150, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
 //    for(;;){} /* error */
//   }

   FRTOS1_vTaskStartScheduler();
}

void RTOS_Init(void) {
	/* Add task LED blinking on ROBO*/
		if (FRTOS1_xTaskCreate(T2, (signed portCHAR *)"T2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
		 for(;;){} /* error */
	  }
  /*! \todo Add tasks here */
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */




