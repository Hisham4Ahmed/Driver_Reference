/**
 * @file Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once 

#include "Macros.h"
/*Mcal Drivers*/

#define DIO_Driver          Enable 
#define EXTI_Driver         Enable
#define GIE_Driver          Enable

/*Hal Drivers*/

#define Led_Driver          Enable 
#define RGB_Driver          Disable 
#define SSD_Driver          Disable 
#define LCD_Driver          Disable 
#define Btn_Driver          Disable 
#define Keypad_Driver       Disable 
#define BtnEXTI_Driver      Enable 
