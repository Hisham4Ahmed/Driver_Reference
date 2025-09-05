/**
 * @file Kpd_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "Kpd_Interface.h"
#include <util/delay.h>


static uint8_t Kpd_ColoumnsGroup[Kpd_ColumnsNo]={Kpd_C0Group,Kpd_C1Group,Kpd_C2Group};
static uint8_t Kpd_ColoumnsPin[Kpd_ColumnsNo]={Kpd_C0Pin,Kpd_C1Pin,Kpd_C2Pin};

static uint8_t Kpd_RowGroup[Kpd_RowsNo]={Kpd_R0Group,Kpd_R1Group,Kpd_R2Group,Kpd_R3Group};
static uint8_t Kpd_RowPin[Kpd_RowsNo]={Kpd_R0Pin,Kpd_R1Pin,Kpd_R2Pin,Kpd_R3Pin};


static uint8_t Kpd_KeysValue[Kpd_RowsNo][Kpd_ColumnsNo]=Kpd_KeyValue;


void hKeypad_Init(void)
{
    uint8_t Counter = 0 ; 
    // Columns as Input & Internal Pull UP
    for(Counter=0;Counter<Kpd_ColumnsNo;Counter++)
    {
        mDIO_SetDirectionForPin(Kpd_ColoumnsGroup[Counter],Kpd_ColoumnsPin[Counter],Input);
        mDIO_WritePin(Kpd_ColoumnsGroup[Counter],Kpd_ColoumnsPin[Counter],High);
    }
    // Row as Output & Initaial Value VCC 
    for(Counter=0;Counter<Kpd_RowsNo;Counter++)
    {
        mDIO_SetDirectionForPin(Kpd_RowGroup[Counter],Kpd_RowPin[Counter],Output);
        mDIO_WritePin(Kpd_RowGroup[Counter],Kpd_RowPin[Counter],High);
    }
}



uint8_t hKeypad_GetPressedKey(void)
{
    uint8_t Kpd_Value = Kpd_NoKeyPressed;
    uint8_t Columns_Counter = 0 ; 
    uint8_t Rows_Counter = 0  ; 
    uint8_t BtnState     = 0 ;

    for(Rows_Counter=0;Rows_Counter<Kpd_RowsNo;Rows_Counter++)
    {
        mDIO_WritePin(Kpd_RowGroup[Rows_Counter],Kpd_RowPin[Rows_Counter],Low);
        for (Columns_Counter = 0 ; Columns_Counter < Kpd_ColumnsNo ; Columns_Counter++)
        {
            mDIO_ReadPin(Kpd_ColoumnsGroup[Columns_Counter],Kpd_ColoumnsPin[Columns_Counter], &BtnState );
            if(BtnState == Kpd_BtnPressed )
            {
                // Kpd Value 
                Kpd_Value = Kpd_KeysValue[Rows_Counter][Columns_Counter];
                mDIO_WritePin(Kpd_RowGroup[Rows_Counter],Kpd_RowPin[Rows_Counter],High);
                _delay_ms(100);
                return Kpd_Value;
            }
        }
        mDIO_WritePin(Kpd_RowGroup[Rows_Counter],Kpd_RowPin[Rows_Counter],High);
    }
    return Kpd_Value; 
}
