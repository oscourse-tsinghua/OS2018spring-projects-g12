/* sm501-regs.h
 *
 * Copyright 2006 Simtec Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Silicon Motion SM501 register definitions
*/

/* System Configuration area */
/* System config base */
#define SM501_SYS_CONFIG		(0x000000)

/* config 1 */
#define SM501_SYSTEM_CONTROL 		(0x000000)

#define SM501_SYSCTRL_PANEL_TRISTATE	(1<<0)
#define SM501_SYSCTRL_MEM_TRISTATE	(1<<1)
#define SM501_SYSCTRL_CRT_TRISTATE	(1<<2)

#define SM501_SYSCTRL_PCI_SLAVE_BURST_MASK (3<<4)
#define SM501_SYSCTRL_PCI_SLAVE_BURST_1	(0<<4)
#define SM501_SYSCTRL_PCI_SLAVE_BURST_2	(1<<4)
#define SM501_SYSCTRL_PCI_SLAVE_BURST_4	(2<<4)
#define SM501_SYSCTRL_PCI_SLAVE_BURST_8	(3<<4)

#define SM501_SYSCTRL_PCI_CLOCK_RUN_EN	(1<<6)
#define SM501_SYSCTRL_PCI_RETRY_DISABLE	(1<<7)
#define SM501_SYSCTRL_PCI_SUBSYS_LOCK	(1<<11)
#define SM501_SYSCTRL_PCI_BURST_READ_EN	(1<<15)

/* miscellaneous control */

#define SM501_MISC_CONTROL		(0x000004)

#define SM501_MISC_BUS_SH		(0x0)
#define SM501_MISC_BUS_PCI		(0x1)
#define SM501_MISC_BUS_XSCALE		(0x2)
#define SM501_MISC_BUS_NEC		(0x6)
#define SM501_MISC_BUS_MASK		(0x7)

#define SM501_MISC_VR_62MB		(1<<3)
#define SM501_MISC_CDR_RESET		(1<<7)
#define SM501_MISC_USB_LB		(1<<8)
#define SM501_MISC_USB_SLAVE		(1<<9)
#define SM501_MISC_BL_1			(1<<10)
#define SM501_MISC_MC			(1<<11)
#define SM501_MISC_DAC_POWER		(1<<12)
#define SM501_MISC_IRQ_INVERT		(1<<16)
#define SM501_MISC_SH			(1<<17)

#define SM501_MISC_HOLD_EMPTY		(0<<18)
#define SM501_MISC_HOLD_8		(1<<18)
#define SM501_MISC_HOLD_16		(2<<18)
#define SM501_MISC_HOLD_24		(3<<18)
#define SM501_MISC_HOLD_32		(4<<18)
#define SM501_MISC_HOLD_MASK		(7<<18)

#define SM501_MISC_FREQ_12		(1<<24)
#define SM501_MISC_PNL_24BIT		(1<<25)
#define SM501_MISC_8051_LE		(1<<26)

#define SM501_GPIO31_0_CONTROL		(0x000008)
#define SM501_GPIO63_32_CONTROL		(0x00000C)
#define SM501_DRAM_CONTROL		(0x000010)

/* command list */
#define SM501_ARBTRTN_CONTROL		(0x000014)

/* command list */
#define SM501_COMMAND_LIST_STATUS	(0x000024)

/* interrupt debug */
#define SM501_RAW_IRQ_STATUS		(0x000028)
#define SM501_RAW_IRQ_CLEAR		(0x000028)
#define SM501_IRQ_STATUS		(0x00002C)
#define SM501_IRQ_MASK			(0x000030)
#define SM501_DEBUG_CONTROL		(0x000034)

/* power management */
#define SM501_POWERMODE_P2X_SRC		(1<<29)
#define SM501_POWERMODE_V2X_SRC		(1<<20)
#define SM501_POWERMODE_M_SRC		(1<<12)
#define SM501_POWERMODE_M1_SRC		(1<<4)

