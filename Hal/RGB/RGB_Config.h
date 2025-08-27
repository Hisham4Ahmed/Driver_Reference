/**
 * @file RGB_Config.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * @note  This Recommend to Use as Maxmuim 4 Led 
 *  if you need add new RGB Led please Follow this Steps 
 * 
 *  - Add New macro for RGB LedNumber this Called RGBn
 *  - Add New mcaro for Group and this called  RGBn_Group
 *  - Add New macro for Red Pin and this called    RGBn_RedPin 
 *  - Add New macro for Green Pin and this called  RGBn_GreenPin 
 *  - Add New macro for Blue Pin and this called   RGBn_BluePin 

 *  - n is indecate to RGB Led Number 
 *  - Update the RGB_GreenPinValue by New RGBn_Group 
 *  - Update the RGB_RedPinValue   by New RGBn_RedPin 
 *  - Update the RGB_GreenPinValue by New RGBn_GreenPin 
 *  - Update the RGB_GreenPinValue by New RGBn_BluePin 

 */

#ifndef _RGB_CONFIG_H_
#define _RGB_CONFIG_H_
#include "../../Mcal/DIO/DIO_Interface.h"
// Some Point



// Driver Provide the Configuration File to Configure following Parameters:
// -  & Pin for each Led
// - to control on one RGB Led You Need 3 Pin for on Led


#define RGB_MaxNo              4



#define RGB1                  1 
#define RGB1_Group            GroupC
#define RGB1_RedPin           Pin0
#define RGB1_GreenPin         Pin1
#define RGB1_BluePin          Pin2

#define RGB2                  2 
#define RGB2_Group           GroupC
#define RGB2_RedPin          Pin3
#define RGB2_GreenPin        Pin4
#define RGB2_BluePin         Pin5
 
#define RGB3                  3 
#define RGB3_Group           GroupD
#define RGB3_RedPin          Pin0
#define RGB3_GreenPin        Pin1
#define RGB3_BluePin         Pin2

#define RGB4                  4 
#define RGB4_Group           GroupC
#define RGB4_RedPin          Pin3        
#define RGB4_GreenPin        Pin4
#define RGB4_BluePin         Pin5




#define RGBGroupValue      {RGB1_Group,RGB2_Group,RGB3_Group,RGB4_Group}
#define RGB_RedPinValue    {RGB1_RedPin,RGB2_RedPin,RGB3_RedPin,RGB4_RedPin}
#define RGB_GreenPinValue  {RGB1_GreenPin,RGB2_GreenPin,RGB3_GreenPin,RGB4_GreenPin}
#define RGB_BluePinValue   {RGB1_BluePin,RGB2_BluePin,RGB3_BluePin,RGB4_BluePin}
#endif 