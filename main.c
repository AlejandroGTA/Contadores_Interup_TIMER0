#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, /*NOMCLR,*/ STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

int contadorGlobal1=0;
int contadorGlobal2=0;
int contadorGlobal3=0;
int contador=0;
int contador2=0;
int contador3=0;
int BCD[10]={254,48,109,121,51,91,95,112,127,123 };
   
#INT_TIMER0
void TIMER0(){
contadorGlobal1++;
contadorGlobal2++;
contadorGlobal3++;

set_timer0(8);
}

void main(void) {
   setup_oscillator(OSC_16MHZ);
   set_tris_c(0x0);
   set_tris_d(0x0);
   set_tris_b(0x0);
   setup_timer_0(RTCC_DIV_256 | RTCC_8_BIT);
   enable_interrupts(INT_TIMER0 );
   enable_interrupts(GLOBAL);
   
   
   set_timer0(8); 
while (1) { 
if(contadorGlobal1==2){
   contador++;
   contadorGlobal1=0;
}
if(contador>=10){
   contador=0;
}
if(contadorGlobal2==5){
   contador2++;
   contadorGlobal2=0;
}
if(contador2>=10){
   contador2=0;
}
if(contadorGlobal3==10){
   contador3++;
   contadorGlobal3=0;
}
if(contador3>=10){
   contador3=0;
}
output_c(BCD[contador]);
output_b(BCD[contador2]);
output_d(BCD[contador3]);
}
}