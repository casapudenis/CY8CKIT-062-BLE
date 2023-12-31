/***************************************************************************//**
* \file DMA_Record.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  DMA_Record component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DMA_Record.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t DMA_Record_PDM_to_SRAM_config =
{
    .retrigger       = CY_DMA_RETRIG_16CYC,
    .interruptType   = CY_DMA_X_LOOP,
    .triggerOutType  = CY_DMA_1ELEMENT,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_HALFWORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 0L,
    .dstXincrement   = 1L,
    .xCount          = 256UL,
    .srcYincrement   = 0L,
    .dstYincrement   = 256L,
    .yCount          = 32UL,
    .nextDescriptor  = &DMA_Record_PDM_to_SRAM
};

cy_stc_dma_descriptor_t DMA_Record_PDM_to_SRAM =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** DMA_Record_initVar indicates whether the DMA_Record 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time DMA_Record_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the DMA_Record_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  DMA_Record_Init() function can be called before the 
*  DMA_Record_Start() or DMA_Record_ChEnable() function.
*/
uint8 DMA_Record_initVar = 0u;


/*******************************************************************************
* Function Name: DMA_Record_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the DMA_Record block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void DMA_Record_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == DMA_Record_initVar)
    {
        DMA_Record_Init();
        DMA_Record_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&DMA_Record_PDM_to_SRAM, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&DMA_Record_PDM_to_SRAM, dstAddress);
    Cy_DMA_Channel_Enable(DMA_Record_HW, DMA_Record_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_Record_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void DMA_Record_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&DMA_Record_PDM_to_SRAM, &DMA_Record_PDM_to_SRAM_config);


    channelConfig.descriptor  = &DMA_Record_PDM_to_SRAM;
    channelConfig.preemptable = DMA_Record_PREEMPTABLE;
    channelConfig.priority    = DMA_Record_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = DMA_Record_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(DMA_Record_HW, DMA_Record_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(DMA_Record_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
