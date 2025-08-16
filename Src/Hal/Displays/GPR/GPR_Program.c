/**
 * @file GPR_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "../../../../Inc/Hal/Displays/GPR/GPR_Interface.h"
static uint8_t GPRGroup[MaxGPR]= GPRGROUPVALUE;

static uint8_t GPRPin[MaxGPR][3]=GPRPINVALUE;

void hGPR_Init(uint8_t GPRNumber)
{
    mDIO_SetDirectionForPin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_RedColor],Output);
    mDIO_SetDirectionForPin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_GreenColor],Output);
    mDIO_SetDirectionForPin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_BlueColor],Output);
}
void hGPR_On(uint8_t GPRNumber, uint8_t Color)
{
    if(Color==GPR_RedColor)
    {
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_RedColor],High);
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_GreenColor],Low);
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_BlueColor],Low);
    }
    else if(Color==GPR_GreenColor)
    {
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_RedColor],Low);
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_GreenColor],High);
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_BlueColor],Low);
    }
    else if(Color==GPR_BlueColor)
    {
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_RedColor],Low);
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_GreenColor],Low);
        mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_BlueColor],High ); 
    }
    else 
    {
         hGPR_Off(GPRNumber);
    }
}   

void hGPR_Off(uint8_t GPRNumber)
{
    mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_RedColor],Low);
    mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_GreenColor],Low);
    mDIO_WritePin(GPRGroup[GPRNumber-1],GPRPin[GPRNumber-1][GPR_BlueColor],Low);
}