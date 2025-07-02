#ifndef PCC_REGISTERS_H
#define PCC_REGISTERS_H

#include <stdint.h>

/** PCC - Register Layout Typedef */
typedef struct {
    uint32_t RESERVED_0[32];       // Offset 0x00 to 0x7C (Reserved)
    volatile uint32_t PCC_FTFC;    // Offset 0x80
    volatile uint32_t PCC_DMAMUX;  // Offset 0x84
    uint32_t RESERVED_1[2];        // Offset 0x88 and 0x8C
    volatile uint32_t PCC_FlexCAN0;// Offset 0x90
    volatile uint32_t PCC_FlexCAN1;// Offset 0x94
    volatile uint32_t PCC_FTM3;    // Offset 0x98
    volatile uint32_t PCC_ADC1;    // Offset 0x9C
    uint32_t RESERVED_2[3];        // Offset 0xA0 to 0xA8 (Reserved)
    volatile uint32_t PCC_FlexCAN2;// Offset 0xAC
    volatile uint32_t PCC_LPSPI0;  // Offset 0xB0
    volatile uint32_t PCC_LPSPI1;  // Offset 0xB4
    volatile uint32_t PCC_LPSPI2;  // Offset 0xB8
    uint32_t RESERVED_3[2];        // Offset 0xBC and 0xC0 (Reserved)
    volatile uint32_t PCC_PDB1;    // Offset 0xC4
    volatile uint32_t PCC_CRC;     // Offset 0xC8
    uint32_t RESERVED_4[3];        // Offset 0xCC and 0xD4 and 0xD4(Reserved)
    volatile uint32_t PCC_PDB0;    // Offset 0xD8
    volatile uint32_t PCC_LPIT;    // Offset 0xDC
    volatile uint32_t PCC_FTM0;    // Offset 0xE0
    volatile uint32_t PCC_FTM1;    // Offset 0xE4
    volatile uint32_t PCC_FTM2;    // Offset 0xE8
    volatile uint32_t PCC_ADC0;    // Offset 0xEC
    uint32_t RESERVED_5[1];        // Offset 0xF0 (Reserved)
    volatile uint32_t PCC_RTC;     // Offset 0xF4
    uint32_t RESERVED_6[2];        // Offset 0xF8 to 0xFC (Reserved)
    volatile uint32_t PCC_LPTMR0;  // Offset 0x100
    uint32_t RESERVED_7[8];        // Offset 0x104 to 0x120 (Reserved)
    volatile uint32_t PCC_PORTA;   // Offset 0x124
    volatile uint32_t PCC_PORTB;   // Offset 0x128
    volatile uint32_t PCC_PORTC;   // Offset 0x12C
    volatile uint32_t PCC_PORTD;   // Offset 0x130
    volatile uint32_t PCC_PORTE;   // Offset 0x134
    uint32_t RESERVED_8[7];        // Offset 0x138 to 0x14C (Reserved)
    volatile uint32_t PCC_SAI0;    // Offset 0x150
    volatile uint32_t PCC_SAI1;    // Offset 0x154
    uint32_t RESERVED_9[5];        // Offset 0x158 to 0x164 (Reserved)
    volatile uint32_t PCC_FlexIO;  // Offset 0x168
    uint32_t RESERVED_10[6];       // Offset 0x16C to 0x180 (Reserved)
    volatile uint32_t PCC_EWM;     // Offset 0x184
    uint32_t RESERVED_11[5];       // Offset 0x188 to 0x194 (Reserved)
    volatile uint32_t PCC_LPI2C0;  // Offset 0x198
    volatile uint32_t PCC_LPI2C1;  // Offset 0x19C
    uint32_t RESERVED_12[2];       // Offset 0x1A0 to 0x1A4 (Reserved)
    volatile uint32_t PCC_LPUART0; // Offset 0x1A8
    volatile uint32_t PCC_LPUART1; // Offset 0x1AC
    volatile uint32_t PCC_LPUART2; // Offset 0x1B0
    uint32_t RESERVED_13[1];       // Offset 0x1B4 (Reserved)
    volatile uint32_t PCC_FTM4;    // Offset 0x1B8
    volatile uint32_t PCC_FTM5;    // Offset 0x1BC
    volatile uint32_t PCC_FTM6;    // Offset 0x1C0
    volatile uint32_t PCC_FTM7;    // Offset 0x1C4
    uint32_t RESERVED_14[1];       // Offset 0x1C8 (Reserved)
    volatile uint32_t PCC_CMP0;    // Offset 0x1CC
    uint32_t RESERVED_15[2];       // Offset 0x1D0 to 0x1D4 (Reserved)
    volatile uint32_t PCC_QSPI;    // Offset 0x1D8
    uint32_t RESERVED_16[1];       // Offset 0x1DC (Reserved)
    volatile uint32_t PCC_ENET;    // Offset 0x1E4
} PCC_Type;

/** Peripheral PCC base address */
#define PCC_base_address                                 (0x40065000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_base_address)

#endif
