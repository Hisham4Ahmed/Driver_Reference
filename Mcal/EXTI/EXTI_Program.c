/**
 * @file  EXTI_Program.c
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#include "../../Common/Config.h"
#if EXTI_Driver ==Enable

#include "EXTI_Interface.h"

static void(*EXTI0_ISRHandler)(void)=Null;
static void(*EXTI1_ISRHandler)(void)=Null;
static void(*EXTI2_ISRHandler)(void)=Null;

// --------------------------------------------------------------------------------------------------------------
void mEXTI0_Init(uint8_t SensControl)
{
    uint8_t  SensControlState = False ;
    // Check on the Sens Control is Vaild 
    // if Sens Control = Low level    => these bits (ISC01&ISC00) Must Be Zero's (ClearBit)
     if(SensControl==EXTI_LowLevel)
     {

        ClearBit(MCUCR_Reg,ISC00_Bit);
        ClearBit(MCUCR_Reg,ISC01_Bit);
        SensControlState=True;
     }
    // if Sens Control = Any logical  => The ISC00 Bit Must Be One  (SetBit)   & The ISC01 Bit Must Be Zero (Clear)
    else if(SensControl==EXTI_AnyChange)
    {
        SetBit(MCUCR_Reg,ISC00_Bit);
        ClearBit(MCUCR_Reg,ISC01_Bit);
        SensControlState=True;
    }
    // if Sens Control = falling edge => The ISC00 Bit Must Be Zero (ClearBit) & The ISC01 Bit Must Be One (Set)
    else if(SensControl==EXTI_FallingEdge)
    {
        ClearBit(MCUCR_Reg,ISC00_Bit);
        SetBit(MCUCR_Reg,ISC01_Bit);
        SensControlState=True;
    }
    // if Sens Control = rising edge  => these bits (ISC01&ISC00) Must Be One's (SetBit)
    else if(SensControl==EXTI_RisingEdge)
    {

        SetBit(MCUCR_Reg,ISC00_Bit);
        SetBit(MCUCR_Reg,ISC01_Bit);
        SensControlState=True;
    }
    // else todo handle senscontrol for EXTI0 OutofRange
    else
    {
        /**
         * @todo handle senscontrol for EXTI0 Out of Range
         * 
         */
         SensControlState=False;
    }
    // Enable for External Interrupt 0  => this Bit INT0 Must one if the Senscontrol is Set Correctly 
    if(SensControlState==True)
    {
        SetBit(GICR_Reg,INT0_Bit);
    }
}
void mEXTI0_Disable()
{
    // Disable for External Interrupt 0  => INT0 Must be Zero (Clear)
    ClearBit(GICR_Reg,INT0_Bit);
}
void mEXTI0_CallBackFunction(void(*PF)(void))
{
    // Check on PF not Equal Null 
    if(PF!=Null)
    {
        // Update the Global Pointer To Function 
        EXTI0_ISRHandler=PF;
    }
    else
    {
        /**
         * @todo handle PF Is Equal Null 
         * 
         */
    }
}
void __vector_1(void)
{
    // Check  on  Global Pointer To Function not Equal Null 
    if(EXTI0_ISRHandler!=Null)
    {
       // Call for  Global Pointer To Function
       EXTI0_ISRHandler();
    }
    else
    {
        /**
         * @todo handle EXTI0_ISRHandler Is Equal Null 
         * 
         */
    }
}
// --------------------------------------------------------------------------------------------------------------


