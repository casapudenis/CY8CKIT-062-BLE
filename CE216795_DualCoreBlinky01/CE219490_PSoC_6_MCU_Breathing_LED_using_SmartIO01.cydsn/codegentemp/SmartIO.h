/*******************************************************************************
* \file SmartIO.h
* \version 1.0
*
* \brief
*  This file provides constants and parameter values for the SmartIO Component.
*
********************************************************************************
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SMARTIO_SmartIO_H)
#define CY_SMARTIO_SmartIO_H

#include "syslib/cy_syslib.h"
#include "cyfitter.h"

/***************************************
*       Constants
***************************************/

/* Port location*/
#define SmartIO_PORT           SmartIO_cy_mxs40_smartio__HW

/* General constants */
#define SmartIO_DUTRIG_MAX     (10UL)
#define SmartIO_REGVAL_MAX     (0xffUL)
#define SmartIO_OPC_MAX        (11UL)
#define SmartIO_DUSIZE_MAX     (8UL)
 

/***************************************
*       Global Variables
***************************************/
/**
* \addtogroup group_globals
* @{
*/
extern uint8_t SmartIO_initVar; /**< Initialization state variable */
/** @} globals */


/***************************************
*        Function Prototypes
***************************************/
/**
* \addtogroup group_functions
* @{
*/
void SmartIO_Init(void);
void SmartIO_Start(void);
void SmartIO_Stop(void);
__STATIC_INLINE void SmartIO_Enable(void);
__STATIC_INLINE void SmartIO_Disable(void);
__STATIC_INLINE uint8_t SmartIO_GetBypass(void);
void SmartIO_SetBypass(uint32_t portChannel);
void SmartIO_ClockSelect(uint32_t clockSrc);
void SmartIO_HoldOverride(uint32_t ovCtrl);
void SmartIO_IoSyncMode(uint32_t portTerm);
void SmartIO_ChipSyncMode(uint32_t portTerm);
cy_status SmartIO_LUT_SelectInputs(uint32_t lutNum, uint32_t inputNum, uint32_t inputSrc);
void SmartIO_LUT_ConfigureMode(uint32_t lutNum, uint32_t mapping, uint32_t mode);
cy_status SmartIO_DU_SelectTriggers(uint32_t tr0Sel, uint32_t tr1Sel, uint32_t tr2Sel);
cy_status SmartIO_DU_SelectData(uint32_t dataNum, uint32_t dataSel);
cy_status SmartIO_DU_RegValue(uint32_t dataValue);
cy_status SmartIO_DU_OpCode(uint32_t opCode, uint32_t dataSize);
/** @} functions */


/***************************************
*        API Constants
***************************************/
/**
* \addtogroup group_constants
* @{
*/
/** \addtogroup channelConst Port channel selection constants
 * \brief Constants to be passed as "portChannel" parameter in SmartIO_SetBypass() function.
 *  @{
 */
#define SmartIO_CHANNEL_NONE    0x00UL /**< \brief Do not bypass any channels  */
#define SmartIO_CHANNEL0        0x01UL /**< \brief Channel 0 (data0 <-> gpio0) */
#define SmartIO_CHANNEL1        0x02UL /**< \brief Channel 1 (data1 <-> gpio1) */
#define SmartIO_CHANNEL2        0x04UL /**< \brief Channel 2 (data2 <-> gpio2) */
#define SmartIO_CHANNEL3        0x08UL /**< \brief Channel 3 (data3 <-> gpio3) */
#define SmartIO_CHANNEL4        0x10UL /**< \brief Channel 4 (data4 <-> gpio4) */
#define SmartIO_CHANNEL5        0x20UL /**< \brief Channel 5 (data5 <-> gpio5) */
#define SmartIO_CHANNEL6        0x40UL /**< \brief Channel 6 (data6 <-> gpio6) */
#define SmartIO_CHANNEL7        0x80UL /**< \brief Channel 7 (data7 <-> gpio7) */
#define SmartIO_CHANNEL_ALL     0xffUL /**< \brief Bypass all channels         */
/** @} channelConst */

/** \addtogroup clockConst Component clock selection constants
 * \brief Constants to be passed as "clockSrc" parameter in SmartIO_ClockSelect() function.
 *  @{
 */
