#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType RCC_udtInitSystemClock(void)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

/********************************** HSI ***************************************/
    #if     CLOCK_SOURCE == HSI
    
    RCC->CR.B.HSION = ENABLE;
    while (RCC->CR.B.HSIRDY == NOT_READY);
    udtReturnType = E_OK;


/********************************** HSE_RC ***************************************/
    #elif   CLOCK_SOURCE == HSE_RC

    RCC->CR.B.HSEBYP = ENABLE;
    RCC->CR.B.HSEON  = ENABLE;
    while (RCC->CR.B.HSERDY == NOT_READY);
    udtReturnType = E_OK;


/********************************** HSE_CRYSTAL ***************************************/
    #elif   CLOCK_SOURCE == HSE_CRYSTAL

    RCC->CR.B.HSEON = ENABLE;
    while (RCC->CR.B.HSERDY == NOT_READY);
    udtReturnType = E_OK;


/********************************** PLL ***************************************/
    #elif   CLOCK_SOURCE == PLL
    /*  
    *   VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
    *   It is recommended to select a frequency of 2 MHz to limit PLL jitter
    */
    uint8 PLLM = (PLL_INPUT_FREQUENCY/PLL_JITTER_FREQUENCY_LIMIT) + MARGINE ;
    RCC->PLLCFGR = PLLM << 2u;

    PLLP = PLL_OUTPUT_FREQUENCY / 45;
    freq_out = 

    uint8 PLLP = 2;
    switch(PLL_OUTPUT_FREQUENCY/45)
    {
        case 1: PLLP = 8; break;
        case 2: PLLP = 6; break;
        case 3: PLLP = 4; break;
        case 4: PLLP = 2; break;
        default: PLLP = 2; break;
    }

    

    RCC->CR.B.PLLON = ENABLE;
    while (RCC->CR.B.PLLRDY == NOT_READY);
    udtReturnType = E_OK;

/********************************** INVALID ***************************************/
    #else
    /* void DET_vidReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId); */
    #endif
    
    return udtReturnType;
    
}
Std_ReturnType RCC_udtEnablePeripheralClock(uint8 u8BusId, uint8 u8PerId)
{
    Std_ReturnType udtReturnValue = E_NOT_OK;

    if(u8PerId > RCC_MAC_PERIPHERAL_ID )
    {
        /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID) */
        return E_NOT_OK;
    }

    switch (u8BusId)
    {
    case AHB:
        SET_BIT(RCC->AHB1ENR, u8PerId);
        udtReturnValue = E_OK;
        break;
    case APB1:
        SET_BIT(RCC->APB1ENR, u8PerId);
        udtReturnValue = E_OK;
        break;
    case APB2:
        SET_BIT(RCC->APB2ENR, u8PerId);
        udtReturnValue = E_OK;
        break;
    default:
        /* !Comment: REport Error */
        /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERPHERIAL_ID)*/
        break;
    }



    return udtReturnValue;
}
Std_ReturnType RCC_udtDisablePeripheralClock(uint8 u8BusId, uint8 u8PerId)
{
    Std_ReturnType udtReturnValue = E_NOT_OK;

    if(u8PerId > RCC_MAC_PERIPHERAL_ID )
    {
        /* Det_ReportError(RCC_ID, RCC_udtDisablePeripheralClock_ID, RCC_INVALID_BUS_ID) */
        return E_NOT_OK;
    }

    switch (u8BusId)
    {
    case AHB:
        CLEAR_BIT(RCC->AHB1ENR, u8PerId);
        udtReturnValue = E_OK;
        break;
    case APB1:
        CLEAR_BIT(RCC->APB1ENR, u8PerId);
        udtReturnValue = E_OK;
        break;
    case APB2:
        CLEAR_BIT(RCC->APB2ENR, u8PerId);
        udtReturnValue = E_OK;
        break;
    default:
        /* !Comment: REport Error */
        /* Det_ReportError(RCC_ID, RCC_udtDisablePeripheralClock_ID, RCC_INVALID_PERPHERIAL_ID)*/
        break;
    }



    return udtReturnValue;
}
Std_ReturnType RCC_udtResetPeripheral(uint8 u8BusId, uint8 u8PerId)
{
    Std_ReturnType udtReturnValue = E_NOT_OK;

    if(u8PerId > RCC_MAC_PERIPHERAL_ID )
    {
        /* Det_ReportError(RCC_ID, RCC_RCC_udtResetPeripheral_ID, RCC_INVALID_BUS_ID) */
        return E_NOT_OK;
    }

    switch (u8BusId)
    {
    case AHB:
        SET_BIT(RCC->AHB1RSTR, u8PerId);
        udtReturnValue = E_OK;
        break;
    case APB1:
        SET_BIT(RCC->APB1RSTR, u8PerId);
        udtReturnValue = E_OK;
        break;
    case APB2:
        SET_BIT(RCC->APB2RSTR, u8PerId);
        udtReturnValue = E_OK;
        break;
    default:
        /* !Comment: REport Error */
        /* Det_ReportError(RCC_ID, RCC_RCC_udtResetPeripheral_ID, RCC_INVALID_PERPHERIAL_ID)*/
        break;
    }



    return udtReturnValue;
}