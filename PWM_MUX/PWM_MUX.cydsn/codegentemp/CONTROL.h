/*******************************************************************************
* File Name: CONTROL.h  
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

#if !defined(CY_PINS_CONTROL_H) /* Pins CONTROL_H */
#define CY_PINS_CONTROL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CONTROL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CONTROL_Write(uint8 value) ;
void    CONTROL_SetDriveMode(uint8 mode) ;
uint8   CONTROL_ReadDataReg(void) ;
uint8   CONTROL_Read(void) ;
uint8   CONTROL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CONTROL_DRIVE_MODE_BITS        (3)
#define CONTROL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CONTROL_DRIVE_MODE_BITS))

#define CONTROL_DM_ALG_HIZ         (0x00u)
#define CONTROL_DM_DIG_HIZ         (0x01u)
#define CONTROL_DM_RES_UP          (0x02u)
#define CONTROL_DM_RES_DWN         (0x03u)
#define CONTROL_DM_OD_LO           (0x04u)
#define CONTROL_DM_OD_HI           (0x05u)
#define CONTROL_DM_STRONG          (0x06u)
#define CONTROL_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define CONTROL_MASK               CONTROL__MASK
#define CONTROL_SHIFT              CONTROL__SHIFT
#define CONTROL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CONTROL_PS                     (* (reg32 *) CONTROL__PS)
/* Port Configuration */
#define CONTROL_PC                     (* (reg32 *) CONTROL__PC)
/* Data Register */
#define CONTROL_DR                     (* (reg32 *) CONTROL__DR)
/* Input Buffer Disable Override */
#define CONTROL_INP_DIS                (* (reg32 *) CONTROL__PC2)


#if defined(CONTROL__INTSTAT)  /* Interrupt Registers */

    #define CONTROL_INTSTAT                (* (reg32 *) CONTROL__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define CONTROL_DRIVE_MODE_SHIFT       (0x00u)
#define CONTROL_DRIVE_MODE_MASK        (0x07u << CONTROL_DRIVE_MODE_SHIFT)


#endif /* End Pins CONTROL_H */


/* [] END OF FILE */