#define SM501_CURRENT_GATE		(0x000038)
#define SM501_CURRENT_CLOCK		(0x00003C)
#define SM501_POWER_MODE_0_GATE		(0x000040)
#define SM501_POWER_MODE_0_CLOCK	(0x000044)
#define SM501_POWER_MODE_1_GATE		(0x000048)
#define SM501_POWER_MODE_1_CLOCK	(0x00004C)
#define SM501_SLEEP_MODE_GATE		(0x000050)
#define SM501_POWER_MODE_CONTROL	(0x000054)

/* power gates for units within the 501 */
#define SM501_GATE_HOST			(0)
#define SM501_GATE_MEMORY		(1)
#define SM501_GATE_DISPLAY		(2)
#define SM501_GATE_2D_ENGINE		(3)
#define SM501_GATE_CSC			(4)
#define SM501_GATE_ZVPORT		(5)
#define SM501_GATE_GPIO			(6)
#define SM501_GATE_UART0		(7)
#define SM501_GATE_UART1		(8)
#define SM501_GATE_SSP			(10)
#define SM501_GATE_USB_HOST		(11)
#define SM501_GATE_USB_GADGET		(12)
#define SM501_GATE_UCONTROLLER		(17)
#define SM501_GATE_AC97			(18)

/* panel clock */
#define SM501_CLOCK_P2XCLK		(24)
/* crt clock */
#define SM501_CLOCK_V2XCLK		(16)
/* main clock */
#define SM501_CLOCK_MCLK		(8)
/* SDRAM controller clock */
#define SM501_CLOCK_M1XCLK		(0)

/* config 2 */
#define SM501_PCI_MASTER_BASE		(0x000058)
#define SM501_ENDIAN_CONTROL		(0x00005C)
#define SM501_DEVICEID			(0x000060)
/* 0x050100A0 */

#define SM501_DEVICEID_SM501		(0x05010000)
#define SM501_DEVICEID_IDMASK		(0xffff0000)
#define SM501_DEVICEID_REVMASK		(0x000000ff)

#define SM501_PLLCLOCK_COUNT		(0x000064)
#define SM501_MISC_TIMING		(0x000068)
#define SM501_CURRENT_SDRAM_CLOCK	(0x00006C)

#define SM501_PROGRAMMABLE_PLL_CONTROL	(0x000074)

/* GPIO base */
#define SM501_GPIO			(0x010000)
#define SM501_GPIO_DATA_LOW		(0x00)
#define SM501_GPIO_DATA_HIGH		(0x04)
#define SM501_GPIO_DDR_LOW		(0x08)
#define SM501_GPIO_DDR_HIGH		(0x0C)
#define SM501_GPIO_IRQ_SETUP		(0x10)
#define SM501_GPIO_IRQ_STATUS		(0x14)
#define SM501_GPIO_IRQ_RESET		(0x14)

/* I2C controller base */
#define SM501_I2C			(0x010040)
#define SM501_I2C_BYTE_COUNT		(0x00)
#define SM501_I2C_CONTROL		(0x01)
#define SM501_I2C_STATUS		(0x02)
#define SM501_I2C_RESET			(0x02)
#define SM501_I2C_SLAVE_ADDRESS		(0x03)
#define SM501_I2C_DATA			(0x04)

/* SSP base */
#define SM501_SSP			(0x020000)

/* Uart 0 base */
#define SM501_UART0			(0x030000)

/* Uart 1 base */
#define SM501_UART1			(0x030020)

/* USB host port base */
#define SM501_USB_HOST			(0x040000)

/* USB slave/gadget base */
#define SM501_USB_GADGET		(0x060000)

/* USB slave/gadget data port base */
#define SM501_USB_GADGET_DATA		(0x070000)

/* Display controller/video engine base */
#define SM501_DC			(0x080000)

/* common defines for the SM501 address registers */
#define SM501_ADDR_FLIP			(1<<31)
#define SM501_ADDR_EXT			(1<<27)
#define SM501_ADDR_CS1			(1<<26)
#define SM501_ADDR_MASK			(0x3f << 26)

