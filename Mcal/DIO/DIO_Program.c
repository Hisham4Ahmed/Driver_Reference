/**
 * @file DIO_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#include "../../Common/Config.h"
#if DIO_Driver ==Enable

#include "DIO_Interface.h"

// DirectionState Shall be from following options :
// - in SetDirectionForPin the Option will be (Input , Output)
// - in SetDirectionForGroup the Value Shall be from this Range 0 : 255

void mDIO_SetDirectionForPin(uint8_t GroupName,uint8_t PinNumber ,uint8_t DirectionState)
{
    if(PinNumber >= Pin0 && PinNumber<=Pin7)
    {
        if(DirectionState==Input)
        {
            switch(GroupName)
            {
                case GroupA: ClearBit(DDRA_Reg,PinNumber);break;
                case GroupB: ClearBit(DDRB_Reg,PinNumber);break;
                case GroupC: ClearBit(DDRC_Reg,PinNumber);break;
                case GroupD: ClearBit(DDRD_Reg,PinNumber);break;
                default: 
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
                
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
                default:
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
            }

        }
        else 
        {
            /**
             * @todo Hanle the Direction Not Vaild 
             * 
             */
        }
    }
    else 
    {
        /**
         * @todo  Handle the PinNumber NotVaild 
         * 
         */
    }
}   

void mDIO_SetDirectionForGroup(uint8_t GroupName,uint8_t DirectionState)
{
    if(DirectionState>=0x00&&DirectionState<=0xFF)
    {
        switch(GroupName)
        {
            case GroupA: DDRA_Reg=DirectionState;break;
            case GroupB: DDRB_Reg=DirectionState;break;
            case GroupC: DDRC_Reg=DirectionState;break;
            case GroupD: DDRD_Reg=DirectionState;break;
            default :
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
        }
    }
    else 
    {
        /**
         * @todo Handle Direction State Out of Range 
         * 
         */
        
    }
}



// OutputValue Shall be from following options :
// - in mDIO_WritePin the Option will be (Low , High)
// - in mDIO_WriteGroup the Value Shall be from this Range 0 : 255

void mDIO_WritePin(uint8_t GroupName,uint8_t PinNumber ,uint8_t OutputValue)
{
    if(PinNumber>=Pin0 && PinNumber<=Pin7)
    {
        if(OutputValue==Low)
        {
            // PORT    0 in Specific Bit   -> 0 = ClearBit(PORT reg, Specific pin)
            switch(GroupName)
            {
                case GroupA:ClearBit(PORTA_Reg,PinNumber);break;
                case GroupB:ClearBit(PORTB_Reg,PinNumber);break;
                case GroupC:ClearBit(PORTC_Reg,PinNumber);break;
                case GroupD:ClearBit(PORTD_Reg,PinNumber);break;
                default : 
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
                
            }
        }
        else if (OutputValue==High)
        {
            // PORT Reg   1 in Specific Bit   -> 1 = SetBit(PORT reg, Specific pin)
            switch(GroupName)
            {
                case GroupA:SetBit(PORTA_Reg,PinNumber);break;
                case GroupB:SetBit(PORTB_Reg,PinNumber);break;
                case GroupC:SetBit(PORTC_Reg,PinNumber);break;
                case GroupD:SetBit(PORTD_Reg,PinNumber);break;
                default : 
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
            }
        }
        else
        {
            /**
             * @todo Handle the OutputValue Not Vaild 
             * 
             */
        }
    }
    else 
    {
        /**
         * @todo Handle the PinNumber Not Vaild 
         * 
         */
    }
}
void mDIO_WriteGroup(uint8_t GroupName,uint8_t OutputValue)
{
    if(OutputValue>=0x00&&OutputValue<=0xFF)
    {
        switch(GroupName)
        {
            case GroupA: PORTA_Reg=OutputValue;break;
            case GroupB: PORTB_Reg=OutputValue;break;
            case GroupC: PORTC_Reg=OutputValue;break;
            case GroupD: PORTD_Reg=OutputValue;break;
            default :  
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;

        }
    }
    else
    {
        /**
         * @todo Handle if the Outputvalue out of range 
         * 
         */
    }
}



void mDIO_TogglePin(uint8_t GroupName,uint8_t PinNumber )
{
    if(PinNumber>=Pin0&&PinNumber<=Pin7)
    {
        switch(GroupName)
        {
            case GroupA:ToggleBit(PORTA_Reg,PinNumber);break;
            case GroupB:ToggleBit(PORTB_Reg,PinNumber);break;
            case GroupC:ToggleBit(PORTC_Reg,PinNumber);break;
            case GroupD:ToggleBit(PORTD_Reg,PinNumber);break;
            default :
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
        }
    }
    else 
    {
        /**
         * @todo Handle the PinNumber not Vaild  
         * 
         */
    }
}




void mDIO_ReadPin(uint8_t GroupName,uint8_t PinNumber ,uint8_t *InputValue)
{
    if(InputValue!=Null)
    {
        if(PinNumber>=Pin0&&PinNumber<=Pin7)
        {
            switch(GroupName)
            {
                case GroupA: *InputValue=GetBit(PINA_Reg,PinNumber);break;
                case GroupB: *InputValue=GetBit(PINB_Reg,PinNumber);break;
                case GroupC: *InputValue=GetBit(PINC_Reg,PinNumber);break;
                case GroupD: *InputValue=GetBit(PIND_Reg,PinNumber);break;
                default : 
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;

            }
        }
        else 
        {
        /**
         * @todo Handle the Pinnumber  is not Vaild 
         * 
         */  
        }
    }
    else 
    {
        /**
         * @todo Handle the Pointer is Null
         * 
         */
    }
}

void mDIO_ReadGroup(uint8_t GroupName,uint8_t *InputValue)
{
    if(InputValue!=Null)
    {
        switch(GroupName)
        {
            case GroupA : *InputValue=PINA_Reg;break;
            case GroupB : *InputValue=PINA_Reg;break;
            case GroupC : *InputValue=PINA_Reg;break;
            case GroupD : *InputValue=PINA_Reg;break;
            default : 
                    /**
                    * @todo Handle if the GroupName Not Vaild 
                    * 
                    */
                   break;
        }
    }
    else
    {
        /**
         * @todo Handle the Pointer is Null
         * 
         */
    }
}

#endif 