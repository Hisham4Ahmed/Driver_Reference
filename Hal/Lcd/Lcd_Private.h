/**
 * @file Lcd_Private.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once 

#define _8BitMode 1
#define _4BitMode 2 

/*Instructions*/
//Clear
#define Lcd_ClearDisplay            0x01
//Return Home 
#define Lcd_ReturnHome              0x02 
/*Entry Set Mode  During Writing (Display)
Cursor Move    
    SH = 0  (Display Shift off  & Cursor Will Move)
        ID = 1 -> Cursor Move to Right 
        ID = 0 -> Cursor Move to Left 
Shift Display
    SH = 1 (Shifts the entire display)
        ID = 1  -> Shift Display To Left 
        ID = 0  -> Shift Display To Right
*/
#define Lcd_CursorMoveToRight       0x06
#define Lcd_CursorMoveToLeft        0x04
#define Lcd_ShiftDisplayToLeft      0x07
#define Lcd_ShiftDisplayToRight     0x05
/*Display On Off
    0 0 0 0 1 D C B
    0 0 0 0 1 1 1 0 
    D => Display State  D = 0 Displayoff / D = 1 DisplayOn
    C => Cursor State   C = 0 CursorOff / C = 1 CursorOn 
    B => Cursor Blink   B = 0 NoBlink   / B = 1  CursorBlink 
  
*/
#define Lcd_DisplayOff  0x08// Display Off & Cursor Off /Blink Off
#define Lcd_DisplayOn   0x0C// Display On & Cursor Off /Blink Off
#define Lcd_CursorOn    0x0E// Display On & Cursor On /Blink Off
#define Lcd_CursorBlink 0x0F// Display On & Cursor On /Blink On

/*Cursor or Display Shift without writing or reading display data
 * 0 0 0 1 S/C R/L 0 0
 * 0 0 0 1  1  1  0 0 .
 */
#define Lcd_ShiftsCursorToLeft            0x10
#define Lcd_ShiftsCursorToRight           0x14
#define Lcd_ShiftsEntireDisplayToLeft     0x18
#define Lcd_ShiftsEntireDisplayToRight    0x1C

/* Function Set Instruction 
    0 0 1 DL  N F 0  0
    0 0 1 1   0 1 0  0
    DL = 0 -> 4Bit mode    DL = 1 ->  8Bit Mode 
    N  = 0 -> One Line     N  = 1 ->  Two Line 
    F  = 0 -> 5x7          F  = 1 ->  5x10

*/

#define Lcd_4BitMode_OneLine_5x7Size      0x20 
#define Lcd_4BitMode_OneLine_5x10Size     0x24
#define Lcd_4BitMode_TwoLine_5x7Size      0x28
#define Lcd_4BitMode_TwoLine_5x10Size     0x2C
#define Lcd_8BitMode_OneLine_5x7Size      0x30
#define Lcd_8BitMode_OneLine_5x10Size     0x34
#define Lcd_8BitMode_TwoLine_5x7Size      0x38
#define Lcd_8BitMode_TwoLine_5x10Size     0x3C


/* CGRAM Memory 
   0 1 AC5 AC4 AC3 AC2 AC1 AC0

   ex: 
    Address    0 0 AC5 AC4 AC3 AC2 AC1 AC0
   | 
    SetCGRAM    0 1  0  0    0   0   0   0
-------------------------------------------
               0 1 AC5 AC4 AC3 AC2 AC1 AC0
            
    SetCGRAM|Address 
*/
#define Lcd_SetCGRAM      0x40



/* DDRAM Memory 
   1 AC6 AC5 AC4 AC3 AC2 AC1 AC0

   ex: 
    Address    0 AC6 AC5 AC4 AC3 AC2 AC1 AC0
   | 
    SetDDRAM   1 0  0  0    0   0   0   0
-------------------------------------------
               1 AC6 AC5 AC4 AC3 AC2 AC1 AC0

    SetDDRAM|Address 
*/
#define Lcd_SetDDRAM      0x80



/* Lines Address */
#define FirstLine     0 
#define SecondLine    1


#define FirstLineAddress     0x00 
#define SecondLineAddress    0x40