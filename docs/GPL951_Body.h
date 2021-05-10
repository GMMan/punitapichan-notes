//*****************************************************************************************
//Topic: The assembler header file to be included for GPL951XXUA and GPL951XXUB Series V1.0 
//Plateform: GPL95100UA
//Description: 1.This inc file defines the control register available for user to use GPL951.
//               The control regsiter setting constants is also included for users' convenience.
//             2.Naming rule:
//               C : define constant
//               P : define I/O port
//             3.Goal:
//               a) include file for GPL.asm
//               b) include file for user source code in assembly language	
//Version: V0.4  
//                     .V0.1 First edit
//					   .V0.2 Add more bit define
//					   .V0.3 Add GPL951XXUB Body	
//					   .V0.4 Add P_MICAGC_Ctrl, P_MICAGC_Time, P_MICAGC_Enable, P_MICAGC_Status and P_MICAGC_UpThres control register 
//**************************************************************************************
#define GPL95100UA	1	
#define GPL95101UA	0

#define GPL95100UB	0
#define GPL95101UB	0
//////////////////////////////////////////////////////////////////
//  Definitions for Peripheral Control Register
//////////////////////////////////////////////////////////////////
#define 	P_PPU_Ctrl_Base					0x7000
#define		P_TFT_Base						0x7050
#define		P_STN_Ctrl_Base					0x7080
#define		P_System_Ctrl_Base				0x7800
#define		P_NANDFlash_Base				0x7850
#define		P_IOPort_Ctrl_Base				0x7860
#define		P_Interrupt_Ctrl_Base			0x78A0
#define		P_TimeBase_Ctrl_Base			0x78B0
#define		P_I2C_Ctrl_Base					0x78C0
#define		P_Audio_Ctrl_Base				0x78F0
#define		P_UART_Ctrl_Base				0x7900
#define		P_SPI_Ctrl_Base					0x7920
#define		P_Analog_Ctrl_Base				0x79A0
#define		P_RTC_Ctrl_Base					0x79F0
#define		P_Timer_Ctrl_Base				0x7A00
#define		P_USBDevice_Base				0x7A40 
#define		P_DMA_Base						0x7A80
#define		P_CTS_Ctrl_Base					0x7AC0 
#define		P_MISC_Base						0x7AF0
#define		P_KeyScan_Base					0x7B20  
#define		P_SPIF_Ctrl_Base				0x7B40
#define		P_SPU_Base						0x7B80			


//////////////////////////////////////////////////
//  Picture Process Unit(PPU) Control Registers
//  Base Address Start from 0x7000
//////////////////////////////////////////////////	
#define		P_Tx3_X_Position				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x00)
#define		P_Tx3_Y_Position				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x01)
#define		P_Tx3_X_Offset					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x02)	
#define		P_Tx3_Y_Offset					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x03)
#define		P_Tx3_Attribute					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x04)
#define		P_Tx3_Control					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x05)
#define		P_Tx3_N_PTR						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x06)
#define		P_Tx3_A_PTR						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x07)
#define		P_Tx1_X_Position				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x10)
#define		P_Tx1_Y_Position				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x11)
#define		P_Tx1_Attribute					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x12)
#define		P_Tx1_Control					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x13)
#define		P_Tx1_N_PTR						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x14)
#define		P_Tx1_A_PTR						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x15)
#define		P_Tx2_X_Position				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x16)
#define		P_Tx2_Y_Position				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x17)
#define		P_Tx2_Attribute					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x18)
#define		P_Tx2_Control					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x19)
#define		P_Tx2_N_PTR						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x1A)
#define		P_Tx2_A_PTR						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x1B)
#define		P_VComp_Value					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x1C)
#define		P_VComp_Offset					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x1D)
#define		P_VComp_Step					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x1E)
#define		P_Segment_Tx1					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x20)	
#define		P_Segment_Tx2					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x21)	
#define		P_Segment_Sp					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x22)	
#define		P_Segment_Tx3					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x23)	
#define		P_Blending						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x2A)	
#define		P_Segment_Tx1H					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x2B)	
#define		P_Segment_Tx2H					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x2C)	
#define		P_Segment_SpH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x2D)	
#define		P_Segment_Tx3H					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x2E)		
#define		P_Fade_Control					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x30)
#define		P_Palette_Control				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x3A)	
#define		P_Sp_Control					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x42)
#define		P_PPU_IRQ_Control				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x62)	
#define		P_PPU_IRQ_Status				(volatile unsigned int*)(P_PPU_Ctrl_Base+0x63)	
#define		P_SPDMA_Source					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x70)
#define		P_SPDMA_Target					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x71)
#define		P_SPDMA_Number					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x72)
#define		P_HB_Ctrl						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x73)
#define		P_HB_GO							(volatile unsigned int*)(P_PPU_Ctrl_Base+0x74)
#define		P_BLD_Color						(volatile unsigned int*)(P_PPU_Ctrl_Base+0x7D)
#define		P_BLD_Color_En					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xD8)
#define		P_PPU_RAM_Bank					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x7E)
#define		P_PPU_Enable					(volatile unsigned int*)(P_PPU_Ctrl_Base+0x7F)
#define		P_Tx1_N_PTRH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xB4)
#define		P_Tx1_A_PTRH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xB5)
#define		P_Tx2_N_PTRH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xB6)
#define		P_Tx2_A_PTRH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xB7)
#define		P_Tx3_N_PTRH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xB8)
#define		P_Tx3_A_PTRH					(volatile unsigned int*)(P_PPU_Ctrl_Base+0xB9)
#define		P_PPU_Free_Height				(volatile unsigned int*)(P_PPU_Ctrl_Base+0xDB)
#define		P_PPU_Free_Width				(volatile unsigned int*)(P_PPU_Ctrl_Base+0xDC)
#define		P_RANDOM0						(volatile unsigned int*)(P_PPU_Ctrl_Base+0xE0)
#define		P_RANDOM1						(volatile unsigned int*)(P_PPU_Ctrl_Base+0xE1)
//PPU RAM
#define		P_Tx_HVoffsetN					(volatile unsigned int*)(0x7100)
#define		P_Tx3_CosineN					(volatile unsigned int*)(0x7100)
#define		P_Tx3_SineN						(volatile unsigned int*)(0x7101)
#define		P_HComp_ValueN					(volatile unsigned int*)(0x7200)
#define		P_PaletteN						(volatile unsigned int*)(0x7300)
#define		P_SpriteN_CharNum				(volatile unsigned int*)(0x7400)
#define		P_SpriteN_X						(volatile unsigned int*)(0x7401)
#define		P_SpriteN_Y						(volatile unsigned int*)(0x7402)
#define		P_SpriteN_Attribute0			(volatile unsigned int*)(0x7403)
#define		P_SpriteN_Attribute1			(volatile unsigned int*)(0x7400)
#define		P_SpriteN_X1					(volatile unsigned int*)(0x7401)
#define		P_SpriteN_X2					(volatile unsigned int*)(0x7402)
#define		P_SpriteN_X3					(volatile unsigned int*)(0x7403)


//////////////////////////////////////////////////
//  TFT Control Registers
//  Base Address Start from 0x7050
//////////////////////////////////////////////////
#define		P_TFT_Ctrl						(volatile unsigned int*)(P_TFT_Base+0x00)
#define		P_TFT_V_Width					(volatile unsigned int*)(P_TFT_Base+0x01)
#define		P_TFT_VSync_Setup				(volatile unsigned int*)(P_TFT_Base+0x02)
#define		P_TFT_V_Start					(volatile unsigned int*)(P_TFT_Base+0x03)
#define		P_TFT_V_End						(volatile unsigned int*)(P_TFT_Base+0x04)
#define		P_TFT_H_Width					(volatile unsigned int*)(P_TFT_Base+0x05)
#define		P_TFT_HSync_Setup				(volatile unsigned int*)(P_TFT_Base+0x06)
#define		P_TFT_H_Start					(volatile unsigned int*)(P_TFT_Base+0x07)
#define		P_TFT_H_End						(volatile unsigned int*)(P_TFT_Base+0x08)
#define		P_TFT_RGB_Ctrl					(volatile unsigned int*)(P_TFT_Base+0x09)
#define		P_TFT_Status					(volatile unsigned int*)(P_TFT_Base+0x0A)
#define		P_TFT_MemMode_WCmd				(volatile unsigned int*)(P_TFT_Base+0x0B)
#define		P_TFT_MemMode_RCmd				(volatile unsigned int*)(P_TFT_Base+0x0C)
#define		P_TFT_INT_EN 	       			(volatile unsigned int*)(P_TFT_Base+0x12)
#define		P_TFT_INT_CLR	  				(volatile unsigned int*)(P_TFT_Base+0x13)

#define		P_US_Ctrl						(volatile unsigned int*)(P_TFT_Base+0x14)
		#define		C_US_En						0x0001
		#define		C_US_LastPixel				0x0000
		#define		C_US_LastBlack				0x0002
#define		P_US_Hscaling					(volatile unsigned int*)(P_TFT_Base+0x15)	
#define		P_US_Vscaling					(volatile unsigned int*)(P_TFT_Base+0x16)
#define		P_US_Width						(volatile unsigned int*)(P_TFT_Base+0x17)
#define		P_US_Height						(volatile unsigned int*)(P_TFT_Base+0x18)
#define		P_US_Hoffset					(volatile unsigned int*)(P_TFT_Base+0x19)
#define		P_US_Voffset					(volatile unsigned int*)(P_TFT_Base+0x1A)

#define		P_TFT_V_Show_Start				(volatile unsigned int*)(P_TFT_Base+0x1C)
#define		P_TFT_V_Show_End				(volatile unsigned int*)(P_TFT_Base+0x1D)
#define		P_TFT_H_Show_Start				(volatile unsigned int*)(P_TFT_Base+0x1E)
#define		P_TFT_H_Show_End				(volatile unsigned int*)(P_TFT_Base+0x1F)

		
////////////////////////////////////////
//  STN Control Registers
//      Base Address Start from 0x7080
////////////////////////////////////////
#define		P_STN_Ctrl1             (volatile unsigned int*)(0x705F)
#define		P_STN_SEG				(volatile unsigned int*)(P_STN_Ctrl_Base+0x00)
#define		P_STN_COM				(volatile unsigned int*)(P_STN_Ctrl_Base+0x01)
#define		P_STN_PIC_SEG           (volatile unsigned int*)(0x705E)
#define		P_STN_PIC_COM			(volatile unsigned int*)(P_STN_Ctrl_Base+0x02)
#define		P_STN_CPWait			(volatile unsigned int*)(P_STN_Ctrl_Base+0x03)
#define		P_STN_Ctrl2				(volatile unsigned int*)(P_STN_Ctrl_Base+0x04)
#define		P_STN_GTG_SEG   		(volatile unsigned int*)(P_STN_Ctrl_Base+0x05)
#define		P_STN_GTG_COM   		(volatile unsigned int*)(P_STN_Ctrl_Base+0x06)
		

////////////////////////////////////////////////
//  System Control Registers
//  Base Address Start from 0x7800
////////////////////////////////////////////////
#define		P_BodyID						(volatile unsigned int*)(P_System_Ctrl_Base+0x00)
#define		P_PwrKey_State					(volatile unsigned int*)(P_System_Ctrl_Base+0x02)
		#define		C_PWR_High					0x0001
		#define 	C_PWR_Low					0x0000
#define		P_SYS_Ctrl						(volatile unsigned int*)(P_System_Ctrl_Base+0x03)
		#define		C_SYSPW_ON					0x8000				
		#define 	C_UEXCE_INT_Dis				0x0000
		#define 	C_UEXCE_INT_En				0x0200
#if (GPL95100UB + GPL95101UB)
		#define		C_ExtendScanTime_1			0x0000
		#define		C_ExtendScanTime_2			0x0080
		#define		C_ExtendScanTime_4			0x0180		
		#define		C_SPI_Improve1_En			0x0020	
#endif		
		#define 	C_ADC_Power_En				0x0008		
		#define 	C_ADC_LDO_En				0x0004	
		#define 	C_Halt_Wakeup_Reset			0x0000
		#define 	C_Halt_Wakeup_NextINS		0x0002
		#define 	C_CLK32K_Internal			0x0000
		#define 	C_CLK32K_External			0x0001
