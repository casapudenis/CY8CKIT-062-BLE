/*******************************************************************************
* \file SMIF_1.h
* \version 1.10
*
*  This file provides constants and parameter values for the SMIF component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(SMIF_1_CY_SMIF_PDL_H)
#define SMIF_1_CY_SMIF_PDL_H

#include "cyfitter.h"
#include "cyfitter_sysint.h"
#include "cyfitter_sysint_cfg.h"

#include "smif/cy_smif.h"
#include "smif/cy_smif_memslot.h"

#if defined(__cplusplus)
extern "C" {
#endif


/***************************************
*   Initial Parameter Constants
****************************************/

/* Interrupt cause group */
#define SMIF_1_MEMORY_MODE_ALIGMENT_ERORR     (0UL)
#define SMIF_1_TX_COMMAND_FIFO_OVERFLOW       (0UL)
#define SMIF_1_TX_DATA_FIFO_OVERFLOW          (0UL)
#define SMIF_1_RX_DATA_FIFO_UNDERFLOW         (0UL)

/* TX and RX FIFO trigger group */
#define SMIF_1_RX_FIFO_TRIGEER_LEVEL          (0UL)
#define SMIF_1_TX_FIFO_TRIGEER_LEVEL          (0UL)



/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_general
* \{
*/

cy_en_smif_status_t SMIF_1_Start(cy_stc_smif_block_config_t *blockConfig, uint32_t timeoutMs);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_Init(cy_stc_smif_block_config_t *blockConfig);
__STATIC_INLINE void                SMIF_1_Mem_DeInit(void);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdWriteEnable(uint32_t slotNumber);
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdWriteDisable(uint32_t slotNumber);
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_QuadEnable(uint32_t slotNumber);
__STATIC_INLINE bool                SMIF_1_Mem_IsBusy(uint32_t slotNumber);

__STATIC_INLINE bool                SMIF_1_BusyCheck(void);
__STATIC_INLINE uint32_t            SMIF_1_GetTxfrStatus(void);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdReadSts(uint32_t slotNumber, uint8_t *status, uint8_t command);
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdWriteSts(uint32_t slotNumber,  uint8_t command, uint8_t status);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdChipErase( uint32_t slotNumber);
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdSectorErase(uint32_t slotNumber, uint8_t const *sectorAddr);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdProgram(uint32_t slotNumber,uint8_t const *addr, 
                                                                    uint8_t *writeBuff, 
                                                                    uint32_t size, 
                                                                    cy_smif_event_cb_t CmdCmpltCb);
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdRead(uint32_t slotNumber, uint8_t const *addr, uint8_t *readBuff, 
                                                                    uint32_t size, 
                                                                    cy_smif_event_cb_t CmdCmpltCb);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_Encrypt(uint32_t address, uint8_t *data, uint32_t size);

__STATIC_INLINE void SMIF_1_Enable(void);
__STATIC_INLINE void SMIF_1_Disable(void);

__STATIC_INLINE void              SMIF_1_SetMode(cy_en_smif_mode_t mode);
__STATIC_INLINE cy_en_smif_mode_t SMIF_1_GetMode(void);

__STATIC_INLINE cy_en_smif_status_t SMIF_1_CacheInvalidate(cy_en_smif_cache_en_t cacheType);

__STATIC_INLINE void     SMIF_1_Interrupt(void);

/***************************************
*  Internal SMIF function declarations
****************************************/
/** \cond INTERNAL */
__STATIC_INLINE void SMIF_1_MemSlotConfigsInit(cy_stc_smif_mem_config_t  * const memConfigs[], 
                                                            uint32_t memConfigsSize);
/** \endcond */

/** \} group_general */


/***************************************
*         Internal Constants
***************************************/

/* GPIO configuration group */
#define SMIF_1_DATALINES0_1                   (1UL)
#define SMIF_1_DATALINES2_3                   (1UL)
#define SMIF_1_DATALINES4_5                   (0UL)
#define SMIF_1_DATALINES6_7                   (0UL)
#define SMIF_1_SS0                            (1UL)
#define SMIF_1_SS1                            (0UL)
#define SMIF_1_SS2                            (0UL)
#define SMIF_1_SS3                            (0UL)

/* Advanced user: Build configuration*/
#define SMIF_1_CYMEM_GEN                      (1UL)

/* DMA Trigger Output */
#define SMIF_1_RX_FIFO_DMA_TRIGGER            (0UL)
#define SMIF_1_TX_FIFO_DMA_TRIGGER            (0UL)

#define SMIF_1_MAX_SLOT_NUMBER    ((uint8_t)SMIF_DEVICE_NR)
#define SMIF_1_BAD_SLOT_NUMBER    ((uint8_t)(SMIF_1_MAX_SLOT_NUMBER + 1U))

#define SMIF_1_HW                 SMIF_1_SMIF__HW

#define SMIF_1_MEMORIES_NUM       (SMIF_1_SS0 + SMIF_1_SS1 + \
                                             SMIF_1_SS2 + SMIF_1_SS3)

