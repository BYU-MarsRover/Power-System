/*******************************************************************************
* File Name: Elbow_MUC.h  
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

#if !defined(CY_PINS_Elbow_MUC_H) /* Pins Elbow_MUC_H */
#define CY_PINS_Elbow_MUC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Elbow_MUC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Elbow_MUC_Write(uint8 value) ;
void    Elbow_MUC_SetDriveMode(uint8 mode) ;
uint8   Elbow_MUC_ReadDataReg(void) ;
uint8   Elbow_MUC_Read(void) ;
uint8   Elbow_MUC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Elbow_MUC_DRIVE_MODE_BITS        (3)
#define Elbow_MUC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Elbow_MUC_DRIVE_MODE_BITS))

#define Elbow_MUC_DM_ALG_HIZ         (0x00u)
#define Elbow_MUC_DM_DIG_HIZ         (0x01u)
#define Elbow_MUC_DM_RES_UP          (0x02u)
#define Elbow_MUC_DM_RES_DWN         (0x03u)
#define Elbow_MUC_DM_OD_LO           (0x04u)
#define Elbow_MUC_DM_OD_HI           (0x05u)
#define Elbow_MUC_DM_STRONG          (0x06u)
#define Elbow_MUC_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Elbow_MUC_MASK               Elbow_MUC__MASK
#define Elbow_MUC_SHIFT              Elbow_MUC__SHIFT
#define Elbow_MUC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Elbow_MUC_PS                     (* (reg32 *) Elbow_MUC__PS)
/* Port Configuration */
#define Elbow_MUC_PC                     (* (reg32 *) Elbow_MUC__PC)
/* Data Register */
#define Elbow_MUC_DR                     (* (reg32 *) Elbow_MUC__DR)
/* Input Buffer Disable Override */
#define Elbow_MUC_INP_DIS                (* (reg32 *) Elbow_MUC__PC2)


#if defined(Elbow_MUC__INTSTAT)  /* Interrupt Registers */

    #define Elbow_MUC_INTSTAT                (* (reg32 *) Elbow_MUC__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Elbow_MUC_DRIVE_MODE_SHIFT       (0x00u)
#define Elbow_MUC_DRIVE_MODE_MASK        (0x07u << Elbow_MUC_DRIVE_MODE_SHIFT)


#endif /* End Pins Elbow_MUC_H */


/* [] END OF FILE */
