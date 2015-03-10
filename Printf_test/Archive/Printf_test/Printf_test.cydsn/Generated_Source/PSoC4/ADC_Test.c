/*******************************************************************************
* File Name: ADC_Test.c  
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
#include "ADC_Test.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ADC_Test_PC =   (ADC_Test_PC & \
                                (uint32)(~(uint32)(ADC_Test_DRIVE_MODE_IND_MASK << (ADC_Test_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ADC_Test_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ADC_Test_Write
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
void ADC_Test_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ADC_Test_DR & (uint8)(~ADC_Test_MASK));
    drVal = (drVal | ((uint8)(value << ADC_Test_SHIFT) & ADC_Test_MASK));
    ADC_Test_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ADC_Test_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ADC_Test_DM_STRONG     Strong Drive 
*  ADC_Test_DM_OD_HI      Open Drain, Drives High 
*  ADC_Test_DM_OD_LO      Open Drain, Drives Low 
*  ADC_Test_DM_RES_UP     Resistive Pull Up 
*  ADC_Test_DM_RES_DWN    Resistive Pull Down 
*  ADC_Test_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ADC_Test_DM_DIG_HIZ    High Impedance Digital 
*  ADC_Test_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ADC_Test_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ADC_Test__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ADC_Test_Read
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
*  Macro ADC_Test_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADC_Test_Read(void) 
{
    return (uint8)((ADC_Test_PS & ADC_Test_MASK) >> ADC_Test_SHIFT);
}


/*******************************************************************************
* Function Name: ADC_Test_ReadDataReg
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
uint8 ADC_Test_ReadDataReg(void) 
{
    return (uint8)((ADC_Test_DR & ADC_Test_MASK) >> ADC_Test_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADC_Test_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADC_Test_ClearInterrupt
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
    uint8 ADC_Test_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ADC_Test_INTSTAT & ADC_Test_MASK);
		ADC_Test_INTSTAT = maskedStatus;
        return maskedStatus >> ADC_Test_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
