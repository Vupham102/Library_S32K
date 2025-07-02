#ifndef LPIT_H
#define LPIT_H

// Base address of LPIT registers
#define LPIT_BASE (0x40037000u)

// Define the structure of the LPIT module
typedef struct {
    volatile const unsigned int VERID;    // 0x00 Version ID Register
    volatile const unsigned int PARAM;    // 0x04 Parameter Register
    volatile unsigned int MCR;            // 0x08 Module Control Register
    volatile unsigned int MSR;            // 0x0C Module Status Register
    volatile unsigned int MIER;           // 0x10 Module Interrupt Enable Register
    volatile unsigned int SETTEN;         // 0x14 Set Timer Enable Register
    volatile unsigned int CLRTEN;         // 0x18 Clear Timer Enable Register
    unsigned int RESERVED1[1];            // 0x1C Reserved
    volatile unsigned int TVAL0;          // 0x20 Timer Value Register 0
    volatile const unsigned int CVAL0;    // 0x24 Current Timer Value 0
    volatile unsigned int TCTRL0;         // 0x28 Timer Control Register 0
    unsigned int RESERVED2[1];            // 0x2C Reserved
    volatile unsigned int TVAL1;          // 0x30 Timer Value Register 1
    volatile const unsigned int CVAL1;    // 0x34 Current Timer Value 1
    volatile unsigned int TCTRL1;         // 0x38 Timer Control Register 1
    unsigned int RESERVED3[1];            // 0x3C Reserved
    volatile unsigned int TVAL2;          // 0x40 Timer Value Register 2
    volatile const unsigned int CVAL2;    // 0x44 Current Timer Value 2
    volatile unsigned int TCTRL2;         // 0x48 Timer Control Register 2
    unsigned int RESERVED4[1];            // 0x4C Reserved
    volatile unsigned int TVAL3;          // 0x50 Timer Value Register 3
    volatile const unsigned int CVAL3;    // 0x54 Current Timer Value 3
    volatile unsigned int TCTRL3;         // 0x58 Timer Control Register 3
} LPIT_Type;

// Define a pointer to the LPIT module
#define LPIT ((LPIT_Type *)LPIT_BASE)

#endif // LPIT_H
