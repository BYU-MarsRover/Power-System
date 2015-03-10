/*******************************************************************************
* File Name: Drive_Right_MCU.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Drive_Right_MCU_H) /* Pins Drive_Right_MCU_H */
#define CY_PINS_Drive_Right_MCU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Drive_Right_MCU_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Drive_Right_MCU_Write(uint8 value) ;
void    Drive_Right_MCU_SetDriveMode(uint8 mode) ;
uint8   Drive_Right_MCU_ReadDataReg(void) ;
uint8   Drive_Right_MCU_Read(void) ;
uint8   Drive_Right_MCU_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Drive_Right_MCU_DRIVE_MODE_BITS        (3)
#define Drive_Right_MCU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Drive_Right_MCU_DRIVE_MODE_BITS))

#define Drive_Right_MCU_DM_ALG_HIZ         (0x00u)
#define Drive_Right_MCU_DM_DIG_HIZ         (0x01u)
#define Drive_Right_MCU_DM_RES_UP          (0x02u)
#define Drive_Right_MCU_DM_RES_DWN         (0x03u)
#define Drive_Right_MCU_DM_OD_LO           (0x04u)
#define Drive_Right_MCU_DM_OD_HI           (0x05u)
#define Drive_Right_MCU_DM_STRONG          (0x06u)
#define Drive_Right_MCU_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Drive_Right_MCU_MASK               Drive_Right_MCU__MASK
#define Drive_Right_MCU_SHIFT              Drive_Right_MCU__SHIFT
#define Drive_Right_MCU_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Drive_Right_MCU_PS                     (* (reg32 *) Drive_Right_MCU__PS)
/* Port Configuration */
#define Drive_Right_MCU_PC                     (* (reg32 *) Drive_Right_MCU__PC)
/* Data Register */
#define Drive_Right_MCU_DR                     (* (reg32 *) Drive_Right_MCU__DR)
/* Input Buffer Disable Override */
#define Drive_Right_MCU_INP_DIS                (* (reg32 *) Drive_Right_MCU__PC2)


#if defined(Drive_Right_MCU__INTSTAT)  /* Interrupt Registers */

    #define Drive_Right_MCU_INTSTAT                (* (reg32 *) Drive_Right_MCU__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Drive_Right_MCU_DRIVE_MODE_SHIFT       (0x00u)
#define Drive_Right_MCU_DRIVE_MODE_MASK        (0x07u << Drive_Right_MCU_DRIVE_MODE_SHIFT)


#endif /* End Pins Drive_Right_MCU_H */


/* [] END OF FILE */
