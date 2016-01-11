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
    int Indication   =  DOOR_STATUS_OPEN;
	int Ligh_Control =  Indication;

	
	
	switch(Ligh_Control){
	/*
	case DOOR_STATUS_CLOSED: 
		
		SIU.GPDO[DOOR_STATUS].B.PDO = TURN_OFF;
			
		break;
		*/
	case DOOR_STATUS_OPEN: 
		
		SIU.GPDO[DOOR_STATUS].B.PDO = TURN_ON;
			
		break;
	/*
	case CHEST_CLOSED: 
			
		SIU.GPDO[CHEST].B.PDO = TURN_OFF;
				
		break;
		*/	
	case CHEST_OPEN: 
			
		SIU.GPDO[CHEST].B.PDO = TURN_ON;
				
		break;
			
			/*
	case TRUNK_CLOSED: 
			
		SIU.GPDO[TRUNK_STATUS].B.PDO = TURN_OFF;
				
		break;
			
			*/
	case TRUNK_OPEN: 
			
		SIU.GPDO[TRUNK_STATUS].B.PDO =  TURN_ON;
				
		break;
		/*
	case TEMP_LOW: 
				
		SIU.GPDO[TEMP].B.PDO =  TURN_OFF;
					
		break;
		*/
	case TEMP_HIGH: 
				
		SIU.GPDO[TEMP].B.PDO =  TURN_ON;
					
		break;
		/*
	case HIGH_BEAMS_OFF: 
				
		SIU.GPDO[HIGH_BEAMS_STATUS].B.PDO =  TURN_OFF;
					
		break;
		*/
	case HIGH_BEAMS_ON: 
				
		SIU.GPDO[HIGH_BEAMS_STATUS].B.PDO =  TURN_ON;
					
		break;
		
	case HIGH_OIL: 
					
		SIU.GPDO[OIL].B.PDO =  TURN_ON;
						
		break;
			/*
	case LOW_OIL: 
					
		SIU.GPDO[OIL].B.PDO =  TURN_OFF;
						
		break;
		*/
	
		
		
	}

}



void diez_pasos()
{
	
	int Veh_Speed   = ONE_HUNDRED_AND_THIRTY_KM;
	int Operation   = Veh_Speed;
	int Battery     = ON;
	int Ign_Status  = ON;
	
	
	if(Battery == OFF){
		
		SIU.GPDO[0].B.PDO =  TURN_ON;
	}
	
	if(Ign_Status == ON){
			
			SIU.GPDO[ENGINE_FAULT].B.PDO =  TURN_ON;
		}
	
	
	if((Battery == OFF || Battery == ON) && ((Ign_Status == ON))){
	switch(Operation){
		
	case NINETY_KM: 
		SIU.PCR[10].R = Pin_Disabled ;	
		SIU.PCR[SEVENTY].R = Pin_Disabled ;	
		SIU.PCR[SEVENTY_FIVE].R = Pin_Disabled ;	
	    SIU.PCR[EIGHTY].R = Pin_Disabled ;		
		SIU.GPDO[NINETY].B.PDO =  TURN_ON;	
		break;

	case EIGHTY_KM: 
		SIU.PCR[10].R = Pin_Disabled ;	
		SIU.PCR[SEVENTY].R = Pin_Disabled;	
		SIU.PCR[SEVENTY_FIVE].R = Pin_Disabled ;	
		SIU.PCR[NINETY].R = Pin_Disabled ;		
	    SIU.GPDO[EIGHTY].B.PDO =  TURN_ON;			   
		break;
			
	case SEVENTY_KM: 
		SIU.PCR[10].R = Pin_Disabled ;	
		SIU.PCR[EIGHTY].R = Pin_Disabled ;	
		SIU.PCR[SEVENTY_FIVE].R = Pin_Disabled ;	
		SIU.PCR[NINETY].R = Pin_Disabled ;		
		SIU.GPDO[SEVENTY].B.PDO =  TURN_ON;			   
		break;
		
	case SEVENTY_FIVE_KM: 
		SIU.PCR[10].R = Pin_Disabled;	
		SIU.PCR[EIGHTY].R = Pin_Disabled;	
		SIU.PCR[SEVENTY].R = Pin_Disabled;	
		SIU.PCR[NINETY].R = Pin_Disabled;		
		SIU.GPDO[SEVENTY_FIVE].B.PDO =  TURN_ON;			   
		break;
		
	case ONE_HUNDRED_AND_THIRTY_KM: 
		SIU.PCR[SEVENTY_FIVE].R = Pin_Disabled;	
		SIU.PCR[EIGHTY].R = Pin_Disabled;	
		SIU.PCR[SEVENTY].R = Pin_Disabled;	
		SIU.PCR[10].R = Pin_Disabled;		
		SIU.GPDO[NINETY].B.PDO =  TURN_ON;
		SIU.GPDO[15].B.PDO =  TURN_ON;
		break;

	case hundred_sixty_km: 
		SIU.PCR[SEVENTY_FIVE].R = Pin_Disabled;	
		SIU.PCR[EIGHTY].R = Pin_Disabled;	
		SIU.PCR[SEVENTY].R = Pin_Disabled;	
		SIU.PCR[10].R = Pin_Disabled;		
		SIU.GPDO[NINETY].B.PDO =  TURN_ON;
		SIU.GPDO[15].B.PDO =  TURN_ON;
		delay_for(400000);
		SIU.PCR[NINETY].R = Pin_Disabled;	
		break;
		
	case zero_km: 
			SIU.PCR[SEVENTY_FIVE].R = Pin_Disabled;	
			SIU.PCR[EIGHTY].R = Pin_Disabled;	
			SIU.PCR[SEVENTY].R = Pin_Disabled;	
			SIU.PCR[10].R = Pin_Disabled;
			SIU.PCR[NINETY].R = Pin_Disabled;	
			SIU.PCR[15].R = Pin_Disabled;
				
			break;	
		
	    }
	}
}


