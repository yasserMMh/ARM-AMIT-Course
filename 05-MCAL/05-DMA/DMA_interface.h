#ifndef _DMA_INTERFACE_H_
#define _DMA_INTERFACE_H_


void DMA_vidInit(uint8 u8DMAPer);
Std_ReturnType DMA_udtTransferData(uint8 u8DMAPer, uint8 u8Stream, uint32* pu32SrcAddress, uint32* pu32DesAddress, uint32 u32BlockSIze);

/* !Comment: DMA Function ID */
#define DMA_vidInit              (uint8)1u
#define DMA_udtTransferData      (uint8)2u

#define DMA1_PERPHERIAL 1u
#define DMA2_PERPHERIAL 2u
#define DMA_NUM_STREAM  8u

#end // _DMA_INTERFACE_H_
