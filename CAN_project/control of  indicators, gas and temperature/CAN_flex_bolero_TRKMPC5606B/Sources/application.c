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
	
	/*if ( Directional_Status== 13)
		  SIU.GPDO[8].B.PDO = 1;
	      SIU.GPDO[9].B.PDO = 1;
	
	if (Temp_high_Status == 14)
		  SIU.GPDO[5].B.PDO = 1;
	
	if (Gas_low_Status== 15)
		  SIU.GPDO[3].B.PDO = 1;  //10?
	
	if (Oil_low_Status== 16)
		  SIU.GPDO[7].B.PDO = 1;
	
	if (High_beams_Status == 17)
		  SIU.GPDO[6].B.PDO = 1;
	
	if (Hand_break_Status == 18)
		  SIU.GPDO[].B.PDO = 1;
	
	if (Battery_low_Status == 19)
		  SIU.GPDO[0].B.PDO = 1;
	
	if (Door_open_Status == 20)
		  SIU.GPDO[1].B.PDO = 1; //15?
	
	*/
	
	switch (Temp_high_Status){  //temp
	
	case 0: SIU.GPDO[26].B.PDO = 1; //caso temp media 70 °c
	        SIU.PCR[28].R= 0x0100;
	       // SIU.GPDO[5].B.PDO = 0; 
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
           
    if (Oil_low_Status== 1)
            SIU.GPDO[7].B.PDO = 1;
            	
    if (High_beams_Status == 1)
            SIU.GPDO[6].B.PDO = 1;
            	
    if (Hand_break_Status == 1)
            SIU.GPDO[2].B.PDO = 1;
    
    


}
    
    
    
    
    
    
    
    
    
    

   
    














	
