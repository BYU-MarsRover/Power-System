/*******************************************************************************
* File Name: Hand.h  
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

#if !defined(CY_PINS_Hand_H) /* Pins Hand_H */
#define CY_PINS_Hand_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Hand_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Hand_Write(uint8 value) ;
void    Hand_SetDriveMode(uint8 mode) ;
uint8   Hand_ReadDataReg(void) ;
uint8   Hand_Read(void) ;
uint8   Hand_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Hand_DRIVE_MODE_BITS        (3)
#define Hand_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Hand_DRIVE_MODE_BITS))

#define Hand_DM_ALG_HIZ         (0x00u)
#define Hand_DM_DIG_HIZ         (0x01u)
#define Hand_DM_RES_UP          (0x02u)
#define Hand_DM_RES_DWN         (0x03u)
#define Hand_DM_OD_LO           (0x04u)
#define Hand_DM_OD_HI           (0x05u)
#define Hand_DM_STRONG          (0x06u)
#define Hand_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Hand_MASK               Hand__MASK
#define Hand_SHIFT              Hand__SHIFT
#define Hand_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Hand_PS                     (* (reg32 *) Hand__PS)
/* Port Configuration */
#define Hand_PC                     (* (reg32 *) Hand__PC)
/* Data Register */
#define Hand_DR                     (* (reg32 *) Hand__DR)
/* Input Buffer Disable Override */
#define Hand_INP_DIS                (* (reg32 *) Hand__PC2)


#if defined(Hand__INTSTAT)  /* Interrupt Registers */

    #define Hand_INTSTAT                (* (reg32 *) Hand__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Hand_DRIVE_MODE_SHIFT       (0x00u)
#define Hand_DRIVE_MODE_MASK        (0x07u << Hand_DRIVE_MODE_SHIFT)


#endif /* End Pins Hand_H */


/* [] END OF FILE */
