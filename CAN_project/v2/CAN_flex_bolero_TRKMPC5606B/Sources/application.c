/*
 * application.c
 *
 *  Created on: Jan 9, 2016
 *      Author: Frank
 */


#include "application.h"

 extern uint8_t High_beams_Status;

void application()
{
	

	
	switch (Temp_high_Status){  //temp
	
	case 0: SIU.GPDO[26].B.PDO = 1; //caso temp media 70 °c
	        SIU.PCR[28].R= 0x0100;
	        break;
	        
	case 1: SIU.GPDO[26].B.PDO = 1; //caso temp alta 77 °c
	        SIU.GPDO[28].B.PDO = 1;
	        SIU.GPDO[5].B.PDO = 1; //turn on high temp indicator
	        break;
	        
	case 2: SIU.PCR[26].R= 0x0100; //caso  0 °c
		    SIU.PCR[28].R= 0x0100;        
            break;
	}
    
	
    switch (Gas_low_Status){
	
    case 0: SIU.GPDO[30].B.PDO = 1;  // gasolina media
            SIU.PCR[29].R= 0x0100; 
            break;
            
    case 1: SIU.GPDO[30].B.PDO = 1;  //gasolina alta
            SIU.GPDO[29].B.PDO = 1; 
            break;
    
    case 2: SIU.PCR[30].R= 0x0100; //gasolina baja
            SIU.PCR[29].R= 0x0100;
            SIU.GPDO[3].B.PDO = 1; 
            break;
    }

////////////////////////////////////////////////////////////////////////////////////////////////tell tale
    if (Directional_Status== 1){
   		     SIU.GPDO[8].B.PDO = 1; //right
   		     SIU.GPDO[9].B.PDO = 1; //left
    }
	if (Oil_low_Status== 1)
            SIU.GPDO[7].B.PDO = 1;
            	
    if (High_beams_Status == 1)
            SIU.GPDO[6].B.PDO = 1;
            	
    if (Hand_break_Status == 1)
            SIU.GPDO[2].B.PDO = 1;
    
  /////////////////////////////////////////////////////////////////////////////////////////////////////
	
    
    switch (Veh_speed_status){  
	
	case 0: SIU.PCR[10].R = 0x0100; // VEL 90
	        SIU.PCR[11].R = 0x0100;
	        SIU.PCR[12].R = 0x0100;
	        SIU.PCR[13].R = 0x0100;
	        SIU.GPDO[14].B.PDO = 1;
	        break;
	        
	case 1: SIU.PCR[10].R = 0x0100; // VEL 80
			SIU.PCR[11].R = 0x0100;
			SIU.PCR[12].R = 0x0100;
			SIU.GPDO[13].B.PDO = 1;
			SIU.PCR[14].R = 0x0100;
			break;
	        
	        
	case 2: SIU.PCR[10].R = 0x0100; // VEL 70
			SIU.PCR[11].R = 0x0100;
			SIU.GPDO[12].B.PDO = 1;
			SIU.PCR[13].R = 0x0100;
			SIU.PCR[14].R = 0x0100;
			break;
    
	case 3: SIU.PCR[10].R = 0x0100; // VEL 75
			SIU.GPDO[11].B.PDO = 1;
			SIU.PCR[12].R = 0x0100;
			SIU.PCR[13].R = 0x0100;
			SIU.PCR[14].R = 0x0100;
			break;
		
	case 4: SIU.PCR[10].R = 0x0100; // VEL 130
			SIU.PCR[11].R = 0x0100;
			SIU.PCR[12].R = 0x0100;
			SIU.PCR[13].R = 0x0100;
			SIU.GPDO[14].B.PDO = 1;
			SIU.GPDO[15].B.PDO = 1;
			break;
	
	case 6: SIU.PCR[10].R = 0x0100; // VEL 130
			SIU.PCR[11].R = 0x0100;
			SIU.PCR[12].R = 0x0100;
			SIU.PCR[13].R = 0x0100;
			SIU.PCR[14].R = 0x0100;	
			SIU.PCR[15].R = 0x0100;	
			break;
	
		
	}
    

  switch (Rpm_status){  
    	
  case 0: 	SIU.PCR[31].R = 0x0100; // RPM 15
			SIU.PCR[18].R = 0x0100;
			SIU.PCR[17].R = 0x0100;
			SIU.GPDO[16].B.PDO = 1;
			break;
			
  case 1: 	SIU.PCR[31].R = 0x0100; // RPM ?
  			SIU.PCR[18].R = 0x0100;
  			SIU.PCR[16].R = 0x0100;
  			SIU.GPDO[17].B.PDO = 1;
  			break;		
  
  case 2: 	SIU.PCR[31].R = 0x0100; // RPM ?
			SIU.PCR[16].R = 0x0100;
			SIU.PCR[17].R = 0x0100;
			SIU.GPDO[18].B.PDO = 1;
    		break;
    		
  case 3: 	SIU.GPDO[31].B.PDO = 1; // VEL 90
 			SIU.PCR[16].R = 0x0100;
 			SIU.PCR[17].R = 0x0100;
 			SIU.GPDO[18].B.PDO = 1;
     		break;				
				
			
  case 5: 	SIU.PCR[31].R = 0x0100; // RPM 0
			SIU.PCR[18].R = 0x0100;
   			SIU.PCR[16].R = 0x0100;
   			SIU.PCR[17].R = 0x0100;
   			
       		break;				
  					
			
			
			
    
  }
    

}
    
    
    
    
    
    
    
    
    
    

   
    














	
