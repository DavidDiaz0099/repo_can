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

uint8_t TNK_MSB;    //MSB B0
uint8_t TNK_LSB;    // LSB  B1
uint8_t GAS_Status; // B2

uint8_t Door_Status;   //B0
uint8_t High_Beams_Status; //B1
uint8_t HandBrake_Status; //B2

uint8_t Seatbelt_Status; //B0
uint8_t Ign_Status;     //B0
uint8_t Gearbox_Status; //B0

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

CAN_MessageDataType CanMessage_PduHandler7;
uint8_t msg_rx_pdu0 = 0;
uint8_t msg_rx_pdu7 = 0;

void Veh_Speed(CAN_MessageDataType CanMessage)
{
	
	Can_Vel_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
	pdu_handler7.can_mb_nr = 7;
	pdu_handler7.can_dlc = Can_Vel_Message.msg_dlc_field;
	pdu_handler7.can_sdu = Can_Vel_Message.msg_data_field;
	
	acteng_msb = Can_Vel_Message.msg_data_field[0]; //
	acteng_lsb = Can_Vel_Message.msg_data_field[1]; //
	if ((acteng_msb == 0) && (acteng_lsb == 1))
		SIU.GPDO[68].B.PDO = 0; //DEJA PRENDIDO LED1 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
	msg_rx_pdu0 = 1;
    PduHandlerCnt0++;
}

void Odometer(CAN_MessageDataType CanMessage)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	Can_Odo_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
		pdu_handler7.can_mb_nr = 7;
		pdu_handler7.can_dlc = Can_Odo_Message.msg_dlc_field;
		pdu_handler7.can_sdu = Can_Odo_Message.msg_data_field;
		
		Increase_ACK = Can_Odo_Message.msg_data_field[0]; //
		Odometer_Value = Can_Odo_Message.msg_data_field[1]; //
		if ((Increase_ACK == 2) &&  (Odometer_Value== 3))
		  SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL MENSAJE	
		msg_rx_pdu0 = 1;
	    PduHandlerCnt0++;

}

void Fuel_Tank (CAN_MessageDataType CanMessage) //UNICO Q JALA
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	Can_Fuel_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
			pdu_handler7.can_mb_nr = 7;
			pdu_handler7.can_dlc = Can_Fuel_Message.msg_dlc_field;
			pdu_handler7.can_sdu = Can_Fuel_Message.msg_data_field;
			
			TNK_MSB = Can_Fuel_Message.msg_data_field[0]; //
			TNK_LSB = Can_Fuel_Message.msg_data_field[1]; //
			GAS_Status = Can_Fuel_Message.msg_data_field[2]; //
			
		//	if ((Increase_ACK == 8) &&  (Odometer_Value== 9))
		//		SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
		msg_rx_pdu0 = 1;
		PduHandlerCnt0++;
}

void  Door_Status_Indicator(CAN_MessageDataType CanMessage)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
		Indicators_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
				pdu_handler7.can_mb_nr = 7;
				pdu_handler7.can_dlc = Indicators_Message.msg_dlc_field;
				pdu_handler7.can_sdu = Indicators_Message.msg_data_field;
				
				Door_Status = Indicators_Message.msg_data_field[0]; //
				High_Beams_Status = Indicators_Message.msg_data_field[1]; //
				HandBrake_Status = Indicators_Message.msg_data_field[2]; //
				
			//	if ((Increase_ACK == 8) &&  (Odometer_Value== 9))
			//		SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
			msg_rx_pdu0 = 1;
			PduHandlerCnt0++;
	
}

void Seatbelt_Indicator(CAN_MessageDataType CanMessage)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	  Seatbelt_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
					pdu_handler7.can_mb_nr = 7;
					pdu_handler7.can_dlc = Seatbelt_Message.msg_dlc_field;
					pdu_handler7.can_sdu = Seatbelt_Message.msg_data_field;
					
					Seatbelt_Status = Indicators_Message.msg_data_field[0]; //
				
				//	if ((Increase_ACK == 8) &&  (Odometer_Value== 9))
				//		SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
				msg_rx_pdu0 = 1;
				PduHandlerCnt0++;
}

void Ignition_Status(CAN_MessageDataType CanMessage)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
		  Ign_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
						pdu_handler7.can_mb_nr = 7;
						pdu_handler7.can_dlc = Ign_Message.msg_dlc_field;
						pdu_handler7.can_sdu = Ign_Message.msg_data_field;
						
						Ign_Status = Ign_Message.msg_data_field[0]; //
					
					//	if ((Increase_ACK == 8) &&  (Odometer_Value== 9))
					//		SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
					msg_rx_pdu0 = 1;
					PduHandlerCnt0++;
} 

void Control_Shift(CAN_MessageDataType CanMessage)
{
	//SIU.GPDO[69].B.PDO = 1; //DEJA PRENDIDO PIN1 PUERTO A COMO INDICADOR DE QUE SE RECIVIO EL ID
	Gearbox_Message = CanMessage; //  se recive CanMeessage uqe es el parametro de entrada de la funcion y se cambia por  canmessage put handler
							pdu_handler7.can_mb_nr = 7;
							pdu_handler7.can_dlc = Gearbox_Message.msg_dlc_field;
							pdu_handler7.can_sdu = Gearbox_Message.msg_data_field;
							
							Gearbox_Status = Gearbox_Message.msg_data_field[0]; //
						
						//	if ((Increase_ACK == 8) &&  (Odometer_Value== 9))
						//		SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID	
						msg_rx_pdu0 = 1;
						PduHandlerCnt0++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Can_Manager_PduHandler7(CAN_MessageDataType CanMessage)
{
	
	//SIU.GPDO[69].B.PDO = 0; //DEJA PRENDIDO LED2 DE LA TARJETA COMO INDICADOR DE QUE SE RECIVIO EL ID
	CanMessage_PduHandler7 = CanMessage;
	msg_rx_pdu7 = 1;
	pdu_handler8_cnt++;
	dummy_msg8[0]++;
	if (256 == pdu_handler8_cnt)
	{
		pdu_handler8_cnt = 0;
		dummy_msg8[0] = 0;
		dummy_msg8[1]++;
	}
	PduHandlerCnt6++;
}

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