#define SM501_FIFO_MASK			(0x3 << 16)
#define SM501_FIFO_1			(0x0 << 16)
#define SM501_FIFO_3			(0x1 << 16)
#define SM501_FIFO_7			(0x2 << 16)
#define SM501_FIFO_11			(0x3 << 16)

/* common registers for panel and the crt */
#define SM501_OFF_DC_H_TOT		(0x000)
#define SM501_OFF_DC_V_TOT		(0x008)
#define SM501_OFF_DC_H_SYNC		(0x004)
#define SM501_OFF_DC_V_SYNC		(0x00C)

#define SM501_DC_PANEL_CONTROL		(0x000)

#define SM501_DC_PANEL_CONTROL_FPEN	(1<<27)
#define SM501_DC_PANEL_CONTROL_BIAS	(1<<26)
#define SM501_DC_PANEL_CONTROL_DATA	(1<<25)
#define SM501_DC_PANEL_CONTROL_VDD	(1<<24)
#define SM501_DC_PANEL_CONTROL_DP	(1<<23)

#define SM501_DC_PANEL_CONTROL_TFT_888	(0<<21)
#define SM501_DC_PANEL_CONTROL_TFT_333	(1<<21)
#define SM501_DC_PANEL_CONTROL_TFT_444	(2<<21)

#define SM501_DC_PANEL_CONTROL_DE	(1<<20)

#define SM501_DC_PANEL_CONTROL_LCD_TFT	(0<<18)
#define SM501_DC_PANEL_CONTROL_LCD_STN8	(1<<18)
#define SM501_DC_PANEL_CONTROL_LCD_STN12 (2<<18)

#define SM501_DC_PANEL_CONTROL_CP	(1<<14)
#define SM501_DC_PANEL_CONTROL_VSP	(1<<13)
#define SM501_DC_PANEL_CONTROL_HSP	(1<<12)
#define SM501_DC_PANEL_CONTROL_CK	(1<<9)
#define SM501_DC_PANEL_CONTROL_TE	(1<<8)
#define SM501_DC_PANEL_CONTROL_VPD	(1<<7)
#define SM501_DC_PANEL_CONTROL_VP	(1<<6)
#define SM501_DC_PANEL_CONTROL_HPD	(1<<5)
#define SM501_DC_PANEL_CONTROL_HP	(1<<4)
#define SM501_DC_PANEL_CONTROL_GAMMA	(1<<3)
#define SM501_DC_PANEL_CONTROL_EN	(1<<2)

#define SM501_DC_PANEL_CONTROL_8BPP	(0<<0)
#define SM501_DC_PANEL_CONTROL_16BPP	(1<<0)
#define SM501_DC_PANEL_CONTROL_32BPP	(2<<0)

#define SM501_DC_PANEL_PANNING_CONTROL	(0x004)
#define SM501_DC_PANEL_COLOR_KEY	(0x008)
#define SM501_DC_PANEL_FB_ADDR		(0x00C)
#define SM501_DC_PANEL_FB_OFFSET	(0x010)
#define SM501_DC_PANEL_FB_WIDTH		(0x014)
#define SM501_DC_PANEL_FB_HEIGHT	(0x018)
#define SM501_DC_PANEL_TL_LOC		(0x01C)
#define SM501_DC_PANEL_BR_LOC		(0x020)
#define SM501_DC_PANEL_H_TOT		(0x024)
#define SM501_DC_PANEL_H_SYNC		(0x028)
#define SM501_DC_PANEL_V_TOT		(0x02C)
#define SM501_DC_PANEL_V_SYNC		(0x030)
#define SM501_DC_PANEL_CUR_LINE		(0x034)

