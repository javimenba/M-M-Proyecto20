#ifndef ADC_H
#define ADC_H

#include <xc.h>

#define _XTAL_FREQ 4000000
void ADC_Init();
int ADC_Read(int);
#endif