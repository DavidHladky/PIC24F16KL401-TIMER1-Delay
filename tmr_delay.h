/*
 * Revision 1.0
 * File:   tmr_delay.h
 * Author: David Hladky
 * Header library for the initialization and generation of a delay on the TIMER1.
 * Created in July 16, 2017, 15:00
 */

#include <stdint.h>
#include "xc.h"

void TMR1DelayUs(uint16_t delay); // This function creates max delay approx. 4095 us.  

void TMR1DelayMs(uint16_t delay); // This function creates max delay approx. 262 ms. 

