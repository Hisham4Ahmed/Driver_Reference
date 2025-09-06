/**
 * @file   EXTI_Private.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_



/**
 * @defgroup  Name of Bits for MCUCR Register
 * 
 */

#define ISC00_Bit                  0
#define ISC01_Bit                  1
#define ISC10_Bit                  2
#define ISC11_Bit                  3  


/**
 * @defgroup  Name of Bits for MCUCSR Register
 * 
 */

#define ISC2_Bit                  2

/**
 * @defgroup Name of Bits for GICR Register 
 * 
 */

#define INT1_Bit      7 
#define INT0_Bit      6 
#define INT2_Bit      5

/**
 * @defgroup Name of Bits for GIFR Register 
 * 
 */
#define INTF1_Bit      7 
#define INTF0_Bit      6 
#define INTF2_Bit      5
// -----------------------------------------------------------------
/*ISR*/

void __vector_1(void)  __attribute__((signal)); // INT0 
void __vector_2(void)  __attribute__((signal)); // INT1 
void __vector_3(void)  __attribute__((signal)); // INT2 


// -----------------------------------------------------------------
/**
 * @defgroup Sens Control Options 
 * 
 */
#define EXTI_LowLevel    0 
#define EXTI_AnyChange   1 
#define EXTI_FallingEdge 2 
#define EXTI_RisingEdge  3



#define EXTI0            0
#define EXTI1            1
#define EXTI2            2
#endif /*_EXTI_PRIVATE_H_*/