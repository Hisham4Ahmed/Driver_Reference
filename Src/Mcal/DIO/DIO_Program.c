/**
 * @file DIO_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include "../../../Inc/Mcal/DIO/DIO_Interface.h"


void mDIO_SetDirectionForPin(uint8_t GroupName,uint8_t PinNumber,uint8_t DirectionState)
{
    if(PinNumber>=Pin0 && PinNumber<=Pin7)
    {
        if(DirectionState==Input)
        {
            switch(GroupName)
            {
                case GroupA: ClearBit(DDRA_Reg,PinNumber);break;
                case GroupB: ClearBit(DDRB_Reg,PinNumber);break;
                case GroupC: ClearBit(DDRC_Reg,PinNumber);break;
                case GroupD: ClearBit(DDRD_Reg,PinNumber);break;
                // default : break;
            }
        }
        else if (DirectionState==Output)
        {
            switch(GroupName)
            {
                case GroupA: SetBit(DDRA_Reg,PinNumber);break;
                case GroupB: SetBit(DDRB_Reg,PinNumber);break;
                case GroupC: SetBit(DDRC_Reg,PinNumber);break;
                case GroupD: SetBit(DDRD_Reg,PinNumber);break;
                // default : break;
            }
        }
        else 
        {
            // Error (Not Vaild Direction State )
        }
    }
    else
    {
        // Error (Not Vaild Pin Number )
    }

}


void mDIO_SetDirectionForGroup(uint8_t GroupName,uint8_t DirectionState)
{
    if(DirectionState>=0&&DirectionState<=255)
    {
        switch(GroupName)
        {
            case GroupA: DDRA_Reg=DirectionState;break;
            case GroupB: DDRB_Reg=DirectionState;break; 
            case GroupC: DDRC_Reg=DirectionState;break;
            case GroupD: DDRD_Reg=DirectionState;break;
        }
    }
    else
    {
        // Errot Not Vaild Direction Value 
    }
}


void mDIO_WritePin(uint8_t GroupName,uint8_t PinNumber,uint8_t OutputValue)
{
    if(PinNumber>=Pin0 && PinNumber<=Pin7)
    {
        if(OutputValue==Low) // LOW-> 0 -> ClearBit  (PORT)
        {
            switch(GroupName)
            {
                case GroupA:  ClearBit(PORTA_Reg,PinNumber);break; 
                case GroupB:  ClearBit(PORTB_Reg,PinNumber);break;
                case GroupC:  ClearBit(PORTC_Reg,PinNumber);break;
                case GroupD:  ClearBit(PORTD_Reg,PinNumber);break;
            }
        }
        else if (OutputValue==High)// High-> 1 -> SetBit  (PORT)
        {
            switch(GroupName) 
            {
                case GroupA:  SetBit(PORTA_Reg,PinNumber);break; 
                case GroupB:  SetBit(PORTB_Reg,PinNumber);break;
                case GroupC:  SetBit(PORTC_Reg,PinNumber);break;
                case GroupD:  SetBit(PORTD_Reg,PinNumber);break;
            }
        }
        else
        {

        }
    }
    else
    {

    }
}

void mDIO_WriteGroup(uint8_t GroupName,uint8_t OutputValues)
{
    if(OutputValues>=0 && OutputValues<=255)
    {
        switch(GroupName)
        {
            case GroupA: PORTA_Reg=OutputValues;break; 
            case GroupB: PORTB_Reg=OutputValues;break;
            case GroupC: PORTC_Reg=OutputValues;break;
            case GroupD: PORTD_Reg=OutputValues;break;
            
        }
    }
    else
    {

    }
}



void mDIO_TogglePin(uint8_t GroupName,uint8_t PinNumber)
{
    if(PinNumber>=Pin0&&PinNumber<=Pin7)
    {
        switch(GroupName)
        {
            case GroupA: ToggleBit(PORTA_Reg,PinNumber);break;
            case GroupB: ToggleBit(PORTB_Reg,PinNumber);break;
            case GroupC: ToggleBit(PORTC_Reg,PinNumber);break;
            case GroupD: ToggleBit(PORTD_Reg,PinNumber);break;
            
        }
    }
}



uint8_t mDIO_ReadPin(uint8_t GroupName,uint8_t PinNumber)
{
    uint8_t BitState  = 0 ; 
    if(PinNumber>=Pin0 && PinNumber <=Pin7)
    {
        switch(GroupName) // PIN
        {
            case GroupA:  return  (GetBit(PINA_Reg,PinNumber));
            case GroupB:  return  (GetBit(PINB_Reg,PinNumber));
            case GroupC:  return  (GetBit(PINC_Reg,PinNumber));
            case GroupD:  return  (GetBit(PIND_Reg,PinNumber));
        }
    }
    else
    {

    }
    return 255 ; 
}

uint8_t mDIO_ReadGroup(uint8_t GroupName)
{
    switch(GroupName)
    {
        case GroupA : return PINA_Reg;
        case GroupB : return PINB_Reg;
        case GroupC : return PINC_Reg;
        case GroupD : return PIND_Reg;
    }
}

