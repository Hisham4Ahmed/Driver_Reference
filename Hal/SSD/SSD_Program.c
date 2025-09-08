/**
 * @file   SSD_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#include "../../Common/Config.h"
#if SSD_Driver ==Enable

#include "SSD_Interface.h"

static uint8_t SSD_TypeConnection[SSD_MaxNo]=SSD_TypeConnectionValue;
static uint8_t SSD_EnablePin[SSD_MaxNo]=SSD_EnablePinValue;
static uint8_t SSD_EnableGroup[SSD_MaxNo]=SSD_EnableGroupValue;
static uint8_t SSD_DataGroup[SSD_MaxNo]=SSD_DataGroupValue;
static uint8_t SSD_Numbers[SSD_MaxNumber]=
{
    SSD_Zero ,
    SSD_One  ,
    SSD_Two  ,
    SSD_Three,
    SSD_Four ,
    SSD_Five ,
    SSD_Six  ,
    SSD_Seven,
    SSD_Eight,
    SSD_Nine ,
};
void hSSD_Init(uint8_t SSDNumber)
{
    // check if the SSDNumber Less than or equal the SSD_MaxNo
    if(SSDNumber<=SSD_MaxNo)
    {
        // Data Group Output 
        mDIO_SetDirectionForGroup(SSD_DataGroup[SSDNumber-SSD_StartIndex],AllGroupOutput);
        // Enable Pin as Output
        mDIO_SetDirectionForPin(SSD_EnableGroup[SSDNumber-SSD_StartIndex],SSD_EnablePin[SSDNumber-SSD_StartIndex],Output);
    }
    else
    {
        /**
         * @todo Handle SSDNumber Out of Range 
         * 
         */
    }
}
void hSSD_DisplayNumber(uint8_t SSDNumber,uint8_t DisplayNumber)
{
    if(DisplayNumber>=SSD_MinNumber&& DisplayNumber<=SSD_MaxNumber)
    {
        // check if the SSDNumber Less than or equal the SSD_MaxNo
        if(SSDNumber<=SSD_MaxNo)
        {
            if(SSD_TypeConnection[SSDNumber-SSD_StartIndex]==SSD_CommonCathod)
            {
                mDIO_WriteGroup(SSD_DataGroup[SSDNumber-SSD_StartIndex],SSD_Numbers[DisplayNumber]);
            }
            else if (SSD_TypeConnection[SSDNumber-SSD_StartIndex]==SSD_CommonAnode)
            {
                mDIO_WriteGroup(SSD_DataGroup[SSDNumber-SSD_StartIndex],~(SSD_Numbers[DisplayNumber]));
            }
        }
        else
        {
            /**
             * @todo Handle SSDNumber Out of Range 
             * 
             */
        }
    }
    else 
    {
        /**
         * @todo Handle the DisplayNumber Out of Range 
         * 
         */
    }
}

void hSSD_EnableSSD(uint8_t SSDNumber)
{
    // check if the SSDNumber Less than or equal the SSD_MaxNo
    if(SSDNumber<=SSD_MaxNo)
    {
            if(SSD_TypeConnection[SSDNumber-SSD_StartIndex]==SSD_CommonCathod)
            {
                mDIO_WritePin(SSD_EnableGroup[SSDNumber-SSD_StartIndex],SSD_EnablePin[SSDNumber-SSD_StartIndex],Low);
            }
            else if (SSD_TypeConnection[SSDNumber-SSD_StartIndex]==SSD_CommonAnode)
            {
                mDIO_WritePin(SSD_EnableGroup[SSDNumber-SSD_StartIndex],SSD_EnablePin[SSDNumber-SSD_StartIndex],High);
            }
    }
    else
    {
        /**
         * @todo Handle SSDNumber Out of Range 
         * 
         */
    }
}
void hSSD_DisableSSD(uint8_t SSDNumber)
{
    // check if the SSDNumber Less than or equal the SSD_MaxNo
    if(SSDNumber<=SSD_MaxNo)
    {
        if(SSD_TypeConnection[SSDNumber-SSD_StartIndex]==SSD_CommonCathod)
        {
            mDIO_WritePin(SSD_EnableGroup[SSDNumber-SSD_StartIndex],SSD_EnablePin[SSDNumber-SSD_StartIndex],High);
        }
        else if (SSD_TypeConnection[SSDNumber-SSD_StartIndex]==SSD_CommonAnode)
        {
            mDIO_WritePin(SSD_EnableGroup[SSDNumber-SSD_StartIndex],SSD_EnablePin[SSDNumber-SSD_StartIndex],Low);
        }
    }
    else
    {
        /**
         * @todo Handle SSDNumber Out of Range 
         * 
         */
    }
}
#endif 