#define SM501_DC_VIDEO_CONTROL		(0x040)
#define SM501_DC_VIDEO_FB0_ADDR		(0x044)
#define SM501_DC_VIDEO_FB_WIDTH		(0x048)
#define SM501_DC_VIDEO_FB0_LAST_ADDR	(0x04C)
#define SM501_DC_VIDEO_TL_LOC		(0x050)
#define SM501_DC_VIDEO_BR_LOC		(0x054)
#define SM501_DC_VIDEO_SCALE		(0x058)
#define SM501_DC_VIDEO_INIT_SCALE	(0x05C)
#define SM501_DC_VIDEO_YUV_CONSTANTS	(0x060)
#define SM501_DC_VIDEO_FB1_ADDR		(0x064)
#define SM501_DC_VIDEO_FB1_LAST_ADDR	(0x068)

#define SM501_DC_VIDEO_ALPHA_CONTROL	(0x080)
#define SM501_DC_VIDEO_ALPHA_FB_ADDR	(0x084)
#define SM501_DC_VIDEO_ALPHA_FB_OFFSET	(0x088)
#define SM501_DC_VIDEO_ALPHA_FB_LAST_ADDR	(0x08C)
#define SM501_DC_VIDEO_ALPHA_TL_LOC	(0x090)
#define SM501_DC_VIDEO_ALPHA_BR_LOC	(0x094)
#define SM501_DC_VIDEO_ALPHA_SCALE	(0x098)
#define SM501_DC_VIDEO_ALPHA_INIT_SCALE	(0x09C)
#define SM501_DC_VIDEO_ALPHA_CHROMA_KEY	(0x0A0)
#define SM501_DC_VIDEO_ALPHA_COLOR_LOOKUP	(0x0A4)

#define SM501_DC_PANEL_HWC_BASE		(0x0F0)
#define SM501_DC_PANEL_HWC_ADDR		(0x0F0)
#define SM501_DC_PANEL_HWC_LOC		(0x0F4)
#define SM501_DC_PANEL_HWC_COLOR_1_2	(0x0F8)
#define SM501_DC_PANEL_HWC_COLOR_3	(0x0FC)

#define SM501_HWC_EN			(1<<31)

#define SM501_OFF_HWC_ADDR		(0x00)
#define SM501_OFF_HWC_LOC		(0x04)
#define SM501_OFF_HWC_COLOR_1_2		(0x08)
#define SM501_OFF_HWC_COLOR_3		(0x0C)

#define SM501_DC_ALPHA_CONTROL		(0x100)
#define SM501_DC_ALPHA_FB_ADDR		(0x104)
#define SM501_DC_ALPHA_FB_OFFSET	(0x108)
#define SM501_DC_ALPHA_TL_LOC		(0x10C)
#define SM501_DC_ALPHA_BR_LOC		(0x110)
#define SM501_DC_ALPHA_CHROMA_KEY	(0x114)
#define SM501_DC_ALPHA_COLOR_LOOKUP	(0x118)

#define SM501_DC_CRT_CONTROL		(0x200)

#define SM501_DC_CRT_CONTROL_TVP	(1<<15)
#define SM501_DC_CRT_CONTROL_CP		(1<<14)
#define SM501_DC_CRT_CONTROL_VSP	(1<<13)
#define SM501_DC_CRT_CONTROL_HSP	(1<<12)
#define SM501_DC_CRT_CONTROL_VS		(1<<11)
#define SM501_DC_CRT_CONTROL_BLANK	(1<<10)
#define SM501_DC_CRT_CONTROL_SEL	(1<<9)
#define SM501_DC_CRT_CONTROL_TE		(1<<8)
#define SM501_DC_CRT_CONTROL_PIXEL_MASK (0xF << 4)
#define SM501_DC_CRT_CONTROL_GAMMA	(1<<3)
#define SM501_DC_CRT_CONTROL_ENABLE	(1<<2)

#define SM501_DC_CRT_CONTROL_8BPP	(0<<0)
#define SM501_DC_CRT_CONTROL_16BPP	(1<<0)
#define SM501_DC_CRT_CONTROL_32BPP	(2<<0)