#define SmartIO_CLK_GPIO0       0UL  /**< \brief Clock sourced from signal on gpio0 */
#define SmartIO_CLK_GPIO1       1UL  /**< \brief Clock sourced from signal on gpio1 */
#define SmartIO_CLK_GPIO2       2UL  /**< \brief Clock sourced from signal on gpio2 */
#define SmartIO_CLK_GPIO3       3UL  /**< \brief Clock sourced from signal on gpio3 */
#define SmartIO_CLK_GPIO4       4UL  /**< \brief Clock sourced from signal on gpio4 */
#define SmartIO_CLK_GPIO5       5UL  /**< \brief Clock sourced from signal on gpio5 */
#define SmartIO_CLK_GPIO6       6UL  /**< \brief Clock sourced from signal on gpio6 */
#define SmartIO_CLK_GPIO7       7UL  /**< \brief Clock sourced from signal on gpio7 */
#define SmartIO_CLK_DATA0       8UL  /**< \brief Clock sourced from signal on data0 */
#define SmartIO_CLK_DATA1       9UL  /**< \brief Clock sourced from signal on data1 */
#define SmartIO_CLK_DATA2       10UL /**< \brief Clock sourced from signal on data2 */
#define SmartIO_CLK_DATA3       11UL /**< \brief Clock sourced from signal on data3 */
#define SmartIO_CLK_DATA4       12UL /**< \brief Clock sourced from signal on data4 */
#define SmartIO_CLK_DATA5       13UL /**< \brief Clock sourced from signal on data5 */
#define SmartIO_CLK_DATA6       14UL /**< \brief Clock sourced from signal on data6 */
#define SmartIO_CLK_DATA7       15UL /**< \brief Clock sourced from signal on data7 */
#define SmartIO_DIV_CLK_ACT     16UL /**< \brief Clock sourced from a divided clock (Active) */
#define SmartIO_DIV_CLK_DS      17UL /**< \brief Clock sourced from a divided clock (Deep-Sleep) */
#define SmartIO_DIV_CLK_HIB     18UL /**< \brief Clock sourced from a divided clock (Hibernate) */
#define SmartIO_LFCLK           19UL /**< \brief Clock sourced from LFCLK */
#define SmartIO_CLK_GATED       20UL /**< \brief Disables the clock connection. Used when turning off the block */
#define SmartIO_ASYNC           31UL /**< \brief Asynchronous operation */
/** @} clockConst */

/** \addtogroup hldOvrConst Component hold override selection constants
 * \brief Constants to be passed as "ovCtrl" parameter in SmartIO_HoldOverride() function.
 *  @{
 */
#define SmartIO_OVCTRL_DISABLE  0UL /**< \brief Controlled by HSIOM  */
#define SmartIO_OVCTRL_ENABLE   1UL /**< \brief Controlled by SmartIO */
/** @} hldOvrConst */

/** \addtogroup termConst Terminal selection constants
 * \brief Constants to be passed as "portTerm" parameter in SmartIO_IoSyncMode() and 
 *  SmartIO_ChipSyncMode() functions.
 *  @{
 */
#define SmartIO_TERM_NONE       0x00UL /**< \brief No synchronization for all data/gpio     */
#define SmartIO_TERM0           0x01UL /**< \brief Enable synchronization for data0/gpio0   */
#define SmartIO_TERM1           0x02UL /**< \brief Enable synchronization for data1/gpio1   */
#define SmartIO_TERM2           0x04UL /**< \brief Enable synchronization for data2/gpio2   */
#define SmartIO_TERM3           0x08UL /**< \brief Enable synchronization for data3/gpio3   */
#define SmartIO_TERM4           0x10UL /**< \brief Enable synchronization for data4/gpio4   */
#define SmartIO_TERM5           0x20UL /**< \brief Enable synchronization for data5/gpio5   */
#define SmartIO_TERM6           0x40UL /**< \brief Enable synchronization for data6/gpio6   */
#define SmartIO_TERM7           0x80UL /**< \brief Enable synchronization for data7/gpio7   */
#define SmartIO_TERM_ALL        0xffUL /**< \brief Enable sycnhronization for all data/gpio */
/** @} termConst */

/** \addtogroup lutNumConst Look-up table number constants
 * \brief Constants to be passed as "lutNum" parameter in SmartIO_LUT_SelectInputs() and SmartIO_LUT_ConfigureMode() functions.
 *  @{
 */
#define SmartIO_LUT0            0UL /**< \brief LUT number 0  */
#define SmartIO_LUT1            1UL /**< \brief LUT number 1  */
#define SmartIO_LUT2            2UL /**< \brief LUT number 2  */
#define SmartIO_LUT3            3UL /**< \brief LUT number 3  */
#define SmartIO_LUT4            4UL /**< \brief LUT number 4  */
#define SmartIO_LUT5            5UL /**< \brief LUT number 5  */
#define SmartIO_LUT6            6UL /**< \brief LUT number 6  */
#define SmartIO_LUT7            7UL /**< \brief LUT number 7  */
/** @} lutNumConst */

/** \addtogroup inputNumConst LUT input number constants
 * \brief Constants to be passed as "inputNum" parameter in SmartIO_LUT_SelectInputs() function.
 *  @{
 */
#define SmartIO_LUT_INPUT0      0x01UL /**< \brief LUT input terminal 0    */
#define SmartIO_LUT_INPUT1      0x02UL /**< \brief LUT input terminal 1    */
#define SmartIO_LUT_INPUT2      0x04UL /**< \brief LUT input terminal 2    */
#define SmartIO_LUT_INPUT_ALL   0x07UL /**< \brief All LUT input terminals */
/** @} inputNumConst */

/** \addtogroup inputSrcConst LUT input source constants
 * \brief Constants to be passed as "inputSrc" parameter in SmartIO_LUT_SelectInputs() function.
 *  @{
 */
