/*******************************************************************************
* File Name: .h
* Version 1.20
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_UART_1_H)
#define CY_SCB_PVT_UART_1_H

#include "UART_1.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_1_SetI2CExtClkInterruptMode(interruptMask) UART_1_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_1_ClearI2CExtClkInterruptSource(interruptMask) UART_1_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_1_GetI2CExtClkInterruptSource()                (UART_1_INTR_I2C_EC_REG)
#define UART_1_GetI2CExtClkInterruptMode()                  (UART_1_INTR_I2C_EC_MASK_REG)
#define UART_1_GetI2CExtClkInterruptSourceMasked()          (UART_1_INTR_I2C_EC_MASKED_REG)

#if(!UART_1_CY_SCBIP_V1_I2C_ONLY)
/* APIs to service INTR_SPI_EC register */
#define UART_1_SetSpiExtClkInterruptMode(interruptMask) UART_1_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define UART_1_ClearSpiExtClkInterruptSource(interruptMask) UART_1_CLEAR_INTR_SPI_EC(interruptMask)
#define UART_1_GetExtSpiClkInterruptSource()                 (UART_1_INTR_SPI_EC_REG)
#define UART_1_GetExtSpiClkInterruptMode()                   (UART_1_INTR_SPI_EC_MASK_REG)
#define UART_1_GetExtSpiClkInterruptSourceMasked()           (UART_1_INTR_SPI_EC_MASKED_REG)
#endif /* (!UART_1_CY_SCBIP_V1_I2C_ONLY) */

#if(UART_1_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_1_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (UART_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if !defined (CY_REMOVE_UART_1_CUSTOM_INTR_HANDLER)
    extern cyisraddress UART_1_customIntrHandler;
#endif /* !defined (CY_REMOVE_UART_1_CUSTOM_INTR_HANDLER) */

extern UART_1_BACKUP_STRUCT UART_1_backup;

#if(UART_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    extern uint8 UART_1_scbMode;
    extern uint8 UART_1_scbEnableWake;
    extern uint8 UART_1_scbEnableIntr;

    /* I2C config vars */
    extern uint8 UART_1_mode;
    extern uint8 UART_1_acceptAddr;

    /* SPI/UART config vars */
    extern volatile uint8 * UART_1_rxBuffer;
    extern uint8   UART_1_rxDataBits;
    extern uint32  UART_1_rxBufferSize;

    extern volatile uint8 * UART_1_txBuffer;
    extern uint8   UART_1_txDataBits;
    extern uint32  UART_1_txBufferSize;

    /* EZI2C config vars */
    extern uint8 UART_1_numberOfAddr;
    extern uint8 UART_1_subAddrSize;
#endif /* (UART_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*  Conditional Macro
****************************************/

#if(UART_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Define run time operation mode */
    #define UART_1_SCB_MODE_I2C_RUNTM_CFG     (UART_1_SCB_MODE_I2C      == UART_1_scbMode)
    #define UART_1_SCB_MODE_SPI_RUNTM_CFG     (UART_1_SCB_MODE_SPI      == UART_1_scbMode)
    #define UART_1_SCB_MODE_UART_RUNTM_CFG    (UART_1_SCB_MODE_UART     == UART_1_scbMode)
    #define UART_1_SCB_MODE_EZI2C_RUNTM_CFG   (UART_1_SCB_MODE_EZI2C    == UART_1_scbMode)
    #define UART_1_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UART_1_SCB_MODE_UNCONFIG == UART_1_scbMode)

    /* Define wakeup enable */
    #define UART_1_SCB_WAKE_ENABLE_CHECK        (0u != UART_1_scbEnableWake)
#endif /* (UART_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_UART_1_H) */


/* [] END OF FILE */
