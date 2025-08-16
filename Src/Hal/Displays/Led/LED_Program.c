/**
 * @file LED_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "../../../../Inc/Hal/Displays/Led/LED_Interface.h"
static uint8_t LedGroup[MaxLed]= LEDGROUPVALUE; 
static uint8_t LedPin[MaxLed]=LEDPINVALUE;


void hLED_Init(uint8_t LedNumber)
{
    mDIO_SetDirectionForPin(LedGroup[LedNumber-1],LedPin[LedNumber-1],Output);
}

void hLED_On(uint8_t LedNumber)
{
    #if ConnectionType==Led_SourceConnection
    mDIO_WritePin(LedGroup[LedNumber-1],LedPin[LedNumber-1],High);
    #elif ConnectionType==Led_SinkConnection
    mDIO_WritePin(LedGroup[LedNumber-1],LedPin[LedNumber-1],Low);
    #endif
}


void hLED_Off(uint8_t LedNumber)
{
  #if ConnectionType==Led_SourceConnection
  mDIO_WritePin(LedGroup[LedNumber-1],LedPin[LedNumber-1],Low);
  #elif ConnectionType==Led_SinkConnection
  mDIO_WritePin(LedGroup[LedNumber-1],LedPin[LedNumber-1],High);
  #endif
}


void hLED_Blink(uint8_t LedNumber)
{
    mDIO_TogglePin(LedGroup[LedNumber-1],LedPin[LedNumber-1]);
    _delay_ms(BlinkTime);
}

