/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 6/11/2023                                                               *
*			                                 File: GPIO_Interface.h                                                           *
*			                                 [GPIO Module Driver]                                                             *
******************************************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* Macros For GPIO PORTs */
#define GPIO_PORTA     0
#define GPIO_PORTB     1
#define GPIO_PORTC     2
#define GPIO_PORTD     3


/* Macros For GPIO PINs */
#define GPIO_PIN0      0
#define GPIO_PIN1      1
#define GPIO_PIN2      2
#define GPIO_PIN3      3
#define GPIO_PIN4      4
#define GPIO_PIN5      5
#define GPIO_PIN6      6 
#define GPIO_PIN7      7

/* Macros For GPIO PINs Modes */
#define GPIO_INPUT     0
#define GPIO_OUTPUT    1

/* Macros For GPIO PORTs Modes */
#define PORT_INPUT     0x00
#define PORT_OUTPUT    0xFF


/* Macros For GPIO Value */
#define LOW           0
#define HIGH          1

/* Macros For GPIO Value */
#define PORT_LOW      0x00
#define PORT_HIGH     0xFF


/* GPIO HAL Interface */
VALIDATION GPIO_SetPinMode     (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Mode);
VALIDATION GPIO_SetPinValue    (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value);
VALIDATION GPIO_TogglePinValue (u8 Copy_u8PORT,u8 Copy_u8PIN);
VALIDATION GPIO_u8ScanPinValue (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 *PtrData);
    
VALIDATION GPIO_SetPortMode      (u8 Copy_u8PORT,u8 Copy_u8Mode);
VALIDATION GPIO_SetPortValue     (u8 Copy_u8PORT,u8 Copy_u8Value);
VALIDATION GPIO_WriteHighNibbles (u8 Copy_u8PortID,u8 Copy_u8Value);
VALIDATION GPIO_WriteLowNibbles  (u8 Copy_u8PortID,u8 Copy_u8Value);
VALIDATION GPIO_TogglePortValue  (u8 Copy_u8PORT);
VALIDATION GPIO_u8ScanPortValue  (u8 Copy_u8PORT,u8 *Copy_u8PtrData);

VALIDATION GPIO_ConnectInternalPullUp (u8 Copy_u8PORT,u8 Copy_u8PIN);
void GPIO_DisableInternalPullUp       (void);



#endif /* GPIO_INTERFACE_H_ */