#define SmartIO_SRC_LUT0        0UL  /**< \brief Source is LUT0 output    */
#define SmartIO_SRC_LUT1        1UL  /**< \brief Source is LUT1 output    */
#define SmartIO_SRC_LUT2        2UL  /**< \brief Source is LUT2 output    */
#define SmartIO_SRC_LUT3        3UL  /**< \brief Source is LUT3 output    */
#define SmartIO_SRC_LUT4        4UL  /**< \brief Source is LUT4 output    */
#define SmartIO_SRC_LUT5        5UL  /**< \brief Source is LUT5 output    */
#define SmartIO_SRC_LUT6        6UL  /**< \brief Source is LUT6 output    */
#define SmartIO_SRC_LUT7        7UL  /**< \brief Source is LUT7 output    */
#define SmartIO_SRC_DATA_04     8UL  /**< \brief Source is data0/data4    */
#define SmartIO_SRC_DATA_15     9UL  /**< \brief Source is data1/data5    */
#define SmartIO_SRC_DATA_26     10UL /**< \brief Source is data2/data6    */
#define SmartIO_SRC_DATA_37     11UL /**< \brief Source is data3/data7    */
#define SmartIO_SRC_GPIO_04     12UL /**< \brief Source is gpio0/gpio4    */
#define SmartIO_SRC_GPIO_15     13UL /**< \brief Source is gpio1/gpio5    */
#define SmartIO_SRC_GPIO_26     14UL /**< \brief Source is gpio2/gpio6    */
#define SmartIO_SRC_GPIO_37     15UL /**< \brief Source is gpio3/gpio7    */
#define SmartIO_SRC_DU          16UL /**< \brief Source is Data Unit output */
/** @} inputSrcConst */

/** \addtogroup modeConst LUT mode constants
 * \brief Constants to be passed as "mode" parameter in SmartIO_LUT_ConfigureMode() function.
 *  @{
 */
#define SmartIO_MODE_COMB       0UL /**< \brief Combinatorial mode      */
#define SmartIO_MODE_REGIN      1UL /**< \brief Registered input mode   */
#define SmartIO_MODE_REGOUT     2UL /**< \brief Registered output mode  */
#define SmartIO_MODE_SRFF       3UL /**< \brief S/R Flip-Flop mode      */
/** @} modeConst */

/** \addtogroup duTrConst Data Unit trigger input constants
 * \brief Constants to be passed as "tr0Sel", "tr1Sel", and "tr2Sel" parameters in SmartIO_DU_SelectTriggers() function.
 *  @{
 */
#define SmartIO_TR_CONST_ZERO   0UL /**< \brief Constant 0        */
#define SmartIO_TR_CONST_ONE    1UL /**< \brief Constant 1        */
#define SmartIO_TR_DU_OUT       2UL /**< \brief Data unit output  */
#define SmartIO_TR_LUT0         3UL /**< \brief LUT 0 output      */
#define SmartIO_TR_LUT1         4UL /**< \brief LUT 1 output      */
#define SmartIO_TR_LUT2         5UL /**< \brief LUT 2 output      */
#define SmartIO_TR_LUT3         6UL /**< \brief LUT 3 output      */
#define SmartIO_TR_LUT4         7UL /**< \brief LUT 4 output      */
#define SmartIO_TR_LUT5         8UL /**< \brief LUT 5 output      */
#define SmartIO_TR_LUT6         9UL /**< \brief LUT 6 output      */
#define SmartIO_TR_LUT7         10UL /**< \brief LUT 7 output     */
/** @} duTrConst */

/** \addtogroup duDataConst Data Unit data register constants
 * \brief Constants to be passed as "dataNum" parameter in SmartIO_DU_SelectData() function.
 *  @{
 */
#define SmartIO_DATA0             1UL /**< \brief DU DATA0 register                  */
#define SmartIO_DATA1             2UL /**< \brief DU DATA1 register                  */
#define SmartIO_DATA_BOTH         3UL /**< \brief Both DU DATA0 and DATA1 registers  */
/** @} duDataConst */

/** \addtogroup duDataSrcConst Data Unit data register source selection constants
 * \brief Constants to be passed as "dataSel" parameter in SmartIO_DU_SelectData() function.
 *  @{
 */
#define SmartIO_DATA_CONST_ZERO   0UL /**< \brief Constant 0          */
#define SmartIO_DATA_TERM_DATA    1UL /**< \brief Terminal data[7:0]  */
#define SmartIO_DATA_TERM_GPIO    2UL /**< \brief Terminal gpio[7:0]  */
#define SmartIO_DATA_DU_REG       3UL /**< \brief Data Unit register  */
/** @} duDataSrcConst */

/** \addtogroup duOpcConst Data Unit opcode constants
 * \brief Constants to be passed as "opCode" parameter in SmartIO_DU_OpCode() function.
 *  @{
 */
