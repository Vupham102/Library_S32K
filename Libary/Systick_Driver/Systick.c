#include "Systick.h"


void SysTick_Init(const SYST_Config* config)
{
	SYST->SYST_CSR &= ~1;
	
	SYST->SYST_RVR = config->reload_value-1;
	SYST->SYST_CVR = 0;
	
	SYST->SYST_CSR &= ~(1 << 1u);
	SYST->SYST_CSR |= (config->enable_interrupt << 1u);
	
	SYST->SYST_CSR &= ~(1 << 2);
	SYST->SYST_CSR |= (config->source_clk << 2);
	
	SYST->SYST_CSR |= 1;
}

void SysTick_Config(unsigned int reload, unsigned int enable, unsigned int clk)
{
    SYST_Config setting;
    setting.reload_value = reload;
    setting.enable_interrupt = enable;
    setting.source_clk = clk;
    SysTick_Init(&setting);
}

void delay_ms(unsigned int ms)
{
    for (unsigned int i = 0; i < ms; i++)
    {
        while ((SYST ->SYST_CSR & (1 << 16)) == 0);
    }
    
}