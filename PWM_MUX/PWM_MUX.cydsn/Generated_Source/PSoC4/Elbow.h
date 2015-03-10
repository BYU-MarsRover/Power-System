/*******************************************************************************
* File Name: Elbow.h  
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

#if !defined(CY_PINS_Elbow_H) /* Pins Elbow_H */
#define CY_PINS_Elbow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Elbow_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Elbow_Write(uint8 value) ;
void    Elbow_SetDriveMode(uint8 mode) ;
uint8   Elbow_ReadDataReg(void) ;
uint8   Elbow_Read(void) ;
uint8   Elbow_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Elbow_DRIVE_MODE_BITS        (3)
#define Elbow_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Elbow_DRIVE_MODE_BITS))

#define Elbow_DM_ALG_HIZ         (0x00u)
#define Elbow_DM_DIG_HIZ         (0x01u)
#define Elbow_DM_RES_UP          (0x02u)
#define Elbow_DM_RES_DWN         (0x03u)
#define Elbow_DM_OD_LO           (0x04u)
#define Elbow_DM_OD_HI           (0x05u)
#define Elbow_DM_STRONG          (0x06u)
#define Elbow_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Elbow_MASK               Elbow__MASK
#define Elbow_SHIFT              Elbow__SHIFT
#define Elbow_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Elbow_PS                     (* (reg32 *) Elbow__PS)
/* Port Configuration */
#define Elbow_PC                     (* (reg32 *) Elbow__PC)
/* Data Register */
#define Elbow_DR                     (* (reg32 *) Elbow__DR)
/* Input Buffer Disable Override */
#define Elbow_INP_DIS                (* (reg32 *) Elbow__PC2)


#if defined(Elbow__INTSTAT)  /* Interrupt Registers */

    #define Elbow_INTSTAT                (* (reg32 *) Elbow__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Elbow_DRIVE_MODE_SHIFT       (0x00u)
#define Elbow_DRIVE_MODE_MASK        (0x07u << Elbow_DRIVE_MODE_SHIFT)


#endif /* End Pins Elbow_H */


/* [] END OF FILE */
