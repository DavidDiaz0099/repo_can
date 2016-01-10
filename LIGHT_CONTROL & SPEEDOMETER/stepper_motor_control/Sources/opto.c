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



//porta [0..15] portb [16...31] 
//SIU.GPDO[11].B.PDO = 1;	

void opto()//opto
{
    int Indication =  HIGH_BEAMS_ON;
	int operacion = Indication;
	
	switch(operacion){
	
	case DOOR_STATUS_CLOSED: 
		
		SIU.GPDO[DOOR_STATUS].B.PDO = TURN_OFF;
			
		break;
		
	case DOOR_STATUS_OPEN: 
		
		SIU.GPDO[DOOR_STATUS].B.PDO = TURN_ON;
			
		break;
		
	case ENGINE_FAULT_OFF: 
			
		SIU.GPDO[ENGINE_FAULT].B.PDO = TURN_OFF;
				
		break;
			
	case ENGINE_FAULT_ON: 
			
		SIU.GPDO[ENGINE_FAULT].B.PDO = TURN_ON;
				
		break;
		
	case CHEST_CLOSED: 
			
		SIU.GPDO[CHEST].B.PDO = TURN_OFF;
				
		break;
			
	case CHEST_OPEN: 
			
		SIU.GPDO[CHEST].B.PDO = TURN_ON;
				
		break;
			
			
	case TRUNK_CLOSED: 
			
		SIU.GPDO[TRUNK_STATUS].B.PDO = TURN_OFF;
				
		break;
			
			
	case TRUNK_OPEN: 
			
		SIU.GPDO[TRUNK_STATUS].B.PDO =  TURN_ON;
				
		break;
		
	case TEMP_LOW: 
				
		SIU.GPDO[TEMP].B.PDO =  TURN_OFF;
					
		break;
		
	case TEMP_HIGH: 
				
		SIU.GPDO[TEMP].B.PDO =  TURN_ON;
					
		break;
		
	case HIGH_BEAMS_OFF: 
				
		SIU.GPDO[HIGH_BEAMS_STATUS].B.PDO =  TURN_OFF;
					
		break;
		
	case HIGH_BEAMS_ON: 
				
		SIU.GPDO[HIGH_BEAMS_STATUS].B.PDO =  TURN_ON;
					
		break;
		
	case HIGH_OIL: 
					
		SIU.GPDO[OIL].B.PDO =  TURN_ON;
						
		break;
			
	case LOW_OIL: 
					
		SIU.GPDO[OIL].B.PDO =  TURN_OFF;
						
		break;
		
		
	}

}



void diez_pasos()
{
	
	int Veh_Speed = hundred_sixty_km;
	int Velocimeter = Veh_Speed;
		
	switch(Velocimeter){
		
	case NINETY_KM: 
		SIU.PCR[10].R = 0x0100;	
		SIU.PCR[11].R = 0x0100;	
		SIU.PCR[12].R = 0x0100;	
	    SIU.PCR[13].R = 0x0100;		
		SIU.GPDO[14].B.PDO =  TURN_ON;	
		break;

	case EIGHTY_KM: 
		SIU.PCR[10].R = 0x0100;	
		SIU.PCR[11].R = 0x0100;	
		SIU.PCR[12].R = 0x0100;	
		SIU.PCR[14].R = 0x0100;		
	    SIU.GPDO[13].B.PDO =  TURN_ON;			   
		break;
			
	case SEVENTY_KM: 
		SIU.PCR[10].R = 0x0100;	
		SIU.PCR[13].R = 0x0100;	
		SIU.PCR[12].R = 0x0100;	
		SIU.PCR[14].R = 0x0100;		
		SIU.GPDO[11].B.PDO =  TURN_ON;			   
		break;
		
	case SEVENTY_FIVE_KM: 
		SIU.PCR[10].R = 0x0100;	
		SIU.PCR[13].R = 0x0100;	
		SIU.PCR[11].R = 0x0100;	
		SIU.PCR[14].R = 0x0100;		
		SIU.GPDO[12].B.PDO =  TURN_ON;			   
		break;
		
	case ONE_HUNDRED_AND_THIRTY_KM: 
		SIU.PCR[12].R = 0x0100;	
		SIU.PCR[13].R = 0x0100;	
		SIU.PCR[11].R = 0x0100;	
		SIU.PCR[10].R = 0x0100;		
		SIU.GPDO[14].B.PDO =  TURN_ON;
		SIU.GPDO[15].B.PDO =  TURN_ON;
		break;

	case hundred_sixty_km: 
		SIU.PCR[12].R = 0x0100;	
		SIU.PCR[13].R = 0x0100;	
		SIU.PCR[11].R = 0x0100;	
		SIU.PCR[10].R = 0x0100;		
		SIU.GPDO[14].B.PDO =  TURN_ON;
		SIU.GPDO[15].B.PDO =  TURN_ON;
		delay_for(400000);
		SIU.PCR[14].R = 0x0100;	
		break;
	}
}


void veinte_pasos()
{
	
	
	  
}














