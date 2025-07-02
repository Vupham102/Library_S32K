#ifndef SYSTICK_H
#define SYSTICK_H
#include "Systick_Registers.h"

typedef struct
{
    SYST_Type         *      base;                  /*!< Gpio base pointer.  */
    unsigned int            reload_value;        /*!< Pin number.*/
    unsigned char            source_clk;          /*!< Pin_mode */
    unsigned char            enable_interrupt;
} SYST_Config;

void SysTick_Init(const SYST_Config* config);
void SysTick_Config(unsigned int reload, unsigned int enable, unsigned int clk);
void delay_ms(unsigned int ms);

#endif