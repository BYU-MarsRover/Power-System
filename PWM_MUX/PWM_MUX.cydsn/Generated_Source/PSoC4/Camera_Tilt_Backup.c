/*******************************************************************************
* File Name: Camera_Tilt_Backup.c  
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
#include "Camera_Tilt_Backup.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Camera_Tilt_Backup_PC =   (Camera_Tilt_Backup_PC & \
                                (uint32)(~(uint32)(Camera_Tilt_Backup_DRIVE_MODE_IND_MASK << (Camera_Tilt_Backup_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Camera_Tilt_Backup_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Camera_Tilt_Backup_Write
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
void Camera_Tilt_Backup_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Camera_Tilt_Backup_DR & (uint8)(~Camera_Tilt_Backup_MASK));
    drVal = (drVal | ((uint8)(value << Camera_Tilt_Backup_SHIFT) & Camera_Tilt_Backup_MASK));
    Camera_Tilt_Backup_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Camera_Tilt_Backup_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Camera_Tilt_Backup_DM_STRONG     Strong Drive 
*  Camera_Tilt_Backup_DM_OD_HI      Open Drain, Drives High 
*  Camera_Tilt_Backup_DM_OD_LO      Open Drain, Drives Low 
*  Camera_Tilt_Backup_DM_RES_UP     Resistive Pull Up 
*  Camera_Tilt_Backup_DM_RES_DWN    Resistive Pull Down 
*  Camera_Tilt_Backup_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Camera_Tilt_Backup_DM_DIG_HIZ    High Impedance Digital 
*  Camera_Tilt_Backup_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Camera_Tilt_Backup_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Camera_Tilt_Backup__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Camera_Tilt_Backup_Read
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
*  Macro Camera_Tilt_Backup_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Camera_Tilt_Backup_Read(void) 
{
    return (uint8)((Camera_Tilt_Backup_PS & Camera_Tilt_Backup_MASK) >> Camera_Tilt_Backup_SHIFT);
}


/*******************************************************************************
* Function Name: Camera_Tilt_Backup_ReadDataReg
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
uint8 Camera_Tilt_Backup_ReadDataReg(void) 
{
    return (uint8)((Camera_Tilt_Backup_DR & Camera_Tilt_Backup_MASK) >> Camera_Tilt_Backup_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Camera_Tilt_Backup_INTSTAT) 

    /*******************************************************************************
    * Function Name: Camera_Tilt_Backup_ClearInterrupt
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
    uint8 Camera_Tilt_Backup_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Camera_Tilt_Backup_INTSTAT & Camera_Tilt_Backup_MASK);
		Camera_Tilt_Backup_INTSTAT = maskedStatus;
        return maskedStatus >> Camera_Tilt_Backup_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
