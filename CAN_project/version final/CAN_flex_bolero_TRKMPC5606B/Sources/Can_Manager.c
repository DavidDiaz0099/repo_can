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

uint8_t Veh_speed_status;  //B0

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
uint8_t Rpm_status;
uint8_t Gas_low_Status;
uint8_t Oil_low_Status;
uint8_t High_beams_Status;
uint8_t Hand_break_Status;
uint8_t Battery_Status; 
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

CAN_MessageDataType Indicators_Message;
CAN_MessageDataType Directional_Message;

CAN_MessageDataType CanMessage_PduHandler7;
uint8_t msg_rx_pdu0 = 0;
uint8_t msg_rx_pdu7 = 0;



void Indicators(CAN_MessageDataType CanMessage1)
{
	
	Indicators_Message = CanMessage1; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
		//pdu_handler7.can_dlc = Can_Odo_Message.msg_dlc_field;
		//pdu_handler7.can_sdu = Can_Odo_Message.msg_data_field;
	  
	Directional_Status = Indicators_Message.msg_data_field[0]; 
	Oil_low_Status	= Indicators_Message.msg_data_field[1]; 
	High_Beams_Status = Indicators_Message.msg_data_field[2]; 
	HandBrake_Status = Indicators_Message.msg_data_field[3]; 
	
}



///////////////////////////////////////////////////////////////////////////////////////////////
void Telltel(CAN_MessageDataType CanMessage7) //chida
{
	Directional_Message = CanMessage7;
	Temp_high_Status = Directional_Message.msg_data_field[0]; 
	Gas_low_Status= Directional_Message.msg_data_field[1];
	Veh_speed_status= Directional_Message.msg_data_field[2]; 
	Rpm_status = Directional_Message.msg_data_field[3];    
	Battery_Status= Directional_Message.msg_data_field[4]; 
	Seatbelt_Status = Directional_Message.msg_data_field[5]; 
	Door_open_Status = Directional_Message.msg_data_field[6];
	Ign_Status =  Directional_Message.msg_data_field[7];
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