#define SmartIO_OPC_INCR           1UL /**< \brief Count Up                */
#define SmartIO_OPC_DECR           2UL /**< \brief Count Down              */
#define SmartIO_OPC_INCR_WRAP      3UL /**< \brief Count Up and wrap       */
#define SmartIO_OPC_DECR_WRAP      4UL /**< \brief Count Down and wrap     */
#define SmartIO_OPC_INCR_DECR      5UL /**< \brief Count Up/Down           */
#define SmartIO_OPC_INCR_DECR_WRAP 6UL /**< \brief Count Up/Down and wrap  */
#define SmartIO_OPC_ROR            7UL /**< \brief Rotate right            */
#define SmartIO_OPC_SHR            8UL /**< \brief Shift right             */
#define SmartIO_OPC_AND_OR         9UL /**< \brief DU Data0 AND DU Data1   */
#define SmartIO_OPC_SHR_MAJ3       10UL /**< \brief Majority 3              */
#define SmartIO_OPC_SHR_EQL        11UL /**< \brief Equal DU Data1         */
/** @} duOpcConst */

/** @} group_constants */


/***************************************
*    Initial Parameter Constants
***************************************/
    
/* Global control */
#define SmartIO_BYPASS0         1UL
#define SmartIO_BYPASS1         1UL
#define SmartIO_BYPASS2         1UL
#define SmartIO_BYPASS3         1UL
#define SmartIO_BYPASS4         0UL
#define SmartIO_BYPASS5         1UL
#define SmartIO_BYPASS6         0UL
#define SmartIO_BYPASS7         1UL
#define SmartIO_CLOCK_SELECT    16UL
#define SmartIO_HLD_OVR         0UL

/* IO Synchronization control */
#define SmartIO_IO_SYNC0        0UL
#define SmartIO_IO_SYNC1        0UL
#define SmartIO_IO_SYNC2        0UL
#define SmartIO_IO_SYNC3        0UL
#define SmartIO_IO_SYNC4        0UL
#define SmartIO_IO_SYNC5        0UL
#define SmartIO_IO_SYNC6        0UL
#define SmartIO_IO_SYNC7        0UL

/* Chip Data Synchronization control */
#define SmartIO_DATA_SYNC0      0UL
#define SmartIO_DATA_SYNC1      0UL
#define SmartIO_DATA_SYNC2      0UL
#define SmartIO_DATA_SYNC3      0UL
#define SmartIO_DATA_SYNC4      0UL
#define SmartIO_DATA_SYNC5      0UL
#define SmartIO_DATA_SYNC6      0UL
#define SmartIO_DATA_SYNC7      0UL

/* LUT input selection */
#define SmartIO_LUT0_TR0        17UL
#define SmartIO_LUT0_TR1        17UL
#define SmartIO_LUT0_TR2        17UL
#define SmartIO_LUT1_TR0        17UL
#define SmartIO_LUT1_TR1        17UL
#define SmartIO_LUT1_TR2        17UL
#define SmartIO_LUT2_TR0        2UL
#define SmartIO_LUT2_TR1        2UL
#define SmartIO_LUT2_TR2        2UL
#define SmartIO_LUT3_TR0        2UL
#define SmartIO_LUT3_TR1        3UL
#define SmartIO_LUT3_TR2        3UL
#define SmartIO_LUT4_TR0        8UL
#define SmartIO_LUT4_TR1        3UL
#define SmartIO_LUT4_TR2        3UL
#define SmartIO_LUT5_TR0        17UL
#define SmartIO_LUT5_TR1        17UL
#define SmartIO_LUT5_TR2        17UL
#define SmartIO_LUT6_TR0        4UL
#define SmartIO_LUT6_TR1        4UL
#define SmartIO_LUT6_TR2        4UL
#define SmartIO_LUT7_TR0        17UL
#define SmartIO_LUT7_TR1        17UL
#define SmartIO_LUT7_TR2        17UL

/* LUT truth table */
#define SmartIO_LUT0_MAP        0UL
#define SmartIO_LUT1_MAP        0UL
#define SmartIO_LUT2_MAP        1UL
#define SmartIO_LUT3_MAP        129UL
#define SmartIO_LUT4_MAP        66UL
#define SmartIO_LUT5_MAP        0UL
#define SmartIO_LUT6_MAP        1UL
#define SmartIO_LUT7_MAP        0UL

/* LUT mode */
#define SmartIO_LUT0_MODE       0UL
#define SmartIO_LUT1_MODE       0UL
#define SmartIO_LUT2_MODE       2UL
#define SmartIO_LUT3_MODE       2UL
#define SmartIO_LUT4_MODE       0UL
#define SmartIO_LUT5_MODE       0UL
#define SmartIO_LUT6_MODE       0UL
#define SmartIO_LUT7_MODE       0UL

/* DU input selection */
#define SmartIO_DU_TR0          0UL
#define SmartIO_DU_TR1          0UL
#define SmartIO_DU_TR2          0UL

/* DU configuration */
#define SmartIO_DU_DATA0        0UL
#define SmartIO_DU_DATA1        0UL
#define SmartIO_DU_REG          0UL
#define SmartIO_DU_SIZE         7UL
#define SmartIO_DU_OPCODE       1UL


