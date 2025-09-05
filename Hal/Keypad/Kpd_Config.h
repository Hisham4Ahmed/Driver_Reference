/**
 * @file Kpd_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once 


#include "../../Mcal/DIO/DIO_Private.h"
#include "Kpd_Private.h"


// User Shall Provide Configuration File To Configure following Parameters:
// Group & Pin For Each Row. -  Done 
// Group & Pin For Each Column. -> 
// Key Mapping Table (Row × Column → Key Value)



#define Kpd_R0Pin      Pin0 
#define Kpd_R0Group    GroupB  

#define Kpd_R1Pin      Pin1
#define Kpd_R1Group    GroupB  

#define Kpd_R2Pin      Pin2
#define Kpd_R2Group    GroupB  

#define Kpd_R3Pin      Pin3
#define Kpd_R3Group    GroupB  



#define Kpd_C0Pin      Pin4 
#define Kpd_C0Group    GroupB  
 
#define Kpd_C1Pin      Pin5
#define Kpd_C1Group    GroupB 

#define Kpd_C2Pin      Pin6
#define Kpd_C2Group    GroupB  





#define Kpd_KeyValue                      {{'1','2','3'},\
                                           {'4','5','6'},\
                                           {'7','8','9'},\
                                           {'C','0','E'}}






