#include "WDOG_registers.h"
#include "WDOG.h"
#define NVIC_ISER_0			(*(volatile unsigned int*)(0xE000E100u + 4*0))


void disable_irq(void)
{
    NVIC_ISER_0 &= ~(1<<22);
}

void enable_irq(void)
{
    NVIC_ISER_0 |= (1<<22);
}

void WDOG_Init(unsigned int timeout, unsigned int clockSource, unsigned int enableInterrupt, unsigned int enableWindow, unsigned int updateConfig) {
    // Vô hiệu hóa toàn bộ ngắt toàn cục trước khi cấu hình
    disable_irq();

    // Mở khóa WDOG
    WDOG->CNT = 0xD928C520;

    // Đợi cho đến khi các thanh ghi được mở khóa
    while (WDOG->CS & WDOG_CS_EN_MASK);

    // Cấu hình thời gian timeout
    WDOG->TOVAL = timeout;

    // Cấu hình các trường của WDOG_CS
    WDOG->CS = (enableInterrupt ? WDOG_CS_INT_ENABLE : 0) |
              (clockSource ? WDOG_CS_CLK_BUS : WDOG_CS_CLK_LPO) |
              (enableWindow ? WDOG_CS_WIN_ENABLE : 0) |
              (updateConfig ? WDOG_CS_UPDATE_ENABLE : 0);

    // Đợi cho đến khi cấu hình mới có hiệu lực
    while (!(WDOG->CS & WDOG_CS_EN_MASK));

    // Bật lại ngắt toàn cục
    enable_irq();
}

void WDOG_Refresh(void) {
    // Vô hiệu hóa toàn bộ ngắt toàn cục trước khi làm mới
    disable_irq();

    // Làm mới WDOG
    WDOG->CNT = 0xB480A602;

    // Bật lại ngắt toàn cục
    enable_irq();
}

void WDOG_Disable(void) {
    // Vô hiệu hóa toàn bộ ngắt toàn cục trước khi vô hiệu hóa
    disable_irq();

    // Mở khóa WDOG
    WDOG->CNT = 0xD928C520;

    // Vô hiệu hóa WDOG
    WDOG->CS &= ~WDOG_CS_EN_MASK;

    // Bật lại ngắt toàn cục
    enable_irq();
}
