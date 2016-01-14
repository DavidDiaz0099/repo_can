/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "Can_Manager.h"
/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Variables*/

/* Temporary CAN Data Messages */
uint8_t dummy_msg0[8] = {0xCA,0x83,0x15,0x77,0x19,0x56,0x65,0x00};
uint8_t dummy_msg1[8] = {0x00,0x65,0x56,0x19,0x77,0x15,0x83,0xCA};
uint8_t dummy_msg2[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};
uint8_t dummy_msg8[2] = {0x00,0x00};
uint8_t dummy_msg9[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};

/** PDU: Protocol data unit */
CAN_PduType    pdu_handler4 = { 4, 8, dummy_msg0};
CAN_PduType    pdu_handler5 = { 5, 6, dummy_msg1};
CAN_PduType    pdu_handler6 = { 6, 2, dummy_msg2};
CAN_PduType    pdu_handler7 = { 2, 4, dummy_msg2};
CAN_PduType    pdu_handler8 = { 8, 2, dummy_msg8};
CAN_PduType    pdu_handler9 = { 9, 8, dummy_msg9};

uint32_t PduHandlerCnt0 = 0;
uint32_t PduHandlerCnt6 = 0;
uint16_t pdu_handler8_cnt = 0;

uint8_t acteng_msb;  //B0
uint8_t acteng_lsb;  //B1

uint8_t Increase_ACK;  //MSB B0
uint8_t Odometer_Value; //LSB B1

uint8_t TNK_MSB;   //MSB B0
uint8_t TNK_LSB;    // LSB  B1
uint8_t GAS_Status; // B2

uint8_t Door_Status;   //B0
uint8_t High_Beams_Status; //B1
uint8_t HandBrake_Status; //B2

uint8_t Seatbelt_Status; //B0
uint8_t Ign_Status;     //B0
uint8_t Gearbox_Status; //B0

uint8_t Directional_Status;
uint8_t Temp_high_Status;

uint8_t Gas_low_Status;
uint8_t Oil_low_Status;
uint8_t High_beams_Status;
uint8_t Hand_break_Status;
uint8_t Battery_low_Status; 
uint8_t Door_open_Status;
uint8_t Seatbeltn_Status;
uint8_t Direction_left_Status;
uint8_t Direction_right_Status;

/*~E*/
/*~A*/
/*~+:Private Operations*/

/*~E*/
/*~A*/
/*~+:Public Operations*/
/*~A*/
/*~+:Can Manager Callbacks*/
CAN_MessageDataType Can_Vel_Message;
CAN_MessageDataType Can_Odo_Message;
CAN_MessageDataType Can_Fuel_Message;
CAN_MessageDataType Indicators_Message;
CAN_MessageDataType Seatbelt_Message;
CAN_MessageDataType Ign_Message;
CAN_MessageDataType Gearbox_Message;
CAN_MessageDataType Directional_Message;
CAN_MessageDataType Temp_high_Message;
CAN_MessageDataType Gal_low_Message;
CAN_MessageDataType Oil_low_Message;

CAN_MessageDataType Temp_high_Message;
CAN_MessageDataType Gas_low_Message;
CAN_MessageDataType Oil_low_Message;
CAN_MessageDataType High_beams_Message;
CAN_MessageDataType Hand_break_Message;
CAN_MessageDataType Battery_low_Message;
CAN_MessageDataType Door_open_Message;
CAN_MessageDataType Seatbeltn_Message;
CAN_MessageDataType Direction_left_Message;
CAN_MessageDataType Direction_right_Message;



CAN_MessageDataType CanMessage_PduHandler7;
uint8_t msg_rx_pdu0 = 0;
uint8_t msg_rx_pdu7 = 0;

void Veh_Speed(CAN_MessageDataType CanMessage0)
{
	
	Can_Vel_Message = CanMessage0; //  unico con detalle de variacion
	//pdu_handler7.can_mb_nr = 7;
	//pdu_handler7.can_dlc = Can_Vel_Message.msg_dlc_field;
	//pdu_handler7.can_sdu = Can_Vel_Message.msg_data_field;
	acteng_msb = 0;
	acteng_lsb = 0;
	acteng_msb = Can_Vel_Message.msg_data_field[0]; //
	acteng_lsb = Can_Vel_Message.msg_data_field[1]; //
	if ((acteng_msb == 0) && (acteng_lsb == 1))
		SIU.GPDO[68].B.PDO = 0; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MSG	
	   // SIU.GPDO[0].B.PDO = 1;
	//msg_rx_pdu0 = 1;
    //PduHandlerCnt0++;
	//return (acteng_msb,acteng_lsb);
}

