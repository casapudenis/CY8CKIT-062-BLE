// ======================================================================
// CE219490_PSoC_6_MCU_Breathing_LED_using_SmartIO01.v generated from TopDesign.cysch
// 06/26/2023 at 13:21
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AD 15
`define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AE 16
`define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 17
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 18
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 19
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 20
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 21
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 22
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 23
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 24
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 25
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 26
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 27
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 28
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 29
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 30
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 31
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 32
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 33
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 37
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 38
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 33
`define CYDEV_CHIP_REVISION_USED 33
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// SmartIO_PDL_v1_0(Clock_select=16, data0_direction=0, data0_src=Undefined, data0_sync=0, data1_direction=0, data1_src=Undefined, data1_sync=0, data2_direction=0, data2_src=Undefined, data2_sync=0, data3_direction=0, data3_src=Undefined, data3_sync=0, data4_direction=1, data4_src=TCPWM[8].line, data4_sync=0, data5_direction=0, data5_src=Undefined, data5_sync=0, data6_direction=4, data6_src=Undefined, data6_sync=0, data7_direction=0, data7_src=Undefined, data7_sync=0, du_data0=0, du_data1=0, du_data1_used=true, du_details=Clock = Divided Clock (Active)\r\nTR0 = Constant 0\r\nTR1 = Constant 0\r\ndu_size = Size - 1\r\nmask = (1 << (du_size + 1)) ? 1\r\ndata_eql_data1 = (data & mask) == (DATA1 & mask)\r\n\r\nCombinatorial:\r\ntr_out = data_eql_data1\r\n\r\nRegistered/Clocked:\r\ndata <= data\r\nif(TR0)\r\n    data <= DATA0 & mask\r\nelse if (TR1)\r\n    data <= data_eql_data1 ? data : (data + 1) & mask, du_in0=0, du_in1=0, du_in2=0, du_opcode=1, du_reg=0, du_reg_used=false, du_size=7, du_size_display=8, du_used=false, Fabric_bypass0=1, Fabric_bypass1=1, Fabric_bypass2=1, Fabric_bypass3=1, Fabric_bypass4=0, Fabric_bypass5=1, Fabric_bypass6=0, Fabric_bypass7=1, gpio0_direction=0, gpio0_sync=0, gpio1_direction=0, gpio1_sync=0, gpio2_direction=0, gpio2_sync=0, gpio3_direction=0, gpio3_sync=0, gpio4_direction=2, gpio4_sync=0, gpio5_direction=0, gpio5_sync=0, gpio6_direction=2, gpio6_sync=0, gpio7_direction=0, gpio7_sync=0, HsiomConnection0=Undefined, HsiomConnection1=Undefined, HsiomConnection2=Undefined, HsiomConnection3=Undefined, HsiomConnection4=TCPWM[8].line, HsiomConnection5=Undefined, HsiomConnection6=Undefined, HsiomConnection7=Undefined, lut0_in0=17, lut0_in1=17, lut0_in2=17, lut0_map=0, lut0_mode=0, lut0_used=false, lut1_in0=17, lut1_in1=17, lut1_in2=17, lut1_map=0, lut1_mode=0, lut1_used=false, lut2_in0=2, lut2_in1=2, lut2_in2=2, lut2_map=1, lut2_mode=2, lut2_used=true, lut3_in0=2, lut3_in1=3, lut3_in2=3, lut3_map=129, lut3_mode=2, lut3_used=true, lut4_in0=8, lut4_in1=3, lut4_in2=3, lut4_map=66, lut4_mode=0, lut4_used=true, lut5_in0=17, lut5_in1=17, lut5_in2=17, lut5_map=0, lut5_mode=0, lut5_used=false, lut6_in0=4, lut6_in1=4, lut6_in2=4, lut6_map=1, lut6_mode=0, lut6_used=true, lut7_in0=17, lut7_in1=17, lut7_in2=17, lut7_map=0, lut7_mode=0, lut7_used=false, Target_port=9, UseHldOvr=false, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SmartIO_PDL_v1_0, CY_CONFIG_TITLE=SmartIO, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SmartIO, CY_INSTANCE_SHORT_NAME=SmartIO, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=SmartIO, )
module SmartIO_PDL_v1_0_0 (
    clock,
    data0_in,
    data0_inout,
    data0_out,
    data1_in,
    data1_inout,
    data1_out,
    data2_in,
    data2_inout,
    data2_out,
    data3_in,
    data3_inout,
    data3_out,
    data4_in,
    data4_inout,
    data4_out,
    data5_in,
    data5_inout,
    data5_out,
    data6_in,
    data6_inout,
    data6_out,
    data7_in,
    data7_inout,
    data7_out,
    gpio0_in,
    gpio0_inout,
    gpio0_out,
    gpio1_in,
    gpio1_inout,
    gpio1_out,
    gpio2_in,
    gpio2_inout,
    gpio2_out,
    gpio3_in,
    gpio3_inout,
    gpio3_out,
    gpio4_in,
    gpio4_inout,
    gpio4_out,
    gpio5_in,
    gpio5_inout,
    gpio5_out,
    gpio6_in,
    gpio6_inout,
    gpio6_out,
    gpio7_in,
    gpio7_inout,
    gpio7_out);
    input       clock;
    input       data0_in;
    inout       data0_inout;
    output      data0_out;
    input       data1_in;
    inout       data1_inout;
    output      data1_out;
    input       data2_in;
    inout       data2_inout;
    output      data2_out;
    input       data3_in;
    inout       data3_inout;
    output      data3_out;
    input       data4_in;
    inout       data4_inout;
    output      data4_out;
    input       data5_in;
    inout       data5_inout;
    output      data5_out;
    input       data6_in;
    inout       data6_inout;
    output      data6_out;
    input       data7_in;
    inout       data7_inout;
    output      data7_out;
    input       gpio0_in;
    inout       gpio0_inout;
    output      gpio0_out;
    input       gpio1_in;
    inout       gpio1_inout;
    output      gpio1_out;
    input       gpio2_in;
    inout       gpio2_inout;
    output      gpio2_out;
    input       gpio3_in;
    inout       gpio3_inout;
    output      gpio3_out;
    input       gpio4_in;
    inout       gpio4_inout;
    output      gpio4_out;
    input       gpio5_in;
    inout       gpio5_inout;
    output      gpio5_out;
    input       gpio6_in;
    inout       gpio6_inout;
    output      gpio6_out;
    input       gpio7_in;
    inout       gpio7_inout;
    output      gpio7_out;


          wire  Net_81;
          wire  Net_65;
          wire  Net_63;
          wire  Net_61;
          wire  Net_59;
          wire  Net_57;
          wire  Net_55;
          wire  Net_53;
          wire  Net_51;
          wire  Net_49;
          wire  Net_47;
          wire  Net_45;
          wire  Net_43;
          wire  Net_41;
          wire  Net_39;
          wire  Net_37;
          wire  Net_35;
          wire  Net_83;
          wire  Net_801;
          wire  Net_800;
          wire  Net_799;
          wire  Net_798;
          wire  Net_797;
          wire  Net_78;
          wire  Net_66;
          wire  Net_654;
          wire  Net_788;
          wire  Net_775;
          wire  Net_772;
          wire  Net_761;
          wire  Net_796;
          wire  Net_794;
          wire  Net_792;
          wire  Net_790;

	// VirtualMux_0 (cy_virtualmux_v1_0)
	assign Net_654 = gpio0_in;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_66 = gpio1_in;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_78 = gpio2_in;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_797 = gpio3_in;

	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign Net_798 = gpio4_in;

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign Net_799 = gpio5_in;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign Net_800 = gpio6_in;

	// VirtualMux_7 (cy_virtualmux_v1_0)
	assign Net_801 = gpio7_in;

    cy_mxs40_smartio_v1_0 cy_mxs40_smartio (
        .clock(Net_83),
        .data0_i(data0_in),
        .data0_io(data0_inout),
        .data0_o(data0_out),
        .data0_oe(Net_35),
        .data1_i(data1_in),
        .data1_io(data1_inout),
        .data1_o(data1_out),
        .data1_oe(Net_37),
        .data2_i(data2_in),
        .data2_io(data2_inout),
        .data2_o(data2_out),
        .data2_oe(Net_39),
        .data3_i(data3_in),
        .data3_io(data3_inout),
        .data3_o(data3_out),
        .data3_oe(Net_41),
        .data4_i(data4_in),
        .data4_io(data4_inout),
        .data4_o(data4_out),
        .data4_oe(Net_43),
        .data5_i(data5_in),
        .data5_io(data5_inout),
        .data5_o(data5_out),
        .data5_oe(Net_45),
        .data6_i(data6_in),
        .data6_io(data6_inout),
        .data6_o(data6_out),
        .data6_oe(Net_47),
        .data7_i(data7_in),
        .data7_io(data7_inout),
        .data7_o(data7_out),
        .data7_oe(Net_49),
        .gpio0_i(Net_654),
        .gpio0_io(gpio0_inout),
        .gpio0_o(gpio0_out),
        .gpio0_oe(Net_51),
        .gpio1_i(Net_66),
        .gpio1_io(gpio1_inout),
        .gpio1_o(gpio1_out),
        .gpio1_oe(Net_53),
        .gpio2_i(Net_78),
        .gpio2_io(gpio2_inout),
        .gpio2_o(gpio2_out),
        .gpio2_oe(Net_55),
        .gpio3_i(Net_797),
        .gpio3_io(gpio3_inout),
        .gpio3_o(gpio3_out),
        .gpio3_oe(Net_57),
        .gpio4_i(Net_798),
        .gpio4_io(gpio4_inout),
        .gpio4_o(gpio4_out),
        .gpio4_oe(Net_59),
        .gpio5_i(Net_799),
        .gpio5_io(gpio5_inout),
        .gpio5_o(gpio5_out),
        .gpio5_oe(Net_61),
        .gpio6_i(Net_800),
        .gpio6_io(gpio6_inout),
        .gpio6_o(gpio6_out),
        .gpio6_oe(Net_63),
        .gpio7_i(Net_801),
        .gpio7_io(gpio7_inout),
        .gpio7_o(gpio7_out),
        .gpio7_oe(Net_65));
    defparam cy_mxs40_smartio.port_id = 9;

	// VirtualMux_8 (cy_virtualmux_v1_0)
	assign Net_83 = clock;

    assign Net_81 = 1'h0;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=20, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=40, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=PWM, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM, CY_INSTANCE_SHORT_NAME=PWM, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=PWM, )
module TCPWM_PWM_PDL_v1_0_1 (
    clock,
    compare,
    count,
    interrupt,
    kill,
    ovrflw,
    pwm,
    pwm_n,
    reload,
    start,
    swap,
    undrflw);
    input       clock;
    output      compare;
    input       count;
    output      interrupt;
    input       kill;
    output      ovrflw;
    output      pwm;
    output      pwm_n;
    input       reload;
    input       start;
    input       swap;
    output      undrflw;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .capture(swap),
        .clock(clock),
        .count(count),
        .interrupt(interrupt),
        .line(pwm),
        .line_compl(pwm_n),
        .reload(reload),
        .start(start),
        .stop(kill),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .tr_underflow(undrflw));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// top
module top ;

          wire  Net_126;
          wire  Net_125;
          wire  Net_124;
          wire  Net_123;
          wire  Net_122;
          wire  Net_121;
          wire  Net_120;
          wire  Net_119;
          wire  Net_118;
          wire  Net_117;
          wire  Net_116;
          wire  Net_115;
          wire  Net_114;
          wire  Net_113;
          wire  Net_112;
          wire  Net_111;
          wire  Net_110;
          wire  Net_109;
          wire  Net_108;
          wire  Net_107;
          wire  Net_106;
          wire  Net_105;
          wire  Net_104;
          wire  Net_103;
          wire  Net_102;
          wire  Net_101;
          wire  Net_100;
          wire  Net_99;
          wire  Net_98;
          wire  Net_97;
          wire  Net_96;
          wire  Net_95;
          wire  Net_94;
          wire  Net_93;
          wire  Net_92;
          wire  Net_91;
          wire  Net_90;
          wire  Net_89;
          wire  Net_88;
          wire  Net_87;
          wire  Net_86;
          wire  Net_85;
          wire  Net_84;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;
          wire  Net_80;
          wire  Net_79;
          wire  Net_78;
          wire  Net_77;
          wire  Net_76;
          wire  Net_75;
          wire  Net_74;
          wire  Net_73;
          wire  Net_72;
          wire  Net_71;
          wire  Net_69;
    electrical  Net_68;
    electrical  Net_67;
    electrical  Net_65;
    electrical  Net_63;
          wire  Net_59;
          wire  Net_18;
          wire  Net_70;
    electrical  Net_62;
          wire  Net_171;
          wire  Net_170;

    SmartIO_PDL_v1_0_0 SmartIO (
        .clock(Net_70),
        .data0_in(1'b0),
        .data0_inout(Net_71),
        .data0_out(Net_72),
        .data1_in(1'b0),
        .data1_inout(Net_74),
        .data1_out(Net_75),
        .data2_in(1'b0),
        .data2_inout(Net_77),
        .data2_out(Net_78),
        .data3_in(1'b0),
        .data3_inout(Net_80),
        .data3_out(Net_81),
        .data4_in(Net_18),
        .data4_inout(Net_82),
        .data4_out(Net_83),
        .data5_in(1'b0),
        .data5_inout(Net_85),
        .data5_out(Net_86),
        .data6_in(1'b0),
        .data6_inout(Net_88),
        .data6_out(Net_89),
        .data7_in(1'b0),
        .data7_inout(Net_91),
        .data7_out(Net_92),
        .gpio0_in(1'b0),
        .gpio0_inout(Net_94),
        .gpio0_out(Net_95),
        .gpio1_in(1'b0),
        .gpio1_inout(Net_97),
        .gpio1_out(Net_98),
        .gpio2_in(1'b0),
        .gpio2_inout(Net_100),
        .gpio2_out(Net_101),
        .gpio3_in(1'b0),
        .gpio3_inout(Net_103),
        .gpio3_out(Net_104),
        .gpio4_in(1'b0),
        .gpio4_inout(Net_106),
        .gpio4_out(Net_170),
        .gpio5_in(1'b0),
        .gpio5_inout(Net_108),
        .gpio5_out(Net_109),
        .gpio6_in(1'b0),
        .gpio6_inout(Net_111),
        .gpio6_out(Net_171),
        .gpio7_in(1'b0),
        .gpio7_inout(Net_113),
        .gpio7_out(Net_114));

    TCPWM_PWM_PDL_v1_0_1 PWM (
        .clock(Net_59),
        .compare(Net_115),
        .count(1'b1),
        .interrupt(Net_117),
        .kill(1'b0),
        .ovrflw(Net_119),
        .pwm(Net_18),
        .pwm_n(Net_120),
        .reload(1'b0),
        .start(1'b0),
        .swap(1'b0),
        .undrflw(Net_124));


	cy_clock_v1_0
		#(.id("9b4bda15-25f9-4b58-a324-ff10418e7fd1"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("1000000000000"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_pwm
		 (.clock_out(Net_59));



	cy_clock_v1_0
		#(.id("9da322ae-b054-46ce-b546-c2a68bc9ed4a"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("10101010101010.1"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_smartio
		 (.clock_out(Net_70));


	wire [0:0] tmpFB_0__Pin_LED_1_net;
	wire [0:0] tmpIO_0__Pin_LED_1_net;
	electrical [0:0] tmpSIOVREF__Pin_LED_1_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		Pin_LED_1
		 (.oe({1'b1}),
		  .y({Net_171}),
		  .fb({tmpFB_0__Pin_LED_1_net[0:0]}),
		  .io({tmpIO_0__Pin_LED_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_LED_1_net),
		  .annotation({Net_67}));


	wire [0:0] tmpFB_0__Pin_LED_2_net;
	wire [0:0] tmpIO_0__Pin_LED_2_net;
	electrical [0:0] tmpSIOVREF__Pin_LED_2_net;

	cy_mxs40_gpio_v1_0
		#(.id("72d55028-fecb-4045-ad69-7d51b6de809e"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("1"),
		  .hotswap_needed("0"))
		Pin_LED_2
		 (.oe({1'b1}),
		  .y({Net_170}),
		  .fb({tmpFB_0__Pin_LED_2_net[0:0]}),
		  .io({tmpIO_0__Pin_LED_2_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_LED_2_net),
		  .annotation({Net_68}));


    cy_annotation_universal_v1_0 LED8 (
        .connect({
            Net_62,
            Net_63
        })
    );
    defparam LED8.comp_name = "LED_v1_0";
    defparam LED8.port_names = "A, K";
    defparam LED8.width = 2;

    cy_annotation_universal_v1_0 LED9 (
        .connect({
            Net_62,
            Net_65
        })
    );
    defparam LED9.comp_name = "LED_v1_0";
    defparam LED9.port_names = "A, K";
    defparam LED9.width = 2;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_62
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_63,
            Net_67
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_65,
            Net_68
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;



endmodule

