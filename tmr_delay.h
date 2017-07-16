/*
 * Revision 1.0
 * File:   tmr_delay.h
 * Author: David Hladky
 * Example for the using the TIMER1 in the MCU PIC24F16KL401
 * Created in July 16, 2017, 15:00
 */

#include <stdint.h>
#include "xc.h"

void TMR1DelayUs(uint16_t delay); // This function creates max delay approx. 4095 us.  

void TMR1DelayMs(uint16_t delay); // This function creates max delay approx. 262 ms. 

