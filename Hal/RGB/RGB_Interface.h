/**
 * @file RGB_Interface.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _RGB_INTERFACE_H_
#define _RGB_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"


#include "RGB_Private.h"
#include "RGB_Config.h"


// API's

void hRGB_Init(uint8_t RGBLedNumber);
void hRGB_On(uint8_t RGBLedNumber,uint8_t Color );
void hRGB_Off(uint8_t RGBLedNumber);


#endif 