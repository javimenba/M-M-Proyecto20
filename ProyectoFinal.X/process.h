#ifndef PRO_H
#define PRO_H

#include <xc.h>
#include "PWM.h"
#define _XTAL_FREQ 4000000
void mostrar_inc(unsigned int duty);
void mostrar_dec(unsigned int duty);
void segment(unsigned int centenas);
void segment2(unsigned int centenas);
void declet(void);
void delay_ms(unsigned int milliseconds);
void Dutty_Pwm(unsigned int fpwm, unsigned int delay);
void demo_delay_ms(unsigned int miliseconds);
void demo_Dutty_Pwm(unsigned int fpwm, unsigned int delay);
#endif