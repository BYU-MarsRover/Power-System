/*******************************************************************************
* File Name: Shoulder_Backup.c  
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
#include "Shoulder_Backup.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Shoulder_Backup_PC =   (Shoulder_Backup_PC & \
                                (uint32)(~(uint32)(Shoulder_Backup_DRIVE_MODE_IND_MASK << (Shoulder_Backup_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Shoulder_Backup_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Shoulder_Backup_Write
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
void Shoulder_Backup_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Shoulder_Backup_DR & (uint8)(~Shoulder_Backup_MASK));
    drVal = (drVal | ((uint8)(value << Shoulder_Backup_SHIFT) & Shoulder_Backup_MASK));
    Shoulder_Backup_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Shoulder_Backup_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Shoulder_Backup_DM_STRONG     Strong Drive 
*  Shoulder_Backup_DM_OD_HI      Open Drain, Drives High 
*  Shoulder_Backup_DM_OD_LO      Open Drain, Drives Low 
*  Shoulder_Backup_DM_RES_UP     Resistive Pull Up 
*  Shoulder_Backup_DM_RES_DWN    Resistive Pull Down 
*  Shoulder_Backup_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Shoulder_Backup_DM_DIG_HIZ    High Impedance Digital 
*  Shoulder_Backup_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Shoulder_Backup_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Shoulder_Backup__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Shoulder_Backup_Read
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
*  Macro Shoulder_Backup_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Shoulder_Backup_Read(void) 
{
    return (uint8)((Shoulder_Backup_PS & Shoulder_Backup_MASK) >> Shoulder_Backup_SHIFT);
}


/*******************************************************************************
* Function Name: Shoulder_Backup_ReadDataReg
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
uint8 Shoulder_Backup_ReadDataReg(void) 
{
    return (uint8)((Shoulder_Backup_DR & Shoulder_Backup_MASK) >> Shoulder_Backup_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Shoulder_Backup_INTSTAT) 

    /*******************************************************************************
    * Function Name: Shoulder_Backup_ClearInterrupt
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
    uint8 Shoulder_Backup_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Shoulder_Backup_INTSTAT & Shoulder_Backup_MASK);
		Shoulder_Backup_INTSTAT = maskedStatus;
        return maskedStatus >> Shoulder_Backup_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
