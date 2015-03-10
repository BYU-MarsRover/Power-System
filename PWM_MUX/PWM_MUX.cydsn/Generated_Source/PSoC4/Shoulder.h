/*******************************************************************************
* File Name: Shoulder.h  
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

#if !defined(CY_PINS_Shoulder_H) /* Pins Shoulder_H */
#define CY_PINS_Shoulder_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Shoulder_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Shoulder_Write(uint8 value) ;
void    Shoulder_SetDriveMode(uint8 mode) ;
uint8   Shoulder_ReadDataReg(void) ;
uint8   Shoulder_Read(void) ;
uint8   Shoulder_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Shoulder_DRIVE_MODE_BITS        (3)
#define Shoulder_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Shoulder_DRIVE_MODE_BITS))

#define Shoulder_DM_ALG_HIZ         (0x00u)
#define Shoulder_DM_DIG_HIZ         (0x01u)
#define Shoulder_DM_RES_UP          (0x02u)
#define Shoulder_DM_RES_DWN         (0x03u)
#define Shoulder_DM_OD_LO           (0x04u)
#define Shoulder_DM_OD_HI           (0x05u)
#define Shoulder_DM_STRONG          (0x06u)
#define Shoulder_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Shoulder_MASK               Shoulder__MASK
#define Shoulder_SHIFT              Shoulder__SHIFT
#define Shoulder_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Shoulder_PS                     (* (reg32 *) Shoulder__PS)
/* Port Configuration */
#define Shoulder_PC                     (* (reg32 *) Shoulder__PC)
/* Data Register */
#define Shoulder_DR                     (* (reg32 *) Shoulder__DR)
/* Input Buffer Disable Override */
#define Shoulder_INP_DIS                (* (reg32 *) Shoulder__PC2)


#if defined(Shoulder__INTSTAT)  /* Interrupt Registers */

    #define Shoulder_INTSTAT                (* (reg32 *) Shoulder__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Shoulder_DRIVE_MODE_SHIFT       (0x00u)
#define Shoulder_DRIVE_MODE_MASK        (0x07u << Shoulder_DRIVE_MODE_SHIFT)


#endif /* End Pins Shoulder_H */


/* [] END OF FILE */