#define SM501_DC_CRT_FB_ADDR		(0x204)
#define SM501_DC_CRT_FB_OFFSET		(0x208)
#define SM501_DC_CRT_H_TOT		(0x20C)
#define SM501_DC_CRT_H_SYNC		(0x210)
#define SM501_DC_CRT_V_TOT		(0x214)
#define SM501_DC_CRT_V_SYNC		(0x218)
#define SM501_DC_CRT_SIGNATURE_ANALYZER	(0x21C)
#define SM501_DC_CRT_CUR_LINE		(0x220)
#define SM501_DC_CRT_MONITOR_DETECT	(0x224)

#define SM501_DC_CRT_HWC_BASE		(0x230)
#define SM501_DC_CRT_HWC_ADDR		(0x230)
#define SM501_DC_CRT_HWC_LOC		(0x234)
#define SM501_DC_CRT_HWC_COLOR_1_2	(0x238)
#define SM501_DC_CRT_HWC_COLOR_3	(0x23C)

#define SM501_DC_PANEL_PALETTE		(0x400)

#define SM501_DC_VIDEO_PALETTE		(0x800)

#define SM501_DC_CRT_PALETTE		(0xC00)

/* Zoom Video port base */
#define SM501_ZVPORT			(0x090000)

/* AC97/I2S base */
#define SM501_AC97			(0x0A0000)

/* 8051 micro controller base */
#define SM501_UCONTROLLER		(0x0B0000)

/* 8051 micro controller SRAM base */
#define SM501_UCONTROLLER_SRAM		(0x0C0000)

/* DMA base */
#define SM501_DMA			(0x0D0000)

/* 2d engine base */
#define SM501_2D_ENGINE			(0x100000)
#define SM501_2D_SOURCE			(0x00)
#define SM501_2D_DESTINATION		(0x04)
#define SM501_2D_DIMENSION		(0x08)
#define SM501_2D_CONTROL		(0x0C)
#define SM501_2D_PITCH			(0x10)
#define SM501_2D_FOREGROUND		(0x14)
#define SM501_2D_BACKGROUND		(0x18)
#define SM501_2D_STRETCH		(0x1C)
#define SM501_2D_COLOR_COMPARE		(0x20)
#define SM501_2D_COLOR_COMPARE_MASK 	(0x24)
#define SM501_2D_MASK			(0x28)
#define SM501_2D_CLIP_TL		(0x2C)
#define SM501_2D_CLIP_BR		(0x30)
#define SM501_2D_MONO_PATTERN_LOW	(0x34)
#define SM501_2D_MONO_PATTERN_HIGH	(0x38)
#define SM501_2D_WINDOW_WIDTH		(0x3C)
#define SM501_2D_SOURCE_BASE		(0x40)
#define SM501_2D_DESTINATION_BASE	(0x44)
#define SM501_2D_ALPHA			(0x48)
#define SM501_2D_WRAP			(0x4C)
#define SM501_2D_STATUS			(0x50)

#define SM501_CSC_Y_SOURCE_BASE		(0xC8)
#define SM501_CSC_CONSTANTS		(0xCC)
#define SM501_CSC_Y_SOURCE_X		(0xD0)
#define SM501_CSC_Y_SOURCE_Y		(0xD4)
#define SM501_CSC_U_SOURCE_BASE		(0xD8)
#define SM501_CSC_V_SOURCE_BASE		(0xDC)
#define SM501_CSC_SOURCE_DIMENSION	(0xE0)
#define SM501_CSC_SOURCE_PITCH		(0xE4)
#define SM501_CSC_DESTINATION		(0xE8)
#define SM501_CSC_DESTINATION_DIMENSION	(0xEC)
#define SM501_CSC_DESTINATION_PITCH	(0xF0)
#define SM501_CSC_SCALE_FACTOR		(0xF4)
#define SM501_CSC_DESTINATION_BASE	(0xF8)
#define SM501_CSC_CONTROL		(0xFC)

/* 2d engine data port base */
#define SM501_2D_ENGINE_DATA		(0x110000)
