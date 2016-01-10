/*
 * diezkm.h
 *
 *  Created on: Dec 26, 2015
 *      Author: HP 240
 */

#ifndef OPTO_H_
#define OPTO_H_


/******** TELLTALES  ********/

#define CHEST               1
#define ENGINE_FAULT        2
#define DOOR_STATUS         3
#define TRUNK_STATUS        4
#define TEMP                5
#define HIGH_BEAMS_STATUS   6
#define OIL                 7


/****** VELOCIMETER ******/

#define NINETY_KM                   0
#define EIGHTY_KM                   1
#define SEVENTY_KM                  2
#define SEVENTY_FIVE_KM             3
#define ONE_HUNDRED_AND_THIRTY_KM   4
#define hundred_sixty_km            5


/******** CONDITIONS ********/

#define DOOR_STATUS_CLOSED  0
#define DOOR_STATUS_OPEN    1
#define ENGINE_FAULT_OFF    2
#define ENGINE_FAULT_ON     3
#define CHEST_CLOSED        4
#define CHEST_OPEN          5
#define TRUNK_CLOSED        6
#define TRUNK_OPEN          7
#define TEMP_LOW            8
#define TEMP_HIGH           9
#define HIGH_BEAMS_OFF      10
#define HIGH_BEAMS_ON       11
#define HIGH_OIL            12
#define LOW_OIL             13
#define TURN_OFF            0
#define TURN_ON             1
#define Pin_Disabled        0x0100
#define OFF                 0
#define ON                  1


#define NINETY              14
#define EIGHTY              13
#define SEVENTY             11
#define SEVENTY_FIVE        12



extern void opto();
extern void diez_pasos();
extern void veinte_pasos();
extern void delay_for();

#endif /* DIEZKM_H_ */
