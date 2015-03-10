/*******************************************************************************
* File Name: MCU.c  
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
#include "MCU.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        MCU_PC =   (MCU_PC & \
                                (uint32)(~(uint32)(MCU_DRIVE_MODE_IND_MASK << (MCU_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (MCU_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: MCU_Write
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
void MCU_Write(uint8 value) 
{
    uint8 drVal = (uint8)(MCU_DR & (uint8)(~MCU_MASK));
    drVal = (drVal | ((uint8)(value << MCU_SHIFT) & MCU_MASK));
    MCU_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: MCU_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MCU_DM_STRONG     Strong Drive 
*  MCU_DM_OD_HI      Open Drain, Drives High 
*  MCU_DM_OD_LO      Open Drain, Drives Low 
*  MCU_DM_RES_UP     Resistive Pull Up 
*  MCU_DM_RES_DWN    Resistive Pull Down 
*  MCU_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MCU_DM_DIG_HIZ    High Impedance Digital 
*  MCU_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MCU_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(MCU__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: MCU_Read
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
*  Macro MCU_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MCU_Read(void) 
{
    return (uint8)((MCU_PS & MCU_MASK) >> MCU_SHIFT);
}


/*******************************************************************************
* Function Name: MCU_ReadDataReg
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
uint8 MCU_ReadDataReg(void) 
{
    return (uint8)((MCU_DR & MCU_MASK) >> MCU_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MCU_INTSTAT) 

    /*******************************************************************************
    * Function Name: MCU_ClearInterrupt
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
    uint8 MCU_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(MCU_INTSTAT & MCU_MASK);
		MCU_INTSTAT = maskedStatus;
        return maskedStatus >> MCU_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
