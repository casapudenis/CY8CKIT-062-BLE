
/*******************************************************************************
* File Name: cyfitter_cfg.c
* 
* PSoC Creator  4.4
*
* Description:
* This file contains device initialization code.
* Except for the user defined sections in CyClockStartupError(), this file should not be modified.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include "cydevice_trm.h"
#include "cyfitter.h"
#include "gpio/cy_gpio.h"
#include "syslib/cy_syslib.h"
#include "cyfitter_cfg.h"
#include "cyapicallbacks.h"
#include "sysclk/cy_sysclk.h"
#include "systick/cy_systick.h"

#define CY_NEED_CYCLOCKSTARTUPERROR 1
#include "syspm/cy_syspm.h"


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CYPACKED 
    #define CYPACKED_ATTR __attribute__ ((packed))
    #define CYALIGNED __attribute__ ((aligned))
    #define CY_CFG_UNUSED __attribute__ ((unused))
    #ifndef CY_CFG_SECTION
        #define CY_CFG_SECTION __attribute__ ((section(".psocinit")))
    #endif
    
    #if defined(__ARMCC_VERSION)
        #define CY_CFG_MEMORY_BARRIER() __memory_changed()
    #else
        #define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
    #endif
    
#elif defined(__ICCARM__)
    #include <intrinsics.h>

    #define CYPACKED __packed
    #define CYPACKED_ATTR 
    #define CYALIGNED _Pragma("data_alignment=4")
    #define CY_CFG_UNUSED _Pragma("diag_suppress=Pe177")
    #define CY_CFG_SECTION _Pragma("location=\".psocinit\"")
    
    #define CY_CFG_MEMORY_BARRIER() __DMB()
    
#else
    #error Unsupported toolchain
#endif

#ifndef CYCODE
    #define CYCODE
#endif
#ifndef CYDATA
    #define CYDATA
#endif
#ifndef CYFAR
    #define CYFAR
#endif
#ifndef CYXDATA
    #define CYXDATA
#endif


CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n);
CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n)
{
	(void)memset(s, 0, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}




/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0u
#define CYCLOCKSTART_XTAL_ERROR  1u
#define CYCLOCKSTART_32KHZ_ERROR 2u
#define CYCLOCKSTART_PLL_ERROR   3u
#define CYCLOCKSTART_FLL_ERROR   4u
#define CYCLOCKSTART_WCO_ERROR   5u


#ifdef CY_NEED_CYCLOCKSTARTUPERROR
/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc.), the system will end up here.  Unless reimplemented by
*  the customer, this function will stop in an infinite loop.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode);
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

#ifdef CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK
    CY_CFG_Clock_Startup_ErrorCallback();
#else
    while(1) {}
#endif /* CY_CFG_CLOCK_STARTUP_ERROR_CALLBACK */
}
#endif

