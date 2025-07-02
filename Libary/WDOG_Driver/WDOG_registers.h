#ifndef WDOG_REGISTERS_H
#define WDOG_REGISTERS_H

// Địa chỉ cơ sở của WDOG
#define WDOG_BASE_ADDR      0x40052000U

// Cấu trúc của các thanh ghi WDOG
typedef struct {
    volatile unsigned int CS;    // Watchdog Control and Status Register
    volatile unsigned int CNT;   // Watchdog Counter Register
    volatile unsigned int TOVAL; // Watchdog Timeout Value Register
    volatile unsigned int WIN;   // Watchdog Window Register
} WDOG_Type;

// Trỏ đến cấu trúc WDOG tại địa chỉ cơ sở
#define WDOG ((WDOG_Type *) WDOG_BASE_ADDR)

// Các bit mask cho các trường của thanh ghi WDOG_CS
#define WDOG_CS_EN_MASK     (0x00000001U) // Enable Watchdog
#define WDOG_CS_CLK_MASK    (0x00000002U) // Clock Source
#define WDOG_CS_INT_MASK    (0x00000004U) // Interrupt Enable
#define WDOG_CS_WIN_MASK    (0x00000008U) // Window Mode
#define WDOG_CS_UPDATE_MASK (0x00000010U) // Update Configuration
#define WDOG_CS_CMD32EN_MASK (0x00000020U) // 32-bit Command Enable
#define WDOG_CS_PRES_MASK   (0x00000040U) // Prescaler Enable
#define WDOG_CS_DBG_MASK    (0x00000080U) // Debug Enable
#define WDOG_CS_WAIT_MASK   (0x00000100U) // Wait Enable
#define WDOG_CS_STOP_MASK   (0x00000200U) // Stop Enable
#define WDOG_CS_TST_MASK    (0x00000C00U) // Test Mode

// Các giá trị cụ thể cho các trường của WDOG_CS
#define WDOG_CS_EN         (1U << 0)
#define WDOG_CS_CLK_LPO    (0U << 1) // LPO Clock Source
#define WDOG_CS_CLK_BUS    (1U << 1) // Bus Clock Source
#define WDOG_CS_INT_ENABLE (1U << 2)
#define WDOG_CS_WIN_ENABLE (1U << 3)
#define WDOG_CS_UPDATE_ENABLE (1U << 4)
#define WDOG_CS_CMD32_ENABLE (1U << 5)
#define WDOG_CS_PRES_ENABLE (1U << 6)
#define WDOG_CS_DBG_ENABLE (1U << 7)
#define WDOG_CS_WAIT_ENABLE (1U << 8)
#define WDOG_CS_STOP_ENABLE (1U << 9)
#define WDOG_CS_TST_DISABLED (0U << 10)
#define WDOG_CS_TST_USER_MODE (1U << 10)
#define WDOG_CS_TST_LOW_BYTE (2U << 10)
#define WDOG_CS_TST_HIGH_BYTE (3U << 10)

#endif // WDOG_REGISTERS_H
