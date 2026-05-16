/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Timestamp: 20/6/2022                                                             *
*			                                 File: LED_Interface.h                                                            *
*			                                 [ LED Module Driver ]                                                            *
******************************************************************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* LED STATEs INTERFACE OPTIONs */
typedef enum LED_STATE
{
    OFF = 0,
    ON
}State_t;


/* LED ACTIVATION MODEs INTERFACE OPTIONs */
typedef enum LED_ACTIVATIONMODE
{
    ACTIVELOW = 0,
    ACTIVEHIGH
}ActivationMode_t;


/* LED CONFIGURATION OBJECT DEFINITION */
typedef struct LED_CONFIGURATION
{
    GPIO_PinConfig   Pin;
    ActivationMode_t Mode:8;
}LED_t;


VALIDATION LED_enumInit(const LED_t *LEDConfig);
VALIDATION LED_enumPowerON (const LED_t *LEDConfig);
VALIDATION LED_enumPowerOFF (const LED_t *LEDConfig);
VALIDATION LED_enumToggleState (const LED_t *LEDConfig);
VALIDATION LED_enumScanCurrentState(const LED_t *LEDConfig,State_t *PtrState);
VALIDATION LED_enumStaticBlink(const LED_t *LEDConfig,u32 Copy_u32DelayMiliSec);
VALIDATION LED_enumDynamicBlink(const LED_t *LEDConfig,u32 Copy_u32ONDelayMiliSec,u32 Copy_u32OFFDelayMiliSec);

#endif /* LED_INTERFACE_H_ */