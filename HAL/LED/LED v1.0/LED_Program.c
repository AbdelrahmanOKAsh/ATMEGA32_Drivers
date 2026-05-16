/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Created: 13/6/2025                                                                 *
*			                             File: LED_Program.c                                                                *
*			                             [LED Module Driver]                                                                *
****************************************************************************************************************************/


#include "../../../LIBs/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO v2.0/GPIO_Interface.h"
#include "LED_Interface.h"



/****************************************************************************************************************************** 
* Brief: Function Used to Configure a LED [ PORT , PIN , ACTIVATION ]                                                         *
* Parameters:                                                                                                                 *
*   A Reference to an Object From [ LED_TYPE ] Defined Type:                                                                  *
*       [1]-PORT ID        [ LED_PORTA , LED_PORTB , LED_PORTC , LED_PORTD ]                                                  *
*       [2]-PIN ID         [ LED_PIN0 , LED_PIN1 , LED_PIN2 , LED_PIN3 , LED_PIN4 , LED_PIN5 , LED_PIN6 , LED_PIN7 ]          *
*       [3]-LED Activation [ ACTIVE_LOW or ACTIVE_HIGH ]                                                                      *
* Return: VALIDATION       [ VALID , INVALID ]                                                                                *
******************************************************************************************************************************/
VALIDATION LED_Init (const LED_TYPE *LED_CONFIG)
{
    VALIDATION Local_ValidationStatus=VALID;
    if(((LED_CONFIG->PortID) <= LED_PORTD) && ((LED_CONFIG->PinID) <= LED_PIN7) && ((LED_CONFIG->Activation) <= ACTIVE_HIGH))
    {
        GPIO_SetPinMode((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_OUTPUT);
        switch(LED_CONFIG->Activation)
        {
            case ACTIVE_LOW:
                GPIO_SetPinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_HIGH);
                break;

            case ACTIVE_HIGH:
                GPIO_SetPinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_LOW);
                break;

            default:
                Local_ValidationStatus=INVALID;
                break;
        }
    }

    else
    {
        Local_ValidationStatus=INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Power ON a LED Connected to Specific [ PORT , PIN , ACTIVATION ]                                    *
* Parameters:                                                                                                                 *
*   A Reference to an Object From [ LED_TYPE ] Defined Type:                                                                  *
*       [1]-PORT ID            [ LED_PORTA , LED_PORTB , LED_PORTC , LED_PORTD ]                                              *
*       [2]-PIN ID             [ LED_PIN0 , LED_PIN1 , LED_PIN2 , LED_PIN3 , LED_PIN4 , LED_PIN5 , LED_PIN6 , LED_PIN7 ]      *
*       [3]-LED Activation     [ ACTIVE_LOW or ACTIVE_HIGH ]                                                                  *
* Return: VALIDATION           [ VALID or INVALID ]                                                                           *
******************************************************************************************************************************/
VALIDATION LED_PowerON (const LED_TYPE *LED_CONFIG)
{
    VALIDATION Local_ValidationStatus=VALID;
    if(((LED_CONFIG->PortID) <= LED_PORTD) && ((LED_CONFIG->PinID) <= LED_PIN7) && ((LED_CONFIG->Activation) <= ACTIVE_HIGH))
    {
        switch(LED_CONFIG->Activation) 
        {
           case ACTIVE_LOW:
                GPIO_SetPinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_LOW);
                break;
            
            case ACTIVE_HIGH:
                 GPIO_SetPinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_HIGH);
                 break;

            default:
                Local_ValidationStatus=INVALID;
                break;
        }
    }

    else
    {
        Local_ValidationStatus=INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Power OFF a LED Connected to Specific [ PORT , PIN , ACTIVATION ]                                   *
* Parameters:                                                                                                                 *
*   A Reference to an Object From [ LED_TYPE ] Defined Type:                                                                  *
*       [1]-PORT ID            [ LED_PORTA , LED_PORTB , LED_PORTC , LED_PORTD ]                                              *
*       [2]-PIN ID             [ LED_PIN0 , LED_PIN1 , LED_PIN2 , LED_PIN3 , LED_PIN4 , LED_PIN5 , LED_PIN6 , LED_PIN7 ]      *
*       [3]-LED Activation     [ ACTIVE_LOW or ACTIVE_HIGH ]                                                                  *
* Return: VALIDATION           [ VALID or INVALID ]                                                                           *
******************************************************************************************************************************/
VALIDATION LED_PowerOFF (const LED_TYPE *LED_CONFIG)
{
    VALIDATION Local_ValidationStatus=VALID;
    if(((LED_CONFIG->PortID) <= LED_PORTD) && ((LED_CONFIG->PinID) <= LED_PIN7) && ((LED_CONFIG->Activation) <= ACTIVE_HIGH))
    {
        switch(LED_CONFIG->Activation) 
        {
           case ACTIVE_LOW:
                GPIO_SetPinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_HIGH);
                break;
            
            case ACTIVE_HIGH:
                 GPIO_SetPinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID),GPIO_PIN_LOW);
                 break;

            default:
                Local_ValidationStatus=INVALID;
                break;
        }
    }

    else
    {
        Local_ValidationStatus=INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: Function Used to Toggle a LED Connected to Specific [ PORT , PIN , ACTIVATION ]                                      *
* Parameters:                                                                                                                 *
*   A Reference to an Object From [ LED_TYPE ] Defined Type:                                                                  *
*       [1]-PORT ID            [ LED_PORTA , LED_PORTB , LED_PORTC , LED_PORTD ]                                              *
*       [2]-PIN ID             [ LED_PIN0 , LED_PIN1 , LED_PIN2 , LED_PIN3 , LED_PIN4 , LED_PIN5 , LED_PIN6 , LED_PIN7 ]      *
*       [3]-LED Activation     [ ACTIVE_LOW or ACTIVE_HIGH ]                                                                  *
* Return: VALIDATION           [ VALID or INVALID ]                                                                           *
******************************************************************************************************************************/
VALIDATION LED_Toggle (const LED_TYPE *LED_CONFIG)
{
    VALIDATION Local_ValidationStatus=VALID;
    if(((LED_CONFIG->PortID) <= LED_PORTD) && ((LED_CONFIG->PinID) <= LED_PIN7) && ((LED_CONFIG->Activation) <= ACTIVE_HIGH))
    {
        GPIO_TogglePinValue((LED_CONFIG->PortID),(LED_CONFIG->PinID));
    }

    else
    {
        Local_ValidationStatus=INVALID;
    }

    return Local_ValidationStatus;
}