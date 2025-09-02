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
void main()
{
  hBtn_Init(1);
  hLed_Init(1);
  uint8_t BtnState = Btn_NotValidState ;
  while(1)
  {
    BtnState = hBtn_IsPressed(1);
    if(BtnState==Btn_Pressed)
    {
      hLed_On(1);
    }
    else 
    {
      hLed_Off(1);
    }
  }
}