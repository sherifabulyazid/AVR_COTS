#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define ENABLE_PERIPHERAL 1
#define DISABLE_PERIPHERAL 0
#define RESET_PERIPHERAL 2

#define AHB_BUS 0
#define APB1_BUS 1
#define APB2_BUS 2

/* Clock Type */
#define	 HSI		 1
#define	 HSE		 2
#define	 PLL		 3
#define	 HSE_BYPASS  7
/*PLL Source*/
#define 	PLL_HSI_DIVIDED_BY_2 	 4
#define 	PLL_HSE					 5
#define 	PLL_HSE_DIVIDED_BY_2 	 6

/* ClockFactor For PLL */
#define NO_CLOCK_FACTOR 0b0000
#define PLL_CLOCK_MULTIPLE_BY_2 0b0000
#define PLL_CLOCK_MULTIPLE_BY_3 0b0001
#define PLL_CLOCK_MULTIPLE_BY_4 0b0010
#define PLL_CLOCK_MULTIPLE_BY_5 0b0011
#define PLL_CLOCK_MULTIPLE_BY_6 0b0100
#define PLL_CLOCK_MULTIPLE_BY_7 0b0101
#define PLL_CLOCK_MULTIPLE_BY_8 0b0110
#define PLL_CLOCK_MULTIPLE_BY_9 0b0111
#define PLL_CLOCK_MULTIPLE_BY_10 0b1000
#define PLL_CLOCK_MULTIPLE_BY_11 0b1001
#define PLL_CLOCK_MULTIPLE_BY_12 0b1010
#define PLL_CLOCK_MULTIPLE_BY_13 0b1011
#define PLL_CLOCK_MULTIPLE_BY_14 0b1100
#define PLL_CLOCK_MULTIPLE_BY_15 0b1101
#define PLL_CLOCK_MULTIPLE_BY_16 0b1110

/* Clock Security System */
#define DISABLE_CLOCK_SECURITY_SYSTEM 0
#define ENABLE_CLOCK_SECURITY_SYSTEM 1

/* Peripheral Clock Enable For AHB Bus */
#define DMA1_RCC 0
#define DMA2_RCC 1
#define SRAM_RCC 2
#define FLITF_RCC 4
#define CRC_RCC 6
#define OTGFS_RCC 12
#define ETHMAC_RCC 14
#define ETHMACTX_RCC 15
#define ETHMACRX_RCC 16

/* Peripheral Clock Enable For APB2 Bus */
#define AFIO_RCC 0
#define GPIOA_RCC 2
#define GPIOB_RCC 3
#define GPIOC_RCC 4
#define GPIOD_RCC 5
#define GPIOE_RCC 6
#define ADC1_RCC 9
#define ADC2_RCC 10
#define TIM1_RCC 11
#define SPI1_RCC 12
#define USART1_RCC 14

/* Peripheral Clock Enable For APB1 Bus */
#define TIM2_RCC 0
#define TIM3_RCC 1
#define TIM4_RCC 2
#define TIM5_RCC 3
#define TIM6_RCC 4
#define TIM7_RCC 5
#define WWDG_RCC 11
#define SPI2_RCC 14
#define SPI3_RCC 15
#define USART2_RCC 17
#define USART3_RCC 18
#define UART4_RCC 19
#define UART5_RCC 20
#define I2C1_RCC 21
#define I2C2_RCC 22
#define CAN1_RCC 25
#define CAN2_RCC 26
#define BKP_RCC 27
#define PWR_RCC 28
#define DAC_RCC 29

void RCC_VoidInit(void);
void RCC_VoidEnablePeripheralClock(uint8 Copy_uint8PeripheralBus, uint8 Copy_uint8Peripheral);
void RCC_VoidDisablePeripheralClock(uint8 Copy_uint8PeripheralBus, uint8 Copy_uint8Peripheral);

#endif
