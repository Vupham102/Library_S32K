#ifndef SYSTICK_REGISTER_H
#define SYSTICK_REGISTER_H

typedef struct
{
    volatile unsigned int SYST_CSR;
    volatile unsigned int SYST_RVR;
    volatile unsigned int SYST_CVR;
    volatile unsigned int SYST_CALIB;
} SYST_Type;

#define SYST_BASE  (0xE000E010u)
#define SYST ((SYST_Type *)SYST_BASE)

#endif
