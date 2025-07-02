#ifndef LPIT_DRIVER_H
#define LPIT_DRIVER_H

// Function to initialize the LPIT module
void LPIT_Init(void);

// Function to enable a specific timer channel interrupt
void LPIT_EnableInterrupt(unsigned char channel);

// Function to disable a specific timer channel interrupt
void LPIT_DisableInterrupt(unsigned char channel);

// Function to set the timer value for a specific channel
void LPIT_SetTimerValue(unsigned char channel, unsigned int value);

// Function to start a specific timer channel
void LPIT_StartTimer(unsigned char channel, unsigned char mode);

// Function to stop a specific timer channel
void LPIT_StopTimer(unsigned char channel);

// Function to clear the timer enable register for a specific channel
void LPIT_ClearTimerEnable(unsigned char channel);

// Function to set the timer enable register for a specific channel
void LPIT_SetTimerEnable(unsigned char channel);

// Function to read the current timer value for a specific channel
unsigned int LPIT_GetCurrentTimerValue(unsigned char channel);

#endif // LPIT_DRIVER_H
