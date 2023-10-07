#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

Std_ReturnType NVIC_udtEnableInterrupt(uint8 u8PerIndex);
Std_ReturnType NVIC_udtDisableInterrupt(uint8 u8PerIndex);
Std_ReturnType NVIC_udtSetPendingFlag(uint8 u8PerIndex);
Std_ReturnType NVIC_udtClearPendingFlag(uint8 u8PerIndex);
Std_ReturnType NVIC_udtGetActiveFlag(uint8 u8PerIndex, uint8 *pu8ActiveFlag);




#end // _NVIC_INTERFACE_H_