#define		P_CLK_Ctrl0						(volatile unsigned int*)(P_System_Ctrl_Base+0x04)
#define		P_CLK_Ctrl1						(volatile unsigned int*)(P_System_Ctrl_Base+0x05)
#define		P_Reset_Flag					(volatile unsigned int*)(P_System_Ctrl_Base+0x06)
		#define		C_PWRKEY_Flag				0x8000
		#define		C_WDT_Reset_Flag			0x0010
		#define		C_WDT_Error_Flag			0x0008
		#define		C_MPE_Error_Flag			0x0004
		#define		C_LVR_Reset_Flag			0x0001		
#define		P_Clock_Ctrl					(volatile unsigned int*)(P_System_Ctrl_Base+0x07)
		#define 	C_SYSCLK_SRC_Div1			0x0000
		#define 	C_SYSCLK_SRC_Div2			0x0001
		#define 	C_SYSCLK_SRC_Div4			0x0002
		#define 	C_SYSCLK_SRC_Div8			0x0003
		#define	 	C_SYSCLK_SRC_Div16			0x0004
		#define 	C_SYSCLK_SRC_Div32			0x0005
		#define 	C_SYSCLK_SRC_Div64			0x0006	
		#define 	C_SYSCLK_SRC_Div128			0x0007
		#define 	C_CLK96M_En					0x0008
		#define 	C_KeyChange_En				0x0200
		#define 	C_USB_CLK_Dis				0x2000
		#define 	C_CUP_Sel_CLK32K			0x4000
		#define 	C_PLL_Fast_En				0x8000	
#define		P_LVR_Ctrl						(volatile unsigned int*)(P_System_Ctrl_Base+0x08)
		#define		C_LVD_Ctrl					0x8000
		#define		C_LVR_OFF					0x0002
		#define		C_LVR_ON					0x0000
#define		P_PM_Ctrl						(volatile unsigned int*)(P_System_Ctrl_Base+0x09)
		#define		C_PWON_Hold200ms_En			0x0000
		#define		C_PWON_Hold200ms_Dis		0x4000	
		#define		C_LVR_Sel_2v1				0x3000
		#define		C_LVR_Sel_2v2				0x2000			
		#define		C_LVR_Sel_2v3				0x1000
		#define		C_LVR_Sel_2v4				0x0000
		#define		C_OVTEMP_Sel_95C			0x0000
		#define		C_OVTEMP_Sel_105C			0x0400
		#define		C_OVTEMP_Sel_115C			0x0800
		#define		C_OVTEMP_Sel_125C			0x0c00
		#define		C_ADC_LDO_3v0				0x0000
		#define		C_ADC_LDO_3v1				0x0040
		#define		C_ADC_LDO_3v2				0x0080
		#define		C_ADC_LDO_3v3				0x00c0
		#define		C_CTS_LDO_2v4				0x0000		
		#define		C_CTS_LDO_2v6				0x0010	
		#define		C_CTS_LDO_2v8				0x0020	
		#define		C_CTS_LDO_3v0				0x0030	
		#define		C_SYS3v3_LDO_3v0			0x0000
		#define		C_SYS3v3_LDO_3v1			0x0004
		#define		C_SYS3v3_LDO_3v2			0x0008
		#define		C_SYS3v3_LDO_3v3			0x000c
		#define		C_SYS1v8_LDO_1v8			0x0000
		#define		C_SYS1v8_LDO_2v0			0x0001
		#define		C_SYS1v8_LDO_1v6			0x0002
		#define		C_SYS1v8_LDO_1v4			0x0003					
#define		P_WatchDog_Ctrl					(volatile unsigned int*)(P_System_Ctrl_Base+0x0A)
		#define 	C_WatchDog_En				0x8000
		#define 	C_WatchDog_Dis				0x0000
		#define 	C_WDT_Reset_CPU_only		0x4000
		#define 	C_WDT_Reset_SYS				0x0000		
		#define 	C_WatchDog_Period_2S 		0x0000
		#define 	C_WatchDog_Period_1S 		0x0001	
		#define 	C_WatchDog_Period_0s5 		0x0002
		#define 	C_WatchDog_Period_0S25 		0x0003
		#define 	C_WatchDog_Period_0S125 	0x0004	
		#define 	C_WatchDog_Period_62S5 		0x0005			
#define		P_WatchDog_Clear				(volatile unsigned int*)(P_System_Ctrl_Base+0x0B)
		#define		C_WDT_Clear					0xA005
#define		P_WAIT							(volatile unsigned int*)(P_System_Ctrl_Base+0x0C)
		#define		C_Enter_Wait				0x5005
#define		P_HALT							(volatile unsigned int*)(P_System_Ctrl_Base+0x0D)
		#define		C_Enter_Halt				0x500A
#define		P_Power_State					(volatile unsigned int*)(P_System_Ctrl_Base+0x0F)
#define		P_BankSwitch					(volatile unsigned int*)(P_System_Ctrl_Base+0x10)
#define		P_PLL_Sel						(volatile unsigned int*)(P_System_Ctrl_Base+0x17)
		#define 	C_SPIF_CLK_Sel_Mask			0x3e00
		#define		C_PLL_Sel_Mask				0x001f			
#define		P_PLLWaitCLK					(volatile unsigned int*)(P_System_Ctrl_Base+0x18)
		#define		C_X32K_WaitCLK				0x000a
		#define		C_Int32K_WaitCLK			0x04b0
#define		P_Cache_Ctrl        			(volatile unsigned int*)(P_System_Ctrl_Base+0x19)
		#define		C_Cache_burst_En			0x0010
		#define		C_Cache_burst_Dis			0x0000
		#define		C_Cache_8words				0x0000
		#define		C_Cache_1kbytes				0x0004
		#define		C_Cache_2kbytes				0x0008
		#define		C_Cache_4kbytes				0x000c
		#define		C_Cache_Clear				0x0002
		#define		C_Cache_Clear_Flag			0x0002
		#define		C_Cache_En					0x0001
		#define		C_Cache_Dis					0x0000
#define		P_Cache_HitRate					(volatile unsigned int*)(P_System_Ctrl_Base+0x1A)
#define		P_SYS_Misc						(volatile unsigned int*)(P_System_Ctrl_Base+0x1F)
		#define		C_PWRKEY_Change_Flag		0x0080
		#define		C_Halt_LDO_1v8				0x0000
		#define		C_Halt_LDO_1v9				0x0010
		#define		C_Halt_LDO_1v4				0x0020
		#define		C_Halt_LDO_1v1				0x0030
		#define		C_OVTEMP_INT_En				0x0004
		#define		C_OVTEMP_INT_Dis			0x0000		
		#define		C_PWRKEY_ChangeINT_En		0x0002		
		#define		C_PWRKEY_ChangeINT_Dis		0x0000
#define		P_Unexpect_Clear				(volatile unsigned int*)(P_System_Ctrl_Base+0x25)
#if (GPL95100UB + GPL95101UB)
#define		P_SPI_Improve					(volatile unsigned int*)(P_System_Ctrl_Base+0x40)
		#define		C_SPI_Improve2_En			0x0020	
#endif

////////////////////////////////////////////////
//  I/O Port Control Registers
//  Base Address Start from 0x7860
////////////////////////////////////////////////
#define		P_IOA_Data						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x00)
#define		P_IOA_Buffer					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x01)
#define		P_IOA_Dir						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x02)
#define		P_IOA_Attrib					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x03)
#define		P_IOA_Drv						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x04)
		#define		C_IOA_Power_5v0				0x0004
		#define		C_IOA_Power_3v3				0x0000
		#define		C_IOA_Driving_Mask			0x0003
#define		P_IOA_Mux						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x05)
		#define		C_IOA_SPI1CS_GPIO			0x0040
		#define		C_IOA_SPI1CS_CSB			0x0000		
		#define		C_IOA_SPI1_En				0x0020
		#define		C_IOA_SPI1_Dis				0x0000
#if (GPL95100UB+GPL95101UB)		
		#define		C_IOA_CCIROutput_Dis		0x0010
		#define		C_IOA_CCIROutput_En			0x0000
#endif		
		#define		C_IOA_Keyout_En				0x0008
		#define		C_IOA_Keyout_Dis			0x0000
		#define		C_IOA_EXTI0_En				0x0004
		#define		C_IOA_EXTI0_Dis				0x0000		
		#define		C_IOA_TFT_En				0x0002
		#define		C_IOA_TFT_Dis				0x0000			
		#define		C_IOA_SMT_En				0x0001		
		#define		C_IOA_SMT_Dis				0x0000			
#define		P_IOA_Latch						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x06)
#define		P_IOA_KeyChange_En				(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x07)
#define		P_IOB_Data						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x08)
#define		P_IOB_Buffer					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x09)
#define		P_IOB_Dir						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x0A)
#define		P_IOB_Attrib					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x0B)
#define		P_IOB_Drv						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x0C)
		#define		C_IOB_Power_5v0				0x0004
		#define		C_IOB_Power_3v3				0x0000
		#define		C_IOB_Driving_Mask			0x0003
#define		P_IOB_Mux						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x0D)
		#define		C_IOB_SPI1CS_GPIO			0x0020
		#define		C_IOB_SPI1CS_CSB			0x0000
		#define		C_IOB_SPI1_En				0x0010
		#define		C_IOB_SPI1_Dis				0x0000
		#define		C_IOB_CCPB_En				0x0008
		#define		C_IOB_CCPB_Dis				0x0000		
		#define		C_IOB_TFT_En				0x0002
		#define		C_IOB_TFT_Dis				0x0000			
		#define		C_IOB_SMT_En				0x0001		
		#define		C_IOB_SMT_Dis				0x0000	
#define		P_IOB_Latch						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x0E)
#define		P_IOB_KeyChange_En				(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x0F)

#if (GPL95100UA + GPL95100UB)
#define		P_IOC_Data						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x10)
#define		P_IOC_Buffer					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x11)
#define		P_IOC_Dir						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x12)
#define		P_IOC_Attrib					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x13)
#define		P_IOC_Drv						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x14)
		#define		C_IOC_NANDWP_High			0x0040
		#define		C_IOC_NANDWP_Low			0x0000
		#define		C_IOC_Driving_Mask			0x003f					
#define		P_IOC_Mux						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x15)
#if (GPL95100UB+GPL95101UB)		
		#define		C_IOC_CCIROutput_Dis		0x2000
		#define		C_IOC_CCIROutput_En			0x0000
#endif	
		#define		C_IOC_I2C_En				0x1000
		#define		C_IOC_I2C_Dis				0x0000
		#define		C_IOC_Keyscan_En			0x0800
		#define		C_IOC_Keyscan_Dis			0x0000
		#define		C_IOC_NFCS_GPIO				0x0400
		#define		C_IOC_NFCS_CSB				0x0000
		#define		C_IOC_NFWP_GPIO				0x0200
		#define		C_IOC_NFWP_WPB				0x0000
		#define		C_IOC_TFT_Control_En		0x0100		
		#define		C_IOC_TFT_Control_Dis		0x0000
		#define		C_IOC_SPI0CS_GPIO			0x0080
		#define		C_IOC_SPI0CS_CSB			0x0000
		#define		C_IOC_NAND_En				0x0040
		#define		C_IOC_NAND_Dis				0x0000	
		#define		C_IOC_EXTI1_En				0x0020
		#define		C_IOC_EXTI1_Dis				0x0000
		#define		C_IOC_SPI0_En				0x0008
		#define		C_IOC_SPI0_Dis				0x0000
		#define		C_IOC_UART_En				0x0004
		#define		C_IOC_UART_Dis				0x0000	
		#define		C_IOC_TFT_En				0x0002
		#define		C_IOC_TFT_Dis				0x0000
		#define		C_IOC_SMT_En				0x0001		
		#define		C_IOC_SMT_Dis				0x0000
#define		P_IOC_Latch						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x16)
#define		P_IOC_KeyChange_En				(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x17)
#endif

