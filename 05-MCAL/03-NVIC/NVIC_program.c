#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DET.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

Std_ReturnType NVIC_udtEnableInterrupt(uint8 u8PerIndex)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(u8PerIndex > 84)
    {
        return udtReturnType;
    }

    NVIC->ISER[u8PerIndex / 32] = (1 << (u8PerIndex % 32) );

    udtReturnType = E_OK;

    return udtReturnType;
}

Std_ReturnType NVIC_udtDisableInterrupt(uint8 u8PerIndex)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(u8PerIndex > 84)
    {
        return udtReturnType;
    }

    NVIC->ICER[u8PerIndex / 32] = (1 << (u8PerIndex % 32) );

    udtReturnType = E_OK;

    return udtReturnType;
}

Std_ReturnType NVIC_udtSetPendingFlag(uint8 u8PerIndex)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(u8PerIndex > 84)
    {
        return udtReturnType;
    }

    NVIC->ISPR[u8PerIndex / 32] = (1 << (u8PerIndex % 32) );

    udtReturnType = E_OK;

    return udtReturnType;
}

Std_ReturnType NVIC_udtClearPendingFlag(uint8 u8PerIndex)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(u8PerIndex > 84)
    {
        return udtReturnType;
    }

    NVIC->ICPR[u8PerIndex / 32] = (1 << (u8PerIndex % 32) );

    udtReturnType = E_OK;

    return udtReturnType;
}

STD_ReturnType NVIC_udtGetActiveFlag(uint8 u8PerIndex, uint8 *pu8ActiveFlag)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

    if(u8PerIndex > 84)
    {
        return udtReturnType;
    }

    *pu8ActiveFlag = GET_BIT(NVIC->IABR[u8PerIndex / 32], (1 << (u8PerIndex % 32) ));

    udtReturnType = E_OK;

    return udtReturnType;
}