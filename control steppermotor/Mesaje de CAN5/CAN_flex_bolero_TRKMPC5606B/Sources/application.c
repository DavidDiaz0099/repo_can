/*
 * application.c
 *
 *  Created on: Jan 9, 2016
 *      Author: Frank
 */


#include "application.h"


void application()
{
	if ((acteng_msb == 0) && (acteng_lsb == 1)) {//velocimetro
		         SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG		
		         SIU.GPDO[6].B.PDO = 1;
	}
	
	if (Increase_ACK == 2){  //odometro
		        SIU.GPDO[1].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG
	}
	
	if(Odometer_Value == 3){//odometro
		        SIU.GPDO[2].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG
	}
	
	
	if ((TNK_MSB == 4) && (TNK_LSB == 5)){ //tanque de gasolina
		        SIU.GPDO[3].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG		
	}
	
	if(GAS_Status==6){	//odometro
		       SIU.GPDO[4].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG	
	}
	
	if (Door_Status == 7 ){ // indicators
				SIU.GPDO[5].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG	
	}
	
	if (High_Beams_Status==8){
				SIU.GPDO[0].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG	
	}
	
	if (HandBrake_Status==9){
				SIU.GPDO[7].B.PDO = 1; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG	
	}
	
	if (Seatbelt_Status == 10){
				SIU.GPDO[8].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
	}
	
	if (Ign_Status == 11){
				SIU.GPDO[9].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
	}
	
	if ( Gearbox_Status== 12){
		        SIU.GPDO[10].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
	
	}



}
	
