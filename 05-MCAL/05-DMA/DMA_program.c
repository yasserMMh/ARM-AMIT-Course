#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DET.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void DMA_vidInit(uint8 u8DMAPer)
{
    Std_ReturnType udtReturnType = E_NOT_OK;


}

Std_ReturnType DMA_udtTransferData(uint8 u8DMAPer, uint8 u8Stream, uint32* pu32SrcAddress, uint32* pu32DesAddress, uint32 u32BlockSIze)
{
    Std_ReturnType udtReturnType = E_NOT_OK;

    DMA_type *pudtDMA = NULL;

    switch (u8DMAPer)
    {
    case DMA1_PERPHERIAL:
        pudtDMA = DMA1;
        break;
    
    case DMA2_PERPHERIAL:
        pudtDMA = DMA2;
        break;
    
    default:
        /* void DET_vidReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId); */
        break;
    }

    if(u8Stream > DMA_NUM_STREAM)
    {
        return udtReturnType;
    }

    pudtDMA->S[u8Stream].M0AR = pu32SrcAddress;
    pudtDMA->S[u8Stream].PAR  = pu32DesAddress;
    pudtDMA->S[u8Stream].NDTR = u32BlockSIze;

    pudtDMA->S[u8Stream].CR.B.EN = 0b1;
}