/***************************************
*        Register Constants
***************************************/

/* Channel number */
#define SmartIO_CH0                       (0U)
#define SmartIO_CH1                       (1U)
#define SmartIO_CH2                       (2U)
#define SmartIO_CH3                       (3U)
#define SmartIO_CH4                       (4U)
#define SmartIO_CH5                       (5U)
#define SmartIO_CH6                       (6U)
#define SmartIO_CH7                       (7U)

/* SmartIO Fabric Enable/Disable */
#define SmartIO_FABRIC_ENABLE             ((uint32_t)((uint32_t)0x01U << SMARTIO_PRT_CTL_ENABLED_Pos))
#define SmartIO_FABRIC_DISABLE            ((uint32_t)(~(uint32_t)((uint32_t)0x01U << SMARTIO_PRT_CTL_ENABLED_Pos)))

/* Bypass Mask */
#define SmartIO_BYPASS_CLEAR              ((uint32_t)(~(uint32_t)(SMARTIO_PRT_CTL_BYPASS_Msk)))

/* Clock Source Const 0, clear, mask */
#define SmartIO_CLOCK_CONST_ZERO          ((uint32_t)((uint32_t)SmartIO_CLK_GATED << SMARTIO_PRT_CTL_CLOCK_SRC_Pos))
#define SmartIO_CLOCK_CLEAR               ((uint32_t)(~(uint32_t)(SMARTIO_PRT_CTL_CLOCK_SRC_Msk)))

/* Hold override HSIOM/SmartIO */
#define SmartIO_HLD_OVR_SMARTIO           ((uint32_t)((uint32_t)0x01U << SMARTIO_PRT_CTL_HLD_OVR_Pos))
#define SmartIO_HLD_OVR_HSIOM             ((uint32_t)(~(uint32_t)((uint32_t)0x01U << SMARTIO_PRT_CTL_HLD_OVR_Pos)))

/* Pipeline Enable/Disable */
#define SmartIO_PIPELINE_ENABLE           ((uint32_t)((uint32_t)0x01U << SMARTIO_PRT_CTL_PIPELINE_EN_Pos))
#define SmartIO_PIPELINE_DISABLE          ((uint32_t)(~(uint32_t)((uint32_t)0x01U << SMARTIO_PRT_CTL_PIPELINE_EN_Pos)))

/* Sync control clear */
#define SmartIO_IO_SYNC_CLEAR             ((uint32_t)(~(uint32_t)(SMARTIO_PRT_SYNC_CTL_IO_SYNC_EN_Msk)))
#define SmartIO_DATA_SYNC_CLEAR           ((uint32_t)(~(uint32_t)(SMARTIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Msk)))

/* LUT inputs clear */
#define SmartIO_LUT_TR0_CLEAR             ((uint32_t)(~(uint32_t)(SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk)))
#define SmartIO_LUT_TR1_CLEAR             ((uint32_t)(~(uint32_t)(SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk)))
#define SmartIO_LUT_TR2_CLEAR             ((uint32_t)(~(uint32_t)(SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk)))
#define SmartIO_LUT_TR_CLEAR_ALL          (SmartIO_LUT_TR0_CLEAR & SmartIO_LUT_TR1_CLEAR & SmartIO_LUT_TR2_CLEAR)

/* LUT config clear */
#define SmartIO_LUT_MAP_CLEAR             ((uint32_t)(~(uint32_t)(SMARTIO_PRT_LUT_CTL_LUT_Msk)))
#define SmartIO_LUT_OPC_CLEAR             ((uint32_t)(~(uint32_t)(SMARTIO_PRT_LUT_CTL_LUT_OPC_Msk)))
#define SmartIO_LUT_CTL_CLEAR             ((uint32_t)(SmartIO_LUT_MAP_CLEAR & SmartIO_LUT_OPC_CLEAR))

/* DU inputs clear */
#define SmartIO_DU_TR0_CLEAR              ((uint32_t)(~(uint32_t)(SMARTIO_PRT_DU_SEL_DU_TR0_SEL_Msk)))
#define SmartIO_DU_TR1_CLEAR              ((uint32_t)(~(uint32_t)(SMARTIO_PRT_DU_SEL_DU_TR1_SEL_Msk)))
#define SmartIO_DU_TR2_CLEAR              ((uint32_t)(~(uint32_t)(SMARTIO_PRT_DU_SEL_DU_TR2_SEL_Msk)))
#define SmartIO_DU_TR_CLEAR_ALL           (SmartIO_DU_TR0_CLEAR & SmartIO_DU_TR1_CLEAR & SmartIO_DU_TR2_CLEAR)

/* DU DATA0 and DATA1 clear */
#define SmartIO_DU_DATA0_CLEAR            ((uint32_t)(~(uint32_t)(SMARTIO_PRT_DU_SEL_DU_DATA0_SEL_Msk)))
#define SmartIO_DU_DATA1_CLEAR            ((uint32_t)(~(uint32_t)(SMARTIO_PRT_DU_SEL_DU_DATA1_SEL_Msk)))
#define SmartIO_DU_DATA01_CLEAR_BOTH      (SmartIO_DU_DATA0_CLEAR & SmartIO_DU_DATA1_CLEAR)


