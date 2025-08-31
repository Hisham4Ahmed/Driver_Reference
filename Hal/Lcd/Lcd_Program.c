/**
 * @file Lcd_Program.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <util/delay.h>
#include "Lcd_Interface.h"






void hLcd_SetInstructions(uint8_t Instructions)
{
    // RS -> Low
    mDIO_WritePin(Lcd_RSGroup,Lcd_RSPin,Low); 
    // RW -> Low
    mDIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);
    //Check on BitMode 
    #if Lcd_Mode==_8BitMode
        //8BitMode
            //Update the Instructions With DataGroup
            mDIO_WriteGroup(Lcd_DataGroup,Instructions);
            //E -> High 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
            //Wait for 1msec
            _delay_ms(1);
            //E -> Low 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    #elif Lcd_Mode==_4BitMode
        //4BitMode 
            //Update the High Instructions Bit(7 6 5 4) on the Data Pin (D7 D6 D5 D4) 
            mDIO_WritePin(Lcd_D4Group,Lcd_D4Pin,GetBit(Instructions,4));
            mDIO_WritePin(Lcd_D5Group,Lcd_D5Pin,GetBit(Instructions,5));
            mDIO_WritePin(Lcd_D6Group,Lcd_D6Pin,GetBit(Instructions,6));
            mDIO_WritePin(Lcd_D7Group,Lcd_D7Pin,GetBit(Instructions,7));
            //E -> High 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
            //Wait for 1msec 
            _delay_ms(1);
            //E -> Low 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
            //Update the Low Instructions Bit(3 2 1 0) on the Data Pin (D7 D6 D5 D4) 
            mDIO_WritePin(Lcd_D4Group,Lcd_D4Pin,GetBit(Instructions,0));
            mDIO_WritePin(Lcd_D5Group,Lcd_D5Pin,GetBit(Instructions,1));
            mDIO_WritePin(Lcd_D6Group,Lcd_D6Pin,GetBit(Instructions,2));
            mDIO_WritePin(Lcd_D7Group,Lcd_D7Pin,GetBit(Instructions,3));  
            //E -> High 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
            //Wait for 1msec 
            _delay_ms(1);
            //E -> Low 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    #endif
    //wait for 2msec 
    _delay_ms(2);
}
void hLcd_WriteCharacter(uint8_t Character)
{
    //RS -> High 
    mDIO_WritePin(Lcd_RSGroup,Lcd_RSPin,High);
    //RW -> Low 
    mDIO_WritePin(Lcd_RWGroup,Lcd_RWPin,Low);
    //Check on BitMode 
    #if Lcd_Mode==_8BitMode
        //8BitMode 
            //Update the Character with DataGroup 
            mDIO_WriteGroup(Lcd_DataGroup,Character);
            //E-> High 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
            //Wait 1msec
            _delay_ms(1);
            //E-> Low 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    #elif Lcd_Mode==_4BitMode
        // 4BitMode 
            //Update the High Character Bits (7 6 5 4) on the Data Pin (D7 D6 D5 D4) 
            mDIO_WritePin(Lcd_D4Group,Lcd_D4Pin,GetBit(Character,4));          
            mDIO_WritePin(Lcd_D5Group,Lcd_D5Pin,GetBit(Character,5));
            mDIO_WritePin(Lcd_D6Group,Lcd_D6Pin,GetBit(Character,6));
            mDIO_WritePin(Lcd_D7Group,Lcd_D7Pin,GetBit(Character,7));
            //E-> High 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
            //Wait 1msec
            _delay_ms(1);
            //E-> Low 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
            //Update the Low Character Bits (3 2 1 0) on the Data Pin (D7 D6 D5 D4)
            mDIO_WritePin(Lcd_D4Group,Lcd_D4Pin,GetBit(Character,0));          
            mDIO_WritePin(Lcd_D5Group,Lcd_D5Pin,GetBit(Character,1));
            mDIO_WritePin(Lcd_D6Group,Lcd_D6Pin,GetBit(Character,2));
            mDIO_WritePin(Lcd_D7Group,Lcd_D7Pin,GetBit(Character,3));
            //E-> High 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,High);
            //Wait 1msec
            _delay_ms(1);
            //E-> Low 
            mDIO_WritePin(Lcd_EGroup,Lcd_EPin,Low);
    #endif
}           
void hLcd_Init()
{
    // RS -> Output 
    mDIO_SetDirectionForPin(Lcd_RSGroup,Lcd_RSPin,Output);
    // RW -> Output 
    mDIO_SetDirectionForPin(Lcd_RWGroup,Lcd_RWPin,Output);
    // E  -> Output
    mDIO_SetDirectionForPin(Lcd_EGroup,Lcd_EPin,Output);
    //Check on BitMode 
    #if Lcd_Mode==_8BitMode
        //8BitMode 
            //Data Group as 0xff (AllGroupOutput)
            mDIO_SetDirectionForGroup(Lcd_DataGroup,AllGroupOutput);
            //wait 35msec
            _delay_ms(35);
            //Sent Function Set 
            hLcd_SetInstructions(Lcd_FunctionSet);
            //Sent Display on Off 
            hLcd_SetInstructions(Lcd_DisplayControl);
            //Sent Clear Display
            hLcd_SetInstructions(Lcd_ClearDisplay);
            //Sent Entry Mode Set 
            hLcd_SetInstructions(Lcd_EntrySet);
    #elif Lcd_Mode==_4BitMode    
        // 4BitMode
            // D4 -> Output 
            mDIO_SetDirectionForPin(Lcd_D4Group,Lcd_D4Pin,Output);
            // D5 -> Output 
            mDIO_SetDirectionForPin(Lcd_D5Group,Lcd_D5Pin,Output);          
            // D6 -> Output
            mDIO_SetDirectionForPin(Lcd_D6Group,Lcd_D6Pin,Output); 
            // D7 -> Output
            mDIO_SetDirectionForPin(Lcd_D7Group,Lcd_D7Pin,Output);
            //wait 35msec
            _delay_ms(35);
            // Sent the 0x20 Hint this Number will not work  
            // hLcd_SetInstructions(0x20);
            hLcd_SetInstructions(0x02);
            //Sent Function Set 
            hLcd_SetInstructions(Lcd_FunctionSet);
            //Sent Display on Off 
            hLcd_SetInstructions(Lcd_DisplayControl);
            //Sent Clear Display
            hLcd_SetInstructions(Lcd_ClearDisplay);
            //Sent Entry Mode Set
            hLcd_SetInstructions(Lcd_EntrySet);
    #endif
}




void hLcd_WriteString(const uint8_t * String)
{

    if(String!=Null)
    {
        while(*String!=NullChar)
        {
            hLcd_WriteCharacter(*String++);
        }
    }
}


void hLcd_MoveDigits(uint8_t LineNumber , uint8_t DigitNumber)
{
    uint8_t DDRAM_Address =  0 ;
    switch(LineNumber)
    {
        case FirstLine :   DDRAM_Address=FirstLineAddress + DigitNumber ; break;
        case SecondLine:   DDRAM_Address=SecondLineAddress+ DigitNumber ; break;
        default : break; // @todo Handle the LineNumber Is NotVaild 
    }

    hLcd_SetInstructions(Lcd_SetDDRAM  | DDRAM_Address ); 

}



void hLcd_WriteNumber(int32_t Number)
{
    int32_t Temp      = 0 ; 
    int32_t MaxDigits = 1 ; 
    uint32_t CurrentDigit = 0 ; 

    if (Number==0)
    {
        hLcd_WriteCharacter('0');
        return;
    }
    if (Number < 0 )
    {
        hLcd_WriteCharacter('-');
        Number = -Number ; 
    }
    Temp=Number;
    while(Temp>=10)
    {
        Temp =  Temp / 10 ; 
        MaxDigits = MaxDigits * 10 ; 
    }

    while(MaxDigits>0)
    {
        CurrentDigit = Number / MaxDigits ; 
        hLcd_WriteCharacter('0'+CurrentDigit);
        Number = Number % MaxDigits ;
        MaxDigits = MaxDigits / 10 ; 
    }

}



void hLcd_StoreNewPattern(uint8_t CGRAMBlockNumber, uint8_t *Pattern)
{
    // Go to CGRAM Address 
        uint8_t CGRAM_Address =  CGRAMBlockNumber * 8   ;
        hLcd_SetInstructions (Lcd_SetCGRAM | CGRAM_Address);
    // Store Pattern in CGRAM 
    for (uint8_t Counter = 0 ; Counter < 8 ;Counter++)
        {
            hLcd_WriteCharacter(Pattern[Counter]);
        }
    //Go to DDRAM
    hLcd_MoveDigits(FirstLine,0);
}



void hLcd_ClearFirstLine()
{
    hLcd_MoveDigits(FirstLine,0);
    hLcd_WriteString((uint8_t *)"                ");
    hLcd_MoveDigits(FirstLine,0);

}
void hLcd_ClearSecondLine()
{
    hLcd_MoveDigits(SecondLine,0);
    hLcd_WriteString((uint8_t *)"                ");
    hLcd_MoveDigits(SecondLine,0);
}
void hLcd_ClearScreen()
{
    // hLcd_SetInstructions(Lcd_ClearDisplay);
    hLcd_ClearFirstLine();
    hLcd_ClearSecondLine();
}


