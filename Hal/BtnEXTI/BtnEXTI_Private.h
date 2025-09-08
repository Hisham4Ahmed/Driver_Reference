/**
 * @file BtnEXTI_Private.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _BtnEXTI_PRIVATE_H_
#define _BtnEXTI_PRIVATE_H_
#include "../../Mcal/DIO/DIO_Private.h"
#define Button1            1 // Connect with EXTI0
#define Button1_Pin        Pin2
#define Button1_Group      GroupD

#define Button2            2 // Connect with EXTI1
#define Button2_Pin        Pin3
#define Button2_Group      GroupD

#define Button3            3 // Connect with EXTI2
#define Button3_Pin        Pin2 
#define Button3_Group      GroupB

#endif /*_BtnEXTI_PRIVATE_H_*/