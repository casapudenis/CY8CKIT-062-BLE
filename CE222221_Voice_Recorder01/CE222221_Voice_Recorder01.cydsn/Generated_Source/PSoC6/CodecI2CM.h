/***************************************************************************//**
* \file CodecI2CM.c
* \version 2.0
*
*  This file provides constants and parameter values for the I2C component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CodecI2CM_CY_SCB_I2C_PDL_H)
#define CodecI2CM_CY_SCB_I2C_PDL_H

#include "cyfitter.h"
#include "scb/cy_scb_i2c.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*   Initial Parameter Constants
****************************************/

#define CodecI2CM_MODE               (0x2U)
#define CodecI2CM_MODE_SLAVE_MASK    (0x1U)
#define CodecI2CM_MODE_MASTER_MASK   (0x2U)

#define CodecI2CM_ENABLE_SLAVE       (0UL != (CodecI2CM_MODE & CodecI2CM_MODE_SLAVE_MASK))
#define CodecI2CM_ENABLE_MASTER      (0UL != (CodecI2CM_MODE & CodecI2CM_MODE_MASTER_MASK))
#define CodecI2CM_MANUAL_SCL_CONTROL (0U)


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
/* Component only APIs. */
void CodecI2CM_Start(void);

/* Basic functions. */
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_Init(cy_stc_scb_i2c_config_t const *config);
__STATIC_INLINE void CodecI2CM_DeInit (void);
__STATIC_INLINE void CodecI2CM_Enable (void);
__STATIC_INLINE void CodecI2CM_Disable(void);

/* Data rate configuration functions. */
__STATIC_INLINE uint32_t CodecI2CM_SetDataRate(uint32_t dataRateHz, uint32_t scbClockHz);
__STATIC_INLINE uint32_t CodecI2CM_GetDataRate(uint32_t scbClockHz);

/* Register callbacks. */
__STATIC_INLINE void CodecI2CM_RegisterEventCallback(cy_cb_scb_i2c_handle_events_t callback);
#if (CodecI2CM_ENABLE_SLAVE)
__STATIC_INLINE void CodecI2CM_RegisterAddrCallback (cy_cb_scb_i2c_handle_addr_t callback);
#endif /* (CodecI2CM_ENABLE_SLAVE) */

/* Configuration functions. */
#if (CodecI2CM_ENABLE_SLAVE)
__STATIC_INLINE void     CodecI2CM_SlaveSetAddress(uint8_t addr);
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetAddress(void);
__STATIC_INLINE void     CodecI2CM_SlaveSetAddressMask(uint8_t addrMask);
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetAddressMask(void);
#endif /* (CodecI2CM_ENABLE_SLAVE) */

#if (CodecI2CM_ENABLE_MASTER)
__STATIC_INLINE void CodecI2CM_MasterSetLowPhaseDutyCycle (uint32_t clockCycles);
__STATIC_INLINE void CodecI2CM_MasterSetHighPhaseDutyCycle(uint32_t clockCycles);
#endif /* (CodecI2CM_ENABLE_MASTER) */

/* Bus status. */
__STATIC_INLINE bool     CodecI2CM_IsBusBusy(void);

/* Slave functions. */
#if (CodecI2CM_ENABLE_SLAVE)
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetStatus(void);

__STATIC_INLINE void     CodecI2CM_SlaveConfigReadBuf(uint8_t *buffer, uint32_t size);
__STATIC_INLINE void     CodecI2CM_SlaveAbortRead(void);
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetReadTransferCount(void);
__STATIC_INLINE uint32_t CodecI2CM_SlaveClearReadStatus(void);

__STATIC_INLINE void     CodecI2CM_SlaveConfigWriteBuf(uint8_t *buffer, uint32_t size);
__STATIC_INLINE void     CodecI2CM_SlaveAbortWrite(void);
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetWriteTransferCount(void);
__STATIC_INLINE uint32_t CodecI2CM_SlaveClearWriteStatus(void);
#endif /* (CodecI2CM_ENABLE_SLAVE) */

/* Master interrupt processing functions. */
#if (CodecI2CM_ENABLE_MASTER)
__STATIC_INLINE uint32_t CodecI2CM_MasterGetStatus(void);

__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterRead(cy_stc_scb_i2c_master_xfer_config_t *xferConfig);
__STATIC_INLINE void CodecI2CM_MasterAbortRead(void);
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterWrite(cy_stc_scb_i2c_master_xfer_config_t *xferConfig);
__STATIC_INLINE void CodecI2CM_MasterAbortWrite(void);
__STATIC_INLINE uint32_t CodecI2CM_MasterGetTransferCount(void);