/***************************************
*        Initial configuration
***************************************/

/* Bypass configuration */
#define SmartIO_INIT_BYPASS              ((uint32_t)(((SmartIO_BYPASS0)       | \
                                                     (SmartIO_BYPASS1 << SmartIO_CH1) | \
                                                     (SmartIO_BYPASS2 << SmartIO_CH2) | \
                                                     (SmartIO_BYPASS3 << SmartIO_CH3) | \
                                                     (SmartIO_BYPASS4 << SmartIO_CH4) | \
                                                     (SmartIO_BYPASS5 << SmartIO_CH5) | \
                                                     (SmartIO_BYPASS6 << SmartIO_CH6) | \
                                                     (SmartIO_BYPASS7 << SmartIO_CH7))  \
                                                     << SMARTIO_PRT_CTL_BYPASS_Pos))

/* Clock configuration */
#define SmartIO_INIT_CLOCK_SRC           ((uint32_t)(SmartIO_CLOCK_SELECT << SMARTIO_PRT_CTL_CLOCK_SRC_Pos))

/* Hold override configuration */
#define SmartIO_INIT_HLD_OVR             ((uint32_t)(SmartIO_HLD_OVR << SMARTIO_PRT_CTL_HLD_OVR_Pos))

/* Disable the pipeline */
#define SmartIO_INIT_PIPELINE_EN         ((uint32_t)((uint32_t)0x00U << SMARTIO_PRT_CTL_PIPELINE_EN_Pos))

/* Initial general control configuration */
#define SmartIO_INIT_CTL_CONFIG          ((uint32_t)(SmartIO_INIT_PIPELINE_EN | \
                                                    SmartIO_INIT_HLD_OVR     | \
                                                    SmartIO_INIT_CLOCK_SRC   | \
                                                    SmartIO_INIT_BYPASS))

/* IO Sync configuration */
#define SmartIO_INIT_IO_SYNC             ((uint32_t)(((SmartIO_IO_SYNC0)       | \
                                                     (SmartIO_IO_SYNC1 << SmartIO_CH1) | \
                                                     (SmartIO_IO_SYNC2 << SmartIO_CH2) | \
                                                     (SmartIO_IO_SYNC3 << SmartIO_CH3) | \
                                                     (SmartIO_IO_SYNC4 << SmartIO_CH4) | \
                                                     (SmartIO_IO_SYNC5 << SmartIO_CH5) | \
                                                     (SmartIO_IO_SYNC6 << SmartIO_CH6) | \
                                                     (SmartIO_IO_SYNC7 << SmartIO_CH7))  \
                                                     << SMARTIO_PRT_SYNC_CTL_IO_SYNC_EN_Pos))

/* Chip data Sync configuration */
#define SmartIO_INIT_DATA_SYNC           ((uint32_t)(((SmartIO_DATA_SYNC0)       | \
                                                     (SmartIO_DATA_SYNC1 << SmartIO_CH1) | \
                                                     (SmartIO_DATA_SYNC2 << SmartIO_CH2) | \
                                                     (SmartIO_DATA_SYNC3 << SmartIO_CH3) | \
                                                     (SmartIO_DATA_SYNC4 << SmartIO_CH4) | \
                                                     (SmartIO_DATA_SYNC5 << SmartIO_CH5) | \
                                                     (SmartIO_DATA_SYNC6 << SmartIO_CH6) | \
                                                     (SmartIO_DATA_SYNC7 << SmartIO_CH7))  \
                                                     << SMARTIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Pos))

/* Initial synchronization configuration */
#define SmartIO_INIT_SYNC_CONFIG         ((uint32_t)(SmartIO_INIT_DATA_SYNC | \
                                                     SmartIO_INIT_IO_SYNC))

/* Initial LUTs input select TR0 */
#define SmartIO_INIT_LUT0_TR0            ((uint32_t)((SmartIO_LUT0_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk))
#define SmartIO_INIT_LUT1_TR0            ((uint32_t)((SmartIO_LUT1_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))
#define SmartIO_INIT_LUT2_TR0            ((uint32_t)((SmartIO_LUT2_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))
#define SmartIO_INIT_LUT3_TR0            ((uint32_t)((SmartIO_LUT3_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))
#define SmartIO_INIT_LUT4_TR0            ((uint32_t)((SmartIO_LUT4_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))
#define SmartIO_INIT_LUT5_TR0            ((uint32_t)((SmartIO_LUT5_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))
#define SmartIO_INIT_LUT6_TR0            ((uint32_t)((SmartIO_LUT6_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))
#define SmartIO_INIT_LUT7_TR0            ((uint32_t)((SmartIO_LUT7_TR0 << SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk ))

