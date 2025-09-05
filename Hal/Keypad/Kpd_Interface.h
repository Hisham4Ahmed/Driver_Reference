/**
 * @file Kpd_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once 
#include <stdint.h>
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"

#include "Kpd_Private.h"
#include "Kpd_Config.h"

/**
 * @fn 
 * @brief 
 * @param  
 */
void hKeypad_Init(void);
/**
 * @fn
 * @brief 
 * @param  
 * @return 
 * @retval 
 */
uint8_t hKeypad_GetPressedKey(void);

