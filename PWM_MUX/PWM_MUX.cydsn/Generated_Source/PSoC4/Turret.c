/*******************************************************************************
* File Name: Turret.c  
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
#include "Turret.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Turret_PC =   (Turret_PC & \
                                (uint32)(~(uint32)(Turret_DRIVE_MODE_IND_MASK << (Turret_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Turret_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Turret_Write
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
void Turret_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Turret_DR & (uint8)(~Turret_MASK));
    drVal = (drVal | ((uint8)(value << Turret_SHIFT) & Turret_MASK));
    Turret_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Turret_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Turret_DM_STRONG     Strong Drive 
*  Turret_DM_OD_HI      Open Drain, Drives High 
*  Turret_DM_OD_LO      Open Drain, Drives Low 
*  Turret_DM_RES_UP     Resistive Pull Up 
*  Turret_DM_RES_DWN    Resistive Pull Down 
*  Turret_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Turret_DM_DIG_HIZ    High Impedance Digital 
*  Turret_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Turret_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Turret__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Turret_Read
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
*  Macro Turret_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Turret_Read(void) 
{
    return (uint8)((Turret_PS & Turret_MASK) >> Turret_SHIFT);
}


/*******************************************************************************
* Function Name: Turret_ReadDataReg
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
uint8 Turret_ReadDataReg(void) 
{
    return (uint8)((Turret_DR & Turret_MASK) >> Turret_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Turret_INTSTAT) 

    /*******************************************************************************
    * Function Name: Turret_ClearInterrupt
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
    uint8 Turret_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Turret_INTSTAT & Turret_MASK);
		Turret_INTSTAT = maskedStatus;
        return maskedStatus >> Turret_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