#define		P_IOD_Data						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x18)
#define		P_IOD_Buffer					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x19)
#define		P_IOD_Dir						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x1A)
#define		P_IOD_Attrib					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x1B)
#define		P_IOD_Drv						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x1C)
#define		P_IOD_Mux						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x1D)				
#define		P_IOE_Data						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x20)
#define		P_IOE_Buffer					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x21)
#define		P_IOE_Dir						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x22)
#define		P_IOE_Attrib					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x23)
#define		P_IOE_Drv						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x24)
		#define		C_IOE_Driving_Mask			0x0003	
#define		P_IOE_Mux						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x25)
		#define		C_IOE_UART_En				0x0008
		#define		C_IOE_UART_Dis				0x0000	
		#define		C_IOE_EXTI0_En				0x0004
		#define		C_IOE_EXTI0_Dis				0x0000
		#define		C_IOE_SMT_En				0x0001		
		#define		C_IOE_SMT_Dis				0x0000
#define		P_IOE_Latch						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x26)
#define		P_IOE_KeyChange_En				(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x27)
#define		P_IOF_Data						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x28)
#define		P_IOF_Buffer					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x29)
#define		P_IOF_Dir						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x2A)
#define		P_IOF_Attrib					(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x2B)
#define		P_IOF_Drv						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x2C)
		#define		C_IOF_Driving_Mask			0x000f	
#define		P_IOF_Mux						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x2D)
#if (GPL95100UB+GPL95101UB)		
		#define		C_IOF_CCIROutput_Dis		0x1000
		#define		C_IOF_CCIROutput_En			0x0000
#endif
		#define		C_IOF_SPI0_En				0x0800
		#define		C_IOF_SPI0_Dis				0x0000
		#define		C_IOF_Keyout_En				0x0400
		#define		C_IOF_Keyout_Dis			0x0000	
		#define		C_IOF_Keyscan_En			0x0200
		#define		C_IOF_Keyscan_Dis			0x0000
		#define		C_IOF_TFT_Control_En		0x0100		
		#define		C_IOF_TFT_Control_Dis		0x0000
		#define		C_IOF_SPICS_GPIO			0x0080
		#define		C_IOF_SPICS_CSB				0x0000
		#define		C_IOF_I2C_En				0x0040
		#define		C_IOF_I2C_Dis				0x0000
		#define		C_IOF_CTS_En				0x0020
		#define		C_IOF_CTS_Dis				0x0000
		#define		C_IOF_EXTI1_En				0x0010
		#define		C_IOF_EXTI1_Dis				0x0000				
		#define		C_IOF_UART_En				0x0008
		#define		C_IOF_UART_Dis				0x0000
		#define		C_IOF_SPI1_En				0x0004
		#define		C_IOF_SPI1_Dis				0x0000
		#define		C_IOF_TFT_En				0x0002
		#define		C_IOF_TFT_Dis				0x0000
		#define		C_IOF_SMT_En				0x0001		
		#define		C_IOF_SMT_Dis				0x0000		
#define		P_IOF_Latch						(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x2E)
#define		P_IOF_KeyChange_En				(volatile unsigned int*)(P_IOPort_Ctrl_Base+0x2F)


////////////////////////////////////////////////
//  NAND Flash Control Registers
//  Base Address Start from 0x7850
////////////////////////////////////////////////
#define		P_NF_Ctrl						(volatile unsigned int*)(P_NANDFlash_Base+0x00)
#define		P_NF_CMD						(volatile unsigned int*)(P_NANDFlash_Base+0x01)	
#define		P_NF_AddrL						(volatile unsigned int*)(P_NANDFlash_Base+0x02)
#define		P_NF_AddrH						(volatile unsigned int*)(P_NANDFlash_Base+0x03)
#define		P_NF_Data						(volatile unsigned int*)(P_NANDFlash_Base+0x04)
#define		P_NF_INT_Ctrl					(volatile unsigned int*)(P_NANDFlash_Base+0x05)
#define		P_ECC_Ctrl						(volatile unsigned int*)(P_NANDFlash_Base+0x07)
#define		P_ECC_LPRL_LB					(volatile unsigned int*)(P_NANDFlash_Base+0x08)
#define		P_ECC_LPRH_LB					(volatile unsigned int*)(P_NANDFlash_Base+0x09)
#define		P_ECC_CPR_LB					(volatile unsigned int*)(P_NANDFlash_Base+0x0A)
#define		P_ECC_LPR_CKL_LB				(volatile unsigned int*)(P_NANDFlash_Base+0x0B)
#define		P_ECC_LPR_CKH_LB				(volatile unsigned int*)(P_NANDFlash_Base+0x0C)
#define		P_ECC_CPCKR_LB					(volatile unsigned int*)(P_NANDFlash_Base+0x0D)
#define		P_ECC_ERR0_LB					(volatile unsigned int*)(P_NANDFlash_Base+0x0E)
#define		P_ECC_ERR1_LB					(volatile unsigned int*)(P_NANDFlash_Base+0x0F)

#define		P_CheckSUM0_LB					(volatile unsigned int*)(0x7830)
#define		P_CheckSUM1_LB					(volatile unsigned int*)(0x7831)
#define		P_CheckSUM0_HB					(volatile unsigned int*)(0x7832)
#define		P_CheckSUM1_HB					(volatile unsigned int*)(0x7833)
#define		P_ECC_LPRL_HB					(volatile unsigned int*)(0x7848)
#define		P_ECC_LPRH_HB					(volatile unsigned int*)(0x7849)
#define		P_ECC_CPR_HB					(volatile unsigned int*)(0x784A)
#define		P_ECC_LPR_CKL_HB				(volatile unsigned int*)(0x784B)
#define		P_ECC_LPR_CKH_HB				(volatile unsigned int*)(0x784C)
#define		P_ECC_CPCKR_HB					(volatile unsigned int*)(0x784D)
#define		P_ECC_ERR0_HB					(volatile unsigned int*)(0x784E)
#define		P_ECC_ERR1_HB					(volatile unsigned int*)(0x784F)

#define		P_BCH_Control					(volatile unsigned int*)(P_NANDFlash_Base+0x06)
#define		P_BCH_Error	    				(volatile unsigned int*)(P_NANDFlash_Base+0x08)
#define		P_BCH_Parity0					(volatile unsigned int*)(P_NANDFlash_Base+0x09)
#define		P_BCH_Parity1					(volatile unsigned int*)(P_NANDFlash_Base+0x0A)
#define		P_BCH_Parity2      				(volatile unsigned int*)(P_NANDFlash_Base+0x0B)
#define		P_BCH_Parity3					(volatile unsigned int*)(P_NANDFlash_Base+0x0C)
#define		P_BCH_Parity4					(volatile unsigned int*)(P_NANDFlash_Base+0x0D)
#define		P_BCH_Parity5					(volatile unsigned int*)(P_NANDFlash_Base+0x0E)
#define		P_BCH_Parity6					(volatile unsigned int*)(P_NANDFlash_Base+0x0F)


////////////////////////////////////////////////
//  Interrupt Control Registers
//  Base Address Start from 0x78A0
////////////////////////////////////////////////
#define		P_INT_Status1					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x00)
		#define		C_INT_EXT0_IF   			0x0001
    	#define 	C_INT_EXT1_IF           	0x0002
		#define		C_INT_DMA_IF 				0x0004
		#define		C_INT_USB_IF 				0x0008
		#define 	C_INT_AUDAFIFOEmpty_IF   	0x0010
		#define 	C_INT_AUDBFIFOEmpty_IF  	0x0020
		#define		C_INT_ADCAutoSample_IF 		0x0080
		#define 	C_INT_FramePulse_IF 	 	0x0200
		#define		C_INT_SPI0_IF 				0x0400
		#define 	C_INT_UART_IF          		0x0800
		#define 	C_INT_OverTemperature_IF 	0x1000
    	#define		C_INT_PowerOnKey_IF 		0x2000	
    	#define 	C_INT_ADCReady_IF       	0x4000
    	#define 	C_INT_KeyC_IF            	0x8000
#define		P_INT_Status2					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x01)
    	#define 	C_INT_MICADCAutoSample_IF  	0x0001
    	#define 	C_INT_RTC_IF        		0x0002
    	#define 	C_INT_SPI1_IF  		     	0x0004
    	#define 	C_INT_NF_IF             	0x0010
		#define 	C_INT_I2C_IF  	       		0x0020
    	#define 	C_INT_CTS_IF 	        	0x0080
    	#define 	C_INT_TimeBaseA_IF     		0x0100
    	#define 	C_INT_TimeBaseB_IF      	0x0200
    	#define 	C_INT_TimeBaseC_IF      	0x0400
    	#define		C_INT_KeyScan_IF 			0x0800
#define		P_INT_Status3					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x02)
    	#define 	C_INT_SPU_BeatIrq_IF       	0x0004       
    	#define 	C_INT_UnExpIrq_IF      		0x0080
    	#define 	C_INT_TMA_IF     			0x0100
    	#define 	C_INT_TMB_IF     			0x0200
    	#define 	C_INT_TMC_IF     			0x0400
    	#define 	C_INT_TMD_IF     			0x0800
    	#define 	C_INT_TME_IF     			0x1000
    	#define 	C_INT_TMF_IF     			0x2000   
    	#define 	C_INT_TMG_IF     			0x4000 
    	#define 	C_INT_TMH_IF     			0x8000  
#define		P_INT_Priority1					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x03)
		#define 	C_KeyChange_IRQ5			0x0000
		#define 	C_KeyChange_FIQ				0x8000
		#define 	C_ADC_IRQ1					0x0000
		#define 	C_ADC_FIQ					0x4000				
		#define 	C_UART_IRQ3					0x0000
		#define		C_UART_FIQ					0x0800		
		#define 	C_SPI0_IRQ3					0x0000
		#define 	C_SPI0_FIQ					0x0400
		#define 	C_LCDFP_IRQ5				0x0000
		#define 	C_LCDFP_FIQ					0x0200						
		#define 	C_LineADCFifoFull_IRQ1		0x0000
		#define 	C_LineADCFifoFull_FIQ		0x0080	
		#define 	C_CHBFifoEmpty_IRQ0			0x0000
		#define 	C_CHBFifoEmpty_FIQ			0x0020
		#define 	C_CHAFifoEmpty_IRQ0			0x0000
		#define 	C_CHAFifoEmpty_FIQ			0x0010	
		#define 	C_USB_IRQ3					0x0000
		#define 	C_USB_FIQ					0x0008
		#define 	C_DMADone_IRQ3				0x0000
		#define 	C_DMADone_FIQ				0x0004
		#define 	C_EXTI1_IRQ2				0x0000
		#define 	C_EXTI1_FIQ					0x0002																
		#define 	C_EXTI0_IRQ2				0x0000
		#define 	C_EXTI0_FIQ					0x0001	
#define		P_INT_Priority2					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x04)
		#define 	C_TimeBaseC_IRQ6			0x0000
		#define 	C_TimeBaseB_IRQ6			0x0000	
		#define 	C_TimeBaseA_IRQ6			0x0000
		#define 	C_CTS_IRQ6					0x0000
		#define 	C_CTS_FIQ					0x0080			
		#define 	C_I2C_IRQ5					0x0000
		#define 	C_I2C_FIQ					0x0020
		#define 	C_NANDIF_IRQ5				0x0000
		#define 	C_NANDIF_FIQ				0x0010
		#define 	C_SPI1_IRQ3					0x0000
		#define 	C_SPI1_FIQ					0x0004							
		#define 	C_RTC_IRQ7					0x0000
		#define 	C_RTC_FIQ					0x0002	
		#define 	C_MicFifoFull_IRQ1			0x0000
		#define 	C_MicFifoFull_FIQ			0x0001	
#define		P_INT_Priority3					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x05)
 		#define 	C_TMH_IRQ4					0x0000
		#define 	C_TMH_FIQ					0x8000	 
		#define 	C_TMG_IRQ4					0x0000
		#define 	C_TMG_FIQ					0x4000	 
		#define 	C_TMF_IRQ4					0x0000
		#define 	C_TMF_FIQ					0x2000	 
		#define 	C_TME_IRQ4					0x0000
		#define 	C_TME_FIQ					0x1000	 
		#define 	C_TMD_IRQ4					0x0000
		#define 	C_TMD_FIQ					0x0800	 
		#define 	C_TMC_IRQ4					0x0000
		#define 	C_TMC_FIQ					0x0400	 	
		#define 	C_TMB_IRQ4					0x0000
		#define 	C_TMB_FIQ					0x0200	 		
		#define 	C_TMA_IRQ4					0x0000
		#define 	C_TMA_FIQ					0x0100	 
		#define 	C_Unexpect_IRQ4				0x0000
		#define 	C_Unexpect_FIQ				0x0080
		#define 	C_BEAT_IRQ4					0x0000
		#define 	C_BEAT_FIQ					0x0004        
