/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.h
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
#ifndef __CAN_MANAGER
#define __CAN_MANAGER
/*~A*/
/*~+:Imports*/
#include "Can.h"
/*~E*/
/*~A*/
/*~+:Exported Interfaces*/

extern void Indicators(CAN_MessageDataType CanMessage1);

extern void Telltel(CAN_MessageDataType CanMessage7);



extern void Can_Manager_PduHandler7(CAN_MessageDataType CanMessage);
extern void CanManager_SendMessage_12p5ms(void);
extern void CanManager_SendMessage_25ms(void);
extern void CanManager_SendMessage_100ms(void);


/*~E*/
#endif /* __CAN_MANAGER */
