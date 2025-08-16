/**
 * @file   LED_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */



#ifndef  _LED_INTERFACE_H_
#define  _LED_INTERFACE_H_

#include <stdint.h>
#include <util/delay.h>
#include "../../../Mcal/DIO/DIO_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"
// LedNumber - > 1 : 8 
void hLED_Init(uint8_t LedNumber);

void hLED_On(uint8_t LedNumber);


void hLED_Off(uint8_t LedNumber);


void hLED_Blink(uint8_t LedNumber);





#endif 