/* Master manual processing functions. */
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterSendStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterSendReStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterSendStop(uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterReadByte(cy_en_scb_i2c_command_t ackNack, uint8_t *byte, uint32_t timeoutMs);
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterWriteByte(uint8_t byte, uint32_t timeoutMs);
#endif /* (CodecI2CM_ENABLE_MASTER) */

/* Interrupt handler. */
__STATIC_INLINE void CodecI2CM_Interrupt(void);
/** @} group_general */


/***************************************
*    Variables with External Linkage
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t CodecI2CM_initVar;
extern cy_stc_scb_i2c_config_t const CodecI2CM_config;
extern cy_stc_scb_i2c_context_t CodecI2CM_context;
/** @} group_globals */


/***************************************
*         Preprocessor Macros
***************************************/
/**
* \addtogroup group_macros
* @{
*/
/** The pointer to the base address of the SCB instance */
#define CodecI2CM_HW     ((CySCB_Type *) CodecI2CM_SCB__HW)

/** The desired data rate in Hz */
#define CodecI2CM_DATA_RATE_HZ      (100000U)

/** The frequency of the clock used by the Component in Hz */
#define CodecI2CM_CLK_FREQ_HZ       (1562500U)

/** The number of Component clocks used by the master to generate the SCL
* low phase. This number is calculated by GUI based on the selected data rate.
*/
#define CodecI2CM_LOW_PHASE_DUTY_CYCLE   (8U)

/** The number of Component clocks used by the master to generate the SCL
* high phase. This number is calculated by GUI based on the selected data rate.
*/
#define CodecI2CM_HIGH_PHASE_DUTY_CYCLE  (8U)
/** @} group_macros */


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: CodecI2CM_Init
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_Init(cy_stc_scb_i2c_config_t const *config)
{
    return Cy_SCB_I2C_Init(CodecI2CM_HW, config, &CodecI2CM_context);
}


/*******************************************************************************
*  Function Name: CodecI2CM_DeInit
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_DeInit() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_DeInit(void)
{
    Cy_SCB_I2C_DeInit(CodecI2CM_HW);
}


/*******************************************************************************
* Function Name: CodecI2CM_Enable
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_Enable(void)
{
    Cy_SCB_I2C_Enable(CodecI2CM_HW);
}


/*******************************************************************************
* Function Name: CodecI2CM_Disable
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Disable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_Disable(void)
{
    Cy_SCB_I2C_Disable(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SetDataRate
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SetDataRate() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SetDataRate(uint32_t dataRateHz, uint32_t scbClockHz)
{
    return Cy_SCB_I2C_SetDataRate(CodecI2CM_HW, dataRateHz, scbClockHz);
}


/*******************************************************************************
* Function Name: CodecI2CM_GetDataRate
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_GetDataRate() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_GetDataRate(uint32_t scbClockHz)
{
    return Cy_SCB_I2C_GetDataRate(CodecI2CM_HW, scbClockHz);
}


/*******************************************************************************
* Function Name: CodecI2CM_RegisterEventCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_RegisterEventCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_RegisterEventCallback(cy_cb_scb_i2c_handle_events_t callback)
{
    Cy_SCB_I2C_RegisterEventCallback(CodecI2CM_HW, callback, &CodecI2CM_context);
}


#if (CodecI2CM_ENABLE_SLAVE)
/*******************************************************************************
* Function Name: CodecI2CM_RegisterAddrCallback
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_RegisterAddrCallback() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_RegisterAddrCallback(cy_cb_scb_i2c_handle_addr_t callback)
{
    Cy_SCB_I2C_RegisterAddrCallback(CodecI2CM_HW, callback, &CodecI2CM_context);
}
#endif /* (CodecI2CM_ENABLE_SLAVE) */


/*******************************************************************************
* Function Name: CodecI2CM_IsBusBusy
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_IsBusBusy() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE bool CodecI2CM_IsBusBusy(void)
{
    return Cy_SCB_I2C_IsBusBusy(CodecI2CM_HW);
}


#if (CodecI2CM_ENABLE_SLAVE)
/*******************************************************************************
* Function Name: CodecI2CM_SlaveSetAddress
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetAddress() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_SlaveSetAddress(uint8_t addr)
{
    Cy_SCB_I2C_SlaveSetAddress(CodecI2CM_HW, addr);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveGetAddress
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetAddress() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetAddress(void)
{
    return Cy_SCB_I2C_SlaveGetAddress(CodecI2CM_HW);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveSetAddressMask
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveSetAddressMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_SlaveSetAddressMask(uint8_t addrMask)
{
    Cy_SCB_I2C_SlaveSetAddressMask(CodecI2CM_HW, addrMask);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveGetAddressMask
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetAddressMask() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetAddressMask(void)
{
    return Cy_SCB_I2C_SlaveGetAddressMask(CodecI2CM_HW);
}
#endif /* (CodecI2CM_ENABLE_SLAVE) */

#if (CodecI2CM_ENABLE_MASTER)
/*******************************************************************************
* Function Name: CodecI2CM_MasterSetLowPhaseDutyCycle
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSetLowPhaseDutyCycle() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_MasterSetLowPhaseDutyCycle(uint32_t clockCycles)
{
    Cy_SCB_I2C_MasterSetLowPhaseDutyCycle(CodecI2CM_HW, clockCycles);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterSetHighPhaseDutyCycle
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSetHighPhaseDutyCycle() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_MasterSetHighPhaseDutyCycle(uint32_t clockCycles)
{
    Cy_SCB_I2C_MasterSetHighPhaseDutyCycle(CodecI2CM_HW, clockCycles);
}
#endif /* (CodecI2CM_ENABLE_MASTER) */


#if (CodecI2CM_ENABLE_SLAVE)
/*******************************************************************************
* Function Name: CodecI2CM_SlaveGetStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetStatus(void)
{
    return Cy_SCB_I2C_SlaveGetStatus(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveConfigReadBuf
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveConfigReadBuf() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_SlaveConfigReadBuf(uint8_t *buffer, uint32_t size)
{
    Cy_SCB_I2C_SlaveConfigReadBuf(CodecI2CM_HW, buffer, size, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveAbortRead
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveAbortRead() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_SlaveAbortRead(void)
{
    Cy_SCB_I2C_SlaveAbortRead(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveGetReadTransferCount
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetReadTransferCount() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetReadTransferCount(void)
{
    return Cy_SCB_I2C_SlaveGetReadTransferCount(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveClearReadStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveClearReadStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveClearReadStatus(void)
{
    return Cy_SCB_I2C_SlaveClearReadStatus(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveConfigWriteBuf
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveConfigWriteBuf() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_SlaveConfigWriteBuf(uint8_t *buffer, uint32_t size)
{
    Cy_SCB_I2C_SlaveConfigWriteBuf(CodecI2CM_HW, buffer, size, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveAbortWrite
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveAbortWrite() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_SlaveAbortWrite(void)
{
    Cy_SCB_I2C_SlaveAbortWrite(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveGetWriteTransferCount
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveGetWriteTransferCount() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveGetWriteTransferCount(void)
{
    return Cy_SCB_I2C_SlaveGetWriteTransferCount(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_SlaveClearWriteStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_SlaveClearWriteStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_SlaveClearWriteStatus(void)
{
    return Cy_SCB_I2C_SlaveClearWriteStatus(CodecI2CM_HW, &CodecI2CM_context);
}
#endif /* (CodecI2CM_ENABLE_SLAVE) */


#if (CodecI2CM_ENABLE_MASTER)
/*******************************************************************************
* Function Name: CodecI2CM_MasterGetStatus
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterGetStatus() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_MasterGetStatus(void)
{
    return Cy_SCB_I2C_MasterGetStatus(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterRead
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterRead() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterRead(cy_stc_scb_i2c_master_xfer_config_t *xferConfig)
{
    return Cy_SCB_I2C_MasterRead(CodecI2CM_HW, xferConfig, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterAbortRead
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterAbortRead() PDL driver function.
*
******************************************************************************/
__STATIC_INLINE void CodecI2CM_MasterAbortRead(void)
{
    Cy_SCB_I2C_MasterAbortRead(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterWrite
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterWrite() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterWrite(cy_stc_scb_i2c_master_xfer_config_t *xferConfig)
{
    return Cy_SCB_I2C_MasterWrite(CodecI2CM_HW, xferConfig, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterAbortWrite
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterAbortWrite() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_MasterAbortWrite(void)
{
    Cy_SCB_I2C_MasterAbortWrite(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterGetTransferCount
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterGetTransferCount() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE uint32_t CodecI2CM_MasterGetTransferCount(void)
{
    return Cy_SCB_I2C_MasterGetTransferCount(CodecI2CM_HW, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterSendStart
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSendStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterSendStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterSendStart(CodecI2CM_HW, address, bitRnW, timeoutMs, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterSendReStart
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSendReStart() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterSendReStart(uint32_t address, cy_en_scb_i2c_direction_t bitRnW, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterSendReStart(CodecI2CM_HW, address, bitRnW, timeoutMs, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterSendStop
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterSendStop() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterSendStop(uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterSendStop(CodecI2CM_HW, timeoutMs, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterReadByte
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterReadByte() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterReadByte(cy_en_scb_i2c_command_t ackNack, uint8_t *byte, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterReadByte(CodecI2CM_HW, ackNack, byte, timeoutMs, &CodecI2CM_context);
}


/*******************************************************************************
* Function Name: CodecI2CM_MasterWriteByte
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_MasterWriteByte() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_scb_i2c_status_t CodecI2CM_MasterWriteByte(uint8_t byte, uint32_t timeoutMs)
{
    return Cy_SCB_I2C_MasterWriteByte(CodecI2CM_HW, byte, timeoutMs, &CodecI2CM_context);
}
#endif /* (CodecI2CM_ENABLE_MASTER) */


/*******************************************************************************
* Function Name: CodecI2CM_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SCB_I2C_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void CodecI2CM_Interrupt(void)
{
    Cy_SCB_I2C_Interrupt(CodecI2CM_HW, &CodecI2CM_context);
}

#if defined(__cplusplus)
}
#endif

#endif /* CodecI2CM_CY_SCB_I2C_PDL_H */


/* [] END OF FILE */