#define		P_MINT_Ctrl						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x06)
		#define 	C_Exti1FallingEdge			0x0000
		#define 	C_Exti1RisingEdge			0x0020
		#define 	C_Exti0FallingEdge			0x0000
		#define 	C_Exti0RisingEdge			0x0010	
		#define 	C_Exti1En					0x0002
		#define 	C_Exti0En					0x0001	
#define		P_IOAB_KCIEN					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x07)
#define		P_IOC_KCIEN						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x08)
#define		P_IOE_KCIEN						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x09)
#define		P_IOF_KCIEN						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x0A)
#define		P_IOAB_KCIFC					(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x0B)
#define		P_IOC_KCIFC						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x0C)
#define		P_IOE_KCIFC						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x0D)
#define		P_IOF_KCIFC						(volatile unsigned int*)(P_Interrupt_Ctrl_Base+0x0E)


////////////////////////////////////////////////
//  TimeBase Control Registers
//  Base Address Start from 0x78B0
////////////////////////////////////////////////
#define		P_TimeBaseA_Ctrl				(volatile unsigned int*)(P_TimeBase_Ctrl_Base+0x00)
		#define 	C_TimeBaseAFlag				0x8000
		#define 	C_TimeBaseAIntEn			0x4000
		#define 	C_TimeBaseAEn				0x2000
		#define 	C_TimeBaseADis				0x0000		
		#define 	C_TimeBaseA_4Hz				0x0003
		#define 	C_TimeBaseA_2Hz				0x0002
		#define 	C_TimeBaseA_1Hz				0x0001	
#define		P_TimeBaseB_Ctrl				(volatile unsigned int*)(P_TimeBase_Ctrl_Base+0x01)
		#define 	C_TimeBaseBFlag				0x8000
		#define 	C_TimeBaseBIntEn			0x4000
		#define 	C_TimeBaseBEn				0x2000
		#define 	C_TimeBaseBDis				0x0000			
		#define 	C_TimeBaseB_64Hz			0x0003
		#define 	C_TimeBaseB_32Hz			0x0002
		#define 	C_TimeBaseB_16Hz			0x0001	
		#define 	C_TimeBaseB_8Hz				0x0000	
#define		P_TimeBaseC_Ctrl				(volatile unsigned int*)(P_TimeBase_Ctrl_Base+0x02)
		#define 	C_TimeBaseCFlag				0x8000
		#define 	C_TimeBaseCIntEn			0x4000
		#define 	C_TimeBaseCEn				0x2000
		#define 	C_TimeBaseCDis				0x0000			
		#define 	C_TimeBaseC_1024Hz			0x0003
		#define 	C_TimeBaseC_512Hz			0x0002
		#define 	C_TimeBaseC_256Hz			0x0001
		#define 	C_TimeBaseC_128Hz			0x0000		
#define		P_TimeBase_Reset				(volatile unsigned int*)(P_TimeBase_Ctrl_Base+0x08)


////////////////////////////////////////////////
//  I2C Control Registers
//  Base Address Start from 0x78C0
////////////////////////////////////////////////
#define		P_I2C_Ctrl						(volatile unsigned int*)(P_I2C_Ctrl_Base+0x00)
		#define 	C_I2C_ACK_Disable			0x0000
		#define 	C_I2C_ACK_Enable			0x0080
		#define		C_I2C_INT_Disable			0x0000
		#define		C_I2C_INT_Enable			0x0020
		#define		C_I2C_INT_Flag				0x0010
		#define 	C_I2C_CLK_LSB				0x0007
#define		P_I2C_Status					(volatile unsigned int*)(P_I2C_Ctrl_Base+0x01)
		#define 	C_I2C_Mode_SlaveRX			0x0000
		#define 	C_I2C_Mode_SlaveTX			0x0040
		#define 	C_I2C_Mode_MasterRX			0x0080
		#define 	C_I2C_Mode_MasterTX			0x00C0
		#define 	C_I2C_Stop					0x0000
		#define 	C_I2C_Start					0x0020
		#define 	C_I2C_Busy					0x0020
		#define 	C_I2C_DataOut_Disable		0x0000
		#define 	C_I2C_DataOut_Enable		0x0010
		#define 	C_I2C_Bus_OK				0x0000
		#define 	C_I2C_Bus_Fail				0x0008
		#define 	C_I2C_Addr_Match			0x0004
		#define 	C_I2C_Addr_Zero				0x0002
		#define 	C_I2C_ACK					0x0000
		#define 	C_I2C_NACK					0x0001
#define		P_I2C_Address					(volatile unsigned int*)(P_I2C_Ctrl_Base+0x02)
#define		P_I2C_Data						(volatile unsigned int*)(P_I2C_Ctrl_Base+0x03)
#define		P_I2C_Debounce					(volatile unsigned int*)(P_I2C_Ctrl_Base+0x04)
#define		P_I2C_Clk						(volatile unsigned int*)(P_I2C_Ctrl_Base+0x05)
#define		P_I2C_MISC						(volatile unsigned int*)(P_I2C_Ctrl_Base+0x06)
		#define		C_I2C_En					0x0001
		#define		C_I2C_Dis					0x0000


/////////////////////////////////////////////////
//  Timer Control Registers
//  Base Address Start from 0x7A00
/////////////////////////////////////////////////
#define		P_TimerA_Ctrl					(volatile unsigned int*)(P_Timer_Ctrl_Base+0x00)
		#define	 C_TimerFlag					0x8000
		#define	 C_TimerIntEn					0x4000	
		#define	 C_TimerEn						0x2000
		#define	 C_TimerEXTI0_16Rising			0x0C00
		#define	 C_TimerEXTI0_4Rising			0x0800				
		#define	 C_TimerEXTI0_Rising			0x0400		
		#define	 C_TimerEXTI0_Falling			0x0000
		#define	 C_TimerEXTI1_16Rising			0x0300
		#define	 C_TimerEXTI1_4Rising			0x0200				
		#define	 C_TimerEXTI1_Rising			0x0100		
		#define	 C_TimerEXTI1_Falling			0x0000		
		#define	 C_TimerSrcB_Mask				0x0070
			#define	 C_TimerSrcB_2048Hz				0x0000		
			#define	 C_TimerSrcB_1024Hz				0x0010			
			#define	 C_TimerSrcB_256Hz				0x0020	
			#define	 C_TimerSrcB_TB1				0x0030			
			#define	 C_TimerSrcB_TB0				0x0040			
			#define	 C_TimerSrcB_Low				0x0050	
			#define	 C_TimerSrcB_High				0x0060			
			#define	 C_TimerSrcB_IOD13				0x0070				
		#define	 C_TimerSrcA_Mask				0x000F
			#define	 C_TimerSrcA_SYSdiv2			0x0000
			#define	 C_TimerSrcA_SYSdiv256			0x0001
			#define	 C_TimerSrcA_32768Hz			0x0002
			#define	 C_TimerSrcA_8192Hz				0x0003
			#define	 C_TimerSrcA_4096Hz				0x0004
			#define	 C_TimerSrcA_High				0x0005
			#define	 C_TimerSrcA_TMNext				0x0006
			#define	 C_TimerSrcA_IOD12				0x0007
			#define	 C_TimerSrcA_Low				0x0008	
#define		P_TimerA_CCP_Ctrl				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x01)
		#define 	C_Capture_En				0x4000
		#define		C_Capture_Falling			0x0000
		#define		C_Capture_Rising			0x0100
		#define 	C_Comparison_En				0x8000	
		#define		C_Comparison_HiPulse		0x0000			
		#define		C_Comparison_LoPulse		0x0010
		#define		C_Comparison_Unaffect		0x0020
		#define 	C_PWM_En					0xC000
		#define 	C_PWM_HiPulse				0x0000
		#define 	C_PWM_LoPulse				0x0001
		#define 	C_BAM_En					0xC000	
		#define 	C_BAM_LoPulse				0x0002
		#define 	C_BAM_HiPulse				0x0003	
#define		P_TimerA_Preload				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x02)
#define		P_TimerA_BAM_Cycle				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x02)
#define		P_TimerA_CCP_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x03)
#define		P_TimerA_PWM_Duty				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x03)
#define		P_TimerA_BAM_Data				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x03)
#define		P_TimerA_UpCount				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x04)

#define		P_TimerB_Ctrl					(volatile unsigned int*)(P_Timer_Ctrl_Base+0x08)
#define		P_TimerB_CCP_Ctrl				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x09)
#define		P_TimerB_Preload				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x0A)
#define		P_TimerB_BAM_Cycle				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x0A)
#define		P_TimerB_CCP_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x0B)
#define		P_TimerB_PWM_Duty				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x0B)
#define		P_TimerB_BAM_Data				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x0B)
#define		P_TimerB_UpCount				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x0C)

#define		P_TimerC_Ctrl					(volatile unsigned int*)(P_Timer_Ctrl_Base+0x10)
#define		P_TimerC_CCP_Ctrl				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x11)
#define		P_TimerC_Preload				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x12)
#define		P_TimerC_BAM_Cycle				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x12)
#define		P_TimerC_CCP_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x13)
#define		P_TimerC_PWM_Duty				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x13)
#define		P_TimerC_BAM_Data				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x13)
#define		P_TimerC_UpCount				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x14)

#define		P_TimerD_Ctrl					(volatile unsigned int*)(P_Timer_Ctrl_Base+0x18)
#define		P_TimerD_CCP_Ctrl				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x19)
#define		P_TimerD_Preload				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x1A)
#define		P_TimerD_BAM_Cycle				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x1A)
#define		P_TimerD_CCP_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x1B)
#define		P_TimerD_PWM_Duty				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x1B)
#define		P_TimerD_BAM_Data				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x1B)
#define		P_TimerD_UpCount				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x1C)

#define		P_TimerE_Ctrl					(volatile unsigned int*)(P_Timer_Ctrl_Base+0x20)
#define		P_TimerE_CCP_Ctrl				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x22)
#define		P_TimerE_Preload				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x24)
#define		P_TimerE_BAM_Cycle				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x24)
#define		P_TimerE_UpCount				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x2A)

#define		P_TimerF_Ctrl					(volatile unsigned int*)(P_Timer_Ctrl_Base+0x21)
#define		P_TimerF_CCP_Ctrl				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x23)
#define		P_TimerF_Preload				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x25)
#define		P_TimerF_BAM_Cycle				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x25)
#define		P_TimerF_UpCount				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x2B)

#define		P_TimerEF_CCP4_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x26)
#define		P_TimerE_BAM_Data				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x26)
#define		P_TimerEF_CCP5_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x27)
#define		P_TimerF_BAM_Data				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x27)
#define		P_TimerEF_CCP6_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x28)
#define		P_TimerEF_CCP7_Reg				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x29)
#define		P_TimerEF_CCP_Sel				(volatile unsigned int*)(P_Timer_Ctrl_Base+0x2C)

#define		P_TimerG_Ctrl					(volatile unsigned int*)(0x78E0)
#define		P_TimerG_Preload				(volatile unsigned int*)(0x78E2)
#define		P_TimerG_UpCount				(volatile unsigned int*)(0x78E4)
#define		P_TimerH_Ctrl					(volatile unsigned int*)(0x78E8)
#define		P_TimerH_Preload				(volatile unsigned int*)(0x78EA)
#define		P_TimerH_UpCount				(volatile unsigned int*)(0x78EC)


