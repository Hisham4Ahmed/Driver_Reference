/**
 * @file   Btn_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once 

#include <stdint.h>
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"

#include "Btn_Private.h"
#include "Btn_Config.h"

/**
 * @fn     
 * @brief 
 * @param BtnNumber 
 */ 
void    hBtn_Init(uint8_t BtnNumber);
/**
 * @fn     
 * @brief 
 * @param BtnNumber 
 * @return
 * @returnval  
 */
uint8_t hBtn_IsPressed(uint8_t BtnNumber);