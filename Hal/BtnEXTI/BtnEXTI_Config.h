/**
 * @file   BtnEXTI_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once
#include "../../Mcal/EXTI/EXTI_Private.h"

/**
 * EXTI_AnyChange   
 * EXTI_FallingEdge
 * EXTI_RisingEdge  
 * */
#define Button1_SensControl EXTI_FallingEdge
/**
 * EXTI_AnyChange   
 * EXTI_FallingEdge
 * EXTI_RisingEdge  
 * */
#define Button2_SensControl EXTI_FallingEdge
/*
 * EXTI_FallingEdge
 * EXTI_RisingEdge  
 * */
#define Button3_SensControl EXTI_FallingEdge