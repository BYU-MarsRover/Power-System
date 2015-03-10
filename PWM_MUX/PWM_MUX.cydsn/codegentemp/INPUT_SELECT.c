/*******************************************************************************
* File Name: INPUT_SELECT.c  
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
#include "INPUT_SELECT.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        INPUT_SELECT_PC =   (INPUT_SELECT_PC & \
                                (uint32)(~(uint32)(INPUT_SELECT_DRIVE_MODE_IND_MASK << (INPUT_SELECT_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (INPUT_SELECT_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: INPUT_SELECT_Write
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
void INPUT_SELECT_Write(uint8 value) 
{
    uint8 drVal = (uint8)(INPUT_SELECT_DR & (uint8)(~INPUT_SELECT_MASK));
    drVal = (drVal | ((uint8)(value << INPUT_SELECT_SHIFT) & INPUT_SELECT_MASK));
    INPUT_SELECT_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: INPUT_SELECT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  INPUT_SELECT_DM_STRONG     Strong Drive 
*  INPUT_SELECT_DM_OD_HI      Open Drain, Drives High 
*  INPUT_SELECT_DM_OD_LO      Open Drain, Drives Low 
*  INPUT_SELECT_DM_RES_UP     Resistive Pull Up 
*  INPUT_SELECT_DM_RES_DWN    Resistive Pull Down 
*  INPUT_SELECT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  INPUT_SELECT_DM_DIG_HIZ    High Impedance Digital 
*  INPUT_SELECT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void INPUT_SELECT_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(INPUT_SELECT__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: INPUT_SELECT_Read
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
*  Macro INPUT_SELECT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 INPUT_SELECT_Read(void) 
{
    return (uint8)((INPUT_SELECT_PS & INPUT_SELECT_MASK) >> INPUT_SELECT_SHIFT);
}


/*******************************************************************************
* Function Name: INPUT_SELECT_ReadDataReg
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
uint8 INPUT_SELECT_ReadDataReg(void) 
{
    return (uint8)((INPUT_SELECT_DR & INPUT_SELECT_MASK) >> INPUT_SELECT_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(INPUT_SELECT_INTSTAT) 

    /*******************************************************************************
    * Function Name: INPUT_SELECT_ClearInterrupt
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
    uint8 INPUT_SELECT_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(INPUT_SELECT_INTSTAT & INPUT_SELECT_MASK);
		INPUT_SELECT_INTSTAT = maskedStatus;
        return maskedStatus >> INPUT_SELECT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
