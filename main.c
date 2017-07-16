/*
 * Revision 1.0
 * File:   main.c
 * Author: David Hladky
 * Example of using the TIMER1 to generate a delay.
 * Created in July 16, 2017, 15:00
 */

#include "xc.h"
#include "config.h"
/*
 * The tmr_delay.h library contains two functions for realizing a specific delay.
 * The first function is TMR1DelayUs(uint16_t delay). This function realizes delay from 1 us to 4095 us.
 * The seconf function is TMR1DelayMs(uint16_t delay). This function realizes delay from 1 ms to 262 ms.
 */
#include "tmr_delay.h" // This library contains two functions for realizing a specific delay.

int main (void){
  /*Initialization of the output pin RB4 - to this pin is connected LED diode*/
  TRISBbits.TRISB4 = 0; //Set pin RB4 as output (0 - output, 1 - input)
  LATBbits.LATB4 = 0;   // Initial value is set to the logical "0" - Led is turned off.
  ANSBbits.ANSB15 = 0;  // Disable analog input.
  
  while(1) // Endless loop
    {
          LATBbits.LATB4 = ~LATBbits.LATB4; // Toggle GPIO RB4
          TMR1DelayMs(250); // Delay 250 ms
          LATBbits.LATB4 = ~LATBbits.LATB4; // Toggle GPIO RB4
          TMR1DelayMs(250); // Delay 250 ms
    }
  return 0;
}
