/*
 * File:   ADC.c
 * Author: javier
 *
 * Created on 16 de mayo de 2021, 10:41 PM
 */

// Potenciometro 5v-0v, 
// Initialize 10-bit ADC
#include "adc.h"
void ADC_Init()
{    
    ADCON1 = 0x0e;  		/*Ref vtg is VDD & Configure pin as analog pin*/    
    ADCON2 = 0x92;  		/*Right Justified, 4Tad and Fosc/32. */
    ADRESH=0;  			    /*Flush ADC output Register*/ 
    ADRESL=0;  
}

int ADC_Read(int channel)
{
    // POT 0-5v, 0-100.
    int digital;
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);

    /*channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000)& ADC is disabled*/
    ADCON0 |= ((1<<ADON)|(1<<GO));/*Enable ADC and start conversion*/

    /*wait for End of conversion i.e. Go/done'=0 conversion completed*/
    while(ADCON0bits.GO_nDONE==1);

   digital = (ADRESH*256) | (ADRESL);/*Combine 8-bit LSB and 2-bit MSB*/
    //   PORTA=digital;
    
    return(digital); 
}

