/**
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * @note  This Recommend to Use as Maxmuim 8 Led 
 *  if you need add new Led please Follow this Steps 
 * 
 *  - Add New macro for LedNumber this Called Ledn
 *  - Add New macro for Pin and this called   Ledn_Pin 
 *  - Add New mcaro for Group and this called Ledn_Group
 *  - n is indecate to Led Number 
 *  - Update the LedGroupValue by New Ledn_Group 

 */

#ifndef _LED_CONFIG_H_
#define _LED_CONFIG_H_ 
#include "../../Mcal/DIO/DIO_Interface.h"








#define Led_MaxNo             6 

#define Led_ConnectionType    Led_SourceConnection

#define Led1                  1 
#define Led1_Pin              Pin0
#define Led1_Group            GroupA 

#define Led2                  2
#define Led2_Pin              Pin1
#define Led2_Group            GroupA 

#define Led3                  3
#define Led3_Pin              Pin2
#define Led3_Group            GroupA 

#define Led4                  4
#define Led4_Pin              Pin3
#define Led4_Group            GroupA 

#define Led5                  5
#define Led5_Pin              Pin4
#define Led5_Group            GroupA

#define Led6                  6
#define Led6_Pin              Pin6
#define Led6_Group            GroupA

#define LedGroupValue        {Led1_Group,Led2_Group,Led3_Group,Led4_Group,Led5_Group,Led6_Group}
#define LedPinValue          {Led1_Pin,Led2_Pin,Led3_Pin,Led4_Pin,Led5_Pin,Led6_Pin}

#endif 
