/**
 * @file BtnEXTI_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _BTNEXTI_INTERFACE_H
#define _BTNEXTI_INTERFACE_H

#include <stdint.h> 
#include "../../Common/Macros.h"
#include "../../Mcal/EXTI/EXTI_Interface.h"
#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/GIE/GIE.h"


#include "BtnEXTI_Private.h"
#include "BtnEXTI_Config.h"


/**
 * @fn             hBtnExti_Init
 * @brief          This Function shall be Init the EXTILine & Set EXTI Pin as Input  & Enable the Internal Pull 
 * @param BtnNo    This Parameter Detect which Button you Will Use  
 *                 BtnNo : Shall be on of this Options  (Button1 / Button2 / Button3)
 */
void hBtnExti_Init   (uint8_t BtnNo);
/**
 * @fn                hBtnExti_Handler
 * @brief             This Function shall be Pass the Action From App Into EXTI ISR 
 * @param BtnNo       This Parameter Detect which Button you Will Use  
 *                    BtnNo : Shall be on of this Options  (Button1 / Button2 / Button3)
 * @param PF          Pointer to Function will Point to the Action will be Execute when the Interrupt Happen 
 */
void hBtnExti_Handler(uint8_t BtnNo , void(*PF)(void));




#endif  /*_BTNEXTI_INTERFACE_H_*/