void Odometer(CAN_MessageDataType CanMessage1)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	
	Can_Odo_Message = CanMessage1; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
		//pdu_handler7.can_mb_nr = 7;
		//pdu_handler7.can_dlc = Can_Odo_Message.msg_dlc_field;
		//pdu_handler7.can_sdu = Can_Odo_Message.msg_data_field;
	   Increase_ACK = 0;
	   Odometer_Value = 0;
	   Increase_ACK = Can_Odo_Message.msg_data_field[0]; //
		Odometer_Value = Can_Odo_Message.msg_data_field[1]; //
	  //  if ((Increase_ACK == 2) && (Odometer_Value == 3)) 
	   // 	SIU.GPDO[1].B.PDO = 1; 
		                             //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MENSAJE	
		//msg_rx_pdu0 = 1;
	    //PduHandlerCnt0++;
		//return (Increase_ACK, Odometer_Value);
}

void Fuel_Tank (CAN_MessageDataType CanMessage2) 
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	Can_Fuel_Message = CanMessage2; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
			//pdu_handler7.can_mb_nr = 7;
			//pdu_handler7.can_dlc = Can_Fuel_Message.msg_dlc_field;
			//pdu_handler7.can_sdu = Can_Fuel_Message.msg_data_field;
	       TNK_MSB = 0;
	       TNK_LSB = 0;
	       GAS_Status  = 0;
		  	   
			TNK_MSB = Can_Fuel_Message.msg_data_field[0]; //
			TNK_LSB = Can_Fuel_Message.msg_data_field[1]; //
			GAS_Status = Can_Fuel_Message.msg_data_field[2]; //
			
			//if (TNK_MSB == 4) 
			 // SIU.GPDO[2].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
		//msg_rx_pdu0 = 1;
		//PduHandlerCnt0++;
}

void  Door_Status_Indicator(CAN_MessageDataType CanMessage3)
{
	
		Indicators_Message = CanMessage3; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
				pdu_handler7.can_mb_nr = 7;
				//pdu_handler7.can_dlc = Indicators_Message.msg_dlc_field;
				//pdu_handle.can_sdu = Indicators_Message.msg_data_field;
		        Door_Status = 0;
		        High_Beams_Status = 0;
		        HandBrake_Status  = 0;
			       
				Door_Status = Indicators_Message.msg_data_field[0]; //
				High_Beams_Status = Indicators_Message.msg_data_field[1]; //
				HandBrake_Status = Indicators_Message.msg_data_field[2]; //
				
				//if ((Door_Status == 7) &&  (High_Beams_Status== 8) && (HandBrake_Status == 9))
					  //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
			//msg_rx_pdu0 = 1;
			//PduHandlerCnt0++;	
}

void Seatbelt_Indicator(CAN_MessageDataType CanMessage4)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	  Seatbelt_Message = CanMessage4; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
					//pdu_handler7.can_mb_nr = 7;
					//pdu_handler7.can_dlc = Seatbelt_Message.msg_dlc_field;
					//pdu_handler7.can_sdu = Seatbelt_Message.msg_data_field;
	            Seatbelt_Status=0;
				Seatbelt_Status = Seatbelt_Message.msg_data_field[0]; //
				
			//	if (Seatbelt_Status == 10)
			//	 SIU.GPDO[4].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
				//msg_rx_pdu0 = 1;
				//PduHandlerCnt0++;
}

void Ignition_Status(CAN_MessageDataType CanMessage5)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
		  Ign_Message = CanMessage5; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
						//pdu_handler7.can_mb_nr = 7;
						//pdu_handler7.can_dlc = Ign_Message.msg_dlc_field;
						//pdu_handler7.can_sdu = Ign_Message.msg_data_field;
						
						Ign_Status = Ign_Message.msg_data_field[0]; //
					
				//	if (Ign_Status == 11)
					//	SIU.GPDO[5].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
					//msg_rx_pdu0 = 1;
					//PduHandlerCnt0++;
} 

void Control_Shift(CAN_MessageDataType CanMessage6)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	Gearbox_Message = CanMessage6; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
							//pdu_handler7.can_mb_nr = 7;
							//pdu_handler7.can_dlc = Gearbox_Message.msg_dlc_field;
							//pdu_handler7.can_sdu = Gearbox_Message.msg_data_field;
							
							Gearbox_Status = Gearbox_Message.msg_data_field[0]; //
						
					//if ( Gearbox_Status== 12)
						//	SIU.GPDO[6].B.PDO = 1; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
						//msg_rx_pdu0 = 1;
						//PduHandlerCnt0++;
}

///////////////////////////////////////////////////////////////////////////////////////////////
void Directionals(CAN_MessageDataType CanMessage7)
{
	Directional_Message = CanMessage7;
	
	Directional_Status = Directional_Message.msg_data_field[0]; 
	
	if ( Directional_Status== 13)
	  SIU.GPDO[69].B.PDO = 1;
     // SIU.GPDO[9].B.PDO = 1;
}