#define SMIF_1_TX_FIFO_TRIGGER    (0UL)
#define SMIF_1_RX_FIFO_TRIGGER    (0UL)


/***************************************
* Kept for backward compatibility
***************************************/

#define SMIF_1_EN_DMA_READ        SMIF_1_RX_FIFO_DMA_TRIGGER
#define SMIF_1_EN_DMA_WRITE       SMIF_1_TX_FIFO_DMA_TRIGGER

/**
* \addtogroup group_globals
* \{
*/
/** Allocate space for context. */
extern cy_stc_smif_context_t SMIF_1_context;

/** Allocate space memory configurations. */
extern cy_stc_smif_mem_config_t* SMIF_1_memSlotConfigs[SMIF_1_MAX_SLOT_NUMBER];

/** Allocate space device configuration. */
extern cy_stc_smif_config_t const SMIF_1_config;

extern uint8_t SMIF_1_initVar;

/** \} group_globals */


/**
* \addtogroup group_constants
* \{
*/
#define SMIF_1_DESELECT_DELAY          (7u)            /**< Minimum duration of SPI de-selection */ 

/** 
 *  What happens when there is a Read to an empty RX FIFO or a Write to a full TX 
 *  FIFO.
 */ 
#define SMIF_1_AHB_BUS_ERROR           (0u)            

/** \} group_constants */


#define SMIF_1_SMIF_INTR_MASK   ( _VAL2FLD(SMIF_INTR_TR_TX_REQ, SMIF_1_TX_FIFO_TRIGGER)                      |\
                                            _VAL2FLD(SMIF_INTR_TR_RX_REQ, SMIF_1_RX_FIFO_TRIGGER)                      |\
                                            _VAL2FLD(SMIF_INTR_XIP_ALIGNMENT_ERROR, SMIF_1_MEMORY_MODE_ALIGMENT_ERORR) |\
                                            _VAL2FLD(SMIF_INTR_TX_CMD_FIFO_OVERFLOW, SMIF_1_TX_COMMAND_FIFO_OVERFLOW)  |\
                                            _VAL2FLD(SMIF_INTR_TX_DATA_FIFO_OVERFLOW, SMIF_1_TX_DATA_FIFO_OVERFLOW)    |\
                                            _VAL2FLD(SMIF_INTR_RX_DATA_FIFO_UNDERFLOW, SMIF_1_RX_DATA_FIFO_UNDERFLOW))     


/***************************************
*    In-line Function Implementation
***************************************/

