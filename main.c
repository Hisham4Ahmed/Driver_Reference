/**
 * @file main.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Hal/Lcd/Lcd_Interface.h"
#include "Hal/Btn/Btn_Interface.h"
#include "Hal/Led/Led_Interface.h"
#include "Hal/Keypad/Kpd_Interface.h"
#include "Hal/BtnWithEXTI/BtnEXTI_Interface.h"
void main()
{
  hLcd_Init();
  hKeypad_Init();
  uint8_t KeypadValue = 0xFF;
  while(1)
  {
    KeypadValue = hKeypad_GetPressedKey();
    if(KeypadValue!=0xFF)
    {
      hLcd_WriteCharacter(KeypadValue);
    }

  }
}