/**
 * @file      main.c
 * @author    your name (you@domain.com)
 * @brief 
 * @version   0.1
 * @date      2025-08-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Hal/Lcd/Lcd_Interface.h"
uint8_t customChar[] = {
  0x00,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x00,
  0x04,
  0x00
};
void main()
{
    hLcd_Init();
    hLcd_StoreNewPattern(0,customChar);
    hLcd_WriteString((uint8_t*)"Gestell");
    hLcd_MoveDigits(SecondLine,15);
    hLcd_WriteCharacter(0);
}