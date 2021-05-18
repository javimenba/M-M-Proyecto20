#ifndef EEPROM_H
#define EEPROM_H

#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _XTAL_FREQ 4000000
void eeprom_guardar(int DIR, char DATE);
char  eeprom_leer(int DIR);
void eeprom_guardar_cadena(int dir, char *date);

#endif