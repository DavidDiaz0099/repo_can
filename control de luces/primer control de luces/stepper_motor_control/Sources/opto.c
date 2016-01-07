/*
 * diezkm.c
 *
 *  Created on: Dec 26, 2015
 *      Author: HP 240
 */

#include "MPC5606B.h"
#include "opto.h"
#include "led.h"
#include "pb.h"

int operacion = 0;


//porta [0..15] portb [16...31] 
//SIU.GPDO[11].B.PDO = 1;	

void opto()//opto
{

	switch(operacion){
	
	
	case 0: 
		
			SIU.GPDO[0].B.PDO = 1;
		break;
		
	case 1: 
		
			SIU.GPDO[1].B.PDO = 1;
		break;
		
	}

}



void diez_pasos()
{


	
	
}


void veinte_pasos()
{
	
	
	  
}














