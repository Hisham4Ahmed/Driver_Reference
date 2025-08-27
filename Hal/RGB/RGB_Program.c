/**
 * @file RGB_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */


#include "RGB_Interface.h"


static uint8_t RGBGroup[RGB_MaxNo]=RGB_GreenPinValue;
static uint8_t RGBRedPin[RGB_MaxNo]=RGB_RedPinValue;
static uint8_t RGBGreenPin[RGB_MaxNo]=RGB_GreenPinValue;
static uint8_t RGBBluePin[RGB_MaxNo]=RGB_GreenPinValue;
void mRGB_Init(uint8_t RGBLedNumber)
{
    if(RGBLedNumber<=RGB_MaxNo)
    {
    mDIO_SetDirectionForPin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBRedPin[RGBLedNumber-RGB_StartIndex],Output);
    mDIO_SetDirectionForPin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBGreenPin[RGBLedNumber-RGB_StartIndex],Output);
    mDIO_SetDirectionForPin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBBluePin[RGBLedNumber-RGB_StartIndex],Output);
    }
    else
    {
        /**
         * @todo Handle the RGB Led Out Of Range 
         * 
         */
    }
}
void mRGB_Off(uint8_t RGBLedNumber)
{
    if(RGBLedNumber<=RGB_MaxNo)
    {
        mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBRedPin[RGBLedNumber-RGB_StartIndex],Low);
        mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBGreenPin[RGBLedNumber-RGB_StartIndex],Low);
        mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBBluePin[RGBLedNumber-RGB_StartIndex],Low);
    }
    else
    {
        /**
         * @todo Handle the RGB Led Out Of Range 
         * 
         */
    }
}





void mRGB_On(uint8_t RGBLedNumber,uint8_t Color )
{
    if(RGBLedNumber<=RGB_MaxNo)
    {
            if(Color==RGB_Red)
            {
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBRedPin[RGBLedNumber-RGB_StartIndex],High);
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBGreenPin[RGBLedNumber-RGB_StartIndex],Low);
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBBluePin[RGBLedNumber-RGB_StartIndex],Low);
            }
            else if (Color==RGB_Green)
            {
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBRedPin[RGBLedNumber-RGB_StartIndex],Low);
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBGreenPin[RGBLedNumber-RGB_StartIndex],High);
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBBluePin[RGBLedNumber-RGB_StartIndex],Low);

            }
            else if (Color==RGB_Blue)
            {
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBRedPin[RGBLedNumber-RGB_StartIndex],Low);
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBGreenPin[RGBLedNumber-RGB_StartIndex],Low);
                mDIO_WritePin(RGBGroup[RGBLedNumber-RGB_StartIndex],RGBBluePin[RGBLedNumber-RGB_StartIndex],High);

            }
            else
            {
                mRGB_Off(RGBLedNumber);
            }
    }
    else
    {
        /**
         * @todo Handle the RGB Led Out Of Range 
         * 
         */
    }

}
