/*******************************************************************************
* File Name: Wrist_Tilt_MCU.h  
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

#if !defined(CY_PINS_Wrist_Tilt_MCU_H) /* Pins Wrist_Tilt_MCU_H */
#define CY_PINS_Wrist_Tilt_MCU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Wrist_Tilt_MCU_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Wrist_Tilt_MCU_Write(uint8 value) ;
void    Wrist_Tilt_MCU_SetDriveMode(uint8 mode) ;
uint8   Wrist_Tilt_MCU_ReadDataReg(void) ;
uint8   Wrist_Tilt_MCU_Read(void) ;
uint8   Wrist_Tilt_MCU_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Wrist_Tilt_MCU_DRIVE_MODE_BITS        (3)
#define Wrist_Tilt_MCU_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Wrist_Tilt_MCU_DRIVE_MODE_BITS))

#define Wrist_Tilt_MCU_DM_ALG_HIZ         (0x00u)
#define Wrist_Tilt_MCU_DM_DIG_HIZ         (0x01u)
#define Wrist_Tilt_MCU_DM_RES_UP          (0x02u)
#define Wrist_Tilt_MCU_DM_RES_DWN         (0x03u)
#define Wrist_Tilt_MCU_DM_OD_LO           (0x04u)
#define Wrist_Tilt_MCU_DM_OD_HI           (0x05u)
#define Wrist_Tilt_MCU_DM_STRONG          (0x06u)
#define Wrist_Tilt_MCU_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Wrist_Tilt_MCU_MASK               Wrist_Tilt_MCU__MASK
#define Wrist_Tilt_MCU_SHIFT              Wrist_Tilt_MCU__SHIFT
#define Wrist_Tilt_MCU_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Wrist_Tilt_MCU_PS                     (* (reg32 *) Wrist_Tilt_MCU__PS)
/* Port Configuration */
#define Wrist_Tilt_MCU_PC                     (* (reg32 *) Wrist_Tilt_MCU__PC)
/* Data Register */
#define Wrist_Tilt_MCU_DR                     (* (reg32 *) Wrist_Tilt_MCU__DR)
/* Input Buffer Disable Override */
#define Wrist_Tilt_MCU_INP_DIS                (* (reg32 *) Wrist_Tilt_MCU__PC2)


#if defined(Wrist_Tilt_MCU__INTSTAT)  /* Interrupt Registers */

    #define Wrist_Tilt_MCU_INTSTAT                (* (reg32 *) Wrist_Tilt_MCU__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Wrist_Tilt_MCU_DRIVE_MODE_SHIFT       (0x00u)
#define Wrist_Tilt_MCU_DRIVE_MODE_MASK        (0x07u << Wrist_Tilt_MCU_DRIVE_MODE_SHIFT)


#endif /* End Pins Wrist_Tilt_MCU_H */


/* [] END OF FILE */
