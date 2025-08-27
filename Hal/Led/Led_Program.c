/**
 * @file Led_Program.c
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#include "Led_Interface.h"



static uint8_t LedsGroup[Led_MaxNo]=LedGroupValue ;

static uint8_t LedsPin[Led_MaxNo]=  LedPinValue;


void mLed_Init(uint8_t LedNumber)
{
  mDIO_SetDirectionForPin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],Output);
}
void mLed_On(uint8_t LedNumber)
{
    #if Led_ConnectionType==Led_SourceConnection
        mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],High);
    #elif Led_ConnectionType==Led_SinkConnection
        mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],Low);
    #endif
}
void mLed_Off(uint8_t LedNumber)
{
    #if Led_ConnectionType==Led_SourceConnection
        mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],Low);
    #elif Led_ConnectionType==Led_SinkConnection
        mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],High);
    #endif
}
void mLed_Toggle(uint8_t LedNumber)
{
        mDIO_TogglePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex]);

}