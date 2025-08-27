/**
 * @file SSD_Config.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * @note  This Recommend to Use as Maxmuim 2 SSD 
 *  if you need add new SSD  please Follow this Steps 
 * 
 *  - Add New macro for SSD  Number this Called           SSDn
 *  - Add New mcaro for Data Group and this called        SSDn_DataGroup
 *  - Add New macro for Enable Pin and this called        SSDn_EnablePin 
 *  - Add New macro for Enable Group and this called      SSDn_EnableGroup 
 *  - Add New macro for Type Connection and this called   SSDn_TypeConnection 

 *  - n is indecate to SSD  Number 
 *  - Update the SSD_TypeConnectionValue by New SSDn_TypeConnection 
 *  - Update the SSD_EnablePinValue      by New SSDn_EnablePin 
 *  - Update the SSD_EnableGroupValue    by New SSDn_EnableGroup 
 *  - Update the SSD_DataGroupValue      by New SSDn_DataGroup 

 */

#ifndef _SSD_CONFIG_H_
#define _SSD_CONFIG_H_ 

#include "../../Mcal/DIO/DIO_Interface.h"
#include "SSD_Private.h"


#define SSD_MaxNo                        2 

#define SSD1                            1 
#define SSD1_TypeConnection             SSD_CommonCathod
#define SSD1_EnablePin                  Pin7
#define SSD1_EnableGroup                GroupC
#define SSD1_DataGroup                  GroupA 



#define SSD2                            2 
#define SSD2_TypeConnection             SSD_CommonAnode
#define SSD2_EnablePin                  Pin0
#define SSD2_EnableGroup                GroupD
#define SSD2_DataGroup                  GroupB





#define SSD_TypeConnectionValue               {SSD1_TypeConnection,SSD2_TypeConnection}
#define SSD_EnablePinValue                    {SSD1_EnablePin,SSD2_EnablePin}
#define SSD_EnableGroupValue                  {SSD1_EnableGroup,SSD2_EnableGroup}
#define SSD_DataGroupValue                    {SSD1_DataGroup,SSD2_DataGroup}






#endif 