static void ClockInit(void);
static void ClockInit(void)
{
	uint32_t status;

	/* Enable all source clocks */
	Cy_SysClk_ClkLfSetSource(CY_SYSCLK_CLKLF_IN_ILO);

	/* Configure CPU clock dividers */
	Cy_SysClk_ClkFastSetDivider(0u);
	Cy_SysClk_ClkPeriSetDivider(1u);
	Cy_SysClk_ClkSlowSetDivider(0u);

	/* Configure LF & HF clocks */
	Cy_SysClk_ClkHfSetSource(0u, CY_SYSCLK_CLKHF_IN_CLKPATH0);
	Cy_SysClk_ClkHfSetDivider(0u, CY_SYSCLK_CLKHF_NO_DIVIDE);
	Cy_SysClk_ClkHfEnable(0u);
	Cy_SysClk_ClkHfSetSource(1u, CY_SYSCLK_CLKHF_IN_CLKPATH0);
	Cy_SysClk_ClkHfSetDivider(1u, CY_SYSCLK_CLKHF_NO_DIVIDE);
	Cy_SysClk_ClkHfEnable(1u);
	Cy_SysClk_ClkHfSetSource(2u, CY_SYSCLK_CLKHF_IN_CLKPATH0);
	Cy_SysClk_ClkHfSetDivider(2u, CY_SYSCLK_CLKHF_NO_DIVIDE);
	Cy_SysClk_ClkHfEnable(2u);
	Cy_SysClk_ClkHfSetSource(3u, CY_SYSCLK_CLKHF_IN_CLKPATH0);
	Cy_SysClk_ClkHfSetDivider(3u, CY_SYSCLK_CLKHF_NO_DIVIDE);
	Cy_SysClk_ClkHfEnable(3u);
	Cy_SysClk_ClkHfSetSource(4u, CY_SYSCLK_CLKHF_IN_CLKPATH0);
	Cy_SysClk_ClkHfSetDivider(4u, CY_SYSCLK_CLKHF_NO_DIVIDE);
	Cy_SysClk_ClkHfEnable(4u);

	/* Configure Path Clocks */
	Cy_SysClk_ClkPathSetSource(1, CY_SYSCLK_CLKPATH_IN_IMO);
	Cy_SysClk_ClkPathSetSource(2, CY_SYSCLK_CLKPATH_IN_IMO);
	Cy_SysClk_ClkPathSetSource(3, CY_SYSCLK_CLKPATH_IN_IMO);
	Cy_SysClk_ClkPathSetSource(4, CY_SYSCLK_CLKPATH_IN_IMO);
	Cy_SysClk_ClkPathSetSource(0, CY_SYSCLK_CLKPATH_IN_IMO);
	{
		const cy_stc_fll_manual_config_t fllConfig = 
		{
			.fllMult =         500u,
			.refDiv =          20u,
			.ccoRange =        CY_SYSCLK_FLL_CCO_RANGE4,
			.enableOutputDiv = true,
			.lockTolerance =   10u,
			.igain =           9u,
			.pgain =           5u,
			.settlingCount =   8u,
			.outputMode =      CY_SYSCLK_FLLPLL_OUTPUT_AUTO,
			.cco_Freq =        355u
		};
		status = Cy_SysClk_FllManualConfigure(&fllConfig);
		if (CY_RET_SUCCESS != status)
		{
			CyClockStartupError(CYCLOCKSTART_FLL_ERROR);
		}
	}
	SRSS->CLK_TRIM_CCO_CTL |= 1u << 31;
	status = Cy_SysClk_FllEnable(200000u);
	if (CY_RET_SUCCESS != status)
	{
		CyClockStartupError(CYCLOCKSTART_FLL_ERROR);
	}

	/* Configure miscellaneous clocks */
	Cy_SysClk_ClkTimerSetSource(CY_SYSCLK_CLKTIMER_IN_IMO);
	Cy_SysClk_ClkTimerSetDivider(0);
	Cy_SysClk_ClkTimerEnable();
	Cy_SysClk_ClkPumpSetSource(CY_SYSCLK_PUMP_IN_CLKPATH0);
	Cy_SysClk_ClkPumpSetDivider(CY_SYSCLK_PUMP_DIV_4);
	Cy_SysClk_ClkPumpEnable();
	Cy_SysClk_ClkBakSetSource(CY_SYSCLK_BAK_IN_CLKLF);
	Cy_SysTick_SetClockSource(CY_SYSTICK_CLOCK_SOURCE_CLK_LF);
	Cy_SysClk_IloEnable();
	Cy_SysClk_IloHibernateOn(1u);

	/* Set memory wait states based on 100 MHz HFClk[0] */
	Cy_SysLib_SetWaitStates(false, 100);
}


/* Analog API Functions */


/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void AnalogSetDefault(void);
static void AnalogSetDefault(void)
{
}




/*******************************************************************************
* Function Name: Cy_SystemInit
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/

void Cy_SystemInit(void)
{
	/* Set worst case memory wait states (150 MHz), ClockInit() will update */
	Cy_SysLib_SetWaitStates(false, 150);

	if(0u == Cy_SysLib_GetResetReason()) /* POR, XRES, or BOD */
	{
		Cy_SysLib_ResetBackupDomain();
		Cy_SysClk_IloDisable();
		Cy_SysClk_IloEnable();
	}

	/* Power Mode */
	Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_1_1V);

	/* PMIC Control */
	Cy_SysPm_UnlockPmic();
	Cy_SysPm_DisablePmicOutput();

	/* Clock */
	ClockInit();

	/* Port0 configuration */
	{
	    const cy_stc_gpio_prt_config_t port0_cfg =
	    {
	        .out        = 0x00000008u,
	        .intrMask   = 0x00000000u,
	        .intrCfg    = 0x00000000u,
	        .cfg        = 0x00006000u,
	        .cfgIn      = 0x00000000u,
	        .cfgOut     = 0x00000000u,
	        .cfgSIO     = 0x00000000u,
	        .sel0Active = 0x00000000u,
	        .sel1Active = 0x00000000u,
	    };
	    (void)Cy_GPIO_Port_Init(GPIO_PRT0, &port0_cfg);
	}

	/* Port6 configuration */
	{
	    const cy_stc_gpio_prt_config_t port6_cfg =
	    {
	        .out        = 0x00000000u,
	        .intrMask   = 0x00000000u,
	        .intrCfg    = 0x00000000u,
	        .cfg        = 0xBA000000u,
	        .cfgIn      = 0x00000000u,
	        .cfgOut     = 0x00000000u,
	        .cfgSIO     = 0x00000000u,
	        .sel0Active = 0x00000000u,
	        .sel1Active = 0x1D1D0000u,
	    };
	    (void)Cy_GPIO_Port_Init(GPIO_PRT6, &port6_cfg);
	}

	/* Port11 configuration */
	{
	    const cy_stc_gpio_prt_config_t port11_cfg =
	    {
	        .out        = 0x00000002u,
	        .intrMask   = 0x00000000u,
	        .intrCfg    = 0x00000000u,
	        .cfg        = 0x00000060u,
	        .cfgIn      = 0x00000000u,
	        .cfgOut     = 0x00000000u,
	        .cfgSIO     = 0x00000000u,
	        .sel0Active = 0x00000000u,
	        .sel1Active = 0x00000000u,
	    };
	    (void)Cy_GPIO_Port_Init(GPIO_PRT11, &port11_cfg);
	}


	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

}
