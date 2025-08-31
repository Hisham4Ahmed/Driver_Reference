/**
 * @file   Lcd_Interface.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once 
#include <stdint.h>
#include "../../Common/Macros.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "Lcd_Private.h"
#include "Lcd_Config.h"

void hLcd_Init();
void hLcd_SetInstructions(uint8_t Instructions);
void hLcd_WriteCharacter(uint8_t Character);
void hLcd_WriteString(const uint8_t * String);
void hLcd_WriteNumber(int32_t Number);
void hLcd_MoveDigits(uint8_t LineNumber , uint8_t DigitNumber);
void hLcd_StoreNewPattern(uint8_t CGRAMBlockNumber, uint8_t *Pattern);
void hLcd_ClearFirstLine();
void hLcd_ClearSecondLine();
void hLcd_ClearScreen();