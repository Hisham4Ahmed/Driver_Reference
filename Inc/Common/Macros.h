/**
 * @file   Macros.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief  This File Use to Define The Function And Object Like Macro
 * @version 0.1
 * @date 2025-08-16
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */

#ifndef _MACROS_H_
#define _MACROS_H_


/*Function Like Macro*/

/**
 * @def     SetBit
 * @brief   This Macro Use to Make Specific Bit By One 
 */
#define SetBit(Reg,Bit)    Reg|=(1<<Bit)

#define ClearBit(Reg,Bit)  Reg&=~(1<<Bit)

#define ToggleBit(Reg,Bit)  Reg^=(1<<Bit)

#define GetBit(Reg,Bit)     ((Reg>>Bit)&0x01)

/*For Atmega*/
#define ClearFlag(Reg,FlagBit)   SetBit(Reg,FlagBit)

#define FlagState(Reg,FlagBit)   GetBit(Reg,FlagBit)


/************************************************************ */
/* Object Like Macro*/

#define Null            (void*)0
#define NullChar        '\0'

#define Input             0
#define Output            1


#define Low               0
#define High              1


#define Disable           0
#define Enable            1


#define FlagDown          0
#define FlagUp            1

#define NullChar          70






#endif /*_MACROS_H_*/