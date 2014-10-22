/*
 * KeyDebounce.h
 *
 *  Created on: 22.10.2014
 *      Author: Geiser
 */

#ifndef KEYDEBOUNCE_H_
#define KEYDEBOUNCE_H_

/*!
 * \brief Kicks the debouncing state machine.
 */
void KEYDBNC_Process(void);

/*!
 * \brief Driver initialization.
 */
void KEYDBNC_Init(void);

/*!
 * \brief Driver de-initialization.
 */
void KEYDBNC_Deinit(void);

#endif /* KEYDEBOUNCE_H_ */
