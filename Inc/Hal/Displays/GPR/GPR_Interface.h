/**
 * @file   GPR_Interface.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _GPR_INTERFACE_H
#define _GPR_INTERFACE_H
#include <stdint.h>
#include "../../../Common/Macros.h"
#include "../../../Mcal/DIO/DIO_Interface.h"
#include "GPR_Private.h"
#include "GPR_Config.h"




void hGPR_Init(uint8_t GPRNumber);

void hGPR_On(uint8_t GPRNumber, uint8_t Color);

void hGPR_Off(uint8_t GPRNumber);
#endif