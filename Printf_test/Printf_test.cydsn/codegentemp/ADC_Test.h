/*******************************************************************************
* File Name: ADC_Test.h  
* Version 2.0
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

#if !defined(CY_PINS_ADC_Test_H) /* Pins ADC_Test_H */
#define CY_PINS_ADC_Test_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ADC_Test_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ADC_Test_Write(uint8 value) ;
void    ADC_Test_SetDriveMode(uint8 mode) ;
uint8   ADC_Test_ReadDataReg(void) ;
uint8   ADC_Test_Read(void) ;
uint8   ADC_Test_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADC_Test_DRIVE_MODE_BITS        (3)
#define ADC_Test_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ADC_Test_DRIVE_MODE_BITS))
#define ADC_Test_DRIVE_MODE_SHIFT       (0x00u)
#define ADC_Test_DRIVE_MODE_MASK        (0x07u << ADC_Test_DRIVE_MODE_SHIFT)

#define ADC_Test_DM_ALG_HIZ         (0x00u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_DIG_HIZ         (0x01u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_RES_UP          (0x02u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_RES_DWN         (0x03u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_OD_LO           (0x04u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_OD_HI           (0x05u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_STRONG          (0x06u << ADC_Test_DRIVE_MODE_SHIFT)
#define ADC_Test_DM_RES_UPDWN       (0x07u << ADC_Test_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define ADC_Test_MASK               ADC_Test__MASK
#define ADC_Test_SHIFT              ADC_Test__SHIFT
#define ADC_Test_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADC_Test_PS                     (* (reg32 *) ADC_Test__PS)
/* Port Configuration */
#define ADC_Test_PC                     (* (reg32 *) ADC_Test__PC)
/* Data Register */
#define ADC_Test_DR                     (* (reg32 *) ADC_Test__DR)
/* Input Buffer Disable Override */
#define ADC_Test_INP_DIS                (* (reg32 *) ADC_Test__PC2)


#if defined(ADC_Test__INTSTAT)  /* Interrupt Registers */

    #define ADC_Test_INTSTAT                (* (reg32 *) ADC_Test__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins ADC_Test_H */


/* [] END OF FILE */
