/**
 * @file   RegistersAddress.h
 * @author Hesham Ahmed  (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date    2025-08-25
 * 
 * @copyright Copyright (c) 2025 , Gestell Company
 * 
 */

#ifndef _REGISTERADDRESS_H_
#define _REGISTERADDRESS_H_
#include <stdint.h>
// Direcite Access 

#define  SREG_Reg    *((volatile uint8_t *)0x5F)

/**
 * @defgroup DIO Registers 
 * 
 */
#define  PORTA_Reg   *((volatile uint8_t *)0x3B)
#define  PORTB_Reg   *((volatile uint8_t *)0x38)
#define  PORTC_Reg   *((volatile uint8_t *)0x35)
#define  PORTD_Reg   *((volatile uint8_t *)0x32)

#define  DDRA_Reg   *((volatile uint8_t *)0x3A)
#define  DDRB_Reg   *((volatile uint8_t *)0x37)
#define  DDRC_Reg   *((volatile uint8_t *)0x34)
#define  DDRD_Reg   *((volatile uint8_t *)0x31)

#define  PINA_Reg   *((volatile uint8_t *)0x39)
#define  PINB_Reg   *((volatile uint8_t *)0x36)
#define  PINC_Reg   *((volatile uint8_t *)0x33)
#define  PIND_Reg   *((volatile uint8_t *)0x30)

/**
 * @defgroup EXTI Registers 
 * 
 */

#define GICR_Reg    *((volatile uint8_t *)0x5B)
#define GIFR_Reg    *((volatile uint8_t *)0x5A)
#define MCUCR_Reg   *((volatile uint8_t *)0x55)
#define MCUCSR_Reg  *((volatile uint8_t *)0x54)

// Struct 




#endif /*_REGISTERADDRESS_H_*/