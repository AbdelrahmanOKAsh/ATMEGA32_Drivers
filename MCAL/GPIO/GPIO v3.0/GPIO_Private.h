/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Timestamp: 20/6/2022                                                             *
*			                                 File: GPIO_Private.h                                                             *
*			                                 [GPIO Module Driver]                                                             *
******************************************************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* GPIOx REGISTER FILE */
typedef struct GPIO_REISTERFILEx
{
    volatile u8 PIN;
    volatile u8 DDR;
    volatile u8 PORT;
}GPIO_REG;


/* GPIOx BASE ADDRESSES */
#define GPIOA_BASE_ADDRESS     0x3B
#define GPIOB_BASE_ADDRESS     0x38
#define GPIOC_BASE_ADDRESS     0x35
#define GPIOD_BASE_ADDRESS     0x32

/* GPIOx MEMORY MAPPING */
#define GPIOA     ((GPIO_REG*) GPIOA_BASE_ADDRESS)
#define GPIOB     ((GPIO_REG*) GPIOB_BASE_ADDRESS)
#define GPIOC     ((GPIO_REG*) GPIOC_BASE_ADDRESS)
#define GPIOD     ((GPIO_REG*) GPIOD_BASE_ADDRESS)

/* SFIO REGISTER MEMORY MAPPING AND PUPD BIT NUMBER */
#define SFIO *((u8*) 0x50)
#define PUPD  2


#endif /* GPIO_PRIVATE_H_ */
