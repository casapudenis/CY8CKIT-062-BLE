/***************************************************************************//**
* \file DMA_PlayRight.c
* \version 2.0
*
*  This file provides the source code to the API for the
*  DMA_PlayRight component.
*
********************************************************************************
* \copyright
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DMA_PlayRight.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Generated code */
const cy_stc_dma_descriptor_config_t DMA_PlayRight_SRAM_to_I2S_config =
{
    .retrigger       = CY_DMA_RETRIG_16CYC,
    .interruptType   = CY_DMA_X_LOOP,
    .triggerOutType  = CY_DMA_1ELEMENT,
    .channelState    = CY_DMA_CHANNEL_ENABLED,
    .triggerInType   = CY_DMA_1ELEMENT,
    .dataSize        = CY_DMA_HALFWORD,
    .srcTransferSize = CY_DMA_TRANSFER_SIZE_DATA,
    .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
    .descriptorType  = CY_DMA_2D_TRANSFER,
    .srcAddress      = NULL,
    .dstAddress      = NULL,
    .srcXincrement   = 1L,
    .dstXincrement   = 0L,
    .xCount          = 256UL,
    .srcYincrement   = 256L,
    .dstYincrement   = 0L,
    .yCount          = 2UL,
    .nextDescriptor  = &DMA_PlayRight_SRAM_to_I2S
};

cy_stc_dma_descriptor_t DMA_PlayRight_SRAM_to_I2S =
{
    .ctl = 0UL,
    .src = 0UL,
    .dst = 0UL,
    .xCtl = 0UL,
    .yCtl = 0UL,
    .nextPtr = 0UL
};


/** DMA_PlayRight_initVar indicates whether the DMA_PlayRight 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time DMA_PlayRight_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the DMA_PlayRight_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  DMA_PlayRight_Init() function can be called before the 
*  DMA_PlayRight_Start() or DMA_PlayRight_ChEnable() function.
*/
uint8 DMA_PlayRight_initVar = 0u;


/*******************************************************************************
* Function Name: DMA_PlayRight_Start
****************************************************************************//**
*
* Based on the settings for descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init(). Enables the DMA_PlayRight block using the DMA_Chnl_Enable().
*  
*******************************************************************************/
void DMA_PlayRight_Start(void const * srcAddress, void const * dstAddress)
{
    if (0U == DMA_PlayRight_initVar)
    {
        DMA_PlayRight_Init();
        DMA_PlayRight_initVar = 1u;
    }
    
    Cy_DMA_Descriptor_SetSrcAddress(&DMA_PlayRight_SRAM_to_I2S, srcAddress);
    Cy_DMA_Descriptor_SetDstAddress(&DMA_PlayRight_SRAM_to_I2S, dstAddress);
    Cy_DMA_Channel_Enable(DMA_PlayRight_HW, DMA_PlayRight_DW_CHANNEL);
}


/*******************************************************************************
* Function Name: DMA_PlayRight_Init
****************************************************************************//**
*
* Based on the settings for the descriptor in the customizer this function runs the
* DMA_Descriptor_Init() and then initializes the channel using
* DMA_Chnl_Init().
*  
*******************************************************************************/
void DMA_PlayRight_Init(void)
{
    cy_stc_dma_channel_config_t channelConfig;

    /* Init all descriptors */
    (void)Cy_DMA_Descriptor_Init(&DMA_PlayRight_SRAM_to_I2S, &DMA_PlayRight_SRAM_to_I2S_config);


    channelConfig.descriptor  = &DMA_PlayRight_SRAM_to_I2S;
    channelConfig.preemptable = DMA_PlayRight_PREEMPTABLE;
    channelConfig.priority    = DMA_PlayRight_PRIORITY;
    channelConfig.enable      = false;
    channelConfig.bufferable  = DMA_PlayRight_BUFFERABLE;

    (void)Cy_DMA_Channel_Init(DMA_PlayRight_HW, DMA_PlayRight_DW_CHANNEL, &channelConfig);

    Cy_DMA_Enable(DMA_PlayRight_HW);
}


#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
