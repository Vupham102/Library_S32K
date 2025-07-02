#ifndef WDOG_H
#define WDOG_H

// Khai báo các hàm quản lý WDOG
void WDOG_Init(unsigned int timeout, unsigned int clockSource, unsigned int enableInterrupt, unsigned int enableWindow, unsigned int updateConfig);
void WDOG_Refresh(void);
void WDOG_Disable(void);

void disable_irq(void);
void enable_irq(void);

#endif // WDOG_H
