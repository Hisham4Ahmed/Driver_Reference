/**
 * @file Btn_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-02
 * 
 * @copyright Copyright (c) 2025
 * @note  This Driver Support 4 Button Only
 * @note  Driver Support Internal Pull Up Connection Only
 * @note  if you need add new button Please Follow this Steps : 
 *      - Increament the Btn_MaxNo By 1 
 *      - Add New Macro for Button Number -> Called    BtnX  
 *      - Add New Macro for Button Group  -> Called    BtnX_Group 
 *      - Add New Macro for Button Pin    -> Called    BtnX_Pin 
 *      - Update the BtnGroupValue By BtnX_Group 
 *      - Update the BtnPinValue   By BtnX_Pin
 *      - X is Indecate to Button Number 
 */

#pragma once 


#include "../../Mcal/DIO/DIO_Private.h"
#include "Btn_Private.h"

#define Btn_MaxNo         3

#define Btn1              1
#define Btn1_Group        GroupA 
#define Btn1_Pin          Pin0 


#define Btn2              2
#define Btn2_Group        GroupA
#define Btn2_Pin          Pin1



#define Btn3              3
#define Btn3_Group        GroupA
#define Btn3_Pin          Pin2

#define Btn4              4
#define Btn4_Group        GroupA
#define Btn4_Pin          Pin3



#define BtnGroupValue         {Btn1_Group,Btn2_Group,Btn3_Group,Btn4_Group}
#define BtnPinValue           {Btn1_Pin,Btn2_Pin,Btn3_Pin,Btn4_Pin}