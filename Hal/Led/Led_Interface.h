/**
 * @file Led_Interface.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_
#include <stdint.h>
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "Led_Private.h"
#include "Led_Config.h"

void hLed_Init(uint8_t LedNumber);
void hLed_On(uint8_t LedNumber);
void hLed_Off(uint8_t LedNumber);
void hLed_Toggle(uint8_t LedNumber);



#endif /*_LED_INTERFACE_H_*/