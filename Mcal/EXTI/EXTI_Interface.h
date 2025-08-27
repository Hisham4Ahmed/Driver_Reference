/**
 * @file EXTI_Interface.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * @note 
 *  To Use this Driver Correctly Please follow the Following Steps: 
 *  1- Set Direction for the EXTI Pin you Will Use :
 *     -if you Use EXTI0  Must Set the Pin 2 in GroupD as Input 
 *     -if you Use EXTI1  Must Set the Pin 3 in GroupD as Input 
 *     -if you Use EXTI2  Must Set the Pin 2 in GroupB as Input 
 *  2- Call the Call Back Function For your EXTI Will Use 
 *     -if you Use EXTI0  Will Call this Function mEXTI0_CallBackFunction
 *     -if you Use EXTI1  Will Call this Function mEXTI1_CallBackFunction
 *     -if you Use EXTI2  Will Call this Function mEXTI2_CallBackFunction
 *  3- Call the Init Fuinction For EXTI you will Use With Select the SensControl :
 *     -if you Use EXTI0  Will Call this Function mEXTI0_Init and Sens Control Option Will Be (EXTI_LowLevel/EXTI_AnyChange/EXTI_FallingEdge/EXTI_RisingEdge )
 *     -if you Use EXTI1  Will Call this Function mEXTI1_Init and Sens Control Option Will Be (EXTI_LowLevel/EXTI_AnyChange/EXTI_FallingEdge/EXTI_RisingEdge )
 *     -if you Use EXTI2  Will Call this Function mEXTI2_Init and Sens Control Option Will Be (EXTI_FallingEdge/EXTI_RisingEdge )
 *  4- Call the mGIE_Enable
 */
 
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
#include <stdint.h>
#include "../RegistersAddress.h"
#include "../../Common/Macros.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"


void mEXTI0_Init(uint8_t SensControl);
void mEXTI1_Init(uint8_t SensControl);
void mEXTI2_Init(uint8_t SensControl);


void mEXTI0_CallBackFunction(void(*PF)(void));
void mEXTI1_CallBackFunction(void(*PF)(void));
void mEXTI2_CallBackFunction(void(*PF)(void));


void mEXTI0_Disable();
void mEXTI1_Disable();
void mEXTI2_Disable();

#endif /*_EXTI_INTERFACE_H_*/