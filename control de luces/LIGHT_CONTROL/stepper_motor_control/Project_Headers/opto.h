/*
 * diezkm.h
 *
 *  Created on: Dec 26, 2015
 *      Author: HP 240
 */

#ifndef OPTO_H_
#define OPTO_H_

#define LEFT_DOOR_CLOSED    0
#define LEFT_DOOR_OPEN      1
#define ENGINE_FAULT_OFF    2
#define ENGINE_FAULT_ON     3
#define CHEST_CLOSED        4
#define CHEST_OPEN          5
#define RIGHT_DOOR_CLOSED   6
#define RIGHT_DOOR_OPEN     7
#define TEMP_LOW            8
#define TEMP_HIGH           9
#define HIGH_LIGHTS_OFF     10
#define HIGH_LIGHTS_ON      11
#define HIGH_OIL            12
#define LOW_OIL             13

extern void opto();
extern void diez_pasos();
extern void veinte_pasos();

#endif /* DIEZKM_H_ */
