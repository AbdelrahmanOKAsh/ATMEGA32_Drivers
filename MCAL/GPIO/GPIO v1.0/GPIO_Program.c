/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Timestamp: 20/6/2022                                                               *
*			                             File: GPIO_Program.c                                                               *
*			                             [GPIO Module Driver]                                                               *
****************************************************************************************************************************/

#include "../../../LIBs/STD_TYPES.h"
#include "../../../LIBs/BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"



/***************************************************************************************************************************** 
* Brief: Function Used to Configure a Pin Mode [INPUT or OUTPUT]                                                             *
* Parameters:                                                                                                                *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                 *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]     *
*   [3]-Pin Mode       [ GPIO_INPUT or GPIO_OUTPUT ]                                                                         *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                  *
*****************************************************************************************************************************/
VALIDATION GPIO_SetPinMode (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        if (Copy_u8Mode == GPIO_INPUT)
        {
            switch (Copy_u8PortID)
            {
                case GPIO_PORTA: CLEAR_BIT(DDRA,Copy_u8PinID);     break;
                case GPIO_PORTB: CLEAR_BIT(DDRB,Copy_u8PinID);     break;
                case GPIO_PORTC: CLEAR_BIT(DDRC,Copy_u8PinID);     break;
                case GPIO_PORTD: CLEAR_BIT(DDRD,Copy_u8PinID);     break;
                default        : Local_ValidationStatus = INVALID; break;
            }
        }

        else if (Copy_u8Mode == GPIO_OUTPUT)
        {
            switch (Copy_u8PortID)
            {
                case GPIO_PORTA: SET_BIT(DDRA,Copy_u8PinID);       break;
                case GPIO_PORTB: SET_BIT(DDRB,Copy_u8PinID);       break;
                case GPIO_PORTC: SET_BIT(DDRC,Copy_u8PinID);       break;
                case GPIO_PORTD: SET_BIT(DDRD,Copy_u8PinID);       break;
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
*   [3]-PIN Mode       [ HIGH or LOW ]                                                                                        *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_SetPinValue (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value)
{
    VALIDATION Local_ValidationStatus = VALID;
    if ((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        if (Copy_u8Value == LOW)
        {
            switch (Copy_u8PortID)
            {
                case GPIO_PORTA: CLEAR_BIT(PORTA,Copy_u8PinID);    break;
                case GPIO_PORTB: CLEAR_BIT(PORTB,Copy_u8PinID);    break; 
                case GPIO_PORTC: CLEAR_BIT(PORTC,Copy_u8PinID);    break; 
                case GPIO_PORTD: CLEAR_BIT(PORTD,Copy_u8PinID);    break;
                default        : Local_ValidationStatus = INVALID; break;  
            }
        }

        else if (Copy_u8Value == HIGH)
        {
            switch (Copy_u8PortID)
            {
                case GPIO_PORTA: SET_BIT(PORTA,Copy_u8PinID);      break;
                case GPIO_PORTB: SET_BIT(PORTB,Copy_u8PinID);      break; 
                case GPIO_PORTC: SET_BIT(PORTC,Copy_u8PinID);      break; 
                case GPIO_PORTD: SET_BIT(PORTD,Copy_u8PinID);      break;
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
* Brief: Function Used to Toggle a Pin Value                                                                                  *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PIN  ID        [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_TogglePinValue (u8 Copy_u8PortID,u8 Copy_u8PinID)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        switch (Copy_u8PortID)
        {
                case GPIO_PORTA: TOGGLE_BIT(PORTA,Copy_u8PinID);    break;
                case GPIO_PORTB: TOGGLE_BIT(PORTB,Copy_u8PinID);    break; 
                case GPIO_PORTC: TOGGLE_BIT(PORTC,Copy_u8PinID);    break; 
                case GPIO_PORTD: TOGGLE_BIT(PORTD,Copy_u8PinID);    break;
                default        : Local_ValidationStatus = INVALID;  break;  
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
*   [3]-Pointer to Return The Pin Current Value                                                                              *
* Return: VALIDATION   [ VALID or INVALID ]  &&   The Pin Current Value ->[PtrData]                                          *
*****************************************************************************************************************************/
VALIDATION GPIO_u8ScanPinValue (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *PtrData)
{
    VALIDATION Local_ValidationStatus=VALID;
    if((Copy_u8PortID <= GPIO_PORTD) && (Copy_u8PinID <= GPIO_PIN7))
    {
        switch (Copy_u8PortID)
        {
            case GPIO_PORTA: *PtrData = SCAN_BIT(PINA,Copy_u8PinID); break;
            case GPIO_PORTB: *PtrData = SCAN_BIT(PINB,Copy_u8PinID); break;
            case GPIO_PORTC: *PtrData = SCAN_BIT(PINC,Copy_u8PinID); break;
            case GPIO_PORTD: *PtrData = SCAN_BIT(PIND,Copy_u8PinID); break;
            default        : Local_ValidationStatus = INVALID;       break;  
        }

    }

    else
    {
        Local_ValidationStatus=INVALID;
    }
        
    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Configure a Port Mode [INPUT or OUTPUT]                                                             *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [3]-PORT Mode      [ GPIO_INPUT or GPIO_OUTPUT ]                                                                          *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_SetPortMode (u8 Copy_u8PortID,u8 Copy_u8Mode)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(Copy_u8PortID <= GPIO_PORTD)
    {
        if (Copy_u8Mode == GPIO_INPUT)
        {
            switch (Copy_u8PortID)
            {
                case GPIO_PORTA: DDRA = PORT_INPUT;                break;
                case GPIO_PORTB: DDRB = PORT_INPUT;                break;
                case GPIO_PORTC: DDRC = PORT_INPUT;                break;
                case GPIO_PORTD: DDRD = PORT_INPUT;                break;
                default        : Local_ValidationStatus = INVALID; break;
            }
        }

        else if (Copy_u8Mode == GPIO_OUTPUT)
        {
            switch (Copy_u8PortID)
            {
                case GPIO_PORTA: DDRA = PORT_OUTPUT;                break;
                case GPIO_PORTB: DDRB = PORT_OUTPUT;                break;
                case GPIO_PORTC: DDRC = PORT_OUTPUT;                break;
                case GPIO_PORTD: DDRD = PORT_OUTPUT;                break;
                default        : Local_ValidationStatus = INVALID;  break;  
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
* Brief: Function Used to Configure a Port Value [HIGH or LOW]                                                                *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PORT ID        [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_SetPortValue (u8 Copy_u8PortID,u8 Copy_u8Value)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(Copy_u8PortID <= GPIO_PORTD)
    {
        switch (Copy_u8PortID)
        {
            case GPIO_PORTA: PORTA = Copy_u8Value;             break;
            case GPIO_PORTB: PORTB = Copy_u8Value;             break;
            case GPIO_PORTC: PORTC = Copy_u8Value;             break;
            case GPIO_PORTD: PORTD = Copy_u8Value;             break;
            default        : Local_ValidationStatus = INVALID; break;  
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
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

    switch(Copy_u8PortID)
    {
        case GPIO_PORTA: PORTA &= 0x0f; PORTA |= Copy_u8Value; break;
        case GPIO_PORTB: PORTB &= 0x0f; PORTB |= Copy_u8Value; break;
        case GPIO_PORTC: PORTC &= 0x0f; PORTC |= Copy_u8Value; break;
        case GPIO_PORTD: PORTD &= 0x0f; PORTD |= Copy_u8Value; break;
        default        : Local_ValidationStatus = INVALID;     break;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Write a Port Value on The LOW Nibbles                                                               *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PORT Value     [ User Input/Given Value ]                                                                             *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_WriteLowNibbles (u8 Copy_u8PortID,u8 Copy_u8Value)
{
    VALIDATION Local_ValidationStatus=VALID;
    Copy_u8Value &= 0x0f;
    switch(Copy_u8PortID)
    {
        case GPIO_PORTA: PORTA &= 0xf0; PORTA |= Copy_u8Value; break;
        case GPIO_PORTB: PORTB &= 0xf0; PORTB |= Copy_u8Value; break;
        case GPIO_PORTC: PORTC &= 0xf0; PORTC |= Copy_u8Value; break;
        case GPIO_PORTD: PORTD &= 0xf0; PORTD |= Copy_u8Value; break;
        default        : Local_ValidationStatus = INVALID;     break;
    }

    return Local_ValidationStatus;
}






/****************************************************************************************************************************** 
* Brief: Function Used to Toggle a Port Value                                                                                 *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PORT ID        [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_TogglePortValue (u8 Copy_u8PortID)
{
    VALIDATION Local_ValidationStatus=VALID;
    
    if(Copy_u8PortID <= GPIO_PORTD)
    {
        switch (Copy_u8PortID)
        {
            case GPIO_PORTA: PORTA = ~PORTA;                   break;
            case GPIO_PORTB: PORTB = ~PORTB;                   break;
            case GPIO_PORTC: PORTC = ~PORTC;                   break;
            case GPIO_PORTD: PORTD = ~PORTD;                   break;
            default        : Local_ValidationStatus = INVALID; break;  
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }
        
    return Local_ValidationStatus;    
}





/****************************************************************************************************************************** 
* Brief: Function Used to Scan a Port Value                                                                                   *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PORT ID        [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
*   [3]-Pointer to Return The Port Current Value                                                                              *
* Return: VALIDATION   [ VALID or INVALID ]  &&   The Port Current Value ->[*PtrData]                                         *
******************************************************************************************************************************/
VALIDATION GPIO_u8ScanPortValue (u8 Copy_u8PortID,u8 *PtrData)
{
    VALIDATION Local_ValidationStatus=VALID;

    if (Copy_u8PortID <= GPIO_PORTD)
    {
        switch (Copy_u8PortID)
        {
            case GPIO_PORTA: *PtrData = PINA;                  break;
            case GPIO_PORTB: *PtrData = PINB;                  break;
            case GPIO_PORTC: *PtrData = PINC;                  break;
            case GPIO_PORTD: *PtrData = PIND;                  break;
            default        : Local_ValidationStatus = INVALID; break;  
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }
        
    return Local_ValidationStatus;
}






/****************************************************************************************************************************** 
* Brief: Function Used to Configure a Switch Connected to a pin as an Internal Pull Up Resistor                               *
* Parameters:                                                                                                                 *
*   [1]-PORT ID        [ GPIO_PORTA , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD ]                                                  *
*   [2]-PIN ID         [ GPIO_PIN0 , GPIO_PIN1 , GPIO_PIN2 , GPIO_PIN3 , GPIO_PIN4 , GPIO_PIN5 , GPIO_PIN6 , GPIO_PIN7 ]      *
* Return: VALIDATION   [ VALID or INVALID ]                                                                                   *
******************************************************************************************************************************/
VALIDATION GPIO_ConnectInternalPullUp (u8 Copy_u8PORT,u8 Copy_u8PIN)
{
    VALIDATION Local_ValidationStatus=VALID;

    if ((Copy_u8PORT <= GPIO_PORTD) && (Copy_u8PIN <= GPIO_PIN7))
    {
        switch(Copy_u8PORT)
        {
            case GPIO_PORTA: SET_BIT(PORTA,Copy_u8PIN); CLEAR_BIT(DDRA,Copy_u8PIN); CLEAR_BIT(SFIOR,PUD); break;
            case GPIO_PORTB: SET_BIT(PORTB,Copy_u8PIN); CLEAR_BIT(DDRB,Copy_u8PIN); CLEAR_BIT(SFIOR,PUD); break;
            case GPIO_PORTC: SET_BIT(PORTC,Copy_u8PIN); CLEAR_BIT(DDRC,Copy_u8PIN); CLEAR_BIT(SFIOR,PUD); break;
            case GPIO_PORTD: SET_BIT(PORTD,Copy_u8PIN); CLEAR_BIT(DDRD,Copy_u8PIN); CLEAR_BIT(SFIOR,PUD); break;
            default        : Local_ValidationStatus = INVALID;                                            break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }
        
    return Local_ValidationStatus;    
}





/****************************************************************************************************************************** 
* Brief: Function Used to Disable a Switch Connected to a pin as an Internal Pull Up Resistor                                 *
* Parameters: Void                                                                                                            *
* Return: Void                                                                                                                *
******************************************************************************************************************************/
void GPIO_DisableInternalPullUp (void)
{
    SET_BIT(SFIOR,PUD);
}