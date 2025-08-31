/**
 * @file Lcd_Config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once 
#include "../../Mcal/DIO/DIO_Private.h"
#include "Lcd_Private.h"
// Lcd Mode


// _4BitMode      _8BitMode 
#define Lcd_Mode      _4BitMode 


// Lcd Control Pin and Groups
/* RS -> Register Select  (Lcd_8BitMode_OneLine_5x10SizeInstruction / Display)
   RS = 0  -> Instruction           RS =1   -> Display 
   
   RW -> Read Write Select 
   RW = 0 -> Write                RW = 1  Read 
 
   E  -> Enable Pin 
    Generate Pulse 
*/

#define Lcd_RSGroup    GroupA     
#define Lcd_RSPin      Pin0

#define Lcd_RWGroup    GroupA
#define Lcd_RWPin      Pin1

#define Lcd_EGroup     GroupA  
#define Lcd_EPin       Pin2



// Lcd Data Pin and Groups
#if Lcd_Mode == _8BitMode
    #define Lcd_DataGroup   GroupC 

#elif Lcd_Mode==_4BitMode
    #define Lcd_D4Group     GroupA 
    #define Lcd_D4Pin       Pin5

    #define Lcd_D5Group     GroupA
    #define Lcd_D5Pin       Pin7
    
    #define Lcd_D6Group     GroupC
    #define Lcd_D6Pin       Pin0
    
    #define Lcd_D7Group     GroupD
    #define Lcd_D7Pin       Pin7

#endif /*Lcd_Mode */


/*Entery Set Mode Config 
    Options: 
        Lcd_CursorMoveToRight  
        Lcd_CursorMoveToLeft   
        Lcd_ShiftDisplayToLeft 
        Lcd_ShiftDisplayToRight
*/

#define Lcd_EntrySet       Lcd_CursorMoveToRight



/*  Display Contol
    Options:
        Lcd_DisplayOff 
        Lcd_DisplayOn  
        Lcd_CursorOn   
        Lcd_CursorBlink
*/
#define Lcd_DisplayControl     Lcd_CursorBlink


/* Function Set 
   Options: 
      Lcd_4BitMode_OneLine_5x7Size 
      Lcd_4BitMode_OneLine_5x10Size
      Lcd_4BitMode_TwoLine_5x7Size 
      Lcd_4BitMode_TwoLine_5x10Size
      Lcd_8BitMode_OneLine_5x7Size 
      Lcd_8BitMode_OneLine_5x10Size
      Lcd_8BitMode_TwoLine_5x7Size 
      Lcd_8BitMode_TwoLine_5x10Size  

 */

#define Lcd_FunctionSet   Lcd_4BitMode_TwoLine_5x7Size