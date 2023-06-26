/*******************************************************************************
* \file cy_smif_memconfig.h
* \version 1.0
*
* \brief
* Provides declarations of the SMIF-driver memory configuration.
*
* Note: This is an auto generated file. Do not modify it.
*
********************************************************************************
* \copyright
* Copyright 2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#ifndef CY_SMIF_MEMCONFIG_H
#define CY_SMIF_MEMCONFIG_H
#include "smif/cy_smif_memslot.h"

#define CY_SMIF_DEVICE_NUM 1

extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_readCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_writeEnCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_writeDisCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_eraseCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_chipEraseCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_programCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_readStsRegQeCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_readStsRegWipCmd;
extern cy_stc_smif_mem_cmd_t S25FL512S_SlaveSlot_0_writeStsRegQeCmd;

extern cy_stc_smif_mem_device_cfg_t S25FL512S_SlaveSlot_0_DeviceCfg;

extern const cy_stc_smif_mem_config_t S25FL512S_SlaveSlot_0;

extern const cy_stc_smif_mem_config_t* smifMemConfigs[CY_SMIF_DEVICE_NUM];

extern const cy_stc_smif_block_config_t smifBlockConfig;


#endif /*CY_SMIF_MEMCONFIG_H*/
