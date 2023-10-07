#ifndef _DMA_PRIVATE_H_
#define _DMA_PRIVATE_H_

typedef struct
{
    union
    {
        uint32 R;
        struct
        {
            uint32 EN:1;
            uint32 DMEIE:1;
            uint32 TEIE:1;
            uint32 HTIE:1;
            uint32 TCIE:1;
            uint32 PFCTRL:1;
            uint32 DIR:2;
            uint32 CIRC:1;
            uint32 PINC:1;
            uint32 MINC:1;
            uint32 PSIZE:2;
            uint32 MSIZE:2;
            uint32 PINCOS:1;
            uint32 PL:2;
            uint32 DBM:1;
            uint32 CT:1;
            uint32 Reserved1:1;
            uint32 PBURST:2;
            uint32 MBURST:2;
            uint32 CHSEL:3;
            uint32 Reserved2:4;
        }B;
        
    }CR;
    uint32 NDTR;
    uint32 PAR;
    uint32 M0AR;
    uint32 M1AR;
    uint32 FCR;
}STREAM_type;

typedef struct
{
    uint32 LISR;
    uint32 HISR;
    uint32 LIFCR;
    uint32 HIFCR;
    STREAM_type S[8];
}DMA_type;

#define DMA1 ((volatile DMA_type *)(0x40026000u))
#define DMA2 ((volatile DMA_type *)(0x40026400u))

#end // _DMA_PRIVATE_H_