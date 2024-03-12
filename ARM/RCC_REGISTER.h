#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_

typedef struct
{
    uint32 CR;
    uint32 CFGR;
    uint32 CIR;
    uint32 APB2RSTR;
    uint32 APB1RSTR;
    uint32 AHBENR;
    uint32 APB2ENR;
    uint32 APB1ENR;
    uint32 BDCR;
    uint32 CSR;
    uint32 AHBRSTR;
    uint32 CFGR2;
} RCC_t;

#define RCC ((volatile RCC_t *)0x40021000)

#endif
