/*******************************************************************************
* File Name: Shoulder_Backup.h  
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

#if !defined(CY_PINS_Shoulder_Backup_H) /* Pins Shoulder_Backup_H */
#define CY_PINS_Shoulder_Backup_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Shoulder_Backup_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Shoulder_Backup_Write(uint8 value) ;
void    Shoulder_Backup_SetDriveMode(uint8 mode) ;
uint8   Shoulder_Backup_ReadDataReg(void) ;
uint8   Shoulder_Backup_Read(void) ;
uint8   Shoulder_Backup_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Shoulder_Backup_DRIVE_MODE_BITS        (3)
#define Shoulder_Backup_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Shoulder_Backup_DRIVE_MODE_BITS))

#define Shoulder_Backup_DM_ALG_HIZ         (0x00u)
#define Shoulder_Backup_DM_DIG_HIZ         (0x01u)
#define Shoulder_Backup_DM_RES_UP          (0x02u)
#define Shoulder_Backup_DM_RES_DWN         (0x03u)
#define Shoulder_Backup_DM_OD_LO           (0x04u)
#define Shoulder_Backup_DM_OD_HI           (0x05u)
#define Shoulder_Backup_DM_STRONG          (0x06u)
#define Shoulder_Backup_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Shoulder_Backup_MASK               Shoulder_Backup__MASK
#define Shoulder_Backup_SHIFT              Shoulder_Backup__SHIFT
#define Shoulder_Backup_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Shoulder_Backup_PS                     (* (reg32 *) Shoulder_Backup__PS)
/* Port Configuration */
#define Shoulder_Backup_PC                     (* (reg32 *) Shoulder_Backup__PC)
/* Data Register */
#define Shoulder_Backup_DR                     (* (reg32 *) Shoulder_Backup__DR)
/* Input Buffer Disable Override */
#define Shoulder_Backup_INP_DIS                (* (reg32 *) Shoulder_Backup__PC2)


#if defined(Shoulder_Backup__INTSTAT)  /* Interrupt Registers */

    #define Shoulder_Backup_INTSTAT                (* (reg32 *) Shoulder_Backup__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Shoulder_Backup_DRIVE_MODE_SHIFT       (0x00u)
#define Shoulder_Backup_DRIVE_MODE_MASK        (0x07u << Shoulder_Backup_DRIVE_MODE_SHIFT)


#endif /* End Pins Shoulder_Backup_H */


/* [] END OF FILE */
