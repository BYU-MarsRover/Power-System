/*******************************************************************************
* File Name: Ground.h  
* Version 2.0
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

#if !defined(CY_PINS_Ground_H) /* Pins Ground_H */
#define CY_PINS_Ground_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Ground_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Ground_Write(uint8 value) ;
void    Ground_SetDriveMode(uint8 mode) ;
uint8   Ground_ReadDataReg(void) ;
uint8   Ground_Read(void) ;
uint8   Ground_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Ground_DRIVE_MODE_BITS        (3)
#define Ground_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Ground_DRIVE_MODE_BITS))
#define Ground_DRIVE_MODE_SHIFT       (0x00u)
#define Ground_DRIVE_MODE_MASK        (0x07u << Ground_DRIVE_MODE_SHIFT)

#define Ground_DM_ALG_HIZ         (0x00u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_DIG_HIZ         (0x01u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_RES_UP          (0x02u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_RES_DWN         (0x03u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_OD_LO           (0x04u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_OD_HI           (0x05u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_STRONG          (0x06u << Ground_DRIVE_MODE_SHIFT)
#define Ground_DM_RES_UPDWN       (0x07u << Ground_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Ground_MASK               Ground__MASK
#define Ground_SHIFT              Ground__SHIFT
#define Ground_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ground_PS                     (* (reg32 *) Ground__PS)
/* Port Configuration */
#define Ground_PC                     (* (reg32 *) Ground__PC)
/* Data Register */
#define Ground_DR                     (* (reg32 *) Ground__DR)
/* Input Buffer Disable Override */
#define Ground_INP_DIS                (* (reg32 *) Ground__PC2)


#if defined(Ground__INTSTAT)  /* Interrupt Registers */

    #define Ground_INTSTAT                (* (reg32 *) Ground__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Ground_H */


/* [] END OF FILE */
