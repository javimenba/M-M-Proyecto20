/*
 * File:   main.c
 * Author: javier
 *
 * Created on 14 de mayo de 2021, 10:14 PM
 */


#include <xc.h>
#include "PWM.h"
#include "ByteConf.h"
#include "process.h"
#include "adc.h"
#include "eeprom.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define XTAL_FREQ 4000000
#define vref 5.00	
#define button1 PORTCbits.RC2
// Proteus 400ms = 1's
int delay,flag,eprom;


// 0.05v-0.12 =1's
// 0.13v-0.17 =2's
// 1.- Inicializa en 0
// 2.- Presiona INT0, configuras, vuelves a presionar RB0, se sale de la interrupcion
//     corre el programa.
// 3.- Vuelve a presionar la interrupción, crea reset.

// Cilo for i=13; presiona INT, le da un valor a Delay.
// 

void __interrupt() INT_EX_0(void){   
    int digital,i,k,j=0;  
    float voltage;
    j=j+1;
    if(INTCONbits.INT0IF==1){
        // código 
        flag=flag+1; 
    do{ 
        if(flag==2){eeprom_guardar(0,2);eprom=eeprom_leer(0x00);}
        i=0;
        LATBbits.LATB2=1;
        delay=0;
        PORTA=0;
        PORTB=0;
        digital=ADC_Read(5);//0-vdd
        voltage= digital*((float)vref/(float)1023); //0-5v      
        __delay_ms(100);
        if(eprom==2){asm("reset");}        
        else if(PORTBbits.RB0==1){
        __delay_ms(500);
        i=1;
        LATBbits.LATB2=0;
        INTCONbits.INT0IF=0;
        }
     }while(i==0);
        
    }
        
    }

void __interrupt(low_priority) INT_EXT_1(void){
    // baja prioridad
    if(INTCON3bits.INT1IF==1){
        //código
        INTCON3bits.INT1IF=0;
    }
}

void main(void) {
    int i,m;
    INTCONbits.INT0IE=1;
    INTCON3bits.INT1IE=1;
    INTCON2bits.INTEDG0=0;
    INTCON2bits.INTEDG1=0;
    RCONbits.IPEN=1;
    INTCONbits.GIEH=1;
    INTCONbits.GIEL=1;
  
    
    declet();
    ADC_Init();			/*Initialize 10-bit ADC*/
    eeprom_guardar(0,0);
    eprom=eeprom_leer(0x00);
    
    while(1){
        if(flag==1){Dutty_Pwm(1000,delay);}    
        else if(flag==0){Dutty_Pwm(1000,0);}

}
}