////////////////////////////////////////////////
//  Audio Output Control Registers
//  Base Address Start from 0x78F0
////////////////////////////////////////////////
#define		P_CHA_Ctrl						(volatile unsigned int*)(P_Audio_Ctrl_Base+0x00)
		#define 	C_AUDIO_CascadeEn			0x0004		
		#define 	C_AUDIO_DAC_1CH				0x0080
		#define 	C_AUDIO_DAC_2CH				0x0000	
		#define 	C_AUDIO_AMPNegative_En		0x0200
		#define 	C_AUDIO_AMPNegative_Dis		0x0000												
		#define 	C_AUDIO_AMPPositive_En		0x0400
		#define 	C_AUDIO_AMPPositive_Dis		0x0000
		#define 	C_AUDIO_Sign_En				0x0800
		#define 	C_AUDIO_DACB_En				0x1000								
		#define 	C_AUDIO_CHA_En				0x2000			
		#define 	C_AUDIO_CHA_FIFOEmpty_En	0x4000		
		#define 	C_AUDIO_CHA_FIFOEmpty_Flag	0x8000	
#define		P_CHA_Data						(volatile unsigned int*)(P_Audio_Ctrl_Base+0x01)
#define		P_CHA_FIFO						(volatile unsigned int*)(P_Audio_Ctrl_Base+0x02)
		#define 	C_AUDIO_FIFO_Reset			0x0100
		#define 	C_AUDIO_FIFO_UnderRun		0x4000		
		#define 	C_AUDIO_FIFO_Full			0x8000
#define		P_CHB_Ctrl						(volatile unsigned int*)(P_Audio_Ctrl_Base+0x08)
		#define 	C_AUDIO_Stereo				0x0000
		#define 	C_AUDIO_Mono				0x0400
		#define 	C_AUDIO_UseCHAConfig		0x0800
		#define 	C_AUDIO_UseCHAFreq			0x1000	
		#define 	C_AUDIO_CHB_En				0x2000	
		#define 	C_AUDIO_CHB_FIFOEmpty_En	0x4000		
		#define 	C_AUDIO_CHB_FIFOEmpty_Flag	0x8000		
#define		P_CHB_Data						(volatile unsigned int*)(P_Audio_Ctrl_Base+0x09)
#define		P_CHB_FIFO						(volatile unsigned int*)(P_Audio_Ctrl_Base+0x0A)


/////////////////////////////////////////////////
//  UART Control Registers
//  Base Address Start from 0x7900
/////////////////////////////////////////////////
#define		P_UART_Data  					(volatile unsigned int*)(P_UART_Ctrl_Base+0x00)
#define		P_UART_RXStatus					(volatile unsigned int*)(P_UART_Ctrl_Base+0x01)
#define		P_UART_Ctrl          			(volatile unsigned int*)(P_UART_Ctrl_Base+0x02)
		#define 	C_UART_RxIntEn				0x8000
		#define 	C_UART_TxIntEn				0x4000	
		#define 	C_UART_RxTimeoutIntEn		0x2000					
		#define 	C_UART_En					0x1000
		#define 	C_UART_ModenIntEn			0x0800		
		#define 	C_UART_Data_5bit			0x0000
		#define 	C_UART_Data_6bit			0x0020											
		#define 	C_UART_Data_7bit			0x0040
		#define 	C_UART_Data_8bit			0x0060
		#define 	C_UART_FifoEn				0x0010	
		#define 	C_UART_Stop_1bit			0x0000	
		#define 	C_UART_Stop_2bit			0x0008
		#define 	C_UART_ParityODD			0x0000
		#define 	C_UART_ParityEVEN			0x0004
		#define 	C_UART_ParityEn				0x0002
		#define 	C_UART_NoParity				0x0000																											
		#define 	C_UART_SendBreak			0x0001
		#define 	C_UART_Normal				0x0000		
#define		P_UART_BaudRate    				(volatile unsigned int*)(P_UART_Ctrl_Base+0x03)
#define		P_UART_Status       			(volatile unsigned int*)(P_UART_Ctrl_Base+0x04)
		#define 	C_UART_RxIntFlag			0x8000
		#define 	C_UART_TxIntFlag			0x4000	
		#define 	C_UART_RxTimeourIntFlag		0x2000	
		#define 	C_UART_TxFifoEmpty			0x0080	
		#define 	C_UART_RxFifoFull			0x0040	
		#define 	C_UART_TxFifoFull			0x0020									
		#define 	C_UART_RxFifoEmpty			0x0010	
		#define 	C_UART_BusyFlag				0x0008	
#define		P_UART_FIFO						(volatile unsigned int*)(P_UART_Ctrl_Base+0x05)
#define		P_UART_TXDelay					(volatile unsigned int*)(P_UART_Ctrl_Base+0x06)


/////////////////////////////////////////////////
//  RTC Control Regsiters
//  Base Address Start from 0x79F0
/////////////////////////////////////////////////
#define		P_RTC_Ctrl						(volatile unsigned int*)(P_RTC_Ctrl_Base+0x00)
		#define		C_RTC_SerialIF_En			0x0001
#define		P_RTC_Addr						(volatile unsigned int*)(P_RTC_Ctrl_Base+0x01)
#define		P_RTC_WriteData					(volatile unsigned int*)(P_RTC_Ctrl_Base+0x02)
#define		P_RTC_Request					(volatile unsigned int*)(P_RTC_Ctrl_Base+0x03)
		#define		C_RTC_Read_Request			0x0002
		#define		C_RTC_Write_Request			0x0001		
#define		P_RTC_Ready  		    		(volatile unsigned int*)(P_RTC_Ctrl_Base+0x04)
		#define		C_RTC_Ready_Flag			0x0001
#define		P_RTC_ReadData					(volatile unsigned int*)(P_RTC_Ctrl_Base+0x05)
#define		P_RTC_ClkDiv					(volatile unsigned int*)(P_RTC_Ctrl_Base+0x0B)


/////////////////////////////////////////////////
//  SPI1 Control Registers
//  Base Address Start from 0x7920
/////////////////////////////////////////////////
#define		P_SPI1_Ctrl						(volatile unsigned int*)(P_SPI_Ctrl_Base+0x00)
		#define 	C_SPI1_Disable				0x0000
		#define 	C_SPI1_Enable				0x8000
		#define		C_SPI1_LBM_Normal			0x0000
		#define		C_SPI1_LBM_Enable			0x2000	
		#define 	C_SPI1_Reset				0x0800
		#define		C_SPI1_Mode					0x0100
		#define 	C_SPI1_MasterMode			0x0000
		#define 	C_SPI1_SlaveMode  			0x0100
		#define 	C_SPI1_Clock_Phase			0x0020
		#define 	C_SPI1_Clock_Phase_Normal	0x0000
		#define 	C_SPI1_Clock_Phase_Shift	0x0020
		#define		C_SPI1_Clock_Pol			0x0010
		#define 	C_SPI1_Clock_Pol_Normal		0x0000
		#define 	C_SPI1_Clock_Pol_Inverse	0x0010
		#define 	C_SPI1_SCK_SEL				0x0007
		#define 	C_SPI1_SCK_SYSCLK_Div_2		0x0000
		#define 	C_SPI1_SCK_SYSCLK_Div_4		0x0001
		#define 	C_SPI1_SCK_SYSCLK_Div_8		0x0002
		#define 	C_SPI1_SCK_SYSCLK_Div_16	0x0003
		#define 	C_SPI1_SCK_SYSCLK_Div_32	0x0004
		#define 	C_SPI1_SCK_SYSCLK_Div_64	0x0005
		#define 	C_SPI1_SCK_SYSCLK_Div_128	0x0006		
#define		P_SPI1_TXStatus					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x01)
		#define 	C_SPI1_TX_INT_Flag			0x8000
		#define 	C_SPI1_TX_INT_DIS			0x0000
		#define 	C_SPI1_TX_INT_EN			0x4000
		#define 	C_SPI1_TX_FIFO_Level		0x0070
		#define 	C_SPI1_TX_FIFO_Level_0		0x0000
		#define 	C_SPI1_TX_FIFO_Level_1		0x0010
		#define 	C_SPI1_TX_FIFO_Level_2		0x0020
		#define 	C_SPI1_TX_FIFO_Level_3		0x0030
		#define 	C_SPI1_TX_FIFO_Level_4		0x0040
		#define 	C_SPI1_TX_FIFO_Level_5		0x0050
		#define 	C_SPI1_TX_FIFO_Level_6		0x0060
		#define 	C_SPI1_TX_FIFO_Level_7		0x0070
		#define		C_SPI1_TX_Flag				0x0007
#define		P_SPI1_TXData					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x02)
#define		P_SPI1_RXStatus					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x03)
		#define 	C_SPI1_RX_INT_Flag			0x8000
		#define 	C_SPI1_RX_INT_DIS			0x0000
		#define 	C_SPI1_RX_INT_EN			0x4000
		#define 	C_SPI1_RX_BUF_Full			0x0200
		#define 	C_SPI1_RX_BUF_OVER_ERROR	0x0100
		#define 	C_SPI1_RX_FIFO_Level		0x0070
		#define 	C_SPI1_RX_FIFO_Level_1		0x0000
		#define 	C_SPI1_RX_FIFO_Level_2		0x0010
		#define 	C_SPI1_RX_FIFO_Level_3		0x0020
		#define 	C_SPI1_RX_FIFO_Level_4		0x0030
		#define 	C_SPI1_RX_FIFO_Level_5		0x0040
		#define 	C_SPI1_RX_FIFO_Level_6		0x0050
		#define 	C_SPI1_RX_FIFO_Level_7		0x0060
		#define 	C_SPI1_RX_FIFO_Level_8		0x0070
		#define		C_SPI1_RX_Flag				0x0007
#define		P_SPI1_RXData					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x04)
#define		P_SPI1_Misc						(volatile unsigned int*)(P_SPI_Ctrl_Base+0x05)
		#define		C_SPI1_FIFO_Full_Mode		0x0200
		#define		C_SPI1_FIFO_Full_Skipped	0x0000
		#define		C_SPI1_FIFO_Full_Overwrite	0x0200
		#define		C_SPI1_FIFO_Normal_Mode		0x0000
		#define		C_SPI1_FIFO_Smart_Mode		0x0100
		#define		C_SPI1_Busy_Flag			0x0010
		#define		C_SPI1_RX_Full_Flag			0x0008
		#define		C_SPI1_RX_NonEmpty_Flag		0x0004
		#define		C_SPI1_TX_NonFull_Flag		0x0002
		#define		C_SPI1_TX_Empty_Flag		0x0001


/////////////////////////////////////////////////
//  SPI0 Control Registers
//  Base Address Start from 0x7920
/////////////////////////////////////////////////
#define		P_SPI0_Ctrl						(volatile unsigned int*)(P_SPI_Ctrl_Base+0x20)
		#define 	C_SPI0_Disable				0x0000
		#define 	C_SPI0_Enable				0x8000
		#define		C_SPI0_LBM_Normal			0x0000
		#define		C_SPI0_LBM_Enable			0x2000		
		#define 	C_SPI0_Reset				0x0800
		#define		C_SPI0_Mode					0x0100
		#define 	C_SPI0_MasterMode			0x0000
		#define 	C_SPI0_SlaveMode  			0x0100
		#define 	C_SPI0_Clock_Phase			0x0020
		#define 	C_SPI0_Clock_Phase_Normal	0x0000
		#define 	C_SPI0_Clock_Phase_Shift	0x0020
		#define		C_SPI0_Clock_Pol			0x0010
		#define 	C_SPI0_Clock_Pol_Normal		0x0000
		#define 	C_SPI0_Clock_Pol_Inverse	0x0010
		#define 	C_SPI0_SCK_SEL				0x0007
		#define 	C_SPI0_SCK_SYSCLK_Div_2		0x0000
		#define 	C_SPI0_SCK_SYSCLK_Div_4		0x0001
		#define 	C_SPI0_SCK_SYSCLK_Div_8		0x0002
		#define 	C_SPI0_SCK_SYSCLK_Div_16	0x0003
		#define 	C_SPI0_SCK_SYSCLK_Div_32	0x0004
		#define 	C_SPI0_SCK_SYSCLK_Div_64	0x0005
		#define 	C_SPI0_SCK_SYSCLK_Div_128	0x0006	
