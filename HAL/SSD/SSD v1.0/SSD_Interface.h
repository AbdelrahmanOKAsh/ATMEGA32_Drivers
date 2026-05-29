/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Timestamp: 20/6/2022                                                             *
*			                                 File: SSD_Interface.h                                                            *
*			                                 [ SSD Module Driver ]                                                            *
******************************************************************************************************************************/


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


/* SSD OBJECT INTERFACE 1 BYTE [ 8 BITs ] SIZE */
typedef struct SSDx
{
    u8 CommonMode:1;
    u8 DataPortID:2;
    u8 EnablePortID:2;
    u8 EnablePinID:3;
}SSD_t;


/* SSD COMMON MODE INTERFACE */ 
#define COMMON_CATHODE          0
#define COMMON_ANODE            1


/*================================================ < PROVIDED APIs FOR SSD INTERFACING > ================================================*/


VALIDATION SSD_enumInit        (const SSD_t *SSD_CONFIG);
VALIDATION SSD_enumEnable      (const SSD_t *SSD_CONFIG);
VALIDATION SSD_enumDisable     (const SSD_t *SSD_CONFIG);
VALIDATION SSD_enumPrintNumber (const SSD_t *SSD_CONFIG,u8 Copy_u8Number);


#endif /* SSD_INTERFACE_H_ */