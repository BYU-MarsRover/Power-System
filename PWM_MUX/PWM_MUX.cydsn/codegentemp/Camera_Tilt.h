/*******************************************************************************
* File Name: Camera_Tilt.h  
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

#if !defined(CY_PINS_Camera_Tilt_H) /* Pins Camera_Tilt_H */
#define CY_PINS_Camera_Tilt_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Camera_Tilt_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Camera_Tilt_Write(uint8 value) ;
void    Camera_Tilt_SetDriveMode(uint8 mode) ;
uint8   Camera_Tilt_ReadDataReg(void) ;
uint8   Camera_Tilt_Read(void) ;
uint8   Camera_Tilt_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Camera_Tilt_DRIVE_MODE_BITS        (3)
#define Camera_Tilt_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Camera_Tilt_DRIVE_MODE_BITS))

#define Camera_Tilt_DM_ALG_HIZ         (0x00u)
#define Camera_Tilt_DM_DIG_HIZ         (0x01u)
#define Camera_Tilt_DM_RES_UP          (0x02u)
#define Camera_Tilt_DM_RES_DWN         (0x03u)
#define Camera_Tilt_DM_OD_LO           (0x04u)
#define Camera_Tilt_DM_OD_HI           (0x05u)
#define Camera_Tilt_DM_STRONG          (0x06u)
#define Camera_Tilt_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Camera_Tilt_MASK               Camera_Tilt__MASK
#define Camera_Tilt_SHIFT              Camera_Tilt__SHIFT
#define Camera_Tilt_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Camera_Tilt_PS                     (* (reg32 *) Camera_Tilt__PS)
/* Port Configuration */
#define Camera_Tilt_PC                     (* (reg32 *) Camera_Tilt__PC)
/* Data Register */
#define Camera_Tilt_DR                     (* (reg32 *) Camera_Tilt__DR)
/* Input Buffer Disable Override */
#define Camera_Tilt_INP_DIS                (* (reg32 *) Camera_Tilt__PC2)


#if defined(Camera_Tilt__INTSTAT)  /* Interrupt Registers */

    #define Camera_Tilt_INTSTAT                (* (reg32 *) Camera_Tilt__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Camera_Tilt_DRIVE_MODE_SHIFT       (0x00u)
#define Camera_Tilt_DRIVE_MODE_MASK        (0x07u << Camera_Tilt_DRIVE_MODE_SHIFT)


#endif /* End Pins Camera_Tilt_H */


/* [] END OF FILE */
