#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_

typedef struct
{
    uint32 ISER[8],
    uint32 RESERVED1[24],
    uint32 ICER[8],
    uint32 RESERVED2[24],
    uint32 ISPR[8],
    uint32 RESERVED3[24],
    uint32 IABR[8],
    uint32 RESERVED4[56],
    uint8  IPR[85],
}NVIC_type;

#define NVIC ((volatile NVIC_type *)(0xE000E100u))

#end // _NVIC_PRIVATE_H_