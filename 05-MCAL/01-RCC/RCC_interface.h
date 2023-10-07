#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

/* !Comment: Peripheral ID */
#define AHB      (uint8)1u
#define APB1     (uint8)2u
#define APB2     (uint8)3u

/* !Comment: Clock Selection ID */
#define RCC_HSI         (uint8)1u    
#define RCC_HSE_RC      (uint8)2u
#define RCC_HSE_CRYSTAL (uint8)3u
#define RCC_PLL         (uint8)4u

/* !Comment: RCC API */
Std_ReturnType RCC_udtInitSystemClock(void);
Std_ReturnType RCC_udtEnablePeripheralClock(uint8 u8BusId, uint8 u8PerId);
Std_ReturnType RCC_udtDisablePeripheralClock(uint8 u8BusId, uint8 u8PerId);
Std_ReturnType RCC_udtResetPeripheral(uint8 u8BusId, uint8 u8PerId);

/* !Comment: RCC Function ID */
#define RCC_udtInitSystemClock_ID           (uint8)1u
#define RCC_udtEnablePeripheralClock_ID     (uint8)2u
#define RCC_udtDisablePeripheralClock_ID    (uint8)3u
#define RCC_udtResetPeripheral_ID           (uint8)4u

/* !Comment: ERROR ID */
#define RCC_INVALID_BUS_ID                   (uint8)1u
#define RCC_INVALID_PERPHERIAL_ID            (uint8)2u


#define HSI         (uint8)0u
#define HSE_RC      (uint8)1u
#define HSE_CRYSTAL (uint8)2u
#define PLL         (uint8)3u

#define CLOCK_SOURCE    HSI

#define ENABLE  0b1
#define DISABLE 0b0

#define NOT_READY       0b0
#define READY           0b1


f(VCO clock) = f(PLL clock input) * (PLLN / PLLM)
f(PLL general clock output) = f(VCO clock) / PLLP

VCO output frequency = VCO input frequency × PLLN with 192 ≤ PLLN ≤ 432


/*  
*   VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
*   It is recommended to select a frequency of 2 MHz to limit PLL jitter
*/
#define PLL_JITTER_FREQUENCY_LIMIT (uint8)2u
#define MARGINE                    (uint8)1u

#define PLL_INPUT_FREQUENCY      17u
#define PLL_OUTPUT_FREQUENCY     80u




#endif
