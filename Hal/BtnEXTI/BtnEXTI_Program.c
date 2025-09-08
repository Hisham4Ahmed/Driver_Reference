/**
 * @file BtnEXTI_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "../../Common/Config.h"

#if BtnEXTI_Driver==Enable

#include "BtnEXTI_Interface.h"


void hBtnExti_Init   (uint8_t BtnNo)
{
    // Check on BtnNo
    // Set Direction as Input 
    // Enable Pull up 
    // EXTI Init 
    if(BtnNo==Button1)
    {
        mDIO_SetDirectionForPin(Button1_Group,Button1_Pin,Input);
        mDIO_WritePin(Button1_Group,Button1_Pin,High);
        mEXTI0_Init(Button1_SensControl);
    }
    else if (BtnNo==Button2)
    {
        mDIO_SetDirectionForPin(Button2_Group,Button2_Pin,Input);
        mDIO_WritePin(Button2_Group,Button2_Pin,High);
        mEXTI1_Init(Button2_SensControl);
    }
    else if (BtnNo==Button3)
    {
        mDIO_SetDirectionForPin(Button3_Group,Button3_Pin,Input);
        mDIO_WritePin(Button3_Group,Button3_Pin,High);
        mEXTI2_Init(Button3_SensControl);
    }
    else  
    {
        /** @todo  : Handle the BtnNo Out Of Range */
    }
}


void hBtnExti_Handler(uint8_t BtnNo , void(*PF)(void))
{
    // Pass the Action function to ISR 
    if(PF!=Null)
    {
        if(BtnNo==Button1)
        {
            mEXTI0_CallBackFunction(PF);
        }
        else if (BtnNo==Button2)
        {
            mEXTI1_CallBackFunction(PF);
        }
        else if (BtnNo==Button3)
        {
            mEXTI2_CallBackFunction(PF);
        }
        else 
        {
            /** @todo  : Handle the BtnNo Out Of Range */
        }
        
    }
    else 
    {
      /** @todo  : Handle the PF Is Null  */

    }
}
#endif /*BtnEXTI_Driver*/