void Temp_high(CAN_MessageDataType CanMessage8)
{
	Temp_high_Message = CanMessage8;
	
	Temp_high_Status = Temp_high_Message.msg_data_field[0]; 
	
	if (Temp_high_Status == 14)
	  SIU.GPDO[5].B.PDO = 1;
}

void Gas_low(CAN_MessageDataType CanMessage9)
{
	Gas_low_Message = CanMessage9;
	
	Gas_low_Status = Gal_low_Message.msg_data_field[0]; 
	
	if (Gas_low_Status== 15)
	  SIU.GPDO[3].B.PDO = 1;
}

void Oil_low(CAN_MessageDataType CanMessage10)
{
	Oil_low_Message = CanMessage10;
	
	Oil_low_Status = Oil_low_Message.msg_data_field[0]; 
	
	if (Oil_low_Status== 16)
	  SIU.GPDO[7].B.PDO = 1;
}


void High_beams(CAN_MessageDataType CanMessage11)
{
	High_beams_Message = CanMessage11;
	
	High_beams_Status = High_beams_Message.msg_data_field[0]; 
	
	if (High_beams_Status == 17)
	  SIU.GPDO[6].B.PDO = 1;
}

void Hand_break(CAN_MessageDataType CanMessage12)
{
	Hand_break_Message = CanMessage12;
	
	Hand_break_Status = Hand_break_Message.msg_data_field[0]; 
	
	if (Hand_break_Status == 18)
	  SIU.GPDO[4].B.PDO = 1;
}

void Battery_low(CAN_MessageDataType CanMessage13)
{
	Battery_low_Message = CanMessage13;
	
	Battery_low_Status = Battery_low_Message.msg_data_field[0]; 
	
	if (Battery_low_Status == 19)
	  SIU.GPDO[0].B.PDO = 1;
}

void Door_open(CAN_MessageDataType CanMessage14)
{
	Door_open_Message = CanMessage14;
	
	Door_open_Status = Door_open_Message.msg_data_field[0]; 
	
	if (Door_open_Status == 20)
	  SIU.GPDO[1].B.PDO = 1;
}

void Seatbelt(CAN_MessageDataType CanMessage15)
{
	Seatbeltn_Message = CanMessage15;
	
	Seatbeltn_Status = Seatbelt_Message.msg_data_field[0]; 
	
	if (Seatbeltn_Status == 21)
	  SIU.GPDO[2].B.PDO = 1;
}

void Direction_left(CAN_MessageDataType CanMessage16)
{
	Direction_left_Message = CanMessage16;
	
	Direction_left_Status = Direction_left_Message.msg_data_field[0]; 
	
	if (Direction_left_Status== 22)
	  SIU.GPDO[8].B.PDO = 1;
}


void Direction_right(CAN_MessageDataType CanMessage17)
{
	Direction_right_Message = CanMessage17;
	
	Direction_right_Status = Direction_right_Message.msg_data_field[0]; 
	
	if (Direction_right_Status== 23)
	 SIU.GPDO[9].B.PDO = 1;
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*~E*/
/*~A*/
/*~+:Can Manager Periodic Functions*/
/*~A*/
/*~+:CanManager_SendMesage_12p5ms*/
CAN_MessageDataType CanMessage_PduHandler2;
void CanManager_SendMessage_12p5ms(void)
{
	CAN_SendFrame(&pdu_handler4);
	if ( 1 == CAN_ReceiveFrame(2, &CanMessage_PduHandler2 ))
	{
		pdu_handler9.can_mb_nr = 9;
		pdu_handler9.can_dlc = CanMessage_PduHandler2.msg_dlc_field;
		pdu_handler9.can_sdu = CanMessage_PduHandler2.msg_data_field; //
		//vel_raww = pdu_handler9.can_sdu && 0x0000ffff00;
		//velocidad=(T_UWORD)(vel_raww>>2)
		//velocidad 
		CAN_SendFrame(&pdu_handler9);
	}
}
/*~E*/
/*~A*/
/*~+:CanManager_SendMesage_25ms*/
void CanManager_SendMessage_25ms(void)
{
	CAN_SendFrame(&pdu_handler6);
	/*~A*/
	/*~+:PDU 0*/
	
	
	if (msg_rx_pdu0)
	{
		msg_rx_pdu0 = 0;
		CAN_SendFrame(&pdu_handler7);
	}
	
	/*~E*/
	/*~A*/
	/*~+:PDU 7*/
	
	if (msg_rx_pdu7)
	{
		msg_rx_pdu7 = 0;
		CAN_SendFrame(&pdu_handler8);
	}
	
	/*~E*/
}
/*~E*/
/*~A*/
/*~+:CanManager_SendMessage_100ms*/
void CanManager_SendMessage_100ms(void)
{
	CAN_SendFrame(&pdu_handler5);
}


/*~E*/
/*~E*/
/*~E*/ 

