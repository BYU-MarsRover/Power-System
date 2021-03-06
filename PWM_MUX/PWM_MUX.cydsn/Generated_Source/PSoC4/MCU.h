/*******************************************************************************
* File Name: MCU.h  
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

#if !defined(CY_PINS_MCU_H) /* Pins MCU_H */
#define CY_PINS_MCU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MCU_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MCU_Write(uint8 value) ;
void    MCU_SetDriveMode(uint8 mode) ;
uint8   MCU_ReadDataReg(void) ;
uint8   MCU_Read(void) ;
uint8   MCU_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MCU_DRIVE_MODE_BITS        (3)
#define MCU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MCU_DRIVE_MODE_BITS))

#define MCU_DM_ALG_HIZ         (0x00u)
#define MCU_DM_DIG_HIZ         (0x01u)
#define MCU_DM_RES_UP          (0x02u)
#define MCU_DM_RES_DWN         (0x03u)
#define MCU_DM_OD_LO           (0x04u)
#define MCU_DM_OD_HI           (0x05u)
#define MCU_DM_STRONG          (0x06u)
#define MCU_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define MCU_MASK               MCU__MASK
#define MCU_SHIFT              MCU__SHIFT
#define MCU_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MCU_PS                     (* (reg32 *) MCU__PS)
/* Port Configuration */
#define MCU_PC                     (* (reg32 *) MCU__PC)
/* Data Register */
#define MCU_DR                     (* (reg32 *) MCU__DR)
/* Input Buffer Disable Override */
#define MCU_INP_DIS                (* (reg32 *) MCU__PC2)


#if defined(MCU__INTSTAT)  /* Interrupt Registers */

    #define MCU_INTSTAT                (* (reg32 *) MCU__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define MCU_DRIVE_MODE_SHIFT       (0x00u)
#define MCU_DRIVE_MODE_MASK        (0x07u << MCU_DRIVE_MODE_SHIFT)


#endif /* End Pins MCU_H */


/* [] END OF FILE */
