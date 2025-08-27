/**
 * @file SSD_Interface.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_ 

#include <stdint.h>
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "SSD_Private.h"
#include "SSD_Config.h"

void hSSD_Init(uint8_t SSDNumber);
/**
 * @brief 
 * 
 * @param SSDNumber 
 * @param DisplayNumber   0 : 9 
 */
void hSSD_DisplayNumber(uint8_t SSDNumber,uint8_t DisplayNumber);
void hSSD_EnableSSD(uint8_t SSDNumber);
void hSSD_DisableSSD(uint8_t SSDNumber);

#endif 