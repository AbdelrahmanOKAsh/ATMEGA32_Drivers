/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Timestamp: 20/6/2022                                                               *
*			                             File: GPIO_Program.c                                                               *
*			                             [GPIO Module Driver]                                                               *
****************************************************************************************************************************/

#include "../../../LIBs/STD_TYPES.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

/* GPIOx IS AN ARRAY THAT HOLD POINTERS TO GPIOS PORTS [ GPIOA , GPIOB , GPIOC , GPIOD ] */
static GPIO_REG* GPIOx[] = { GPIOA , GPIOB , GPIOC , GPIOD };


/* PORTSIZEMASK IS AN ARRAY THAT HOLD EACH PORT SIZE MASK TO CORRESPONDING PORT SIZE */
static u8 PortSizeMask[] = { 0b11 , 0b111 , 0b1111 , 0b11111 , 0b111111 , 0b1111111 , 0b11111111 };


/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO CONFIGURE A GPIO PIN                                                                                *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE                                                        *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumPinInit (const GPIO_PinConfig *PinConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        if((PinConfig->PortID <= PORTD) && (PinConfig->PinID <= PIN7) && (PinConfig->PinMode <= INPUT_INTERNALPULLUP))
        {
            switch(PinConfig->PinMode)
            {
                case INPUT_FLOATING : GPIOx[PinConfig->PortID]->DDR  &= ~(1 << PinConfig->PinID);
                                      GPIOx[PinConfig->PortID]->PORT &= ~(1 << PinConfig->PinID);
                                      break;
                case OUTPUT         : GPIOx[PinConfig->PortID]->DDR |=  (1 << PinConfig->PinID);
                                      break;
                case INPUT_INTERNALPULLUP: GPIOx[PinConfig->PortID]->DDR  &= ~(1 << PinConfig->PinID);
                                           GPIOx[PinConfig->PortID]->PORT |=  (1 << PinConfig->PinID);
                                           SFIO &= ~(1 << PUPD);
                                           break; 
                default: Local_ValidationStatus = INVALID; break;
            }
        }

        else
        {
            Local_ValidationStatus = INVALID;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SET GPIO PIN STATE                                                                                  *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE , PIN STATE                                            *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumSetPinState (const GPIO_PinConfig *PinConfig,PinState_t Copy_enumPinState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        switch(Copy_enumPinState)
        {
            case LOW : GPIOx[PinConfig->PortID]->PORT &= ~(1 << PinConfig->PinID); break;
            case HIGH: GPIOx[PinConfig->PortID]->PORT |=  (1 << PinConfig->PinID); break;
            default  : Local_ValidationStatus = INVALID;                           break;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SCAN A GPIO PIN STATE                                                                               *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE , POINTER TO [ PinState_t ] DEFINED TYPE               *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumScanPinState (const GPIO_PinConfig *PinConfig,PinState_t* PtrPinState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        switch(PinConfig->PinMode)
        {
            case INPUT_FLOATING      : *PtrPinState = ((GPIOx[PinConfig->PortID]->PIN  >> PinConfig->PinID) & 1); break;
            case OUTPUT              : *PtrPinState = ((GPIOx[PinConfig->PortID]->PORT >> PinConfig->PinID) & 1); break;
            case INPUT_INTERNALPULLUP: *PtrPinState = ((GPIOx[PinConfig->PortID]->PIN  >> PinConfig->PinID) & 1); break;
            default                  : Local_ValidationStatus = INVALID;                                          break;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO TOGGLE A GPIO PIN STATE                                                                             *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE                                                        *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumTogglePinState (const GPIO_PinConfig *PinConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        GPIOx[PinConfig->PortID]->PORT ^= (1 << PinConfig->PinID);
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO CONFIGURE A GPIO PORT                                                                               *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PortConfig ] DEFINED TYPE                                                       *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumPortInit (const GPIO_PortConfig *PortConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        if((PortConfig->PortID <= PORTD) && (PortConfig->PortInitPinID <= PIN7) && (PortConfig->PortSize <= PORTSIZE_8) && (PortConfig->PortMode <= INPUT_INTERNALPULLUP))
        {
            switch(PortConfig->PortMode)
            {
                case INPUT_FLOATING: GPIOx[PortConfig->PortID]->DDR  &= ~(PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
                                     GPIOx[PortConfig->PortID]->PORT &= ~(PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
                                     break;
                case OUTPUT        : GPIOx[PortConfig->PortID]->DDR |= (PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
                                     break;
                case INPUT_INTERNALPULLUP: GPIOx[PortConfig->PortID]->DDR  &= ~(PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
                                           GPIOx[PortConfig->PortID]->PORT |=  (PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
                                           SFIO &= ~(1 << PUPD);
                                           break;
            }
        }

        else
        {
            Local_ValidationStatus = INVALID;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SET GPIO PORT STATE                                                                                 *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PortConfig ] DEFINED TYPE , PORT STATE ]                                        *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumSetPortState (const GPIO_PortConfig *PortConfig,PortState_t Copy_enumPortState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        GPIOx[PortConfig->PortID]->PORT &= ~(PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
        GPIOx[PortConfig->PortID]->PORT |=  (             Copy_enumPortState        << PortConfig->PortInitPinID); 
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SCAN A GPIO PORT STATE                                                                              *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PortConfig ] DEFINED TYPE , POINTER TO [ PortState_t ] DEFINED TYPE             *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumScanPortState (const GPIO_PortConfig *PortConfig,PortState_t* PtrPortState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        switch(PortConfig->PortMode)
        {
            case INPUT_FLOATING      : *PtrPortState = ((GPIOx[PortConfig->PortID]->PIN  >> PortConfig->PortInitPinID) & PortSizeMask[PortConfig->PortSize - 2]); break;
            case OUTPUT              : *PtrPortState = ((GPIOx[PortConfig->PortID]->PORT >> PortConfig->PortInitPinID) & PortSizeMask[PortConfig->PortSize - 2]); break;
            case INPUT_INTERNALPULLUP: *PtrPortState = ((GPIOx[PortConfig->PortID]->PIN  >> PortConfig->PortInitPinID) & PortSizeMask[PortConfig->PortSize - 2]); break;
            default                  : Local_ValidationStatus = INVALID;                                                                                          break;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO TOGGLE A GPIO PORT STATE                                                                            *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PortConfig ] DEFINED TYPE                                                       *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumTogglePortState (const GPIO_PortConfig *PortConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        GPIOx[PortConfig->PortID]->PORT ^= (PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}