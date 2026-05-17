/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Timestamp: 20/6/2022                                                             *
*			                                 File: GPIO_Interface.h                                                           *
*			                                 [GPIO Module Driver]                                                             *
******************************************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* GPIO PORTs INTERFACE OPTIONs */
typedef enum GPIO_PORTIDs
{
    PORTA = 3,
    PORTB = 2,
    PORTC = 1,
    PORTD = 0
}PortID_t;

/* GPIO PINs INTERFACE OPTIONs */
typedef enum GPIO_PINIDs
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}PinID_t;

/* GPIO PIN MODEs INTERFACE OPTIONs */
typedef enum GPIO_PINMODEs
{
    INPUT_FLOATING = 0,
    OUTPUT,
    INPUT_INTERNALPULLUP
}PinMode_t;

/* GPIO PIN STATEs INTERFACE OPTIONs */
typedef enum GPIO_PINSTATEs
{
    LOW = 0,
    HIGH
}PinState_t;

/* GPIO PORT STATEs INTERFACE OPTIONs */
typedef enum GPIO_PORTSTATEs
{
    PORT_LOW  = 0x00,
    PORT_HIGH = 0xFF
}PortState_t;


typedef enum GPIO_PORTSIZE
{
    PORTSIZE_2 = 2,
    PORTSIZE_3,
    PORTSIZE_4,
    PORTSIZE_5,
    PORTSIZE_6,
    PORTSIZE_7,
    PORTSIZE_8
}PortSize_t;


typedef struct GPIO_PINCONFIG
{
    PortID_t  PortID:2;
    PinID_t   PinID:3;
    PinMode_t PinMode:3;
}GPIO_PinConfig;

VALIDATION GPIO_enumPinInit (const GPIO_PinConfig *PinConfig);
VALIDATION GPIO_enumSetPinState (const GPIO_PinConfig *PinConfig,PinState_t Copy_enumPinState);
VALIDATION GPIO_enumScanPinState (const GPIO_PinConfig *PinConfig,PinState_t* PtrPinState);
VALIDATION GPIO_enumTogglePinState (const GPIO_PinConfig *PinConfig);

typedef struct GPIO_PORTCONFIG
{
    PortID_t   PortID:2;
    PinID_t    PortInitPinID:3;
    PinMode_t  PortMode:3;
    PortSize_t PortSize:8;
}GPIO_PortConfig;

VALIDATION GPIO_enumPortInit (const GPIO_PortConfig *PortConfig);
VALIDATION GPIO_enumSetPortState (const GPIO_PortConfig *PortConfig,PortState_t Copy_enumPortState);
VALIDATION GPIO_enumScanPortState (const GPIO_PortConfig *PortConfig,PortState_t* PtrPortState);
VALIDATION GPIO_enumTogglePortState (const GPIO_PortConfig *PortConfig);


#endif /* GPIO_INTERFACE_H_ */
