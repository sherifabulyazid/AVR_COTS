#include "STD.h"
#include "BIT_MATH.h"
#include "RCC_CONFIG.h"
#include "RCC_REGISTER.h"
#include "RCC_INTERFACE.h"
#include "RCC_PRIVATE.h"


void RCC_VoidInit(void)
{
	uint32 local_uint32TimeOut = 0;

#if CLOCK_TYPE ==HSI
	/*Bits 1:0 SW: System clock switch*/
	/*00: HSI selected as system clock*/
	CLEAR_BIT(RCC->CFGR,0);
	CLEAR_BIT(RCC->CFGR,1);
	/* HSION: Internal high-speed clock enable */
	SET_BIT(RCC->CR,0);
	/*wait till HSI is stable*/
	while((GET_BIT(RCC->CR,1)==0) && (local_uint32TimeOut<100000))
	{
		local_uint32TimeOut++;
	}
#elif  CLOCK_TYPE == HSE
	/*Bits 1:0 SW: System clock switch*/
	/*01: HSE selected as system clock */
	SET_BIT(RCC->CFGR,0);
	CLEAR_BIT(RCC->CFGR,1);
	/*Bit 16 HSEON: HSE clock enable*/
	SET_BIT(RCC->CR,16);
	/*wait till HSE is stable*/
	while((GET_BIT(RCC->CR,17)==0) && (local_uint32TimeOut<100000))
	{
		local_uint32TimeOut++;
	}

#elif CLOCK_TYPE == PLL

	/*Bits 1:0 SW: System clock switch*/
	/*10: PLL selected as system clock */
	CLEAR_BIT(RCC->CFGR, 0);
	SET_BIT(RCC->CFGR, 1);
	/* The start of nested if */
	#if ( CLOCK_FACTOR>=NO_CLOCK_FACTOR )&& ( CLOCK_FACTOR <=PLL_CLOCK_MULTIPLE_BY_16 )
	RCC->CFGR &= ~((0b11111)<<18);
	RCC->CFGR |= ( CLOCK_FACTOR ) <<18;
	#elif ( CLOCK_FACTOR < NO_CLOCK_FACTOR )&& ( CLOCK_FACTOR > PLL_CLOCK_MULTIPLE_BY_16 )
	#warning "Wrong Multiplication Factor"
	/*The End Of Nested IF*/
	#endif
	/*  The start of nested if  */
	#if PLL_SOURCE == PLL_HSI_DIVIDED_BY_2
	/*HSI oscillator clock / 2 selected as PLL input clock*/
	CLEAR_BIT(RCC->CFGR, 16);
	#elif PLL_SOURCE == PLL_HSE

	/* Bit 16 -> Enable The HSE Clock */
	SET_BIT(RCC->CR, 16);

	/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
	/* PLL Entery Clock Source Is HSE */
	SET_BIT(RCC->CFGR, 16);

	/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
	/* HSE Is Not Divided */
	CLEAR_BIT(RCC->CFGR, 17);

	#elif PLL_SOURCE == PLL_HSE_DIVIDED_BY_2

	/* Bit 16 : Enable The HSE Clock */
	SET_BIT(RCC->CR, 16);

	/* BIT 16 : Choose PLL Source -> If HSI/2 OR HSE */
	/* PLL Entery Clock Source Is HSE */
	SET_BIT(RCC->CFGR, 16);
	/* BIT 17 : IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
	/* HSE Is Divided By Two */
	SET_BIT(RCC->CFGR, 17);
	/*The End Of Nested IF*/
	#endif
	/* PLL Clock Enable */
	SET_BIT(RCC->CR,24);
	/* Wait Until PLL Ready Flag Set */
	while ( (GET_BIT(RCC->CR,25)==0) && (local_uint32TimeOut<100000) )
	{
		local_uint32TimeOut++;
	}
#elif CLOCK_TYPE== HSE_BYPASS
	/*The HSEBYP bit can be written only if the HSE oscillator is disabled */
	CLEAR_BIT(RCC->CR,16);
	/*Bit 18 HSEBYP: External high-speed clock bypass*/
	SET_BIT(RCC->CR,18);
	/* Select HSE As A System Clock */
	SET_BIT(RCC->CFGR,0);
	CLEAR_BIT(RCC->CFGR,1);
	/*Enable HSE CLOCK*/
	SET_BIT(RCC->CR,16);
	/*wait till HSE is stable*/
	while((GET_BIT(RCC->CR,17)==0) && (local_uint32TimeOut<100000))
	{
		local_uint32TimeOut++;
	}
#else

#error " Invalid Clock System Type Configuration Choice"

#endif

#if CLOCK_SECURITY_SYSTEM== ENABLE_CLOCK_SECURITY_SYSTEM
	SET_BIT(RCC->CR,19);
#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM
	CLEAR_BIT(RCC->CR,19);
#else

#warning " Invalid Clock Security System Configuration Choice "
#endif
}
void RCC_VoidEnablePeripheralClock(uint8 Copy_uint8PeripheralBus, uint8 Copy_uint8Peripheral)
{
	switch(Copy_uint8PeripheralBus)
	{
	case APB1_BUS:
		SET_BIT(RCC->APB1ENR,Copy_uint8Peripheral);
		break;
	case APB2_BUS:
		SET_BIT(RCC->APB2ENR,Copy_uint8Peripheral);
		break;
	case AHB_BUS:
		SET_BIT(RCC->AHBENR,Copy_uint8Peripheral);
	}
}

void RCC_VoidDisablePeripheralClock(uint8 Copy_uint8PeripheralBus, uint8 Copy_uint8Peripheral)
{
	switch(Copy_uint8PeripheralBus)
	{
	case APB1_BUS:
		CLEAR_BIT(RCC->APB1ENR,Copy_uint8Peripheral);
		break;
	case APB2_BUS:
		CLEAR_BIT(RCC->APB2ENR,Copy_uint8Peripheral);
		break;
	case AHB_BUS:
		CLEAR_BIT(RCC->AHBENR,Copy_uint8Peripheral);
	}
}