void veinte_pasos()
{
	
	
	int RPM         = 4;
	int Op          = RPM;
	
	
	
	switch(Op){
			
		case Fifty_RPM: 
			SIU.PCR[31].R  = Pin_Disabled;	
			SIU.PCR[18].R  = Pin_Disabled;
			SIU.PCR[17].R  = Pin_Disabled;
			SIU.GPDO[ Fifty].B.PDO =  TURN_ON;	
			break;
			
			
		case 1: 
			SIU.PCR[31].R  = Pin_Disabled;	
			SIU.PCR[18].R  = Pin_Disabled;				
			SIU.GPDO[17].B.PDO =  TURN_ON;
			SIU.PCR[16].R  = Pin_Disabled;
			break;
			
		case 2: 
			SIU.PCR[31].R  = Pin_Disabled;	
			SIU.GPDO[18].B.PDO =  TURN_ON;
			SIU.PCR[17].R  = Pin_Disabled;				
			SIU.PCR[16].R  = Pin_Disabled;
			break;
			
		case 3: 
			SIU.GPDO[31].B.PDO =  TURN_ON;
			SIU.GPDO[18].B.PDO =  TURN_ON;
			SIU.PCR[17].R  = Pin_Disabled;				
			SIU.PCR[16].R  = Pin_Disabled;
			break;
			
		case 4: 
			
			SIU.GPDO[18].B.PDO =  TURN_ON;
			SIU.PCR[17].R  = Pin_Disabled;				
			SIU.PCR[16].R  = Pin_Disabled;
			delay_for(400000);
			SIU.GPDO[31].B.PDO =  TURN_ON;
			SIU.PCR[18].R  = Pin_Disabled;
			break;
			
		
	}
	
	
}

    
  void temp(){
	  
	   int Low_temp = 1;
	   int Active_Low_temp = Low_temp;
	   
	   if(Active_Low_temp == 0){
		  SIU.GPDO[26].B.PDO =  TURN_ON;
		  SIU.PCR[28].R  = Pin_Disabled;	
	   }
	   
	   if(Active_Low_temp == 1){
	  	SIU.GPDO[26].B.PDO =  TURN_ON;
	  	SIU.GPDO[28].B.PDO =  TURN_ON;	
	  	   }
  }
  
  
  
  
  void Directionals(){
	  
	  int left = 1;
	  int Left_Turn    =  TOOGLE;
	  int Active       =  Left_Turn;
	  	
	  	if(left == 1){
	  	while(Active == TOOGLE){
	  			
	  			SIU.GPDO[8].B.PDO = TURN_ON;
	  			t(4000000);
	  			SIU.GPDO[8].B.PDO = TURN_OFF;
	  			t(9000000);
	  			
	  		}
	  	}
	  	
	      if(left == 2){
	      	
	      	while(Active == TOOGLE){
	      				
	      				SIU.GPDO[9].B.PDO = TURN_ON;
	      				t(4000000);
	      				SIU.GPDO[9].B.PDO = TURN_OFF;
	      				t(9000000);
	      				
	      			}
  }
}











