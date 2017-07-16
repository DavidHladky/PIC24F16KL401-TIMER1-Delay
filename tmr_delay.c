/*
 * Revision 1.0
 * File:   tmr_delay.c
 * Author: David Hladky
 * Example for the using the TIMER1 in the MCU PIC24F16KL401
 * Created July 16, 2017, 15:00
 */

#include "tmr_delay.h"

void TMR1DelayUs(uint16_t delay) // This function creates max delay approx. 4095 us. 
{
  T1CONbits.TON = 0; // Disable the TIMER1.
  TMR1 = 0x0000;     // Reset the counter register of the TIMER1.
  PR1 = 16*delay;    // Set the period register. An value in the period register determines the period when an owerflow occurs.
  IFS0bits.T1IF = 0; // Clear interrupt flag for the TIMER1.
  T1CONbits.TCKPS = 0b00; // Set the prescaler to 1 -> 16 MHz = 62.5 ns
  T1CONbits.TON = 1;      // Enable the TIMER1.
  while(IFS0bits.T1IF == 0); // Wait until the TIMER1 overflow.
  IFS0bits.T1IF = 0;      // Clear interrupt flag for the TIMER1.
  T1CONbits.TON = 0;      // Disable the TIMER1.
}

void TMR1DelayMs(uint16_t delay) // This function creates max delay approx. 262 ms. 
{
  T1CONbits.TON = 0; // Disable the TIMER1.
  TMR1 = 0x0000;     // Reset the counter register of the TIMER1.
  PR1 = 250*delay;   // Set the period register. An value in the period register determines the period when an owerflow occurs.
  IFS0bits.T1IF = 0; // Clear interrupt flag for the TIMER1.
  T1CONbits.TCKPS = 0b10; // Set the prescaler to 64 -> 16 MHz = 4 us
  T1CONbits.TON = 1;      // Enable the TIMER1.
  while(IFS0bits.T1IF == 0); // Wait until the TIMER1 overflow.
  IFS0bits.T1IF = 0;    // Clear interrup flag for the TIMER1.
  T1CONbits.TON = 0;    // Disable the TIMER1.
}
