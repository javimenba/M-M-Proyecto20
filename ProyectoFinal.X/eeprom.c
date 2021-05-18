/*
 * File:   eeprom.c
 * Author: javier
 *
 * Created on 18 de mayo de 2021, 01:25 AM
 */

#include "eeprom.h"
void eeprom_guardar(int DIR, char DATE){
    EEADR = DIR;
    EEDATA = DATE;
    EECON1bits.EEPGD=0;
    EECON1bits.CFGS=0;
    EECON1bits.WREN=1;
   //INTCONbits.GIE=0;
    EECON2=0x55;
    EECON2=0x0AA;
    EECON1bits.WR=1;
  //  INTCONbits.GIE=1;
    while(!PIR2bits.EEIF);
    PIR2bits.EEIF=0;
    EECON1bits.WREN=0;
}

 char eeprom_leer(int DIR){
    EEADR = DIR;
    EECON1bits.EEPGD=0;
    EECON1bits.CFGS=0;
    EECON1bits.RD;
    return EEDATA;
}

void eeprom_guardar_cadena(int address,char *data)
{
    /*Write Operation for String*/
    while(*data!=0)
    {
        eeprom_guardar(address,*data);
        address++;
        *data++;
    }    
}