/* Initial LUTs input select TR1 */
#define SmartIO_INIT_LUT0_TR1            ((uint32_t)((SmartIO_LUT0_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT1_TR1            ((uint32_t)((SmartIO_LUT1_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT2_TR1            ((uint32_t)((SmartIO_LUT2_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT3_TR1            ((uint32_t)((SmartIO_LUT3_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT4_TR1            ((uint32_t)((SmartIO_LUT4_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT5_TR1            ((uint32_t)((SmartIO_LUT5_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT6_TR1            ((uint32_t)((SmartIO_LUT6_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))
#define SmartIO_INIT_LUT7_TR1            ((uint32_t)((SmartIO_LUT7_TR1 << SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk ))

/* Initial LUTs input select TR2 */
#define SmartIO_INIT_LUT0_TR2            ((uint32_t)((SmartIO_LUT0_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk ))
#define SmartIO_INIT_LUT1_TR2            ((uint32_t)((SmartIO_LUT1_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))
#define SmartIO_INIT_LUT2_TR2            ((uint32_t)((SmartIO_LUT2_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))
#define SmartIO_INIT_LUT3_TR2            ((uint32_t)((SmartIO_LUT3_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))
#define SmartIO_INIT_LUT4_TR2            ((uint32_t)((SmartIO_LUT4_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))
#define SmartIO_INIT_LUT5_TR2            ((uint32_t)((SmartIO_LUT5_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))
#define SmartIO_INIT_LUT6_TR2            ((uint32_t)((SmartIO_LUT6_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))
#define SmartIO_INIT_LUT7_TR2            ((uint32_t)((SmartIO_LUT7_TR2 << SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos) & SMARTIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk  ))

/* Initial LUTs input selections */
#define SmartIO_INIT_LUT0_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT0_TR0 | \
                                                    SmartIO_INIT_LUT0_TR1 | \
                                                    SmartIO_INIT_LUT0_TR2))
#define SmartIO_INIT_LUT1_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT1_TR0 | \
                                                    SmartIO_INIT_LUT1_TR1 | \
                                                    SmartIO_INIT_LUT1_TR2))
#define SmartIO_INIT_LUT2_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT2_TR0 | \
                                                    SmartIO_INIT_LUT2_TR1 | \
                                                    SmartIO_INIT_LUT2_TR2))
#define SmartIO_INIT_LUT3_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT3_TR0 | \
                                                    SmartIO_INIT_LUT3_TR1 | \
                                                    SmartIO_INIT_LUT3_TR2))
#define SmartIO_INIT_LUT4_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT4_TR0 | \
                                                    SmartIO_INIT_LUT4_TR1 | \
                                                    SmartIO_INIT_LUT4_TR2))
#define SmartIO_INIT_LUT5_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT5_TR0 | \
                                                    SmartIO_INIT_LUT5_TR1 | \
                                                    SmartIO_INIT_LUT5_TR2))
#define SmartIO_INIT_LUT6_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT6_TR0 | \
                                                    SmartIO_INIT_LUT6_TR1 | \
                                                    SmartIO_INIT_LUT6_TR2))
#define SmartIO_INIT_LUT7_SEL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT7_TR0 | \
                                                    SmartIO_INIT_LUT7_TR1 | \
                                                    SmartIO_INIT_LUT7_TR2))

/* Initial LUTs truth tables */
#define SmartIO_INIT_LUT0_MAP            ((uint32_t)(SmartIO_LUT0_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT1_MAP            ((uint32_t)(SmartIO_LUT1_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT2_MAP            ((uint32_t)(SmartIO_LUT2_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT3_MAP            ((uint32_t)(SmartIO_LUT3_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT4_MAP            ((uint32_t)(SmartIO_LUT4_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT5_MAP            ((uint32_t)(SmartIO_LUT5_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT6_MAP            ((uint32_t)(SmartIO_LUT6_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))
#define SmartIO_INIT_LUT7_MAP            ((uint32_t)(SmartIO_LUT7_MAP << SMARTIO_PRT_LUT_CTL_LUT_Pos))

/* Initial LUTs modes */
#define SmartIO_INIT_LUT0_MODE           ((uint32_t)(SmartIO_LUT0_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT1_MODE           ((uint32_t)(SmartIO_LUT1_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT2_MODE           ((uint32_t)(SmartIO_LUT2_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT3_MODE           ((uint32_t)(SmartIO_LUT3_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT4_MODE           ((uint32_t)(SmartIO_LUT4_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT5_MODE           ((uint32_t)(SmartIO_LUT5_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT6_MODE           ((uint32_t)(SmartIO_LUT6_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))
#define SmartIO_INIT_LUT7_MODE           ((uint32_t)(SmartIO_LUT7_MODE << SMARTIO_PRT_LUT_CTL_LUT_OPC_Pos))

