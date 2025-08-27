/**
 * @file   Macros.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _MACROS_H_
#define _MACROS_H_


/*Function Like Macro*/

#define SetBit(Reg,BitNo)         ((Reg)|=(1<<BitNo))
#define ClearBit(Reg,BitNo)       ((Reg)&=~(1<<BitNo))
#define ToggleBit(Reg,BitNo)      ((Reg)^=(1<<BitNo))
#define GetBit(Reg,BitNo)         ((Reg>>BitNo)&0x01)

#define ClearFlag(Reg,FlagNo)      SetBit(Reg,FlagNo)
#define GetFlagStatus(Reg,FlagNo)  GetBit(Reg,FlagNo);
/*------------------------------------------------------------------------------------*/

/*Object Like Macro*/

#define Null              (void*)0
#define NullChar          '\0'


#define FlagDown            0
#define FlagUp              1

#define Input               0
#define Output              1

#define Low                 0
#define High                1

#define Off                 0
#define On                  1

#define Enable              0    
#define Disable             1

#define AllGroupOutput      0xFF


#endif /* _MACROS_H_ */