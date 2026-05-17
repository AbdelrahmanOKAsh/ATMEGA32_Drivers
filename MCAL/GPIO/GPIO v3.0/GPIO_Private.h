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


/* GPIO REGISTER FILE MEMORY MAPPING FOR ACCESSING [ A POINTER TO AN ARRAY OF 4 ELEMENTs OF [ GPIO_REG ] DEFINED TYPE ] */
#define GPIO      (*((GPIO_REG(*)[4]) 0x30))


/* SFIO REGISTER MEMORY MAPPING AND PUPD BIT NUMBER */
#define SFIO *((u8*) 0x50)
#define PUPD  2


#define PORT_BOUNDRY          3
#define PIN_BOUNDRY           7


#endif /* GPIO_PRIVATE_H_ */
