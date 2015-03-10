/*******************************************************************************
* File Name: Drive_Left.c  
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
#include "Drive_Left.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Drive_Left_PC =   (Drive_Left_PC & \
                                (uint32)(~(uint32)(Drive_Left_DRIVE_MODE_IND_MASK << (Drive_Left_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Drive_Left_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Drive_Left_Write
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
void Drive_Left_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Drive_Left_DR & (uint8)(~Drive_Left_MASK));
    drVal = (drVal | ((uint8)(value << Drive_Left_SHIFT) & Drive_Left_MASK));
    Drive_Left_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Drive_Left_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Drive_Left_DM_STRONG     Strong Drive 
*  Drive_Left_DM_OD_HI      Open Drain, Drives High 
*  Drive_Left_DM_OD_LO      Open Drain, Drives Low 
*  Drive_Left_DM_RES_UP     Resistive Pull Up 
*  Drive_Left_DM_RES_DWN    Resistive Pull Down 
*  Drive_Left_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Drive_Left_DM_DIG_HIZ    High Impedance Digital 
*  Drive_Left_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Drive_Left_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Drive_Left__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Drive_Left_Read
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
*  Macro Drive_Left_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Drive_Left_Read(void) 
{
    return (uint8)((Drive_Left_PS & Drive_Left_MASK) >> Drive_Left_SHIFT);
}


/*******************************************************************************
* Function Name: Drive_Left_ReadDataReg
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
uint8 Drive_Left_ReadDataReg(void) 
{
    return (uint8)((Drive_Left_DR & Drive_Left_MASK) >> Drive_Left_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Drive_Left_INTSTAT) 

    /*******************************************************************************
    * Function Name: Drive_Left_ClearInterrupt
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
    uint8 Drive_Left_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Drive_Left_INTSTAT & Drive_Left_MASK);
		Drive_Left_INTSTAT = maskedStatus;
        return maskedStatus >> Drive_Left_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