/* Initial LUTs control configuration */
#define SmartIO_INIT_LUT0_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT0_MAP  | SmartIO_INIT_LUT0_MODE))
#define SmartIO_INIT_LUT1_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT1_MAP  | SmartIO_INIT_LUT1_MODE))
#define SmartIO_INIT_LUT2_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT2_MAP  | SmartIO_INIT_LUT2_MODE))
#define SmartIO_INIT_LUT3_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT3_MAP  | SmartIO_INIT_LUT3_MODE))
#define SmartIO_INIT_LUT4_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT4_MAP  | SmartIO_INIT_LUT4_MODE))
#define SmartIO_INIT_LUT5_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT5_MAP  | SmartIO_INIT_LUT5_MODE))
#define SmartIO_INIT_LUT6_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT6_MAP  | SmartIO_INIT_LUT6_MODE))
#define SmartIO_INIT_LUT7_CTL_CONFIG     ((uint32_t)(SmartIO_INIT_LUT7_MAP  | SmartIO_INIT_LUT7_MODE))

/* Initial DU selection configuration */
#define SmartIO_INIT_DU_TR0_SEL          ((uint32_t)(SmartIO_DU_TR0 << SMARTIO_PRT_DU_SEL_DU_TR0_SEL_Pos))
#define SmartIO_INIT_DU_TR1_SEL          ((uint32_t)(SmartIO_DU_TR1 << SMARTIO_PRT_DU_SEL_DU_TR1_SEL_Pos))
#define SmartIO_INIT_DU_TR2_SEL          ((uint32_t)(SmartIO_DU_TR2 << SMARTIO_PRT_DU_SEL_DU_TR2_SEL_Pos))
#define SmartIO_INIT_DU_DATA0_SEL        ((uint32_t)(SmartIO_DU_DATA0 << SMARTIO_PRT_DU_SEL_DU_DATA0_SEL_Pos))
#define SmartIO_INIT_DU_DATA1_SEL        ((uint32_t)(SmartIO_DU_DATA1 << SMARTIO_PRT_DU_SEL_DU_DATA1_SEL_Pos))

#define SmartIO_INIT_DU_SEL              ((uint32_t)(SmartIO_INIT_DU_TR0_SEL | \
                                                    SmartIO_INIT_DU_TR1_SEL | \
                                                    SmartIO_INIT_DU_TR2_SEL | \
                                                    SmartIO_INIT_DU_DATA0_SEL | \
                                                    SmartIO_INIT_DU_DATA1_SEL ))

/* Initial DU control configuration */
#define SmartIO_INIT_DU_SIZE             ((uint32_t)(SmartIO_DU_SIZE << SMARTIO_PRT_DU_CTL_DU_SIZE_Pos))
#define SmartIO_INIT_DU_OPC              ((uint32_t)(SmartIO_DU_OPCODE << SMARTIO_PRT_DU_CTL_DU_OPC_Pos))

#define SmartIO_INIT_DU_CTL              ((uint32_t)(SmartIO_INIT_DU_SIZE | \
                                                    SmartIO_INIT_DU_OPC ))

/* Initial DU Data register */
#define SmartIO_INIT_DU_DATA_REG         SmartIO_DU_REG


/***************************************
*        Inline Functions
***************************************/

/**
* \addtogroup group_functions
* @{
*/


/*******************************************************************************
* Function Name: SmartIO_Enable
****************************************************************************//**
*
* \brief Enables the component. 
*  
* Once enabled, it takes two component clock cycles for the fabric reset to
* deactivate and the fabric becomes operational. If the clock source is set to
* Asynchronous mode, it takes three SYSCLK cycles before becoming functional.
*
* \funcusage
*  \snippet SmartIO_SUT.c usage_SmartIO_Enable
*******************************************************************************/
__STATIC_INLINE void SmartIO_Enable(void)
{
    SmartIO_PORT->CTL |= SmartIO_FABRIC_ENABLE;
}


/*******************************************************************************
* Function Name: SmartIO_Disable
****************************************************************************//**
*
* \brief Disables the component. 
*  
* The block is disabled, which places the channels into bypass mode and the
* sequential elements are reset based on the chosen clock selection.
*
* \funcusage
*  \snippet SmartIO_SUT.c usage_SmartIO_Disable
*******************************************************************************/
__STATIC_INLINE void SmartIO_Disable(void)
{
    SmartIO_PORT->CTL &= SmartIO_FABRIC_DISABLE;
}


/*******************************************************************************
* Function Name: SmartIO_GetBypass
****************************************************************************//**
*
* \brief Returns the bypass configuration of the channels on a bit by bit basis. 
*
* Bypassed channels behave like they would as if the SmartIO component was
* not present for those particular channels. 
*
* \return
*  uint8_t Bypass state of the channels on the port.
*
* \funcusage
*  \snippet SmartIO_SUT.c usage_SmartIO_GetBypass
*******************************************************************************/
__STATIC_INLINE uint8_t SmartIO_GetBypass(void)
{
    return ((uint8_t)(SmartIO_PORT->CTL & ((uint32_t)SmartIO_CHANNEL_ALL << SMARTIO_PRT_CTL_BYPASS_Pos)));
}


/** @} functions */

#endif /* (CY_SMARTIO_SmartIO_H) */


/* [] END OF FILE */
