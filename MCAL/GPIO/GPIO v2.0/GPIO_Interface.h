/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 12/6/2025                                                               *
*			                                 File: GPIO_Interface.h                                                           *
*			                                 [GPIO Module Driver]                                                             *
******************************************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/* GPIO PINs INTERFACE */
#define GPIO_PIN0                   0
#define GPIO_PIN1                   1 
#define GPIO_PIN2                   2
#define GPIO_PIN3                   3
#define GPIO_PIN4                   4
#define GPIO_PIN5                   5
#define GPIO_PIN6                   6
#define GPIO_PIN7                   7 


/* INPUT/OUTPUT PIN INTERFACE */
#define GPIO_PIN_INPUT              0
#define GPIO_PIN_OUTPUT             1


/* LOW/HIGH PIN INTERFACE */
#define GPIO_PIN_LOW                0
#define GPIO_PIN_HIGH               1


/* GPIO PORTs INTERFACE */
#define GPIO_PORTA                   0
#define GPIO_PORTB                   1 
#define GPIO_PORTC                   2
#define GPIO_PORTD                   3


/* INPUT/OUTPUT PORT INTERFACE */
#define GPIO_PORT_INPUT              0x00
#define GPIO_PORT_OUTPUT             0xFF
 
 
/* LOW/HIGH PORT INTERFACE */ 
#define GPIO_PORT_LOW                0x00
#define GPIO_PORT_HIGH               0xFF




/*=================================================== < PROVIDED APIs FOR GPIO PINs > ===================================================*/

VALIDATION GPIO_SetPinMode      (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode     );
VALIDATION GPIO_SetPinValue     (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue    );
VALIDATION GPIO_ScanPinValue    (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *Copy_u8PtrPinValue);
VALIDATION GPIO_TogglePinValue  (u8 Copy_u8PortID,u8 Copy_u8PinID                       );




/*=================================================== < PROVIDED APIs FOR GPIO PORTs > ===================================================*/

VALIDATION GPIO_SetPortMode      (u8 Copy_u8PortID,u8 Copy_u8PortMode     );
VALIDATION GPIO_SetPortValue     (u8 Copy_u8PortID,u8 Copy_u8PortValue    );
VALIDATION GPIO_ScanPortValue    (u8 Copy_u8PortID,u8 *Copy_u8PtrPortValue);
VALIDATION GPIO_WriteHighNibbles (u8 Copy_u8PortID,u8 Copy_u8Value        );
VALIDATION GPIO_WriteLowNibbles  (u8 Copy_u8PortID,u8 Copy_u8Value        );
VALIDATION GPIO_TogglePortValue  (u8 Copy_u8PortID                        );


/*================================================ < PROVIDED APIs FOR INTERNAL PULL UP > ================================================*/


VALIDATION GPIO_EnableGlobalInternalPullUp    (                                );       
VALIDATION GPIO_DisableGloballInternalPullUp  (                                );   
VALIDATION GPIO_ConnectInternalPullUp         (u8 Copy_u8PortID,u8 Copy_u8PinID);
VALIDATION GPIO_DisconnectInternalPullUp      (u8 Copy_u8PortID,u8 Copy_u8PinID);




#endif /* GPIO_INTERFACE_H_ */