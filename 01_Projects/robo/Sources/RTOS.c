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

void RTOS_Run(void) {

  FRTOS1_vTaskStartScheduler();
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */
  if (FRTOS1_xTaskCreate(T1, (signed portCHAR *)"T1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */




