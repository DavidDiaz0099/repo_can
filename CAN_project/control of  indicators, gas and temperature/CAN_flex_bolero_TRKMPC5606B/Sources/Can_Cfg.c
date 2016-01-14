/*~A*/
/*~+:Header*/
/*******************************************************************************/
/**
\file       can_cfg.c
\author     Alicia Álvarez
\version    1.0
*/
/****************************************************************************************************/
/*~E*/
/*~A*/
/*~+:Imports*/
#include "Can_Cfg.h"
#include "Can_Manager.h"
/*~E*/
/*~A*/
/*~+:Defines*/
#define MAX_NUM_RX_FILTERS  (4)
#define MAX_NUM_TX_FILTERS  (2)
/*~E*/
/*~A*/
/*~+:External Interfaces*/
extern uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len);
/*~E*/
/*~A*/
/*~+:Variables*/
/*~A*/
/*~+:CAN Baudrate Configuration*/
CAN_DevBaudrateType bios_cnf_can_baudrate_options[] = {
/***********************************************************************************/
/* Propagation Segment------------------------------+                              */
/* Phase Segment 2-------------------------------+  |                              */
/* Phase Segment 1----------------------------+  |  |                              */
/* Resync Jump Width-----------------------+  |  |  |                              */
/* Baudrate Prescaler------------------+   |  |  |  |                              */
/* Clock Source ------------+          |   |  |  |  |                              */
/*                          |          |   |  |  |  |                              */
                     {CNF_CAN_OSC_CLK, 1,  2, 2, 2, 3},     /* BR 1Mbps            */
                     {CNF_CAN_OSC_CLK, 2,  2, 2, 2, 3},     /* BR 500kbps          */
                     {CNF_CAN_OSC_CLK, 4,  2, 2, 2, 3},     /* BR 250kbps          */
                     {CNF_CAN_OSC_CLK, 8,  2, 2, 2, 3}      /* BR 125kbps          */
};



/*~E*/
/*~A*/
/*~+:CAN Messages Configuration*/
CAN_ConfigMsgType bios_cnf_can_messages[] = {
 /* MB#, Message      , Message transmit ,  Message length , Message   ,	Message	  ,	Callback function 
  *     operation		remote request							ID			Mask
  *      TX / RX
  */
	{ 0, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x310,         0x310,                NULL  }, //Veh_Speed
	{ 1, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x202,         0x202,                Odometer },
	{ 2, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x203,         0x203,              Fuel_Tank  },
	{ 3, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x204,         0x204,    Door_Status_Indicator},
	{ 4, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x601,         0x601,     Seatbelt_Indicator  },
	{ 5, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x302,         0x302,          Ignition_Status},
	{ 6, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x307,         0x307,          Control_Shift  },
	{ 7, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x308,         0x308,             Directionals},
	{ 8, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x309,         0x309,                Temp_high},
	/*{ 9, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x310,         0x201,                Veh_Speed},
	{ 10, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x311,    0x311,                 Oil_low},
	{ 11, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x312,    0x312,              High_beams},
	{ 12, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x313,    0x313,             Hand_break },
	{ 13, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x314,    0x314,             Battery_low},
	{ 14, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x315,    0x315,               Door_open},
	{ 15, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x316,    0x316,                Seatbelt},
	{ 16, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x317,    0x317,         Direction_left},
	{ 17, CNF_CAN_CH_RX, CNF_CAN_DATA_FRAME, CNF_CAN_IDE_STD, 0x318,    0x318,          Direction_right}*/
};

/*~E*/
/*~A*/
/*~+:CAN Device Configuration*/
CAN_ConfigDeviceType bios_cnf_can_dev[] = 
{
	{
		CANB,                                           						/* CAN Device */
		( sizeof(bios_cnf_can_messages)/sizeof(bios_cnf_can_messages[0]) ),		/* Number of channels */
		CNF_CAN_BOFF_DIS,                               						/* Automatic Recovery OFF */
		CNF_CAN_LBUF_ON,                                						/* Lower buffer is transmitted first */
		CNF_CAN_FIFO_DIS,                               						/* FIFO Disabled */
		CNF_CAN_IND_MASK,                               						/* Filter mode Individual Mask */
		&bios_cnf_can_baudrate_options[1],              						/* CAN Baud rate Configuration */
		bios_cnf_can_messages,                  								/* Configured channels for this CAN Engine */
	}
};

/*~E*/
/*~A*/
/*~+:CAN Driver Configuration*/
CAN_ConfigType can_driver_config = {
( sizeof(bios_cnf_can_dev)/sizeof(bios_cnf_can_dev[0]) ),   /* Number of devices */
bios_cnf_can_dev                                            /* Pointer to devices configuration */
};

/*~E*/
/*~E*/
