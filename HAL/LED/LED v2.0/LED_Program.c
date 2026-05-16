/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Timestamp: 21/6/2022                                                               *
*			                             File: LED_Program.c                                                                *
*			                             [ LED Module Driver ]                                                              *
****************************************************************************************************************************/


#include "../../LIBs/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO v2.0/GPIO_Interface.h"
#include "LED_Interface.h"
//#include<util/delay.h>



/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO CONFIGURE A LED                                                                                     *
* PARAMETERS:                                                                                                                 *
*   A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                      *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/

VALIDATION LED_enumInit(const LED_t *LEDConfig)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        if(GPIO_enumPinInit(&LEDConfig->Pin) == VALID)
        {
            GPIO_enumSetPinState(&LEDConfig->Pin,!(LEDConfig->Mode));
        }

        else
        {
            Local_enumValidationStatus = INVALID;
        }
    }

    else
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO POWER ON A LED                                                                                      *
* PARAMETERS:                                                                                                                 *
*   A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                      *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/
VALIDATION LED_enumPowerON (const LED_t *LEDConfig)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        GPIO_enumSetPinState(&LEDConfig->Pin,LEDConfig->Mode);
    }

    else
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO POWER Off A LED                                                                                     *
* PARAMETERS:                                                                                                                 *
*   A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                      *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/
VALIDATION LED_enumPowerOFF (const LED_t *LEDConfig)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        GPIO_enumSetPinState(&LEDConfig->Pin,!(LEDConfig->Mode));
    }

    else
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO TOGGLE LED STATE                                                                                    *
* PARAMETERS:                                                                                                                 *
*   A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                      *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/
VALIDATION LED_enumToggleState (const LED_t *LEDConfig)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        GPIO_enumTogglePinState(&LEDConfig->Pin);
    }

    else
    {
        Local_enumValidationStatus = INVALID;
    }

    return Local_enumValidationStatus;
}





/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO SCAN LED CUREENT STATE                                                                              *
* PARAMETERS:                                                                                                                 *
*   A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                      *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/
VALIDATION LED_enumScanCurrentState (const LED_t *LEDConfig,State_t *PtrState)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        GPIO_enumScanPinState(&LEDConfig->Pin,PtrState);
    }

    else
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO BLINK A LED WITH STATIC ON OFF [ BUSY WAITING ] DELAY TIME                                          *
* PARAMETERS:                                                                                                                 *
*   -A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                     *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
*   -DELAY TIME [ IN MILI SECEND ]                                                                                            *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/
VALIDATION LED_enumStaticBlink (const LED_t *LEDConfig,u32 Copy_u32DelayMiliSec)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        GPIO_enumSetPinState(&LEDConfig->Pin,LEDConfig->Mode);
        _delay_ms(Copy_u32DelayMiliSec);
        GPIO_enumSetPinState(&LEDConfig->Pin,!(LEDConfig->Mode));
        _delay_ms(Copy_u32DelayMiliSec);
    }

    else
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/****************************************************************************************************************************** 
* BRIEF: FUNCTION USED TO BLINK A LED WITH DYNAMIC ON OFF [ BUSY WAITING ] DELAY TIME                                         *
* PARAMETERS:                                                                                                                 *
*   -A REFERENCE TO AN OBJECT OF [ LED_t ] DEFINED TYPE :                                                                     *
*       [1]-PIN CONFIGURATION                                                                                                 *
*       [2]-LED ACTIVATION MODE                                                                                               *
*   -DELAY TIME [ IN MILI SECEND ]                                                                                            *
* RETURN: VALIDATION                                                                                                          *
******************************************************************************************************************************/
VALIDATION LED_enumDynamicBlink (const LED_t *LEDConfig,u32 Copy_u32ONDelayMiliSec,u32 Copy_u32OFFDelayMiliSec)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(LEDConfig != NULL)
    {
        GPIO_enumSetPinState(&LEDConfig->Pin,LEDConfig->Mode);
        _delay_ms(Copy_u32ONDelayMiliSec);
        GPIO_enumSetPinState(&LEDConfig->Pin,!(LEDConfig->Mode));
        _delay_ms(Copy_u32OFFDelayMiliSec);
    }

    else
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}