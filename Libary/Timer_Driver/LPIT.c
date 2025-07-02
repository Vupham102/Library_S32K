#include "LPIT_Resgister.h"
#include "LPIT.h"
#define PCC_LPIT 			(*(volatile unsigned int*)(0x40065000u + 0xDC))

// Function to initialize the LPIT module
void LPIT_Init(void) {
    // Enable clock for LPIT
    PCC_LPIT |= (1u << 30u);
    PCC_LPIT |= (7u << 24u);
    // Enable module and set timer stop in debug mode
    LPIT->MCR |= (1u);
    LPIT->MCR |= (1u << 3u);
}

// Function to enable a specific timer channel interrupt
void LPIT_EnableInterrupt(unsigned char channel) {
    LPIT->MIER |= (1u << channel);
}

// Function to disable a specific timer channel interrupt
void LPIT_DisableInterrupt(unsigned char channel) {
    LPIT->MIER &= ~(1u << channel);
}

// Function to set the timer value for a specific channel
void LPIT_SetTimerValue(unsigned char channel, unsigned int value) {
    switch(channel) {
        case 0:
            LPIT->TVAL0 = value;
            break;
        case 1:
            LPIT->TVAL1 = value;
            break;
        case 2:
            LPIT->TVAL2 = value;
            break;
        case 3:
            LPIT->TVAL3 = value;
            break;
    }
}

// Function to start a specific timer channel
void LPIT_StartTimer(unsigned char channel, unsigned char mode) {
    switch(channel) {
        case 0:
            LPIT->TCTRL0 &= ~(1u << 2);  // Clear mode bit
            LPIT->TCTRL0 |= (mode << 2); // Set mode
            LPIT->TCTRL0 |= (1u << 0);
            break;
        case 1:
            LPIT->TCTRL1 &= ~(1u << 2);  // Clear mode bit
            LPIT->TCTRL1 |= (mode << 2); // Set mode
            LPIT->TCTRL1 |= (1u << 0);
            break;
        case 2:
            LPIT->TCTRL2 &= ~(1u << 2);  // Clear mode bit
            LPIT->TCTRL2 |= (mode << 2); // Set mode
            LPIT->TCTRL2 |= (1u << 0);
            break;
        case 3:
            LPIT->TCTRL3 &= ~(1u << 2);  // Clear mode bit
            LPIT->TCTRL3 |= (mode << 2); // Set mode
            LPIT->TCTRL3 |= (1u << 0);
            break;
    }
}

// Function to stop a specific timer channel
void LPIT_StopTimer(unsigned char channel) {
    switch(channel) {
        case 0:
            LPIT->TCTRL0 &= ~(1u << 0);
            break;
        case 1:
            LPIT->TCTRL1 &= ~(1u << 0);
            break;
        case 2:
            LPIT->TCTRL2 &= ~(1u << 0);
            break;
        case 3:
            LPIT->TCTRL3 &= ~(1u << 0);
            break;
    }
}

// Function to clear the timer enable register for a specific channel
void LPIT_ClearTimerEnable(unsigned char channel) {
    LPIT->CLRTEN |= (1u << channel);
}

// Function to set the timer enable register for a specific channel
void LPIT_SetTimerEnable(unsigned char channel) {
    LPIT->SETTEN |= (1u << channel);
}

// Function to read the current timer value for a specific channel
unsigned int LPIT_GetCurrentTimerValue(unsigned char channel) {
    switch(channel) {
        case 0:
            return LPIT->CVAL0;
        case 1:
            return LPIT->CVAL1;
        case 2:
            return LPIT->CVAL2;
        case 3:
            return LPIT->CVAL3;
        default:
            return 0; // Invalid channel
    }
}