#define		P_SPI0_TXStatus					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x21)
		#define 	C_SPI0_TX_INT_Flag			0x8000
		#define 	C_SPI0_TX_INT_DIS			0x0000
		#define 	C_SPI0_TX_INT_EN			0x4000
		#define 	C_SPI0_TX_FIFO_Level		0x0070
		#define 	C_SPI0_TX_FIFO_Level_0		0x0000
		#define 	C_SPI0_TX_FIFO_Level_1		0x0010
		#define 	C_SPI0_TX_FIFO_Level_2		0x0020
		#define 	C_SPI0_TX_FIFO_Level_3		0x0030
		#define 	C_SPI0_TX_FIFO_Level_4		0x0040
		#define 	C_SPI0_TX_FIFO_Level_5		0x0050
		#define 	C_SPI0_TX_FIFO_Level_6		0x0060
		#define 	C_SPI0_TX_FIFO_Level_7		0x0070
		#define		C_SPI0_TX_Flag				0x0007
#define		P_SPI0_TXData					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x22)
#define		P_SPI0_RXStatus					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x23)
		#define 	C_SPI0_RX_INT_Flag			0x8000
		#define 	C_SPI0_RX_INT_DIS			0x0000
		#define 	C_SPI0_RX_INT_EN			0x4000
		#define 	C_SPI0_RX_BUF_Full			0x0200
		#define 	C_SPI0_RX_BUF_OVER_ERROR	0x0100
		#define 	C_SPI0_RX_FIFO_Level		0x0070
		#define 	C_SPI0_RX_FIFO_Level_1		0x0000
		#define 	C_SPI0_RX_FIFO_Level_2		0x0010
		#define 	C_SPI0_RX_FIFO_Level_3		0x0020
		#define 	C_SPI0_RX_FIFO_Level_4		0x0030
		#define 	C_SPI0_RX_FIFO_Level_5		0x0040
		#define 	C_SPI0_RX_FIFO_Level_6		0x0050
		#define 	C_SPI0_RX_FIFO_Level_7		0x0060
		#define 	C_SPI0_RX_FIFO_Level_8		0x0070
		#define		C_SPI0_RX_Flag				0x0007
#define		P_SPI0_RXData					(volatile unsigned int*)(P_SPI_Ctrl_Base+0x24)
#define		P_SPI0_Misc						(volatile unsigned int*)(P_SPI_Ctrl_Base+0x25)
		#define		C_SPI0_FIFO_Full_Mode		0x0200
		#define		C_SPI0_FIFO_Full_Skipped	0x0000
		#define		C_SPI0_FIFO_Full_Overwrite	0x0200
		#define		C_SPI0_FIFO_Normal_Mode		0x0000
		#define		C_SPI0_FIFO_Smart_Mode		0x0100
		#define		C_SPI0_Busy_Flag			0x0010
		#define		C_SPI0_RX_Full_Flag			0x0008
		#define		C_SPI0_RX_NonEmpty_Flag		0x0004
		#define		C_SPI0_TX_NonFull_Flag		0x0002
		#define		C_SPI0_TX_Empty_Flag		0x0001


/////////////////////////////////////////////////
//  SPIF Control Registers
//  Base Address Start from 0x7B40
/////////////////////////////////////////////////
#define		P_SPIFC_Ctrl1					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x00)
		#define 	C_SPIF_Pending_Flag			0x0001
		#define 	C_SPIF_CLK_PreStateLo		0x0000
		#define 	C_SPIF_CLK_PreStateHi		0x0002		
		#define 	C_SPIF_MIO_1bit				0x0000
		#define 	C_SPIF_MIO_2bit				0x0004
		#define 	C_SPIF_MIO_4bit				0x0008
		#define 	C_SPIF_AMIO_1bit			0x0000
		#define 	C_SPIF_AMIO_2bit			0x0010
		#define 	C_SPIF_AMIO_4bit			0x0020	
		#define 	C_SPIF_CMIO_1bit			0x0000
		#define 	C_SPIF_CMIO_2bit			0x0040
		#define 	C_SPIF_CMIO_4bit			0x0080
		#define 	C_SPIF_Auto_Mode			0x0000	
		#define 	C_SPIF_Manual_Mode			0x0100
		#define 	C_SPIF_NotIgnoreLastClk		0x0000
		#define 	C_SPIF_IgnoreLastClk		0x0200
		#define 	C_SPIF_Idle_Flag			0x2000
		#define 	C_SPIF_RxFifoEmpty_Flag		0x4000
		#define 	C_SPIF_TxTransDone_Flag		0x8000
#define		P_SPIFC_CMD						(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x01)
		#define 	C_SPIF_CMD_Mask				0x000f
		#define 	C_SPIF_TransWithoutCMD		0x0100
		#define 	C_SPIF_TransOnlyCMD			0x0200
		#define 	C_SPIF_TransWithOneCMD		0x2000
#define		P_SPIFC_PARA 					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x02)
		#define 	C_SPIF_EnhanBitMask			0x00ff
			#define 	C_SPIF_Enhance_bit0			0x0001
			#define 	C_SPIF_Enhance_bit1			0x0002
			#define 	C_SPIF_Enhance_bit2			0x0004
			#define 	C_SPIF_Enhance_bit3			0x0008
			#define 	C_SPIF_Enhance_bit4			0x0010
			#define 	C_SPIF_Enhance_bit5			0x0020
			#define 	C_SPIF_Enhance_bit6			0x0040
			#define 	C_SPIF_Enhance_bit7			0x0080	
		#define 	C_SPIF_DummyClkCycle_Mask	0x0f00
			#define		C_SPIF_DummyClk_0cycle		0x0000
			#define 	C_SPIF_DummyClk_1cycle		0x0100
			#define 	C_SPIF_DummyClk_2cycle		0x0200	
			#define 	C_SPIF_DummyClk_3cycle		0x0300
			#define 	C_SPIF_DummyClk_4cycle		0x0400
			#define 	C_SPIF_DummyClk_5cycle		0x0500
			#define 	C_SPIF_DummyClk_6cycle		0x0600
			#define 	C_SPIF_DummyClk_7cycle		0x0700
			#define 	C_SPIF_DummyClk_8cycle		0x0800
			#define 	C_SPIF_DummyClk_9cycle		0x0900
		#define 	C_SPIF_TransWithAddr		0x0000								
		#define 	C_SPIF_TransWithoutAddr		0x1000
		#define 	C_SPIF_TransOnlyAddr		0x2000
		#define 	C_SPIF_TransWithEnhanByte		0x0000
		#define 	C_SPIF_TransWithoutEnhanByte	0x4000
#define		P_SPIFC_ADDRL					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x03)
#define		P_SPIFC_ADDRH					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x04)
#define		P_SPIFC_TX_Data					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x05)
#define		P_SPIFC_RX_Data					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x06)
#define		P_SPIFC_TX_BC					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x07)
#define		P_SPIFC_RX_BC					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x08)
#define		P_SPIFC_TIMING					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x09)
#define		P_SPIFC_Ctrl2					(volatile unsigned int*)(P_SPIF_Ctrl_Base+0x0B)
		#define 	C_SPIFC_EN					0x0001
		#define 	C_SPIFC_4thAdr_EN			0xff00		


////////////////////////////////////////////////
//  DMA Control Registers
//  Base Address Start from 0x7A80
////////////////////////////////////////////////
#define		P_DMA_Ctrl0						(volatile unsigned int*)(P_DMA_Base+0x00)
		#define		C_DMA_ChEn       			0x0001
		#define		C_DMA_Busy       			0x0002
		#define		C_DMA_Mode_SW      			0x0000	
		#define		C_DMA_Mode_External   		0x0004	
		#define		C_DMA_DoubleBufferFull 		0x0008
		#define		C_DMA_TARAddress_Inc		0x0000
		#define		C_DMA_TARAddress_Dec		0x0010							
		#define		C_DMA_SRCAddress_Inc		0x0000
		#define		C_DMA_SRCAddress_Dec		0x0020	
		#define		C_DMA_TARAddress_Fix		0x0040	
		#define		C_DMA_SRCAddress_Fix		0x0080		
		#define		C_DMA_IntEn					0x0100	
		#define		C_DMA_SWReset				0x0200	
		#define		C_DMA_M_M					0x0000	
		#define		C_DMA_M_IO					0x0400			
		#define		C_DMA_IO_M					0x0800		
		#define		C_DMA_IO_IO					0x0C00	
		#define		C_DMA_SRC_8Bit				0x1000			
		#define		C_DMA_SRC_16Bit				0x0000		
		#define		C_DMA_TAR_8Bit				0x2000			
		#define		C_DMA_TAR_16Bit				0x0000	
		#define		C_DMA_Transfer_Single		0x0000	
		#define		C_DMA_Transfer_Demand		0x4000
		#define		C_DMA_Request_Read			0x0000	
		#define		C_DMA_Request_Write			0x8000	
#define		P_DMA_SRC_AddrL0				(volatile unsigned int*)(P_DMA_Base+0x01)
#define		P_DMA_TAR_AddrL0				(volatile unsigned int*)(P_DMA_Base+0x02)
#define		P_DMA_TCountL0					(volatile unsigned int*)(P_DMA_Base+0x03)
#define		P_DMA_SRC_AddrH0				(volatile unsigned int*)(P_DMA_Base+0x04)
#define		P_DMA_TAR_AddrH0				(volatile unsigned int*)(P_DMA_Base+0x05)
#define		P_DMA_TCountH0					(volatile unsigned int*)(P_DMA_Base+0x06)
#define		P_DMA_MISC0						(volatile unsigned int*)(P_DMA_Base+0x07)
#define		P_DMA_Ctrl1						(volatile unsigned int*)(P_DMA_Base+0x08)
#define		P_DMA_SRC_AddrL1				(volatile unsigned int*)(P_DMA_Base+0x09)
#define		P_DMA_TAR_AddrL1				(volatile unsigned int*)(P_DMA_Base+0x0A)
#define		P_DMA_TCountL1					(volatile unsigned int*)(P_DMA_Base+0x0B)
#define		P_DMA_SRC_AddrH1				(volatile unsigned int*)(P_DMA_Base+0x0C)
#define		P_DMA_TAR_AddrH1				(volatile unsigned int*)(P_DMA_Base+0x0D)
#define		P_DMA_TCountH1					(volatile unsigned int*)(P_DMA_Base+0x0E)
#define		P_DMA_MISC1						(volatile unsigned int*)(P_DMA_Base+0x0F)
#define		P_DMA_SPRISize0					(volatile unsigned int*)(P_DMA_Base+0x30)
#define		P_DMA_SPRISize1					(volatile unsigned int*)(P_DMA_Base+0x31)
#define		P_DMA_LineLength				(volatile unsigned int*)(P_DMA_Base+0x3D)
#define		P_DMA_SS						(volatile unsigned int*)(P_DMA_Base+0x3E)
#define		P_DMA_INT						(volatile unsigned int*)(P_DMA_Base+0x3F)
		#define		C_DMA0_ISRFlag				0x0001
		#define		C_DMA1_ISRFlag				0x0002
		#define		C_DMA0_TimeoutFlag			0x0010
		#define		C_DMA1_TimeoutFlag			0x0020
		#define		C_DMA0_BusyFlag				0x0100
		#define		C_DMA1_BusyFlag				0x0200


/////////////////////////////////////////////////
//  CTS Control Registers
//  Base Address Start from 0x7AC0
/////////////////////////////////////////////////
#define		P_CTS_Ctrl1					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x00)
		#define		C_CTS_Start       			0x8000			
		#define		C_CTS_SRCIOA4       		0x2000
		#define		C_CTS_Others       			0x0000				
		#define		C_CTS_TriEn       			0x0400
		#define		C_CTS_NF_200M      			0x0000
		#define		C_CTS_NF_8M      			0x0100
		#define		C_CTS_NF_3M      			0x0200
		#define		C_CTS_NF_1P5M      			0x0300
		#define		C_CTS_Duration_450n			0x0000
		#define		C_CTS_Duration_300n			0x0010
		#define		C_CTS_Duration_150n			0x0020
		#define		C_CTS_Duration_70n			0x0030
		#define		D_CtsVrefSel_2_1			0x0000
		#define		D_CtsVrefSel_275_025		0x0080				
		#define		C_CTS_Current_25u			0x0000
		#define		C_CTS_Current_50u			0x0002
		#define		C_CTS_Current_100u			0x0004
		#define		C_CTS_Current_150u			0x0006
		#define		C_CTS_Current_200u			0x0008	
		#define		C_CTS_Current_300u			0x000A
		#define		C_CTS_Current_450u			0x000C
		#define		C_CTS_Current_600u			0x000E
		#define		C_CTS_En					0x0001	
