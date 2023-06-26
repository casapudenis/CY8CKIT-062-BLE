/***************************************************************************//**
* \file SMIF_1.c
* \version 1.10
*
*  This file provides the source code to the API for the SMIF component.
*
*******************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SMIF_1.h"

#if defined(__cplusplus)
extern "C" {
#endif


/***************************************
*     Global variables
***************************************/


/** SMIF_1_initVar Indicates whether the SMIF_1 component
* has been initialized. The variable is initialized to 0 and set to 1 the first
* time SMIF_1_Start() is called. This allows the component to restart
* without reinitialization after the first call to the SMIF_1_Start()
* routine. */
uint8_t SMIF_1_initVar = 0U;

/* Allocate space for the context and initialize. */
cy_stc_smif_context_t SMIF_1_context;

/* Allocate space memories configurations sorted by the slot number. */
cy_stc_smif_mem_config_t* SMIF_1_memSlotConfigs[SMIF_1_MAX_SLOT_NUMBER];

/* Allocate the space device configuration. */
cy_stc_smif_config_t const SMIF_1_config =
{
    .mode           = (uint32_t)CY_SMIF_NORMAL,
    .deselectDelay  = SMIF_1_DESELECT_DELAY,
    .rxClockSel     = (uint32_t)CY_SMIF_SEL_INV_INTERNAL_CLK,
    .blockEvent     = (uint32_t)CY_SMIF_BUS_ERROR
};


/*******************************************************************************
* Function Name: SMIF_1_Start
****************************************************************************//**
*
*  This function starts the SMIF block allocating and configuring its 
*  interrupt for Normal mode. This function initializes all the memory slots,
*  sets the trigger level, and enables Memory mode cache with prefetching.     
*  The SMIF HW block is configured according to the \ref SMIF_1_config 
*  values.
*   
*  \note Changing of SMIF mode does not invalidate cache. Invalidate cache after changing the mode 
*  from Normal to Memory to prevent the reading 
*  of outdated values from cache in Memory mode.  
*   
* \param configStruct
* Define configuration of the external memories connected to the SMIF.
*
* \param timeout
* Timeout in microseconds for blocking APIs in use.
*
* \globalvars
*  - SMIF_1_initVar - Checks the initial configuration modified
*  on the first function call.
*  - SMIF_1_memSlotConfigs - Allocates the array of external memory 
*  configuration structures.
*
*******************************************************************************/
cy_en_smif_status_t SMIF_1_Start(cy_stc_smif_block_config_t *blockConfig, uint32_t timeoutMs)
{
    if (0U == SMIF_1_initVar)
    {
        /* Configure the component. */
        (void) Cy_SMIF_Init(SMIF_1_HW , &SMIF_1_config, timeoutMs, &SMIF_1_context);
        
        /* Configure the interrupt sources. */
        Cy_SMIF_SetInterruptMask(SMIF_1_HW , SMIF_1_SMIF_INTR_MASK);
        
        /* Configure the trigger levels. */
        Cy_SMIF_SetTxFifoTriggerLevel(SMIF_1_HW , SMIF_1_TX_FIFO_TRIGEER_LEVEL);
        Cy_SMIF_SetRxFifoTriggerLevel(SMIF_1_HW , SMIF_1_RX_FIFO_TRIGEER_LEVEL);

        /* Hook the interrupt service routine. */


        #if defined(SMIF_1_SMIF_IRQ__INTC_ASSIGNED)
           (void)Cy_SysInt_Init(&SMIF_1_SMIF_IRQ_cfg, &SMIF_1_Interrupt);
        #endif /* defined(SMIF_1_SMIF_IRQ__INTC_ASSIGNED) */
        
        /* Enable the fast and slow caches with pre-fetching */
        (void)Cy_SMIF_CacheEnable(SMIF_1_HW, CY_SMIF_CACHE_BOTH);
        (void)Cy_SMIF_CachePrefetchingEnable(SMIF_1_HW, CY_SMIF_CACHE_BOTH);

        /* The component is configured. */
        SMIF_1_initVar = 1U;
    }

    /* Enable the interrupt in NVIC. */
    #if defined(SMIF_1_SMIF_IRQ__INTC_ASSIGNED)
       NVIC_EnableIRQ((IRQn_Type)SMIF_1_SMIF_IRQ_cfg.intrSrc);
    #endif /*CY_CPU_CORTEX_M0P*/


    Cy_SMIF_Enable(SMIF_1_HW , &SMIF_1_context);

    /* Initialization of the SMIF DEVICE region needs the SMIF IP up and running to 
     * auto-detect configuration from external memory. */
    return SMIF_1_Mem_Init(blockConfig); 
}

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
