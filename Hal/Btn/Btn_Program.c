/**
 * @file Btn_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "Btn_Interface.h"



static uint8_t BtnGroup[Btn_MaxNo] = BtnGroupValue ; 
static uint8_t BtnPin[Btn_MaxNo]= BtnPinValue;

void  hBtn_Init(uint8_t BtnNumber)
{
    // Pin is Input 
    mDIO_SetDirectionForPin(BtnGroup[BtnNumber-Btn_StartIndex],BtnPin[BtnNumber-Btn_StartIndex],Input);
    // Enable Pull Up Internal 
    mDIO_WritePin(BtnGroup[BtnNumber-Btn_StartIndex],BtnPin[BtnNumber-Btn_StartIndex],High);
}


uint8_t hBtn_IsPressed(uint8_t BtnNumber)
{
    uint8_t BtnState = Btn_NotValidState ; 
    mDIO_ReadPin(BtnGroup[BtnNumber-Btn_StartIndex],BtnPin[BtnNumber-Btn_StartIndex],&BtnState);

    return BtnState ; 
}