/*******************************************************************************
* File Name: CONTROL.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "CONTROL.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        CONTROL_PC =   (CONTROL_PC & \
                                (uint32)(~(uint32)(CONTROL_DRIVE_MODE_IND_MASK << (CONTROL_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (CONTROL_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: CONTROL_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void CONTROL_Write(uint8 value) 
{
    uint8 drVal = (uint8)(CONTROL_DR & (uint8)(~CONTROL_MASK));
    drVal = (drVal | ((uint8)(value << CONTROL_SHIFT) & CONTROL_MASK));
    CONTROL_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: CONTROL_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CONTROL_DM_STRONG     Strong Drive 
*  CONTROL_DM_OD_HI      Open Drain, Drives High 
*  CONTROL_DM_OD_LO      Open Drain, Drives Low 
*  CONTROL_DM_RES_UP     Resistive Pull Up 
*  CONTROL_DM_RES_DWN    Resistive Pull Down 
*  CONTROL_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CONTROL_DM_DIG_HIZ    High Impedance Digital 
*  CONTROL_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CONTROL_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(CONTROL__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: CONTROL_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro CONTROL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CONTROL_Read(void) 
{
    return (uint8)((CONTROL_PS & CONTROL_MASK) >> CONTROL_SHIFT);
}


/*******************************************************************************
* Function Name: CONTROL_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 CONTROL_ReadDataReg(void) 
{
    return (uint8)((CONTROL_DR & CONTROL_MASK) >> CONTROL_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CONTROL_INTSTAT) 

    /*******************************************************************************
    * Function Name: CONTROL_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 CONTROL_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(CONTROL_INTSTAT & CONTROL_MASK);
		CONTROL_INTSTAT = maskedStatus;
        return maskedStatus >> CONTROL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
