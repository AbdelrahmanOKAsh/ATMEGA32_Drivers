/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 13/6/2025                                                               *
*			                                 File: LED_Interface.h                                                            *
*			                                 [LED Module Driver]                                                              *
******************************************************************************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/* LED OBJECT INTERFACE */
typedef struct LEDx
{
    u8 PortID:3;
    u8 PinID:3;
    u8 Activation:2;
}LED_TYPE;


/* LED GPIO PORTs INTERFACE */
#define LED_PORTA        GPIO_PORTA
#define LED_PORTB        GPIO_PORTB
#define LED_PORTC        GPIO_PORTC
#define LED_PORTD        GPIO_PORTD


/* LED GPIO PINs INTERFACE */
#define LED_PIN0         GPIO_PIN0
#define LED_PIN1         GPIO_PIN1
#define LED_PIN2         GPIO_PIN2
#define LED_PIN3         GPIO_PIN3
#define LED_PIN4         GPIO_PIN4
#define LED_PIN5         GPIO_PIN5
#define LED_PIN6         GPIO_PIN6
#define LED_PIN7         GPIO_PIN7


/* LED ACTIVATION INTERFACE */
#define ACTIVE_LOW       0
#define ACTIVE_HIGH      1


/*================================================ < PROVIDED APIs FOR LED INTERFACING > ================================================*/

VALIDATION LED_Init     (const LED_TYPE *LED_CONFIG);
VALIDATION LED_PowerON  (const LED_TYPE *LED_CONFIG);
VALIDATION LED_PowerOFF (const LED_TYPE *LED_CONFIG);
VALIDATION LED_Toggle   (const LED_TYPE *LED_CONFIG);


#endif /* LED_INTERFACE_H_ */