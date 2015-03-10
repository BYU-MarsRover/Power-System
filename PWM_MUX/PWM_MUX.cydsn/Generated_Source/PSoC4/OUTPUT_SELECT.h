/*******************************************************************************
* File Name: OUTPUT_SELECT.h  
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

#if !defined(CY_PINS_OUTPUT_SELECT_H) /* Pins OUTPUT_SELECT_H */
#define CY_PINS_OUTPUT_SELECT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "OUTPUT_SELECT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    OUTPUT_SELECT_Write(uint8 value) ;
void    OUTPUT_SELECT_SetDriveMode(uint8 mode) ;
uint8   OUTPUT_SELECT_ReadDataReg(void) ;
uint8   OUTPUT_SELECT_Read(void) ;
uint8   OUTPUT_SELECT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OUTPUT_SELECT_DRIVE_MODE_BITS        (3)
#define OUTPUT_SELECT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - OUTPUT_SELECT_DRIVE_MODE_BITS))

#define OUTPUT_SELECT_DM_ALG_HIZ         (0x00u)
#define OUTPUT_SELECT_DM_DIG_HIZ         (0x01u)
#define OUTPUT_SELECT_DM_RES_UP          (0x02u)
#define OUTPUT_SELECT_DM_RES_DWN         (0x03u)
#define OUTPUT_SELECT_DM_OD_LO           (0x04u)
#define OUTPUT_SELECT_DM_OD_HI           (0x05u)
#define OUTPUT_SELECT_DM_STRONG          (0x06u)
#define OUTPUT_SELECT_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define OUTPUT_SELECT_MASK               OUTPUT_SELECT__MASK
#define OUTPUT_SELECT_SHIFT              OUTPUT_SELECT__SHIFT
#define OUTPUT_SELECT_WIDTH              3u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUTPUT_SELECT_PS                     (* (reg32 *) OUTPUT_SELECT__PS)
/* Port Configuration */
#define OUTPUT_SELECT_PC                     (* (reg32 *) OUTPUT_SELECT__PC)
/* Data Register */
#define OUTPUT_SELECT_DR                     (* (reg32 *) OUTPUT_SELECT__DR)
/* Input Buffer Disable Override */
#define OUTPUT_SELECT_INP_DIS                (* (reg32 *) OUTPUT_SELECT__PC2)


#if defined(OUTPUT_SELECT__INTSTAT)  /* Interrupt Registers */

    #define OUTPUT_SELECT_INTSTAT                (* (reg32 *) OUTPUT_SELECT__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define OUTPUT_SELECT_DRIVE_MODE_SHIFT       (0x00u)
#define OUTPUT_SELECT_DRIVE_MODE_MASK        (0x07u << OUTPUT_SELECT_DRIVE_MODE_SHIFT)


#endif /* End Pins OUTPUT_SELECT_H */


/* [] END OF FILE */