/*******************************************************************************
* Function Name: SMIF_1_Mem_Init
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_Init() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_Init(cy_stc_smif_block_config_t *blockConfig)
{
    SMIF_1_MemSlotConfigsInit(blockConfig->memConfig, blockConfig->memCount);
    return Cy_SMIF_Memslot_Init(SMIF_1_HW , blockConfig, &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_DeInit
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_DeInit() PDL driver function.
* 
*******************************************************************************/
__STATIC_INLINE void SMIF_1_Mem_DeInit(void)
{
    Cy_SMIF_Memslot_DeInit(SMIF_1_HW );
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdWriteEnable
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdWriteEnable() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdWriteEnable()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdWriteEnable(uint32_t slotNumber)
{
    return Cy_SMIF_Memslot_CmdWriteEnable(SMIF_1_HW, 
                SMIF_1_memSlotConfigs[slotNumber], &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdWriteDisable
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdWriteDisable() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdWriteDisable()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdWriteDisable(uint32_t slotNumber)
{
    return Cy_SMIF_Memslot_CmdWriteDisable(SMIF_1_HW, 
                SMIF_1_memSlotConfigs[slotNumber], &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_IsBusy
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_IsBusy() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_IsBusy()  
* PDL driver function in PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE bool SMIF_1_Mem_IsBusy(uint32_t slotNumber)
{
    return Cy_SMIF_Memslot_IsBusy( SMIF_1_HW, 
            SMIF_1_memSlotConfigs[slotNumber], &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_QuadEnable
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_QuadEnable() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_QuadEnable()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_QuadEnable(uint32_t slotNumber)
{
    return Cy_SMIF_Memslot_QuadEnable(SMIF_1_HW, 
            SMIF_1_memSlotConfigs[slotNumber], &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdReadSts
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdReadSts() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdReadSts()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdReadSts(uint32_t slotNumber,
                                                            uint8_t *status, 
                                                            uint8_t command)
{
    return Cy_SMIF_Memslot_CmdReadSts(SMIF_1_HW, 
            SMIF_1_memSlotConfigs[slotNumber], status, command, 
            &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdWriteSts
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdWriteSts() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
*  
* \note For details, see the description of the Cy_SMIF_Memslot_CmdWriteSts()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdWriteSts(uint32_t slotNumber,
                                                            uint8_t command, 
                                                            uint8_t status)
{
    return Cy_SMIF_Memslot_CmdWriteSts(SMIF_1_HW,                                     
                                    SMIF_1_memSlotConfigs[slotNumber], 
                                    &status,
                                    command,
                                    &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdChipErase
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdChipErase() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdChipErase()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdChipErase(uint32_t slotNumber)
{
    return Cy_SMIF_Memslot_CmdChipErase(SMIF_1_HW ,
                                   SMIF_1_memSlotConfigs[slotNumber],
                                    &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdSectorErase
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdSectorErase() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdSectorErase()  
* PDL driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdSectorErase(uint32_t slotNumber, 
                                                    uint8_t const *sectorAddr)
{
    return Cy_SMIF_Memslot_CmdSectorErase(SMIF_1_HW ,
                                        SMIF_1_memSlotConfigs[slotNumber], 
                                        sectorAddr,
                                        &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdProgram
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdProgram() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the 
* slave select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdProgram() PDL 
* driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdProgram(uint32_t slotNumber, 
                                                            uint8_t const *addr, 
                                                            uint8_t *writeBuff, 
                                                            uint32_t size, 
                                                            cy_smif_event_cb_t CmdCmpltCb)
{
    return Cy_SMIF_Memslot_CmdProgram(SMIF_1_HW,                                    
                                    SMIF_1_memSlotConfigs[slotNumber], 
                                    addr, 
                                    writeBuff, 
                                    size,
                                    CmdCmpltCb,
                                    &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Mem_CmdRead
****************************************************************************//**
*
* Invokes the Cy_SMIF_Memslot_CmdRead() PDL driver function.
*
* \param slotNumber
* The slave device ID. This number is either 0, 1, 2, or 3. This is decided by the slave
* select line to be used while a transmit is happening.
* 
* \note For details, see the description of the Cy_SMIF_Memslot_CmdRead() PDL 
* driver function in the PDL API Reference Guide.
* 
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Mem_CmdRead(uint32_t slotNumber, 
                                                            uint8_t const *addr, 
                                                            uint8_t *readBuff, 
                                                            uint32_t size, 
                                                            cy_smif_event_cb_t CmdCmpltCb)
{
    return Cy_SMIF_Memslot_CmdRead(SMIF_1_HW,                                    
                                    SMIF_1_memSlotConfigs[slotNumber], 
                                    addr, 
                                    readBuff, 
                                    size,
                                    CmdCmpltCb,
                                    &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Interrupt
****************************************************************************//**
*
* Invokes the Cy_SMIF_Interrupt() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SMIF_1_Interrupt(void)
{
    Cy_SMIF_Interrupt(SMIF_1_HW , &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Encrypt
****************************************************************************//**
*
* Invokes the Cy_SMIF_Encrypt() PDL driver function.
* 
* \note For details, see the cryptography subsection in the Serial Memory Interface 
* (SMIF) section in the chip technical reference manual (TRM). 
*
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_Encrypt(uint32_t address,
                                                    uint8_t *data,
                                                    uint32_t size)
{
    return Cy_SMIF_Encrypt(SMIF_1_HW, address, data, size,
                            &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Enable
****************************************************************************//**
*
* Invokes the Cy_SMIF_Enable() PDL driver function.
*
*******************************************************************************/
__STATIC_INLINE void SMIF_1_Enable(void)
{
    Cy_SMIF_Enable(SMIF_1_HW, &SMIF_1_context);
}


/*******************************************************************************
* Function Name: SMIF_1_Disable
****************************************************************************//**
*
* Invokes the Cy_SMIF_Disable() PDL driver function. 
*
*******************************************************************************/
__STATIC_INLINE void SMIF_1_Disable(void)
{
    Cy_SMIF_Disable(SMIF_1_HW);
}


/*******************************************************************************
* Function Name: SMIF_1_SetMode
****************************************************************************//**
*
* Invokes the Cy_SMIF_SetMode() PDL driver function. 
*
*******************************************************************************/
__STATIC_INLINE void     SMIF_1_SetMode(cy_en_smif_mode_t mode)
{
    Cy_SMIF_SetMode(SMIF_1_HW , mode);
}


/*******************************************************************************
* Function Name: SMIF_1_GetMode
****************************************************************************//**
*
* Invokes the SMIF_GetMode() PDL driver function. 
*
*******************************************************************************/
__STATIC_INLINE cy_en_smif_mode_t SMIF_1_GetMode(void)
{
    return Cy_SMIF_GetMode(SMIF_1_HW );
}


/*******************************************************************************
* Function Name: SMIF_1_BusyCheck
****************************************************************************//**
*
* Invokes the SMIF_BusyCheck() PDL driver function. 
*
*******************************************************************************/
__STATIC_INLINE bool SMIF_1_BusyCheck(void)
{
    return Cy_SMIF_BusyCheck(SMIF_1_HW );
}


/*******************************************************************************
* Function Name: SMIF_1_CacheInvalidate
****************************************************************************//**
*
* Invokes the SMIF_CacheInvalidate() PDL driver function. 
*
*******************************************************************************/
__STATIC_INLINE cy_en_smif_status_t SMIF_1_CacheInvalidate(cy_en_smif_cache_en_t cacheType)
{
    return Cy_SMIF_CacheInvalidate(SMIF_1_HW , cacheType);
}


/*******************************************************************************
* Function Name: SMIF_1_GetTxfrStatus
****************************************************************************//**
*
* Invokes the SMIF_GetTxfrStatus() PDL driver function. 
*
*******************************************************************************/
__STATIC_INLINE uint32_t SMIF_1_GetTxfrStatus(void)
{
    return Cy_SMIF_GetTxfrStatus(SMIF_1_HW , &SMIF_1_context);
}


/***************************************
*  Internal SMIF inline functions 
****************************************/

/** \cond INTERNAL */

/*******************************************************************************
* Function Name: SMIF_1_MemSlotConfigsInit
****************************************************************************//**
*
*  \internal
*  This function initializes the SMIF_1_memSlotConfigs arrays with 
*  the pointers to the device memory configuration structure. The index of the 
*  SMIF_1_memSlotConfigs array is equal to the device slotNumber number.     
*   
* \param memConfigs
* The configuration structure array that configures the SMIF memory device to be  
* mapped into the PSoC memory map. \ref cy_stc_smif_mem_config_t 
*
* \globalvars
*  SMIF_1_memSlotConfigs The component array of the external memory 
*  configuration structures.
*
*******************************************************************************/
__STATIC_INLINE void SMIF_1_MemSlotConfigsInit(cy_stc_smif_mem_config_t  * const memConfigs[], 
                                                            uint32_t memConfigsSize)
{
    uint8_t slotIndex;

    /* Initialization of _memSlotConfigs*/
    for(slotIndex = 0U; slotIndex < SMIF_1_MAX_SLOT_NUMBER; slotIndex++)
    {
        SMIF_1_memSlotConfigs[slotIndex] = NULL;
    }

    /* Filling of _memSlotConfigs */
    if (NULL != memConfigs)
    {
        uint8_t slotNumber = SMIF_1_BAD_SLOT_NUMBER;
        for(slotIndex = 0U; slotIndex < memConfigsSize; slotIndex++)
        {
            if (NULL != memConfigs[slotIndex])
            {       
                switch ((cy_en_smif_slave_select_t)memConfigs[slotIndex]->slaveSelect)
                {
                    case CY_SMIF_SLAVE_SELECT_0:
                        slotNumber = 0U;            
                        break;
                    case CY_SMIF_SLAVE_SELECT_1:
                        slotNumber = 1U;         
                        break;
                    case CY_SMIF_SLAVE_SELECT_2:
                        slotNumber = 2U;           
                        break;
                    case CY_SMIF_SLAVE_SELECT_3:
                        slotNumber = 3U;         
                        break;
                    default:
                        /* User error: the slot number is not supported*/
                        slotNumber = SMIF_1_BAD_SLOT_NUMBER;
                        break;
                }
                if (slotNumber < SMIF_1_MAX_SLOT_NUMBER)
                {
                    SMIF_1_memSlotConfigs[slotNumber] = memConfigs[slotIndex];
                }
            }  
        }
    }
}

/** \endcond */


#if defined(__cplusplus)
}
#endif

#endif /* SMIF_1_CY_SMIF_PDL_H */


/* [] END OF FILE */
