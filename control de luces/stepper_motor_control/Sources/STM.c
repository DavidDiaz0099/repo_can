/*
 * STM.c
 *
 *  Created on: Dec 25, 2015
 *      Author: HP 240
 */

#include "MPC5606B.h"
/*Functions for use the timer*/



//Function for configuration timer
void Config_clock_STM() 
{
	STM.CNT.R = 0; 
	STM.CH[0].CMP.R = 0x9C401;                //Time of 1ms in channel 0
	STM.CH[0].CCR.B.CEN = 1;
	STM.CH[1].CMP.R = 0x186A001;             //Time of 400ms in channel 1
	STM.CH[1].CCR.B.CEN = 1;
	STM.CH[2].CMP.R = 0x1E84801;           //Time of 500ms in channel 2
	STM.CH[2].CCR.B.CEN = 1;
	STM.CH[3].CMP.R = 0x1E84801;         //Time of 5s in channel 3
	STM.CH[3].CCR.B.CEN = 1;
	STM.CR.B.FRZ = 0;
	STM.CR.B.CPS = 0;
	STM.CR.B.TEN = 1;	
}

