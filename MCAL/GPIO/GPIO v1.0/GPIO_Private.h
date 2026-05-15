/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 6/11/2023                                                               *
*			                                 File: GPIO_Private.h                                                             *
*			                                 [GPIO Module Driver]                                                             *
******************************************************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* PORT A */
#define PORTA  *((volatile u8*) 0x3B)
#define DDRA   *((volatile u8*) 0x3A)
#define PINA   *((volatile u8*) 0x39)

/* PORT B */
#define PORTB  *((volatile u8*) 0x38)
#define DDRB   *((volatile u8*) 0x37)
#define PINB   *((volatile u8*) 0x36)

/* PORT C */
#define PORTC  *((volatile u8*) 0x35)
#define DDRC   *((volatile u8*) 0x34)
#define PINC   *((volatile u8*) 0x33)

/* PORT D */
#define PORTD  *((volatile u8*) 0x32)
#define DDRD   *((volatile u8*) 0x31)
#define PIND   *((volatile u8*) 0x30)

/* INTERNAL PULL UP RESISTOR */
#define SFIOR  *((volatile u8*) 0x50)
#define PUD    2


#endif /* GPIO_PRIVATE_H_ */
