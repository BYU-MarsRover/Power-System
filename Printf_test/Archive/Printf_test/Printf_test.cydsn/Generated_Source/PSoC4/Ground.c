/*******************************************************************************
* File Name: Ground.c  
* Version 2.0
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
#include "Ground.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Ground_PC =   (Ground_PC & \
                                (uint32)(~(uint32)(Ground_DRIVE_MODE_IND_MASK << (Ground_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Ground_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Ground_Write
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
void Ground_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Ground_DR & (uint8)(~Ground_MASK));
    drVal = (drVal | ((uint8)(value << Ground_SHIFT) & Ground_MASK));
    Ground_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Ground_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Ground_DM_STRONG     Strong Drive 
*  Ground_DM_OD_HI      Open Drain, Drives High 
*  Ground_DM_OD_LO      Open Drain, Drives Low 
*  Ground_DM_RES_UP     Resistive Pull Up 
*  Ground_DM_RES_DWN    Resistive Pull Down 
*  Ground_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Ground_DM_DIG_HIZ    High Impedance Digital 
*  Ground_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Ground_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Ground__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Ground_Read
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
*  Macro Ground_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Ground_Read(void) 
{
    return (uint8)((Ground_PS & Ground_MASK) >> Ground_SHIFT);
}


/*******************************************************************************
* Function Name: Ground_ReadDataReg
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
uint8 Ground_ReadDataReg(void) 
{
    return (uint8)((Ground_DR & Ground_MASK) >> Ground_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Ground_INTSTAT) 

    /*******************************************************************************
    * Function Name: Ground_ClearInterrupt
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
    uint8 Ground_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Ground_INTSTAT & Ground_MASK);
		Ground_INTSTAT = maskedStatus;
        return maskedStatus >> Ground_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
