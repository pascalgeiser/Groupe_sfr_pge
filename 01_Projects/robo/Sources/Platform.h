/*
 * Platform.h
 *
 *  Created on: 25.09.2014
 *      Author: Geiser
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "PE_Types.h" /* for common Processor Expert types used throughout the project, e.g. 'bool' */
#include "PE_Error.h" /* global error constants */
#include <stddef.h>   /* for NULL */

/* List of supported platforms. The PL_BOARD_IS_xxx is defined in the compiler command line settings.  */
#define PL_IS_FRDM   (defined(PL_IS_FRDM))
  /*!< Macro is defined through compiler option for the FRDM board */
#define PL_IS_ROBO  (defined(PL_IS_ROBO))
  /*!< Macro is defined through compiler option for the Robot board */

#define PL_HAS_LED  (1)
  /*!< Set to 1 to enable LED support, 0 otherwise */
#define PL_HAS_EVENTS (1)
  /*!< Set to 1 to enable event support, 0 otherwise */
#define PL_HAS_TIMER (1)
  /*!< Set to 1 to enable event support, 0 otherwise */
#define PL_HAS_KEYS           (1)
  /*!< Set to 1 to enable key/push button support, 0 otherwise */
#define PL_HAS_KBI            (1)
  /*!< Set to 1 to enable key interrupt support, 0 otherwise */
#define PL_HAS_RESET_KEY      (0 && PL_IS_FRDM && PL_HAS_KEYS)
  /*!< Set to 1 to use reset switch on FRDM as button, 0 otherwise */
#define PL_HAS_JOYSTICK       (0 && PL_IS_FRDM && PL_HAS_KEYS)
  /*!< Set to 1 to enable joystick shield support, 0 otherwise */
#define PL_HAS_MEALY      	  (0 && PL_NOF_LEDS>=1 && PL_NOF_KEYS>=1)
  /*!< Set to 1 to enable Mealy FSM, 0 otherwise */
#define PL_HAS_SHELL          (1 && (PL_IS_FRDM || (PL_IS_ROBO && PL_HAS_USB_CDC)))
  /*!< Set to 1 to enable shell, 0 otherwise */
#define PL_HAS_DEBOUNCE       (1)//(1 && PL_HAS_KEYS)
  /*!< Set to 1 to enable triggers, 0 otherwise */
#define PL_HAS_TRIGGER	(1)
  /*!< Set to 1 to enable triggers, 0 otherwise */
#define PL_HAS_BUZZER	(1)
  /*!< Set to 1 to enable triggers, 0 otherwise */
#define PL_HAS_RTOS	(1)
  /*!< Set to 1 to enable triggers, 0 otherwise */
#define PL_HAS_USB_CDC        (0)
  /*!< Set to 1 if using USB CDC, 0 otherwise */
#define PL_HAS_BLUETOOTH      (0 && PL_IS_ROBO)
  /*!< Set to 1 if using Bluetooth, 0 otherwise */
#define PL_HAS_SHELL_QUEUE    (1 && PL_HAS_SHELL)
  /*!< Set to 1 if using shell queues, 0 otherwise */
#define PL_HAS_SEMAPHORE      (1)
  /*!< Set to 1 if using semaphore labs, 0 otherwise */
#define PL_HAS_LINE_SENSOR    (1)
  /*!< Set to 1 if using line sensor, 0 otherwise */
#define PL_HAS_REFLECTANCE    (1 && PL_HAS_LINE_SENSOR)
  /*!< Set to 1 if using reflectance sensor array, 0 otherwise */
#define PL_HAS_MOTOR          (1 && PL_IS_ROBO)
  /*!< Set to 1 if using motors, 0 otherwise */
#define PL_HAS_CONFIG_NVM     (0)
  /*!< Set to 1 if using NVMC, 0 otherwise */
#define PL_HAS_MPC4728        (0 && PL_IS_ROBO)
  /*!< Set to 1 if using MPC4728, 0 otherwise */
#define PL_HAS_QUAD_CALIBRATION (0 && PL_HAS_MPC4728)
  /*!< Set to 1 if using quadrature calibration, 0 otherwise */
#define PL_HAS_QUADRATURE     (0 && PL_IS_ROBO)
  /*!< Set to 1 if using quadrature counters, 0 otherwise */

/* additional hardware configuration */

/* if keys are using interrupts or are polled */
#if PL_IS_FRDM
  #define PL_KEY_POLLED_KEY1    (0)
  //#define PL_KEY_POLLED_KEY2    (0)
  //#define PL_KEY_POLLED_KEY3    (0)
  //#define PL_KEY_POLLED_KEY4    (0)
  //#define PL_KEY_POLLED_KEY5    (1)
  //#define PL_KEY_POLLED_KEY6    (1)
  //#define PL_KEY_POLLED_KEY7    (0)
#endif


#if PL_IS_FRDM
  #if PL_HAS_JOYSTICK
    #define PL_NOF_LEDS       (2)
      /*!< FRDM board has 2 LEDs (red is used by joystick shield) */
    #define PL_NOF_KEYS       (7)
       /*!< FRDM board has no keys without joystick shield */
  #else
    #define PL_NOF_LEDS       (3)
	#define PL_NOF_LEDS_ROBO	(1) //PGE

       /*!< FRDM board has up to 3 LEDs (RGB) */
#if PL_HAS_RESET_KEY
    #define PL_NOF_KEYS       (1)
       /*!< FRDM board with using the reset button */
#else
    #define PL_NOF_KEYS       (1)
       /*!< FRDM board has no keys without joystick shield */
#endif
  #endif
#else
  #error "unknown configuration?"
#endif

/*!
 * \brief Platform initialization
 */
void PL_Init(void);

/*!
 * \brief Platform de-initialization
 */
void PL_Deinit(void);

#endif /* PLATFORM_H_ */
