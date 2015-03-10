/*******************************************************************************
* File Name: INPUT_SELECT.h  
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

#if !defined(CY_PINS_INPUT_SELECT_H) /* Pins INPUT_SELECT_H */
#define CY_PINS_INPUT_SELECT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "INPUT_SELECT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    INPUT_SELECT_Write(uint8 value) ;
void    INPUT_SELECT_SetDriveMode(uint8 mode) ;
uint8   INPUT_SELECT_ReadDataReg(void) ;
uint8   INPUT_SELECT_Read(void) ;
uint8   INPUT_SELECT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define INPUT_SELECT_DRIVE_MODE_BITS        (3)
#define INPUT_SELECT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - INPUT_SELECT_DRIVE_MODE_BITS))

#define INPUT_SELECT_DM_ALG_HIZ         (0x00u)
#define INPUT_SELECT_DM_DIG_HIZ         (0x01u)
#define INPUT_SELECT_DM_RES_UP          (0x02u)
#define INPUT_SELECT_DM_RES_DWN         (0x03u)
#define INPUT_SELECT_DM_OD_LO           (0x04u)
#define INPUT_SELECT_DM_OD_HI           (0x05u)
#define INPUT_SELECT_DM_STRONG          (0x06u)
#define INPUT_SELECT_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define INPUT_SELECT_MASK               INPUT_SELECT__MASK
#define INPUT_SELECT_SHIFT              INPUT_SELECT__SHIFT
#define INPUT_SELECT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define INPUT_SELECT_PS                     (* (reg32 *) INPUT_SELECT__PS)
/* Port Configuration */
#define INPUT_SELECT_PC                     (* (reg32 *) INPUT_SELECT__PC)
/* Data Register */
#define INPUT_SELECT_DR                     (* (reg32 *) INPUT_SELECT__DR)
/* Input Buffer Disable Override */
#define INPUT_SELECT_INP_DIS                (* (reg32 *) INPUT_SELECT__PC2)


#if defined(INPUT_SELECT__INTSTAT)  /* Interrupt Registers */

    #define INPUT_SELECT_INTSTAT                (* (reg32 *) INPUT_SELECT__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define INPUT_SELECT_DRIVE_MODE_SHIFT       (0x00u)
#define INPUT_SELECT_DRIVE_MODE_MASK        (0x07u << INPUT_SELECT_DRIVE_MODE_SHIFT)


#endif /* End Pins INPUT_SELECT_H */


/* [] END OF FILE */
