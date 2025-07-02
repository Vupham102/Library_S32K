#ifndef PCC_H
#define PCC_H
#include "PCC_Registers.h"

typedef struct 
{
    unsigned char index;
}PCC_Config;

void PCC_ENA(const PCC_Config* configptr);
void PCC_DIS(const PCC_Config* configptr);

#endif
