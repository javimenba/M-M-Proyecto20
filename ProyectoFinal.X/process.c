/*
 * File:   process.c
 * Author: javier
 *
 * Created on 16 de mayo de 2021, 01:21 AM
 */

#include "process.h"

int CEN=1,CEN2=11;
   void mostrar_inc(unsigned int duty){
        int por_pwm, par;
        por_pwm=duty/5; 
        par = por_pwm%2; 
        if(par==1){
            PORTB=0xF0;
        }
        else if (par==0){
            PORTB=0x00;
            CEN++;
            //PORTD=CEN;
            segment(CEN); 
        }
    }

    void mostrar_dec(unsigned int duty){
        int por_pwm, par;
        por_pwm=duty/5; 
        par = por_pwm%2;
        
        if(por_pwm==20 && par==0){
            PORTA=0x7E;
            PORTB=0xF8; 
            PWM_generar(100,1000);   
               
        }
        else if(por_pwm!=20 && par==1 ){
            PORTB=0xF0;
            CEN2--;
            //PORTD=CEN2;
            segment2(CEN2); 
        }
        else if (par==0){
            PORTB=0x00;
        }
}

void segment(unsigned int centenas){
    if(centenas==1){
        PORTA=0x7E;    
    }
    else if(centenas==2){
        PORTA=0x30;    
    }
    else if(centenas==3){
        PORTA=0x6D;     
    }
    else if(centenas==4){
        PORTA=0x79;    
    }
    else if(centenas==5){
        PORTA=0x33;
    }
    else if(centenas==6){
        PORTA=0x5B;      
    }
    else if(centenas==7){
        PORTA=0x5F;      
    }
    else if(centenas==8){
        PORTA=0x70;      
    }
    else if(centenas==9){
        PORTA=0x7F;        
    }
    else if(centenas==10){
        PORTA=0x73;
        CEN2=10;
    }

}
void segment2(unsigned int centenas){
    if(centenas==1){
        PORTA=0x30;
        CEN=1;
    }
    else if(centenas==2){
        PORTA=0x6D;
    }
    else if(centenas==3){
        PORTA=0x79;
    }
    else if(centenas==4){
        PORTA=0x33;
    }
    else if(centenas==5){
        PORTA=0x5B;
    }
    else if(centenas==6){
        PORTA=0x5F;
    }
    else if(centenas==7){
        PORTA=0x70;
    }
    else if(centenas==8){
        PORTA=0x7F;
    }
    else if(centenas==9){
        PORTA=0x73;
    }
    else if(centenas==10){
        PORTA=0x7E;
    }

}
void declet(void){
    OSCCON=0b01010111; //4MHz
    PORTC=0;
    TRISC=0;
    PORTA=0;
    LATA=0;
    ANSELA=0;
    TRISA=0;
    PORTE=0;
    LATE=0;
    ANSELE=0;
    TRISE=0;
    PORTB=0;
    LATB=0;
    ANSELB=0;
    TRISB=0;
    PORTD=0;
    LATEbits.LE0=0; 

}
void delay_s(unsigned int seconds)
 {
   while(seconds > 0)
   {
       __delay_ms(1000);
      seconds--;
    }
 }


void Dutty_Pwm(unsigned int fpwm, unsigned int delay)
{
        int i, k=0;  
        
       
        for(i=0; i<20 ; i++){
          
            PWM_generar(k,fpwm);
            delay_s(delay);
            k=k+5;
            mostrar_inc(k);
        }
        k=105;
        PORTA=0;
        for(i=0; i<21 ; i++){
           
            k=k-5;
            PWM_generar(k,fpwm);   
            delay_s(delay);
            mostrar_dec(k);
        }
        k=0;
        PORTA=0;
 } 

//void Dutty_Pwm(unsigned int fpwm, unsigned int delay)
//{
//
//    int con=0,i,k;
//    do{
//     i=0;
//     PWM_generar(con,fpwm);
//     delay_s(delay);
//     con=con+5;
//     mostrar_inc(con);
//     if(con==100){
//         PORTA=0;
//         con=100;
//         do{            
//            k=0;
//            con=con-5;
//            PWM_generar(con,fpwm);   
//            delay_s(delay);
//            mostrar_dec(con);
//            if(con==0){i=1; k=1;}
//         }while(k==0);
//     }
//    }while(i==0);
//    PORTA=0;    
// } 


void demo_delay_ms(unsigned int miliseconds)
 {
   while(miliseconds > 0)
   {
       __delay_ms(1);
      miliseconds--;
    }
 }

void demo_Dutty_Pwm(unsigned int fpwm, unsigned int delay)
{
        int i, k=0;    
        for(i=0; i<20 ; i++){
            PWM_generar(k,fpwm);
            demo_delay_ms(delay);
            k=k+5;
            mostrar_inc(k);
        }
        k=105;
        PORTB=0;
        for(i=0; i<21 ; i++){
            k=k-5;
            PWM_generar(k,fpwm);   
            demo_delay_ms(delay);
            mostrar_dec(k);
        }
        k=0;
        PORTB=0;
 } 