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

#include "Hal/BtnEXTI/BtnEXTI_Interface.h"
#include "Hal/Led/Led_Interface.h"
#include "Mcal/GIE/GIE.h"
#include "Common/Macros.h"
#include <util/delay.h>

void ToggleLed();
void main()
{
    hBtnExti_Handler(Button1,ToggleLed);
    hBtnExti_Init(Button1);
    hLed_Init(Led1);
    hLed_Init(Led2);
    mGIE_Enable();
    while (1)
    {
        hLed_Toggle(Led2);
        _delay_ms(1000);
    }
    

}

void ToggleLed()
{
    static uint8_t State = Off;
    if(State==Off)
    {
        hLed_On(Led1);
        State=On;
    }
    else if (State==On)
    {
        hLed_Off(Led1);
        State=Off;
    }
}