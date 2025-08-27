/**
 * @file   SSD_Private.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */


#ifndef _SSD_PRIVATE_H_
#define _SSD_PRIVATE_H_ 

 /**
  * MCU : 7 6 5 4 3 2 1 0 
  * SSD : h g f e d c b a 
  * Common Cathod 
  */
#define SSD_Zero           0x3F 
#define SSD_One            0x06
#define SSD_Two            0x5B
#define SSD_Three          0x4f
#define SSD_Four           0x66
#define SSD_Five           0x6D
#define SSD_Six            0x7D
#define SSD_Seven          0x07
#define SSD_Eight          0x7F
#define SSD_Nine           0x6F      
/*--------------------------------------------------------------------------------*/
#define SSD_CommonCathod   0
#define SSD_CommonAnode    1


#define SSD_StartIndex     1


#define SSD_MinNumber      0
#define SSD_MaxNumber      9 
#endif  /*_SSD_PRIVATE_H_*/