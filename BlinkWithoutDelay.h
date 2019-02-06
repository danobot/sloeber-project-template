/*
 * blink.h
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef BLINK_H_
#define BLINK_H_
#include "Arduino.h"
#include "gdb.h"
#define INTERVAL 500 //The blinking interval
//void RAMFUNC setup();
//void RAMFUNC loop();
uint8_t RAMFUNC calcLedState(uint32_t currentMillis, uint8_t ledState);


#endif /* BLINK_H_ */