#define		P_CTS_CH					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x01)
#define		P_CTS_DIV					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x02)
		#define		C_CTS_SYS_DIV2     			0x0001
		#define		C_CTS_SYS_DIV4      		0x0002
		#define		C_CTS_SYS_DIV8     			0x0003		
		#define		C_CTS_SYS_DIV16    			0x0004
		#define		C_CTS_SYS_DIV32    			0x0005
		#define		C_CTS_SYS_DIV64    			0x0006
		#define		C_CTS_SYS_DIV128   			0x0007			
#define		P_CTS_CYCLE					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x03)
#define		P_CTS_Ctrl2					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x04)
		#define		C_CTS_ScanDoneIntEn 		0x0001
		#define		C_CTS_ScanAllDoneIntEn 		0x0002	
		#define		C_CTS_OverflowIntEn 		0x0004	
#define		P_CTS_Status				(volatile unsigned int*)(P_CTS_Ctrl_Base+0x05)
		#define		C_CTS_ScanDoneFlag			0x0001
		#define		C_CTS_ScanAllDoneFlag  		0x0002
		#define		C_CTS_OverflowFlag	 		0x0004	
		#define		C_CTS_FIFOFullFlag			0x0008	
#define		P_CTS_Ctrl3					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x06)	
		#define		C_CTS_LDO33_En				0x0001			
#define		P_CTS_FIFOLevel				(volatile unsigned int*)(P_CTS_Ctrl_Base+0x08)
#define		P_CTS_CNT					(volatile unsigned int*)(P_CTS_Ctrl_Base+0x09)


////////////////////////////////////////////////
//  KeyScan Control Registers
//  Base Address Start from 0x7B20
////////////////////////////////////////////////
#define		P_KS_Ctrl1						(volatile unsigned int*)(P_KeyScan_Base+0x00)
#define		P_KS_Ctrl2						(volatile unsigned int*)(P_KeyScan_Base+0x01)
#define		P_KS_Addr						(volatile unsigned int*)(P_KeyScan_Base+0x02)
#define		P_KS_Velocity					(volatile unsigned int*)(P_KeyScan_Base+0x03)
#define		P_KS_Data0						(volatile unsigned int*)(P_KeyScan_Base+0x08)
#define		P_KS_Data1						(volatile unsigned int*)(P_KeyScan_Base+0x09)
#define		P_KS_Data2						(volatile unsigned int*)(P_KeyScan_Base+0x0A)	
#define		P_KS_Data3						(volatile unsigned int*)(P_KeyScan_Base+0x0B)
#define		P_KS_Data4						(volatile unsigned int*)(P_KeyScan_Base+0x0C)
#define		P_KS_Data5						(volatile unsigned int*)(P_KeyScan_Base+0x0D)
#define		P_KS_Data6						(volatile unsigned int*)(P_KeyScan_Base+0x0E)
#define		P_KS_Data7						(volatile unsigned int*)(P_KeyScan_Base+0x0F)
#define		P_KS_Data8						(volatile unsigned int*)(P_KeyScan_Base+0x10)
#define		P_KS_Data9						(volatile unsigned int*)(P_KeyScan_Base+0x11)
#define		P_KS_Data10						(volatile unsigned int*)(P_KeyScan_Base+0x12)


/////////////////////////////////////////////////
//  ADC Control Registers
//  Base Address Start from 0x79A0
/////////////////////////////////////////////////
#define		P_ADC_Setup						(volatile unsigned int*)(P_Analog_Ctrl_Base+0x00)
		#define		C_ADC_AlwaysOn	       			0x4000
		#define		C_ADC_ManualOn	       			0x0000		
		#define		C_ADC_SysDiv4096	       		0x0600
		#define		C_ADC_SysDiv2048	       		0x0500				
		#define		C_ADC_SysDiv1024	       		0x0400
		#define		C_ADC_SysDiv64		       		0x0300
		#define		C_ADC_SysDiv128		       		0x0200	
		#define		C_ADC_SysDiv256		       		0x0100	
		#define		C_ADC_SysDiv512		       		0x0000	
		#define		C_ADC_AutoSample_En	       		0x0080
		#define		C_ADC_AutoSample_Dis       		0x0000	
		#define		C_ADC_AutoSample_LDOV50  		0x0070												
		#define		C_ADC_AutoSample_1P2V	 		0x0060	
		#define		C_ADC_AutoSample_LineIn5 		0x0050
		#define		C_ADC_AutoSample_LineIn4 		0x0040
		#define		C_ADC_AutoSample_LineIn3 		0x0030							
		#define		C_ADC_AutoSample_LineIn2 		0x0020
		#define		C_ADC_AutoSample_LineIn1 		0x0010
		#define		C_ADC_AutoSample_LineIn0 		0x0000
		#define		C_ADC_AutoSample_Start	 		0x0008
		#define		C_ADC_AutoSample_Stop	 		0x0000		
		#define		C_ADC_AutoSample_TimerF	 		0x0005
		#define		C_ADC_AutoSample_TimerE	 		0x0004
		#define		C_ADC_AutoSample_TimerD	 		0x0003
		#define		C_ADC_AutoSample_TimerC	 		0x0002
		#define		C_ADC_AutoSample_TimerB	 		0x0001
		#define		C_ADC_AutoSample_TimerA	 		0x0000																				
#define		P_MADC_Ctrl						(volatile unsigned int*)(P_Analog_Ctrl_Base+0x01)
		#define		C_ADC_ReadyFlag	       			0x8000
		#define		C_ADC_ReadyINT	       			0x4000		
		#define		C_ADC_Ready		       			0x0080		
		#define		C_ADC_ManualStart      			0x0040
		#define		C_ADC_ErrFlag1      			0x0020
		#define		C_ADC_ErrFlag2	     			0x0010	
		#define		C_ADC_Manual_LDOV50  			0x0007												
		#define		C_ADC_Manual_1P2V	 			0x0006	
		#define		C_ADC_Manual_LineIn5 			0x0005
		#define		C_ADC_Manual_LineIn4 			0x0004
		#define		C_ADC_Manual_LineIn3 			0x0003							
		#define		C_ADC_Manual_LineIn2 			0x0002
		#define		C_ADC_Manual_LineIn1 			0x0001
		#define		C_ADC_Manual_LineIn0 			0x0000					
#define		P_MADC_Data						(volatile unsigned int*)(P_Analog_Ctrl_Base+0x02)
#define		P_ASADC_Ctrl					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x03)
		#define		C_ADC_AutoSample_FF_Flag		0x8000	
		#define		C_ADC_AutoSample_FF_INT			0x4000
		#define		C_ADC_AutoSample_FF				0x2000		
		#define		C_ADC_AutoSample_OV				0x1000		
		#define		C_ADC_AutoSample_INT			0x0000			
		#define		C_ADC_AutoSample_DMA			0x0800
		#define		C_ADC_AutoSample_OverWrite		0x0400
		#define		C_ADC_AutoSample_FF_Level8		0x0080
		#define		C_ADC_AutoSample_FF_Level7		0x0070								
		#define		C_ADC_AutoSample_FF_Level6		0x0060
		#define		C_ADC_AutoSample_FF_Level5		0x0050
		#define		C_ADC_AutoSample_FF_Level4		0x0040
		#define		C_ADC_AutoSample_FF_Level3		0x0030
		#define		C_ADC_AutoSample_FF_Level2		0x0020
		#define		C_ADC_AutoSample_FF_Level1		0x0010
		#define		C_ADC_AutoSample_FF_Level0		0x0000	
		#define		C_ADC_AutoSample_FIFO_8			0x0008
		#define		C_ADC_AutoSample_FIFO_7			0x0007								
		#define		C_ADC_AutoSample_FIFO_6			0x0006
		#define		C_ADC_AutoSample_FIFO_5			0x0005
		#define		C_ADC_AutoSample_FIFO_4			0x0004
		#define		C_ADC_AutoSample_FIFO_3			0x0003
		#define		C_ADC_AutoSample_FIFO_2			0x0002
		#define		C_ADC_AutoSample_FIFO_1			0x0001
		#define		C_ADC_AutoSample_FIFO_0			0x0000																
#define		P_ASADC_Data					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x04)
#define		P_ADC_LineCH_En					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x06)
		#define		C_ADC_LineIn5_En				0x0020
		#define		C_ADC_LineIn4_En				0x0010
		#define		C_ADC_LineIn3_En				0x0008		
		#define		C_ADC_LineIn2_En				0x0004
		#define		C_ADC_LineIn1_En				0x0002
		#define		C_ADC_LineIn0_En				0x0001									
#define		P_ADC_SH_Wait					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x07)
#define		P_MICADC_Setup					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x10)
		#define		C_MICADC_AlwaysOn     			0x4000
		#define		C_MICADC_ManualOn     			0x0000		
		#define		C_MICADC_AGCEn	       			0x2000		
		#define		C_MICADC_AGCDis	       			0x0000		
		#define		C_MICADC_SignData     			0x1000	
		#define		C_MICADC_UnsignData     		0x0000	
		#define		C_MICADC_SysDiv4096	       		0x0600
		#define		C_MICADC_SysDiv2048	       		0x0500				
		#define		C_MICADC_SysDiv1024	       		0x0400
		#define		C_MICADC_SysDiv64		    	0x0300
		#define		C_MICADC_SysDiv128		       	0x0200	
		#define		C_MICADC_SysDiv256		       	0x0100	
		#define		C_MICADC_SysDiv512		       	0x0000
		#define		C_MICADC_AutoSample_En	   		0x0080
		#define		C_MICADC_AutoSample_Dis       	0x0000						
		#define		C_MICADC_MICEn       			0x0040		
		#define		C_MICADC_MICDis      			0x0000
    	#define		C_MICADC_Vref_En				0x0020
		#define		C_MICADC_Vref_Dis      			0x0000  					
		#define		C_MICADC_AutoSample_Start	 	0x0008
		#define		C_MICADC_AutoSample_Stop	 	0x0000		
		#define		C_MICADC_AutoSample_TimerF	 	0x0005
		#define		C_MICADC_AutoSample_TimerE	 	0x0004
		#define		C_MICADC_AutoSample_TimerD	 	0x0003
		#define		C_MICADC_AutoSample_TimerC	 	0x0002
		#define		C_MICADC_AutoSample_TimerB	 	0x0001
		#define		C_MICADC_AutoSample_TimerA	 	0x0000							
#define		P_MICGAIN_Ctrl					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x11)
		#define		C_MICADC_Ready				 	0x0080	
		#define		C_MICADC_GAINEN				 	0x0001			
		#define		C_MICADC_GAINDIS				0x0000
#define		P_ASMICADC_Ctrl					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x13)
		#define		C_MICADC_AutoSample_FF_Flag		0x8000	
		#define		C_MICADC_AutoSample_FF_INT		0x4000
		#define		C_MICADC_AutoSample_FF			0x2000		
		#define		C_MICADC_AutoSample_OV			0x1000		
		#define		C_MICADC_AutoSample_INT			0x0000			
		#define		C_MICADC_AutoSample_DMA			0x0800
		#define		C_MICADC_AutoSample_OverWrite	0x0400
		#define		C_MICADC_AutoSample_FF_Level8	0x0080
		#define		C_MICADC_AutoSample_FF_Level7	0x0070								
		#define		C_MICADC_AutoSample_FF_Level6	0x0060
		#define		C_MICADC_AutoSample_FF_Level5	0x0050
		#define		C_MICADC_AutoSample_FF_Level4	0x0040
		#define		C_MICADC_AutoSample_FF_Level3	0x0030
		#define		C_MICADC_AutoSample_FF_Level2	0x0020
		#define		C_MICADC_AutoSample_FF_Level1	0x0010
		#define		C_MICADC_AutoSample_FF_Level0	0x0000	
		#define		C_MICADC_AutoSample_FIFO_8		0x0008
		#define		C_MICADC_AutoSample_FIFO_7		0x0007								
		#define		C_MICADC_AutoSample_FIFO_6		0x0006
		#define		C_MICADC_AutoSample_FIFO_5		0x0005
		#define		C_MICADC_AutoSample_FIFO_4		0x0004
		#define		C_MICADC_AutoSample_FIFO_3		0x0003
		#define		C_MICADC_AutoSample_FIFO_2		0x0002
		#define		C_MICADC_AutoSample_FIFO_1		0x0001
		#define		C_MICADC_AutoSample_FIFO_0		0x0000	