void mEXTI1_Init(uint8_t SensControl)
{
    uint8_t SensControlState=False;
    // check on sens Control 
    // if  SensControl = Low level    => These Bits (ISC11&ISC10)Must be Zero  
    if(SensControl==EXTI_LowLevel)
    {
        ClearBit(MCUCR_Reg,ISC10_Bit);
        ClearBit(MCUCR_Reg,ISC11_Bit);
        SensControlState=True;
    }
    // if  SensControl = Any logical  => The ISC10 Must Be one  & the ISC11 Must be Zero 
    else if(SensControl==EXTI_AnyChange)
    {
        SetBit(MCUCR_Reg,ISC10_Bit);
        ClearBit(MCUCR_Reg,ISC11_Bit);
        SensControlState=True;
    }
    // if  SensControl =falling edge  => The ISC10 Must Be Zero & the ISC11 Must be one 
    else if(SensControl==EXTI_FallingEdge)
    {
        ClearBit(MCUCR_Reg,ISC10_Bit);
        SetBit(MCUCR_Reg,ISC11_Bit);
        SensControlState=True;
    }
    // if  SensControl = rising edge  => These Bits (ISC11&ISC10)Must be One 
    else if(SensControl==EXTI_RisingEdge)
    {
        SetBit(MCUCR_Reg,ISC10_Bit);
        SetBit(MCUCR_Reg,ISC11_Bit);
        SensControlState=True;
    }
    else
    {
        /**
         * @todo Handle the Sens Control For Interrupt 1 Out of Range 
         * 
         */
        SensControlState=False;
    }
    // Enable the External interrupt 1 if the SensControl Set Correctly
    if(SensControlState==True)
    {
        // this INT1 Bit in GICR  must be 1  
        SetBit(GICR_Reg,INT1_Bit);
    }
}
void mEXTI1_Disable()
{
    /*Disable the EXternal Interrup 1  */
    // this INT1 Bit in GICR  must be 0  
    ClearBit(GICR_Reg,INT1_Bit);
}
void mEXTI1_CallBackFunction(void(*PF)(void))
{
    if(PF!=Null)
    {
        EXTI1_ISRHandler=PF;
    }
    else 
    {
        /**
         * @todo handle PF Is Equal Null 
         * 
         */
    }
}
void __vector_2(void)
{
    // Check if the EXTI1_ISRHandle Is Not Equal Null 
    if(EXTI1_ISRHandler!=Null)
    {
        // Call for the EXTI1_ISRHandle
        EXTI1_ISRHandler();
    }
    else
    {
        /**
         * @todo handle EXTI1_ISRHandler Is Equal Null 
         * 
         */
    }
}

// --------------------------------------------------------------------------------------------------------------

void mEXTI2_Init(uint8_t SensControl)
{
    uint8_t SensControlState=False;
    // check on sens Control for Interrupt 2 
    // if SensControl=  Falling edge => the ISC2 Bit in MCUCSR Reg Must be 0 
    if(SensControl==EXTI_FallingEdge)
    {
        ClearBit(MCUCSR_Reg,ISC2_Bit);
        SensControlState=True;
    }
    // if SensControl=  Rising edge => the ISC2 Bit in MCUCSR Reg Must be 1
    else if(SensControl==EXTI_RisingEdge)
    {
        SetBit(MCUCSR_Reg,ISC2_Bit);
        SensControlState=True;
    }
    else
    {
        /**
         * @todo Handle the SensControl For Interrupt Two Not Vaild 
         * 
         */
        SensControlState=False;
    }
    // Enable the External interrupt 1 if the SensControl Set Correctly
    if(SensControlState==True)
    {
        // The INT2 Bit in GICR Reg Must Be One 
        SetBit(GICR_Reg,INT2_Bit);
    }
}
void mEXTI2_Disable()
{
    /*Disable the EXternal Interrupt 2  */
    // The INT2 Bit in GICR Reg Must Be One 
    ClearBit(GICR_Reg,INT2_Bit);
}
void mEXTI2_CallBackFunction(void(*PF)(void))
{
    if(PF!=Null)
    {
        EXTI2_ISRHandler=PF;
    }
    else
    {
        /**
         * @todo Handle the PF iS Equal Null 
         * 
         */      
    }
}

void __vector_3(void)  
{
    if(EXTI2_ISRHandler!=Null)
    {
        EXTI2_ISRHandler();
    }
    else 
    {
        /**
         * @todo Handle the EXTI2_ISRHandler iS Equal Null 
         * 
         */ 
    }
}

#endif