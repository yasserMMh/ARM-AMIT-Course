#ifndef _DET_H_
#define _DET_H_

/* !Comment: List of Module IDs */
#define RCC_MODULE_ID       1u
#define GPIO_MODULE_ID      2u
#define NVIC_MODULE_ID      3u
#define DMA_MODULE_ID      5u


void DET_vidReportError(uint8 u8ModuleId, uint8 u8ErrorId, uint8 u8FunctionId);

#endif //_DET_H_