#define		P_ASMICADC_Data					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x14)
#define		P_MICADC_SH_Wait				(volatile unsigned int*)(P_Analog_Ctrl_Base+0x17)
#define		P_MICADC_DataMAX				(volatile unsigned int*)(P_Analog_Ctrl_Base+0x18)
#define		P_MICADC_DataMIN				(volatile unsigned int*)(P_Analog_Ctrl_Base+0x19)
#define		P_MICADC_FLAG					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x1A)
#define		P_MICADC_GAIN					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x1B)

#define		P_MICAGC_Ctrl					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x1C)
		#define		C_MICAGC_Peak	       	0x8000		
		#define		C_MICAGC_RMS	       	0x0000	
		#define		C_MICAGC_AttSca_1		0x0000	
		#define		C_MICAGC_AttSca_4	    0x0040	
		#define		C_MICAGC_AttSca_16	    0x0080	
		#define		C_MICAGC_AttSca_64	    0x00C0	
		#define		C_MICAGC_RelSca_1      	0x0000	
		#define		C_MICAGC_RelSca_4      	0x0010
		#define		C_MICAGC_RelSca_16     	0x0020
		#define		C_MICAGC_RelSca_64     	0x0030
		#define		C_MICAGC_ZeroCross_En  	0x0000
		#define		C_MICAGC_ZeroCross_Dis 	0x0008
#define		P_MICAGC_Time					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x1D)
#define		P_MICAGC_Enable					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x1E)
		#define		C_MICAGC_En	       		0x0001		
		#define		C_MICAGC_Dis	       	0x0000	
#define		P_MICAGC_Status					(volatile unsigned int*)(P_Analog_Ctrl_Base+0x1F)
#define		P_MICAGC_UpThres				(volatile unsigned int*)(P_Analog_Ctrl_Base+0x15)

/////////////////////////////////////////////////
//  USB Device Control Registers
//  Base Address Start from 0x7A40
/////////////////////////////////////////////////
#define		P_USBD_Config					(volatile unsigned int*)(P_USBDevice_Base+0x00)
#define		P_USBD_Function					(volatile unsigned int*)(P_USBDevice_Base+0x01)
#define		P_USBD_PMR						(volatile unsigned int*)(P_USBDevice_Base+0x02)
#define		P_USBD_EP0Data					(volatile unsigned int*)(P_USBDevice_Base+0x03)
#define		P_USBD_BIData					(volatile unsigned int*)(P_USBDevice_Base+0x04)
#define		P_USBD_BOData					(volatile unsigned int*)(P_USBDevice_Base+0x05)
#define		P_USBD_INTINData				(volatile unsigned int*)(P_USBDevice_Base+0x06)
#define		P_USBD_EPEvent					(volatile unsigned int*)(P_USBDevice_Base+0x07)	
#define		P_USBD_GLOINT					(volatile unsigned int*)(P_USBDevice_Base+0x08)
#define		P_USBD_INTEN					(volatile unsigned int*)(P_USBDevice_Base+0x09)
#define		P_USBD_INT						(volatile unsigned int*)(P_USBDevice_Base+0x0A)
#define		P_USBD_SCINTEN					(volatile unsigned int*)(P_USBDevice_Base+0x0B)
#define		P_USBD_SCINTF					(volatile unsigned int*)(P_USBDevice_Base+0x0C)
#define		P_USBD_EPAutoSet				(volatile unsigned int*)(P_USBDevice_Base+0x0D)
#define		P_USBD_EPSetStall				(volatile unsigned int*)(P_USBDevice_Base+0x0E)
#define		P_USBD_EPBufClear				(volatile unsigned int*)(P_USBDevice_Base+0x0F)
#define		P_USBD_EPEvntClear				(volatile unsigned int*)(P_USBDevice_Base+0x10)
#define		P_USBD_EP0WrtCount				(volatile unsigned int*)(P_USBDevice_Base+0x11)
#define		P_USBD_BOWrtCount				(volatile unsigned int*)(P_USBDevice_Base+0x12)
#define		P_USBD_EP0BufPointer			(volatile unsigned int*)(P_USBDevice_Base+0x13)
#define		P_USBD_BBufRdPointer			(volatile unsigned int*)(P_USBDevice_Base+0x14)
#define		P_USBD_BBufWrtPointer			(volatile unsigned int*)(P_USBDevice_Base+0x15)
#define		P_USBD_EP0RTR					(volatile unsigned int*)(P_USBDevice_Base+0x16)
#define		P_USBD_EP0RR					(volatile unsigned int*)(P_USBDevice_Base+0x17)
#define		P_USBD_EP0VR					(volatile unsigned int*)(P_USBDevice_Base+0x18)
#define		P_USBD_EP0IR					(volatile unsigned int*)(P_USBDevice_Base+0x19)
#define		P_USBD_EP0LR					(volatile unsigned int*)(P_USBDevice_Base+0x1A)
#define		P_USBD_DMAWrtCountL				(volatile unsigned int*)(P_USBDevice_Base+0x20)
#define		P_USBD_DMAWrtCountH				(volatile unsigned int*)(P_USBDevice_Base+0x21)
#define		P_USBD_DMAAckL					(volatile unsigned int*)(P_USBDevice_Base+0x22)
#define		P_USBD_DMAAckH					(volatile unsigned int*)(P_USBDevice_Base+0x23)
#define		P_USBD_EPStall					(volatile unsigned int*)(P_USBDevice_Base+0x24)
#define		P_USBD_Device					(volatile unsigned int*)(P_USBDevice_Base+0x27)
#define		P_USBD_NullPkt					(volatile unsigned int*)(P_USBDevice_Base+0x28)
#define		P_USBD_DMAINT					(volatile unsigned int*)(P_USBDevice_Base+0x29)
#define		P_USBD_INTF     				(volatile unsigned int*)(P_USBDevice_Base+0x2C)


////////////////////////////////////////////
//	miscellaneous control register
//	Base address is from 0x7AF0
////////////////////////////////////////////
#define		P_Byte_Swap						(volatile unsigned int*)(P_MISC_Base+0x00)
#define		P_Nibble_Swap					(volatile unsigned int*)(P_MISC_Base+0x01)
#define		P_TowBit_Swap					(volatile unsigned int*)(P_MISC_Base+0x02)
#define		P_Bit_Reverse					(volatile unsigned int*)(P_MISC_Base+0x03)


///////////////////////////////////////////////
//  Speech Process Unit(SPU) Control Registers
//  Base Address Start from 0x7B80
///////////////////////////////////////////////
#define		P_SPU_CtrChEn					(volatile unsigned int*)(P_SPU_Base+0x00)	
#define		P_SPU_CtrMainVol				(volatile unsigned int*)(P_SPU_Base+0x01)
#define		P_SPU_CtrChFiqEn				(volatile unsigned int*)(P_SPU_Base+0x02)	
#define		P_SPU_CtrChFiqSts				(volatile unsigned int*)(P_SPU_Base+0x03)	
#define		P_SPU_CtrBeatBase				(volatile unsigned int*)(P_SPU_Base+0x04)	
#define		P_SPU_CtrBeatCnt				(volatile unsigned int*)(P_SPU_Base+0x05)	
#define		P_SPU_CtrEnvClkSel0				(volatile unsigned int*)(P_SPU_Base+0x06)	
#define		P_SPU_CtrEnvClkSel1				(volatile unsigned int*)(P_SPU_Base+0x07)	
#define		P_SPU_CtrEnvClkSel2				(volatile unsigned int*)(P_SPU_Base+0x08)	
#define		P_SPU_CtrEnvClkSel3				(volatile unsigned int*)(P_SPU_Base+0x09)	
#define		P_SPU_CtrEnvRampDown			(volatile unsigned int*)(P_SPU_Base+0x0A)	
#define		P_SPU_CtrChStopSts				(volatile unsigned int*)(P_SPU_Base+0x0B)	
#define		P_SPU_CtrChZeroCrossEn			(volatile unsigned int*)(P_SPU_Base+0x0C)	
#define		P_SPU_CtrFlag					(volatile unsigned int*)(P_SPU_Base+0x0D)	
#define		P_SPU_CtrDummy					(volatile unsigned int*)(P_SPU_Base+0x0E)	
#define		P_SPU_CtrChSts					(volatile unsigned int*)(P_SPU_Base+0x0F)	
#define		P_SPU_CtrWaveInL				(volatile unsigned int*)(P_SPU_Base+0x10)	
#define		P_SPU_CtrWaveInR				(volatile unsigned int*)(P_SPU_Base+0x11)	
#define		P_SPU_CtrWaveOutL				(volatile unsigned int*)(P_SPU_Base+0x12)	
#define		P_SPU_CtrWaveOutR				(volatile unsigned int*)(P_SPU_Base+0x13)	
#define		P_SPU_CtrChRepeatEn				(volatile unsigned int*)(P_SPU_Base+0x14)
#define		P_SPU_CtrChEnvMode				(volatile unsigned int*)(P_SPU_Base+0x15)	
#define		P_SPU_CtrChToneRelease			(volatile unsigned int*)(P_SPU_Base+0x16)	
#define		P_SPU_CtrChEnvIrqSts			(volatile unsigned int*)(P_SPU_Base+0x17)	
#define		P_SPU_CtrChPitchBendEn			(volatile unsigned int*)(P_SPU_Base+0x18)	
#define		P_SPU_CtrAttRelTime     		(volatile unsigned int*)(P_SPU_Base+0x1A)			
#define		P_SPU_CtrWaveBankAddr  	 		(volatile unsigned int*)(P_SPU_Base+0x1F)			
#define		P_SPU_ChWaveAddr				(volatile unsigned int*)(P_SPU_Base+0x80)	
#define		P_SPU_ChMode					(volatile unsigned int*)(P_SPU_Base+0x81)	
#define		P_SPU_ChLoopAddr				(volatile unsigned int*)(P_SPU_Base+0x82)	
#define		P_SPU_ChPan						(volatile unsigned int*)(P_SPU_Base+0x83)	
#define		P_SPU_ChEnvelop0				(volatile unsigned int*)(P_SPU_Base+0x84)	
#define		P_SPU_ChEnvelopData				(volatile unsigned int*)(P_SPU_Base+0x85)	
#define		P_SPU_ChEnvelop1				(volatile unsigned int*)(P_SPU_Base+0x86)	
#define		P_SPU_ChEnvelopSeg				(volatile unsigned int*)(P_SPU_Base+0x87)	
#define		P_SPU_ChEnvelopOffset			(volatile unsigned int*)(P_SPU_Base+0x88)	
#define		P_SPU_ChWaveData0				(volatile unsigned int*)(P_SPU_Base+0x89)	
#define		P_SPU_ChEnvelopLoop				(volatile unsigned int*)(P_SPU_Base+0x8A)	
#define		P_SPU_ChWaveData1				(volatile unsigned int*)(P_SPU_Base+0x8B)	
#define		P_SPU_ChAdpcmSel				(volatile unsigned int*)(P_SPU_Base+0x8D)	
#define		P_SPU_ChPhaseHi					(volatile unsigned int*)(P_SPU_Base+0x280)
#define		P_SPU_ChPhaseAccumHi			(volatile unsigned int*)(P_SPU_Base+0x281)
#define		P_SPU_ChTargetPhaseHi			(volatile unsigned int*)(P_SPU_Base+0x282)
#define		P_SPU_ChRampDownClk				(volatile unsigned int*)(P_SPU_Base+0x283)
#define		P_SPU_ChPhase					(volatile unsigned int*)(P_SPU_Base+0x284)
#define		P_SPU_ChPhaseAccum				(volatile unsigned int*)(P_SPU_Base+0x285)
#define		P_SPU_ChTargetPhase				(volatile unsigned int*)(P_SPU_Base+0x286)
#define		P_SPU_ChPhaseControl			(volatile unsigned int*)(P_SPU_Base+0x287)	

//========================================================================================
// End of include file            
//========================================================================================