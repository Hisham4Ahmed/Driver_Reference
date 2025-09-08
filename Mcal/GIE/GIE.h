/**
 * @file   GIE.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _GIE_H_
#define _GIE_H_
#include "../../Common/Config.h"
#if GIE_Driver==Enable
#include <stdint.h>
#include "../RegistersAddress.h"
#include "../../Common/Macros.h"


#define I_Bit    7 

#define mGIE_Enable()       SetBit(SREG_Reg,I_Bit)
#define mGIE_Diable()       ClearBit(SREG_Reg,I_Bit)
 
#endif /*GIE_Driver*/
#endif/*_GIE_H_*/