/**
 * @file   DIO_Interface.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief  This File Will Contain the Prototype for DIO API's
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025 , Gestell Company , Gestell Company 
 * 
 */
#ifndef  _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
#include <stdint.h>
#include "../../Common/Macros.h"
#include "../RegistersAddress.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
/**
 * @fn      mDIO_SetDirectionForPin
 * @brief   This Function Use to Control Direction for Specific Pin
 * 
 * @param GroupName     : This Parameter Detect Which Group Will Use and will be on of following Options :
                          GroupA,GroupB,GroupC,GroupD
 * @param PinNumber     : This Parameter Detect Which Pin Will be Controlled and and will be on of following Options :
                          Pin0,Pin1,Pin2,Pin3,Pin4,Pin5,Pin6,Pin7
 * @param DirectionState: This Parameter Used to Define Which Direction you Need and and will be on of following Options :
                          Input , Output 
 * @return void 
 */ 
void mDIO_SetDirectionForPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirectionState);


void mDIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue);


uint8_t mDIO_ReadPin(uint8_t GroupName,uint8_t PinNumber);

void mDIO_TogglePin(uint8_t GroupName,uint8_t PinNumber);

/********************************************************************** */

/*
DirectionState (0 :  255 )*/
void mDIO_SetDirectionForGroup(uint8_t GroupName,uint8_t DirectionState);

/*
OutputValues (0 :  255 )*/
void mDIO_WriteGroup(uint8_t GroupName,uint8_t OutputValues);

uint8_t mDIO_ReadGroup(uint8_t GroupName);




#endif /*_DIO_INTERFACE_H_ */
