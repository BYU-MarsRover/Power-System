/*******************************************************************************
* File Name: Turret_MCU.h  
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

#if !defined(CY_PINS_Turret_MCU_H) /* Pins Turret_MCU_H */
#define CY_PINS_Turret_MCU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Turret_MCU_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Turret_MCU_Write(uint8 value) ;
void    Turret_MCU_SetDriveMode(uint8 mode) ;
uint8   Turret_MCU_ReadDataReg(void) ;
uint8   Turret_MCU_Read(void) ;
uint8   Turret_MCU_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Turret_MCU_DRIVE_MODE_BITS        (3)
#define Turret_MCU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Turret_MCU_DRIVE_MODE_BITS))

#define Turret_MCU_DM_ALG_HIZ         (0x00u)
#define Turret_MCU_DM_DIG_HIZ         (0x01u)
#define Turret_MCU_DM_RES_UP          (0x02u)
#define Turret_MCU_DM_RES_DWN         (0x03u)
#define Turret_MCU_DM_OD_LO           (0x04u)
#define Turret_MCU_DM_OD_HI           (0x05u)
#define Turret_MCU_DM_STRONG          (0x06u)
#define Turret_MCU_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Turret_MCU_MASK               Turret_MCU__MASK
#define Turret_MCU_SHIFT              Turret_MCU__SHIFT
#define Turret_MCU_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Turret_MCU_PS                     (* (reg32 *) Turret_MCU__PS)
/* Port Configuration */
#define Turret_MCU_PC                     (* (reg32 *) Turret_MCU__PC)
/* Data Register */
#define Turret_MCU_DR                     (* (reg32 *) Turret_MCU__DR)
/* Input Buffer Disable Override */
#define Turret_MCU_INP_DIS                (* (reg32 *) Turret_MCU__PC2)


#if defined(Turret_MCU__INTSTAT)  /* Interrupt Registers */

    #define Turret_MCU_INTSTAT                (* (reg32 *) Turret_MCU__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Turret_MCU_DRIVE_MODE_SHIFT       (0x00u)
#define Turret_MCU_DRIVE_MODE_MASK        (0x07u << Turret_MCU_DRIVE_MODE_SHIFT)


#endif /* End Pins Turret_MCU_H */


/* [] END OF FILE */
