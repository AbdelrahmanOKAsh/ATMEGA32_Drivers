/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Created: 12/6/2025                                                                 *
*			                             File: GPIO_Program.c                                                               *
*			                             [GPIO Module Driver]                                                               *
****************************************************************************************************************************/

#include "../../../LIBs/STD_TYPES.h"
#include "../../../LIBs/BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"


/***************************************************************************************************************************** 
* Brief: Function Used to Configure a Pin Mode [INPUT or OUTPUT]                                                             *
* Parameters:                                                                                                                *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                 *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]     *
*   [3]-Pin Mode       [ GPIO_PIN_INPUT or GPIO_PIN_OUTPUT ]                                                                 *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                   *
*****************************************************************************************************************************/
VALIDATION GPIO_SetPinMode (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        if(Copy_u8PinMode == GPIO_PIN_INPUT)
        {
            switch(Copy_u8PortID)
            {
                case GPIO_PORTA: CLEAR_BIT(GPIOA->DDR,Copy_u8PinID); break;
                case GPIO_PORTB: CLEAR_BIT(GPIOB->DDR,Copy_u8PinID); break;
                case GPIO_PORTC: CLEAR_BIT(GPIOC->DDR,Copy_u8PinID); break;
                case GPIO_PORTD: CLEAR_BIT(GPIOD->DDR,Copy_u8PinID); break;
                default        : Local_ValidationStatus  =  INVALID; break;
            }
        }

        else if(Copy_u8PinMode == GPIO_PIN_OUTPUT)
        {
            switch(Copy_u8PortID)
            {
                case GPIO_PORTA: SET_BIT(GPIOA->DDR,Copy_u8PinID); break;
                case GPIO_PORTB: SET_BIT(GPIOB->DDR,Copy_u8PinID); break;
                case GPIO_PORTC: SET_BIT(GPIOC->DDR,Copy_u8PinID); break;
                case GPIO_PORTD: SET_BIT(GPIOD->DDR,Copy_u8PinID); break;
                default        : Local_ValidationStatus = INVALID; break;
            }
        }

        else
        {
            Local_ValidationStatus = INVALID;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Configure a Pin Value [HIGH or LOW]                                                                 *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
*   [3]-PIN Mode       [ GPIO_PIN_LOW or GPIO_PIN_HIGH ]                                                                      *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                    *
******************************************************************************************************************************/
VALIDATION GPIO_SetPinValue (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        if(Copy_u8PinValue == GPIO_PIN_LOW)
        {
            switch(Copy_u8PortID)
            {
                case GPIO_PORTA: CLEAR_BIT(GPIOA->PORT,Copy_u8PinID); break;
                case GPIO_PORTB: CLEAR_BIT(GPIOB->PORT,Copy_u8PinID); break;
                case GPIO_PORTC: CLEAR_BIT(GPIOC->PORT,Copy_u8PinID); break;
                case GPIO_PORTD: CLEAR_BIT(GPIOD->PORT,Copy_u8PinID); break;
                default        : Local_ValidationStatus  =   INVALID; break;
            }
        }

        else if(Copy_u8PinValue == GPIO_PIN_HIGH)
        {
            switch(Copy_u8PortID)
            {
                case GPIO_PORTA: SET_BIT(GPIOA->PORT,Copy_u8PinID); break;
                case GPIO_PORTB: SET_BIT(GPIOB->PORT,Copy_u8PinID); break;
                case GPIO_PORTC: SET_BIT(GPIOC->PORT,Copy_u8PinID); break;
                case GPIO_PORTD: SET_BIT(GPIOD->PORT,Copy_u8PinID); break;
                default        : Local_ValidationStatus  = INVALID; break;
            }
        }

        else
        {
            Local_ValidationStatus = INVALID;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Toggle a Pin Value                                                                                  *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PIN  ID        [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                    *
******************************************************************************************************************************/
VALIDATION GPIO_TogglePinValue (u8 Copy_u8PortID,u8 Copy_u8PinID)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        switch(Copy_u8PortID)
        {
            case GPIO_PORTA: TOGGLE_BIT(GPIOA->PORT,Copy_u8PinID); break;
            case GPIO_PORTB: TOGGLE_BIT(GPIOB->PORT,Copy_u8PinID); break;
            case GPIO_PORTC: TOGGLE_BIT(GPIOC->PORT,Copy_u8PinID); break;
            case GPIO_PORTD: TOGGLE_BIT(GPIOD->PORT,Copy_u8PinID); break;
            default        : Local_ValidationStatus  =    INVALID; break;
        }
    }

    else
    {       
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/***************************************************************************************************************************** 
* Brief: Function Used to Scan a Pin Value                                                                                   *
* Parameters:                                                                                                                *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                 *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]     *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                   *
*****************************************************************************************************************************/
VALIDATION GPIO_ScanPinValue (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *PtrPinValue)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        switch(Copy_u8PortID)
        {
            case GPIO_PORTA: *PtrPinValue = SCAN_BIT(GPIOA->PIN,Copy_u8PinID); break;
            case GPIO_PORTB: *PtrPinValue = SCAN_BIT(GPIOB->PIN,Copy_u8PinID); break;
            case GPIO_PORTC: *PtrPinValue = SCAN_BIT(GPIOC->PIN,Copy_u8PinID); break;
            case GPIO_PORTD: *PtrPinValue = SCAN_BIT(GPIOD->PIN,Copy_u8PinID); break;
            default : Local_ValidationStatus  =     INVALID;                   break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Configure a Port Mode [INPUT or OUTPUT]                                                             *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [3]-PORT Mode      [ GPIO_PORT_INPUT or GPIO_PORT_OUTPUT ]                                                                *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                    *
******************************************************************************************************************************/
VALIDATION GPIO_SetPortMode (u8 Copy_u8PortID,u8 Copy_u8PortMode)
{
    VALIDATION Local_ValidationStatus=VALID;
    switch(Copy_u8PortID)
    {
        case GPIO_PORTA: GPIOA->DDR=Copy_u8PortMode; break;
        case GPIO_PORTB: GPIOB->DDR=Copy_u8PortMode; break;
        case GPIO_PORTC: GPIOC->DDR=Copy_u8PortMode; break;
        case GPIO_PORTD: GPIOD->DDR=Copy_u8PortMode; break;
        default : Local_ValidationStatus  = INVALID; break;
    }
        
    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Configure a Port Value [HIGH or LOW]                                                                *
* Parameters:                                                                                                                 *
*   [1]-PORT ID           [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                               *
*   [2]-PORT Value        [ GPIO_PORT_LOW , GPIO_PORT_HIGH ]                                                                  *
* Return: VALIDATION      [ VALID , INVALID ]                                                                                 *
******************************************************************************************************************************/
VALIDATION GPIO_SetPortValue (u8 Copy_u8PortID,u8 Copy_u8PortValue)
{
    VALIDATION Local_ValidationStatus=VALID;
    switch(Copy_u8PortID)
    {
        case GPIO_PORTA: GPIOA->PORT=Copy_u8PortValue; break;
        case GPIO_PORTB: GPIOB->PORT=Copy_u8PortValue; break;
        case GPIO_PORTC: GPIOC->PORT=Copy_u8PortValue; break;
        case GPIO_PORTD: GPIOD->PORT=Copy_u8PortValue; break;
        default : Local_ValidationStatus   =  INVALID; break;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Toggle a Port Value                                                                                 *
* Parameters:                                                                                                                 *
*   -PORT ID           [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                    *
******************************************************************************************************************************/
VALIDATION GPIO_TogglePortValue (u8 Copy_u8PortID)
{
    VALIDATION Local_ValidationStatus=VALID;
    switch(Copy_u8PortID)
    {
        case GPIO_PORTA: GPIOA->PORT = ~(GPIOA->PORT); break;
        case GPIO_PORTB: GPIOB->PORT = ~(GPIOB->PORT); break;
        case GPIO_PORTC: GPIOC->PORT = ~(GPIOC->PORT); break;
        case GPIO_PORTD: GPIOD->PORT = ~(GPIOD->PORT); break;
        default : Local_ValidationStatus  =   INVALID; break;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Scan a Port Value                                                                                   *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-Pointer to Return The Port Current Value                                                                              *
* Return: VALIDATION   [ VALID , INVALID ]                                                                                    *
******************************************************************************************************************************/
VALIDATION GPIO_ScanPortValue (u8 Copy_u8PortID,u8 *Copy_u8PtrPortValue)
{
    VALIDATION Local_ValidationStatus=VALID;
    switch(Copy_u8PortID)
    {
        case GPIO_PORTA: *Copy_u8PtrPortValue=GPIOA->PIN; break;
        case GPIO_PORTB: *Copy_u8PtrPortValue=GPIOB->PIN; break;
        case GPIO_PORTC: *Copy_u8PtrPortValue=GPIOC->PIN; break;
        case GPIO_PORTD: *Copy_u8PtrPortValue=GPIOD->PIN; break;
        default        : Local_ValidationStatus =INVALID; break;
    }

    return Local_ValidationStatus;   
}




/****************************************************************************************************************************** 
* Brief: Function Used to Write a Port Value on The High Nibbles                                                              *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PORT Value     [ User Input/Given Value ]                                                                             *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_WriteHighNibbles (u8 Copy_u8PortID,u8 Copy_u8Value)
{
    VALIDATION Local_ValidationStatus=VALID;
    Copy_u8Value = (Copy_u8Value << 4);
    if(Copy_u8PortID <= GPIO_PORTD)
    {
        switch(Copy_u8PortID)
        {
            case GPIO_PORTA: (GPIOA->PORT) &= 0x0F; (GPIOA->PORT) |= Copy_u8Value; break;
            case GPIO_PORTB: (GPIOB->PORT) &= 0x0F; (GPIOB->PORT) |= Copy_u8Value; break;
            case GPIO_PORTC: (GPIOC->PORT) &= 0x0F; (GPIOC->PORT) |= Copy_u8Value; break;
            case GPIO_PORTD: (GPIOD->PORT) &= 0x0F; (GPIOD->PORT) |= Copy_u8Value; break;
            default        : Local_ValidationStatus  =  INVALID;                   break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Write a Port Value on The Low Nibbles                                                               *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PORT Value     [ User Input/Given Value ]                                                                             *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_WriteLowNibbles (u8 Copy_u8PortID,u8 Copy_u8Value)
{
    VALIDATION Local_ValidationStatus=VALID;
    Copy_u8Value &= 0x0F;
    if(Copy_u8PortID <= GPIO_PORTD)
    {
        switch(Copy_u8PortID)
        {
            case GPIO_PORTA: (GPIOA->PORT) &= 0xF0; (GPIOA->PORT) |= Copy_u8Value; break;
            case GPIO_PORTB: (GPIOB->PORT) &= 0xF0; (GPIOB->PORT) |= Copy_u8Value; break;
            case GPIO_PORTC: (GPIOC->PORT) &= 0xF0; (GPIOC->PORT) |= Copy_u8Value; break;
            case GPIO_PORTD: (GPIOD->PORT) &= 0xF0; (GPIOD->PORT) |= Copy_u8Value; break;
            default        : Local_ValidationStatus  =   INVALID;                  break;
        }
    }

    else
    {
        Local_ValidationStatus=INVALID;
    }

    return Local_ValidationStatus;
}




/****************************************************************************************************************************** 
* Brief: Function Used to Enable The Global Internal Pull Up Resistor For All GPIOs PORTs and PINs                            *
* Parameters:  Void                                                                                                           *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_EnableGlobalInternalPullUp()
{
    VALIDATION Local_ValidationStatus=VALID;
    CLEAR_BIT(SFIOR,PUD);
    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Disable The Global Internal Pull Up Resistor For All GPIOs PORTs and PINs                           *
* Parameters:  Void                                                                                                           *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_DisableGloballInternalPullUp()
{
    VALIDATION Local_ValidationStatus=VALID;
    SET_BIT(SFIOR,PUD);
    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Connect a Pin as an Internal Pull Up Resistor                                                       *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_ConnectInternalPullUp (u8 Copy_u8PortID,u8 Copy_u8PinID)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        switch(Copy_u8PortID)
        {
            case GPIO_PORTA: CLEAR_BIT(SFIOR,PUD); CLEAR_BIT(GPIOA->DDR,Copy_u8PinID); SET_BIT(GPIOA->PORT,Copy_u8PinID); break;
            case GPIO_PORTB: CLEAR_BIT(SFIOR,PUD); CLEAR_BIT(GPIOB->DDR,Copy_u8PinID); SET_BIT(GPIOB->PORT,Copy_u8PinID); break;
            case GPIO_PORTC: CLEAR_BIT(SFIOR,PUD); CLEAR_BIT(GPIOC->DDR,Copy_u8PinID); SET_BIT(GPIOC->PORT,Copy_u8PinID); break;
            case GPIO_PORTD: CLEAR_BIT(SFIOR,PUD); CLEAR_BIT(GPIOD->DDR,Copy_u8PinID); SET_BIT(GPIOD->PORT,Copy_u8PinID); break;
            default : Local_ValidationStatus   =    INVALID;                                                              break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Disconnect a Pin as an Internal Pull Up Resistor                                                    *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_DisconnectInternalPullUp (u8 Copy_u8PortID,u8 Copy_u8PinID)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        switch(Copy_u8PortID)
        {
            case GPIO_PORTA: CLEAR_BIT(GPIOA->PORT,Copy_u8PinID); break;
            case GPIO_PORTB: CLEAR_BIT(GPIOB->PORT,Copy_u8PinID); break;
            case GPIO_PORTC: CLEAR_BIT(GPIOC->PORT,Copy_u8PinID); break;
            case GPIO_PORTD: CLEAR_BIT(GPIOD->PORT,Copy_u8PinID); break;
            default        : Local_ValidationStatus   =  INVALID; break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}