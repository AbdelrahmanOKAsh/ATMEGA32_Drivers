/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Timestamp: 20/6/2022                                                               *
*			                             File: SSD_Program.c                                                                *
*			                             [ SSD Module Driver ]                                                              *
****************************************************************************************************************************/


#include "../../../LIBs/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO v2.0/GPIO_Interface.h"
#include "SSD_Interface.h"



/* REPRESNTAION OF THE NUMBERS FROM [ 0 -> 9 ] ON THE 7-SEG [ COMMON CATHODE ] DISPLAY [ THE CONTENTS IN THE ARRAY IN HEXADECIMAL ] */
static u8 const SSD_DataArr[]={ 0x3F, 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0xFF , 0x6F };
/*                                0     1      2      3      4      5      6      7      8      9                                   */



/*******************************************************************************************************************************
* BRIEF:  FUNCTION USED TO CONFIGURE A 7-SEG                                                                                   *
* PARAMETERS: A POINTER TO AN OBJECT FROM [ SSD_t ] DEFINED TYPE                                                               *
* RETURN: ENUM                                                                                                                 *
*******************************************************************************************************************************/
VALIDATION SSD_enumInit (const SSD_t *SSD_CONFIG)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if (SSD_CONFIG != NULL)
    {
        if((SSD_CONFIG->CommonMode <= COMMON_ANODE) && (SSD_CONFIG->DataPortID <= GPIO_PORTD) && (SSD_CONFIG->EnablePortID <= GPIO_PORTD) && (SSD_CONFIG->EnablePinID <= GPIO_PIN7))
        {
            GPIO_SetPortMode(SSD_CONFIG->DataPortID,GPIO_PORT_OUTPUT);
            GPIO_SetPinMode(SSD_CONFIG->EnablePortID,SSD_CONFIG->EnablePinID,GPIO_PIN_OUTPUT);
            GPIO_SetPinValue(SSD_CONFIG->EnablePortID,SSD_CONFIG->EnablePinID,SSD_CONFIG->CommonMode);
            switch(SSD_CONFIG->CommonMode)
            {
                case COMMON_CATHODE: GPIO_SetPortValue(SSD_CONFIG->DataPortID,~SSD_DataArr[8]); break;
                case COMMON_ANODE  : GPIO_SetPortValue(SSD_CONFIG->DataPortID, SSD_DataArr[8]); break;
                default            : Local_enumValidationStatus = INVALID;                      break;
            }
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





/*******************************************************************************************************************************
* BRIEF:  FUNCTION USED TO ENABLE A 7-SEG                                                                                      *
* PARAMETERS: A POINTER TO AN OBJECT FROM [ SSD_t ] DEFINED TYPE                                                               *
* RETURN: ENUM                                                                                                                 *
*******************************************************************************************************************************/
VALIDATION SSD_enumEnable (const SSD_t *SSD_CONFIG)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(SSD_CONFIG != NULL)
    {
        GPIO_SetPinValue(SSD_CONFIG->EnablePortID,SSD_CONFIG->EnablePinID,SSD_CONFIG->CommonMode);
    }

    else 
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/*******************************************************************************************************************************
* BRIEF:  FUNCTION USED TO DISABLE A 7-SEG                                                                                     *
* PARAMETERS: A POINTER TO AN OBJECT FROM [ SSD_t ] DEFINED TYPE                                                               *
* RETURN: ENUM                                                                                                                 *
*******************************************************************************************************************************/
VALIDATION SSD_enumDisable (const SSD_t *SSD_CONFIG)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(SSD_CONFIG != NULL)
    {
        GPIO_SetPinValue(SSD_CONFIG->EnablePortID,SSD_CONFIG->EnablePinID,!SSD_CONFIG->CommonMode);
    }

    else 
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}





/*******************************************************************************************************************************
* BRIEF:  FUNCTION USED TO PRINT A NUMBER ON 7-SEG                                                                             *
* PARAMETERS: A POINTER TO AN OBJECT FROM [ SSD_t ] DEFINED TYPE , NUMBER                                                      *
* RETURN: ENUM                                                                                                                 *
*******************************************************************************************************************************/
VALIDATION SSD_enumPrintNumber (const SSD_t *SSD_CONFIG,u8 Copy_u8Number)
{
    VALIDATION Local_enumValidationStatus = VALID;
    if(SSD_CONFIG != NULL)
    {
        switch(SSD_CONFIG->CommonMode)
        {
            case COMMON_CATHODE: GPIO_SetPortValue(SSD_CONFIG->DataPortID, SSD_DataArr[Copy_u8Number]); break;
            case COMMON_ANODE  : GPIO_SetPortValue(SSD_CONFIG->DataPortID,~SSD_DataArr[Copy_u8Number]); break;
            default            : Local_enumValidationStatus = INVALID;                                  break;
        }
    }

    else 
    {
        Local_enumValidationStatus = NULL_POINTER;
    }

    return Local_enumValidationStatus;
}