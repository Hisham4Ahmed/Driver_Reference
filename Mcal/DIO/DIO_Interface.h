/**
 * @file DIO_Interface.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_
#include <stdint.h>
#include "../../Common/Macros.h"
#include "../RegistersAddress.h"
#include "DIO_Private.h"




/**
 * @fn                       mDIO_SetDirectionForPin
 * @brief                    
 * @param GroupName          
 * @param PinNumber       
 * @param DirectionState 
 * @return void 
 * 
 */
void mDIO_SetDirectionForPin(uint8_t GroupName,uint8_t PinNumber ,uint8_t DirectionState);
void mDIO_WritePin(uint8_t GroupName,uint8_t PinNumber ,uint8_t OutputValue);
void mDIO_ReadPin(uint8_t GroupName,uint8_t PinNumber ,uint8_t *InputValue);
void mDIO_TogglePin(uint8_t GroupName,uint8_t PinNumber );
void mDIO_SetDirectionForGroup(uint8_t GroupName,uint8_t DirectionState);
void mDIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue);
void mDIO_ReadGroup(uint8_t GroupName,uint8_t *InputValue);


#endif /*_DIO_INTERFACE_H_*/