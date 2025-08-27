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
  if(LedNumber<=Led_MaxNo)
  {
      mDIO_SetDirectionForPin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],Output);
  }
  else 
  {
        /**
         * @todo Handle the  Led Out Of Range 
         * 
         */
  }
}
void mLed_On(uint8_t LedNumber)
{
    if(LedNumber<=Led_MaxNo)
    {
        #if Led_ConnectionType==Led_SourceConnection
        mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],High);
        #elif Led_ConnectionType==Led_SinkConnection
            mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],Low);
        #endif
    }
    else 
    {
          /**
           * @todo Handle the  Led Out Of Range 
           * 
           */
    }

}
void mLed_Off(uint8_t LedNumber)
{
    if(LedNumber<=Led_MaxNo)
    {
        #if Led_ConnectionType==Led_SourceConnection
            mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],Low);
        #elif Led_ConnectionType==Led_SinkConnection
            mDIO_WritePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex],High);
        #endif
    }
    else 
    {
          /**
           * @todo Handle the  Led Out Of Range 
           * 
           */
    }
}
void mLed_Toggle(uint8_t LedNumber)
{
    if(LedNumber<=Led_MaxNo)
    {
      mDIO_TogglePin(LedsGroup[LedNumber-StartIndex],LedsPin[LedNumber-StartIndex]);
    }
    else 
    {
          /**
           * @todo Handle the  Led Out Of Range 
           * 
           */
    }

}